#!/usr/bin/env python3
"""Per-case diff for a function built around a jump-table switch.

    tools/casediff.py ADDRESS SOURCE [--lang c|cpp] [--swap esi:edi] [--cases 1,0x1e] [-v]

Whole-function scores are useless on a big switch: one register choice moves
every later offset, and the aligned metric still counts a swapped esi/edi as a
difference on every line. This splits the original and the candidate at their
jump tables (`jmp dword ptr [reg*4 + TABLE]`), pairs the blocks case by case,
normalises branch targets, and counts mismatched instructions per case, plus
the code before the first case ("head"). `--swap esi:edi` renames one register
pair in the candidate only, which separates "the case body is right but a
global allocation is swapped" from real differences (00435d90 GOB_RunScript).

The count for one case is the number of instructions outside the longest
common subsequence of the two blocks, so a dropped or moved instruction costs
one line, not the rest of the block. Use it as a search objective: the total
fell from 231 to 22 on RunScript while the positional percentage stayed near
30%.
"""
import argparse, difflib, os, re, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import probe  # noqa: E402

TABLE_JUMP = re.compile(r'jmp dword ptr \[e(?:[a-d]x|si|di|bp)\*4 \+ 0x([0-9a-f]+)')
BRANCH = re.compile(r'0x4[0-9a-f]{5}\b(?!<)')


BYTE_MAP = re.compile(r'mov [a-d]l, byte ptr \[e(?:[a-d]x|si|di|bp) \+ 0x([0-9a-f]+)')
BOUND = re.compile(r'cmp e(?:[a-d]x|si|di|bp), (0x[0-9a-f]+|\d+)$')


def tables(ins, data, base, read=None):
    """(table address, entries) for every jump table; entries stop at the first
    word that does not point into the function. A table past the extent (the
    original's extent stops before its tables) is read through `read`.

    A sparse switch compiles to a byte map indexed by the case value and a
    dword table of distinct targets (`mov al, [ecx + MAP]; jmp [eax*4 + T]`).
    The dword table's order follows the source order of the case bodies, so
    those entries are expanded per case value through the map: pairing by
    value survives reordering the cases in the source."""
    out = []
    end = base + len(data)

    def word(addr, size):
        off = addr - base
        if 0 <= off <= len(data) - size:
            return data[off:off + size]
        return read(addr, size) if read else None

    for k, (a, b, t) in enumerate(ins):
        m = TABLE_JUMP.search(t)
        if not m:
            continue
        tab = int(m.group(1), 16)
        entries = []
        addr = tab
        while True:
            w = word(addr, 4)
            if w is None:
                break
            v = struct.unpack('<I', w)[0]
            if not base <= v < end:
                break
            entries.append(v)
            addr += 4
        mm = BYTE_MAP.search(ins[k - 1][2]) if k else None
        bound = next((int(x.group(1), 0) for _, _, pt in reversed(ins[max(0, k - 8):k]) for x in [BOUND.search(pt)] if x), None)
        if mm and bound is not None:
            raw = word(int(mm.group(1), 16), bound + 1)
            if raw is not None:
                entries = [entries[c] if c < len(entries) else None for c in raw]
                entries = [e for e in entries if e is not None]
        out.append((tab, entries))
    return out


def normalise(text, swap=None):
    if swap and not re.match(r'(push|pop) ', text):
        a, b = swap
        text = re.sub(rf'\b({a}|{b})\b', lambda m: b if m.group(1) == a else a, text)
    if text.split()[0].startswith('j') and 'dword ptr [' not in text:
        text = BRANCH.sub('ADDR', text)
    return text


def blocks(ins, starts, limit):
    """Instructions from each start to the next start (or limit)."""
    starts = sorted(set(starts))
    out = {}
    for i, s in enumerate(starts):
        nxt = starts[i + 1] if i + 1 < len(starts) else limit
        out[s] = [t for a, b, t in ins if s <= a < nxt]
    return out


