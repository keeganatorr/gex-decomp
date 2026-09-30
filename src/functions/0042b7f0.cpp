// Adapted from pc_decomp_backup/src/functions/FUN_0042b7f0.cpp
// Historical source SHA256: 46cd9b9ecf61e1b66ec27ca93ffcf51a3acc8e5e463dcf635c0d3662fb231ae5
// Provisional behavior candidate; original bytes and gameplay are not claimed to match.
extern "C" {
extern int DAT_00455c1c;
extern int DAT_00455c3c;
extern int DAT_00456ad8;
extern int DAT_00456adc;
extern unsigned char DAT_004577b1;
extern int DAT_0045adf4;
extern int DAT_0045aecc;
extern int DAT_00463b30;
extern int DAT_00463b34;
extern int DAT_00463b38;
extern int DAT_00463b3c;
extern int DAT_00463b44;
extern int DAT_00463b4c;
extern int DAT_00463b50;
extern int DAT_00463b54;
extern int DAT_00463b5c;
extern int DAT_00463b60;
extern int DAT_00463b68;
extern int DAT_00463b70;
extern int DAT_00463bc0;
extern int DAT_00463bc4;
extern int DAT_00463bdc;
extern int DAT_00463be4;
extern int DAT_00463be8;
extern int DAT_00463bec;
extern int DAT_00463bfc;
extern int DAT_00463c08;
extern int DAT_00463c0c;
extern int DAT_00463c10;
extern int DAT_00463c14;
extern int DAT_00463c1c;
extern int DAT_00463c20;
extern int DAT_00463c24;
extern int DAT_00463c44;
extern int DAT_00463c48;
extern int DAT_00463c50;
extern int DAT_00463c54;
extern int DAT_00463c58;
extern int DAT_00463c5c;
extern int DAT_00463c60;
extern int DAT_00463c64;
extern int DAT_00463c68;
extern int DAT_00463c6c;
extern int DAT_00463c80;
extern int DAT_00463c84;
extern int DAT_00463d74;
extern unsigned char DAT_00487fd4_DPadKeyboardInput;
extern unsigned char DAT_004a028f_ActionButtons;
extern unsigned char DAT_004a0290;
extern unsigned char DAT_004a0291;
extern unsigned char DAT_004a0292;
extern unsigned char DAT_004a0294_SkipSubtitleMenu;
extern unsigned char DAT_004a0296;
extern unsigned char DAT_004a0299;
extern int DAT_004a2540;
extern int DAT_004a2964_LEV_Value;
extern int DAT_004a2a7c;
extern char FUN_0045AF48[];
extern char FUN_0045AF78[];
void __cdecl FUN_0040b9f0(void);
unsigned int __cdecl FUN_0040c110(int, int);
void __cdecl FUN_0041a360(int, int);
void __cdecl FUN_0041f8c0_LoadVoice(int);
void __cdecl FUN_0041fa80_SetUpVFXVariableForLoading(int);
unsigned int __cdecl FUN_0042bfe0(int, int);
void __cdecl FUN_0042c0a0(int, int, int);
void __cdecl FUN_0042c1a0(int);
void __cdecl FUN_00434190(int, int);
void __cdecl FUN_00434a20(int);
void __cdecl FUN_00405390_EmptyStringDebugFunction(char*, ...);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

extern "C" void __cdecl MapPlayerDoIt_0042b7f0(int param_1)

{
  int uVar1;
  unsigned int uVar2;
  int iVar3;
  int *puVar4;
  int *puVar5;
  int *puVar6;

  if (DAT_00463b30 != 0) {
    return;
  }
  if (DAT_00463b60 == 0) {
    DAT_00463b60 = 1;
    uVar2 = FUN_0042bfe0(param_1,0);
    *(unsigned int *)(param_1 + 0x9c) = *(unsigned int *)(param_1 + 0x9c) & 0xffff0000 | uVar2;
    FUN_0041a360(0x9a, 0xff);
    uVar2 = FUN_0040c110(0xdc,*(unsigned int *)(param_1 + 0x9c) & 0xffff);
    DAT_00463b38 = 1;
    *(int *)(param_1 + 0xa4) = 0xfffffffa;
    if ((*(unsigned int *)(uVar2 + 0xa4) & 0x10000000) == 0) {
      DAT_0045adf4 = 0x20000;
    }
    else {
      *(int *)(param_1 + 0xa4) = 0xffffffe7;
      DAT_0045adf4 = 0x8000;
    }
    iVar3 = *(int *)(param_1 + 0xa4) + -10;
    DAT_00463b3c = 2 - iVar3;
    *(int *)(param_1 + 0xa4) = iVar3;
    DAT_00463b4c = (int)(0x10000 / (__int64)DAT_00463b3c);
    *(int *)(param_1 + 200) = 0;
    *(int *)(param_1 + 0xcc) = 0;
    DAT_0045aecc = *(int *)(param_1 + 0x7c) - DAT_00463b3c * DAT_0045adf4;
  }
  if ((DAT_00463b38 != 0) && (*(int *)(param_1 + 0xa4) == -2)) {
    DAT_00463b38 = 0;
    *(int *)(param_1 + 200) = 0x10000;
    *(int *)(param_1 + 0xcc) = 0x10000;
    *(int *)(param_1 + 0xa4) = 0;
    return;
  }
  if ((DAT_004a0296 != '\0') && (DAT_00455c1c != 0)) {
    DAT_00455c3c = 0;
    DAT_004a2a7c = 1;
    FUN_0040b9f0();
    return;
  }
  if (*(int *)(param_1 + 0xa4) < -2) {
    return;
  }
  uVar2 = *(unsigned int *)(param_1 + 0xb4);
  if ((uVar2 & 0xfff0) < 0x1900) {
    uVar2 = (uVar2 + 0x10 ^ uVar2) & 0xfff0 ^ uVar2;
    goto FUN_0042BA09;
  }
  switch(uVar2 & 0xf) {
  case 1:
    FUN_0041f8c0_LoadVoice(0x08);
    iVar3 = 8;
    break;
  case 2:
    FUN_0041f8c0_LoadVoice(0x2e);
    iVar3 = 0x2e;
    break;
  case 3:
    FUN_0041f8c0_LoadVoice(0x1e);
    iVar3 = 0x1e;
    break;
  case 4:
  case 7:
    FUN_0041f8c0_LoadVoice(0x39);
    iVar3 = 0x39;
    break;
  default:
    goto switchD_0042b99d_caseD_5;
  case 6:
    FUN_0041f8c0_LoadVoice(0x27);
    iVar3 = 0x27;
  }
  FUN_0041fa80_SetUpVFXVariableForLoading(iVar3);
switchD_0042b99d_caseD_5:
  uVar2 = *(unsigned int *)(param_1 + 0xb4) & 0xffff000f;
FUN_0042BA09:
  *(unsigned int *)(param_1 + 0xb4) = uVar2;
  if (*(int *)(param_1 + 0xa4) == -2) {
    FUN_0041a360(0x99, 0xff);
    uVar2 = FUN_0040c110(0xdc,*(unsigned int *)(param_1 + 0x9c) & 0xffff);
    DAT_00456ad8 = *(int *)(uVar2 + 0x9c);
    DAT_00456adc = *(int *)(uVar2 + 0xa0);
    DAT_004a2964_LEV_Value = *(int *)(uVar2 + 0x9c);
    DAT_00455c3c = 2;
    DAT_004a2a7c = 1;
    FUN_0040b9f0();
    return;
  }
  if (*(int *)(param_1 + 0x98) == 0) {
    if (DAT_004a0299 == '\0') {
      if (DAT_00463b68 != 0) {
        return;
      }
      if ((DAT_004a0294_SkipSubtitleMenu != '\0') || (DAT_00487fd4_DPadKeyboardInput == '\r')) {
        uVar2 = FUN_0040c110(0xdc,*(unsigned int *)(param_1 + 0x9c) & 0xffff);
        if (uVar2 == 0) {
          return;
        }
        iVar3 = *(int *)(uVar2 + 0x9c);
        if (iVar3 < 0) {
          return;
        }
        if ((((&DAT_004577b1)[iVar3 * 8] & 2) != 0) &&
           ((*(unsigned char *)((int)&DAT_004a2540 + iVar3) & 2) != 0)) {
          return;
        }
        if (DAT_004a2964_LEV_Value != iVar3) {
          if ((*(unsigned char *)((int)&DAT_004a2540 + iVar3) & 1) == 0) {
            return;
          }
          *(int *)(param_1 + 0xa4) = 0xfffffffa;
          if ((*(unsigned int *)(uVar2 + 0xa4) & 0x10000000) == 0) {
            DAT_0045adf4 = 0xfffe0000;
          }
          else {
            *(int *)(param_1 + 0xa4) = 0xffffffe7;
            DAT_0045adf4 = 0xffff8000;
          }
          DAT_00463b3c = 2 - *(int *)(param_1 + 0xa4);
          DAT_00463b4c = (int)(0x10000 / (__int64)DAT_00463b3c);
          *(int *)(param_1 + 0x50) = 0x18;
          *(int *)(param_1 + 0xa0) = 8;
          uVar1 = *(int *)(param_1 + 0xb0);
          *(int *)(param_1 + 0xb0) = 0;
          *(int *)(param_1 + 0xac) = uVar1;
          FUN_0042c1a0(param_1);
          return;
        }
        if (*(char *)(uVar2 + 0xa4) != '\x01') {
          return;
        }
        DAT_00463b34 = *(int *)(uVar2 + 0xa0);
        DAT_00463b30 = 1;
        DAT_00463b44 = 0;
        return;
      }
    }
    if (DAT_00463b68 != 0) {
      return;
    }
    if (DAT_004a028f_ActionButtons == '\0') {
      if (DAT_004a0290 == '\0') {
        if (DAT_004a0291 == '\0') {
          if (DAT_004a0292 == '\0') {
            return;
          }
          uVar2 = FUN_0040c110(0xdc,*(unsigned int *)(param_1 + 0x9c) & 0xffff);
          iVar3 = *(int *)(uVar2 + 0xb4);
        }
        else {
          uVar2 = FUN_0040c110(0xdc,*(unsigned int *)(param_1 + 0x9c) & 0xffff);
          iVar3 = *(int *)(uVar2 + 0xb0);
        }
      }
      else {
        uVar2 = FUN_0040c110(0xdc,*(unsigned int *)(param_1 + 0x9c) & 0xffff);
        iVar3 = *(int *)(uVar2 + 0xac);
      }
    }
    else {
      uVar2 = FUN_0040c110(0xdc,*(unsigned int *)(param_1 + 0x9c) & 0xffff);
      iVar3 = *(int *)(uVar2 + 0xa8);
    }
    if (iVar3 < 1) {
      return;
    }
    puVar4 = (int *)FUN_0040c110(0xdd,iVar3);
    if (puVar4 == (int *)0x0) {
      FUN_00405390_EmptyStringDebugFunction
                (FUN_0045AF78,*(unsigned int *)(param_1 + 0x9c) & 0xffff,
                 iVar3);
      return;
    }
    uVar2 = FUN_0040c110(0xdc,puVar4[0x27]);
    if (uVar2 == 0) {
      FUN_00405390_EmptyStringDebugFunction
                (FUN_0045AF48,iVar3,puVar4[0x27]);
      return;
    }
    if (((*(unsigned int *)(uVar2 + 0xa4) & 0x200) != 0) &&
       ((*(unsigned char *)((int)&DAT_004a2540 + *(int *)(uVar2 + 0x9c)) & 1) == 0)) {
      return;
    }
    if ((*(unsigned int *)(uVar2 + 0xa4) & 0x100) != 0) {
      FUN_0042c0a0(param_1,uVar2,*(unsigned int *)(param_1 + 0x9c) & 0xffff);
    }
    puVar6 = puVar4;
    puVar5 = &DAT_00463b70;
    for (iVar3 = 0x81; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
    }
    FUN_00434a20(0x463b70);
    DAT_00463bfc = 0;
    DAT_00463c08 = 0;
    DAT_00463c10 = 0;
    DAT_00463c14 = puVar4[0x29];
    DAT_00463c1c = 0;
    DAT_00463c0c = 0x18000;
    DAT_00463c20 = 0;
    DAT_00463c24 = puVar4[0x2d];
    DAT_00463b50 = puVar4[0x1e];
    DAT_00463b54 = puVar4[0x1f];
    DAT_00463be8 = DAT_00463b50;
    DAT_00463bec = DAT_00463b54;
    *(int *)(param_1 + 0x98) = 1;
    uVar2 = puVar4[0x27];
    *(int *)(param_1 + 0x54) = 0;
    *(int *)(param_1 + 0xa8) = 0;
    *(int *)(param_1 + 0xa4) = 1;
    *(unsigned int *)(param_1 + 0x9c) = *(unsigned int *)(param_1 + 0x9c) & 0xffff0000 | uVar2;
    DAT_00463d74 = 0;
  }
  iVar3 = DAT_00463be4;
  if (-1 < *(int *)(param_1 + 0xa4)) {
    DAT_00463c44 = DAT_00463be8;
    DAT_00463c48 = DAT_00463bec;
    DAT_00463c6c = DAT_00463bdc;
    DAT_00463c64 = DAT_00463bc0;
    DAT_00463c68 = DAT_00463bc4;
    DAT_00463c54 = 0;
    DAT_00463c58 = 0;
    DAT_00463c5c = 0;
    DAT_00463c60 = 0;
    DAT_00463c50 = (DAT_00463c50 ^ (DAT_00463c50 * 2 ^ DAT_00463c50) & 0x200) & 0xfffffeff;
    FUN_00434190(0x463b70,DAT_00463b5c);
    if (iVar3 != DAT_00463be4) {
      if ((*(unsigned int *)(param_1 + 0x9c) & 0xffff0000) == 0) {
        *(int *)(param_1 + 0xa4) = 0xffffffff;
      }
      else {
        puVar5 = (int *)FUN_0040c110(0xdd,*(unsigned int *)(param_1 + 0x9c) >> 0x10);
        puVar4 = puVar5;
        puVar6 = &DAT_00463b70;
        for (iVar3 = 0x81; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar6 = puVar6 + 1;
        }
        FUN_00434a20(0x463b70);
        DAT_00463bfc = 0;
        DAT_00463c08 = 0;
        DAT_00463c10 = 0;
        DAT_00463c14 = puVar5[0x29];
        DAT_00463c1c = 0;
        DAT_00463c0c = 0x18000;
        DAT_00463c20 = 0;
        DAT_00463c24 = puVar5[0x2d];
        DAT_00463b50 = puVar5[0x1e];
        DAT_00463b54 = puVar5[0x1f];
        uVar2 = puVar5[0x27];
        DAT_00463be8 = DAT_00463b50;
        DAT_00463bec = DAT_00463b54;
        *(int *)(param_1 + 0x54) = 0;
        *(int *)(param_1 + 0xa8) = 0;
        *(int *)(param_1 + 0xa4) = 1;
        *(unsigned int *)(param_1 + 0x9c) = uVar2 | *(unsigned int *)(param_1 + 0x9c) & 0xffff0000;
        *(unsigned int *)(param_1 + 0x9c) = uVar2 & 0xffff;
      }
    }
    if (DAT_00463c84 == -1) {
      DAT_00463c80 = 0;
    }
    DAT_00463c84 = -1;
  }
  return;
}
