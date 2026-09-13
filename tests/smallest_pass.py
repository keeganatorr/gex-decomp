#!/usr/bin/env python3
"""Synthetic client safety checks; no real compiler/provider/backend mutation."""
import importlib.util
import importlib.machinery
import pathlib
import struct
import tempfile
import unittest
from unittest import mock

spec = importlib.util.spec_from_file_location('smallest_pass', pathlib.Path(__file__).resolve().parents[1]/'tools/smallest_pass.py')
p = importlib.util.module_from_spec(spec)
spec.loader.exec_module(p)


class PassTests(unittest.TestCase):
    def test_independent_pe_slicing(self):
        script = pathlib.Path(__file__).resolve().parents[1]/'scripts/report-smallest-pass'
        loader = importlib.machinery.SourceFileLoader('pass_report_test', str(script))
        module_spec = importlib.util.spec_from_loader(loader.name, loader)
        report = importlib.util.module_from_spec(module_spec)
        loader.exec_module(report)
        image = bytearray(528)
        struct.pack_into('<I', image, 0x3c, 0x80)
        image[0x80:0x84] = b'PE\0\0'
        struct.pack_into('<H', image, 0x86, 1)
        struct.pack_into('<H', image, 0x94, 0xe0)
        struct.pack_into('<H', image, 0x98, 0x10b)
        struct.pack_into('<I', image, 0x98+28, 0x400000)
        struct.pack_into('<III', image, 0x178+12, 0x1000, 16, 512)
        image[512:528] = bytes(range(16))
        self.assertEqual(report.image_bytes(image, 0x401003, 4), b'\x03\x04\x05\x06')
        with self.assertRaisesRegex(RuntimeError, 'outside raw-backed'):
            report.image_bytes(image, 0x40100f, 2)

    def test_comments_preserve_strings(self):
        self.assertEqual(p.normalized('/* x */ return "https://a/*b*/"; // tail'), ('return', '"https://a/*b*/"', ';'))

    def test_normalization_preserves_token_and_literal_boundaries(self):
        self.assertNotEqual(p.normalized('"a b"'), p.normalized('"ab"'))
        self.assertNotEqual(p.normalized('a + +b'), p.normalized('a++b'))
        self.assertNotEqual(p.normalized('unsigned int'), p.normalized('unsignedint'))
        self.assertEqual(p.normalized('return  x /* comment */ + 1;'), p.normalized('return x+1;'))

    def test_extent_gates(self):
        d = dict(size=1, extentVerified=True, bodyEnd='00401000', originalAssembly='00401000: c3  retl\n')
        self.assertEqual(p.preflight(d), '')
        self.assertIn('Edited', p.preflight(dict(d, ghidraBytesEqualOriginal=False)))
        self.assertIn('Unproven', p.preflight(dict(d, extentVerified=False)))
        self.assertIn('Unproven', p.preflight(dict(d, extentVerified=False, analysisWarning=None)))
        self.assertIn('fall-through', p.preflight(dict(d, originalAssembly='00401000: 53  pushl %ebx\n')))
        self.assertIn('noreturn', p.preflight(dict(d, originalAssembly='00401000: e8 00 00 00 00  calll 0x401005\n')))
        self.assertIn('import thunk', p.preflight(dict(d, size=6, originalAssembly='00401000: ff 25 00 10 40 00  jmpl *0x401000\n')))

    def test_proposal_rejects_unrecovered_inputs_and_non_cdecl(self):
        d = dict(size=30, ghidraPseudocode='int FUN_00401000(void) { return unaff_EBX; }')
        with self.assertRaisesRegex(ValueError, 'register/stack'):
            p.fresh_proposal(d, '', None, {})
        d['ghidraPseudocode'] = 'int __stdcall FUN_00401000(int x) { return x; }'
        with self.assertRaisesRegex(ValueError, 'non-cdecl'):
            p.fresh_proposal(d, '', None, {})
        d['ghidraPseudocode'] = 'int FUN_00401000(void) { return 0; }'
        with self.assertRaisesRegex(ValueError, 'placeholder'):
            p.fresh_proposal(d, '', None, {})
        d['ghidraPseudocode'] = 'void FUN_00401000(void) { return; }'
        with self.assertRaisesRegex(ValueError, 'placeholder'):
            p.fresh_proposal(d, '', None, {})

    def test_empty_real_body(self):
        source = p.fresh_proposal(dict(size=1, ghidraPseudocode='void FUN_00401000(void) { return; }'), '', None, {})
        self.assertIn('void GEX_Target(void)', source)
        self.assertIn('return;', source)

    def test_splice_preserves_existing_declarations(self):
        with tempfile.TemporaryDirectory() as temp:
            path = pathlib.Path(temp)/'previous.cpp'
            old = 'typedef unsigned int uint;\nextern "C" { extern uint data_00402000; uint GEX_Target(uint x) { return x; } }'
            path.write_text(old)
            d = dict(size=20, ghidraPseudocode='uint FUN_00401000(uint x) { return x + data_00402000; }')
            proposal = p.fresh_proposal(d, old, path, {'_data_00402000': '00402000'})
            self.assertEqual(proposal.count('typedef unsigned int uint;'), 1)
            path.write_text(proposal)
            self.assertEqual(p.syntax(path)[0], 0)

    def test_opaque_type_does_not_invent_layout(self):
        with tempfile.TemporaryDirectory() as temp:
            path = pathlib.Path(temp)/'candidate.cpp'
            raw = 'extern "C" { GXObject **GEX_Target(GXObject **p) { p[0]=p[1]; return p; } }'
            source, used, errors = p.repair_declarations(raw, path, {})
            self.assertEqual(errors, [])
            self.assertIn('struct GXObject;', source)
            self.assertNotIn('struct GXObject {', source)
            raw = 'extern "C" { GXObject *GEX_Target(GXObject *p) { return p+1; } }'
            source, used, errors = p.repair_declarations(raw, path, {})
            self.assertTrue(errors)

    def test_declaration_reuse_changes_only_known_identifier(self):
        with tempfile.TemporaryDirectory() as temp:
            path = pathlib.Path(temp)/'candidate.cpp'
            catalog = {'work': {'name':'DAT_00401000', 'declaration':'extern unsigned int DAT_00401000;'}}
            source, used, errors = p.repair_declarations('extern "C" { void GEX_Target() { work=3; } }', path, catalog)
            self.assertEqual(errors, [])
            self.assertEqual(used, ['work'])
            self.assertIn('DAT_00401000=3;', source)

    def test_install_and_external_edit_refusal(self):
        with tempfile.TemporaryDirectory() as temp, mock.patch.object(p, 'ROOT', pathlib.Path(temp)):
            state_path = pathlib.Path(temp)/'state.json'
            state = dict(installedHash=None)
            p.install('00401000', b'first', state, state_path)
            target = pathlib.Path(temp)/'src/functions/00401000.cpp'
            self.assertEqual(target.read_bytes(), b'first')
            target.write_bytes(b'user edit')
            with self.assertRaisesRegex(RuntimeError, 'external source edit'):
                p.install('00401000', b'second', state, state_path)
            self.assertEqual(target.read_bytes(), b'user edit')

    def test_interrupted_install_and_remove_recovery(self):
        with tempfile.TemporaryDirectory() as temp, mock.patch.object(p, 'ROOT', pathlib.Path(temp)):
            target = pathlib.Path(temp)/'src/functions/00401000.cpp'
            p.atomic_bytes(target, b'new')
            state_path = pathlib.Path(temp)/'state.json'
            state = dict(installedHash=p.digest(b'old'), nextHash=p.digest(b'new'), installPending=True)
            p.recover_install('00401000', state, state_path)
            self.assertEqual(state['installedHash'], p.digest(b'new'))
            self.assertFalse(state['installPending'])
            p.install('00401000', None, state, state_path)
            self.assertFalse(target.exists())
            self.assertIsNone(state['installedHash'])

    def test_uncertainty_keeps_stable_command(self):
        with tempfile.TemporaryDirectory() as temp, mock.patch.object(p, 'ROOT', pathlib.Path(temp)), mock.patch.object(p, 'WORK', pathlib.Path(temp)/'work'):
            root = pathlib.Path(temp)
            (root/'project.json').write_text('{}')
            p.WORK.mkdir()
            state = dict(installedHash=p.digest(b'source'), attempts=[])
            manifest = dict(configHash=p.digest(b'{}'), analysisEpoch='test')
            with mock.patch.object(p.subprocess, 'run', return_value=mock.Mock(returncode=3)):
                with self.assertRaisesRegex(RuntimeError, 'resolve smallest-'):
                    p.verify('00401000', 'trial', manifest, state, root/'state.json')
                first = state['pendingCommand']
                with self.assertRaises(RuntimeError):
                    p.verify('00401000', 'trial', manifest, state, root/'state.json')
                self.assertEqual(state['pendingCommand'], first)
            self.assertEqual(state['attempts'], [])

    def test_snapshot_order_and_existing_match_protection(self):
        class Fake:
            snapshot = {'health': {'ghidra': {'analysisEpoch':'test'}}, 'progress':{}}
            def inventory(self):
                return [dict(id='b',address='00401020',size=8,status='Compiles'),
                        dict(id='a',address='00401010',size=1,status='Unanalysed'),
                        dict(id='c',address='00401030',size=1,status='ExactMatch')]
        with tempfile.TemporaryDirectory() as temp, mock.patch.object(p, 'ROOT', pathlib.Path(temp)), mock.patch.object(p, 'WORK', pathlib.Path(temp)/'work'):
            root = pathlib.Path(temp)
            (root/'project.json').write_text('{}')
            (root/'src/functions').mkdir(parents=True)
            (root/'src/functions/00401030.cpp').write_bytes(b'protected')
            manifest = p.capture(Fake())
            self.assertEqual([r['address'] for r in manifest['rows']], ['00401010','00401020'])
            self.assertEqual(manifest['originalSources']['00401030'], p.digest(b'protected'))
            self.assertEqual(p.capture(Fake()), manifest)


if __name__ == '__main__':
    unittest.main()
