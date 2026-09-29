// Adapted from pc_decomp_backup/src/functions/FUN_004374a0.cpp
// Historical source SHA256: 7e3b8557bd52cbdb3ce64061d4c86fa02f5f173a520a35fb4953dff3e8b9feb0
typedef unsigned char byte;
typedef unsigned int uint;
extern "C" {
void __cdecl FUN_004374a0(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0x10000;
  uVar5 = (int)*param_2 >> 0x1f;
  uVar1 = *param_1;
  iVar2 = (*param_2 ^ uVar5) - uVar5;
  iVar3 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
  if (iVar2 <= iVar3) {
    iVar2 = iVar3;
  }
  iVar3 = 0;
  do {
    if (iVar2 < iVar6) break;
    iVar6 = iVar6 * 2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  iVar3 = 3 - iVar3;
  bVar4 = (byte)iVar3;
  if (0 < iVar3) {
    *param_1 = uVar1 << (bVar4 & 0x1f);
    *param_2 = *param_2 << (bVar4 & 0x1f);
    return;
  }
  if (iVar3 < 0) {
    *param_1 = (int)uVar1 >> (-bVar4 & 0x1f);
    *param_2 = (int)*param_2 >> (-bVar4 & 0x1f);
  }
  return;
}
}
