// Adapted from pc_decomp_backup/src/functions/FUN_0042f910.cpp
// Historical source SHA256: 6b96b01f0833dbbfce0d1581a269f3b280b9dabaf33fe50f062c05cc5e9cfe84
// Provisional behavior candidate; original bytes and gameplay are not claimed to match.
extern "C" {
extern int _DAT_0045A5C8;
extern int _DAT_0045A6C8;
extern int _DAT_0045A7C8;
extern int _DAT_0045A8C8;
extern int _DAT_0045A9C8;
extern int _DAT_0045B100;
extern int _DAT_0045B104;
extern int _DAT_0045B108;
extern int _DAT_0045B10C;
extern int _DAT_0045B110;
extern int _DAT_00463F00;
extern int _DAT_00463F04;
extern int _DAT_00463F08;
extern int _DAT_00463F0C;
extern int _DAT_004A2A1C;
extern int _DAT_004A2AD4;
extern int DAT_004a2a38_Camera;
extern unsigned char s_sl67_0045a3c4[];
extern unsigned char s_mainmap1__grave__0045a2c0[];
extern unsigned char s_GOB_KeepOutOfTiles__ERROR___Your_0045aa9c[];
extern void **PTR_s_rez1_0045a4c8;
int __cdecl FUN_00419C00(int, int, int, int*, int*);
int __cdecl FUN_00428C80(int);
int* __cdecl FUN_004195d0_GameFunctions(int, int, int, int);
void __cdecl FUN_00419BE0(int*, int*);
void __cdecl FUN_00443AE0(int, int, int, int, int, int, int, int, int, int);
}

