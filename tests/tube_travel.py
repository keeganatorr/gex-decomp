#!/usr/bin/env python3
"""Compare linked tube movement and entry with pinned x86 instructions.

Animation/audio, reset and block-attribute lookup are boundary stubs in both
images. Object fields, probes, directions and camera locks are compared; this
behavior test publishes no matching proof. Requires pefile/unicorn and a build.
"""
import hashlib
import itertools
import struct

from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP
from rez_camera import machine
from rotated_sprite_commands import addr, build
from sprite_rotation import PIN, ROOT


class Tube:
    def __init__(self, new):
        self.new = new
        self.cpu = machine(build/'gex-source.exe' if new else ROOT/'.work/original.exe')
        self.calls = []
        self.hooks = {addr(a, new): (a, n) for a,n in
                      ((0x40f170,3),(0x41a250,4),(0x41a340,2),(0x41fa80,1),(0x420bc0,1))}
        self.cpu.hook_add(UC_HOOK_CODE, self.hook)

    def word(self, address):
        return struct.unpack('<I', self.cpu.mem_read(address,4))[0]

    def put(self, address, value):
        self.cpu.mem_write(address,struct.pack('<I',value & 0xffffffff))

    def hook(self, cpu, pc, size, user):
        if pc not in self.hooks:
            return
        a,n = self.hooks[pc]
        sp = cpu.reg_read(UC_X86_REG_ESP)
        args = tuple(self.word(sp+4+i*4) for i in range(n))
        self.calls.append((a,args))
        result = 0
        if a==0x40f170:
            result = self.tile if self.probes==0 else self.neighbour
            self.probes += 1
        cpu.reg_write(UC_X86_REG_EAX,result)
        cpu.reg_write(UC_X86_REG_EIP,self.word(sp))
        cpu.reg_write(UC_X86_REG_ESP,sp+4)

    def run(self, direction, tile, buttons=0, phase=(16,16), neighbour=0x58,
            timer=8, initial=False, entry=False, ticks=1):
        obj,stack,stop = 0x1003000,0x1002000,0x1000000
        self.cpu.mem_write(obj,bytes((i*17+3)&255 for i in range(0x204)))
        fields={0x54:7,0x78:0x1f200000+(phase[0]<<16),0x7c:0x2300000+(phase[1]<<16),
                0x98:0 if initial else 1,0x9c:direction}
        for off,v in fields.items(): self.put(obj+off,v)
        for i in range(4): self.cpu.mem_write(addr(0x4a0280+i,self.new),bytes([(buttons>>i)&1]))
        self.put(addr(0x4a2990,self.new),0x1008000)
        self.put(addr(0x4a283c,self.new),direction)
        self.calls=[];self.tile=tile;self.neighbour=neighbour;self.probes=0
        output=[]
        for tick in range(ticks):
            self.put(addr(0x4a2ac8,self.new),timer+tick)
            self.cpu.mem_write(stack,struct.pack('<II',stop,obj))
            self.cpu.reg_write(UC_X86_REG_ESP,stack)
            self.cpu.emu_start(addr(0x415b20 if entry and tick==0 else 0x415820,self.new),stop,count=20000)
            assert self.cpu.reg_read(UC_X86_REG_EIP)==stop,'tube routine did not return'
            output.append((bytes(self.cpu.mem_read(obj,0x204)),
                           bytes(self.cpu.mem_read(addr(0x455bb4,self.new),32))))
        return output,self.calls


def main():
    assert hashlib.sha256((ROOT/'.work/original.exe').read_bytes()).hexdigest()==PIN
    original,candidate = Tube(False),Tube(True)
    count=0
    def check(*args,**kwargs):
        nonlocal count
        expected=original.run(*args,**kwargs)
        actual=candidate.run(*args,**kwargs)
        assert actual==expected,(args,kwargs)
        count+=1
    # All attributes, four directions, sound/animation phases and unmapped X.
    for direction,tile in itertools.product(range(4),range(256)):
        check(direction,tile,timer=8+(tile&7))
    for direction,initial,entry in itertools.product(range(4),(False,True),(False,True)):
        check(direction,0x60,initial=initial,entry=entry,ticks=8)
    # Input priority, forbidden reversals, adjacent probes, inclusive turn bounds.
    phases=((0,16),(11,16),(12,12),(16,16),(20,20),(21,16),(16,11),(16,21),(31,31))
    for direction,tile,buttons,phase in itertools.product(range(4),range(0x5c,0x60),range(16),phases):
        check(direction,tile,buttons,phase,neighbour=0x58+(buttons%4))
        check(direction,tile,buttons,phase,neighbour=0x60)
    print(f'{count} tube-travel cases agree with pinned original: entry, unmapped coordinates, all attributes, junctions, movement/scales, exits and call/probe arguments')


if __name__=='__main__':
    main()
