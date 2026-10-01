#!/usr/bin/env python3
"""Exercise linked zoom controls, camera restoration, pixels and fixed-size HUD.

Requires pefile/unicorn and a replacement build. Uses the real box, textured
rectangle and quad renderers; viewport width and texture palette lookup are
boundary stubs. No backend proof is published.
"""
import struct
from pathlib import Path
from functools import lru_cache
import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP

ROOT=Path(__file__).resolve().parents[1]
BUILD=ROOT/'.work/replacement-short'
SYMBOLS={}
for line in (BUILD/'gex-source.map').read_text(errors='replace').splitlines():
    p=line.split()
    if len(p)>2:
        try: SYMBOLS[p[1]]=int(p[2],16)
        except ValueError: pass

@lru_cache(maxsize=1)
def image():
    pe=pefile.PE(str(BUILD/'gex-source.exe'),fast_load=True)
    return pe.OPTIONAL_HEADER.ImageBase,(pe.OPTIONAL_HEADER.SizeOfImage+4095)&~4095,pe.get_memory_mapped_image()

class Game:
    def __init__(self,width):
        base,size,data=image()
        self.cpu=Uc(UC_ARCH_X86,UC_MODE_32)
        self.cpu.mem_map(base,size);self.cpu.mem_write(base,data)
        self.cpu.mem_map(0x1000000,0x200000)
        self.cpu.hook_add(UC_HOOK_CODE,self.hook)
        self.width=width
        self.palette=0
        self.put('004a2964',3);self.put('004a2a7c',0)
    def hook(self,m,pc,size,user):
        if pc==SYMBOLS['_GEX_WidescreenWidth'] or (self.palette and pc==SYMBOLS['_FUN_00402400_InnerGraphicsTilesMostInner']):
            sp=m.reg_read(UC_X86_REG_ESP)
            m.reg_write(UC_X86_REG_EAX,self.width if pc==SYMBOLS['_GEX_WidescreenWidth'] else self.palette)
            m.reg_write(UC_X86_REG_ESP,sp+4)
            m.reg_write(UC_X86_REG_EIP,self.word(sp))
    def put(self,a,value):
        if isinstance(a,str): a=SYMBOLS['_GEX_DATA_'+a]
        self.cpu.mem_write(a,struct.pack('<I',value&0xffffffff))
    def word(self,a):return struct.unpack('<I',self.cpu.mem_read(a,4))[0]
    def call(self,name,*args):
        sp=0x1001000;stop=0x1000000
        self.cpu.mem_write(sp,struct.pack('<'+'I'*(len(args)+1),stop,*(a&0xffffffff for a in args)))
        self.cpu.reg_write(UC_X86_REG_ESP,sp)
        self.cpu.emu_start(SYMBOLS['_'+name],stop,count=80000000)
        assert self.cpu.reg_read(UC_X86_REG_EIP)==stop,(name,'did not return')
        return self.cpu.reg_read(UC_X86_REG_EAX)
    def scale(self,value):
        key=0x6b if value>65536 else 0x6d
        for _ in range(abs(value-65536)//8192):self.call('GEX_ZoomKey',key,0)
        for _ in range(50):self.call('GEX_ZoomBeginFrame')
        assert self.call('GEX_ZoomFactor')==value

def controls():
    g=Game(320)
    assert g.call('GEX_ZoomKey',0x6b,0)==1
    assert g.call('GEX_ZoomRequested')==73728
    for _ in range(4):assert g.call('GEX_ZoomKey',0x6b,0x40000000)==1
    assert g.call('GEX_ZoomRequested')==73728
    for _ in range(20):g.call('GEX_ZoomKey',0x6b,0)
    assert g.call('GEX_ZoomRequested')==131072
    for _ in range(30):g.call('GEX_ZoomKey',0x6d,0)
    assert g.call('GEX_ZoomRequested')==32768
    g.call('GEX_ZoomKey',0x60,0)
    assert g.call('GEX_ZoomRequested')==65536
    assert g.call('GEX_ZoomKey',0x41,0)==0
    for level in range(63):
        g.put('004a2964',level)
        assert g.call('GEX_ZoomKey',0x6b,0)==1
        assert g.call('GEX_ZoomRequested')==73728
        g.call('GEX_ZoomKey',0x60,0)
    for level,in_map in ((63,0),(3,1)):
        g.put('004a2964',level);g.put('004a2a7c',in_map)
        assert g.call('GEX_ZoomKey',0x6b,0)==0
        assert g.call('GEX_ZoomRequested')==65536

def pixels(width,factor):
    g=Game(width);g.scale(factor)
    frame=0x1080000;head=0x1003000;map_ptr=0x1004000
    guard=struct.pack('<H',0x1234)*(1024*512)
    g.cpu.mem_write(frame,guard);g.put('004a33ac',frame)
    cameras=('004a2a38','004a2a1c','004a2974','004a2988','004a293c','004a2978')
    for i,a in enumerate(cameras):g.put(a,(400 if i%2==0 else 300)<<16)
    pool=('004a2adc','004a2ae0','004a2ae4')
    for a,value in zip(pool,(0x100e000,0x100d000,0x100d010)):g.put(a,value)
    g.cpu.mem_write(map_ptr,struct.pack('<III',0,2000<<16,1400<<16))
    g.put(head,0xffffff);g.put('004a2b18',head);g.put('004a2b14',head)
    g.call('GEX_ZoomBeginDraw',map_ptr)
    vw=g.call('GEX_ZoomViewWidth');vh=g.call('GEX_ZoomViewHeight')
    if factor!=65536:
        assert g.word(SYMBOLS['_GEX_DATA_004a2adc'])-g.word(SYMBOLS['_GEX_DATA_004a2ae0'])==1048576
    nodes=[]
    def box(x,y,w,h,colour):
        p=0x1005000+len(nodes)*40
        data=struct.pack('<IIhhhh',0xffffff,0x60000000|colour,x,y,w,h)
        g.cpu.mem_write(p,data)
        prev=nodes[-1] if nodes else head
        g.put(prev,p);nodes.append(p);g.put('004a2b18',p);g.put('004a2b14',p)
    for y in range(0,vh,32):
        for x in range(0,vw,32):
            r=(x//32*3+1)%32;green=(y//32*5+1)%32;b=(x//32+y//32+1)%32
            colour=(b<<19)|(green<<11)|(r<<3)
            box(x,y,32,32,colour)
    g.call('GEX_ZoomUIBegin')
    for i,a in enumerate(cameras):assert g.word(SYMBOLS['_GEX_DATA_'+a])==(400 if i%2==0 else 300)<<16
    box(20,24,30,12,0xf8f8f8)
    g.call('GEX_ZoomUIEnd');g.call('GEX_ZoomEndDraw')
    for i,a in enumerate(cameras):assert g.word(SYMBOLS['_GEX_DATA_'+a])==(400 if i%2==0 else 300)<<16
    for a,value in zip(pool,(0x100e000,0x100d000,0x100d010)):
        assert g.word(SYMBOLS['_GEX_DATA_'+a])==value,'command pool root not restored'
    before=[bytes(g.cpu.mem_read(p,16)) for p in nodes]
    g.call('FUN_00445140_InnerGraphics',head)
    assert [bytes(g.cpu.mem_read(p,16)) for p in nodes]==before,'commands mutated'
    raw=bytes(g.cpu.mem_read(frame,len(guard)))
    for y in range(512):
        for x in range(1024):
            expected=0x1234
            if 8<=y<232 and x<width:
                sx=x*65536//factor;sy=y*65536//factor
                r=(sx//32*3+1)%32;green=(sy//32*5+1)%32;b=(sx//32+sy//32+1)%32
                expected=r|(green<<5)|(b<<10)
                if 20<=x<50 and 24<=y<36:expected=0x7fff
            actual=struct.unpack_from('<H',raw,(y*1024+x)*2)[0]
            assert actual==expected,(width,factor,x,y,hex(actual),hex(expected))
    # A viewer/pause early return on the next tick must not reuse this scene.
    g.call('GEX_ZoomBeginFrame')
    assert g.call('GEX_ZoomRender',head)==0
    assert g.call('GEX_ZoomViewWidth')==width
    assert g.call('GEX_ZoomViewHeight')==240

def anchor():
    count=0
    for width in (320,424,560,672):
        for factor in (32768,49152,98304,131072):
            for level in (3,27):
                g=Game(width);g.put('004a2964',level);g.scale(factor)
                player,map_ptr,head=0x1003000,0x1004000,0x1005000
                g.put('004a27fc',player);g.put(player+0x78,1065<<16);g.put(player+0x7c,1180<<16)
                for a in ('004a2a38','004a2a1c','004a2974','004a2988','004a293c','004a2978'):g.put(a,1000<<16)
                g.cpu.mem_write(map_ptr,struct.pack('<III',0,4000<<16,4000<<16))
                g.put(head,0xffffff);g.put('004a2b18',head);g.put('004a2b14',head)
                cull=(g.call('GEX_ZoomCullX'),g.call('GEX_ZoomCullY'))
                g.call('GEX_ZoomBeginDraw',map_ptr)
                for axis,(physical,position,a) in enumerate(((width,65,'004a2974'),(240,180,'004a2988'))):
                    virtual=(physical*65536+factor-1)//factor
                    pivot=physical//2 if level==27 else position
                    expected=(1000<<16)+(pivot*65536//physical)*(physical-virtual)
                    actual=g.word(SYMBOLS['_GEX_DATA_'+a])
                    assert actual==expected,('anchor',width,factor,level,axis,actual,expected)
                    if factor<65536:
                        assert cull[axis]==expected
                    elif level!=27:
                        screen=((1000+position)*65536-actual)*factor//65536
                        assert abs(screen-(position<<16))<=factor+physical*65536//factor,'player pivot moved'
                g.call('GEX_ZoomEndDraw')
                assert g.word(player+0x78)==1065<<16 and g.word(player+0x7c)==1180<<16
                count+=1
    return count

def texture_frame(factor, quad, sprite_x, sprite_y):
    g=Game(320);g.scale(factor)
    frame,head,map_ptr=0x1080000,0x1003000,0x1004000
    g.palette=0x1070000
    g.cpu.mem_write(g.palette,struct.pack('<16H',0,*(i*211 for i in range(1,16))))
    g.put('004a33ac',frame)
    for y in range(32):
        row=bytes((((x//4+y//4)%15+1)|(((x+1)//4+y//4)%15+1)<<4) for x in range(0,32,2))
        g.cpu.mem_write(frame+1536+y*2048,row)
    for a in ('004a2a38','004a2a1c','004a2974','004a2988','004a293c','004a2978'):g.put(a,400<<16)
    g.cpu.mem_write(map_ptr,struct.pack('<III',0,2000<<16,1400<<16))
    g.put(head,0xffffff);g.put('004a2b18',head);g.put('004a2b14',head)
    g.call('GEX_ZoomBeginDraw',map_ptr)
    tpage,sprite=0x1005000,0x1005040
    g.cpu.mem_write(tpage,struct.pack('<II',sprite,0xe100000c))
    command=bytearray(40)
    struct.pack_into('<II',command,0,0xffffff,0x2c808080 if quad else 0x64808080)
    if quad:
        for i,(x,y,u,v) in enumerate(((sprite_x,sprite_y,0,0),(sprite_x+32,sprite_y,32,0),
                                      (sprite_x,sprite_y+32,0,32),(sprite_x+32,sprite_y+32,32,32))):
            struct.pack_into('<hhBBH',command,8+i*8,x,y,u,v,12 if i==1 else 0)
    else:
        struct.pack_into('<hhBBHhh',command,8,sprite_x,sprite_y,0,0,0,32,32)
    g.cpu.mem_write(sprite,bytes(command));g.put(head,tpage)
    g.put('004a2b18',sprite);g.put('004a2b14',sprite)
    g.call('GEX_ZoomEndDraw');g.call('FUN_00445140_InnerGraphics',head)
    assert bytes(g.cpu.mem_read(sprite,40))==bytes(command)
    return bytes(g.cpu.mem_read(frame,2048*240))


def textures():
    count=0
    for quad in (False,True):
        baseline=texture_frame(65536,quad,32,32)
        for factor in (32768,49152,98304,131072):
            # The zoom-out cases cross both the horizontal and vertical tile seams.
            sx,sy=(312,216) if factor<65536 else (80,80)
            actual=texture_frame(factor,quad,sx,sy)
            for y in range(8,232):
                vy=y*65536//factor-sy+32
                for x in range(320):
                    vx=x*65536//factor-sx+32
                    expected=struct.unpack_from('<H',baseline,vy*2048+vx*2)[0] if 0<=vx<96 and 8<=vy<96 else 0
                    value=struct.unpack_from('<H',actual,y*2048+x*2)[0]
                    assert value==expected,('texture',quad,factor,x,y,value,expected)
            count+=1
    return count

def main():
    controls()
    anchor_count=anchor()
    count=0
    for width in (320,424,560,672):
        for factor in (32768,49152,65536,98304,131072):
            pixels(width,factor);count+=1
    texture_count=textures()
    print(f'Manual zoom: controls, {anchor_count} player/Rez camera pivots, camera/command/pool preservation, fixed HUD and all framebuffer pixels pass in {count} width/scale cases; {texture_count} textured rectangle/quad cases pass across tile seams')

if __name__=='__main__':main()
