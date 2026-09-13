// Adapted from pc_decomp_backup/src/functions/FUN_004317b0.cpp
// Historical source SHA256: c822ad64a1f1bb5aab33a68dfac16ddd3153fcf032c7984eb7d5483c705af406
extern "C" {
void __cdecl GEX_Target(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x15c);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) - *(int *)(iVar1 + 0x78);
    *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) - *(int *)(iVar1 + 0x7c);
  }
  return;
}
}
