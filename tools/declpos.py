#!/usr/bin/env python3
"""Exhaustive placement of a few local declarations, scored per case.

    tools/declpos.py ADDRESS FILE VAR[,VAR...] [--lang c|cpp] [--jobs N] [--top K]

Every placement of the named locals among the other declarations of
GEX_Target is compiled (the others keep their relative order) and scored with
tools/casediff.py; the best orders are printed and the best source is written
to FILE.dp.cpp. PROBE_BIND is honoured as in tools/probe.py.

Why exhaustive: CL 10.00 breaks register-allocation ties by declaration order,
and the right order for two or three variables is often a combination that a
greedy one-move search (tools/altsearch.py) never reaches, because each single
move on the way scores worse. Three names among ten declarations are 720
compiles, a couple of minutes with --jobs 12. 00439390 (prologue `lea edi,
[row+8]` scheduled first) was found this way; the negative result is also
useful: when no placement moves a register swap, the residue is not a
declaration-order one and further decl searches are wasted.
"""
import argparse, itertools, os, re, sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import casediff

DECLS = re.compile(r'(GEX_Target\([^)]*\)\n\{\n)((?:    (?:(?:unsigned|signed|struct|const|register|volatile)\s+)*\w+[\s*]+\w+(?:\[[^\]]*\])?;\n)+)')
_STATE = {}


def name(decl):
    return re.sub(r'[\[\];=].*', '', decl.split()[-1]).lstrip('*')


def _init(address, text, lang):
    _STATE.update(address=address, text=text, lang=lang)


def score(order):
    s = _STATE['text']
    m = DECLS.search(s)
    try:
        _, rows = casediff.compare(_STATE['address'], s[:m.start(2)] + ''.join(order) + s[m.end(2):], _STATE['lang'])
    except BaseException:
        return 10 ** 9
    return sum(casediff.mismatches(x, y) for _, x, y in rows)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('address')
    ap.add_argument('file')
    ap.add_argument('names')
    ap.add_argument('--lang', choices=['c', 'cpp'])
    ap.add_argument('--jobs', type=int, default=os.cpu_count() or 4)
    ap.add_argument('--top', type=int, default=5)
    a = ap.parse_args()
    address = a.address.lower().zfill(8)
    lang = a.lang or ('c' if a.file.endswith('.c') else 'cpp')
    text = open(a.file).read()
    m = DECLS.search(text)
    if not m:
        raise SystemExit('no declaration block after GEX_Target')
    decls = m.group(2).splitlines(keepends=True)
    want = a.names.split(',')
    movers = [d for d in decls if name(d) in want]
    rest = [d for d in decls if name(d) not in want]
    if len(movers) != len(want):
        raise SystemExit(f'declared: {[name(d) for d in decls]}')
    orders = []
    n = len(decls)
    for pos in itertools.permutations(range(n), len(movers)):
        slots = [None] * n
        for p, d in zip(pos, movers):
            slots[p] = d
        it = iter(rest)
        orders.append([d if d is not None else next(it) for d in slots])
    with ProcessPoolExecutor(a.jobs, initializer=_init, initargs=(address, text, lang)) as pool:
        scores = list(pool.map(score, orders, chunksize=4))
    ranked = sorted(range(len(orders)), key=lambda i: scores[i])
    print(f'{len(orders)} placements; current order scores {scores[orders.index(decls)]}')
    for i in ranked[:a.top]:
        print(scores[i], ' '.join(name(d) for d in orders[i]))
    best = orders[ranked[0]]
    open(a.file + '.dp.cpp', 'w').write(text[:m.start(2)] + ''.join(best) + text[m.end(2):])


if __name__ == '__main__':
    main()
