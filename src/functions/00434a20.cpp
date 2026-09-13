// Adapted from pc_decomp_backup/src/functions/FUN_00434a20.cpp
// Historical source SHA256: 85b41dfe335407bf4acbd87a6da564d7d9c63785daeb71fca9aabb71b35eb636
typedef unsigned int uint;
extern "C" {
void __cdecl GEX_Target(int param_1)

{
  if (*(int *)(param_1 + 0xa4) != 0) {
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa4) + 4;
    *(uint *)(param_1 + 0xb4) = *(uint *)(param_1 + 0xb4) & 0xfffffff7;
  }
  return;
}
}
