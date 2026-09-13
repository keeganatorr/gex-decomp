// Adapted from pc_decomp_backup/src/functions/FUN_0042cbd0.cpp
// Historical source SHA256: 9f758baece423e6088ae4d03b12d0ad2d7861b81b960ad3c6b90376a4cfe163d
extern "C" {
void __cdecl GEX_Target(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  param_2[1] = (int)param_1;
  *param_2 = iVar1;
  *(int **)(iVar1 + 4) = param_2;
  *param_1 = (int)param_2;
  return;
}
}