def mismatches(x, y):
    sm = difflib.SequenceMatcher(None, x, y, autojunk=False)
    return max(len(x), len(y)) - sum(m.size for m in sm.get_matching_blocks())


_PROBES = {}


def compare(address, source, lang=None, swap=None):
    # One Probe per address: building it reads the database and the symbol
    # index, which costs more than a compile when a search calls this often.
    p = _PROBES.get(address) or _PROBES.setdefault(address, probe.Probe(address))
    base = int(address, 16)
    r = p.measure(source, lang=lang)
    if not r['compiled']:
        raise SystemExit(r['output'][-2000:])
    orig, cand = p.original, r['candidate']
    oins = probe.disassemble(orig, base, p.resolver)
    cins = probe.disassemble(cand, base, p.resolver)
    ot, ct = tables(oins, orig, base, probe.original_bytes), tables(cins, cand, base)
    if not ot or len(ot) != len(ct):
        # No switch, or the candidate's switches do not pair up yet: one row
        # for the code, so the count still serves as a search objective.
        oend = min([t for t, _ in ot] + [base + len(orig)])
        cend = min([t for t, _ in ct] + [base + len(cand)])
        return r, [('all', [normalise(t) for a, b, t in oins if a < oend], [normalise(t, swap) for a, b, t in cins if a < cend])]
    # Code ends at the first table; everything after it is data.
    olimit = min([t for t, _ in ot] + [base + len(orig)])
    climit = min(t for t, _ in ct)
    oins = [i for i in oins if i[0] < olimit]
    cins = [i for i in cins if i[0] < climit]
    ostarts = {e for _, es in ot for e in es}
    cstarts = {e for _, es in ct for e in es}
    ob, cb = blocks(oins, ostarts, olimit), blocks(cins, cstarts, climit)
    rows = []
    head_o = [normalise(t) for a, b, t in oins if a < min(ostarts)]
    head_c = [normalise(t, swap) for a, b, t in cins if a < min(cstarts)]
    rows.append(('head', head_o, head_c))
    seen = set()
    for n, ((otab, oes), (ctab, ces)) in enumerate(zip(ot, ct)):
        for i, (oe, ce) in enumerate(zip(oes, ces)):
            if oe in seen:
                continue
            seen.add(oe)
            label = f'{i}' if len(ot) == 1 else f'{n}:{i}'
            rows.append((label, [normalise(t) for t in ob[oe]], [normalise(t, swap) for t in cb[ce]]))
    return r, rows


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('address')
    ap.add_argument('source')
    ap.add_argument('--lang', choices=['c', 'cpp'])
    ap.add_argument('--swap', help='register pair renamed in the candidate, e.g. esi:edi')
    ap.add_argument('--cases', help='comma-separated table indexes to print side by side')
    ap.add_argument('-v', action='store_true', help='print every mismatching case side by side')
    a = ap.parse_args()
    address = a.address.lower().zfill(8)
    swap = tuple(a.swap.split(':')) if a.swap else None
    r, rows = compare(address, open(a.source).read(), a.lang, swap)
    want = {int(x, 0) for x in a.cases.split(',')} if a.cases else set()
    total = 0
    counts = []
    for label, x, y in rows:
        m = mismatches(x, y)
        total += m
        if m:
            counts.append(f'{label}:{m}')
        show = (a.v and m) or (label not in ('head', 'all') and int(label.split(':')[-1]) in want)
        if show:
            print(f'== {label}')
            for i in range(max(len(x), len(y))):
                u = x[i] if i < len(x) else ''
                w = y[i] if i < len(y) else ''
                print(('   ' if u == w else ' * ') + f'{u[:60]:60} | {w[:60]}')
    print(f"{address} total {total}  positional {r['percent']:.1f}%")
    print(' '.join(counts))


if __name__ == '__main__':
    main()
