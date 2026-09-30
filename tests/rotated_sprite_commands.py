#!/usr/bin/env python3
"""Compare rotated sprite command coordinates with the pinned original.

Requires pefile/unicorn and a fresh replacement build. Synthetic sprite/image
records exercise full tiles and interpolated subtiles. Only frame lookup and
colour conversion are stubbed identically in both executables. This compares
command output, not whole-game behavior, and publishes no byte proof.
"""

import hashlib
import struct
import re
from sprite_rotation import machine, ROOT, PIN
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP

build = ROOT / ".work/replacement-short"
lines = (build / "gex-source.map").read_text(errors="replace").splitlines()
symbols = {
    l.split()[1]: int(l.split()[2], 16)
    for l in lines
    if len(l.split()) > 2 and re.fullmatch("[0-9a-fA-F]{16}", l.split()[2])
}
data = {int(n[-8:], 16): a for n, a in symbols.items() if n.startswith("_GEX_DATA_")}
names = dict(
    l.split("\t")[:2]
    for l in (ROOT / "src/replacement/function_names.tsv").read_text().splitlines()
    if l and not l.startswith("#")
)


def addr(a, new):
    if not new:
        return a
    if a in data:
        return data[a]
    if "%08x" % a in names:
        return symbols["_" + names["%08x" % a]]
    lo = max(k for k in data if k < a)
    return data[lo] + a - lo


def run(new, angle, flags=0, tile=(0, 0, 16, 32)):
    m = machine(build / "gex-source.exe" if new else ROOT / ".work/original.exe")

    def put(a, v):
        m.mem_write(a, struct.pack("<I", v & 0xFFFFFFFF))

    def glob(a, v):
        put(addr(a, new), v)

    obj = 0x1003000
    sprite = 0x1004000
    lst = 0x1004100
    draw = 0x1004200
    img = 0x1004300
    tex = 0x1004400
    pool = 0x1006000
    for a, v in {
        0x4A2974: 0,
        0x4A2988: 0,
        0x4A2AC8: 20,
        0x4A2A94: 0,
        0x4A2AE4: pool,
        0x4A2ADC: pool + 0x2000,
        0x4A2AE0: pool,
        0x4A2B18: 0x1005000,
        0x4A2B14: 0x1005010,
        0x460F6C: tex,
    }.items():
        glob(a, v)
    for a, v in {
        0x6C: flags,
        0x78: 160 << 16,
        0x7C: 120 << 16,
        0xBC: 0,
        0xC0: 0,
        0xC4: angle << 16,
        0xC8: 0x10000,
        0xCC: 0x10000,
        0x1F4: 100,
    }.items():
        put(obj + a, v)
    put(sprite + 0x18, lst)
    put(lst, draw)
    put(draw + 8, img)
    for a, v in {
        0: 16 << 16,
        4: 32 << 16,
        8: -8 << 16,
        12: -16 << 16,
        16: 0x42,
        20: 0x20100001,
        24: 0,
        28: 0,
    }.items():
        put(img + a, v)
    tx, ty, tw, th = tile
    put(img + 20, 1 | (tw << 16) | (th << 24))
    put(img + 24, (tx & 0xFFFF) | ((ty & 0xFFFF) << 16))
    put(tex, 0x00000000)
    put(tex + 4, 0)
    hooks = {addr(0x41A500, new): sprite, addr(0x43E2C0, new): 0x808080}

    def hook(cpu, a, size, _):
        if a in hooks:
            sp = cpu.reg_read(UC_X86_REG_ESP)
            ret = struct.unpack("<I", cpu.mem_read(sp, 4))[0]
            cpu.reg_write(UC_X86_REG_EAX, hooks[a])
            cpu.reg_write(UC_X86_REG_ESP, sp + 4)
            cpu.reg_write(UC_X86_REG_EIP, ret)

    m.hook_add(UC_HOOK_CODE, hook)
    m.mem_write(0x1002000, struct.pack("<II", 0x1000000, obj))
    m.reg_write(UC_X86_REG_ESP, 0x1002000)
    m.emu_start(addr(0x441150, new), 0x1000000, count=20000)
    assert m.reg_read(UC_X86_REG_EIP) == 0x1000000, hex(m.reg_read(UC_X86_REG_EIP))
    return bytes(m.mem_read(pool, 80))


if __name__ == "__main__":
    assert hashlib.sha256((ROOT / ".work/original.exe").read_bytes()).hexdigest() == PIN
    count = 0
    for angle in [1, 32, 64, 96, 128, 160, 192, 224, 256, -64, -128]:
        for tile in [(0, 0, 16, 32), (0, 0, 8, 16), (8, 16, 8, 16), (4, 8, 8, 16)]:
            expected = run(False, angle, tile=tile)
            actual = run(True, angle, tile=tile)
            assert actual == expected, (angle, tile)
            count += 1
    print(f"{count} rotated sprite command pairs agree with the pinned original")
