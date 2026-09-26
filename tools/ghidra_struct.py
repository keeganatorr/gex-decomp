#!/usr/bin/env python3
"""Print a self-contained C struct from Ghidra's (read-only) layout.

    tools/ghidra_struct.py GXObject [--only 80,84,88] [--name Local]

Candidate translation units must be self-contained, so a source that touches
object fields otherwise declares `void **` slots, and Ghidra's own pseudocode
for GXObject** parameters reads as `param_1[0x23]->gob_scripts[0].gas_stack`.
Real member names change what an author (human or model) writes, and the
natural `gob->gob_yVel += gob->gob_yAccl` form is often the one that matches
(docs/knowledge/natural-field-access.md). The layout is evidence, not proof:
exact bytes never establish member types.

--only keeps the listed hex offsets and pads the rest, which keeps a source
short; the struct size is then only as large as the last kept member.
Non-scalar members become byte arrays or void pointers.
"""
import argparse, json, os, re, sys, urllib.parse, urllib.request

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GHIDRA = json.load(open(os.path.join(ROOT, 'project.json')))['ghidra']['url'].rstrip('/')
SCALAR = {'int': 'int', 'uint': 'unsigned int', 'short': 'short', 'ushort': 'unsigned short',
          'char': 'char', 'uchar': 'unsigned char', 'byte': 'unsigned char', 'word': 'unsigned short',
          'dword': 'unsigned int', 'long': 'long', 'ulong': 'unsigned long', 'undefined4': 'int',
          'undefined2': 'short', 'undefined1': 'char', 'float': 'float', 'double': 'double', 'bool': 'char'}


def layout(name):
    url = f'{GHIDRA}/get_struct_layout?' + urllib.parse.urlencode({'struct_name': name})
    with urllib.request.urlopen(url, timeout=20) as reply:
        return json.loads(reply.read())


def member(kind, size):
    kind = kind.strip()
    if kind in SCALAR:
        return SCALAR[kind], ''
    if kind.endswith('*'):
        base = kind[:-1].strip()
        return (SCALAR[base] + ' *') if base in SCALAR else 'void *', ''
    array = re.match(r'(.+)\[(\d+)\]$', kind)
    if array and array.group(1) in SCALAR:
        return SCALAR[array.group(1)], f'[{array.group(2)}]'
    return 'unsigned char', f'[{size}]'


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('struct'); parser.add_argument('--only'); parser.add_argument('--name')
    args = parser.parse_args()
    only = {int(x, 16) for x in args.only.split(',')} if args.only else None
    data = layout(args.struct)
    if 'fields' not in data:
        sys.exit(json.dumps(data))
    name = args.name or args.struct
    out = [f'typedef struct {name} {{  /* Ghidra {args.struct}, {data["size"]} bytes: evidence, not proof */']
    position = pad = 0
    for field in data['fields']:
        offset, size = field['offset'], field['size']
        if offset < position or (only is not None and offset not in only):
            continue
        if offset > position:
            out.append(f'    unsigned char _pad{pad}[0x{offset - position:x}];'); pad += 1
        ctype, suffix = member(field['type'], size)
        out.append(f'    {ctype} {field["name"] or "field_%x" % offset}{suffix};  /* 0x{offset:x} {field["type"]} */')
        position = offset + size
    if only is None and position < data['size']:
        out.append(f'    unsigned char _pad{pad}[0x{data["size"] - position:x}];')
    out.append(f'}} {name};')
    print('\n'.join(out))


if __name__ == '__main__':
    main()
