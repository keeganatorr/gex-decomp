extern "C" { extern int DAT_00455B90; }
extern "C" { extern int DAT_00455B8C; }
extern "C" { extern int DAT_004A2A1C; }
extern "C" { extern int DAT_004A2A38; }
typedef unsigned int undefined4;
extern "C" {
void __cdecl GEX_Target(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x78) - DAT_004A2A38;
  iVar2 = *(int *)(param_1 + 0x7c) - DAT_004A2A1C;
  if ((((-1 < iVar1) && (iVar1 < 0x1400000)) && (-1 < iVar2)) && (iVar2 < 0xf00000)) {
    DAT_00455B8C = *(undefined4 *)(param_1 + 0x98);
    DAT_00455B90 = *(undefined4 *)(param_1 + 0x9c);
  }
  return;
}
}
