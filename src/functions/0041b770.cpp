// Adapted from pc_decomp_backup/src/functions/FUN_0041b770.cpp
// Historical source SHA256: c34b2520590b71a4a133b094239fc0994910cde14a8ea9973a4bfef398760e4f
// Behavior candidate; original bytes are not claimed to match.
extern "C" {
extern int DAT_00455c54_EventVar;
extern int DAT_00456afc_MaxHealth;
extern int DAT_00456b00;
extern int DAT_004593bc;
extern int DAT_004593c0;
extern int DAT_004593c4;
extern int DAT_004593d0;
extern int DAT_004594a0;
extern int DAT_004594a8;
extern int DAT_0045a6e0;
extern int DAT_004635b4;
extern int DAT_004635b8;
extern int DAT_004635bc;
extern int DAT_004a23c4;
extern int DAT_004a2808;
extern int DAT_004a281c_Health;
extern int DAT_004a2a1c;
extern int DAT_004a2a38_Camera;
extern int DAT_004a2ac8_FrameCount;
extern int DAT_004a2ad4;
extern char FUN_00459474[];
extern char FUN_0045947C[];
extern char FUN_00459484[];
int __cdecl sprintf(char*, const char*, ...);
void __cdecl FUN_0041a360(int, int);
void __cdecl FUN_00441150_Flashing(int);
void __cdecl FUN_00444590_DrawBehindAndInfrontObjects(int);
int __cdecl GEX_WidescreenWidth(void);
}


extern "C" void __cdecl HUDDraw_0041b770(int param_1)

