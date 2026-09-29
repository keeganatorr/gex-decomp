"""Place up to three local declarations at every combination of positions.

    tools/declgrid.py ADDRESS SOURCE NAME [NAME [NAME]] [--lang c] [--write OUT]

declclimb.py moves one declaration at a time and keeps a move only when it
helps, so it stalls when two declarations must move together. CL 10.00
orders the operands of an address like [base+index] by the symbols involved:
0041e9d0 had `[eax+ecx+0xc]` for one heights[] load and `[ecx+eax+0xc]` for
another, and only a joint placement of `contour`, `li` and `i4` among the
other locals produced both (declclimb, pads and 64 index spellings had not).
NAMEs are local variable names; every other local keeps its relative order.
With three names over n locals this is n**3 compiles, run in parallel.
Probes never publish; the first exact candidate is written to --write.
"""
import itertools
import os
import re
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from probe import Probe  # noqa: E402

ARGS = sys.argv[1:]
LANG = ARGS[ARGS.index('--lang') + 1] if '--lang' in ARGS else None
OUT = ARGS[ARGS.index('--write') + 1] if '--write' in ARGS else None
POS = [a for i, a in enumerate(ARGS) if not a.startswith('--') and (i == 0 or ARGS[i - 1] not in ('--lang', '--write'))]
ADDRESS, PATH, NAMES = (POS[0], POS[1], POS[2:]) if len(POS) >= 3 else (None, None, [])

LINES = open(PATH).read().split('\n') if PATH else []
DECL = re.compile(r'^    [A-Za-z_][\w \*]*?\b(\w+)(\[[^\]]*\])?;\s*$')


def local_block():
    start = next(i for i, l in enumerate(LINES) if 'GEX_Target' in l and not l.rstrip().endswith(';'))
    first = start + 2
    end = first
    while end < len(LINES) and DECL.match(LINES[end]):
        end += 1
    return first, end


def build(positions):
    first, end = local_block()
    decls = LINES[first:end]
    moving = {n: next(d for d in decls if DECL.match(d).group(1) == n) for n in NAMES}
    order = [d for d in decls if DECL.match(d).group(1) not in NAMES]
    for name, pos in sorted(zip(NAMES, positions), key=lambda x: x[1]):
        order.insert(pos, moving[name])
    return '\n'.join(LINES[:first] + order + LINES[end:])


_probe = None


def score(positions):
    global _probe
    if _probe is None:
        _probe = Probe(ADDRESS)
    r = _probe.measure(build(positions), lang=LANG)
    return (r['percent'] or 0, bool(r['exact']))


def main():
    if not NAMES or len(NAMES) > 3:
        sys.exit(__doc__)
    first, end = local_block()
    slots = end - first - len(NAMES) + 1
    cands = list(itertools.product(range(slots), repeat=len(NAMES)))
    with ProcessPoolExecutor(max(1, (os.cpu_count() or 2) - 2)) as ex:
        results = list(ex.map(score, cands, chunksize=8))
    ranked = sorted(zip(results, cands), reverse=True)
    for (pct, exact), pos in ranked[:5]:
        print(f'{pct:.1f}%', 'EXACT' if exact else '', pos)
    hit = next((pos for (pct, exact), pos in ranked if exact), None)
    if hit is not None and OUT:
        open(OUT, 'w').write(build(hit))


if __name__ == '__main__':
    main()
