#!/usr/bin/env python3
"""Check map direction/scale updates against the pinned original in x86 emulation.

Requires pefile/unicorn and a fresh scripts/assess-replacement-link build.
This behavioral comparison publishes no byte-match proof.
"""
import hashlib
import struct

from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_ESP
from sprite_rotation import ROOT, PIN, machine


def main():
    original = ROOT / '.work/original.exe'
    assert hashlib.sha256(original.read_bytes()).hexdigest() == PIN
    build = ROOT / '.work/replacement-short'
    lines = (build / 'gex-source.map').read_text(errors='replace').splitlines()

    def address(symbol):
        entries = [line.split() for line in lines if symbol in line.split()]
        assert len(entries) == 1, symbol
        return int(entries[0][2], 16)

    original_cpu = machine(original)
    new_cpu = machine(build / 'gex-source.exe')
    original_addresses = (0x42c860, 0x463b70, 0x463b5c)
    new_addresses = (address('_FUN_0042c860'), address('_GEX_DATA_00463b70'),
                     address('_GEX_DATA_00463b5c'))

    def run(cpu, addresses, dx, dy, scale):
        entry, reference, step = addresses
        # Deliberately distinguish the object's first pointer from its scale.
        cpu.mem_write(reference, struct.pack('<I', 0x0138c3bc))
        cpu.mem_write(reference + 0xc8, struct.pack('<i', scale))
        cpu.mem_write(step, struct.pack('<i', -1))
        cpu.mem_write(0x1002000, bytes([0x55]) * 0x200)
        cpu.mem_write(0x1001000, struct.pack('<IIii', 0x1000000, 0x1002000, dx, dy))
        cpu.reg_write(UC_X86_REG_ESP, 0x1001000)
        cpu.emu_start(entry, 0x1000000, count=10000)
        assert cpu.reg_read(UC_X86_REG_EIP) == 0x1000000
        return bytes(cpu.mem_read(0x1002000, 0x200)), bytes(cpu.mem_read(step, 4))

    count = 0
    for scale in (0x8000, 0x10000, -0x10000):
        for dx in range(-8, 9):
            for dy in range(-8, 9):
                expected = run(original_cpu, original_addresses, dx << 16, dy << 16, scale)
                actual = run(new_cpu, new_addresses, dx << 16, dy << 16, scale)
                assert actual == expected, (dx, dy, scale)
                count += 1
    print(f'{count} map direction/scale cases agree with the pinned original')


if __name__ == '__main__':
    main()
