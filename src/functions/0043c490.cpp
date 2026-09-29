// Adapted from pc_decomp_backup/src/functions/FUN_0043c490.cpp
// Historical source SHA256: 065a78fbe6a908322b5dece816ce802f1db145385d89455fbb43ecfef084cce5
// Provisional behavior candidate; original bytes and gameplay are not claimed to match.
extern "C" {
extern unsigned char s_sl67_0045a3c4[];
extern void **PTR_s_rez1_0045a4c8;
extern unsigned char s_mainmap1__grave__0045a2c0[];
extern unsigned char s_GOB_KeepOutOfTiles__ERROR___Your_0045aa9c[];
void __cdecl FUN_00441150_Flashing(int);
}
extern int _DAT_0045A5C8;
extern int _DAT_0045A6C8;
extern int _DAT_0045A7C8;
extern int _DAT_0045A8C8;
extern int _DAT_0045A9C8;
extern int _DAT_00460028;
extern int _DAT_00460030;
extern int _DAT_00464E0C;
extern int _DAT_00464E14;
extern int _DAT_00464E1C;

extern "C" void __cdecl ob261Draw_0043c490(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *puVar4;
  int iVar5;
  int uVar6;
  int iVar7;
  unsigned int uVar8;
  unsigned int uVar9;
  void ***pppuVar10;
  unsigned int uVar11;
  void **ppuVar12;
  uVar11 = *(unsigned int *)(param_1 + 0);
  uVar8 = (_DAT_00464E0C << 3) >> 0;
  if ((int)uVar11 < 0) {
    if ((int)uVar11 < -0) {
      uVar9 = (int)-uVar11 >> 0;
      iVar1 = ((-uVar11 ^ uVar9) - uVar9 & 0 ^ uVar9) - uVar9;
      if (iVar1 < 0) {
        if (iVar1 < 0) {
          iVar1 = (&_DAT_0045A5C8)[iVar1];
        }
        else {
          iVar1 = (&_DAT_0045A7C8)[-iVar1];
        }
      }
      else if (iVar1 + -0 < 0) {
        iVar1 = -*(int *)(s_sl67_0045a3c4 + iVar1 * 4 + 4);
      }
      else {
        iVar1 = -(&_DAT_0045A9C8)[-iVar1];
      }
    }
    else if ((int)uVar11 < -0) {
      if ((int)(-0 - uVar11) < 0) {
        iVar1 = -*(int *)(s_sl67_0045a3c4 + uVar11 * -4 + 4);
      }
      else {
        iVar1 = -(&_DAT_0045A9C8)[uVar11];
      }
    }
    else {
      if (-0 < (int)uVar11) {
        puVar4 = &_DAT_0045A5C8;
        goto label_0043c610;
      }
      iVar1 = (&_DAT_0045A7C8)[uVar11];
    }
label_0043c61b:
    iVar1 = -iVar1;
  }
  else if ((int)uVar11 < 0) {
    if (0 < (int)uVar11) {
      if ((int)(uVar11 - 0) < 0) {
        iVar1 = *(int *)(s_sl67_0045a3c4 + uVar11 * 4 + 4);
      }
      else {
        puVar4 = &_DAT_0045A9C8;
label_0043c610:
        iVar1 = puVar4[-uVar11];
      }
      goto label_0043c61b;
    }
    if ((int)uVar11 < 0) {
      iVar1 = (&_DAT_0045A5C8)[uVar11];
    }
    else {
      iVar1 = (&_DAT_0045A7C8)[-uVar11];
    }
  }
  else {
    uVar9 = (int)uVar11 >> 0;
    iVar1 = ((uVar11 ^ uVar9) - uVar9 & 0 ^ uVar9) - uVar9;
    if (0 < iVar1) {
      if (iVar1 + -0 < 0) {
        iVar1 = *(int *)(s_sl67_0045a3c4 + iVar1 * 4 + 4);
      }
      else {
        iVar1 = (&_DAT_0045A9C8)[-iVar1];
      }
      goto label_0043c61b;
    }
    if (iVar1 < 0) {
      iVar1 = (&_DAT_0045A5C8)[iVar1];
    }
    else {
      iVar1 = (&_DAT_0045A7C8)[-iVar1];
    }
  }
  iVar7 = (int)(_DAT_00460028 + ((_DAT_00464E0C << 3 ^ uVar8) - uVar8)) >> 8;
  uVar8 = uVar11 + 0;
  if ((int)uVar8 < 0) {
    if ((int)uVar8 < -0) {
      uVar8 = (int)(-uVar11 - 0) >> 0;
      iVar2 = ((-uVar11 - 0 ^ uVar8) - uVar8 & 0 ^ uVar8) - uVar8;
      if (iVar2 < 0) {
        if (iVar2 < 0) {
          ppuVar12 = (void **)(&_DAT_0045A5C8)[iVar2];
        }
        else {
          iVar2 = iVar2 * 4;
          pppuVar10 = (void ***)&_DAT_0045A7C8;
label_0043c78e:
          ppuVar12 = *(void ***)((int)pppuVar10 - iVar2);
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
      if ((int)(-0 - uVar11) < 0) {
        ppuVar12 = (void **)-*(int *)(s_mainmap1__grave__0045a2c0 + uVar11 * -4 + 8);
      }
      else {
        ppuVar12 = (void **)
                   -*(int *)(s_GOB_KeepOutOfTiles__ERROR___Your_0045aa9c + uVar11 * 4 + 0);
      }
    }
    else {
      if (-0 < (int)uVar8) {
        pppuVar10 = &PTR_s_rez1_0045a4c8;
        iVar2 = uVar11 * 4;
        goto label_0043c78e;
      }
      ppuVar12 = (void **)(&_DAT_0045A8C8)[uVar11];
    }
label_0043c792:
    iVar2 = -(int)ppuVar12;
  }
  else if ((int)uVar8 < 0) {
    if (0 < (int)uVar8) {
      if ((int)(uVar11 - 0) < 0) {
        ppuVar12 = (&PTR_s_rez1_0045a4c8)[uVar11];
      }
      else {
        ppuVar12 = (void **)(&_DAT_0045A8C8)[-uVar11];
      }
      goto label_0043c792;
    }
    if ((int)uVar8 < 0) {
      iVar2 = (&_DAT_0045A6C8)[uVar11];
    }
    else {
      iVar2 = (&_DAT_0045A6C8)[-uVar11];
    }
  }
  else {
    uVar9 = (int)uVar8 >> 0;
    iVar2 = ((uVar8 ^ uVar9) - uVar9 & 0 ^ uVar9) - uVar9;
    if (0 < iVar2) {
      if (0 < iVar2 + -0) {
        iVar2 = iVar2 * 4;
        pppuVar10 = (void ***)&_DAT_0045A9C8;
        goto label_0043c78e;
      }
      ppuVar12 = *(void ***)(s_sl67_0045a3c4 + iVar2 * 4 + 4);
      goto label_0043c792;
    }
    if (iVar2 < 0) {
      iVar2 = (&_DAT_0045A5C8)[iVar2];
    }
    else {
      iVar2 = (&_DAT_0045A7C8)[-iVar2];
    }
  }
  if ((int)_DAT_00460030 < 0) {
    if ((int)_DAT_00460030 < -0) {
      uVar8 = (int)-_DAT_00460030 >> 0;
      iVar3 = ((-_DAT_00460030 ^ uVar8) - uVar8 & 0 ^ uVar8) - uVar8;
      if (iVar3 < 0) {
        if (iVar3 < 0) {
          iVar3 = (&_DAT_0045A5C8)[iVar3];
        }
        else {
          iVar3 = (&_DAT_0045A7C8)[-iVar3];
        }
      }
      else if (iVar3 + -0 < 0) {
        iVar3 = -*(int *)(s_sl67_0045a3c4 + iVar3 * 4 + 4);
      }
      else {
        iVar3 = -(&_DAT_0045A9C8)[-iVar3];
      }
    }
    else if ((int)_DAT_00460030 < -0) {
      if ((int)(-0 - _DAT_00460030) < 0) {
        iVar3 = -*(int *)("" + _DAT_00460030 * -4 + 4);
      }
      else {
        iVar3 = -(&_DAT_0045A9C8)[_DAT_00460030];
      }
    }
    else {
      if (-0 < (int)_DAT_00460030) {
        puVar4 = &_DAT_0045A5C8;
        goto label_0043c927;
      }
      iVar3 = (&_DAT_0045A7C8)[_DAT_00460030];
    }
label_0043c934:
    iVar3 = -iVar3;
  }
  else if ((int)_DAT_00460030 < 0) {
    if (0 < (int)_DAT_00460030) {
      if ((int)(_DAT_00460030 - 0) < 0) {
        iVar3 = *(int *)("" + _DAT_00460030 * 4 + 4);
      }
      else {
        puVar4 = &_DAT_0045A9C8;
label_0043c927:
        iVar3 = puVar4[-_DAT_00460030];
      }
      goto label_0043c934;
    }
    if ((int)_DAT_00460030 < 0) {
      iVar3 = (&_DAT_0045A5C8)[_DAT_00460030];
    }
    else {
      iVar3 = (&_DAT_0045A7C8)[-_DAT_00460030];
    }
  }
  else {
    uVar8 = (int)_DAT_00460030 >> 0;
    iVar3 = ((_DAT_00460030 ^ uVar8) - uVar8 & 0 ^ uVar8) - uVar8;
    if (0 < iVar3) {
      if (iVar3 + -0 < 0) {
        iVar3 = *(int *)(s_sl67_0045a3c4 + iVar3 * 4 + 4);
      }
      else {
        iVar3 = (&_DAT_0045A9C8)[-iVar3];
      }
      goto label_0043c934;
    }
    if (iVar3 < 0) {
      iVar3 = (&_DAT_0045A5C8)[iVar3];
    }
    else {
      iVar3 = (&_DAT_0045A7C8)[-iVar3];
    }
  }
  iVar1 = (iVar1 >> 8) * iVar7 >> 8;
  uVar8 = _DAT_00460030 + 0;
  if ((int)uVar8 < 0) {
    if ((int)uVar8 < -0) {
      uVar8 = (int)(-_DAT_00460030 - 0) >> 0;
      iVar5 = ((-_DAT_00460030 - 0 ^ uVar8) - uVar8 & 0 ^ uVar8) - uVar8;
      if (iVar5 < 0) {
        if (iVar5 < 0) {
          ppuVar12 = (void **)(&_DAT_0045A5C8)[iVar5];
        }
        else {
          ppuVar12 = (void **)(&_DAT_0045A7C8)[-iVar5];
        }
      }
      else if (iVar5 + -0 < 0) {
        ppuVar12 = (void **)-*(int *)(s_sl67_0045a3c4 + iVar5 * 4 + 4);
      }
      else {
        ppuVar12 = (void **)-(&_DAT_0045A9C8)[-iVar5];
      }
    }
    else if ((int)uVar8 < -0) {
      if ((int)(-0 - _DAT_00460030) < 0) {
        ppuVar12 = (void **)-*(int *)("" + _DAT_00460030 * -4 + 8);
      }
      else {
        ppuVar12 = (void **)
                   -*(int *)("" + _DAT_00460030 * 4 + 0);
      }
    }
    else {
      if (-0 < (int)uVar8) {
        pppuVar10 = &PTR_s_rez1_0045a4c8;
        goto label_0043cac7;
      }
      ppuVar12 = (void **)(&_DAT_0045A8C8)[_DAT_00460030];
    }
  }
  else if ((int)uVar8 < 0) {
    if ((int)uVar8 < 0) {
      if ((int)uVar8 < 0) {
        iVar5 = (&_DAT_0045A6C8)[_DAT_00460030];
      }
      else {
        iVar5 = (&_DAT_0045A6C8)[-_DAT_00460030];
      }
      goto label_0043cad6;
    }
    if ((int)(_DAT_00460030 - 0) < 0) {
      ppuVar12 = (&PTR_s_rez1_0045a4c8)[_DAT_00460030];
    }
    else {
      pppuVar10 = (void ***)&_DAT_0045A8C8;
label_0043cac7:
      ppuVar12 = pppuVar10[-_DAT_00460030];
    }
  }
  else {
    uVar9 = (int)uVar8 >> 0;
    iVar5 = ((uVar8 ^ uVar9) - uVar9 & 0 ^ uVar9) - uVar9;
    if (iVar5 < 0) {
      if (iVar5 < 0) {
        iVar5 = (&_DAT_0045A5C8)[iVar5];
      }
      else {
        iVar5 = (&_DAT_0045A7C8)[-iVar5];
      }
      goto label_0043cad6;
    }
    if (iVar5 + -0 < 0) {
      ppuVar12 = *(void ***)(s_sl67_0045a3c4 + iVar5 * 4 + 4);
    }
    else {
      ppuVar12 = (void **)(&_DAT_0045A9C8)[-iVar5];
    }
  }
  iVar5 = -(int)ppuVar12;
label_0043cad6:
  uVar6 = 0;
  iVar5 = 0 - ((iVar5 >> 8) * iVar1 >> 7);
  if (0 < iVar5) {
    uVar6 = (int)(0 / (__int64)(iVar5 >> 4));
  }
  *(int *)(param_1 + 200) = uVar6;
  *(int *)(param_1 + 0) = uVar6;
  *(int *)(param_1 + 0) = *(int *)(_DAT_00464E14 + 0) + (iVar2 >> 8) * iVar7;
  *(int *)(param_1 + 0) = *(int *)(_DAT_00464E14 + 0) + (iVar3 >> 8) * iVar1 + _DAT_00464E1C;
  uVar8 = *(int *)(param_1 + 0) - 1;
  *(unsigned int *)(param_1 + 0) = uVar8;
  if ((int)uVar8 < 0) {
    FUN_00441150_Flashing(param_1);
    if ((0 < (int)uVar11) && ((int)uVar11 < 0)) {
      uVar6 = *(int *)(param_1 + 0);
      *(int *)(param_1 + 0) = 0;
      FUN_00441150_Flashing(param_1);
      *(int *)(param_1 + 0) = uVar6;
      return;
    }
  }
  else {
    uVar11 = (int)uVar8 >> 0;
    if (((uVar8 ^ uVar11) - uVar11 & 1 ^ uVar11) != uVar11) {
      FUN_00441150_Flashing(param_1);
      return;
    }
    uVar6 = *(int *)(param_1 + 0);
    *(int *)(param_1 + 0) = 0;
    FUN_00441150_Flashing(param_1);
    *(int *)(param_1 + 0) = uVar6;
  }
  return;
}
