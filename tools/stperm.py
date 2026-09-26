#!/usr/bin/env python3
"""stperm.py ADDR FILE: greedy hill-climb over swaps of adjacent independent
simple statements (assignments with distinct lvalues, no calls, neither reads
the other's lvalue). Accepts any strict improvement; stops at a local optimum
or EXACT. Writes FILE.st.cpp."""
import re, sys
sys.path.insert(0, __import__('os').path.dirname(__import__('os').path.abspath(__file__))); import probe
addr, path = sys.argv[1], sys.argv[2]
p = probe.Probe(addr); L = open(path).read().split('\n')
assign = re.compile(r'^\s*(?:[\w\s\*]+\s)?([\w\->\.\[\]\*]+)\s*(\+|-|\||&)?=\s*(.+);\s*$')
def parts(l):
    m = assign.match(l)
    if not m or '==' in l or re.search(r'\w\s*\(', m.group(3)) or l.strip().startswith(('if', 'for', 'while', 'return', '//')): return None
    return m.group(1).strip(), m.group(3)
def reads(expr, lv): return re.search(r'(?<![\w>.])' + re.escape(lv) + r'(?![\w\[])', expr)
def movable(l):
    t = l.strip()
    return t.endswith(';') and not t.startswith(('return', 'break', 'continue', '//', 'extern', 'typedef', '#', 'goto')) and '{' not in t and '}' not in t
def independent(a, b):
    # Exact bytes prove equivalence, so any swap is admissible as a search step;
    # only statement shape and indentation are required.
    return movable(a) and movable(b) and len(a) - len(a.lstrip()) == len(b) - len(b.lstrip()) and len(a) - len(a.lstrip()) >= 4
def independent_strict(a, b):
    pa, pb = parts(a), parts(b)
    if not pa or not pb or pa[0] == pb[0]: return False
    if len(a) - len(a.lstrip()) != len(b) - len(b.lstrip()): return False
    return not reads(pb[1], pa[0]) and not reads(pa[1], pb[0]) and not reads(pa[0], pb[0]) and not reads(pb[0], pa[0])
def score(lines):
    r = p.measure('\n'.join(lines)); return (r['percent'] or 0), r['exact']
best, exact = score(L); print('baseline', round(best, 1))
# Local declaration lists: every order of `int a, b, c;` (numbering lever).
import itertools
decl = re.compile(r'^(\s+)((?:unsigned |signed |register |const )*(?:int|char|short|long|unsigned|[A-Z]\w*\s*\*?))\s+([^;(){}]+);\s*$')
for i, line in enumerate(list(L)):
    m = decl.match(line)
    if exact or not m or ',' not in m.group(3): continue
    names = [x.strip() for x in m.group(3).split(',')]
    if len(names) > 5: continue
    for order in itertools.permutations(names):
        M = list(L); M[i] = f'{m.group(1)}{m.group(2)} {", ".join(order)};'
        sc, ex = score(M)
        if sc > best:
            best, exact, L = sc, ex, M; print(round(best, 1), 'decl', M[i].strip())
            if exact: break
improved = True
while improved and not exact:
    improved = False
    for i in range(len(L) - 1):
        if not independent(L[i], L[i + 1]): continue
        M = list(L); M[i], M[i + 1] = M[i + 1], M[i]
        s, e = score(M)
        if s > best:
            best, exact, L, improved = s, e, M, True
            print(round(best, 1), 'swap', L[i + 1].strip()[:30], '<->', L[i].strip()[:30])
            if exact: break
open(path.replace('.cpp', '.st.cpp'), 'w').write('\n'.join(L)); print('EXACT' if exact else 'best %.1f' % best)
