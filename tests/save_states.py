#!/usr/bin/env python3
"""Run the linked snapshot and audio serializers under x86 with synthetic resources.

OS/DirectSound calls are mocked; graph serialization, validation, migrations and
commit are the actual VC4-compiled replacement code. No proprietary fixtures.
"""
import re
import struct
import zlib
import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP
from sprite_viewer import ROOT


class Machine:
    def __init__(self, files=None, heap=0x2000000, executable=None, symbol_map=None):
        build = ROOT / '.work/replacement-short'
        pe = pefile.PE(str(executable or build / 'gex-source.exe'))
        self.cpu = Uc(UC_ARCH_X86, UC_MODE_32)
        self.cpu.mem_map(pe.OPTIONAL_HEADER.ImageBase, (pe.OPTIONAL_HEADER.SizeOfImage+4095)&~4095)
        self.cpu.mem_write(pe.OPTIONAL_HEADER.ImageBase, pe.get_memory_mapped_image())
        self.cpu.mem_map(0x1000000, 0x100000)
        self.cpu.mem_map(heap, 0x8000000)
        self.next = heap + 0x1000
        self.heap_end=heap+0x8000000
        self.allocations={}
        self.free_blocks=[]
        self.symbols = {}
        for line in (symbol_map or build / 'gex-source.map').read_text(errors='replace').splitlines():
            f = line.split()
            if len(f) >= 3 and f[0].count(':') == 1:
                try: self.symbols[f[1]] = int(f[2],16)
                except ValueError: pass
        self.stubs = {}
        self.stub_next=0x1001000
        self.cpu.hook_add(UC_HOOK_CODE,self.hook,begin=0x1001000,end=0x100afff)
        self.files = dict(files or {})
        self.files.setdefault('VFX\\GEX017.VFX',bytes(range(64)))
        self.files.setdefault('MUS\\GEX035.MUS',bytes(range(128)))
        self.files.setdefault('SFX\\GEX.SFX',bytes(range(64))*8)
        self.handles = {}
        self.next_handle=0x100
        self.buffers = {}
        self.notices = []
        self.fail_alloc = self.fail_write = self.fail_audio = False
        self.fail_flush=self.fail_replace=self.fail_create=False
        self.fail_after=None
        self.tick = 1000
        self.paused_presents=0
        for name in ('_malloc','_free','_sprintf','??2@YAPAXI@Z','??3@YAXPAX@Z'):
            self.stub(self.symbols[name], name)
        for name in ('?SSAudioHold@@YAHXZ','?SSAudioRelease@@YAXXZ'):
            self.stub(self.symbols[name], name)
        self.stub(self.symbols['?checksum@@YAIPBEII@Z'], 'checksum')
        for name in ('M1_PlayLevel_0040a010','M1_GameLoop_0040ad40','M1_ExitLevel_0040a660','M1_FreeLevel_0040aa60',
                     'DRAW_CacheClear_0043e430','DRAW_CacheInit_0043e350',
                     'FUN_0043eb50_LoadTilePoss','BLOC_BlockLoader_0040b460',
                     'TXT_DrawPrintP_0043fa70','TXT_DrawPrintFP_0043faa0','FUN_0040b2d0_InputProcessing','GFX_Flush_00406c30'):
            self.stub(self.symbols['_'+name], name)
        sizes = {'SetWindowTextA':8,'PostMessageA':16,'InterlockedIncrement':4,'InterlockedDecrement':4,'InterlockedExchange':8,'GetModuleFileNameA':12,'GlobalAlloc':8,'GlobalFree':4,'GetTickCount':0,'Sleep':4,
                 'OutputDebugStringA':4,'CreateFileA':28,'CloseHandle':4,
                 'ReadFile':20,'WriteFile':20,'SetFilePointer':16,'GetFileSize':8,
                 'FlushFileBuffers':4,'MoveFileExA':12,'DeleteFileA':4,
                 'CreateDirectoryA':8,'GetEnvironmentVariableA':12}
        for dll in pe.DIRECTORY_ENTRY_IMPORT:
            for imp in dll.imports:
                name = imp.name.decode() if imp.name else ''
                if name in sizes:
                    target = self.stub_next; self.stub_next+=16
                    self.put(imp.address, target)
                    self.stub(target, name, sizes[name])
        self.regions = [self.words(self.symbols['_SSImages']+n*12,3) for n in range(3)]
        # Construct a minimal stable gameplay boundary, with explicit pointer
        # fields and a scalar whose value deliberately looks like an old pointer.
        ranges = [(0x455b00,0x461000),(0x461180,0x461184),(0x4626d0,0x464e28),
                  (0x46a530,0x46d000),(0x4a0200,0x4a2b0c),(0x47ef70,0x47f004),
                  (0x455998,0x45599c),(0x49f6b0,0x49fb14),(0x49fb54,0x49fb58),
                  (0x49fb90,0x4a0200)]
        for a,b in ranges: self.cpu.mem_write(self.address(a), bytes(b-a))
        self.put(self.address(0x4a33ac), self.alloc(0x100000))
        self.put(self.address(0x4a2964),3)
        self.put(self.address(0x455c3c),1)
        self.put(self.address(0x487f88),1)
        self.put(self.address(0x4626f0),1)
        self.graph = self.alloc(32)
        self.call('GEX_StateAllocated',self.graph,32)
        self.put(self.graph, self.graph+12)
        self.put(self.graph+4,self.graph+12)  # scalar, not a descriptor
        self.put(self.graph+8,self.symbols['_GOB_DoIt_0040ef40'])
        self.put(self.graph+12,0x12345678)
        self.call('GEX_StatePointer',self.graph)
        self.call('GEX_StatePointer',self.graph+8)
        self.put(self.address(0x4a27dc),self.graph)
        # Input-record schema accesses two records; use a different valid root.
        self.put(self.address(0x4a27dc),0)
        self.put(self.address(0x4a2ad4),self.graph)
        self.put(self.address(0x4a281c),3)
        self.put(self.address(0x461180),0xabc)
        self.put(self.address(0x49a070), self.device())
        slots=[0x48a040,0x49a068]+list(range(0x49fb30,0x49fb50,4))
        self.audio=0
        for i,slot in enumerate(slots):
            b=self.buffer(bytes(range(64)),cursor=20+i*2,status=5 if i%2==0 else 1)
            self.put(self.address(slot),b)
            if not i: self.audio=b
            if i:
                asset='VFX\\GEX017.VFX' if i==1 else 'SFX\\GEX.SFX'
                name=self.alloc(len(asset)+1); self.cpu.mem_write(name,asset.encode()+b'\0')
                self.call('GEX_StateAudioAsset',i,name,0 if i==1 else (i-2)*64,64)
        self.cpu.mem_write(self.address(0x48a050),bytes(range(256))*256)
        self.put(self.address(0x49a058),0xe000)
        self.put(self.address(0x49a05c),0x4000)
        self.put(self.address(0x49a060),0xf000)
        self.put(self.address(0x49a054),17)
        self.put(self.address(0x48a034),35)

    def words(self,p,n=1): return struct.unpack('<'+'I'*n,self.cpu.mem_read(p,n*4))
    def put(self,p,v): self.cpu.mem_write(p,struct.pack('<I',v&0xffffffff))
    def text(self,p):
        data=bytearray()
        while (b:=self.cpu.mem_read(p,1)[0]): data.append(b); p+=1
        return data.decode('ascii')
    def alloc(self,n):
        space=(n+31)&~15
        for i,(p,size) in enumerate(self.free_blocks):
            if size>=space:
                self.free_blocks.pop(i)
                if size>space: self.free_blocks.append((p+space,size-space))
                break
        else:
            p=self.next; self.next+=space
            if self.next>self.heap_end: raise AssertionError('fixture exhausted heap')
        self.allocations[p]=space
        self.cpu.mem_write(p,bytes(n)); return p
    def release(self,p):
        size=self.allocations.pop(p,None)
        if size is not None: self.free_blocks.append((p,size))
    def address(self,id):
        for base,p,size in self.regions:
            if base<=id<base+size: return p+id-base
        raise AssertionError(hex(id))
    def stub(self,p,name,pop=0):
        self.stubs[p]=(name,pop)
        if not 0x1001000<=p<0x100b000:
            self.cpu.hook_add(UC_HOOK_CODE,self.hook,begin=p,end=p)
    def method(self,name,pop):
        p=self.stub_next; self.stub_next+=16; self.stub(p,name,pop); return p
    def device(self):
        v=self.alloc(16); self.put(v+12,self.method('CreateBuffer',16))
        p=self.alloc(4); self.put(p,v); return p
    def buffer(self,pcm,cursor=0,status=0,fmt=None):
        fmt=fmt or struct.pack('<HHIIHHH',1,1,22050,44100,2,16,0)
        v=self.alloc(80)
        for slot,name,pop in ((2,'ReleaseBuffer',4),(3,'Caps',8),(4,'Position',12),
            (5,'Format',16),(6,'Volume',8),(7,'Pan',8),(8,'Frequency',8),(9,'Status',8),
            (11,'Lock',32),(12,'Play',16),(13,'SetPosition',8),(15,'SetVolume',8),
            (16,'SetPan',8),(17,'SetFrequency',8),(18,'Stop',4),(19,'Unlock',20)):
            self.put(v+slot*4,self.method(name,pop))
        p=self.alloc(4); self.put(p,v); data=self.alloc(len(pcm)); self.cpu.mem_write(data,pcm)
        self.buffers[p]=dict(data=data,bytes=len(pcm),cursor=cursor,status=status,
                             volume=-500,pan=250,frequency=22050,fmt=fmt)
        return p
    def hook(self,cpu,p,size,unused):
        if p not in self.stubs: return
        name,pop=self.stubs[p]; sp=cpu.reg_read(UC_X86_REG_ESP); a=self.words(sp+4,12); result=1
        if name in ('_malloc','??2@YAPAXI@Z','GlobalAlloc'):
            result=0 if self.fail_alloc or self.fail_after==0 else self.alloc(a[1] if name=='GlobalAlloc' else a[0])
            if self.fail_after is not None and self.fail_after>0: self.fail_after-=1
        elif name in ('_free','??3@YAXPAX@Z','GlobalFree'):
            self.release(a[0]); result=0
        elif name=='checksum': result=(zlib.crc32(bytes(cpu.mem_read(a[0],a[1])),a[2]^0xffffffff)^0xffffffff)&0xffffffff
        elif name=='_sprintf':
            values=iter(a[2:]); fmt=self.text(a[1])
            def sub(m):
                v=next(values); f=m[0]
                if m[2]=='s': v=self.text(v)
                elif m[2]=='d' and v&0x80000000: v-=0x100000000
                return f%v
            text=re.sub(r'%([-+#0-9.]*)([usdxX])',sub,fmt).encode()
            cpu.mem_write(a[0],text+b'\0'); result=len(text)
        elif name=='OutputDebugStringA': self.notices.append(self.text(a[0]))
        elif name.startswith('Interlocked'):
            old=self.words(a[0])[0]
            result=(old+(1 if name=='InterlockedIncrement' else -1))&0xffffffff
            self.put(a[0],a[1] if name=='InterlockedExchange' else result)
            if name=='InterlockedExchange': result=old
        elif name=='GetTickCount': result=self.tick
        elif name=='GetModuleFileNameA': result=0
        elif name=='GetEnvironmentVariableA':
            data=b'C:\\local\0'; cpu.mem_write(a[1],data); result=len(data)-1
        elif name=='CreateFileA':
            path=self.text(a[0])
            if a[4]==2 and not self.fail_create: self.files[path]=b''
            if path not in self.files or (a[4]==2 and self.fail_create): result=0xffffffff
            else: result=self.next_handle; self.next_handle+=1; self.handles[result]=[path,0]
        elif name=='CloseHandle': self.handles.pop(a[0],None)
        elif name=='ReadFile':
            path,offset=self.handles[a[0]]; data=self.files[path][offset:offset+a[2]]
            cpu.mem_write(a[1],data); self.put(a[3],len(data)); self.handles[a[0]][1]+=len(data)
        elif name=='WriteFile':
            result=0 if self.fail_write else 1
            if result:
                path,offset=self.handles[a[0]]; data=bytes(cpu.mem_read(a[1],a[2]))
                self.files[path]=self.files[path][:offset]+data; self.put(a[3],len(data)); self.handles[a[0]][1]+=len(data)
        elif name=='SetFilePointer':
            h=self.handles[a[0]]; h[1]=(h[1] if a[3]==1 else 0)+a[1]; result=h[1]
        elif name=='GetFileSize': result=len(self.files[self.handles[a[0]][0]])
        elif name=='FlushFileBuffers': result=0 if self.fail_flush else 1
        elif name=='MoveFileExA':
            result=0 if self.fail_replace else 1
            if result: self.files[self.text(a[1])]=self.files.pop(self.text(a[0]))
        elif name=='DeleteFileA': self.files.pop(self.text(a[0]),None)
        elif name=='M1_PlayLevel_0040a010': result=0
        elif name=='GFX_Flush_00406c30':
            assert self.words(self.address(0x4a294c))[0]==2
            self.paused_presents+=1
        elif name=='FUN_0040ab60_MainGame_Clean1':
            # A prepared load unwinds temporary-level playback into case 6.
            self.put(self.address(0x455c3c),6)
            self.put(self.address(0x4a2a80),1)
        elif name=='CreateBuffer':
            desc=self.words(a[1],5)
            result=0x8007000e if self.fail_audio else 0
            if not result: self.put(a[2],self.buffer(bytes(desc[2]),fmt=bytes(cpu.mem_read(desc[4],18))))
        elif name in ('Caps','Position','Format','Volume','Pan','Frequency','Status','Lock','Play',
                      'SetPosition','SetVolume','SetPan','SetFrequency','Stop','Unlock','ReleaseBuffer'):
            assert a[0] in self.buffers,(name,hex(a[0]),hex(p),hex(self.stub_next),tuple(hex(x) for x in a[:8]))
            b=self.buffers[a[0]]; result=0
            if name=='Caps': self.put(a[1]+8,b['bytes'])
            elif name=='Position': self.put(a[1],b['cursor']); self.put(a[2],b['cursor'])
            elif name=='Format': cpu.mem_write(a[1],b['fmt']); self.put(a[3],18)
            elif name in ('Volume','Pan','Frequency','Status'): self.put(a[1],b[name.lower()])
            elif name=='Lock':
                self.put(a[3],b['data']); self.put(a[4],b['bytes']); self.put(a[5],0); self.put(a[6],0)
            elif name=='Play': b['status']=1|(4 if a[3]&1 else 0)
            elif name=='Stop': b['status']&=~1
            elif name.startswith('Set'): b[name[3:].lower().replace('position','cursor')]=a[1]
        cpu.reg_write(UC_X86_REG_EAX,result)
        cpu.reg_write(UC_X86_REG_EIP,self.words(sp)[0]); cpu.reg_write(UC_X86_REG_ESP,sp+4+pop)
    def call(self,name,*args):
        p=self.symbols.get('_'+name,self.symbols.get(name))
        sp=0x100f000; self.cpu.mem_write(sp,struct.pack('<'+'I'*(len(args)+1),0x1000000,*(v&0xffffffff for v in args)))
        self.cpu.reg_write(UC_X86_REG_ESP,sp); self.cpu.emu_start(p,0x1000000,count=100000000)
        assert self.cpu.reg_read(UC_X86_REG_EIP)==0x1000000,(name,'did not return')
        return self.cpu.reg_read(UC_X86_REG_EAX)
    def key(self,k,mode=1,repeat=False):
        assert self.call('GEX_StateKey',k,0x40000000 if repeat else 0)==1
        return self.call('GEX_StatePoll',mode)
    def slot(self,n): return f'C:\\local\\GexSource\\states\\slot-{n}.gxs'


