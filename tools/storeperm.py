#!/usr/bin/env python3
"""Try every order of each run of straight-line assignments.

After a call, CL 10.00's scheduler decides where a shared zero (`xor r, r`)
and the next call's argument pushes land from the *whole* order of the stores
around them, not from any one adjacent pair. stperm.py searches by local
moves and missed both 004248e0 and 004263b0; the full permutation of their six
stores found each in under a minute. Runs of up to --max-run consecutive
`lhs = rhs;` lines (no control flow, same indentation) are permuted in full;
a longer run is searched in sliding windows of that size.

Writes FILE.sp.cpp and prints EXACT <lang> on a match, else the best score.

    storeperm.py ADDRESS FILE [--languages cpp,c] [--max-run 7]
"""
import argparse, itertools, os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import probe

STORE = re.compile(r'^(\s+)[^\s{}()][^;{}]*[^=!<>+\-*/%&|^]=[^=][^;{}]*;\s*$')


def runs(lines, body, end, max_run):
    j = body
    while j < end:
        if not STORE.match(lines[j]):
            j += 1
            continue
        indent = STORE.match(lines[j]).group(1)
        k = j
        while k < end and STORE.match(lines[k]) and STORE.match(lines[k]).group(1) == indent:
            k += 1
        if k - j >= 2:
            if k - j <= max_run:
                yield j, k
            else:
                for lo in range(j, k - max_run + 1):
                    yield lo, lo + max_run
        j = k


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('address'); ap.add_argument('source')
    ap.add_argument('--languages', default='cpp,c'); ap.add_argument('--max-run', type=int, default=7)
    args = ap.parse_args()
    p = probe.Probe(args.address)
    text = open(args.source).read()
    lines = text.split('\n')
    start = next(i for i, l in enumerate(lines) if 'GEX_Target' in l and '(' in l)
    body = next(i for i in range(start, len(lines)) if lines[i].strip() == '{') + 1
    end = next(i for i in range(body, len(lines)) if lines[i].rstrip() == '}')
    langs = args.languages.split(',')
    out = args.source.replace('.cpp', '.sp.cpp')
    best, tried = (-1, None, None), 0
    for lo, hi in runs(lines, body, end, args.max_run):
        for perm in itertools.permutations(lines[lo:hi]):
            if list(perm) == lines[lo:hi] and tried:
                continue
            cand = '\n'.join(lines[:lo] + list(perm) + lines[hi:])
            for lang in langs:
                tried += 1
                source = cand if lang == 'cpp' else probe.to_c(cand)
                r = p.measure(source, lang=lang)
                if r['exact']:
                    open(out, 'w').write(source)
                    print(f'tried {tried}'); print('EXACT', lang, out)
                    return 0
                if r['compiled'] and r['percent'] is not None and r['percent'] > best[0]:
                    best = (r['percent'], lang, cand)
    if best[2]:
        open(out, 'w').write(best[2])
    print(f'tried {tried}'); print(f'best {best[0]:.1f} {best[1]}')
    return 2


if __name__ == '__main__':
    sys.exit(main())
