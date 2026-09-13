extern "C" { extern int DAT_004A2A78; }
extern "C" { extern int DAT_004626FC; }
typedef unsigned int undefined4;
extern "C" {
void __cdecl GEX_Target(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < DAT_004626FC) {
    iVar2 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*(int *)((int)DAT_004A2A78 + iVar2) + 0x34) = param_1;
      iVar2 = iVar2 + 4;
    } while (iVar1 < DAT_004626FC);
  }
  return;
}
}
