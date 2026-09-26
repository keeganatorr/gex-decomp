#!/usr/bin/env python3
"""Search compiler-state perturbations of a candidate that already has the right logic.

    tools/perturb.py ADDRESS SOURCE [--pad 8] [--moves] [--languages cpp,c]
                     [--max 3000] [--write OUT] [--manifest OUT.json]

When a candidate differs from the original only in commutative operand order
(`cmp eax, ecx` vs `cmp ecx, eax`, SIB base/index), register choice or the
order of independent instructions, CL 10.00 is choosing between equivalent
encodings by its internal symbol numbering. The original headers set that
numbering; a reconstructed translation unit does not. Three cheap levers move
it without touching the function body (docs/knowledge/symbol-numbering.md):

  * unused extern data declarations inserted at one position (count matters,
    names and data types do not; function prototypes count differently),
  * the order of existing top-level declarations (every order up to five
    declarations, otherwise single moves then swaps),
  * the front end: /Tp (C++) vs /Tc (C) lays symbols out differently.

Probes never publish. The first exact candidate is written to --write; publish
it through scripts/verify like any other source. --manifest instead emits a
pc-decomp SourceSearch manifest (version 1) of the tried candidates, so the
backend can run the same finite family itself under its owner lock.
"""
import argparse, hashlib, itertools, json, os, re, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import probe

PAD_NOTE = ('// Unused declarations below are compiler-state padding, not recovered source:\n'
            '// VC4 orders commutative operands/registers by internal symbol numbering,\n'
            '// which the original headers set. They emit no code or relocations.\n'
            '// See docs/knowledge/symbol-numbering.md.\n')


def sha256_file(path):
    return hashlib.sha256(open(path, 'rb').read()).hexdigest() if os.path.exists(path) else 'missing'


def declaration_lines(lines):
    """Top-level one-line declarations. extern "C" { ... } is not nesting."""
    depth, found = 0, []
    for i, line in enumerate(lines):
        text = line.strip()
        if re.match(r'extern\s+"C"\s*\{\s*$', text):
            continue
        one_line_linkage = re.match(r'extern\s+"C"\s*\{.*;\s*\}\s*$', text)
        if depth == 0 and (one_line_linkage or (text.endswith(';') and '{' not in text and not text.startswith(('//', 'typedef', '}', '#')))):
            found.append(i)
        if one_line_linkage:
            continue
        depth = max(0, depth + text.count('{') - text.count('}'))
    return found


def in_linkage_block(lines, index):
    """Whether line `index` sits inside an extern "C" { } block."""
    depth_stack = []
    for line in lines[:index]:
        text = line.strip()
        if re.match(r'extern\s+"C"\s*\{\s*$', text):
            depth_stack.append(0); continue
        if depth_stack:
            depth_stack[-1] += text.count('{') - text.count('}')
            if depth_stack[-1] < 0:
                depth_stack.pop()
    return bool(depth_stack)


def volatile_variants(source):
    """Every subset (up to 6 globals) of extern int-like data declarations made
    volatile. Flags polled across threads (Sleep loops) were volatile in the
    original: CL then keeps constant 0 in a callee-saved register and reloads
    the flag each iteration (0040b2d0, 0040ab00, 0040b320)."""
    lines = source.split('\n')
    idx = [i for i, l in enumerate(lines) if re.match(r'\s*extern\s+(?:"C"\s+)?(?:unsigned\s+)?(?:int|long|short|char)\s+\w+\s*;', l)]
    if not idx or len(idx) > 6:
        return
    for mask in range(1, 1 << len(idx)):
        out = list(lines)
        for bit, i in enumerate(idx):
            if mask >> bit & 1:
                out[i] = re.sub(r'extern(\s+"C")?\s+', lambda m: 'extern' + (m.group(1) or '') + ' volatile ', out[i], count=1)
        yield f'volatile-{mask:x}', '\n'.join(out)


