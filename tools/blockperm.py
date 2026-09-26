#!/usr/bin/env python3
"""blockperm.py ADDR FILE [lang]: for each run of 2-6 consecutive simple
statements at one indentation, try every order (exact bytes prove
equivalence, so dependencies are not checked). Keeps any improvement and
repeats until no run improves. Writes FILE.bp.cpp."""
import sys, itertools
sys.path.insert(0, __import__('os').path.dirname(__import__('os').path.abspath(__file__))); import probe
addr, path = sys.argv[1], sys.argv[2]; lang = sys.argv[3] if len(sys.argv) > 3 else None
p = probe.Probe(addr); L = open(path).read().split('\n')
KEYW = ('return', 'break', 'continue', '//', 'extern', 'typedef', 'goto', 'if', 'else', 'for', 'while', 'do', 'switch', 'case', 'default')
def movable(l):
    t = l.strip()
    if not t.endswith(';') or t.startswith(KEYW) or '{' in t or '}' in t: return False
    return '=' in t or '++' in t or '--' in t or t.endswith(');')
def runs(L):
    out, i = [], 0
    body = next(i for i, l in enumerate(L) if 'GEX_Target' in l)
    i = body
    while i < len(L):
        if movable(L[i]) and len(L[i]) - len(L[i].lstrip()) >= 4:
            ind = len(L[i]) - len(L[i].lstrip()); j = i
            while j < len(L) and movable(L[j]) and len(L[j]) - len(L[j].lstrip()) == ind: j += 1
            if j - i > 1:
                for k in range(i, max(i + 1, j - 5)):   # windows of up to 6
                    out.append((k, min(j, k + 6)))
            i = j
        else: i += 1
    return out
def score(lines):
    r = p.measure('\n'.join(lines), lang); return (r['percent'] or 0) if r['compiled'] else -1, r['exact']
best, ex = score(L); print('baseline', round(best, 1), runs(L))
improved = True
while improved and not ex:
    improved = False
    for a, b in runs(L):
        for perm in itertools.permutations(L[a:b]):
            M = L[:a] + list(perm) + L[b:]
            s, e = score(M)
            if e or s > best + 1e-9:
                best, ex, L, improved = s, e, M, True; print('improved', round(best, 1)); break
        if ex: break
open(path.replace('.cpp', '.bp.cpp'), 'w').write('\n'.join(L))
print('EXACT' if ex else 'best %.1f' % best)
