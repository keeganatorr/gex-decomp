#!/usr/bin/env python3
"""Fast scratch compile + relocated byte diff for one Gex function.

    tools/probe.py ADDRESS SOURCE [--lang c|cpp|both] [--flags "..."] [-d] [-q] [--asm]

A probe is an experiment, never a proof: it writes nothing to the backend, the
database or src/. It mirrors pc-decomp's strict rules (CoffCode section/extent
checks, DIR32/REL32 resolution through symbolBindings then the pinned symbol
index, positional comparison against the pinned original) so a 100% probe
should verify, but only `scripts/verify` / `scripts/backend verify` publishes.

Why it exists: the loop's models get one compile per turn and a turn costs
minutes. VC4 codegen for operand order, register choice and scheduling is
perturbation-sensitive (docs/knowledge/), so matching needs many cheap
compiles. With a warm Wine server a probe costs ~0.1 s.

Reads .work/decomp.db read-only (SQLite mode=ro) for the function extent and
the pinned symbol index; reads project.json for compiler, flags and overrides.
"""
import argparse, difflib, json, os, re, shutil, sqlite3, struct, subprocess, sys, tempfile, time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PROJECT = json.load(open(os.path.join(ROOT, 'project.json')))
TOOLCHAIN = PROJECT['toolchain']
SCRATCH = os.environ.get('GEX_PROBE_DIR', os.path.join(ROOT, '.work', 'probes', 'scratch'))
HEX8 = re.compile(r'(?<![0-9a-fA-F])([0-9a-fA-F]{8})(?![0-9a-fA-F])')


def database():
    return sqlite3.connect(f'file:{ROOT}/.work/decomp.db?mode=ro', uri=True)


def function_record(address, db=None):
    db = db or database()
    for (body,) in db.execute("select body from records where resource='functions'"):
        row = json.loads(body)
        if row['entry'] == address:
            return row
    raise SystemExit('no function ' + address)


def contract(address, lang=None, flags=None):
    """Effective flags/language/symbol, as pc-decomp's CompileContract resolves them."""
    override = dict(PROJECT.get('functionOverrides', {}).get(address, {}))
    # PROBE_OVERRIDE='{"targetSymbol": "_GEX_Target@16"}' trials an override
    # (a __stdcall target, a C-only body) before it is added to project.json;
    # verification still needs the real functionOverrides entry.
    override.update(json.loads(os.environ.get('PROBE_OVERRIDE') or '{}'))
    return (flags or override.get('flags', TOOLCHAIN['flags']),
            lang or override.get('language', 'cpp'),
            override.get('targetSymbol', '_GEX_Target'))


class Resolver:
    """Same order as pc-decomp SymbolResolver: explicit binding, embedded
    pinned address, unique pinned name. Never guesses."""
    def __init__(self, db=None, extra=None):
        db = db or database()
        index = json.loads(db.execute("select body from records where resource='symbols'").fetchone()[0])
        self.bindings = {k: int(v, 16) for k, v in PROJECT['symbolBindings'].items()}
        self.trial = {k: int(v, 16) for k, v in (extra or {}).items()}  # --bind: not yet in project.json
        self.names, self.ambiguous, self.by_address = {}, set(), {}
        for group in ('functions', 'data'):
            for text, name in index.get(group, {}).items():
                address = int(text, 16)
                self.by_address.setdefault(address, name)
                key = name.lstrip('_')
                if not key:
                    continue
                if key in self.names and self.names[key] != address:
                    self.ambiguous.add(key); del self.names[key]
                elif key not in self.ambiguous:
                    self.names[key] = address

    def resolve(self, symbol):
        if symbol in self.bindings:
            return self.bindings[symbol], 'binding'
        if symbol in self.trial:
            return self.trial[symbol], 'TRIAL binding (add to project.json before verifying)'
        embedded = [a for a in {int(m, 16) for m in HEX8.findall(symbol)} if a in self.by_address]
        if len(embedded) == 1:
            return embedded[0], 'embedded'
        key = symbol.lstrip('_')
        if key not in self.ambiguous and key in self.names:
            return self.names[key], 'name'
        return None, None


