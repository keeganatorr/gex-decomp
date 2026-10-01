#!/usr/bin/env python3
"""Exercise the built in-game viewer with synthetic resolved assets under x86.

Run after scripts/assess-replacement-link. Requires pefile and unicorn, like
sprite_rotation.py. Rendering calls are observed, not treated as pixel proofs;
the actual game renderer is exercised separately under Wine.
"""
from pathlib import Path
import struct
import re

import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UcError
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP

ROOT = Path(__file__).resolve().parents[1]


class Viewer:
    def __init__(self):
        build = ROOT / '.work/replacement-short'
        pe = pefile.PE(str(build / 'gex-source.exe'))
        self.cpu = Uc(UC_ARCH_X86, UC_MODE_32)
        self.cpu.mem_map(pe.OPTIONAL_HEADER.ImageBase,
                         (pe.OPTIONAL_HEADER.SizeOfImage + 4095) & ~4095)
        self.cpu.mem_write(pe.OPTIONAL_HEADER.ImageBase, pe.get_memory_mapped_image())
        self.cpu.mem_map(0x1000000, 0x200000)
        self.next = 0x1010000
        self.symbols = {}
        for line in (build / 'gex-source.map').read_text(errors='replace').splitlines():
            fields = line.split()
            if len(fields) >= 3 and fields[0].count(':') == 1:
                try:
                    self.symbols[fields[1]] = int(fields[2], 16)
                except ValueError:
                    pass
        self.calls = []
        self.clock = 1000
        self.stubs = {}
        names = ['FUN_0043f080_ResetGraphics_Clean1', 'GFX_DrawRectHelper_00428cc0',
                 'TXT_DrawPrintP_0043fa70', '_vsnprintf', 'UpdateTimer_00405120', 'CEL_DrawCels_0043db70',
                 'FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow',
                 'FUN_0040b2d0_InputProcessing', 'FUN_0043db50_UpdateGraphicsState',
                 'GOB_DisplayObject_00444590', 'FUN_004432c0_Graphics', 'GEX_WidescreenWidth']
        for name in names:
            self.stubs[self.symbols['_' + name]] = (name, 0)
        for dll in pe.DIRECTORY_ENTRY_IMPORT:
            for imp in dll.imports:
                if imp.name in (b'IsBadReadPtr', b'GetTickCount'):
                    target = self.alloc([0])
                    self.cpu.mem_write(imp.address, struct.pack('<I', target))
                    self.stubs[target] = (imp.name.decode(), 8 if imp.name == b'IsBadReadPtr' else 0)
        self.cpu.hook_add(UC_HOOK_CODE, self.hook)

    def words(self, address, count):
        return struct.unpack('<' + 'I' * count, self.cpu.mem_read(address, count * 4))

    def alloc(self, words):
        address = self.next
        self.next += len(words) * 4 + 16
        self.cpu.mem_write(address, struct.pack('<' + 'I' * len(words), *[w & 0xffffffff for w in words]))
        return address

    def text(self, address):
        result = bytearray()
        while (b := self.cpu.mem_read(address, 1)[0]):
            result.append(b)
            address += 1
        return result.decode('ascii')

    def hook(self, cpu, address, size, data):
        if address not in self.stubs:
            return
        name, pop = self.stubs[address]
        sp = cpu.reg_read(UC_X86_REG_ESP)
        args = self.words(sp + 4, 9)
        result = 1
        if name == 'IsBadReadPtr':
            try:
                cpu.mem_read(args[0], args[1])
                result = 0
            except UcError:
                result = 1
        elif name == 'GetTickCount':
            result = self.clock
        elif name == 'GEX_WidescreenWidth':
            result = 320
        elif name == 'FUN_0040b2d0_InputProcessing':
            assert self.words(self.symbols['_GEX_DATA_004a294c'], 1)[0] == 0, 'viewer must not wait in the pause loop'
        elif name == '_vsnprintf':
            fmt = self.text(args[2])
            values = self.words(args[3], 8)
            self.calls.append(('text', fmt, values))
            at = iter(values)
            def substitute(match):
                value = next(at)
                return self.text(value) if match[0] == '%s' else str(value)
            line = re.sub(r'%[ds]', substitute, fmt).encode('ascii')[:args[1]]
            cpu.mem_write(args[0], line + b'\0')
            result = len(line)
        elif name == 'TXT_DrawPrintP_0043fa70':
            self.calls.append(('status', self.text(args[2])))
        elif name in ('GOB_DisplayObject_00444590', 'FUN_004432c0_Graphics'):
            self.calls.append(('draw', name, self.words(args[0], 0x204 // 4)))
            address = self.symbols['_GEX_DATA_004a2b18']
            cpu.mem_write(address, struct.pack('<I', self.words(address, 1)[0] + 4))
        cpu.reg_write(UC_X86_REG_EAX, result)
        cpu.reg_write(UC_X86_REG_EIP, self.words(sp, 1)[0])
        cpu.reg_write(UC_X86_REG_ESP, sp + 4 + pop)

    def call(self, name, *args):
        sp = 0x100f000
        self.cpu.mem_write(sp, struct.pack('<' + 'I' * (len(args) + 1), 0x1000000, *args))
        self.cpu.reg_write(UC_X86_REG_ESP, sp)
        self.cpu.emu_start(self.symbols['_' + name], 0x1000000, count=1000000)
        assert self.cpu.reg_read(UC_X86_REG_EIP) == 0x1000000, 'viewer did not return'
        return self.cpu.reg_read(UC_X86_REG_EAX)

    def key(self, code, flags=0):
        return self.call('GEX_SpriteViewerKey', code, flags)

    def tick(self, level):
        self.calls = []
        return self.call('GEX_SpriteViewerTick', level)


def main():
    v = Viewer()
    # One oversized frame, one empty slot, and a second animation. This is a
    # resolved structure fixture, not a copy of any proprietary game asset.
    image = v.alloc([400 << 16, 40 << 16, 0, 0, 2, 1, 0, 0])
    cel = v.alloc([0, 0, image, 0, 0])
    sprite = v.alloc([0] * 6 + [v.alloc([cel, 0])])
    first = v.alloc([sprite, 0])
    second = v.alloc([sprite])
    obj = v.alloc([v.alloc([first, second]), 0, 1, 2, v.alloc([1, 0])])
    original_object = bytes(v.cpu.mem_read(obj, 20))
    # Version-zero assets terminate their animation and frame tables with null.
    legacy = v.alloc([v.alloc([v.alloc([sprite, 0]), 0]), 0, 0, 0, 0])
    rows = v.alloc([obj, 0, legacy, 0, obj, 0, 0, 0])
    root = v.alloc([0] * 8 + [v.alloc([rows, 0])])
    level = v.alloc([0, root])
    assert v.tick(level) == 0
    assert v.key(0x27) == 0, 'ordinary gameplay key must pass through'
    assert v.key(0x77) == 1
    assert v.tick(level) == 1
    draws = [c for c in v.calls if c[0] == 'draw']
    assert len(draws) == 1 and draws[0][1] == 'FUN_004432c0_Graphics'
    assert draws[0][2][3] == obj and draws[0][2][0xc8 // 4] < 65536
    counts = next(c for c in v.calls if c[0] == 'text' and c[1].startswith('%d FRAMES'))
    assert counts[2][0] == 4 and counts[2][3] != 0 and counts[2][4] == 0
    v.key(0x27)
    v.tick(level)
    assert ('status', 'EMPTY FRAME SLOT') in v.calls
    assert not any(c[0] == 'draw' for c in v.calls), 'null slots must not reset to frame zero'
    v.key(0x27)
    v.tick(level)
    assert next(c[2][0x50 // 4] for c in v.calls if c[0] == 'draw') == 1
    v.key(0x22)
    v.tick(level)
    assert next(c[2][3] for c in v.calls if c[0] == 'draw') == legacy
    v.key(ord('N'))
    v.tick(level)
    assert ('status', 'NATIVE SIZE - MAY CLIP') in v.calls
    assert next(c[1] for c in v.calls if c[0] == 'draw') == 'GOB_DisplayObject_00444590'
    assert bytes(v.cpu.mem_read(obj, 20)) == original_object
    v.key(0x24)
    v.key(0x20)
    v.tick(level)
    v.clock += 200
    v.tick(level)
    assert ('status', 'EMPTY FRAME SLOT') in v.calls
    v.key(0x77, 0x40000000)
    assert v.tick(level) == 1, 'repeat key must not close viewer'
    v.key(0x1b)
    assert v.tick(level) == 0
    # Closing and reopening in the same level refreshes separately loaded idle
    # assets instead of retaining a pointer that gameplay could have freed.
    idle = v.alloc([v.alloc([v.alloc([sprite]), 0]), 0, 1, 1, v.alloc([0])])
    idle_slot = v.symbols['_GEX_DATA_004a2a10']
    v.cpu.mem_write(idle_slot, struct.pack('<I', idle))
    v.key(0x77)
    v.tick(level)
    counts = next(c for c in v.calls if c[0] == 'text' and c[1].startswith('%d FRAMES'))
    assert counts[2][0] == 5
    v.key(0x1b)
    v.tick(level)
    v.cpu.mem_write(idle_slot, struct.pack('<I', 0))
    # A level teardown must discard every pointer, while preserving the user's
    # armed state for the next selected level.
    v.key(0x77)
    v.tick(level)
    v.call('GEX_SpriteViewerReset')
    empty = v.alloc([0, v.alloc([0] * 8 + [v.alloc([0])])])
    assert v.tick(empty) == 1
    assert ('status', 'NO LOADED OBJECTS') in v.calls
    # Invalid metadata stays visible as a diagnostic and can be navigated away.
    bad = v.alloc([0, 0, 1, 5000, 0])
    badrows = v.alloc([bad, 0, legacy, 0, 0, 0])
    badlevel = v.alloc([0, v.alloc([0] * 8 + [v.alloc([badrows, 0])])])
    v.call('GEX_SpriteViewerReset')
    v.tick(badlevel)
    assert ('status', 'INVALID ANIMATION TABLE') in v.calls
    v.key(0x27)
    v.tick(badlevel)
    assert any(c[0] == 'draw' for c in v.calls)
    # The pause snapshot is disabled only during presentation and then restored.
    frozen = v.symbols['_GEX_DATA_004a294c']
    v.cpu.mem_write(frozen, struct.pack('<I', 2))
    v.tick(badlevel)
    assert v.words(frozen, 1)[0] == 2
    print('Sprite viewer: navigation, deduplication, empty/invalid slots, fit/native, playback, pause, reopen and teardown passed')


if __name__ == '__main__':
    main()
