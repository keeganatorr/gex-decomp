// Adapted from pc_decomp_backup/src/functions/FUN_0040d910.cpp
// Historical source SHA256: 1b586971b8087b3b42a029239af5d78c92308f23e70b15b59a4a519e876ccc3b
typedef unsigned int uint;
typedef unsigned int undefined4;
extern "C" {
void __cdecl GEX_Target(int param_1,int *param_2)

{
  if (((*param_2 != 0) && ((*(uint *)(param_1 + 0xa0) & 0xf) == 0)) &&
     ((**(uint **)(*(int *)(param_1 + 0x178) + 0x170) & 0xffff) == 1)) {
    *(undefined4 *)(param_1 + 0xa4) = 0;
    *(undefined4 *)(param_1 + 0xa8) = 0;
    *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & 0xfffffff1 | 1;
  }
  *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & 0xfffffef | 0x10;
  return;
}
}
