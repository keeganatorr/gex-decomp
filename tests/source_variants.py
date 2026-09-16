#!/usr/bin/env python3
"""Host-only behavior tests for reviewed variant families, NOT byte proofs.
The real CL/PE/COFF checks remain exclusively pc-decomp-owned.
"""
import ctypes, importlib.util, pathlib, random, subprocess, tempfile, unittest
ROOT=pathlib.Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('variants',ROOT/'tools/source_variants.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)

class Variants(unittest.TestCase):
    def test_deterministic_bounded(self):
        for entry in ('0042dcf0','0040bc50'):
            a=mod.variants(entry,96);self.assertEqual(a,mod.variants(entry,96));self.assertEqual(len(a),96)
            self.assertEqual(len({v['source'] for v in a}),96)
            for v in a:
                for forbidden in ('#','__asm','volatile','0x004','0x00'):
                    self.assertNotIn(forbidden,v['source'])
        with self.assertRaises(ValueError):mod.variants('00400000')

    def test_behavior_all_bounded_variants(self):
        rng=random.Random(10005270);values=[0,1,2,0x7fffffff,0x80000000,0xfffffffe,0xffffffff]+[rng.getrandbits(32) for _ in range(100)]
        with tempfile.TemporaryDirectory(prefix='gex-variant-semantics-') as td:
            for entry in ('0042dcf0','0040bc50'):
                src=['typedef char uint_is_32[sizeof(unsigned)==4?1:-1];\n']
                cases=mod.variants(entry,256)
                for v in cases:
                    name=v['id'];s=v['source'].replace('GEX_Target','target_'+name)
                    if entry=='0042dcf0':
                        global_='gPlayerObject_004a27fc';callee='FUN_0042cc70_Object_unk'
                        import re
                        typ=re.search(r'extern (.+) '+global_+';',s).group(1)
                        s=s.replace('extern '+typ+' '+global_+';',typ+' '+global_+';').replace(global_,'global_'+name).replace(callee,'call_'+name)
                        s+=f'unsigned count_{name}, zero_{name}; unsigned long long last_{name};\n'
                        s+=f'extern "C" void call_{name}(int z,{typ} p) {{count_{name}++;zero_{name}=z;last_{name}=(unsigned long long)p;global_{name}=({typ})0;}}\n'
                        s+=f'extern "C" unsigned test_{name}(unsigned long long p,unsigned long long g) {{global_{name}=({typ})g;count_{name}=0;int r=target_{name}(({typ})p);return r==0 && count_{name}==(unsigned)(p==g) && (!count_{name} || (zero_{name}==0 && last_{name}==p));}}\n'
                    else:
                        typ='int' if 'extern int DAT_' in s else 'unsigned'
                        atype='int' if 'int amount' in s else 'unsigned'
                        s=s.replace('extern '+typ+' DAT_00456034;',typ+' DAT_00456034;').replace('DAT_00456034','global_'+name)
                        s+=f'extern "C" unsigned test_{name}(unsigned p,unsigned g) {{global_{name}=({typ})g;target_{name}(({atype})p);return (unsigned)global_{name};}}\n'
                    src.append(s)
                source=pathlib.Path(td)/(entry+'.cpp');library=pathlib.Path(td)/(entry+'.so');source.write_text(''.join(src))
                subprocess.run(['g++','-std=c++98','-O2','-shared','-fPIC','-D__cdecl=',str(source),'-o',str(library)],check=True,capture_output=True)
                lib=ctypes.CDLL(str(library))
                for v in cases:
                    f=getattr(lib,'test_'+v['id']);f.restype=ctypes.c_uint
                    f.argtypes=[ctypes.c_ulonglong,ctypes.c_ulonglong] if entry=='0042dcf0' else [ctypes.c_uint,ctypes.c_uint]
                    for x in values:
                        for g in (x,0,0xffffffff,0x80000000,rng.getrandbits(32)):
                            expected=1 if entry=='0042dcf0' else (g if g==0xffffffff else (g+x)&0x7fffffff)
                            self.assertEqual(f(x,g),expected,(entry,v['id'],x,g))

if __name__=='__main__':unittest.main()
