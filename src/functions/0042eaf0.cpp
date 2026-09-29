// Adapted from pc_decomp_backup/src/functions/FUN_0042eaf0.cpp
// Historical source SHA256: 25f9416dae8a2df97c671c27f1c536ec51d4a566130ad15765a8099aaa2e780e
// Provisional behavior candidate; original bytes and gameplay are not claimed to match.
extern "C" {
extern int DAT_004a2a38_Camera;
int __cdecl FUN_0042E720(int, unsigned int);
int __cdecl FUN_0042E750(int, unsigned int);
void __cdecl FUN_0042E780(int);
void __cdecl FUN_0042E930(int, int, int, int);
void __cdecl FUN_0042EA10(int, int, int, int);
}
extern int _DAT_0045B100;
extern int _DAT_0045B104;
extern int _DAT_0045B108;
extern int _DAT_0045B10C;
extern int _DAT_0045B110;
extern int _DAT_0045B114;
extern int _DAT_0045B118;
extern int _DAT_0045B11C;
extern int _DAT_00463E0C;
extern int _DAT_00463E18;
extern int _DAT_00463E54;
extern int _DAT_00463E58;
extern int _DAT_00463E94;
extern int _DAT_00463F10;
extern int _DAT_00463F14;
extern int _DAT_00463F98;
extern int _DAT_00463FA0;
extern int _DAT_00463FDC;
extern int _DAT_00463FE0;
extern int _DAT_004A2A1C;

