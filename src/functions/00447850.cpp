// Adapted from pc_decomp_backup/src/functions/FUN_00447850.cpp
// Historical source SHA256: 3c3fdd9f1c96e4c2352c8a9ecdd96f0b635e4ce190e497c6efb41613d3758c91
// Behavior candidate; original bytes are not claimed to match.

extern "C" {
extern int DAT_004610cc;
extern int DAT_004a2b24;
extern int DAT_004a2b28;
extern int DAT_004a2b2c;
extern int DAT_004a2b34;
extern int DAT_004a2b38;
extern int DAT_004a2b3c;
extern int DAT_004a2b40;
extern unsigned int* DAT_004a2f54;
extern unsigned int DAT_004a2f58;
extern unsigned int DAT_004a2f5c;
extern int DAT_004a2f60;
extern int DAT_004a2f64;
extern int DAT_004a2f68;
extern int DAT_004a2f78;
extern int DAT_004a2f88;
extern int DAT_004a2f8c;
extern int DAT_004a33a4;
extern int DAT_004a33a8;
extern int DAT_004a33ac;

void __cdecl FUN_00448560(int, int, int, unsigned int, int, unsigned int, unsigned int, int);
}

static int CARRY4(unsigned int left, unsigned int right) { return left + right < left; }

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

extern "C" void __cdecl FUN_00447850_InnerGraphicsTiles3(int param_1,int param_2)

