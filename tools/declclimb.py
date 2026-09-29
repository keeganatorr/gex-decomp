"""declclimb.py ADDR FILE [--locals]: greedy best-move hill climb over top-level declaration order
(and optionally GEX_Target local declaration order), casediff objective. Writes FILE.dc.cpp. PROBE_BIND honoured."""
import sys, os, re
from concurrent.futures import ProcessPoolExecutor
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__))); sys.path.insert(0, os.path.join(ROOT, 'tools')); os.chdir(ROOT)
import casediff, perturb
addr, path = sys.argv[1], sys.argv[2]
use_locals = '--locals' in sys.argv
lang = 'c' if path.endswith('.c') else 'cpp'
src = open(path).read()
def split(s):
    lines = s.split('\n')
    top = perturb.declaration_lines(lines)
    loc = []
    if use_locals:
        for i, l in enumerate(lines):
            if re.match(r'\s*void __cdecl GEX_Target|\s*\w[\w\s\*]*GEX_Target\(', l):
                j = i + 2
                while j < len(lines) and re.match(r'    [A-Za-z_][\w\s\*]*[\w\]];\s*$', lines[j]) and '=' not in lines[j] and '(' not in lines[j]:
                    loc.append(j); j += 1
                break
    return lines, [top, loc]
def score(s):
    try:
        r, rows = casediff.compare(addr, s, lang, None)
        return sum(casediff.mismatches(x, y) for _, x, y in rows) if rows else 10**9
    except BaseException:
        return 10**9
def moves(s):
    lines, groups = split(s)
    for g in groups:
        content = [lines[i] for i in g]
        for i in range(len(content)):
            for j in range(len(content)):
                if i == j: continue
                order = list(content); order.insert(j, order.pop(i))
                out = list(lines)
                for k, idx in enumerate(g): out[idx] = order[k]
                yield '\n'.join(out)
if __name__ == '__main__':
    best = score(src); print('start', best, flush=True)
    with ProcessPoolExecutor(22) as ex:
        while best > 0:
            cands = list(moves(src))
            sc = list(ex.map(score, cands, chunksize=4))
            k = min(range(len(sc)), key=sc.__getitem__)
            if sc[k] >= best: break
            best, src = sc[k], cands[k]
            open(path + '.dc.cpp', 'w').write(src); print('best', best, flush=True)
    print('done', best)