{
  int uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char acStack_14 [20];
  int widescreenCameraX = DAT_004a2a38_Camera + ((GEX_WidescreenWidth() - 320) / 2 << 16);

  if (DAT_00455c54_EventVar == 0) {
    *(unsigned int *)(param_1 + 0xe0) = *(unsigned int *)(param_1 + 0xe0) | 0x1000000;
    *(int *)(param_1 + 0x50) = 3;
    *(int *)(param_1 + 0x7c) = DAT_004a2a1c + 0x200000;
    if (9999999 < DAT_004a23c4) {
      DAT_004a23c4 = 9999999;
    }
    iVar4 = 0;
    sprintf(acStack_14,FUN_00459484,DAT_004a23c4);
    iVar5 = 0;
    do {
      iVar2 = widescreenCameraX + iVar4;
      iVar4 = iVar4 + 0x90000;
      *(int *)(param_1 + 0x78) = iVar2 + 0x1c0000;
      *(int *)(param_1 + 0x54) = acStack_14[iVar5] + -0x30;
      FUN_00444590_DrawBehindAndInfrontObjects(param_1);
      iVar5 = iVar5 + 1;
    } while (iVar4 < 0x3f0000);
    if ((DAT_004a2ac8_FrameCount & 1) != 0) {
      DAT_004635bc = DAT_004635bc + 1;
    }
    *(int *)(param_1 + 0x50) = 4;
    *(int *)(param_1 + 0x54) = DAT_004635bc;
    *(int *)(param_1 + 0x78) = widescreenCameraX + 0xb00000;
    *(int *)(param_1 + 0x7c) = DAT_004a2a1c + 0x1f0000;
    *(int *)(param_1 + 200) = 0xa000;
    *(int *)(param_1 + 0xcc) = 0xa000;
    *(int *)(param_1 + 0xc4) = 0;
    FUN_00441150_Flashing(param_1);
    DAT_004635bc = *(int *)(param_1 + 0x54);
    *(int *)(param_1 + 0x50) = 3;
    *(int *)(param_1 + 0x7c) = DAT_004a2a1c + 0x200000;
    if (99 < DAT_004a2808) {
      DAT_004a2808 = 0;
      FUN_0041a360(0x7b, 0x100);
      DAT_00456b00 = DAT_00456b00 + 1;
    }
    iVar4 = 0;
    sprintf(acStack_14,FUN_0045947C,DAT_004a2808);
    iVar5 = 0;
    do {
      iVar2 = widescreenCameraX + iVar4;
      iVar4 = iVar4 + 0x90000;
      *(int *)(param_1 + 0x78) = iVar2 + 0xbe0000;
      *(int *)(param_1 + 0x54) = acStack_14[iVar5] + -0x30;
      FUN_00444590_DrawBehindAndInfrontObjects(param_1);
      iVar5 = iVar5 + 1;
    } while (iVar4 < 0x120000);
    *(int *)(param_1 + 0x50) = 1;
    *(int *)(param_1 + 0x54) = 0;
    *(int *)(param_1 + 0x78) = widescreenCameraX + 0x900000;
    *(int *)(param_1 + 0x7c) = DAT_004a2a1c + 0x1e0000;
    FUN_00444590_DrawBehindAndInfrontObjects(param_1);
    *(int *)(param_1 + 0x50) = 3;
    *(int *)(param_1 + 0x7c) = DAT_004a2a1c + 0x200000;
    if (99 < DAT_00456b00) {
      DAT_00456b00 = 99;
    }
    iVar4 = 0x900000;
    sprintf(acStack_14,FUN_0045947C,DAT_00456b00);
    iVar5 = 0;
    do {
      iVar2 = widescreenCameraX + iVar4;
      iVar4 = iVar4 + 0x90000;
      *(int *)(param_1 + 0x78) = iVar2;
      *(int *)(param_1 + 0x54) = acStack_14[iVar5] + -0x30;
      FUN_00444590_DrawBehindAndInfrontObjects(param_1);
      iVar5 = iVar5 + 1;
    } while (iVar4 < 0xa20000);
    iVar5 = DAT_00456afc_MaxHealth * -0x20000 + 0x110000;
    piVar3 = &DAT_004594a8;
    do {
      if (-1 < *piVar3) {
        iVar5 = iVar5 + -2;
      }
      piVar3 = piVar3 + -1;
    } while ((int *)0x45949f < piVar3);
    *(int *)(param_1 + 0x50) = 2;
    *(int *)(param_1 + 0x54) = 1;
    *(int *)(param_1 + 0x7c) = DAT_004a2a1c + 0x200000;
    *(int *)(param_1 + 0x78) = widescreenCameraX + 0x1280000;
    if (8 < DAT_00456afc_MaxHealth) {
      DAT_00456afc_MaxHealth = 8;
    }
    if (8 < DAT_004a281c_Health) {
      DAT_004a281c_Health = 8;
    }
    iVar4 = 1;
    if (0 < DAT_00456afc_MaxHealth) {
      do {
        if (DAT_004a281c_Health < iVar4) {
          *(int *)(param_1 + 0x54) = 0;
        }
        iVar4 = iVar4 + 1;
        FUN_00444590_DrawBehindAndInfrontObjects(param_1);
        *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) - iVar5;
      } while (iVar4 <= DAT_00456afc_MaxHealth);
    }
    uVar1 = *(int *)(param_1 + 0xc);
    iVar4 = 8;
    *(int *)(param_1 + 0xc) = DAT_004a2ad4;
    *(int *)(param_1 + 0x50) = 0;
    *(int *)(param_1 + 200) = 0x10000;
    *(int *)(param_1 + 0xcc) = 0x10000;
    do {
      iVar2 = *(int *)((int)&DAT_004594a0 + iVar4);
      if (-1 < iVar2) {
        *(int *)(iVar4 + 0x4635a8) = *(int *)(iVar4 + 0x4635a8) + 0x80000;
        *(int *)(param_1 + 0x54) = iVar2;
        *(unsigned int *)(param_1 + 0xc4) = *(unsigned int *)(iVar4 + 0x4635a8) & 0xff0000;
        FUN_00441150_Flashing(param_1);
        *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) - iVar5;
      }
      iVar4 = iVar4 + -4;
    } while (-1 < iVar4);
    if (-1 < DAT_0045a6e0) {
      if ((&DAT_004593d0)[DAT_004635b8] == 0) {
        DAT_004635b8 = 0;
      }
      DAT_004635b4 = DAT_004635b4 + 0x80000;
      if (DAT_0045a6e0 == 0xb1) {
        *(int *)(param_1 + 0x54) = 0xb;
        *(int *)(param_1 + 200) = 0x8000;
        *(int *)(param_1 + 0xcc) = 0x8000;
      }
      else {
        *(int *)(param_1 + 0x54) = DAT_0045a6e0;
        *(int *)(param_1 + 200) = 0x10000;
        *(int *)(param_1 + 0xcc) = 0x10000;
      }
      *(unsigned int *)(param_1 + 0xc4) = DAT_004635b4 & 0xff0000;
      *(int *)(param_1 + 0xbc) = (&DAT_004593d0)[DAT_004635b8];
      DAT_004635b8 = DAT_004635b8 + 1;
      FUN_00441150_Flashing(param_1);
      *(int *)(param_1 + 0xbc) = 0;
    }
    *(int *)(param_1 + 0xc) = uVar1;
    if (DAT_004593c4 != 0) {
      *(int *)(param_1 + 0x50) = 3;
      *(int *)(param_1 + 0x7c) = DAT_004a2a1c + 0xd20000;
      if (DAT_004593bc < 0) {
        DAT_004593bc = 0;
      }
      else if (99 < DAT_004593bc) {
        DAT_004593bc = 99;
      }
      iVar4 = 0;
      sprintf(acStack_14,FUN_0045947C,DAT_004593bc);
      iVar5 = 0;
      do {
        iVar2 = widescreenCameraX + iVar4;
        iVar4 = iVar4 + 0x90000;
        *(int *)(param_1 + 0x78) = iVar2 + 0x1180000;
        *(int *)(param_1 + 0x54) = acStack_14[iVar5] + -0x30;
        FUN_00444590_DrawBehindAndInfrontObjects(param_1);
        iVar5 = iVar5 + 1;
      } while (iVar4 < 0x120000);
      *(int *)(param_1 + 0x50) = 1;
      *(int *)(param_1 + 0x54) = 0;
      *(int *)(param_1 + 0x78) = widescreenCameraX + 0x140000;
      *(int *)(param_1 + 0x7c) = DAT_004a2a1c + 0xd20000;
      FUN_00444590_DrawBehindAndInfrontObjects(param_1);
      *(int *)(param_1 + 0x50) = 3;
      *(int *)(param_1 + 0x7c) = DAT_004a2a1c + 0xd20000;
      if (DAT_004593c0 < 0) {
        DAT_004593c0 = 0;
      }
      else if (999 < DAT_004593c0) {
        DAT_004593c0 = 999;
      }
      iVar4 = 0;
      sprintf(acStack_14,FUN_00459474,DAT_004593c0);
      iVar5 = 0;
      do {
        iVar2 = widescreenCameraX + iVar4;
        iVar4 = iVar4 + 0x90000;
        *(int *)(param_1 + 0x78) = iVar2 + 0x1e0000;
        *(int *)(param_1 + 0x54) = acStack_14[iVar5] + -0x30;
        FUN_00444590_DrawBehindAndInfrontObjects(param_1);
        iVar5 = iVar5 + 1;
      } while (iVar4 < 0x1b0000);
    }
  }
  return;
}
