#!/usr/bin/env python3
"""Synthetic listing and host behavior tests; neither is an exact-byte proof."""
import ctypes, pathlib, random, subprocess, sys, tempfile, unittest
ROOT=pathlib.Path(__file__).resolve().parents[1];sys.path.insert(0,str(ROOT/'tools'))
import search_feedback as sf
import source_variants as variants


def listing(candidate=False, entry=0x1000, first=0x2000, flag=0x3000, tail=0x4000):
    # Placeholder bytes exercise parsing/CFG extent only, not PE decoding.
    ops=[(5,'calll',f'0x{first:x}')]
    ops += [(5,'movb',f'0x{flag:x}, %al'),(2,'testb','%al, %al')] if candidate else [(7,'cmpb',f'$0x0, 0x{flag:x}')]
    ops += [(2,'je',f'0x{entry+19:x}'),(5,'jmp',f'0x{tail:x}'),(1,'retl','')]
    lines=[];address=entry
    for length,op,args in ops:
        lines.append(f' {address:x}: '+ '00 '*length+' '+op+' '+args);address+=length
    return '\n'.join(lines)+'\n'


def detail():
    return {'entry':'0044c690','size':20,'extentVerified':True,'ghidraBytesEqualOriginal':True,
            'originalAssembly':listing(entry=0x44c690,first=0x44e7e0,flag=0x461138,tail=0x44e920)}


