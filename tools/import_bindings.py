#!/usr/bin/env python3
"""Derive named PE import IAT bindings from the pinned executable and SDK libs.
Read-only: prints a staged mapping; never edits project.json or the database.
"""
import argparse,hashlib,json,pathlib,struct,subprocess

def u16(b,o):return struct.unpack_from('<H',b,o)[0]
def u32(b,o):return struct.unpack_from('<I',b,o)[0]
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--exe',default='.work/original.exe');ap.add_argument('--sdk',default='/home/keegan/Downloads/NTSource/public/sdk/lib/i386');args=ap.parse_args();exe=pathlib.Path(args.exe);b=exe.read_bytes();assert hashlib.sha256(b).hexdigest()=='e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86';pe=u32(b,0x3c);assert b[pe:pe+4]==b'PE\0\0' and u16(b,pe+4)==0x14c;opt=pe+24;assert u16(b,opt)==0x10b;base=u32(b,opt+28);n=u16(b,pe+6);size=u16(b,pe+20);secs=[]
 for i in range(n):
  q=opt+size+i*40;secs.append((u32(b,q+12),u32(b,q+16),u32(b,q+20)))
 def off(rva,length=1):
  hits=[raw+rva-r for r,size,raw in secs if r<=rva and rva+length<=r+size];assert len(hits)==1;return hits[0]
 def string(rva):
  o=off(rva);return b[o:b.index(0,o)].decode('ascii')
 imports=[];directory=u32(b,opt+104);directory_size=u32(b,opt+108)
 for di in range(directory_size//20):
  do=off(directory+di*20,20);ilt,timestamp,forwarder,name,iat=struct.unpack_from('<5I',b,do)
  if not any((ilt,timestamp,forwarder,name,iat)):break
  dll=string(name)
  for index in range(65536):
   lookup=u32(b,off((ilt or iat)+index*4,4))
   if not lookup:break
   if lookup&0x80000000:continue
   imports.append({'dll':dll,'name':string(lookup+2),'hint':u16(b,off(lookup,2)),'slot':f'{base+iat+index*4:08x}','slotRva':f'{iat+index*4:08x}','index':index})
 libs={p.stem.upper():p for p in pathlib.Path(args.sdk).glob('*.lib')};bindings={};mapped=[]
 for item in imports:
  if not item['name']:item['reason']='ordinal-only import';continue
  lib=libs.get(item['dll'].split('.')[0].upper())
  if not lib:item['reason']='no SDK import library';continue
  text=subprocess.check_output(['llvm-nm',str(lib)],text=True,stderr=subprocess.DEVNULL)
  names=[]
  for line in text.splitlines():
   if not line.strip():continue
   sym=line.split()[-1]
   if not sym.startswith('__imp__'):continue
   undec=sym[len('__imp__'):].rsplit('@',1)[0]
   if undec==item['name']:names.append(sym)
  if len(names)!=1:item['reason']='SDK COFF spelling ambiguous or absent';item['candidates']=names;continue
  sym=names[0]
  if sym in bindings and bindings[sym]!=item['slot']:raise RuntimeError('same COFF symbol mapped to two IAT slots')
  bindings[sym]=item['slot'];item['coffSymbol']=sym;item['sdkLibrary']=str(lib);mapped.append(item)
 out={'state':'staged-only; no project/config/database edits','executable':str(exe.resolve()),'sha256':hashlib.sha256(b).hexdigest(),'imageBase':f'{base:08x}','imports':imports,'mappedCount':len(mapped),'unmappedCount':len(imports)-len(mapped),'bindings':dict(sorted(bindings.items())),'sdkLibraries':{str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in sorted(set(libs.values())) if any(x.get('sdkLibrary')==str(p) for x in mapped)}}
 print(json.dumps(out,indent=2))
if __name__=='__main__':main()