def original_bytes(address, size):
    data = open(os.path.join(ROOT, '.work', 'original.exe'), 'rb').read()
    pe = struct.unpack_from('<I', data, 60)[0]
    count, optional_size = struct.unpack_from('<H', data, pe + 6)[0], struct.unpack_from('<H', data, pe + 20)[0]
    optional = pe + 24; base = struct.unpack_from('<I', data, optional + 28)[0]
    for i in range(count):
        header = optional + optional_size + i * 40
        _, rva, raw_size, raw_offset = struct.unpack_from('<IIII', data, header + 8)
        relative = address - base - rva
        if 0 <= relative and relative + size <= raw_size:
            return data[raw_offset + relative: raw_offset + relative + size]
    raise SystemExit('not file-backed')


def coff_target(obj, target):
    """Target code bytes, relocations and symbol, with the verifier's refusals."""
    symbol_table, symbol_count = struct.unpack_from('<II', obj, 8)
    strings = symbol_table + symbol_count * 18
    entries, target_index, i = {}, None, 0
    while i < symbol_count:
        p = symbol_table + i * 18
        if struct.unpack_from('<I', obj, p)[0] == 0:
            start = strings + struct.unpack_from('<I', obj, p + 4)[0]
            name = obj[start:obj.index(b'\0', start)].decode()
        else:
            name = obj[p:p + 8].rstrip(b'\0').decode()
        value, section, kind, storage, aux = struct.unpack_from('<IhHBB', obj, p + 8)
        entries[i] = (name, section, value, kind, storage)
        if name == target:
            target_index = i
        i += 1 + aux
    if target_index is None:
        functions = [e[0] for e in entries.values() if e[3] == 0x20]
        raise ValueError(f'object lacks {target}; functions: {functions} (extern "C" missing?)')
    target_entry = entries[target_index]
    others = [e[0] for e in entries.values() if e[1] == target_entry[1] and e[3] == 0x20 and e[0] != target]
    if others:
        raise ValueError(f'backend refuses: other functions share the target section: {others}')
    header = 20 + (target_entry[1] - 1) * 40
    size, raw, relocations = struct.unpack_from('<III', obj, header + 16)
    relocation_count = struct.unpack_from('<H', obj, header + 32)[0]
    code = bytes(obj[raw:raw + size])
    relocs = []
    for k in range(relocation_count):
        offset, index, kind = struct.unpack_from('<IIH', obj, relocations + k * 10)
        relocs.append((offset, kind, entries[index]))
    return code, relocs, target_entry


def resolve(code, relocs, target_entry, address, resolver):
    out = bytearray(code); unresolved = []; used = {}
    for offset, kind, (name, section, value, _, storage) in relocs:
        if section > 0 and section == target_entry[1]:
            destination = address + value - target_entry[2]
        elif section == -1:
            destination = value
        elif storage == 2:
            destination, how = resolver.resolve(name)
            if destination is None:
                unresolved.append(name); continue
            used[name] = (destination, how)
        else:
            unresolved.append(name + ' (static; backend cannot bind it)'); continue
        addend = struct.unpack_from('<I', out, offset)[0]
        if kind == 0x06: result = destination + addend
        elif kind == 0x14: result = destination + addend - (address + offset + 4)
        else: raise ValueError('unsupported relocation %x' % kind)
        struct.pack_into('<I', out, offset, result & 0xffffffff)
    return bytes(out), unresolved, used


_warm = False
def warm_compiler():
    """Keep one Wine server alive so compiles cost ~0.1 s instead of ~3 s.
    Both the server and Wine's bootstrap services must get null descriptors,
    or they inherit the capture pipes and every compile waits for EOF
    (the trap pc-decomp's SetCompilerPersistence documents)."""
    global _warm
    if _warm or os.environ.get('GEX_PROBE_COLD'):
        return
    env = dict(os.environ, WINEPREFIX=TOOLCHAIN['winePrefix'], WINEDEBUG='-all')
    null = subprocess.DEVNULL
    subprocess.run(['wineserver', '-p900'], env=env, stdin=null, stdout=null, stderr=null)
    subprocess.run([TOOLCHAIN['wine'], 'cmd', '/c', 'exit'], env=env, stdin=null, stdout=null, stderr=null, timeout=60)
    _warm = True


