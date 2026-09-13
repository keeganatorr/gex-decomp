typedef unsigned int uint;
typedef unsigned int undefined4;
extern "C" {
undefined4 __cdecl GEX_Target(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_3 - param_1;
  uVar3 = param_4 - param_2;
  iVar1 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
  iVar2 = (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
  uVar4 = (uint)(0 < (int)uVar4);
  if (0 < (int)uVar3) {
    uVar4 = uVar4 | 2;
  }
  if (iVar2 < iVar1) {
    uVar3 = uVar4 | 4;
    if (iVar2 < iVar1 >> 1) {
      return *(undefined4 *)((uVar4 | 0xc) * 4 + 0x45ab68);
    }
  }
  else {
    uVar3 = uVar4;
    if (iVar1 < iVar2 >> 1) {
      uVar3 = uVar4 | 8;
    }
  }
  return *(undefined4 *)(uVar3 * 4 + 0x45ab68);
}
}
