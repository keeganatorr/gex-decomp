#!/usr/bin/env python3
"""Flag original-code idioms the pinned CL 10.00 toolchain is not known to emit.

    tools/idiom_scan.py [ADDRESS ...] [--json]

Without addresses, scans every reconstruction-eligible function and prints
counts split by current proof status. A hit is a triage signal, not a verdict:
it says "a family of functions with this shape has zero exact proofs and a
reviewed negative search", so spend search on something else first or try a
different compiler hypothesis. See docs/knowledge/toolchain-limits.md.
"""
import argparse, json, os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import probe

REG = r'(e[a-d]x|e[sd]i|ebp)'


def narrow_mask_shift(instructions):
    """`and r, 0x80000000` ... `shr r, k`. For k < 31 CL 10.00 /O2 widens the mask
    to 0x8fffffff for bits the shift discards (source form, bitfields and split
    statements all tried); only disabling /Og keeps it, which breaks the rest.
    For k == 31 it drops the `and` entirely (0041cb80: five spellings tried)."""
    masked = set()
    for ins in instructions:
        m = re.match(REG + r', 0x([0-9a-f]+)$', ins.op_str)
        if not m:
            continue
        register, value = m.group(1), int(m.group(2), 16)
        if ins.mnemonic == 'and' and value in (0x80000000, 0xc0000000, 0xe0000000, 0xf0000000):
            masked.add(register)
        elif ins.mnemonic == 'shr' and register in masked and value <= 31:
            return f'{ins.address:08x}'
        elif register in masked and ins.mnemonic in ('mov', 'lea'):
            masked.discard(register)  # overwritten: the mask no longer feeds a shift
    return None


def noreturn_tail(instructions):
    """Body ends in a call with no epilogue (e.g. `call _exit`). CL 10.00 has no
    noreturn knowledge for exit/_exit and emits `add esp, n; ret` after it; the
    verifier also refuses an extent that ends in a call."""
    if instructions and instructions[-1].mnemonic == 'call':
        return f'{instructions[-1].address:08x}'
    return None


IDIOMS = {'narrow-mask-shift': narrow_mask_shift, 'noreturn-tail': noreturn_tail}


def scan(record):
    import capstone
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    try:
        data = probe.original_bytes(int(record['entry'], 16), int(record['size']))
    except SystemExit:
        return {}
    instructions = list(decoder.disasm(data, int(record['entry'], 16)))
    return {name: where for name, test in IDIOMS.items() if (where := test(instructions))}


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('addresses', nargs='*'); parser.add_argument('--json', action='store_true')
    args = parser.parse_args()
    db = probe.database()
    rows = [json.loads(b) for (b,) in db.execute("select body from records where resource='functions'")]
    wanted = {a.lower().replace('0x', '').zfill(8) for a in args.addresses}
    results = []
    for row in rows:
        if wanted and row['entry'] not in wanted:
            continue
        if not wanted and not row.get('reconstructionEligible'):
            continue
        hits = scan(row)
        if hits:
            results.append({'address': row['entry'], 'name': row['name'], 'exact': bool((row.get('match') or {}).get('verifiedExact')), 'idioms': hits})
    if args.json:
        print(json.dumps(results, indent=1)); return
    if wanted:
        for r in results:
            print(r['address'], r['name'], 'EXACT' if r['exact'] else 'unmatched', r['idioms'])
        missing = wanted - {r['address'] for r in results}
        for address in sorted(missing):
            print(address, 'no known toolchain-limited idiom')
        return
    for idiom in IDIOMS:
        hit = [r for r in results if idiom in r['idioms']]
        exact = sum(1 for r in hit if r['exact'])
        print(f'{idiom}: {len(hit)} functions ({exact} exact, {len(hit) - exact} unmatched)')
        print('   ', ' '.join(r['address'] for r in hit if not r['exact']))


if __name__ == '__main__':
    main()
