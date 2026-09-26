#!/usr/bin/env python3
"""Permute a run of local assignments together with the locals' declarations.

A save/restore block such as `x = gob->x; y = gob->y; plut = gob->plut;`
decides register and stack-slot assignment through two things at once: the
order the loads are written in and the order the locals are declared in.
lperm.py (declarations) and stperm.py (statements) each search one of them
and can both miss a pair that only works together; 00433ec0 went from 62.8%
to exact only on the joint search.

For every run of 2-4 consecutive `name = expr;` statements whose names are
distinct locals, try every order of the run times every order of those
locals' declarations (other declarations stay put). Writes FILE.jp.cpp and
prints EXACT <lang> on a match, else the best score.

    jointperm.py ADDRESS FILE [--languages cpp,c] [--max-run 4]
"""
import argparse, itertools, os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import probe

ASSIGN = re.compile(r'^\s+([A-Za-z_]\w*) = [^;=]+;\s*$')
DECL = re.compile(r'^\s+(?:unsigned |signed |const |struct )*[A-Za-z_]\w*[\s\*]+([A-Za-z_]\w*)(\[[^\]]*\])?;\s*$')


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('address'); ap.add_argument('source')
    ap.add_argument('--languages', default='cpp,c'); ap.add_argument('--max-run', type=int, default=4)
    args = ap.parse_args()
    p = probe.Probe(args.address)
    lines = open(args.source).read().split('\n')
    start = next(i for i, l in enumerate(lines) if 'GEX_Target' in l and '(' in l)
    body = next(i for i in range(start, len(lines)) if lines[i].strip() == '{') + 1
    end = next(i for i in range(body, len(lines)) if lines[i].rstrip() == '}')
    decl_idx = {DECL.match(lines[i]).group(1): i for i in range(body, end) if DECL.match(lines[i])}
    runs = []
    j = body
    while j < end:
        k = j
        names = []
        while k < len(lines) and ASSIGN.match(lines[k]) and ASSIGN.match(lines[k]).group(1) in decl_idx \
                and ASSIGN.match(lines[k]).group(1) not in names:
            names.append(ASSIGN.match(lines[k]).group(1)); k += 1
        if len(names) >= 2:
            for a in range(len(names)):
                for b in range(a + 2, min(len(names), a + args.max_run) + 1):
                    runs.append((j + a, j + b))
        j = max(k, j + 1)
    langs = args.languages.split(',')
    best = (-1, None, None)
    tried = 0
    for lo, hi in runs:
        stmts = lines[lo:hi]
        names = [ASSIGN.match(s).group(1) for s in stmts]
        slots = sorted(decl_idx[n] for n in names)
        decls = [lines[s] for s in slots]
        for sp in itertools.permutations(stmts):
            for dp in itertools.permutations(decls):
                cand = list(lines)
                cand[lo:hi] = sp
                for s, d in zip(slots, dp):
                    cand[s] = d
                text = '\n'.join(cand)
                for lang in langs:
                    tried += 1
                    r = p.measure(text, lang=lang)
                    if r['exact']:
                        out = args.source.replace('.cpp', '.jp.cpp')
                        open(out, 'w').write(text if lang == 'cpp' else probe.to_c(text))
                        print(f'tried {tried}'); print('EXACT', lang, out)
                        return 0
                    if r['compiled'] and r['percent'] is not None and r['percent'] > best[0]:
                        best = (r['percent'], lang, text)
    if best[2]:
        open(args.source.replace('.cpp', '.jp.cpp'), 'w').write(best[2])
    print(f'tried {tried}'); print(f'best {best[0]:.1f} {best[1]}')
    return 2


if __name__ == '__main__':
    sys.exit(main())
