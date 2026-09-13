// Adapted from pc_decomp_backup/src/functions/FUN_0042c1a0.cpp
// Historical source SHA256: 29dd87a7ad7bb6289f7fd25fe3e1c9d4fab0e314f67fdb2fa693701b3ac38af5
typedef unsigned int uint;
extern "C" {
void __cdecl GEX_Target(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0xac) == *(int *)(param_1 + 0xb0)) {
    *(uint *)(param_1 + 0xb4) = *(uint *)(param_1 + 0xb4) & 0xffffff;
    return;
  }
  uVar3 = *(int *)(param_1 + 0xb0) - *(int *)(param_1 + 0xac);
  uVar1 = uVar3;
  if ((int)uVar3 < 0) {
    uVar1 = -uVar3;
  }
  uVar2 = uVar3;
  if (4 < (int)uVar1) {
    uVar2 = (int)uVar1 >> 0x1f;
    uVar2 = 4 - (((uVar1 ^ uVar2) - uVar2 & 3 ^ uVar2) - uVar2);
    if (0 < (int)uVar3) {
      uVar2 = -uVar2;
    }
  }
  if ((int)uVar2 < 0) {
    *(uint *)(param_1 + 0xb4) = *(uint *)(param_1 + 0xb4) | 0xff000000;
    return;
  }
  *(uint *)(param_1 + 0xb4) = *(uint *)(param_1 + 0xb4) & 0xffffff | 0x1000000;
  return;
}
}
