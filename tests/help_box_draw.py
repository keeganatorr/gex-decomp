#!/usr/bin/env python3
"""Compare help-box visibility/state transitions with the pinned original.

Requires pefile/unicorn and a fresh replacement build. Graphics/text calls are
recorded as boundary effects; this is behavioral evidence, not a byte proof.
"""

import hashlib
import struct

from rotated_sprite_commands import addr, build
from sprite_rotation import PIN, ROOT, machine
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_ESP


def run(new, state, delay, flags, width):
    cpu = machine(build / "gex-source.exe" if new else ROOT / ".work/original.exe")
    obj, stack, stop, text = 0x1003000, 0x1002000, 0x1000000, 0x1004000
    calls = []

    def put(a, v):
        cpu.mem_write(a, struct.pack("<I", v & 0xFFFFFFFF))

    def word(a):
        return struct.unpack("<I", cpu.mem_read(a, 4))[0]

    for a in (0x455C04, 0x455C4C, 0x487FD4, 0x4A0293, 0x4A0297, 0x4A0299):
        put(addr(a, new), 0)
    put(addr(0x456220, new), 2)
    put(addr(0x456224, new), 0x1F81)
    for offset, value in {
        0x80: flags,
        0x90: delay,
        0x98: text,
        0xA0: state | 0x10,
        0xA4: width << 16,
        0xA8: width << 16,
        0xAC: 2 << 16,
        0xB0: 2 << 16,
        0xB4: 0x00100010,
    }.items():
        put(obj + offset, value)
    targets = {addr(0x428CC0, new): ("rect", 6), addr(0x419520, new): ("remove", 1)}

    def hook(m, pc, size, user):
        if pc in targets:
            name, count = targets[pc]
            sp = m.reg_read(UC_X86_REG_ESP)
            calls.append((name, tuple(word(sp + 4 + 4 * i) for i in range(count))))
            m.reg_write(UC_X86_REG_ESP, sp + 4)
            m.reg_write(UC_X86_REG_EIP, word(sp))

    cpu.hook_add(UC_HOOK_CODE, hook)
    ticks = []
    for _ in range(4):
        calls.clear()
        put(stack, stop)
        put(stack + 4, obj)
        cpu.reg_write(UC_X86_REG_ESP, stack)
        cpu.emu_start(addr(0x40D980, new), stop, count=10000)
        assert cpu.reg_read(UC_X86_REG_EIP) == stop
        ticks.append(
            (bytes(cpu.mem_read(obj, 0x204)), tuple(calls), word(addr(0x455C4C, new)))
        )
    return ticks


def main():
    assert hashlib.sha256((ROOT / ".work/original.exe").read_bytes()).hexdigest() == PIN
    count = 0
    for state in range(8):
        for delay in (0, 1, 2, 20):
            for flags in (0, 8):
                for width in (0, 2, 16):
                    expected = run(False, state, delay, flags, width)
                    actual = run(True, state, delay, flags, width)
                    assert actual == expected, (state, delay, flags, width)
                    if state in (0, 5):
                        assert not any(tick[1] for tick in actual)
                    count += 1
    print(f"{count} help-box cases (four ticks each) agree with the pinned original")


if __name__ == "__main__":
    main()