{
  int *piVar1;
  unsigned int uVar2;
  int iVar3;
  unsigned int uVar4;
  int iVar5;
  unsigned int uVar6;
  int iVar7;
  int iVar8;
  unsigned int uVar9;
  int iVar10;
  unsigned int *puVar11;
  int bVar12;
  unsigned int uVar13;
  int local_80 [19];
  int local_34;
  int local_30;
  int local_2c;
  int local_24;
  unsigned int local_20;
  int local_1c;
  unsigned int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;

  iVar5 = 0;
  iVar10 = 0;
  uVar2 = (int)*(short *)(param_1 + 0x20) - (int)*(short *)(param_1 + 8);
  uVar6 = (int)uVar2 >> 0x1f;
  DAT_004a2f8c = (uVar2 ^ uVar6) - uVar6;
  uVar2 = (int)*(short *)(param_1 + 0x22) - (int)*(short *)(param_1 + 10);
  uVar6 = (int)uVar2 >> 0x1f;
  DAT_004a2f88 = (uVar2 ^ uVar6) - uVar6;
  if (((((DAT_004a2f8c < 1) || (DAT_004a2f88 < 1)) ||
       (*(short *)(param_1 + 0x18) != *(short *)(param_1 + 8))) ||
      ((*(short *)(param_1 + 0x10) != *(short *)(param_1 + 0x20) ||
       (*(short *)(param_1 + 0x12) != *(short *)(param_1 + 10))))) ||
     (*(short *)(param_1 + 0x1a) != *(short *)(param_1 + 0x22))) {
    local_80[1] = (int)*(short *)(param_1 + 10);
    local_80[0] = (int)*(short *)(param_1 + 8);
    local_80[4] = (int)*(short *)(param_1 + 0x10);
    local_80[5] = (int)*(short *)(param_1 + 0x12);
    local_80[2] = (unsigned int)*(unsigned char *)(param_1 + 0xc);
    local_80[3] = (unsigned int)*(unsigned char *)(param_1 + 0xd);
    if (*(unsigned char *)(param_1 + 0x14) == 0) {
      local_80[6] = 0x100;
    }
    else {
      local_80[6] = (unsigned int)*(unsigned char *)(param_1 + 0x14);
    }
    local_80[9] = (int)*(short *)(param_1 + 0x1a);
    local_80[8] = (int)*(short *)(param_1 + 0x18);
    local_80[7] = (unsigned int)*(unsigned char *)(param_1 + 0x15);
    local_80[10] = (unsigned int)*(unsigned char *)(param_1 + 0x1c);
    if (*(unsigned char *)(param_1 + 0x1d) == 0) {
      local_80[0xb] = 0x100;
    }
    else {
      local_80[0xb] = (unsigned int)*(unsigned char *)(param_1 + 0x1d);
    }
    local_80[0xc] = (int)*(short *)(param_1 + 0x20);
    local_80[0xd] = (int)*(short *)(param_1 + 0x22);
    if (*(unsigned char *)(param_1 + 0x24) == 0) {
      local_80[0xe] = 0x100;
    }
    else {
      local_80[0xe] = (unsigned int)*(unsigned char *)(param_1 + 0x24);
    }
    if (*(unsigned char *)(param_1 + 0x25) == 0) {
      local_80[0xf] = 0x100;
    }
    else {
      local_80[0xf] = (unsigned int)*(unsigned char *)(param_1 + 0x25);
    }
    iVar5 = local_80[1];
    if (local_80[5] < local_80[1]) {
      iVar5 = local_80[5];
    }
    uVar2 = (unsigned int)(local_80[5] < local_80[1]);
    if (local_80[9] < iVar5) {
      uVar2 = 2;
      iVar5 = local_80[9];
    }
    if (*(short *)(param_1 + 0x22) < iVar5) {
      uVar2 = 3;
    }
    if (uVar2 == 0) {
      uVar6 = 1;
    }
    else {
      uVar6 = 3;
      if (uVar2 != 1) {
        uVar6 = -(unsigned int)(uVar2 == 3) & 2;
      }
    }
    uVar9 = uVar2;
    if (local_80[uVar6 * 4 + 1] == local_80[uVar2 * 4 + 1]) {
      if (uVar2 == 0) {
        uVar9 = 1;
      }
      else if (uVar2 == 1) {
        uVar9 = 3;
      }
      else {
        uVar9 = -(unsigned int)(uVar2 == 3) & 2;
      }
    }
    if (uVar2 == 0) {
      uVar6 = 2;
    }
    else {
      uVar6 = 3;
      if (uVar2 != 2) {
        uVar6 = (unsigned int)(uVar2 == 3);
      }
    }
    if (local_80[uVar6 * 4 + 1] == local_80[uVar2 * 4 + 1]) {
      if (uVar2 == 0) {
        uVar2 = 2;
      }
      else if (uVar2 == 2) {
        uVar2 = 3;
      }
      else {
        uVar2 = (unsigned int)(uVar2 == 3);
      }
    }
    if (uVar9 == 0) {
      uVar6 = 1;
    }
    else {
      uVar6 = 3;
      if (uVar9 != 1) {
        uVar6 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_8 = local_80[uVar9 * 4 + 1];
    if (local_80[uVar6 * 4 + 1] == local_8) {
      return;
    }
    uVar6 = local_8 << 0x10;
    local_14 = local_80[uVar9 * 4] << 0x10;
    local_24 = local_80[uVar9 * 4 + 2] << 0x10;
    local_20 = local_80[uVar9 * 4 + 3] << 0x10;
    if (uVar9 == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 3;
      if (uVar9 != 1) {
        uVar4 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_8 = local_80[uVar4 * 4 + 1] - local_8;
    if (uVar9 == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 3;
      if (uVar9 != 1) {
        uVar4 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_80[0x10] = ((local_80[uVar4 * 4] - local_80[uVar9 * 4]) * 0x10000) / local_8;
    if (uVar9 == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 3;
      if (uVar9 != 1) {
        uVar4 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_80[0x11] = ((local_80[uVar4 * 4 + 2] - local_80[uVar9 * 4 + 2]) * 0x10000) / local_8;
    if (uVar9 == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 3;
      if (uVar9 != 1) {
        uVar4 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_80[0x12] = ((local_80[uVar4 * 4 + 3] - local_80[uVar9 * 4 + 3]) * 0x10000) / local_8;
    local_10 = local_80[uVar2 * 4] << 0x10;
    local_1c = local_80[uVar2 * 4 + 2] << 0x10;
    local_18 = local_80[uVar2 * 4 + 3] << 0x10;
    if (uVar2 == 0) {
      uVar4 = 2;
    }
    else {
      uVar4 = 3;
      if (uVar2 != 2) {
        uVar4 = (unsigned int)(uVar2 == 3);
      }
    }
    local_c = local_80[uVar4 * 4 + 1] - local_80[uVar2 * 4 + 1];
    if (uVar2 == 0) {
      uVar4 = 2;
    }
    else {
      uVar4 = 3;
      if (uVar2 != 2) {
        uVar4 = (unsigned int)(uVar2 == 3);
      }
    }
    local_34 = ((local_80[uVar4 * 4] - local_80[uVar2 * 4]) * 0x10000) / local_c;
    if (uVar2 == 0) {
      uVar4 = 2;
    }
    else {
      uVar4 = 3;
      if (uVar2 != 2) {
        uVar4 = (unsigned int)(uVar2 == 3);
      }
    }
    local_30 = ((local_80[uVar4 * 4 + 2] - local_80[uVar2 * 4 + 2]) * 0x10000) / local_c;
    if (uVar2 == 0) {
      uVar4 = 2;
    }
    else {
      uVar4 = 3;
      if (uVar2 != 2) {
        uVar4 = (unsigned int)(uVar2 == 3);
      }
    }
    local_2c = ((local_80[uVar4 * 4 + 3] - local_80[uVar2 * 4 + 3]) * 0x10000) / local_c;
    do {
      if (uVar2 == 0) {
        uVar4 = 2;
      }
      else {
        uVar4 = 3;
        if (uVar2 != 2) {
          uVar4 = (unsigned int)(uVar2 == 3);
        }
      }
      if (uVar4 == uVar9) {
        return;
      }
      if (local_8 == 0) {
FUN_004482BD:
        if (uVar9 == 0) {
          uVar9 = 1;
        }
        else if (uVar9 == 1) {
          uVar9 = 3;
        }
        else {
          uVar9 = -(unsigned int)(uVar9 == 3) & 2;
        }
        if (uVar9 == 0) {
          uVar6 = 1;
        }
        else {
          uVar6 = 3;
          if (uVar9 != 1) {
            uVar6 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8 = local_80[uVar9 * 4 + 1];
        if (local_80[uVar6 * 4 + 1] == local_8) {
          return;
        }
        uVar6 = local_8 << 0x10;
        local_14 = local_80[uVar9 * 4] << 0x10;
        local_24 = local_80[uVar9 * 4 + 2] << 0x10;
        local_20 = local_80[uVar9 * 4 + 3] << 0x10;
        if (uVar9 == 0) {
          uVar4 = 1;
        }
        else {
          uVar4 = 3;
          if (uVar9 != 1) {
            uVar4 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8 = local_80[uVar4 * 4 + 1] - local_8;
        if (uVar9 == 0) {
          uVar4 = 1;
        }
        else {
          uVar4 = 3;
          if (uVar9 != 1) {
            uVar4 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_80[0x10] = ((local_80[uVar4 * 4] - local_80[uVar9 * 4]) * 0x10000) / local_8;
        if (uVar9 == 0) {
          uVar4 = 1;
        }
        else {
          uVar4 = 3;
          if (uVar9 != 1) {
            uVar4 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_80[0x11] = ((local_80[uVar4 * 4 + 2] - local_80[uVar9 * 4 + 2]) * 0x10000) / local_8;
        if (uVar9 == 0) {
          uVar4 = 1;
        }
        else {
          uVar4 = 3;
          if (uVar9 != 1) {
            uVar4 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_80[0x12] = ((local_80[uVar4 * 4 + 3] - local_80[uVar9 * 4 + 3]) * 0x10000) / local_8;
      }
      else {
        do {
          if (local_c == 0) break;
          if ((7 < (int)uVar6 >> 0x10) && ((int)uVar6 >> 0x10 < 0xe8)) {
            iVar5 = local_10;
            iVar10 = local_14;
            iVar3 = local_1c;
            uVar4 = local_18;
            iVar7 = local_24;
            uVar13 = local_20;
            if (local_14 <= local_10) {
              iVar5 = local_14;
              iVar10 = local_10;
              iVar3 = local_24;
              uVar4 = local_20;
              iVar7 = local_1c;
              uVar13 = local_18;
            }
            FUN_00448560(iVar5,iVar10,iVar3,uVar4,iVar7,uVar13,uVar6,param_2);
          }
          uVar6 = uVar6 + 0x10000;
          local_14 = local_14 + local_80[0x10];
          local_10 = local_10 + local_34;
          local_24 = local_24 + local_80[0x11];
          local_20 = local_20 + local_80[0x12];
          local_1c = local_1c + local_30;
          local_c = local_c + -1;
          local_18 = local_18 + local_2c;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        if (local_8 == 0) goto FUN_004482BD;
      }
      if (local_c == 0) {
        if (uVar2 == 0) {
          uVar2 = 2;
        }
        else if (uVar2 == 2) {
          uVar2 = 3;
        }
        else {
          uVar2 = (unsigned int)(uVar2 == 3);
        }
        if (uVar2 == 0) {
          uVar4 = 2;
        }
        else {
          uVar4 = 3;
          if (uVar2 != 2) {
            uVar4 = (unsigned int)(uVar2 == 3);
          }
        }
        if (local_80[uVar4 * 4 + 1] == local_80[uVar2 * 4 + 1]) {
          return;
        }
        local_10 = local_80[uVar2 * 4] << 0x10;
        local_1c = local_80[uVar2 * 4 + 2] << 0x10;
        local_18 = local_80[uVar2 * 4 + 3] << 0x10;
        if (uVar2 == 0) {
          uVar4 = 2;
        }
        else {
          uVar4 = 3;
          if (uVar2 != 2) {
            uVar4 = (unsigned int)(uVar2 == 3);
          }
        }
        local_c = local_80[uVar4 * 4 + 1] - local_80[uVar2 * 4 + 1];
        if (uVar2 == 0) {
          uVar4 = 2;
        }
        else {
          uVar4 = 3;
          if (uVar2 != 2) {
            uVar4 = (unsigned int)(uVar2 == 3);
          }
        }
        local_34 = ((local_80[uVar4 * 4] - local_80[uVar2 * 4]) * 0x10000) / local_c;
        if (uVar2 == 0) {
          uVar4 = 2;
        }
        else {
          uVar4 = 3;
          if (uVar2 != 2) {
            uVar4 = (unsigned int)(uVar2 == 3);
          }
        }
        local_30 = ((local_80[uVar4 * 4 + 2] - local_80[uVar2 * 4 + 2]) * 0x10000) / local_c;
        if (uVar2 == 0) {
          uVar4 = 2;
        }
        else {
          uVar4 = 3;
          if (uVar2 != 2) {
            uVar4 = (unsigned int)(uVar2 == 3);
          }
        }
        local_2c = ((local_80[uVar4 * 4 + 3] - local_80[uVar2 * 4 + 3]) * 0x10000) / local_c;
      }
      if (uVar2 == uVar9) {
        return;
      }
    } while( 1 );
  }
  uVar2 = 0x100;
  if (*(unsigned char *)(param_1 + 0x24) != 0) {
    uVar2 = (unsigned int)*(unsigned char *)(param_1 + 0x24);
  }
  DAT_004a2f58 = (unsigned int)*(unsigned char *)(param_1 + 0xc);
  iVar3 = (int)((uVar2 - DAT_004a2f58) * 0x10000) / DAT_004a2f8c;
  uVar2 = 0x100;
  if (*(unsigned char *)(param_1 + 0x25) != 0) {
    uVar2 = (unsigned int)*(unsigned char *)(param_1 + 0x25);
  }
  uVar2 = (int)((uVar2 - *(unsigned char *)(param_1 + 0xd)) * 0x10000) / DAT_004a2f88;
  if (*(short *)(param_1 + 0x20) < *(short *)(param_1 + 8)) {
    DAT_004a2f58 = DAT_004a2f58 + 1;
    iVar7 = (int)*(short *)(param_1 + 0x10);
    if (0x13f < iVar7) {
      DAT_004a2f60 = iVar7;
      return;
    }
    if (iVar7 < 0) {
      if (iVar7 + DAT_004a2f8c < 1) {
        DAT_004a2f60 = iVar7;
        return;
      }
      DAT_004a2f60 = 0;
      iVar8 = 0x140;
      DAT_004a2f8c = DAT_004a2f8c + iVar7;
      if (0x140 < DAT_004a2f8c) {
FUN_004479B0:
        DAT_004a2f8c = iVar8;
      }
    }
    else {
      DAT_004a2f60 = iVar7;
      if (0x140 < iVar7 + DAT_004a2f8c) {
        iVar5 = iVar7 + -0x140 + DAT_004a2f8c;
        iVar8 = DAT_004a2f8c - iVar5;
        goto FUN_004479B0;
      }
    }
    DAT_004a2f68 = -2;
    DAT_004a2f60 = DAT_004a2f60 + DAT_004a2f8c + -1;
  }
  else {
    DAT_004a2f60 = (int)*(short *)(param_1 + 8);
    if (0x13f < DAT_004a2f60) {
      return;
    }
    if (DAT_004a2f60 < 0) {
      if (DAT_004a2f60 + DAT_004a2f8c < 1) {
        return;
      }
      iVar5 = -DAT_004a2f60;
      DAT_004a2f8c = DAT_004a2f8c + DAT_004a2f60;
      DAT_004a2f60 = 0;
      iVar7 = 0;
      if (0x140 < DAT_004a2f8c) {
        DAT_004a2f8c = 0x140;
        iVar7 = DAT_004a2f60;
      }
    }
    else {
      iVar7 = DAT_004a2f60;
      if (0x140 < DAT_004a2f60 + DAT_004a2f8c) {
        DAT_004a2f8c = 0x140 - DAT_004a2f60;
      }
    }
    DAT_004a2f60 = iVar7;
    DAT_004a2f68 = 2;
  }
  if (*(short *)(param_1 + 0x22) < *(short *)(param_1 + 10)) {
    DAT_004a2f5c = *(unsigned char *)(param_1 + 0xd) + 1;
    DAT_004a2f64 = (int)*(short *)(param_1 + 0x22);
    if (0xe7 < DAT_004a2f64) {
      return;
    }
    if (DAT_004a2f64 < 8) {
      if (DAT_004a2f64 + DAT_004a2f88 < 9) {
        return;
      }
      iVar7 = DAT_004a2f64 + -8;
      DAT_004a2f64 = 8;
      DAT_004a2f88 = DAT_004a2f88 + iVar7;
      if (0xe0 < DAT_004a2f88) {
        DAT_004a2f88 = 0xe0;
      }
    }
    else if (0xe8 < DAT_004a2f64 + DAT_004a2f88) {
      iVar10 = DAT_004a2f64 + -0xe8 + DAT_004a2f88;
      DAT_004a2f88 = DAT_004a2f88 - iVar10;
    }
    DAT_004a2f64 = DAT_004a2f64 + DAT_004a2f88 + -1;
    iVar7 = -0x800;
    goto FUN_00447BDF;
  }
  DAT_004a2f5c = (unsigned int)*(unsigned char *)(param_1 + 0xd);
  DAT_004a2f64 = (int)*(short *)(param_1 + 10);
  if (0xe7 < DAT_004a2f64) {
    return;
  }
  if (DAT_004a2f64 < 8) {
    if (DAT_004a2f64 + DAT_004a2f88 < 9) {
      return;
    }
    iVar10 = 8 - DAT_004a2f64;
    DAT_004a2f88 = DAT_004a2f88 - iVar10;
    DAT_004a2f64 = DAT_004a2f64 + iVar10;
    iVar7 = 0xe0;
    if (0xe0 < DAT_004a2f88) {
FUN_00447BD4:
      DAT_004a2f88 = iVar7;
    }
  }
  else if (0xe8 < DAT_004a2f64 + DAT_004a2f88) {
    iVar7 = 0xe8 - DAT_004a2f64;
    goto FUN_00447BD4;
  }
  iVar7 = 0x800;
FUN_00447BDF:
  DAT_004a2b24 = iVar7 - DAT_004a2f68 * DAT_004a2f8c;
  DAT_004a2b2c = iVar3 << 0x10;
  DAT_004a2b28 = (iVar3 >> 0x10) * 2;
  DAT_004a2b38 = uVar2 << 0x10;
  DAT_004a2b34 = (int)(uVar2 & 0xffff001f) >> 5;
  DAT_004a2b40 = iVar5 * iVar3 * 0x10000;
  iVar3 = ((int)(iVar5 * iVar3 + DAT_004a2f58 * 0x10000) >> 0x10) * 2 +
          ((int)(iVar10 * uVar2 + DAT_004a2f5c * 0x10000 & 0xffff001f) >> 5) + DAT_004a2f78;
  DAT_004a33a8 = iVar10 * uVar2 * 0x10000;
  puVar11 = (unsigned int *)(DAT_004a33ac + (DAT_004a2f64 * 0x400 + DAT_004a2f60) * 2);
  iVar5 = DAT_004a2f8c;
  DAT_004a2b3c = iVar3;
  DAT_004a2f54 = puVar11;
  DAT_004a33a4 = DAT_004a2b40;
  if (param_2 != 0) {
    do {
      do {
        iVar10 = DAT_004a2f68;
        piVar1 = (int *)(iVar3 + -2);
        bVar12 = CARRY4(DAT_004a33a4,DAT_004a2b2c);
        DAT_004a33a4 = DAT_004a33a4 + DAT_004a2b2c;
        iVar3 = iVar3 + DAT_004a2b28 + (unsigned int)bVar12 * 2;
        uVar2 = *piVar1 >> 0x10;
        if (uVar2 != 0) {
          if ((int)uVar2 < 0) {
            uVar2 = (uVar2 >> 1 & 0x3def) + ((*puVar11 & 0x7bde) >> 1);
          }
          *(short *)puVar11 = (short)uVar2;
        }
        puVar11 = (unsigned int *)((int)puVar11 + iVar10);
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      bVar12 = CARRY4(DAT_004a33a8,DAT_004a2b38);
      DAT_004a33a8 = DAT_004a33a8 + DAT_004a2b38;
      DAT_004a33a4 = DAT_004a2b40;
      iVar3 = DAT_004a2b3c + DAT_004a2b34 + *(int *)(&DAT_004610cc + (unsigned int)bVar12 * -4);
      puVar11 = (unsigned int *)((int)puVar11 + DAT_004a2b24);
      DAT_004a2b3c = iVar3;
      DAT_004a2f88 = DAT_004a2f88 + -1;
      iVar5 = DAT_004a2f8c;
    } while (DAT_004a2f88 != 0);
    return;
  }
  do {
    do {
      iVar10 = DAT_004a2f68;
      piVar1 = (int *)(iVar3 + -2);
      bVar12 = CARRY4(DAT_004a33a4,DAT_004a2b2c);
      DAT_004a33a4 = DAT_004a33a4 + DAT_004a2b2c;
      iVar3 = iVar3 + DAT_004a2b28 + (unsigned int)bVar12 * 2;
      if (*piVar1 >> 0x10 != 0) {
        *(short *)puVar11 = (short)((unsigned int)*piVar1 >> 0x10);
      }
      puVar11 = (unsigned int *)((int)puVar11 + iVar10);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    bVar12 = CARRY4(DAT_004a33a8,DAT_004a2b38);
    DAT_004a33a8 = DAT_004a33a8 + DAT_004a2b38;
    DAT_004a33a4 = DAT_004a2b40;
    iVar3 = DAT_004a2b3c + DAT_004a2b34 + *(int *)(&DAT_004610cc + (unsigned int)bVar12 * -4);
    DAT_004a2b3c = iVar3;
    puVar11 = (unsigned int *)((int)puVar11 + DAT_004a2b24);
    DAT_004a2f88 = DAT_004a2f88 + -1;
    iVar5 = DAT_004a2f8c;
  } while (DAT_004a2f88 != 0);
  return;
}