extern "C" void __cdecl FUN_0042eaf0_GRAPHICSDRAWING(int param_1,int param_2,int param_3)
{
  int uVar1;
  int uVar2;
  int uVar3;
  int uVar4;
  int uVar5;
  int uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  unsigned int uVar10;
  int iVar11;
  int iVar12;
  int *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int local_28;
  int local_24;
  int local_20;
  int local_8;
  _DAT_0045B100 = 0;
  uVar1 = *(int *)(param_1 + 0);
  local_20 = *(int *)(param_1 + 0);
  uVar2 = *(int *)(param_1 + 200);
  uVar3 = *(int *)(param_1 + 0);
  uVar4 = *(int *)(param_1 + 0);
  uVar5 = *(int *)(param_1 + 0);
  FUN_0042E780(param_1);
  iVar8 = *(int *)(param_1 + 0);
  iVar11 = *(int *)(param_1 + 0);
  *(int *)(param_1 + 0) = uVar4;
  *(int *)(param_1 + 0) = uVar5;
  *(int *)(param_1 + 0) = uVar1;
  *(int *)(param_1 + 0) = local_20;
  *(int *)(param_1 + 200) = uVar2;
  *(int *)(param_1 + 0) = uVar3;
  iVar16 = iVar8;
  local_28 = iVar11;
  if (param_2 != 0) {
    uVar1 = *(int *)(param_2 + 0);
    uVar2 = *(int *)(param_2 + 0);
    uVar3 = *(int *)(param_2 + 200);
    uVar4 = *(int *)(param_2 + 0);
    local_20 = *(int *)(param_2 + 0);
    uVar5 = *(int *)(param_2 + 0);
    FUN_0042E780(param_2);
    iVar16 = *(int *)(param_2 + 0);
    local_28 = *(int *)(param_2 + 0);
    *(int *)(param_2 + 0) = local_20;
    *(int *)(param_2 + 0) = uVar5;
    *(int *)(param_2 + 0) = uVar1;
    *(int *)(param_2 + 0) = uVar2;
    *(int *)(param_2 + 200) = uVar3;
    *(int *)(param_2 + 0) = uVar4;
  }
  iVar12 = local_28;
  if (param_3 == 0) {
    iVar14 = iVar8 + iVar16 >> 1;
    iVar15 = iVar11 + local_28 >> 1;
  }
  else {
    uVar1 = *(int *)(param_3 + 0);
    uVar2 = *(int *)(param_3 + 0);
    uVar3 = *(int *)(param_3 + 200);
    uVar4 = *(int *)(param_3 + 0);
    local_20 = *(int *)(param_3 + 0);
    uVar5 = *(int *)(param_3 + 0);
    FUN_0042E780(param_3);
    iVar14 = *(int *)(param_3 + 0);
    iVar15 = *(int *)(param_3 + 0);
    *(int *)(param_3 + 0) = local_20;
    *(int *)(param_3 + 0) = uVar5;
    *(int *)(param_3 + 0) = uVar1;
    *(int *)(param_3 + 0) = uVar2;
    *(int *)(param_3 + 200) = uVar3;
    *(int *)(param_3 + 0) = uVar4;
  }
  if ((iVar8 < iVar16) && (iVar16 < iVar14)) {
    local_8 = 1;
    iVar7 = iVar14 - iVar8;
  }
  else if ((iVar14 < iVar8) || (iVar16 < iVar14)) {
    if ((iVar8 < iVar16) || (iVar14 < iVar8)) {
      if (iVar14 < iVar16) {
        if ((iVar8 < iVar14) || (iVar16 < iVar8)) goto label_0042ed13;
        local_8 = 5;
        iVar7 = iVar16 - iVar14;
      }
      else if (iVar8 < iVar14) {
label_0042ed13:
        iVar7 = local_20;
        if ((iVar14 <= iVar16) && (iVar16 <= iVar8)) {
          local_8 = 6;
          iVar7 = iVar8 - iVar14;
        }
      }
      else {
        local_8 = 4;
        iVar7 = iVar8 - iVar16;
      }
    }
    else {
      local_8 = 3;
      iVar7 = iVar14 - iVar16;
    }
  }
  else {
    local_8 = 2;
    iVar7 = iVar16 - iVar8;
  }
  if ((local_28 < iVar11) || (iVar15 < local_28)) {
    if ((iVar15 < iVar11) || (local_28 < iVar15)) {
      if ((iVar11 < local_28) || (iVar15 < iVar11)) {
        if (iVar15 < local_28) {
          if ((iVar11 < iVar15) || (local_28 < iVar11)) goto label_0042edd3;
          local_28 = 5;
          local_20 = iVar12 - iVar15;
        }
        else if (iVar11 < iVar15) {
label_0042edd3:
          if ((iVar15 <= local_28) && (local_28 <= iVar11)) {
            local_28 = 6;
            local_20 = iVar11 - iVar15;
          }
        }
        else {
          local_28 = 4;
          local_20 = iVar11 - iVar12;
        }
      }
      else {
        local_28 = 3;
        local_20 = iVar15 - iVar12;
      }
    }
    else {
      local_28 = 2;
      local_20 = iVar12 - iVar11;
    }
  }
  else {
    local_28 = 1;
    local_20 = iVar15 - iVar11;
  }
  _DAT_0045B100 = local_20 / 0;
  if (_DAT_0045B100 < iVar7 / 0) {
    local_24 = 1;
    _DAT_0045B100 = iVar7 / 0;
  }
  else {
    local_24 = 2;
  }
  if (_DAT_0045B100 < 0) {
    local_24 = 0;
  }
  if (_DAT_0045B11C < _DAT_0045B100) {
    _DAT_0045B100 = _DAT_0045B11C;
  }
  else if (_DAT_0045B100 < _DAT_0045B118) {
    _DAT_0045B100 = _DAT_0045B118;
  }
  iVar8 = 0;
  puVar13 = &_DAT_00463FA0;
  do {
    iVar8 = iVar8 + -1;
    *puVar13 = puVar13[1];
    _DAT_00463FDC = _DAT_0045B100;
    puVar13 = puVar13 + 1;
  } while (iVar8 != 0);
  _DAT_0045B100 = 0;
  piVar9 = &_DAT_00463FA0;
  do {
    _DAT_0045B100 = _DAT_0045B100 + *piVar9;
    piVar9 = piVar9 + 1;
  } while (piVar9 < &_DAT_00463FE0);
  _DAT_0045B100 = _DAT_0045B100 >> 4;
  uVar1 = *(int *)(param_1 + 0);
  uVar2 = *(int *)(param_1 + 0);
  uVar3 = *(int *)(param_1 + 0);
  uVar4 = *(int *)(param_1 + 200);
  uVar5 = *(int *)(param_1 + 0);
  uVar6 = *(int *)(param_1 + 0);
  FUN_0042E780(param_1);
  iVar8 = *(int *)(param_1 + 0);
  iVar11 = *(int *)(param_1 + 0);
  *(int *)(param_1 + 0) = uVar5;
  *(int *)(param_1 + 0) = uVar6;
  *(int *)(param_1 + 0) = uVar2;
  *(int *)(param_1 + 0) = uVar3;
  *(int *)(param_1 + 200) = uVar4;
  *(int *)(param_1 + 0) = uVar1;
  iVar12 = iVar11;
  iVar16 = iVar8;
  if (param_2 != 0) {
    uVar1 = *(int *)(param_2 + 0);
    uVar2 = *(int *)(param_2 + 0);
    uVar3 = *(int *)(param_2 + 200);
    uVar4 = *(int *)(param_2 + 0);
    uVar5 = *(int *)(param_2 + 0);
    uVar6 = *(int *)(param_2 + 0);
    FUN_0042E780(param_2);
    iVar16 = *(int *)(param_2 + 0);
    iVar12 = *(int *)(param_2 + 0);
    *(int *)(param_2 + 0) = uVar5;
    *(int *)(param_2 + 0) = uVar6;
    *(int *)(param_2 + 0) = uVar1;
    *(int *)(param_2 + 0) = uVar2;
    *(int *)(param_2 + 200) = uVar3;
    *(int *)(param_2 + 0) = uVar4;
  }
  if (param_3 == 0) {
    iVar14 = iVar8 + iVar16 >> 1;
    iVar15 = iVar11 + iVar12 >> 1;
  }
  else {
    uVar1 = *(int *)(param_3 + 0);
    uVar2 = *(int *)(param_3 + 0);
    uVar3 = *(int *)(param_3 + 200);
    uVar4 = *(int *)(param_3 + 0);
    uVar5 = *(int *)(param_3 + 0);
    uVar6 = *(int *)(param_3 + 0);
    FUN_0042E780(param_3);
    iVar14 = *(int *)(param_3 + 0);
    iVar15 = *(int *)(param_3 + 0);
    *(int *)(param_3 + 0) = uVar5;
    *(int *)(param_3 + 0) = uVar6;
    *(int *)(param_3 + 0) = uVar1;
    *(int *)(param_3 + 0) = uVar2;
    *(int *)(param_3 + 200) = uVar3;
    *(int *)(param_3 + 0) = uVar4;
  }
  if ((_DAT_0045B118 < _DAT_0045B100) || (_DAT_0045B118 == _DAT_0045B11C)) {
    if (local_24 != 1) {
      if (local_24 == 2) {
        switch(local_28) {
        case 1:
        case 2:
          _DAT_004A2A1C = iVar11 + -0;
          break;
        case 3:
          if (iVar15 - iVar12 < 0) {
            _DAT_004A2A1C = iVar12 + -0;
          }
          else if (iVar11 - iVar12 < 0) {
            _DAT_004A2A1C = iVar12 + -0;
          }
          else {
            _DAT_004A2A1C = iVar11 + -0;
          }
          break;
        case 4:
        case 6:
          _DAT_004A2A1C = iVar11 + -0;
          break;
        case 5:
          if ((iVar12 - iVar15 < 0) || (iVar11 - iVar15 < 0)) {
            _DAT_004A2A1C = iVar15 + -0;
          }
          else {
            _DAT_004A2A1C = iVar11 + -0;
          }
        }
        FUN_0042E930(iVar8,iVar16,iVar14,local_8);
        goto label_0042f234;
      }
      goto label_0042f20f;
    }
    switch(local_8) {
    case 1:
    case 2:
      DAT_004a2a38_Camera = iVar8 + -0;
      break;
    case 3:
      if (iVar14 - iVar16 < 0) {
        DAT_004a2a38_Camera = iVar16 + -0;
      }
      else if (iVar8 - iVar16 < 0) {
        DAT_004a2a38_Camera = iVar16 + -0;
      }
      else {
        DAT_004a2a38_Camera = iVar8 + -0;
      }
      break;
    case 4:
    case 6:
      DAT_004a2a38_Camera = iVar8 + -0;
      break;
    case 5:
      if ((iVar16 - iVar14 < 0) || (iVar8 - iVar14 < 0)) {
        DAT_004a2a38_Camera = iVar14 + -0;
      }
      else {
        DAT_004a2a38_Camera = iVar8 + -0;
      }
    }
  }
  else {
label_0042f20f:
    FUN_0042E930(iVar8,iVar16,iVar14,local_8);
  }
  FUN_0042EA10(iVar11,iVar12,iVar15,local_28);
label_0042f234:
  if (_DAT_0045B100 < 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = (unsigned int)(0 / (__int64)(_DAT_0045B100 >> 4));
  }
  iVar16 = (int)uVar10 >> 8;
  iVar11 = (0 - _DAT_0045B104 >> 8) * iVar16 + _DAT_0045B104;
  iVar8 = (0 - _DAT_0045B108 >> 8) * iVar16 + _DAT_0045B108;
  if ((DAT_004a2a38_Camera < iVar11) || (_DAT_0045B114 == 0)) {
    DAT_004a2a38_Camera = iVar11;
  }
  iVar11 = (0 - _DAT_0045B104 >> 8) * iVar16 + _DAT_0045B104 + -0;
  if ((iVar11 < DAT_004a2a38_Camera) || (_DAT_0045B114 == 0)) {
    DAT_004a2a38_Camera = iVar11;
  }
  if ((iVar8 <= _DAT_004A2A1C) &&
     (iVar11 = (0 - _DAT_0045B108 >> 8) * iVar16 + _DAT_0045B108 + -0,
     iVar8 = _DAT_004A2A1C, iVar11 < _DAT_004A2A1C)) {
    iVar8 = iVar11;
  }
  _DAT_004A2A1C = iVar8;
  _DAT_0045B104 = FUN_0042E720(DAT_004a2a38_Camera + 0,uVar10);
  _DAT_0045B108 = FUN_0042E750(_DAT_004A2A1C + 0,uVar10);
  iVar8 = 4;
  do {
    *(int *)(&_DAT_00463E54 + iVar8) = *(int *)((int)&_DAT_00463E58 + iVar8);
    *(int *)(iVar8 + 0) = *(int *)((int)&_DAT_00463E18 + iVar8);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0);
  _DAT_00463E94 = _DAT_0045B104;
  _DAT_00463E54 = _DAT_0045B108;
  iVar8 = 0;
  _DAT_0045B104 = 0;
  _DAT_0045B108 = 0;
  do {
    _DAT_0045B104 = _DAT_0045B104 + *(int *)((int)&_DAT_00463E58 + iVar8);
    _DAT_0045B108 = _DAT_0045B108 + *(int *)((int)&_DAT_00463E18 + iVar8);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0);
  _DAT_0045B104 = _DAT_0045B104 >> 4;
  _DAT_0045B108 = _DAT_0045B108 >> 4;
  iVar12 = _DAT_0045B104 + -0;
  iVar8 = _DAT_0045B108 + -0;
  iVar14 = (0 - _DAT_0045B104 >> 8) * iVar16 + _DAT_0045B104;
  iVar11 = (0 - _DAT_0045B104 >> 8) * iVar16 + _DAT_0045B104;
  if ((iVar14 < iVar12) || (_DAT_0045B104 + 0 <= iVar14)) {
    if ((iVar11 < iVar12) || (_DAT_0045B104 + 0 <= iVar11)) {
      iVar14 = iVar12 - iVar14;
      iVar11 = (iVar11 - iVar12) + iVar14 + -0 >> 0;
      if (iVar11 != 0) {
        iVar14 = iVar14 / iVar11;
      }
      iVar14 = (iVar14 >> 8) * 0 + 0;
      iVar11 = iVar12;
    }
    else {
      iVar14 = 0;
    }
    _DAT_0045B10C = iVar14 - iVar11;
  }
  else {
    _DAT_0045B10C = 0 - iVar14;
  }
  iVar14 = (0 - _DAT_0045B108 >> 8) * iVar16;
  iVar11 = iVar14 + _DAT_0045B108;
  if ((iVar11 < iVar8) || (_DAT_0045B108 + 0 <= iVar11)) {
    iVar16 = iVar8 - ((0 - _DAT_0045B108 >> 8) * iVar16 + _DAT_0045B108);
    iVar11 = (iVar16 - iVar8) + iVar11 + -0 >> 0;
    if (iVar11 != 0) {
      iVar16 = iVar16 / iVar11;
    }
    iVar14 = (iVar16 >> 8) * 0 + 0;
    iVar11 = iVar8;
  }
  else {
    iVar14 = 0 - iVar14;
    iVar11 = _DAT_0045B108;
  }
  _DAT_0045B110 = iVar14 - iVar11;
  DAT_004a2a38_Camera = iVar12 + _DAT_0045B10C;
  _DAT_004A2A1C = iVar8 + (iVar14 - iVar11);
  iVar8 = 0;
  if ((DAT_004a2a38_Camera < 0) || (iVar8 = 0, 0 < DAT_004a2a38_Camera)) {
    DAT_004a2a38_Camera = iVar8;
  }
  iVar8 = 0;
  if ((_DAT_004A2A1C < 0) || (iVar8 = 0, 0 < _DAT_004A2A1C)) {
    _DAT_004A2A1C = iVar8;
  }
  _DAT_00463F10 = DAT_004a2a38_Camera;
  _DAT_00463F98 = DAT_004a2a38_Camera + 0;
  _DAT_00463F14 = _DAT_004A2A1C;
  _DAT_00463E0C = _DAT_004A2A1C + 0;
  return;
}
