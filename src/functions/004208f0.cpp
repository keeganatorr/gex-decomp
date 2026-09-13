// Adapted from pc_decomp_backup/src/functions/FUN_004208f0.cpp
// Historical source SHA256: 000830566023eec8f71ec40a372218e2d126f9f1a0ba12ecfd09580e35a819c6
typedef unsigned int uint;
extern "C" {
void __cdecl GEX_Target(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(int *)(param_1 + 0x7c) + (0x200000 - (*(uint *)(param_2 + 0x20) & 0x1fffff));
  return;
}
}
