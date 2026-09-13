extern "C" { void __cdecl FUN_0043EE60(int); }
extern "C" { void __cdecl FUN_0043EEA0(int); }
// Adapted from pc_decomp_backup/src/functions/FUN_0040EEA0.cpp
// Historical source SHA256: 94febc725872e15527f33612b0167184e1a5892204c267ea2bfacecc94433c38
extern "C" {
extern "C" void __cdecl FUN_0043EEA0(int);
extern "C" void __cdecl FUN_0043EE60(int);

extern "C" void __cdecl GEX_Target(int **param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (**param_1 != 0) {
    iVar4 = 0;
    do {
      if (**(int **)((int)*param_1 + iVar4) != 0) {
        iVar5 = 0;
        do {
          iVar1 = *(int *)(*(int *)((int)*param_1 + iVar4) + iVar5);
          if (**(int **)(iVar1 + 0x18) != 0) {
            iVar3 = 0;
            do {
              iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 0x18) + iVar3) + 8);
              if (iVar2 != 0) {
                FUN_0043EEA0(iVar2);
              }
              iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 0x18) + iVar3) + 0xc);
              if (iVar2 != 0) {
                FUN_0043EE60(iVar2);
              }
              iVar3 = iVar3 + 4;
            } while (*(int *)(*(int *)(iVar1 + 0x18) + iVar3) != 0);
          }
          iVar5 = iVar5 + 4;
        } while (*(int *)(*(int *)((int)*param_1 + iVar4) + iVar5) != 0);
      }
      iVar4 = iVar4 + 4;
    } while (*(int *)((int)*param_1 + iVar4) != 0);
  }
  return;
}
}
