#!/usr/bin/env python3
"""Compare compiled sprite rotation with the pinned original under x86 emulation.

Requires pefile and unicorn. Run after scripts/assess-replacement-link.
Reads local ignored binaries only; this behavioral test publishes no byte proof.
"""
import hashlib
from pathlib import Path
import random
import struct

import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_ESP

ROOT = Path(__file__).resolve().parents[1]
PIN = 'e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86'


def machine(path):
    pe = pefile.PE(str(path))
    cpu = Uc(UC_ARCH_X86, UC_MODE_32)
    base = pe.OPTIONAL_HEADER.ImageBase
    cpu.mem_map(base, (pe.OPTIONAL_HEADER.SizeOfImage + 4095) & ~4095)
    cpu.mem_write(base, pe.get_memory_mapped_image())
    cpu.mem_map(0x1000000, 0x10000)
    return cpu


def rotate(cpu, address, x, y, angle):
    cpu.mem_write(0x1001000, struct.pack('<IIII', 0x1000000, 0x1002000,
                                       0x1002004, angle & 0xffffffff))
    cpu.mem_write(0x1002000, struct.pack('<II', x & 0xffffffff, y & 0xffffffff))
    cpu.reg_write(UC_X86_REG_ESP, 0x1001000)
    cpu.emu_start(address, 0x1000000, count=10000)
    assert cpu.reg_read(UC_X86_REG_EIP) == 0x1000000, 'rotation did not return'
    return struct.unpack('<ii', cpu.mem_read(0x1002000, 8))


def main():
    original = ROOT / '.work/original.exe'
    assert hashlib.sha256(original.read_bytes()).hexdigest() == PIN
    build = ROOT / '.work/replacement-short'
    symbol = '_FUN_00442e50_GraphicsFlashingInner2'
    lines = (build / 'gex-source.map').read_text(errors='replace').splitlines()
    entries = [line.split() for line in lines if symbol in line.split()]
    assert len(entries) == 1
    address = int(entries[0][2], 16)
    oracle = machine(original)
    candidate = machine(build / 'gex-source.exe')
    rng = random.Random(42)
    count = 0
    for angle in range(-1024, 1025):
        vectors = [(0x10000, 0), (0, 0x10000), (16 << 16, -12 << 16),
                   (rng.randint(-2000000, 2000000), rng.randint(-2000000, 2000000))]
        for x, y in vectors:
            fixed_angle = (angle << 16) + 12345
            expected = rotate(oracle, 0x442e50, x, y, fixed_angle)
            actual = rotate(candidate, address, x, y, fixed_angle)
            assert actual == expected, (angle, x, y, expected, actual)
            count += 1
    print(f'{count} sprite rotation cases agree with the pinned original')


if __name__ == '__main__':
    main()
