"""Try block-scoping a temporary in each block that assigns it first.

    tools/blockscope.py ADDRESS SOURCE VAR [--type int] [--write OUT]

CL 10.00 picks a temporary's register partly by where it is declared, and
the choice can hinge on one block: 0041dd50 was exact only with `int t`
declared inside the first of six rotation cases, the other five using the
function-level `t`. This finds every line whose first statement in its block
assigns VAR (`VAR = ...;` directly after a line ending in `{`), and compiles
every subset of them with that assignment turned into a declaration. Up to
twelve sites (4096 compiles); the function-level declaration stays, so any
subset still compiles. Probes never publish; the first exact candidate is
written to --write.
"""
import itertools
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from probe import Probe  # noqa: E402


def sites(lines, var):
    pat = re.compile(r'^(\s*)' + re.escape(var) + r'\s*=[^=]')
    return [i for i, line in enumerate(lines)
            if pat.match(line) and i > 0 and lines[i - 1].rstrip().endswith('{')]


def main():
    args = sys.argv[1:]
    if len(args) < 3:
        sys.exit(__doc__)
    address, path, var = args[:3]
    vtype = args[args.index('--type') + 1] if '--type' in args else 'int'
    out = args[args.index('--write') + 1] if '--write' in args else None
    lines = open(path).read().split('\n')
    found = sites(lines, var)
    if not found:
        sys.exit(f'no block-leading assignment to {var}')
    if len(found) > 12:
        sys.exit(f'{len(found)} sites; narrow the source first')
    probe = Probe(address)
    results = []
    for bits in itertools.product((0, 1), repeat=len(found)):
        trial = list(lines)
        for on, i in zip(bits, found):
            if on:
                trial[i] = re.sub(r'^(\s*)', r'\g<1>' + vtype + ' ', trial[i], count=1)
        r = probe.measure('\n'.join(trial))
        results.append((r['percent'] or 0, bits))
        if r['exact']:
            print('EXACT', bits, 'sites', [i + 1 for i in found])
            if out:
                open(out, 'w').write('\n'.join(trial))
            return
    results.sort(reverse=True)
    print('sites (lines):', [i + 1 for i in found])
    for pct, bits in results[:5]:
        print(f'{pct:.1f}%', bits)


if __name__ == '__main__':
    main()
