#!/usr/bin/env python3
"""Exercise the linked VC4 command parser and one-shot startup level hook.

Build first with ./build.sh. Requires pefile and unicorn; no game assets needed.
"""
import struct

from sprite_viewer import Viewer
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP


class Launch(Viewer):
    def __init__(self):
        super().__init__()
        import pefile
        from sprite_viewer import ROOT
        pe = pefile.PE(str(ROOT / '.work/replacement-short/gex-source.exe'))
        self.output = ''
        self.started = []
        self.assets = True
        self.stubs = {self.symbols['_WinMain_00405bf0@16']: ('startup', 16)}
        for dll in pe.DIRECTORY_ENTRY_IMPORT:
            for imp in dll.imports:
                name = imp.name.decode() if imp.name else ''
                pops = {'GetModuleFileNameA': 12, 'SetCurrentDirectoryA': 4,
                        'GetFileAttributesA': 4, 'GetStdHandle': 4, 'WriteFile': 20,
                        'SHBrowseForFolderA': 4}
                if name in pops:
                    target = self.alloc([0])
                    self.cpu.mem_write(imp.address, struct.pack('<I', target))
                    self.stubs[target] = (name, pops[name])

    def hook(self, cpu, address, size, data):
        if address not in self.stubs:
            return
        name, pop = self.stubs[address]
        sp = cpu.reg_read(UC_X86_REG_ESP)
        args = self.words(sp + 4, 5)
        result = 0
        if name == 'GetFileAttributesA':
            path = self.text(args[0])
            result = (0x10 if path in ('AVI', 'IDL', 'LEV', 'MUS', 'SFX', 'VFX')
                      else 0) if self.assets else 0xffffffff
        elif name == 'GetStdHandle':
            result = 1
        elif name == 'WriteFile':
            self.output += bytes(cpu.mem_read(args[1], args[2])).decode('ascii')
            result = 1
        elif name == 'startup':
            self.started.append(self.text(args[2]))
        elif name == 'SHBrowseForFolderA':
            raise AssertionError('help/invalid arguments must not open asset picker')
        cpu.reg_write(UC_X86_REG_EAX, result)
        cpu.reg_write(UC_X86_REG_EIP, self.words(sp, 1)[0])
        cpu.reg_write(UC_X86_REG_ESP, sp + 4 + pop)

    def launch(self, line):
        address = self.alloc([0] * (len(line) // 4 + 1))
        self.cpu.mem_write(address, line.encode() + b'\0')
        self.output = ''
        return self.call('WinMain@16', 0, 0, address, 0)


def main():
    v = Launch()
    # Resolve names and IDs from the linked game tables, including Planet X.
    tables = v.words(v.symbols['_GEX_DATA_0045a580'], 2)
    counts = v.words(v.symbols['_GEX_DATA_0045a578'], 2)
    entries = []
    for table, count in zip(tables, counts):
        for i in range(count - 1):
            name, level = v.words(table + i * 8, 2)
            entries.append((v.text(name).split()[0], level - 1))
    assert ('grave4', 3) in entries
    assert len(entries) == 44
    for name, level in entries:
        assert v.launch('--level ' + name) == 0
        assert v.started[-1] == '', 'direct level launch should skip intro'
        v.call('GEX_StartupLevelApply')
        assert v.words(v.symbols['_GEX_DATA_004a2964'], 1)[0] == level
        assert v.words(v.symbols['_GEX_DATA_00455c3c'], 1)[0] == 1
        assert v.words(v.symbols['_GEX_DATA_004a281c'], 1)[0] == 3
        assert v.words(v.symbols['_GEX_DATA_00456afc'], 1)[0] == 3
        v.cpu.mem_write(v.symbols['_GEX_DATA_004a2964'], struct.pack('<I', 63))
        v.call('GEX_StartupLevelApply')
        assert v.words(v.symbols['_GEX_DATA_004a2964'], 1)[0] == 63
    assert v.launch('  --play-intro\t--level "GRAVE4"  ') == 0
    assert v.started[-1] == 'X'
    v.call('GEX_StartupLevelApply')
    assert v.words(v.symbols['_GEX_DATA_004a2964'], 1)[0] == 3
    for demo in range(3):
        assert v.launch('--attract ' + str(demo)) == 0
        assert v.words(v.symbols['_GEX_DATA_00455c34'], 1)[0] == demo + 4
    v.assets = False
    starts = len(v.started)
    assert v.launch('--list-levels') == 0
    for name, _ in entries:
        assert name in v.output.split(), name
    assert v.launch('--help') == 0 and '--level NAME' in v.output
    for line in ('--level', '--level nonexistent', '--level grave',
                 '--level grave4 --level grave1', '--level grave4 --attract 0',
                 '--attract 0 --level grave4', '--level "grave4',
                 '--level "grave4"x', '--level ' + 'a' * 100,
                 '--level grave4 --unknown', '--attract 3'):
        assert v.launch(line) == 2, line
        assert 'Usage:' in v.output
    assert len(v.started) == starts
    print('Level CLI: all 44 names, IDs, one-shot startup, quoting, intro/attract, help and invalid arguments passed')


if __name__ == '__main__':
    main()
