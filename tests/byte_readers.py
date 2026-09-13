#!/usr/bin/env python3
"""Host-only behavioural checks, NOT original-byte verification or an ABI proof.

Compile the two self-contained candidates with the host compiler. __cdecl is
removed only for this Linux test build; the matching queue still uses the pinned
VC4-era compiler and unchanged candidate files. Outputs remain under .work/.
"""
import ctypes
import hashlib
import json
import pathlib
import random
import subprocess

ROOT = pathlib.Path(__file__).resolve().parents[1]
OUT = ROOT / '.work' / 'byte-reader-tests'
OUT.mkdir(parents=True, exist_ok=True)
U8 = ctypes.c_ubyte
P8 = ctypes.POINTER(U8)
results = []
for address, width in [('00417f40', 2), ('00417f00', 4)]:
    source = ROOT / 'src' / 'functions' / (address + '.cpp')
    source_hash = hashlib.sha256(source.read_bytes()).hexdigest()
    library = OUT / (address + '-' + source_hash[:16] + '.so')
    command = ['g++', '-shared', '-fPIC', '-O2', '-D__cdecl=', str(source), '-o', str(library)]
    subprocess.run(command, check=True)
    module = ctypes.CDLL(str(library))
    function = module.GEX_Target
    function.argtypes = [ctypes.POINTER(P8)]
    function.restype = ctypes.c_ulong
    count = 0

    def check(value, offset):
        global count
        buffer = (U8 * 12)(*([0xa5] * 12))
        expected = list(buffer)
        encoded = value.to_bytes(width, 'little')
        for i, byte in enumerate(encoded):
            buffer[offset + i] = byte
            expected[offset + i] = byte
        start = ctypes.addressof(buffer) + offset
        cursor = ctypes.cast(start, P8)
        actual = function(ctypes.byref(cursor))
        assert actual == value, (address, value, actual)
        assert ctypes.cast(cursor, ctypes.c_void_p).value == start + width
        assert list(buffer) == expected, 'reader modified input bytes'
        count += 1

    if width == 2:
        for value in range(65536):
            check(value, 1)
    else:
        for value in [0, 1, 0x7fffffff, 0x80000000, 0xffffffff, 0x12345678]:
            for offset in range(4):
                check(value, offset)
        for lane in range(4):
            for byte in range(256):
                check(byte << (lane * 8), 1)
        random_values = random.Random(0x474558)
        for _ in range(10000):
            check(random_values.getrandbits(32), 1)
    results.append(dict(address=address, cases=count, sourceHash=source_hash,
                        compilerCommand=command, kind='host behavioural check; not ExactMatch'))
report = json.dumps(results, indent=2)
(OUT / 'report.json').write_text(report + '\n')
print(report)
