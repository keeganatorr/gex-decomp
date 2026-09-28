#!/usr/bin/env python3
"""Rank whole-file source variants by instruction-level difference.

    rankvariants.py ADDRESS VARIANTS_FILE [cpp|c]

VARIANTS_FILE holds complete sources separated by a line `=====`. Each is
compiled with tools/probe.py's contract; the first exact one is written to
VARIANTS_FILE.v<k>.<lang>.cpp. Otherwise prints the five best variants by the
number of differing instructions (branch targets and relocated symbols
normalised), which unlike the positional percentage does not collapse when a
change shifts the rest of the function. Honours PROBE_BIND and PROBE_OVERRIDE.
"""
import collections, difflib, os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import probe


def main():
    address, path = sys.argv[1], sys.argv[2]
    lang = sys.argv[3] if len(sys.argv) > 3 else 'cpp'
    variants = open(path).read().split('\n=====\n')
    p = probe.Probe(address)
    normal = lambda t: re.sub(r'0x4[0-9a-f]{5}(<[^>]*>)?', 'J', t)
    original = [normal(t) for _, _, t in probe.disassemble(p.original, int(address, 16), p.resolver)]
    ranked = []
    for k, text in enumerate(variants):
        source = text if lang == 'cpp' else probe.to_c(text)
        r = p.measure(source, lang=lang)
        if r['exact']:
            out = f'{path}.v{k}.{lang}.cpp'
            open(out, 'w').write(source)
            print('EXACT', k, out)
            return 0
        if not r['compiled'] or not r.get('candidate'):
            continue
        candidate = [normal(t) for _, _, t in probe.disassemble(r['candidate'], int(address, 16), p.resolver)]
        ranked.append((sum(1 for line in difflib.ndiff(original, candidate) if line[:1] in '+-'), k))
    ranked.sort()
    print(ranked[:5], dict(collections.Counter(n for n, _ in ranked)))
    return 2


if __name__ == '__main__':
    sys.exit(main())
