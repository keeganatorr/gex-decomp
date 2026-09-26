#!/usr/bin/env python3
"""mvperm.py ADDR FILE [lang]: hill-climb over moving any single movable
statement (same indentation, inside the target function's outermost block
run) to any other position in its run. Exact bytes prove equivalence, so the
search does not check dependencies. Writes FILE.mv.cpp with the best."""
import sys, re
sys.path.insert(0, __import__('os').path.dirname(__import__('os').path.abspath(__file__))); import probe
addr, path = sys.argv[1], sys.argv[2]; lang = sys.argv[3] if len(sys.argv) > 3 else None
p = probe.Probe(addr); L = open(path).read().split('\n')
def movable(l):
    t = l.strip()
    return t.endswith(';') and not t.startswith(('return', 'break', 'continue', '//', 'extern', 'typedef', 'goto', 'int ', 'unsigned ', 'char ', 'short ')) and '{' not in t and '}' not in t
# runs: maximal consecutive movable lines with equal indentation
runs, i = [], 0
while i < len(L):
    if movable(L[i]):
        ind = len(L[i]) - len(L[i].lstrip()); j = i
        while j < len(L) and movable(L[j]) and len(L[j]) - len(L[j].lstrip()) == ind: j += 1
        if j - i > 1: runs.append((i, j))
        i = j
    else: i += 1
def score(lines):
    r = p.measure('\n'.join(lines), lang); return (r['percent'] or 0), r['exact']
best, ex = score(L); print('baseline', round(best, 1), 'runs', runs)
improved = True
while improved and not ex:
    improved = False
    for a, b in runs:
        for i in range(a, b):
            for j in range(a, b):
                if i == j: continue
                M = list(L)
                if j > i: M[i], M[j] = M[j], M[i]      # pairwise swap
                else: x = M.pop(i); M.insert(j, x)   # move earlier
                s, e = score(M)
                if not (e or s > best + 1e-9) and j > i:
                    M = list(L); x = M.pop(i); M.insert(j, x)  # move later
                    s, e = score(M)
                if e or s > best + 1e-9:
                    best, ex, L = s, e, M; improved = True
                    print('improved', round(best, 1)); break
            if improved or ex: break
        if improved or ex: break
open(path.replace('.cpp', '.mv.cpp'), 'w').write('\n'.join(L))
print('EXACT' if ex else 'best %.1f' % best)