def legacy_fixture():
    import json
    f=json.loads((ROOT/'tests/fixtures/save_states/v1.json').read_text())
    parts=[]; refs=[]
    for id,size in f['staticChunks']:
        mask=bytearray(size); data=bytearray(size)
        if id==0x4a0200:
            for field,value in ((0x4a2964,f['level']),(0x4a281c,3)):
                struct.pack_into('<I',data,field-id,value)
            offset=0x4a2ad4-id; mask[offset]=1
            refs.append((id,offset,1,f['graphAllocationID'],0))
        elif id==0x461180: struct.pack_into('<I',data,0,0xabc)
        parts.append(struct.pack('<II',id,size)+mask+data)
    id=f['graphAllocationID']; mask=bytearray(32); mask[0]=mask[8]=1
    data=bytearray(32); struct.pack_into('<I',data,4,f['graphScalar']); struct.pack_into('<I',data,12,0x12345678)
    parts.append(struct.pack('<II',id,32)+mask+data)
    refs.extend(((id,0,1,id,12),(id,8,2,f['callbackID'],0)))
    b=bytearray(struct.pack('<8I',0x32535847,f['wireVersion'],f['worldABI'],f['level'],len(parts),len(refs),0,0))
    b.extend(b''.join(parts)); b.extend(b''.join(struct.pack('<5I',*r) for r in refs))
    b.extend(struct.pack('<14I',*f['audioVariables'])); b.extend(bytes(range(256))*256)
    b.extend(bytes(260+16))
    pcm=bytes.fromhex(f['audioPCMHex']); fmt=bytes.fromhex(f['audioFormatHex'])
    for i in range(10):
        b.extend(struct.pack('<4Iiii',1,len(pcm),f['firstFrameCursor']+i,5 if i%2==0 else 1,
                             f['audioVolume'],f['audioPan'],f['audioFrequency']))
        b.extend(fmt); b.extend(pcm)
    b.extend(struct.pack('<I',zlib.crc32(b)))
    work=ROOT/'.work/save-states-runtime/fixtures'; work.mkdir(parents=True,exist_ok=True)
    (work/'v1.gxs').write_bytes(b)
    return bytes(b),f

