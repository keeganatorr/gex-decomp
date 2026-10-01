#!/usr/bin/env python3
"""Compare Rez camera and restored objects with the pinned original on x86.

Requires pefile/unicorn and a fresh replacement build. Calls execute the real
projection/centering helpers. This is behavioral evidence, never a byte proof.
"""
import hashlib
import itertools
import random
import struct
from functools import lru_cache

import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP

from rotated_sprite_commands import addr, build, symbols
from sprite_rotation import PIN, ROOT


@lru_cache(maxsize=2)
def image(path):
    pe = pefile.PE(str(path), fast_load=True)
    return (pe.OPTIONAL_HEADER.ImageBase,
            (pe.OPTIONAL_HEADER.SizeOfImage + 4095) & ~4095,
            pe.get_memory_mapped_image())


def machine(path):
    base, size, data = image(path)
    cpu = Uc(UC_ARCH_X86, UC_MODE_32)
    cpu.mem_map(base, size)
    cpu.mem_write(base, data)
    cpu.mem_map(0x1000000, 0x10000)
    return cpu


def run(new, points, present, limits, mode, history, ticks=3, width=320):
    cpu = machine(build / 'gex-source.exe' if new else ROOT / '.work/original.exe')
    objects = [0x1003000, 0x1003400, 0x1003800]
    stack, stop = 0x1002000, 0x1000000

    def put(a, v):
        cpu.mem_write(a, struct.pack('<I', v & 0xffffffff))

    for i, (x, y, z) in enumerate(points):
        cpu.mem_write(objects[i], bytes((j * 13 + i) & 255 for j in range(0x204)))
        for off, value in {8: i & 1, 0x78: x, 0x7c: y, 0xa0: z,
                           0xc8: 0x10000, 0xcc: 0x10000,
                           0x1f8: x - 0x20000, 0x1fc: y + 0x30000}.items():
            put(objects[i] + off, value)
    original_objects = [bytes(cpu.mem_read(p, 0x204)) for p in objects]
    for a, v in {0x45b100: 0x10000, 0x45b104: 0x3000000, 0x45b108: 0x1600000,
                 0x45b114: mode, 0x45b118: limits[0], 0x45b11c: limits[1]}.items():
        put(addr(a, new), v)
    for i in range(16):
        put(addr(0x463fa0 + 4*i, new), history[i])
        put(addr(0x463e58 + 4*i, new), 0x3000000 + i*0x1000)
        put(addr(0x463e18 + 4*i, new), 0x1600000 + i*0x1000)
    if new:
        def width_hook(m, pc, size, user):
            if pc == symbols['_GEX_WidescreenWidth']:
                sp = m.reg_read(UC_X86_REG_ESP)
                ret = struct.unpack('<I', m.mem_read(sp, 4))[0]
                m.reg_write(UC_X86_REG_EAX, width)
                m.reg_write(UC_X86_REG_ESP, sp+4)
                m.reg_write(UC_X86_REG_EIP, ret)
        cpu.hook_add(UC_HOOK_CODE, width_hook)
    output = []
    for _ in range(ticks):
        cpu.mem_write(stack, struct.pack('<IIII', stop, objects[0],
                                        objects[1] if present[0] else 0,
                                        objects[2] if present[1] else 0))
        cpu.reg_write(UC_X86_REG_ESP, stack)
        cpu.emu_start(addr(0x42eaf0, new), stop, count=100000)
        assert cpu.reg_read(UC_X86_REG_EIP) == stop, 'camera did not return'
        actual_objects = [bytes(cpu.mem_read(p, 0x204)) for p in objects]
        assert actual_objects == original_objects, 'projection changed object fields'
        # Compare complete history storage, zoom/offset globals and screen bounds.
        output.append(tuple(bytes(cpu.mem_read(addr(a, new), n)) for a,n in (
            (0x45b100, 32), (0x463e0c, 0x1d4), (0x4a2a1c,4), (0x4a2a38,4))))
    return output


def main():
    assert hashlib.sha256((ROOT / '.work/original.exe').read_bytes()).hexdigest() == PIN
    count = 0
    # All six orderings on each axis, ties, missing targets and forced edge modes.
    coords = list(itertools.permutations((20<<16, 450<<16, 900<<16)))
    coords += [(400<<16,)*3, (400<<16,400<<16,700<<16), (700<<16,400<<16,400<<16)]
    for xs, ys in itertools.product(coords, repeat=2):
        points = [(xs[i], ys[i], 0) for i in range(3)]
        for present in ((False,False),(True,False),(False,True),(True,True)):
            for mode in (0x68,0x69,0x6a):
                for limits in ((0x10000,0x40000),(0x18000,0x18000)):
                    expected = run(False,points,present,limits,mode,[0x10000]*16)
                    actual = run(True,points,present,limits,mode,[0x10000]*16)
                    assert actual == expected, (xs,ys,present,limits,mode)
                    count += 1
    rng = random.Random(42)
    for _ in range(120):
        points = [(rng.randrange(280,1100)<<16,rng.randrange(160,640)<<16,
                   rng.choice((0,0x10000,0x20000))) for i in range(3)]
        history = [rng.randrange(0x10000,0x40000) for i in range(16)]
        expected = run(False,points,(True,True),(0x10000,0x40000),0x68,history)
        actual = run(True,points,(True,True),(0x10000,0x40000),0x68,history)
        assert actual == expected, (points,history)
        count += 1
    # Wider views exercise positive fit divisors and actual viewport bounds.
    for width in (384,424,560,672):
        for present in ((False,False),(True,False),(True,True)):
            result = run(True,[(400<<16,300<<16,0),(800<<16,400<<16,0),
                              (600<<16,500<<16,0)],present,(0x10000,0x40000),
                         0x68,[0x10000]*16,ticks=20,width=width)
            for frame in result:
                region=frame[1]
                left=struct.unpack_from('<i',region,0x463f10-0x463e0c)[0]
                right=struct.unpack_from('<i',region,0x463f98-0x463e0c)[0]
                assert right-left == width<<16
    print(f'{count} Rez camera cases (three ticks each) agree with the pinned original; '
          '12 widescreen cases pass for 20 ticks each')


if __name__ == '__main__':
    main()
