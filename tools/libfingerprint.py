"""Fingerprint the exe's CRT region against static C libraries.

    tools/libfingerprint.py NAME=DIR [NAME=DIR ...] [--start 0x449000]

Each DIR holds libc.lib/libcmt.lib. Every 16-byte window of a library's code
sections that contains no relocation byte is collected; the exe's .text from
--start to its end is scanned for those windows. Reports hits per library and
windows unique to each (the Yodecomp compiler-hunt method: a library build is
identified by windows only it contains). 2026-09-29: NTSource c1032 7647/26096,
c932 1581; 6136 unique to c1032, 70 to c932.
"""
import os, struct, sys
W=16
def ar_members(path):
    d=open(path,'rb').read(); assert d[:8]==b'!<arch>\n'
    i=8
    while i+60<=len(d):
        h=d[i:i+60]; size=int(h[48:58].decode().strip()); name=h[:16].decode(errors='replace').strip()
        body=d[i+60:i+60+size]
        if not name.startswith('/') or name[1:2] not in ('','/',' ') and not name.startswith('//'):
            pass
        yield name, body
        i+=60+size+(size&1)
def coff_windows(body, out):
    if len(body)<20: return
    mach,nsec=struct.unpack_from('<HH',body,0)
    if mach!=0x14c: return
    optsz=struct.unpack_from('<H',body,16)[0]
    for s in range(nsec):
        o=20+optsz+s*40
        if o+40>len(body): return
        size,ptr,prel,_,nrel=struct.unpack_from('<IIIIH',body,o+16)
        ch=struct.unpack_from('<I',body,o+36)[0]
        if not ch&0x20 or ptr==0 or size==0: continue
        data=body[ptr:ptr+size]; bad=bytearray(len(data))
        for r in range(nrel):
            ro=struct.unpack_from('<I',body,prel+r*10)[0]
            for k in range(ro,min(ro+4,len(data))): bad[k]=1
        run=0
        for j in range(len(data)):
            run = run+1 if not bad[j] else 0
            if run>=W: out.add(bytes(data[j-W+1:j+1]))
def libset(path):
    s=set()
    for n,b in ar_members(path): coff_windows(b,s)
    return s
exe=open(os.path.join(os.path.dirname(os.path.abspath(__file__)),'..','.work','original.exe'),'rb').read()
pe=struct.unpack_from('<I',exe,60)[0]; nsec=struct.unpack_from('<H',exe,pe+6)[0]; opt=struct.unpack_from('<H',exe,pe+20)[0]
base=struct.unpack_from('<I',exe,pe+24+28)[0]
for i in range(nsec):
    h=pe+24+opt+i*40; name=exe[h:h+8].rstrip(b'\0'); vs,va,rs,ro=struct.unpack_from('<IIII',exe,h+8)
    if name==b'.text': text=exe[ro:ro+rs]; tva=base+va
start=int(sys.argv[sys.argv.index('--start')+1],16) if '--start' in sys.argv else 0x449000
crt=text[start-tva:]
libs=dict(a.split('=',1) for a in sys.argv[1:] if '=' in a)
sets={}
for k,p in libs.items():
    s=set()
    for lib in ('libc.lib','libcmt.lib'):
        import os
        if os.path.exists(os.path.join(p,lib)): s|=libset(os.path.join(p,lib))
    sets[k]=s; print(k,'windows',len(s))
wins=[bytes(crt[j:j+W]) for j in range(0,len(crt)-W)]
tot=len(wins)
for k,s in sets.items(): print(k,'hits',sum(1 for w in wins if w in s),'of',tot)
for k,s in sets.items():
    others=set().union(*[v for kk,v in sets.items() if kk!=k])
    print('unique',k,sum(1 for w in wins if w in s and w not in others))