def compile_source(text, flags, lang, keep_asm=False):
    """Compile in a private directory; returns (obj bytes or None, output, asm)."""
    warm_compiler()
    os.makedirs(SCRATCH, exist_ok=True)
    work = tempfile.mkdtemp(prefix='probe-', dir=SCRATCH)
    try:
        with open(os.path.join(work, 'source.cpp'), 'w') as f:
            f.write(text)
        win = lambda p: 'Z:' + os.path.abspath(p).replace('/', '\\')
        env = dict(os.environ, WINEPREFIX=TOOLCHAIN['winePrefix'], WINEDEBUG='-all',
                   WINEDLLOVERRIDES='winemenubuilder.exe=d', INCLUDE='', LIB='', CL='', _CL_='')
        source = ('/Tc' if lang == 'c' else '/Tp') + win(os.path.join(work, 'source.cpp'))
        command = [TOOLCHAIN['wine'], TOOLCHAIN['compiler'], '/nologo', '/c', *flags,
                   '/Fo' + win(os.path.join(work, 'target.obj'))]
        if keep_asm:
            command.append('/Fa' + win(os.path.join(work, 'target.asm')))
        result = subprocess.run(command + [source], cwd=work, env=env, capture_output=True, text=True, timeout=60)
        obj_path = os.path.join(work, 'target.obj')
        obj = open(obj_path, 'rb').read() if os.path.exists(obj_path) and result.returncode == 0 else None
        asm = open(os.path.join(work, 'target.asm'), errors='replace').read() if keep_asm and obj else ''
        return obj, result.stdout + result.stderr, asm
    finally:
        shutil.rmtree(work, ignore_errors=True)


def to_c(source):
    """Strip C++ linkage wrappers so a C++ candidate can be tried under /Tc."""
    blocks = len(re.findall(r'extern\s+"C"\s*\{', source))
    text = re.sub(r'extern\s+"C"\s*\{', '', source)
    text = re.sub(r'extern\s+"C"\s+', '', text)
    lines = text.rstrip().split('\n')
    while blocks and lines:
        if lines[-1].strip() == '}': lines.pop(); blocks -= 1
        elif not lines[-1].strip(): lines.pop()
        else: break
    return '\n'.join(lines) + '\n'


MAX_TRAILING_DATA = 4096


def trailing_data(relocs, candidate, address, extent, entries):
    """pc-decomp Verifier.TrailingData: bytes after the extent that the code
    references through a DIR32 relocation (switch tables), unless another
    function starts inside them."""
    extra = len(candidate) - extent
    if extra <= 0 or extra > MAX_TRAILING_DATA:
        return 0
    referenced = any(kind == 0x06 and offset + 4 <= extent and
                     address + extent <= struct.unpack_from('<I', candidate, offset)[0] < address + len(candidate)
                     for offset, kind, _ in relocs)
    if not referenced or any(address < e < address + len(candidate) for e in entries):
        return 0
    return extra


