#!/usr/bin/env python3
"""Random search over declaration order: locals, extern data, prototypes.

CL 10.00 chooses between equivalent encodings (which of two globals loads
first, `cmp a, b` orientation, which scratch register a temporary gets) by
internal symbol numbering, and declaration order sets that numbering.
`perturb.py` tries padding and single moves; some near misses need a
permutation no single move reaches (00420300 needed a shuffle of all twelve
locals, 0040a010 two swapped externs).

Each sample shuffles one group, chosen at random: the local declarations at
the top of GEX_Target, the `extern` data lines, or the prototype lines.
Stops at the first exact candidate and writes FILE.ds.cpp; otherwise writes
the best candidate by aligned similarity.

    declshuffle.py ADDRESS FILE [--samples 300] [--languages cpp,c] [--seed 1]
"""
import argparse, os, random, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import probe


def groups(src):
    """Return lists of line indices for each shuffleable group."""
    lines = src.split('\n')
    externs, protos, local = [], [], []
    body = None
    for i, l in enumerate(lines):
        if re.match(r'\s*extern\s+(?!"C")', l) and '(' not in l and l.rstrip().endswith(';'):
            externs.append(i)
        elif re.match(r'^[A-Za-z_][\w\s\*]*__cdecl\s+\w+\(.*\);\s*$', l) and 'GEX_Target' not in l:
            protos.append(i)
        if 'GEX_Target(' in l and not l.rstrip().endswith(';'):
            body = i
    if body is not None:
        j = body + 1
        if lines[j].strip() == '{':
            j += 1
        while j < len(lines) and re.match(r'^    [A-Za-z_][\w\s\*]*[\w\]]+(\[\w+\])?;\s*$', lines[j]) \
                and '=' not in lines[j] and '(' not in lines[j]:
            local.append(j)
            j += 1
    return lines, [g for g in (local, externs, protos) if len(g) > 1]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('address'); ap.add_argument('source')
    ap.add_argument('--samples', type=int, default=300)
    ap.add_argument('--languages', default='cpp,c')
    ap.add_argument('--seed', type=int, default=1)
    args = ap.parse_args()
    rng = random.Random(args.seed)
    p = probe.Probe(args.address)
    src = open(args.source).read()
    lines, gs = groups(src)
    if not gs:
        print('no shuffleable groups'); return 2
    langs = args.languages.split(',')
    best = (-1, None, None)
    out = args.source.replace('.cpp', '.ds.cpp')
    for n in range(args.samples):
        cand = lines[:]
        g = rng.choice(gs)
        vals = [lines[i] for i in g]
        rng.shuffle(vals)
        for i, v in zip(g, vals):
            cand[i] = v
        text = '\n'.join(cand)
        for lang in langs:
            r = p.measure(text, lang=lang)
            if r['exact']:
                open(out, 'w').write(text if lang == 'cpp' else probe.to_c(text))
                print(f'EXACT {lang} sample {n} {out}')
                return 0
            if r['compiled'] and r['percent'] is not None and r['percent'] > best[0]:
                best = (r['percent'], lang, text)
    open(out, 'w').write(best[2] if best[1] == 'cpp' else probe.to_c(best[2]))
    print(f'best {best[0]:.1f} {best[1]} {out}')
    return 2


if __name__ == '__main__':
    sys.exit(main())
