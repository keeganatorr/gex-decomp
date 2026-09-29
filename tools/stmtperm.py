"""stmtperm.py ADDR FILE START END [--write OUT]: try every order of source lines START..END (1-based, inclusive,
<= 8 lines), casediff objective (PROBE_BIND honoured). Prints the best few; writes the best to OUT (default FILE)."""
import sys, os, itertools
from concurrent.futures import ProcessPoolExecutor
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__))); sys.path.insert(0, os.path.join(ROOT, 'tools')); os.chdir(ROOT)
import casediff
addr, path, a, b = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
out = sys.argv[sys.argv.index('--write') + 1] if '--write' in sys.argv else path
lines = open(path).read().split('\n')
seg = lines[a - 1:b]
lang = 'c' if path.endswith('.c') else 'cpp'
def build(p): return '\n'.join(lines[:a - 1] + list(p) + lines[b:])
def score(p):
    try:
        r, rows = casediff.compare(addr, build(p), lang, None)
        return sum(casediff.mismatches(x, y) for _, x, y in rows) if rows else 10**9
    except BaseException:
        return 10**9
if __name__ == '__main__':
    perms = list(itertools.permutations(seg))
    with ProcessPoolExecutor(22) as ex:
        sc = list(ex.map(score, perms, chunksize=8))
    best = sorted(zip(sc, range(len(perms))))[:4]
    base = score(tuple(seg))
    print('base', base)
    for s, k in best: print(s, [l.strip() for l in perms[k]])
    if best[0][0] < base:
        open(out, 'w').write(build(perms[best[0][1]])); print('wrote', out)