def variants(source, lang, pad_limit, moves, volatile=False):
    """Reorders first (a match then needs no padding), then padding."""
    lines = source.split('\n')
    decls = declaration_lines(lines)
    yield 'baseline', source
    if volatile:
        yield from volatile_variants(source)
    if moves and len(decls) > 1:
        content = [lines[i] for i in decls]
        def apply(order):
            out = list(lines)
            for k, index in enumerate(decls): out[index] = order[k]
            return '\n'.join(out)
        if len(content) <= 5:
            # Every order: a commutative sum of four globals needed the exact
            # reverse of its declaration order (004237c0), not one move.
            for order in itertools.permutations(content):
                yield 'order-' + '-'.join(str(content.index(x)) for x in order), apply(order)
        else:
            for i in range(len(content)):
                for j in range(len(content)):
                    if i == j: continue
                    order = list(content); item = order.pop(i); order.insert(j, item)
                    yield f'move-{i}-to-{j}', apply(order)
            for i in range(len(content)):
                for j in range(i + 1, len(content)):
                    order = list(content); order[i], order[j] = order[j], order[i]
                    yield f'swap-{i}-{j}', apply(order)
    slots = decls + ([decls[-1] + 1] if decls else [0])
    for count in range(1, pad_limit + 1):
        for slot in slots:
            linkage = '' if lang == 'c' or in_linkage_block(lines, slot) else 'extern "C" '
            pads = [f'{linkage or "extern "}int decl_pad_{k};' for k in range(count)]
            out = lines[:slot] + PAD_NOTE.rstrip('\n').split('\n') + pads + lines[slot:]
            yield f'pad-{count}-at-{slot}', '\n'.join(out)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('address'); parser.add_argument('source')
    parser.add_argument('--pad', type=int, default=32, help='max unused declarations per slot (default 32; 10, 14 and 19 were needed)')
    parser.add_argument('--moves', action='store_true', help='also try declaration moves and swaps')
    parser.add_argument('--languages', default=None, help='comma list, e.g. cpp,c (default: the contract language)')
    parser.add_argument('--max', type=int, default=3000); parser.add_argument('--write'); parser.add_argument('--manifest')
    parser.add_argument('--flags', help='override the contract flags for this search (a result needs functionOverrides)')
    parser.add_argument('--bind', action='append', default=[], metavar='SYMBOL=ADDRESS', help='trial binding, as in probe.py')
    parser.add_argument('--volatile', action='store_true', help='also try volatile on subsets of extern data globals (thread-polled flags)')
    args = parser.parse_args()
    p = probe.Probe(args.address, dict(b.split('=', 1) for b in args.bind))
    flags = args.flags.split() if args.flags else None
    source = open(args.source).read()
    _, default_lang, _ = probe.contract(p.address)
    languages = args.languages.split(',') if args.languages else [default_lang]
    best, seen, tried, started, manifest = (-1.0, None, None), set(), 0, time.time(), []
    for lang in languages:
        base = probe.to_c(source) if lang == 'c' else source
        for label, text in variants(base, lang, args.pad, args.moves, args.volatile):
            if (lang, text) in seen: continue
            seen.add((lang, text)); tried += 1
            if tried > args.max: break
            if args.manifest:
                manifest.append({'id': f'{lang}-{label}'[:80], 'family': f'perturb-{lang}', 'source': text,
                                 'hypothesis': f'symbol-numbering perturbation {label} under {lang}; body unchanged'})
                continue
            result = p.measure(text, lang, flags)
            if result['percent'] is not None and result['percent'] > best[0]:
                best = (result['percent'], text, f'{lang}/{label}')
                print(f'{tried:5d} {lang}/{label}: {result["percent"]:.1f}%', flush=True)
            if result['exact']:
                print(f'EXACT after {tried} probes ({time.time() - started:.1f}s): {lang}/{label}'
                      + (f' -- needs bindings {result["trial"]} in project.json' if result['trial'] else ''))
                if lang != default_lang:
                    print(f'NOTE: needs functionOverrides["{p.address}"].language = "{lang}" in project.json')
                break
        else:
            continue
        break
    if args.manifest:
        payload = {'version': 1, 'functionId': p.record['id'], 'maxSeconds': 600, 'keepCompilerWarm': True,
                   'familyDuplicateLimit': 0, 'candidates': manifest[:256],
                   # The backend pins its search to the current file under src/functions,
                   # the project.json bytes and the executable, and refuses a stale basis.
                   'expectedBinaryHash': probe.PROJECT['sha256'],
                   'expectedConfigHash': sha256_file(os.path.join(probe.ROOT, 'project.json')),
                   'expectedSourceHash': sha256_file(os.path.join(probe.ROOT, 'src', 'functions', p.address + '.cpp'))}
        json.dump(payload, open(args.manifest, 'w'), indent=1)
        print(f'wrote {min(len(manifest), 256)} candidates to {args.manifest}'); return 0
    print(f'tried {tried}; best {best[0]:.1f}% ({best[2]})')
    if args.write and best[1] is not None:
        open(args.write, 'w').write(best[1])
    return 0 if best[0] == 100.0 else 2


if __name__ == '__main__':
    sys.exit(main())