class Probe:
    """Reusable comparison context for one function (searches call measure())."""
    def __init__(self, address, bind=None):
        self.address = address.lower().replace('0x', '').zfill(8)
        db = database()
        self.record = function_record(self.address, db)
        # PROBE_BIND=SYM=ADDR[,SYM=ADDR] gives every search script (perturb, lperm,
        # blockperm, ...) the same trial bindings without a flag of its own.
        env = dict(b.split('=', 1) for b in os.environ.get('PROBE_BIND', '').split(',') if '=' in b)
        self.resolver = Resolver(db, {**env, **(bind or {})} or None)
        self.original = original_bytes(int(self.address, 16), int(self.record['size']))
        self.entries = [int(json.loads(b)['entry'], 16) for (b,) in db.execute("select body from records where resource='functions'")]

    def measure(self, source, lang=None, flags=None, keep_asm=False):
        flags, lang, target = contract(self.address, lang, flags)
        text = to_c(source) if lang == 'c' and 'extern "C"' in source else source
        obj, output, asm = compile_source(text, flags, lang, keep_asm)
        result = {'address': self.address, 'lang': lang, 'flags': flags, 'compiled': obj is not None,
                  'output': output, 'asm': asm, 'exact': False, 'percent': None}
        if obj is None:
            return result
        try:
            code, relocs, entry = coff_target(obj, target)
        except ValueError as e:
            result['error'] = str(e); return result
        candidate, unresolved, used = resolve(code, relocs, entry, int(self.address, 16), self.resolver)
        original = self.original
        trailing = trailing_data(relocs, candidate, int(self.address, 16), len(original), self.entries)
        if trailing:
            original = original_bytes(int(self.address, 16), len(original) + trailing)
        result['trailing'] = trailing
        total = max(len(original), len(candidate))
        equal = sum(1 for a, b in zip(original, candidate) if a == b)
        trial = sorted(k for k, v in used.items() if v[1].startswith('TRIAL'))
        rejected = input_rejection(source)
        percent = 100.0 * equal / total
        if os.environ.get('PROBE_METRIC') == 'aligned' and candidate != original:
            # Positional equality collapses after the first inserted or
            # deleted byte, so a search cannot see a fix that shifts the rest
            # of the function. Compare instruction text instead, with branch
            # targets and relocated symbols normalised away.
            percent = aligned_percent(original, candidate, int(self.address, 16), self.resolver)
        result.update(candidate=candidate, unresolved=unresolved, used=used, percent=percent, trial=trial,
                      rejected=rejected, exact=candidate == original and not unresolved and not rejected)
        return result


def input_rejection(source):
    """Mirror of pc-decomp Verifier.CheckInputs: the service refuses any '#'
    (even in a comment), digraph '%:', trigraphs, inline assembly and time
    macros, so a probe must not call such a source exact."""
    spliced = re.sub(r'\\\r?\n', '', source)
    if '#' in source or '%:' in source or re.search(r"\?\?[=/'()!<>-]", source) \
            or re.search(r'\b(__asm|_asm|asm|_emit|__DATE__|__TIME__|__TIMESTAMP__)\b', spliced):
        return 'verifier rejects this source: no preprocessor directives (no # anywhere), inline assembly or time macros'
    return None


def disassemble(data, address, resolver):
    import capstone
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    rows = []
    for ins in decoder.disasm(data, address):
        text = f'{ins.mnemonic} {ins.op_str}'.strip()
        text = re.sub(r'0x[0-9a-f]{6,8}', lambda m: m.group(0) + (f'<{resolver.by_address[int(m.group(0), 16)]}>' if int(m.group(0), 16) in resolver.by_address and int(m.group(0), 16) >= 0x401000 else ''), text)
        rows.append((ins.address, bytes(ins.bytes), text))
    return rows


def aligned_percent(original, candidate, address, resolver):
    """Similarity of two code blocks by instruction text (PROBE_METRIC=aligned).

    Branch targets inside the function are replaced by a placeholder so that a
    one-byte insertion does not make every later jump differ. 100 means the
    instruction streams are identical apart from branch displacement."""
    def rows(data):
        out = []
        for _, _, text in disassemble(data, address, resolver):
            if text.startswith('j'):
                text = re.sub(r'0x[0-9a-f]+', 'L', text)
            out.append(text)
        return out
    a, b = rows(original), rows(candidate)
    matcher = difflib.SequenceMatcher(None, a, b, autojunk=False)
    same = sum(block.size for block in matcher.get_matching_blocks())
    return 100.0 * same / max(len(a), len(b), 1)


def spans(a, b):
    out, start = [], None
    for i in range(max(len(a), len(b))):
        differs = i >= len(a) or i >= len(b) or a[i] != b[i]
        if differs and start is None: start = i
        if not differs and start is not None: out.append((start, i - start)); start = None
    if start is not None: out.append((start, max(len(a), len(b)) - start))
    return out