def main():
    m=Machine()
    # Check the native CRC independently before enabling the fast fixture stub.
    checksum=m.symbols['?checksum@@YAIPBEII@Z']; mocked=m.stubs.pop(checksum)
    sample=m.alloc(9); m.cpu.mem_write(sample,b'123456789')
    assert m.call('?checksum@@YAIPBEII@Z',sample,9,0xffffffff)==0x340bc6d9
    first=m.call('?checksum@@YAIPBEII@Z',sample,4,0xffffffff)
    assert m.call('?checksum@@YAIPBEII@Z',sample+4,5,first)==0x340bc6d9
    m.stubs[checksum]=mocked
    for slot in range(10):
        m.key(ord('0')+slot)
        m.key(0x74)
        assert m.slot(slot) in m.files, m.notices[-5:]
    simple_fixture=m.files[m.slot(0)]
    m.key(ord('0')); assert m.call('GEX_StateMutationBegin')==1
    m.key(0x74); assert m.files[m.slot(0)]==simple_fixture
    m.call('GEX_StateMutationEnd'); m.call('GEX_StatePoll',1)
    assert 'SAVED' in m.notices[-2],m.notices[-4:]
    for slot in range(10):
        restarted=Machine(m.files)
        restarted.key(ord('0')+slot)
        assert restarted.key(0x78)==1,restarted.notices[-4:]
        restarted.call('GEX_StateDispatch')
        assert restarted.words(restarted.address(0x4a281c))[0]==3
    # Exercise the real script interpreter, object/collision/intro references,
    # mutable bytecode, health, pickups, camera, timer and both gameplay RNGs.
    objects=m.alloc(100*0x204); m.call('GEX_StateAllocated',objects,100*0x204)
    script=m.alloc(64); m.call('GEX_StateAllocated',script,64)
    program=bytes([0x8a,59,0,0x97,12,0x9b,1,0,0,0,0xa7,12,0x82,1,0x85,0xf1,0xff])
    m.cpu.mem_write(script,program); m.cpu.mem_write(script+60,b'\x8b')
    m.put(m.address(0x4a27a0),objects)
    head=m.address(0x4a28a0); m.put(head,objects); m.put(head+8,objects)
    m.put(objects,head+4); m.put(objects+4,head)
    m.put(objects+0x10,script)
    m.put(objects+0x98,7)
    m.put(objects+0x50,0); m.put(objects+0x54,1)
    m.put(objects+0xf4,0); m.put(objects+0xf8,0)
    # A real GXLoadObject animation table within the tracked mutable resource.
    m.put(objects+0xc,script+20); m.put(script+20,script+36)
    m.put(script+36,script+40); m.put(script+40,script+48); m.put(script+44,script+52)
    m.put(script+48,0x1111); m.put(script+52,0x2222)
    for offset in (20,36,40,44): m.call('GEX_StatePointer',script+offset)
    assert m.call('GOB_GetCurrentFrameWithDefault_0041a380',objects)==script+52
    m.put(objects+0xa0,m.graph)
    m.call('GEX_StateCopyKind',objects+0xa0,m.address(0x4a2ad4))
    collisions=m.alloc(1200); m.call('GEX_StateAllocated',collisions,1200)
    m.put(collisions,m.address(0x463680)+4); m.put(collisions+4,m.address(0x463680)); m.put(collisions+8,objects)
    m.put(m.address(0x463680),collisions); m.put(m.address(0x463688),collisions)
    intro=m.alloc(60); m.call('GEX_StateAllocated',intro,60)
    table=m.alloc(4); m.call('GEX_StateAllocated',table,4); m.put(table,intro)
    m.put(intro,script); m.put(intro+4,m.symbols['_GOB_DoIt_0040ef40'])
    m.put(m.address(0x4a2a78),table); m.put(m.address(0x4626fc),1)
    m.key(ord('0')); m.key(0x74)
    def replay(machine):
        obj=machine.words(machine.address(0x4a27a0))[0]
        script=machine.words(obj+0x10)[0]
        for delta in (1,4,2,7):
            machine.put(script+6,delta)
            machine.put(obj+0x54,(machine.words(obj+0x54)[0]+delta)%2)
            frame=machine.call('GOB_GetCurrentFrameWithDefault_0041a380',obj)
            machine.put(frame,machine.words(frame)[0]+delta)
            machine.put(obj+0x14,0)
            # Resolve a saved PC back to the current bytecode allocation.
            pc=machine.words(obj+0x10)[0]
            pc=machine.call('GOB_RunScript_00435d90',obj,obj+0x10,pc)
            machine.put(obj+0x10,pc)
            machine.put(machine.address(0x4a2ac8),machine.words(machine.address(0x4a2ac8))[0]+1)
            machine.put(machine.address(0x4a2a38),machine.words(machine.address(0x4a2a38))[0]+delta*65536)
            machine.put(machine.address(0x4a2808),machine.words(machine.address(0x4a2808))[0]+1)
            machine.call('GEX_StateRand')
            machine.call('UTL_ReallyRandom32_00428c60')
            machine.call('UTL_ReallyRandom_00428c80',17)
        machine.key(ord('8')); machine.key(0x74)
        assert 'SAVED' in machine.notices[-2],machine.notices[-4:]
        return machine.files[machine.slot(8)]
    expected=replay(m)
    m.key(ord('0')); assert m.key(0x78)==1,m.notices[-4:]
    m.call('GEX_StateDispatch')
    restored_object=m.words(m.address(0x4a27a0))[0]
    assert m.words(restored_object+0xa0)[0]==m.words(m.address(0x4a2ad4))[0]!=m.graph
    frame=m.call('GOB_GetCurrentFrameWithDefault_0041a380',restored_object)
    old_frame=m.call('GOB_GetOldFrame_0041a400',restored_object)
    assert m.words(frame)[0]==0x2222 and m.words(old_frame)[0]==0x1111
    assert replay(m)==expected,'identical inputs changed normalized portable state'
    # Restore the simpler compatibility snapshot for the remaining failure tests.
    m.files[m.slot(0)]=simple_fixture
    m=Machine(m.files)
    fixture=m.files[m.slot(0)]
    m.key(ord('0')); m.key(0x74,repeat=True)
    assert m.files[m.slot(0)]==fixture
    m.fail_write=True; m.key(0x74); m.fail_write=False
    assert m.files[m.slot(0)]==fixture and 'PREVIOUS FILE KEPT' in m.notices[-2]
    m.fail_alloc=True; m.key(0x74); m.fail_alloc=False
    assert m.files[m.slot(0)]==fixture and 'NOT ENOUGH MEMORY' in m.notices[-2]
    for failure in ('fail_create','fail_flush','fail_replace'):
        setattr(m,failure,True); m.key(0x74); setattr(m,failure,False)
        assert m.files[m.slot(0)]==fixture and 'PREVIOUS FILE KEPT' in m.notices[-2]
    m.key(0x74,mode=0); assert 'UNAVAILABLE' in m.notices[-2]
    m.put(m.address(0x462714),1); m.key(0x78)
    assert not m.call('GEX_StatePending')
    m.put(m.address(0x462714),0); assert m.call('GEX_StatePoll',1)==1
    m.call('GEX_StateDispatch')
    # Restart with a different allocation address and a different current level.
    n=Machine(m.files,heap=0xb000000)
    n.put(n.address(0x4a2964),20)
    n.put(n.address(0x4a281c),1)
    n.put(n.address(0x487ff8),1)
    assert n.key(0x78,mode=0)==1, n.notices[-4:]
    n.call('GEX_StateDispatch')
    root=n.words(n.address(0x4a2ad4))[0]
    assert n.words(root,4)==(root+12,m.graph+12,n.symbols['_GOB_DoIt_0040ef40'],0x12345678)
    assert n.words(n.address(0x4a2964))[0]==3
    assert n.words(n.address(0x487ff8))[0]==0
    assert n.words(n.address(0x4a281c))[0]==3
    assert n.words(n.address(0x461180))[0]==0xabc
    audio=n.buffers[n.words(n.address(0x48a040))[0]]
    assert (audio['cursor'],audio['status'],audio['volume'],audio['pan'],audio['frequency'])==(20,5,(-500)&0xffffffff,250,22050)
    assert bytes(n.cpu.mem_read(audio['data'],64))==bytes(range(64))
    for i,slot in enumerate([0x48a040,0x49a068]+list(range(0x49fb30,0x49fb50,4))):
        b=n.buffers[n.words(n.address(slot))[0]]
        assert b['cursor']==20+i*2 and b['status']==(5 if i%2==0 else 1)
    assert bytes(n.cpu.mem_read(n.address(0x48a050),65536))==bytes(range(256))*256
    assert tuple(n.words(n.address(a))[0] for a in (0x49a058,0x49a05c,0x49a060))==(0xe000,0x4000,0xf000)
    assert n.words(n.address(0x49a054))[0]==17 and n.words(n.address(0x48a034))[0]==35
    # Retained v1 wire fixture: the same stable world IDs, PCM frame cursors.
    migration=bytearray(fixture[:32]+fixture[36:])
    count,nrefs,nassets,nfiles=struct.unpack_from('<IIII',migration,16)
    off=32
    for _ in range(count):
        _,size=struct.unpack_from('<II',migration,off); off+=8+2*size
    off+=nrefs*20+nassets*268+nfiles*264
    off+=14*4+65536+260+16
    for _ in range(10):
        present=struct.unpack_from('<I',migration,off)[0]; off+=4
        if present:
            size,cursor=struct.unpack_from('<II',migration,off)
            struct.pack_into('<I',migration,off+4,cursor//2)
            off+=24+18+size
    migration=migration[:off]+bytes(4)
    struct.pack_into('<I',migration,4,1)
    struct.pack_into('<I',migration,len(migration)-4,zlib.crc32(migration[:-4]))
    n.files[n.slot(0)]=bytes(migration)
    assert n.key(0x78)==1,n.notices[-3:]
    n.call('GEX_StateDispatch')
    root=n.words(n.address(0x4a2ad4))[0]
    assert n.buffers[n.words(n.address(0x48a040))[0]]['cursor']==20
    # A second link with a different preferred image address must load the v1
    # fixture and reconstruct callbacks at the new build's addresses.
    import subprocess
    build=ROOT/'.work/replacement-short'
    response=(build/'link-game-lld.rsp').read_text()
    second=build/'save-state-compatible.exe'; second_map=build/'save-state-compatible.map'
    response=re.sub(r'/out:[^\n]+','/out:"'+str(second)+'"',response)
    response=re.sub(r'/map:[^\n]+','/map:"'+str(second_map)+'"',response)
    rsp=build/'save-state-compatible.rsp'; rsp.write_text(response+'\n/base:0x800000\n')
    subprocess.run(['lld-link','@'+str(rsp)],check=True,cwd=build)
    legacy,old=legacy_fixture()
    q=Machine({n.slot(0):legacy},heap=0x14000000,executable=second,symbol_map=second_map)
    assert q.key(0x78)==1,q.notices[-4:]
    q.call('GEX_StateDispatch')
    qr=q.words(q.address(0x4a2ad4))[0]
    assert q.words(qr+8)[0]==q.symbols['_GOB_DoIt_0040ef40']!=m.symbols['_GOB_DoIt_0040ef40']
    assert q.call('GEX_StateFunctionValid',q.words(qr+8)[0])==1
    assert q.words(qr+4)[0]==old['graphScalar']
    assert q.buffers[q.words(q.address(0x48a040))[0]]['cursor']==20
    for bad in (fixture[:-1],fixture[:100],fixture[:80]+b'bad'+fixture[83:]):
        n.files[n.slot(0)]=bad; n.key(0x78)
        assert not n.call('GEX_StatePending')
        assert n.words(n.address(0x4a2ad4))[0]==root
    n.files[n.slot(0)]=fixture
    for asset in ('VFX\\GEX017.VFX','SFX\\GEX.SFX','MUS\\GEX035.MUS'):
        original=n.files.pop(asset); n.key(0x78)
        assert not n.call('GEX_StatePending') and n.words(n.address(0x4a2ad4))[0]==root
        assert any('AUDIO ASSETS DIFFER' in text for text in n.notices[-4:])
        n.files[asset]=original
    n.fail_alloc=True; n.key(0x78); n.fail_alloc=False
    assert not n.call('GEX_StatePending') and n.words(n.address(0x4a2ad4))[0]==root
    for allocations in (5,12):
        n.fail_after=allocations; n.key(0x78); n.fail_after=None
        assert not n.call('GEX_StatePending') and n.words(n.address(0x4a2ad4))[0]==root
    n.fail_audio=True; n.key(0x78); n.fail_audio=False
    assert not n.call('GEX_StatePending') and n.words(n.address(0x4a2ad4))[0]==root
    assert n.buffers[n.words(n.address(0x48a040))[0]]['status']==5
    # A valid checksum does not excuse unsupported schemas or invalid table counts.
    for offset,value in ((4,99),(8,99),(28,99),(20,0)):
        bad=bytearray(fixture); struct.pack_into('<I',bad,offset,value)
        struct.pack_into('<I',bad,len(bad)-4,zlib.crc32(bad[:-4]))
        n.files[n.slot(0)]=bytes(bad); n.key(0x78)
        assert not n.call('GEX_StatePending') and n.words(n.address(0x4a2ad4))[0]==root
    # Asset provenance is explicit: this pointer targets a named file segment,
    # with its file offset and allocation owner recorded in the reference table.
    asset_name='LEV\\synthetic.lev'; asset=bytes(range(64))
    q.files[asset_name]=asset
    name=q.alloc(len(asset_name)+1); q.cpu.mem_write(name,asset_name.encode()+b'\0')
    handle=0x700; q.handles[handle]=[asset_name,64]
    q.call('GEX_StateFileOpened',handle,name)
    resource=q.alloc(64); q.call('GEX_StateAllocated',resource,64); q.cpu.mem_write(resource,asset)
    q.call('GEX_StateResourceRead',handle,resource,64)
    # CDIO also reads small resource headers into static gameplay storage.
    static_resource=q.address(0x4626e4)
    q.cpu.mem_write(static_resource,asset[:4]); q.handles[handle][1]=4
    q.call('GEX_StateResourceRead',handle,static_resource,4)
    q.put(qr+16,static_resource); q.call('GEX_StatePointer',qr+16)
    q.put(qr,resource+12)
    q.call('GEX_StateFileClosed',handle); q.handles.pop(handle)
    q.key(0x74)
    assert 'SAVED' in q.notices[-2],q.notices[-4:]
    resource_fixture=q.files[q.slot(0)]
    assert struct.unpack_from('<I',resource_fixture,32)[0]==2
    before=q.words(q.address(0x4a2ad4))[0]
    q.files[asset_name]=asset[:-1]+b'x'
    q.key(0x78)
    assert not q.call('GEX_StatePending') and q.words(q.address(0x4a2ad4))[0]==before
    assert any('ASSETS DIFFER' in text for text in q.notices[-4:])
    q.files.pop(asset_name); q.key(0x78)
    assert not q.call('GEX_StatePending') and q.words(q.address(0x4a2ad4))[0]==before
    q.files[asset_name]=asset
    assert q.key(0x78)==1,q.notices[-4:]
    q.call('GEX_StateDispatch')
    restored=q.words(q.words(q.address(0x4a2ad4))[0])[0]
    assert bytes(q.cpu.mem_read(restored-12,64))==asset and restored!=resource+12
    assert q.words(q.words(q.address(0x4a2ad4))[0]+16)[0]==static_resource
    music_name='MUS\\synthetic.mus'; music=bytes(range(128))
    q.files[music_name]=music
    name=q.alloc(len(music_name)+1); q.cpu.mem_write(name,music_name.encode()+b'\0')
    q.call('GEX_StateMusicOpened',name)
    handle=0x701; q.handles[handle]=[music_name,112]; q.put(q.address(0x48a04c),handle)
    q.key(0x74)
    assert 'SAVED' in q.notices[-2],q.notices[-4:]
    assert q.key(0x78)==1,q.notices[-4:]
    q.call('GEX_StateDispatch')
    handle=q.words(q.address(0x48a04c))[0]
    assert q.handles[handle]==[music_name,112]
    before=q.words(q.address(0x4a2ad4))[0]
    q.files.pop(music_name); q.key(0x78)
    assert not q.call('GEX_StatePending') and q.words(q.address(0x4a2ad4))[0]==before
    assert any('MUSIC ASSET DIFFERS' in text for text in q.notices[-4:])
    q.files[music_name]=music
    # Restore logical sequence position without restoring a native thread stack.
    q.put(q.address(0x455c3c),4); q.call('GEX_StateSequence',7)
    q.key(0x74); q.call('GEX_StateSequence',12)
    assert q.key(0x78)==1,q.notices[-4:]
    q.call('GEX_StateDispatch')
    position=q.alloc(4)
    assert q.call('GEX_StateSequenceResume',position)==1 and q.words(position)[0]==7
    q.put(q.address(0x455c3c),1)
    q.call('GEX_SpriteViewerKey',0x77,0); q.call('GEX_SpriteViewerMenu')
    assert q.call('GEX_SpriteViewerActive')
    q.key(0x74); assert 'UNAVAILABLE' in q.notices[-2]
    assert q.key(0x78)==1,q.notices[-4:]
    q.call('GEX_StateDispatch')
    assert not q.call('GEX_SpriteViewerActive')
    q.key(ord('7')); q.put(q.address(0x487f88),0); q.put(q.address(0x4a294c),2)
    q.key(0x74); q.put(q.address(0x487f88),1); q.put(q.address(0x4a294c),0)
    assert q.key(0x78)==1,q.notices[-4:]
    q.call('GEX_StateDispatch')
    assert q.words(q.address(0x487f88))[0]==0 and q.words(q.address(0x4a294c))[0]==2
    assert q.words(q.address(0x48a03c))[0]==1
    assert q.paused_presents==1
    q.put(q.address(0x487f88),1); q.put(q.address(0x4a294c),0)
    q.put(q.address(0x455c3c),5); q.put(q.address(0x4a2964),0x44)
    q.call('GEX_StateReturnLevel',27); q.key(0x74)
    assert q.key(0x78)==1,q.notices[-4:]
    q.stub(q.symbols['_FUN_0040ab60_MainGame_Clean1'],'FUN_0040ab60_MainGame_Clean1')
    q.stub(q.symbols['_FUN_004099b0_CloseMusic'],'FUN_004099b0_CloseMusic')
    q.put(q.address(0x455c3c),5); q.put(q.address(0x4a2964),27)
    q.call('GEX_RunGameLoop_0040af60')
    assert q.words(q.address(0x455c3c))[0]==6 and q.words(q.address(0x4a2964))[0]==0x44
    q.put(q.address(0x4a2a80),0)
    q.call('GEX_StateDispatch')
    assert q.words(q.address(0x4a2964))[0]==27 and q.words(q.address(0x455c3c))[0]==1
    q.key(0x74,mode=-1)
    assert 'UNAVAILABLE DURING VIDEO' in q.notices[-2]
    q.key(0x74,repeat=True,mode=-1)
    print('Save states: ten slots, repeats, atomic failure, menu loading, deferral, restart relocation, explicit scalar preservation, deterministic script/world replay, PCM/settings/ring wraparound, changed-link migration fixture, asset identities, corrupt files and staging failures passed')


if __name__=='__main__': main()
