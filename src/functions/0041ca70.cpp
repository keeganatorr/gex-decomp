// Adapted from pc_decomp_backup/src/functions/FUN_0041ca70.cpp
// Historical source SHA256: 79f22130d175cabe3e4a7be4544820de89ee380bbbcad7bf47f3839b2e5dcf7e
typedef unsigned int uint;
typedef unsigned int undefined4;
extern "C" {
undefined4 __cdecl CLD_ComputeAngleEdgesWithFrame_0041ca70(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  piVar5 = (int *)*param_1;
  if (piVar5 != (int *)0x0) {
    piVar1 = param_1 + 6;
    uVar6 = param_1[1] + 0x200000U & 0xc00000;
    param_1[1] = uVar6;
    if (param_1[4] == 0) {
      *piVar1 = *piVar5;
      iVar4 = piVar5[2];
    }
    else {
      *piVar1 = -piVar5[2];
      iVar4 = -*piVar5;
    }
    piVar3 = param_1 + 7;
    piVar2 = param_1 + 8;
    *piVar3 = iVar4;
    if (param_1[5] == 0) {
      *piVar2 = piVar5[1];
      iVar4 = piVar5[3];
    }
    else {
      *piVar2 = -piVar5[3];
      iVar4 = -piVar5[1];
    }
    piVar5 = param_1 + 9;
    *piVar5 = iVar4;
    if (uVar6 != 0) {
      if (uVar6 == 0x400000) {
        iVar4 = *piVar2;
        *piVar2 = *piVar1;
        *piVar1 = -*piVar5;
        *piVar5 = *piVar3;
        *piVar3 = -iVar4;
      }
      else if (uVar6 == 0x800000) {
        iVar4 = *piVar2;
        *piVar2 = -*piVar5;
        *piVar5 = -iVar4;
        iVar4 = *piVar1;
        *piVar1 = -*piVar3;
        *piVar3 = -iVar4;
      }
      else if (uVar6 == 0xc00000) {
        iVar4 = *piVar2;
        *piVar2 = -*piVar3;
        *piVar3 = *piVar5;
        *piVar5 = -*piVar1;
        *piVar1 = iVar4;
      }
    }
    *piVar3 = *piVar3 + param_1[2];
    *piVar1 = *piVar1 + param_1[2];
    *piVar2 = *piVar2 + param_1[3];
    *piVar5 = *piVar5 + param_1[3];
    return 1;
  }
  return 0;
}
}