extern "C" void __cdecl FUN_0042f910_GRAPHICSDRAWING(int *param_1,unsigned int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *paVar4;
  int iVar5;
  int iVar6;
  unsigned int uVar7;
  unsigned int uVar8;
  int *puVar9;
  int *piVar10;
  int iVar11;
  void **ppuVar12;
  int iVar13;
  int iVar14;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  iVar1 = FUN_00419C00((int)param_1,0,0,&local_18,&local_14);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = local_18 + param_1[0];
  _DAT_00463F0C = local_14 + param_1[0];
  local_4 = _DAT_00463F0C + 0;
  local_c = ((-(unsigned int)((param_1[0] & 0x80000000U) == 0) & 0) - 0) + iVar1;
  uVar8 = param_2 + 0;
  if ((int)uVar8 < 0) {
    if ((int)uVar8 < -0) {
      uVar8 = (int)(-param_2 - 0) >> 0;
      iVar2 = ((-param_2 - 0 ^ uVar8) - uVar8 & 0 ^ uVar8) - uVar8;
      if (iVar2 < 0) {
        if (iVar2 < 0) {
          ppuVar12 = (void **)(&_DAT_0045A5C8)[iVar2];
        }
        else {
          ppuVar12 = (void **)(&_DAT_0045A7C8)[-iVar2];
        }
      }
      else if (iVar2 + -0 < 0) {
        ppuVar12 = (void **)-*(int *)(s_sl67_0045a3c4 + iVar2 * 4 + 4);
      }
      else {
        ppuVar12 = (void **)-(&_DAT_0045A9C8)[-iVar2];
      }
    }
    else if ((int)uVar8 < -0) {
      if ((int)(-0 - param_2) < 0) {
        ppuVar12 = (void **)-*(int *)(s_mainmap1__grave__0045a2c0 + param_2 * -4 + 8);
      }
      else {
        ppuVar12 = (void **)
                   -*(int *)(s_GOB_KeepOutOfTiles__ERROR___Your_0045aa9c + param_2 * 4 + 0);
      }
    }
    else if ((int)uVar8 < -0) {
      ppuVar12 = (void **)(&_DAT_0045A8C8)[param_2];
    }
    else {
      ppuVar12 = (&PTR_s_rez1_0045a4c8)[-param_2];
    }
label_0042fb00:
    iVar2 = -(int)ppuVar12;
  }
  else if ((int)uVar8 < 0) {
    if (0 < (int)uVar8) {
      if ((int)(param_2 - 0) < 0) {
        ppuVar12 = (&PTR_s_rez1_0045a4c8)[param_2];
      }
      else {
        ppuVar12 = (void **)(&_DAT_0045A8C8)[-param_2];
      }
      goto label_0042fb00;
    }
    if ((int)uVar8 < 0) {
      iVar2 = (&_DAT_0045A6C8)[param_2];
    }
    else {
      iVar2 = (&_DAT_0045A6C8)[-param_2];
    }
  }
  else {
    uVar7 = (int)uVar8 >> 0;
    iVar2 = ((uVar8 ^ uVar7) - uVar7 & 0 ^ uVar7) - uVar7;
    if (0 < iVar2) {
      if (iVar2 + -0 < 0) {
        ppuVar12 = *(void ***)(s_sl67_0045a3c4 + iVar2 * 4 + 4);
      }
      else {
        ppuVar12 = (void **)(&_DAT_0045A9C8)[-iVar2];
      }
      goto label_0042fb00;
    }
    if (iVar2 < 0) {
      iVar2 = (&_DAT_0045A5C8)[iVar2];
    }
    else {
      iVar2 = (&_DAT_0045A7C8)[-iVar2];
    }
  }
  iVar2 = iVar2 >> 8;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  if ((int)param_2 < 0) {
    if ((int)param_2 < -0) {
      uVar8 = (int)-param_2 >> 0;
      iVar3 = ((-param_2 ^ uVar8) - uVar8 & 0 ^ uVar8) - uVar8;
      if (iVar3 < 0) {
        if (0 < iVar3) {
          piVar10 = &_DAT_0045A7C8 + -iVar3;
          goto label_0042fc64;
        }
        iVar3 = (&_DAT_0045A5C8)[iVar3];
      }
      else if (iVar3 + -0 < 0) {
        iVar3 = -*(int *)(s_sl67_0045a3c4 + iVar3 * 4 + 4);
      }
      else {
        iVar3 = -(&_DAT_0045A9C8)[-iVar3];
      }
    }
    else if ((int)param_2 < -0) {
      if ((int)(-0 - param_2) < 0) {
        iVar3 = -*(int *)(s_sl67_0045a3c4 + param_2 * -4 + 4);
      }
      else {
        iVar3 = -(&_DAT_0045A9C8)[param_2];
      }
    }
    else {
      if (-0 < (int)param_2) {
        puVar9 = &_DAT_0045A5C8;
        goto label_0042fc5f;
      }
      iVar3 = (&_DAT_0045A7C8)[param_2];
    }
  }
  else if ((int)param_2 < 0) {
    if ((int)param_2 < 0) {
      if ((int)param_2 < 0) {
        iVar3 = (&_DAT_0045A5C8)[param_2];
      }
      else {
        iVar3 = (&_DAT_0045A7C8)[-param_2];
      }
      goto label_0042fc68;
    }
    if (0 < (int)(param_2 - 0)) {
      puVar9 = &_DAT_0045A9C8;
label_0042fc5f:
      piVar10 = puVar9 + -param_2;
      goto label_0042fc64;
    }
    iVar3 = *(int *)(s_sl67_0045a3c4 + param_2 * 4 + 4);
  }
  else {
    uVar8 = (int)param_2 >> 0;
    iVar3 = ((param_2 ^ uVar8) - uVar8 & 0 ^ uVar8) - uVar8;
    if (iVar3 < 0) {
      if (iVar3 < 0) {
        iVar3 = (&_DAT_0045A5C8)[iVar3];
      }
      else {
        iVar3 = (&_DAT_0045A7C8)[-iVar3];
      }
      goto label_0042fc68;
    }
    if (iVar3 + -0 < 0) {
      iVar3 = *(int *)(s_sl67_0045a3c4 + iVar3 * 4 + 4);
    }
    else {
      piVar10 = &_DAT_0045A9C8 + -iVar3;
label_0042fc64:
      iVar3 = *piVar10;
    }
  }
  iVar3 = -iVar3;
label_0042fc68:
  iVar3 = ((iVar3 << 8) / iVar2 >> 8) * (0 - _DAT_00463F0C >> 8);
  iVar2 = -iVar3;
  if ((param_1[0] & 0x80000000U) != 0) {
    iVar2 = iVar3;
  }
  iVar2 = iVar2 + iVar1;
  local_10 = iVar2 + -0;
  _DAT_00463F00 = iVar2 + -0;
  _DAT_00463F08 = 0;
  _DAT_00463F04 = iVar1;
  local_18 = iVar1;
  local_14 = _DAT_00463F0C;
  local_8 = _DAT_00463F0C;
  paVar4 = FUN_004195d0_GameFunctions(0x5c,iVar2 + -0,0,_DAT_004A2AD4);
  if (paVar4 != (int *)0) {
    paVar4[0x6c / 4] = paVar4[0x6c / 4] | 0;
    *(int *)&paVar4[0x90 / 4] = 0;
    iVar3 = FUN_00428C80(0);
    *(int *)&paVar4[0x8c / 4] = -iVar3;
    *(int *)&paVar4[0x94 / 4] = 0;
    *(int *)&paVar4[0x50 / 4] = 0;
    *(int *)&paVar4[0x98 / 4] = 6;
    *(int *)&paVar4[0x70 / 4] = 0;
    *(unsigned int *)&paVar4[0xe0 / 4] = *(unsigned int *)&paVar4[0xe0 / 4] | 0;
    FUN_00419BE0((int *)paVar4,param_1);
  }
  if (_DAT_0045B100 < 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (int)(0 / (__int64)(_DAT_0045B100 >> 4));
  }
  iVar3 = iVar3 >> 8;
  iVar5 = ((iVar1 - _DAT_0045B104 >> 8) * iVar3 - DAT_004a2a38_Camera) + _DAT_0045B104 + _DAT_0045B10C;
  iVar14 = ((iVar2 - _DAT_0045B104 >> 8) * iVar3 - DAT_004a2a38_Camera) + _DAT_0045B104 + _DAT_0045B10C
  ;
  iVar6 = ((local_c - _DAT_0045B104 >> 8) * iVar3 - DAT_004a2a38_Camera) + _DAT_0045B104 +
          _DAT_0045B10C;
  iVar11 = ((local_10 - _DAT_0045B104 >> 8) * iVar3 - DAT_004a2a38_Camera) + _DAT_0045B104 +
           _DAT_0045B10C;
  iVar13 = ((local_8 - _DAT_0045B108 >> 8) * iVar3 - _DAT_004A2A1C) + _DAT_0045B110 + _DAT_0045B108;
  iVar1 = ((local_4 - _DAT_0045B108 >> 8) * iVar3 - _DAT_004A2A1C) + _DAT_0045B110 + _DAT_0045B108;
  local_10 = ((0 - _DAT_0045B108 >> 8) * iVar3 - _DAT_004A2A1C) + _DAT_0045B110 + _DAT_0045B108;
  local_c = param_1[0];
  iVar2 = param_1[0];
  local_4 = param_1[0];
  local_8 = param_1[0];
  param_1[0] = 0;
  param_1[0] = 0;
  FUN_00443AE0((int)param_1,0,iVar5,iVar13,iVar6,iVar1,iVar14,local_10,iVar11,local_10);
  param_1[0] = iVar2;
  param_1[0] = local_c;
  param_1[0] = local_8;
  param_1[0] = local_4;
  return;
}
