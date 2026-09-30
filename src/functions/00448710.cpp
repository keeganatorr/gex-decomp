// Raster clipping follows the source replacement viewport, including sprite spans.
extern "C" int __cdecl GEX_WidescreenWidth(void);
// Adapted from pc_decomp_backup/src/functions/FUN_00448710.cpp
// Historical source SHA256: 182da47b39bf99a1f2e5cbe4c82e634cb478ab32d05ab28351d00c6075a48bce
// Behavior candidate; original bytes are not claimed to match.
/* Extern declarations */
extern "C" {
extern int DAT_004610d4;
extern int DAT_004a2b24;
extern int DAT_004a2b28;
extern int DAT_004a2b2c;
extern int DAT_004a2b34;
extern int DAT_004a2b38;
extern int DAT_004a2b3c;
extern int DAT_004a2b40;
extern unsigned int* DAT_004a2f54;
extern int DAT_004a2f58;
extern int DAT_004a2f5c;
extern int DAT_004a2f60;
extern int DAT_004a2f64;
extern int DAT_004a2f68;
extern int* DAT_004a2f6c;
extern unsigned char* DAT_004a2f78;
extern int DAT_004a2f88;
extern int DAT_004a2f8c;
extern int DAT_004a33a4;
extern int DAT_004a33a8;
extern int DAT_004a33ac;
extern int* __cdecl FUN_00402400(unsigned char, unsigned char, unsigned char, unsigned int, int);
extern void __cdecl FUN_00449500(int, int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, int);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

extern "C" void __cdecl FUN_00448710_InnerGraphicsTiles1(int param_1,int param_2)

{
  unsigned char bVar1;
  unsigned int uVar2;
  int *puVar3;
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
  unsigned int uVar14;
  unsigned int uVar15;
  int local_8c [19];
  int local_40;
  int local_3c;
  int local_38;
  unsigned int local_34;
  int local_30;
  unsigned int local_2c;
  unsigned int local_28;
  unsigned int local_24;
  unsigned int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;

  iVar7 = 0;
  iVar8 = 0;
  uVar2 = (int)*(short *)(param_1 + 0x20) - (int)*(short *)(param_1 + 8);
  uVar4 = (int)uVar2 >> 0x1f;
  DAT_004a2f8c = (uVar2 ^ uVar4) - uVar4;
  uVar2 = (int)*(short *)(param_1 + 0x22) - (int)*(short *)(param_1 + 10);
  uVar4 = (int)uVar2 >> 0x1f;
  DAT_004a2f88 = (uVar2 ^ uVar4) - uVar4;
  if (((((DAT_004a2f8c < 1) || (DAT_004a2f88 < 1)) ||
       (*(short *)(param_1 + 0x18) != *(short *)(param_1 + 8))) ||
      ((*(short *)(param_1 + 0x10) != *(short *)(param_1 + 0x20) ||
       (*(short *)(param_1 + 0x12) != *(short *)(param_1 + 10))))) ||
     (*(short *)(param_1 + 0x1a) != *(short *)(param_1 + 0x22))) {
    local_8c[1] = (int)*(short *)(param_1 + 10);
    local_8c[0] = (int)*(short *)(param_1 + 8);
    local_8c[4] = (int)*(short *)(param_1 + 0x10);
    local_8c[5] = (int)*(short *)(param_1 + 0x12);
    local_8c[2] = (unsigned int)*(unsigned char *)(param_1 + 0xc);
    local_8c[3] = (unsigned int)*(unsigned char *)(param_1 + 0xd);
    if (*(unsigned char *)(param_1 + 0x14) == 0) {
      local_8c[6] = 0x100;
    }
    else {
      local_8c[6] = (unsigned int)*(unsigned char *)(param_1 + 0x14);
    }
    local_8c[9] = (int)*(short *)(param_1 + 0x1a);
    local_8c[8] = (int)*(short *)(param_1 + 0x18);
    local_8c[7] = (unsigned int)*(unsigned char *)(param_1 + 0x15);
    local_8c[10] = (unsigned int)*(unsigned char *)(param_1 + 0x1c);
    if (*(unsigned char *)(param_1 + 0x1d) == 0) {
      local_8c[0xb] = 0x100;
    }
    else {
      local_8c[0xb] = (unsigned int)*(unsigned char *)(param_1 + 0x1d);
    }
    local_8c[0xc] = (int)*(short *)(param_1 + 0x20);
    local_8c[0xd] = (int)*(short *)(param_1 + 0x22);
    if (*(unsigned char *)(param_1 + 0x24) == 0) {
      local_8c[0xe] = 0x100;
    }
    else {
      local_8c[0xe] = (unsigned int)*(unsigned char *)(param_1 + 0x24);
    }
    if (*(unsigned char *)(param_1 + 0x25) == 0) {
      local_8c[0xf] = 0x100;
    }
    else {
      local_8c[0xf] = (unsigned int)*(unsigned char *)(param_1 + 0x25);
    }
    iVar7 = local_8c[1];
    if (local_8c[5] < local_8c[1]) {
      iVar7 = local_8c[5];
    }
    uVar2 = (unsigned int)(local_8c[5] < local_8c[1]);
    if (local_8c[9] < iVar7) {
      uVar2 = 2;
      iVar7 = local_8c[9];
    }
    if (*(short *)(param_1 + 0x22) < iVar7) {
      uVar2 = 3;
    }
    if (uVar2 == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 3;
      if (uVar2 != 1) {
        uVar4 = -(unsigned int)(uVar2 == 3) & 2;
      }
    }
    uVar9 = uVar2;
    if (local_8c[uVar4 * 4 + 1] == local_8c[uVar2 * 4 + 1]) {
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
      uVar4 = 2;
    }
    else {
      uVar4 = 3;
      if (uVar2 != 2) {
        uVar4 = (unsigned int)(uVar2 == 3);
      }
    }
    if (local_8c[uVar4 * 4 + 1] == local_8c[uVar2 * 4 + 1]) {
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
      uVar4 = 1;
    }
    else {
      uVar4 = 3;
      if (uVar9 != 1) {
        uVar4 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_14 = uVar9 * 0x10;
    local_8 = local_8c[uVar9 * 4 + 1];
    if (local_8c[uVar4 * 4 + 1] == local_8) {
      return;
    }
    uVar4 = local_8 << 0x10;
    local_1c = local_8c[uVar9 * 4] << 0x10;
    local_2c = local_8c[uVar9 * 4 + 2] << 0x10;
    local_28 = local_8c[uVar9 * 4 + 3] << 0x10;
    if (uVar9 == 0) {
      uVar6 = 1;
    }
    else {
      uVar6 = 3;
      if (uVar9 != 1) {
        uVar6 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_8 = local_8c[uVar6 * 4 + 1] - local_8;
    if (uVar9 == 0) {
      uVar6 = 1;
    }
    else {
      uVar6 = 3;
      if (uVar9 != 1) {
        uVar6 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_8c[0x10] = ((local_8c[uVar6 * 4] - local_8c[uVar9 * 4]) * 0x10000) / local_8;
    if (uVar9 == 0) {
      uVar6 = 1;
    }
    else {
      uVar6 = 3;
      if (uVar9 != 1) {
        uVar6 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_8c[0x11] = ((local_8c[uVar6 * 4 + 2] - local_8c[uVar9 * 4 + 2]) * 0x10000) / local_8;
    if (uVar9 == 0) {
      uVar6 = 1;
    }
    else {
      uVar6 = 3;
      if (uVar9 != 1) {
        uVar6 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_8c[0x12] = ((local_8c[uVar6 * 4 + 3] - local_8c[uVar9 * 4 + 3]) * 0x10000) / local_8;
    local_10 = uVar2 * 0x10;
    local_18 = local_8c[uVar2 * 4] << 0x10;
    local_24 = local_8c[uVar2 * 4 + 2] << 0x10;
    local_20 = local_8c[uVar2 * 4 + 3] << 0x10;
    if (uVar2 == 0) {
      uVar6 = 2;
    }
    else {
      uVar6 = 3;
      if (uVar2 != 2) {
        uVar6 = (unsigned int)(uVar2 == 3);
      }
    }
    local_c = local_8c[uVar6 * 4 + 1] - local_8c[uVar2 * 4 + 1];
    if (uVar2 == 0) {
      uVar6 = 2;
    }
    else {
      uVar6 = 3;
      if (uVar2 != 2) {
        uVar6 = (unsigned int)(uVar2 == 3);
      }
    }
    local_40 = ((local_8c[uVar6 * 4] - local_8c[uVar2 * 4]) * 0x10000) / local_c;
    if (uVar2 == 0) {
      uVar6 = 2;
    }
    else {
      uVar6 = 3;
      if (uVar2 != 2) {
        uVar6 = (unsigned int)(uVar2 == 3);
      }
    }
    local_3c = ((local_8c[uVar6 * 4 + 2] - local_8c[uVar2 * 4 + 2]) * 0x10000) / local_c;
    if (uVar2 == 0) {
      uVar6 = 2;
    }
    else {
      uVar6 = 3;
      if (uVar2 != 2) {
        uVar6 = (unsigned int)(uVar2 == 3);
      }
    }
    local_38 = ((local_8c[uVar6 * 4 + 3] - local_8c[uVar2 * 4 + 3]) * 0x10000) / local_c;
    DAT_004a2f6c = FUN_00402400(*(unsigned char *)(param_1 + 4),*(unsigned char *)(param_1 + 5),*(unsigned char *)(param_1 + 6)
                                ,(unsigned int)*(unsigned short *)(param_1 + 0xe),0x10);
    do {
      if (uVar2 == 0) {
        uVar6 = 2;
      }
      else {
        uVar6 = 3;
        if (uVar2 != 2) {
          uVar6 = (unsigned int)(uVar2 == 3);
        }
      }
      if (uVar9 == uVar6) {
        return;
      }
      if (local_8 == 0) {
FUN_00449232:
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
          uVar4 = 1;
        }
        else {
          uVar4 = 3;
          if (uVar9 != 1) {
            uVar4 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8 = local_8c[uVar9 * 4 + 1];
        if (local_8c[uVar4 * 4 + 1] == local_8) {
          return;
        }
        uVar4 = local_8 << 0x10;
        local_1c = local_8c[uVar9 * 4] << 0x10;
        local_2c = local_8c[uVar9 * 4 + 2] << 0x10;
        local_28 = local_8c[uVar9 * 4 + 3] << 0x10;
        if (uVar9 == 0) {
          uVar6 = 1;
        }
        else {
          uVar6 = 3;
          if (uVar9 != 1) {
            uVar6 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8 = local_8c[uVar6 * 4 + 1] - local_8;
        if (uVar9 == 0) {
          uVar6 = 1;
        }
        else {
          uVar6 = 3;
          if (uVar9 != 1) {
            uVar6 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8c[0x10] = ((local_8c[uVar6 * 4] - local_8c[uVar9 * 4]) * 0x10000) / local_8;
        if (uVar9 == 0) {
          uVar6 = 1;
        }
        else {
          uVar6 = 3;
          if (uVar9 != 1) {
            uVar6 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8c[0x11] = ((local_8c[uVar6 * 4 + 2] - local_8c[uVar9 * 4 + 2]) * 0x10000) / local_8;
        if (uVar9 == 0) {
          uVar6 = 1;
        }
        else {
          uVar6 = 3;
          if (uVar9 != 1) {
            uVar6 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8c[0x12] = ((local_8c[uVar6 * 4 + 3] - local_8c[uVar9 * 4 + 3]) * 0x10000) / local_8;
      }
      else {
        do {
          if (local_c == 0) break;
          if ((7 < (int)uVar4 >> 0x10) && ((int)uVar4 >> 0x10 < 0xe8)) {
            iVar7 = local_18;
            iVar8 = local_1c;
            uVar6 = local_24;
            uVar13 = local_20;
            uVar14 = local_2c;
            uVar15 = local_28;
            if (local_1c <= local_18) {
              iVar7 = local_1c;
              iVar8 = local_18;
              uVar6 = local_2c;
              uVar13 = local_28;
              uVar14 = local_24;
              uVar15 = local_20;
            }
            FUN_00449500(iVar7,iVar8,uVar6,uVar13,uVar14,uVar15,uVar4,param_2);
          }
          uVar4 = uVar4 + 0x10000;
          local_1c = local_1c + local_8c[0x10];
          local_18 = local_18 + local_40;
          local_2c = local_2c + local_8c[0x11];
          local_28 = local_28 + local_8c[0x12];
          local_24 = local_24 + local_3c;
          local_c = local_c + -1;
          local_20 = local_20 + local_38;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        if (local_8 == 0) goto FUN_00449232;
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
          uVar6 = 2;
        }
        else {
          uVar6 = 3;
          if (uVar2 != 2) {
            uVar6 = (unsigned int)(uVar2 == 3);
          }
        }
        if (local_8c[uVar6 * 4 + 1] == local_8c[uVar2 * 4 + 1]) {
          return;
        }
        local_18 = local_8c[uVar2 * 4] << 0x10;
        local_24 = local_8c[uVar2 * 4 + 2] << 0x10;
        local_20 = local_8c[uVar2 * 4 + 3] << 0x10;
        if (uVar2 == 0) {
          uVar6 = 2;
        }
        else {
          uVar6 = 3;
          if (uVar2 != 2) {
            uVar6 = (unsigned int)(uVar2 == 3);
          }
        }
        local_c = local_8c[uVar6 * 4 + 1] - local_8c[uVar2 * 4 + 1];
        if (uVar2 == 0) {
          uVar6 = 2;
        }
        else {
          uVar6 = 3;
          if (uVar2 != 2) {
            uVar6 = (unsigned int)(uVar2 == 3);
          }
        }
        local_40 = ((local_8c[uVar6 * 4] - local_8c[uVar2 * 4]) * 0x10000) / local_c;
        if (uVar2 == 0) {
          uVar6 = 2;
        }
        else {
          uVar6 = 3;
          if (uVar2 != 2) {
            uVar6 = (unsigned int)(uVar2 == 3);
          }
        }
        local_3c = ((local_8c[uVar6 * 4 + 2] - local_8c[uVar2 * 4 + 2]) * 0x10000) / local_c;
        if (uVar2 == 0) {
          uVar6 = 2;
        }
        else {
          uVar6 = 3;
          if (uVar2 != 2) {
            uVar6 = (unsigned int)(uVar2 == 3);
          }
        }
        local_38 = ((local_8c[uVar6 * 4 + 3] - local_8c[uVar2 * 4 + 3]) * 0x10000) / local_c;
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
  local_34 = (unsigned int)*(unsigned char *)(param_1 + 0xc);
  local_30 = (int)((uVar2 - local_34) * 0x10000) / DAT_004a2f8c;
  uVar2 = 0x100;
  if (*(unsigned char *)(param_1 + 0x25) != 0) {
    uVar2 = (unsigned int)*(unsigned char *)(param_1 + 0x25);
  }
  uVar2 = (int)((uVar2 - *(unsigned char *)(param_1 + 0xd)) * 0x10000) / DAT_004a2f88;
  if (*(short *)(param_1 + 0x20) < *(short *)(param_1 + 8)) {
    DAT_004a2f58 = local_34 + 1;
    iVar10 = (int)*(short *)(param_1 + 0x10);
    if ((GEX_WidescreenWidth() - 1) < iVar10) {
      DAT_004a2f60 = iVar10;
      return;
    }
    if (iVar10 < 0) {
      if (iVar10 + DAT_004a2f8c < 1) {
        DAT_004a2f60 = iVar10;
        return;
      }
      DAT_004a2f60 = 0;
      DAT_004a2f8c = DAT_004a2f8c + iVar10;
      iVar10 = GEX_WidescreenWidth();
      if (GEX_WidescreenWidth() < DAT_004a2f8c) {
FUN_00448875:
        DAT_004a2f8c = iVar10;
      }
    }
    else {
      DAT_004a2f60 = iVar10;
      if (GEX_WidescreenWidth() < iVar10 + DAT_004a2f8c) {
        iVar7 = iVar10 + -GEX_WidescreenWidth() + DAT_004a2f8c;
        iVar10 = DAT_004a2f8c - iVar7;
        goto FUN_00448875;
      }
    }
    DAT_004a2f68 = -2;
    DAT_004a2f60 = DAT_004a2f60 + DAT_004a2f8c + -1;
  }
  else {
    iVar10 = (int)*(short *)(param_1 + 8);
    if ((GEX_WidescreenWidth() - 1) < iVar10) {
      DAT_004a2f58 = local_34;
      DAT_004a2f60 = iVar10;
      return;
    }
    if (iVar10 < 0) {
      if (iVar10 + DAT_004a2f8c < 1) {
        DAT_004a2f58 = local_34;
        DAT_004a2f60 = iVar10;
        return;
      }
      iVar7 = -iVar10;
      DAT_004a2f60 = 0;
      iVar5 = GEX_WidescreenWidth();
      DAT_004a2f8c = DAT_004a2f8c + iVar10;
      if (GEX_WidescreenWidth() < DAT_004a2f8c) {
FUN_00448923:
        DAT_004a2f8c = iVar5;
      }
    }
    else {
      DAT_004a2f60 = iVar10;
      if (GEX_WidescreenWidth() < iVar10 + DAT_004a2f8c) {
        iVar5 = GEX_WidescreenWidth() - iVar10;
        goto FUN_00448923;
      }
    }
    DAT_004a2f68 = 2;
    DAT_004a2f58 = local_34;
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
      DAT_004a2f88 = DAT_004a2f88 + DAT_004a2f64 + -8;
      DAT_004a2f64 = 8;
      if (0xe0 < DAT_004a2f88) {
        DAT_004a2f88 = 0xe0;
      }
    }
    else if (0xe8 < DAT_004a2f64 + DAT_004a2f88) {
      iVar8 = DAT_004a2f64 + -0xe8 + DAT_004a2f88;
      DAT_004a2f88 = DAT_004a2f88 - iVar8;
    }
    DAT_004a2f64 = DAT_004a2f64 + DAT_004a2f88 + -1;
    iVar10 = -0x800;
    goto FUN_00448AA6;
  }
  DAT_004a2f5c = (unsigned int)*(unsigned char *)(param_1 + 0xd);
  DAT_004a2f64 = (int)*(short *)(param_1 + 10);
  if (0xe7 < DAT_004a2f64) {
    return;
  }
  if (DAT_004a2f64 < 8) {
    if (DAT_004a2f88 + DAT_004a2f64 < 9) {
      return;
    }
    iVar8 = 8 - DAT_004a2f64;
    DAT_004a2f88 = DAT_004a2f88 - iVar8;
    DAT_004a2f64 = DAT_004a2f64 + iVar8;
    iVar10 = 0xe0;
    if (0xe0 < DAT_004a2f88) {
FUN_00448A9B:
      DAT_004a2f88 = iVar10;
    }
  }
  else if (0xe8 < DAT_004a2f64 + DAT_004a2f88) {
    iVar10 = 0xe8 - DAT_004a2f64;
    goto FUN_00448A9B;
  }
  iVar10 = 0x800;
FUN_00448AA6:
  DAT_004a2b24 = iVar10 - DAT_004a2f68 * DAT_004a2f8c;
  DAT_004a2b2c = local_30 << 0x10;
  DAT_004a2b28 = local_30 >> 0x10;
  DAT_004a2b38 = uVar2 << 0x10;
  DAT_004a2b34 = (int)(uVar2 & 0xffff000f) >> 4;
  DAT_004a2b40 = iVar7 * local_30 * 0x10000;
  DAT_004a2b3c = ((int)(iVar7 * local_30 + DAT_004a2f58 * 0x10000) >> 0x10) +
                 ((int)(iVar8 * uVar2 + DAT_004a2f5c * 0x10000 & 0xffff000f) >> 4);
  DAT_004a33a8 = iVar8 * uVar2 * 0x10000;
  DAT_004a2f54 = (unsigned int *)(DAT_004a33ac + (DAT_004a2f64 * 0x400 + DAT_004a2f60) * 2);
  DAT_004a33a4 = DAT_004a2b40;
  puVar3 = FUN_00402400(*(unsigned char *)(param_1 + 4),*(unsigned char *)(param_1 + 5),*(unsigned char *)(param_1 + 6),
                        (unsigned int)*(unsigned short *)(param_1 + 0xe),0x10);
  iVar7 = DAT_004a2f8c;
  uVar2 = DAT_004a2b3c;
  puVar11 = DAT_004a2f54;
  DAT_004a2f6c = puVar3;
  if (param_2 != 0) {
    do {
      do {
        iVar8 = DAT_004a2f68;
        bVar1 = *(unsigned char *)((uVar2 >> 1) + DAT_004a2f78);
        if ((uVar2 & 1) != 0) {
          bVar1 = bVar1 >> 4;
        }
        bVar12 = ((unsigned int)(DAT_004a33a4) + (unsigned int)(DAT_004a2b2c) < (unsigned int)(DAT_004a33a4));
        DAT_004a33a4 = DAT_004a33a4 + DAT_004a2b2c;
        iVar10 = uVar2 + DAT_004a2b28;
        uVar2 = *(int *)((int)puVar3 + (bVar1 & 0xf) * 2 + -2) >> 0x10;
        if (uVar2 != 0) {
          if ((int)uVar2 < 0) {
            uVar2 = (uVar2 >> 1 & 0x3def) + ((*puVar11 & 0x7bde) >> 1);
          }
          *(short *)puVar11 = (short)uVar2;
        }
        puVar11 = (unsigned int *)((int)puVar11 + iVar8);
        iVar7 = iVar7 + -1;
        uVar2 = iVar10 + (unsigned int)bVar12;
      } while (iVar7 != 0);
      bVar12 = ((unsigned int)(DAT_004a33a8) + (unsigned int)(DAT_004a2b38) < (unsigned int)(DAT_004a33a8));
      DAT_004a33a8 = DAT_004a33a8 + DAT_004a2b38;
      DAT_004a33a4 = DAT_004a2b40;
      DAT_004a2b3c = DAT_004a2b3c + DAT_004a2b34 + *(int *)((char *)&DAT_004610d4 - (unsigned int)bVar12 * 4);
      DAT_004a2f88 = DAT_004a2f88 + -1;
      iVar7 = DAT_004a2f8c;
      uVar2 = DAT_004a2b3c;
      puVar11 = (unsigned int *)((int)puVar11 + DAT_004a2b24);
    } while (DAT_004a2f88 != 0);
    return;
  }
  do {
    do {
      iVar8 = DAT_004a2f68;
      bVar1 = *(unsigned char *)((uVar2 >> 1) + DAT_004a2f78);
      if ((uVar2 & 1) != 0) {
        bVar1 = bVar1 >> 4;
      }
      bVar12 = ((unsigned int)(DAT_004a33a4) + (unsigned int)(DAT_004a2b2c) < (unsigned int)(DAT_004a33a4));
      DAT_004a33a4 = DAT_004a33a4 + DAT_004a2b2c;
      iVar5 = uVar2 + DAT_004a2b28;
      iVar10 = *(int *)((int)puVar3 + (bVar1 & 0xf) * 2 + -2);
      if (iVar10 >> 0x10 != 0) {
        *(short *)puVar11 = (short)((unsigned int)iVar10 >> 0x10);
      }
      puVar11 = (unsigned int *)((int)puVar11 + iVar8);
      iVar7 = iVar7 + -1;
      uVar2 = iVar5 + (unsigned int)bVar12;
    } while (iVar7 != 0);
    bVar12 = ((unsigned int)(DAT_004a33a8) + (unsigned int)(DAT_004a2b38) < (unsigned int)(DAT_004a33a8));
    DAT_004a33a8 = DAT_004a33a8 + DAT_004a2b38;
    DAT_004a33a4 = DAT_004a2b40;
    DAT_004a2b3c = DAT_004a2b3c + DAT_004a2b34 + *(int *)((char *)&DAT_004610d4 - (unsigned int)bVar12 * 4);
    DAT_004a2f88 = DAT_004a2f88 + -1;
    iVar7 = DAT_004a2f8c;
    uVar2 = DAT_004a2b3c;
    puVar11 = (unsigned int *)((int)puVar11 + DAT_004a2b24);
  } while (DAT_004a2f88 != 0);
  return;
}
