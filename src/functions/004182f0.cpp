// Adapted from pc_decomp_backup/src/functions/FUN_004182f0.cpp
// Historical source SHA256: 164ccfad7fb783dd778c74d8fa7aa1a7dbbb8409329eb7e405ef2d351178cca3
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned int undefined4;
extern "C" {
byte * __cdecl GEX_Target(byte *param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  bVar1 = *param_1;
  uVar2 = *(undefined4 *)(param_2 + 0x68 + (uint)bVar1 * 4);
  for (iVar3 = *(int *)(param_2 + 0x160); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x164)) {
    *(undefined4 *)(iVar3 + 0x68 + (uint)bVar1 * 4) = uVar2;
  }
  return param_1 + 1;
}
}
