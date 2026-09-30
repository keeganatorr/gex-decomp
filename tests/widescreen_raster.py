#!/usr/bin/env python3
"""Exercise actual sprite rasterizers in 32-bit Wine, including the old x=320 seam.

This is a behavior check, not a matching-decompilation proof. Artifacts stay in
.work; no installed game or matching backend is used.
"""
import os
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parent.parent
WORK = ROOT / '.work/widescreen-raster'
CASES = {
    '004457b0': 'FUN_004457b0_DrawTilesInner2',
    '004459e0': 'FUN_004459e0_DrawTilesInner3',
    '00445ca0': 'FUN_00445ca0_DrawTilesInner4',
    '004461c0': 'FUN_004461c0_DrawTilesInner5',
    '00446430': 'FUN_00446430_DrawTilesInner6',
    '00447680': 'FUN_00447680_InnerGraphicsTiles2_Tiles2',
    '00448560': 'FUN_00448560_InnerGraphicsTiles3_Tiles3',
    '00449500': 'FUN_00449500_InnerGraphicsTiles1_Tiles1',
}
VARIABLE = re.compile(r'extern\s+(?:"C"\s+)?((?:unsigned\s+)?(?:int|short|char|void)\s*\*?)\s*(\w+)\s*(\[\])?\s*;')


def harness(address, name):
    source = (ROOT / 'src/functions' / (address + '.cpp')).read_text()
    variables = list(VARIABLE.finditer(source))
    definitions = '\n'.join(f'{m[1]} {m[2]}' + ('[8192]' if m[3] else '') + ';' for m in variables)
    palette_stub = ''
    declaration = re.search(r'extern "C" ([\w* ]+? __cdecl FUN_00402400\([^;]+\));', source)
    if declaration:
        result = declaration[1].split('__cdecl')[0].strip()
        palette_stub = 'extern "C" ' + declaration[1] + ' { return (' + result + ')palette; }'
    init = []
    for m in variables:
        lower = m[2].lower()
        if lower.endswith('33ac') or '33ac_' in lower:
            init.append(f'{m[2]} = (decltype({m[2]}))framebuffer;')
        if '2f78' in lower:
            init.append(f'{m[2]} = (decltype({m[2]}))texture;')
        if '2f6c' in lower:
            init.append(f'{m[2]} = (decltype({m[2]}))palette;')
    direct = address in ('004459e0', '004461c0', '00446430', '00448560')
    scan = address in ('00447680', '00448560', '00449500')
    call = (f'{name}(x * 65536, (x + 7) * 65536, 0, 0, 8 * 65536, 0, 20 * 65536, 0);'
            if scan else f'{name}(command);')
    return r'''
#include <cstdio>
#include <cstring>
''' + source + '\n' + definitions + r'''
static int viewport;
extern "C" int __cdecl GEX_WidescreenWidth(void) { return viewport; }
static unsigned short framebuffer[1024 * 240], texture[1024 * 4], palette[256];
''' + palette_stub + r'''
int main() {
    for (int i=0; i<256; ++i) palette[i]=0x1234;
''' + ('    for (int i=0; i<4096; ++i) texture[i]=0x1234;\n' if direct else '    memset(texture,0x11,sizeof(texture));\n') + '\n'.join(init) + r'''
    int widths[]={320,384,424,560,672};
    for (int wi=0;wi<5;++wi) {
        viewport=widths[wi];
        int positions[]={-4,0,316,320,350,viewport-4,viewport,viewport+4};
        for (int pi=0;pi<8;++pi) {
            int x=positions[pi];
            for (int i=0;i<1024*240;++i) framebuffer[i]=0x2222;
            unsigned char command[24]={0};
            command[4]=command[5]=command[6]=0x80;
            *(short *)(command+8)=(short)x;
            *(short *)(command+10)=20;
            *(short *)(command+16)=8;
            *(short *)(command+18)=1;
''' + call + r'''
            for (int row=0;row<240;++row) for(int column=0;column<1024;++column) {
                bool inside=row==20 && column>=x && column<x+8 && column<viewport;
                unsigned short expected=inside?0x1234:0x2222;
                if(framebuffer[row*1024+column]!=expected) {
                    printf("FAIL width=%d x=%d pixel=%d,%d actual=%x expected=%x\n",viewport,x,column,row,framebuffer[row*1024+column],expected);
                    return 1;
                }
            }
        }
    }
    puts("PASS: 5 viewport widths, 8 edge positions, framebuffer guards intact");
    return 0;
}
'''


def main():
    WORK.mkdir(parents=True, exist_ok=True)
    env = dict(os.environ, WINEDEBUG='-all',
               WINEPREFIX=os.environ.get('WINEPREFIX', str(WORK / 'wine')))
    for address, name in CASES.items():
        cpp, exe = WORK / (address + '.cpp'), WORK / (address + '.exe')
        cpp.write_text(harness(address, name))
        subprocess.run(['i686-w64-mingw32-g++', '-w', '-O1', '-static', str(cpp), '-o', str(exe)], check=True)
        result = subprocess.run(['wine', str(exe)], env=env, capture_output=True, text=True, timeout=60)
        print(address, result.stdout.strip(), flush=True)
        if result.returncode:
            raise SystemExit(result.stderr or result.returncode)


if __name__ == '__main__':
    main()
