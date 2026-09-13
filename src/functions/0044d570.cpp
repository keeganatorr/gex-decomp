typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
extern "C" {
ushort __cdecl GEX_Target(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = (param_1 & 0x10) != 0;
  if ((param_1 & 8) != 0) {
    bVar3 = bVar3 | 4;
  }
  if ((param_1 & 4) != 0) {
    bVar3 = bVar3 | 8;
  }
  if ((param_1 & 2) != 0) {
    bVar3 = bVar3 | 0x10;
  }
  if ((param_1 & 1) != 0) {
    bVar3 = bVar3 | 0x20;
  }
  if ((param_1 & 0x80000) != 0) {
    bVar3 = bVar3 | 2;
  }
  uVar1 = (ushort)bVar3;
  uVar2 = param_1 & 0x300;
  if (uVar2 == 0x100) {
    uVar1 = uVar1 | 0x400;
  }
  else if (uVar2 == 0x200) {
    uVar1 = uVar1 | 0x800;
  }
  else if (uVar2 == 0x300) {
    uVar1 = uVar1 | 0xc00;
  }
  if ((param_1 & 0x30000) == 0) {
    uVar1 = uVar1 | 0x300;
  }
  else if ((param_1 & 0x30000) == 0x10000) {
    uVar1 = uVar1 | 0x200;
  }
  if ((param_1 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  return uVar1;
}
}
