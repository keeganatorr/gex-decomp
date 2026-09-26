#!/usr/bin/env python3
"""lperm.py ADDR FILE [lang...]: try every order of the first function's
consecutive local declaration lines (<=6), each language. Writes FILE.lp.cpp
with the best."""
import sys, re, itertools
sys.path.insert(0, __import__('os').path.dirname(__import__('os').path.abspath(__file__))); import probe
addr, path = sys.argv[1], sys.argv[2]; langs = sys.argv[3:] or ['cpp', 'c']
p = probe.Probe(addr); L = open(path).read().split('\n')
start = next(i for i, l in enumerate(L) if l.strip() == '{' and i > 0 and 'GEX_Target' in L[i-1]) + 1
end = start
while end < len(L) and re.match(r'^\s+[\w ]+[\s\*]+\w+(\[\d+\])?(, *\**\w+)*;$', L[end]) and '=' not in L[end] and not L[end].strip().startswith('return'): end += 1
decls = L[start:end]; print('decls', decls)
best = (-1, None, None)
def orders(d):
    if len(d) <= 5:
        yield from itertools.permutations(d); return
    seen = set()
    for k in range(len(d) - 4):            # every order of each 5-wide window
        for w in itertools.permutations(d[k:k + 5]):
            o = tuple(d[:k]) + w + tuple(d[k + 5:])
            if o not in seen: seen.add(o); yield o
    for i in range(len(d)):                # plus single moves across the whole list
        for j in range(len(d)):
            if i != j:
                e = list(d); x = e.pop(i); e.insert(j, x)
                if tuple(e) not in seen: seen.add(tuple(e)); yield tuple(e)
for perm in orders(decls):
    s = L[:start] + list(perm) + L[end:]
    for lang in langs:
        r = p.measure('\n'.join(s), lang); pc = r['percent'] or 0
        if r['exact']:
            open(path.replace('.cpp', '.lp.cpp'), 'w').write('\n'.join(s)); print('EXACT', lang, perm); sys.exit(0)
        if pc > best[0]: best = (pc, lang, s)
open(path.replace('.cpp', '.lp.cpp'), 'w').write('\n'.join(best[2])); print('best', round(best[0], 1), best[1])