class Feedback(unittest.TestCase):
    def test_liveout_and_partial_registers(self):
        for alias in ('%al','%ah','%ax','%eax'):
            result=sf.feedback(listing(),listing(True).replace('%al',alias))
            self.assertTrue(result['lostCallResultOnReturn']);self.assertFalse(result['isProof'])
        self.assertFalse(sf.feedback(listing(),listing())['lostCallResultOnReturn'])
        self.assertFalse(sf.feedback(listing(),listing(True).replace('%al','%cl'))['lostCallResultOnReturn'])
        self.assertEqual(sf.cleanup_evidence(detail())['flagBits'],8)
        self.assertFalse(sf.cleanup_evidence(detail())['isAbiProof'])

    def test_fail_closed(self):
        for s in (listing().replace('cmpb','cpuid'),listing().replace('0x4000','*%eax'),
                  listing().replace('0x1013','0x1000'),listing().replace('0x1013','0x9000'),
                  listing().replace('1005:','1006:'),listing().replace('retl ','retl $4'),listing().replace('retl','nop')):
            with self.assertRaises(ValueError):sf.eax_exits(s)
        for f in ({**detail(),'extentVerified':False},{**detail(),'ghidraBytesEqualOriginal':False},
                  {**detail(),'originalAssembly':detail()['originalAssembly'].replace('cmpb','cmpl')}):
            with self.assertRaises(ValueError):list(variants.cleanup_variants(f))
        with self.assertRaises(ValueError):variants.variants('0044c690',12)
        with self.assertRaises(ValueError):variants.variants('0044c690',0,detail())

    def test_resolved_not_placeholder_control_flow(self):
        import struct
        base=0x1000
        obj='0: e8 00 00 00 00 calll 0x5\n5: a0 00 00 00 00 movb 0x0, %al\na: 84 c0 testb %al, %al\nc: 74 05 je 0x13\ne: e9 00 00 00 00 jmp 0x13\n13: c3 retl\n'
        resolved=b'\xe8'+struct.pack('<i',0x2000-(base+5))+b'\xa0'+struct.pack('<I',0x3000)+bytes.fromhex('84c07405e9')+struct.pack('<i',0x4000-(base+19))+b'\xc3'
        result=sf.eax_exits(sf.relocated_listing(obj,resolved,base))
        self.assertEqual(len([e for e in result if e['exit']=='return']),1)
        self.assertEqual([e['target'] for e in result if e['exit']=='tail'],[0x4000])
        self.assertTrue(sf.feedback(listing(),sf.relocated_listing(obj,resolved,base))['lostCallResultOnReturn'])
        with self.assertRaises(ValueError):sf.relocated_listing(obj,resolved[:-1],base)
        with self.assertRaises(ValueError):sf.relocated_listing(obj,b'\x90'+resolved[1:],base)

    def test_no_automatic_hypothesis_repetition(self):
        lost={'lostCallResultOnReturn':True}
        sf.require_new_liveout_hypothesis({},lost)
        sf.require_new_liveout_hypothesis({'families':{'eax-liveout':{'distinctOutputs':0}}},lost)
        with self.assertRaises(ValueError):sf.require_new_liveout_hypothesis({}, {'lostCallResultOnReturn':False})
        with self.assertRaises(ValueError):sf.require_new_liveout_hypothesis({'families':{'eax-liveout':{'distinctOutputs':1}}},lost)
        with self.assertRaises(ValueError):sf.require_new_liveout_hypothesis({'families':{'observable-byte':{'distinctOutputs':1}}},lost)

    def test_prioritization(self):
        cases=variants.variants('0044c690',12,detail());self.assertEqual(len(cases),12)
        self.assertEqual(cases,variants.variants('0044c690',12,detail()))
        self.assertEqual([c['family'] for c in cases],['eax-liveout']*6+['observable-byte']*6)
        self.assertIn('return result;',cases[0]['source'])
        for c in cases:
            for forbidden in ('__asm','#','0x004'):self.assertNotIn(forbidden,c['source'])
            self.assertEqual(c['source'].count('DAT_00461138'),2, 'One declaration plus exactly one byte-read expression')
            self.assertEqual(c['source'].count('volatile'),int(c['family']=='observable-byte'))

    def test_behavior_including_return_bits(self):
        cases=variants.variants('0044c690',12,detail());code=['typedef char uint_is_32[sizeof(unsigned)==4?1:-1];\n']
        for c in cases:
            name=c['id'];s=c['source'];typ='unsigned char' if 'extern unsigned char' in s else 'char'
            s=s.replace(f'extern {typ} DAT_00461138;',f'{typ} DAT_00461138;')
            for symbol in ('GEX_Target','FUN_0044e7e0','FUN_0044e920','DAT_00461138'):s=s.replace(symbol,symbol+'_'+name)
            s+=f'unsigned trace_{name}, next_{name}, first_{name}, last_{name};\n'
            s+=f'extern "C" unsigned FUN_0044e7e0_{name}(void) {{trace_{name}=trace_{name}*10+1;DAT_00461138_{name}=({typ})next_{name};return first_{name};}}\n'
            s+=f'extern "C" unsigned FUN_0044e920_{name}(void) {{trace_{name}=trace_{name}*10+2;return last_{name};}}\n'
            call=f'unsigned value=GEX_Target_{name}();'
            check=f' && value==(flag ? b : a)'
            s+=f'extern "C" unsigned test_{name}(unsigned initial,unsigned flag,unsigned a,unsigned b) {{trace_{name}=0;next_{name}=flag;first_{name}=a;last_{name}=b;DAT_00461138_{name}=({typ})initial;{call} return trace_{name}==(flag ? 12u : 1u){check};}}\n'
            code.append(s)
        with tempfile.TemporaryDirectory(prefix='liveout-behavior-') as tmp:
            source=pathlib.Path(tmp)/'test.cpp';out=pathlib.Path(tmp)/'test.so';source.write_text(''.join(code))
            subprocess.run(['g++','-std=c++98','-O2','-shared','-fPIC','-D__cdecl=',str(source),'-o',str(out)],check=True,capture_output=True)
            lib=ctypes.CDLL(str(out));rng=random.Random(5270);values=[0,1,0xff,0x100,0x80000000,0xffffffff]+[rng.getrandbits(32) for _ in range(10)]
            for c in cases:
                f=getattr(lib,'test_'+c['id']);f.argtypes=[ctypes.c_uint]*4;f.restype=ctypes.c_uint
                for flag in range(256):
                    for a in values:
                        b=rng.getrandbits(32)
                        for initial in (0,255):self.assertEqual(f(initial,flag,a,b),1,(c['id'],flag,a,b))

if __name__=='__main__':unittest.main()
