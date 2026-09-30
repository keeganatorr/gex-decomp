extern "C" {
int __cdecl GEX_WidescreenWidth(void);
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int DAT_00455b8c_CamX2;
extern int DAT_00455b90_CamY2;

void __cdecl FUN_00410200(int param_1)
{
  int iVar1;
  int iVar2;

  iVar1 = *(int *)(param_1 + 0x78) - CAMERA_XPos_004a2a38;
  iVar2 = *(int *)(param_1 + 0x7c) - CAMERA_YPos_004a2a1c;
  if ((iVar1 >= 0 && iVar1 < (GEX_WidescreenWidth() << 16)) && (iVar2 >= 0 && iVar2 < 0xf00000)) {
    DAT_00455b8c_CamX2 = *(int *)(param_1 + 0x98);
    DAT_00455b90_CamY2 = *(int *)(param_1 + 0x9c);
  }
}
}
