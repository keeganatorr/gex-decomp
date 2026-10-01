#!/usr/bin/env python3
"""Generate stable callback IDs and explicit data/object pointer descriptors.

Uses source and source-built COFF only. Generated assembly stays in .work.
"""
import re
import subprocess
from pathlib import Path
from function_names import coff_export
from rebind_source_symbols import symbols

ROOT = Path(__file__).resolve().parents[1]
WORK = ROOT / '.work/replacement-short'


def build():
    paths = sorted((ROOT / 'src/functions').glob('[0-9a-f]' * 8 + '.cpp'))
    objects = [ROOT / '.work/replacement-objects' / (p.stem + '.obj') for p in paths]
    by_object, _ = symbols(objects)
    funcs = [(int(p.stem, 16), coff_export(p.stem, by_object[p.stem])) for p in paths]
    pointers = set()
    at = None
    for line in (ROOT / 'src/replacement/image_data.s').read_text().splitlines():
        label = re.fullmatch(r'_GEX_(?:RDATA|DATA)_([0-9a-f]{8}):', line)
        if label:
            at = int(label[1], 16)
        elif line.startswith('.long ') and at is not None:
            if line.startswith('.long _GEX_'):
                pointers.add(at)
            at += 4
        elif line.startswith('.byte ') and at is not None:
            at += len(line.split(','))
        elif line.startswith(('.zero ', '.space ')) and at is not None:
            at += int(line.split()[1], 0)
    fields = set()
    for path in paths:
        source = path.read_text()
        # Named pointer globals provide a descriptor even when initialized to 0.
        for m in re.finditer(r'extern\s+[^;{}\n]*\*[^;{}\n]*?\b\w*?_([0-9a-fA-F]{8})\b[^;\n]*;', source):
            base=int(m[1],16)
            pointers.add(base)
            dimensions=re.search(r'\[\s*(0x[0-9a-fA-F]+|[0-9]+)\s*\]',m[0])
            if dimensions:
                count=int(dimensions[1],0)
                if count>4096: raise ValueError('pointer array descriptor is too large')
                pointers.update(base+4*i for i in range(count))
        # Per-callback object unions: e.g. gob_work0 is a pointer in some types
        # and an integer in others. Only that callback's declarations apply.
        for struct in re.finditer(r'(?:struct|typedef struct) GXObject\s*\{(.*?)\}', source, re.S):
            for line in struct[1].splitlines():
                m = re.search(r'\*\s*\w+\s*;\s*/\*\s*(0x[0-9a-fA-F]+)', line)
                if m:
                    fields.add((int(path.stem, 16), int(m[1], 16)))
    # These source structs use padding arrays instead of offset comments.
    # Their pointer members are at the following audited VC4 layout offsets.
    fields.update({(0x42a690,0xac),(0x40c2c0,0x9c),(0x40ea90,0x9c)})
    # 0043bba0 uses &DAT_00464E00 as an array end; 0043b630 stores a scalar there.
    pointers.discard(0x464e00)
    out = ['.section .rdata,"dr"', '.balign 4', '.globl _SSImages', '_SSImages:',
           '.long 0x450000,_GEX_RDATA_00450000,0x600',
           '.long 0x451000,_GEX_DATA_00451000,0x11800',
           '.long 0x462800,_GEX_DATA_00462800,0x41ce0',
           '.globl _SSFunctions', '_SSFunctions:']
    out += [f'.long 0x{address:x},{symbol}' for address, symbol in funcs]
    out += ['.globl _SSFunctionCount', '_SSFunctionCount:', f'.long {len(funcs)}',
            '.globl _SSInitialPointers', '_SSInitialPointers:']
    out += [f'.long 0x{p:x}' for p in sorted(pointers)]
    out += ['.globl _SSInitialPointerCount', '_SSInitialPointerCount:', f'.long {len(pointers)}',
            '.globl _SSObjectFields', '_SSObjectFields:']
    out += [f'.long 0x{callback:x},0x{offset:x}' for callback, offset in sorted(fields)]
    out += ['.globl _SSObjectFieldCount', '_SSObjectFieldCount:', f'.long {len(fields)}']
    WORK.mkdir(parents=True, exist_ok=True)
    source = WORK / 'save_state_schema.s'
    source.write_text('\n'.join(out) + '\n')
    subprocess.run(['i686-w64-mingw32-as', '-o', str(WORK / 'save_state_schema.obj'), str(source)], check=True)
    print(f'Save-state schema: {len(funcs)} callbacks, {len(pointers)} pointer globals, {len(fields)} object fields')


if __name__ == '__main__':
    build()
