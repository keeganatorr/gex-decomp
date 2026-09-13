#!/usr/bin/env python3
"""Synthetic binary and effective-contract checks; no game/compiler needed."""
import pathlib
import struct
import sys
import unittest
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[1] / 'tools'))
from proof_audit import image_bytes, resolve_object, check_contract


def coff():
    code = b'\xa1' + struct.pack('<I', 4) + b'\xe8' + struct.pack('<I', 0) + b'\xc3'
    raw, relocs = 60, 60 + len(code)
    symbols_at = relocs + 20
    names = ['_GEX_Target@4', '_data', '_callee']
    strings = bytearray(b'\0' * 4)
    symbols = bytearray()
    for index, name in enumerate(names):
        offset = len(strings)
        strings += name.encode() + b'\0'
        symbols += struct.pack('<IIIhHBB', 0, offset, 0, 1 if index == 0 else 0, 0x20 if index == 0 else 0, 2, 0)
    struct.pack_into('<I', strings, 0, len(strings))
    header = struct.pack('<HHIIIHH', 0x14c, 1, 0, symbols_at, 3, 0, 0)
    section = struct.pack('<8sIIIIIIHHI', b'.text\0\0\0', 0, 0, len(code), raw, relocs, 0, 2, 0, 0x60000020)
    return bytearray(header + section + code + struct.pack('<IIHIIH', 1, 1, 6, 6, 2, 20) + symbols + strings)


class Tests(unittest.TestCase):
    def resolve(self, data=None, bindings=None):
        return resolve_object(coff() if data is None else data, '_GEX_Target@4', 0x401000,
                              {'_data': '00402000', '_callee': '00401100'} if bindings is None else bindings)

    def test_dir32_rel32_addends_and_decorated_target(self):
        code, relocations = self.resolve()
        self.assertEqual(code, b'\xa1' + struct.pack('<I', 0x402004) + b'\xe8' + struct.pack('<I', 0xf6) + b'\xc3')
        self.assertEqual(relocations, [{'Offset': 1, 'Type': 6, 'Symbol': '_data'}, {'Offset': 6, 'Type': 20, 'Symbol': '_callee'}])

    def test_self_binding_and_modular_relative_arithmetic(self):
        data = coff()
        struct.pack_into('<I', data, 71 + 10 + 4, 0)
        code, _ = self.resolve(data)
        self.assertEqual(struct.unpack_from('<I', code, 6)[0], 0xfffffff6)

    def test_reject_unsafe_relocations(self):
        for at, fmt, value in [(71 + 10, '<I', 3), (71 + 10, '<I', 9), (71 + 8, '<H', 7), (71 + 4, '<I', 30)]:
            with self.subTest(at=at, value=value):
                data = coff(); struct.pack_into(fmt, data, at, value)
                with self.assertRaises(ValueError): self.resolve(data)
        with self.assertRaises(ValueError): self.resolve(bindings={})
        with self.assertRaises(ValueError): self.resolve(bindings={'_data':'100000000', '_callee':'00401100'})

    def test_truncation_bad_section_and_ambiguous_extent(self):
        for data in [coff()[:19], coff()[:-1]]:
            with self.assertRaises(ValueError): self.resolve(data)
        for at, fmt, value in [(20 + 20, '<I', 0xffff), (16, '<H', 1), (91 + 8, '<I', 1),
                               (91 + 18 + 12, '<I', 0x00200001)]:
            data = coff(); struct.pack_into(fmt, data, at, value)
            with self.assertRaises(ValueError): self.resolve(data)
        with self.assertRaises(ValueError): resolve_object(coff(), 'wrong', 0x401000, {})

    def test_raw_backed_pe_range(self):
        data = bytearray(528);data[:2] = b'MZ';struct.pack_into('<I', data, 0x3c, 0x80)
        data[0x80:0x84] = b'PE\0\0';struct.pack_into('<HH', data, 0x84, 0x14c, 1)
        struct.pack_into('<H', data, 0x94, 0xe0);struct.pack_into('<H', data, 0x98, 0x10b)
        struct.pack_into('<I', data, 0x98 + 28, 0x400000)
        struct.pack_into('<III', data, 0x178 + 12, 0x1000, 16, 512)
        data[512:] = bytes(range(16))
        self.assertEqual(image_bytes(data, 0x401004, 4), b'\x04\x05\x06\x07')
        for address, size in [(0x40100f, 2), (0x400fff, 1), (0x401000, 0)]:
            with self.assertRaises(ValueError): image_bytes(data, address, size)
        with self.assertRaises(ValueError): image_bytes(data[:520], 0x401004, 8)

    def test_effective_contract_and_legacy_cpp(self):
        config = {'toolchain': {'flags': ['/O2'], 'targetSymbol': '_GEX_Target'},
                  'functionOverrides': {'00401000': {'flags': ['/O1'], 'language': 'c', 'targetSymbol': '_GEX_Target@4'}}}
        legacy = {'flags': ['/O2'], 'targetSymbol': '_GEX_Target'}
        check_contract(legacy, config, '00402000')
        with self.assertRaises(ValueError): check_contract(legacy, config, '00401000')
        current = {'flags': ['/O1'], 'language': 'c', 'targetSymbol': '_GEX_Target@4'}
        check_contract(current, config, '00401000')
        for key, value in [('flags', ['/O2']), ('language', 'cpp'), ('targetSymbol', '_GEX_Target')]:
            changed = dict(current); changed[key] = value
            with self.assertRaises(ValueError): check_contract(changed, config, '00401000')


if __name__ == '__main__':
    unittest.main()