def report(probe, result, diff_only=False):
    r = result
    print(f"{probe.address} {probe.record['name']}  lang={r['lang']} flags={' '.join(r['flags'])}")
    if not r['compiled']:
        print('COMPILE FAILED'); print(r['output'][-3000:]); return
    if 'error' in r:
        print('REFUSED:', r['error']); return
    print(f"original {len(probe.original)}B candidate {len(r['candidate'])}B  positional {r['percent']:.1f}%  "
          f"{'EXACT' if r['exact'] else 'differs'}" + (f"  UNRESOLVED {r['unresolved']}" if r['unresolved'] else ''))
    if r.get('rejected'): print('REJECTED:', r['rejected'])
    print('mismatch spans (offset,len):', spans(probe.original if not r.get('trailing') else original_bytes(int(probe.address, 16), len(probe.original) + r['trailing']), r['candidate'])[:24])
    trial = sorted(k for k, v in r['used'].items() if v[1].startswith('TRIAL'))
    if trial: print('uses TRIAL bindings (not proof until in project.json):', ', '.join(trial))
    original = probe.original if not r.get('trailing') else original_bytes(int(probe.address, 16), len(probe.original) + r['trailing'])
    if r.get('trailing'): print(f"compared {r['trailing']} trailing switch-data bytes beyond the extent")
    a = disassemble(original, int(probe.address, 16), probe.resolver)
    b = disassemble(r['candidate'], int(probe.address, 16), probe.resolver)
    matcher = difflib.SequenceMatcher(a=[x[2] + x[1].hex() for x in a], b=[x[2] + x[1].hex() for x in b], autojunk=False)
    for tag, i1, i2, j1, j2 in matcher.get_opcodes():
        if diff_only and tag == 'equal': continue
        for k in range(max(i2 - i1, j2 - j1)):
            left = a[i1 + k] if i1 + k < i2 else None; right = b[j1 + k] if j1 + k < j2 else None
            mark = ' ' if tag == 'equal' else '|' if left and right else '<' if left else '>'
            ls = f'{left[0]:06x} {left[1].hex():<12.12} {left[2]}' if left else ''
            rs = f'{right[0]:06x} {right[1].hex():<12.12} {right[2]}' if right else ''
            print(f'{ls[:72]:72} {mark} {rs[:72]}')


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('address'); parser.add_argument('source')
    parser.add_argument('--lang', choices=('c', 'cpp', 'both')); parser.add_argument('--flags')
    parser.add_argument('-d', '--diff-only', action='store_true'); parser.add_argument('-q', '--quiet', action='store_true')
    parser.add_argument('--asm', action='store_true', help='print the compiler listing (/Fa)')
    parser.add_argument('--bind', action='append', default=[], metavar='SYMBOL=ADDRESS',
                        help='trial binding for a symbol the pinned inventory lacks; verification still needs it in project.json')
    args = parser.parse_args()
    probe = Probe(args.address, dict(b.split('=', 1) for b in args.bind))
    source = open(args.source).read()
    langs = ('cpp', 'c') if args.lang == 'both' else (args.lang,)
    best = 2
    for lang in langs:
        started = time.time()
        result = probe.measure(source, lang, args.flags.split() if args.flags else None, keep_asm=args.asm)
        if args.asm and result['asm']: print(result['asm'])
        if args.quiet:
            state = ('EXACT (with TRIAL bindings %s)' % ', '.join(result['trial']) if result['exact'] and result['trial'] else 'EXACT') if result['exact'] else ('%.1f%%' % result['percent'] if result['percent'] is not None else 'compile failed')
            if result.get('rejected'): state += ' REJECTED (' + result['rejected'] + ')'
            print(f"{probe.address} lang={result['lang']} {state} ({time.time() - started:.2f}s)")
        else:
            report(probe, result, args.diff_only)
        if result['exact']: best = 0
    return best


if __name__ == '__main__':
    sys.exit(main())
