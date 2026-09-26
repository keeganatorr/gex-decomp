#!/usr/bin/env python3
"""Re-run every executable check in docs/knowledge/recipes.json.

    python3 tests/knowledge_checks.py [--recipe ID]

Uses the pinned compiler through tools/probe.py (scratch compiles only; nothing
is published). A recipe whose checks fail no longer describes this toolchain:
fix or retire the recipe, do not loosen the check. Needs the pinned executable
under .work/ and the backend database for extents; no Ghidra, no service.
"""
import argparse, json, os, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'tools'))
import probe

STATUSES = {'verifier-proved', 'probe-observed', 'toolchain-limited', 'hypothesis'}


def main():
    parser = argparse.ArgumentParser(); parser.add_argument('--recipe')
    args = parser.parse_args()
    book = json.load(open(os.path.join(ROOT, 'docs', 'knowledge', 'recipes.json')))
    assert book['format'] == 'gex-knowledge-recipes-v1'
    assert book['toolchainId'] == probe.TOOLCHAIN['id'], 'recipes were recorded under another toolchain'
    probes, failures, count = {}, [], 0
    ids = set()
    for recipe in book['recipes']:
        assert recipe['id'] not in ids, 'duplicate recipe ' + recipe['id']; ids.add(recipe['id'])
        assert recipe['status'] in STATUSES, recipe['id']
        assert os.path.exists(os.path.join(ROOT, recipe['doc'])), recipe['doc']
        assert recipe['checks'] or recipe['status'] == 'hypothesis', recipe['id'] + ' needs an executable check'
        if args.recipe and recipe['id'] != args.recipe:
            continue
        for check in recipe['checks']:
            address = check['address']
            source = check.get('source') or open(os.path.join(ROOT, check['file'])).read()
            p = probes.setdefault(address, probe.Probe(address))
            result = p.measure(source, check.get('lang'))
            count += 1
            got = 'exact' if result['exact'] else 'differs' if result['compiled'] and 'error' not in result else 'failed'
            label = f"{recipe['id']} {address} {check.get('file', 'inline')} expect={check['expect']} got={got}"
            if got != check['expect']:
                failures.append(label + (f" ({result.get('error') or result['output'][-300:]})" if got == 'failed' else ''))
            print(('ok   ' if got == check['expect'] else 'FAIL ') + label)
    print(f'{count} checks, {len(failures)} failed')
    return 1 if failures else 0


if __name__ == '__main__':
    sys.exit(main())
