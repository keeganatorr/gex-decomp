// Adapted from pc_decomp_backup/src/functions/FUN_00446890.cpp
// Historical source SHA256: d139f479c5140cbaf5f388991d5f38ace420f8eba47570ddda7da1a1cd59839b
// Behavior candidate; original bytes are not claimed to match.

extern "C" {
extern int DAT_004610cc;
extern int DAT_004a2b24;
extern int DAT_004a2b28;
extern int DAT_004a2b2c;
extern int DAT_004a2b34;
extern int DAT_004a2b38;
extern unsigned char* DAT_004a2b3c;
extern int DAT_004a2b40;
extern unsigned int* DAT_004a2f54;
extern unsigned int DAT_004a2f58;
extern unsigned int DAT_004a2f5c;
extern int DAT_004a2f60;
extern int DAT_004a2f64;
extern int DAT_004a2f68;
extern int* DAT_004a2f6c;
extern int DAT_004a2f78;
extern int DAT_004a2f88;
extern int DAT_004a2f8c;
extern int DAT_004a33a4;
extern int DAT_004a33a8;
extern int DAT_004a33ac;

int* __cdecl FUN_00402400(unsigned char, unsigned char, unsigned char, unsigned int, unsigned int);
void __cdecl FUN_00447680(int, int, int, unsigned int, int, unsigned int, unsigned int, int);
}

static int CARRY4(unsigned int left, unsigned int right) { return left + right < left; }

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

extern "C" void __cdecl FUN_00446890_InnerGraphicsTiles2(int param_1,int param_2)

{
  unsigned int uVar1;
  int *puVar2;
  unsigned int uVar3;
  int iVar4;
  unsigned int uVar5;
  int iVar6;
  int iVar7;
  unsigned char *pbVar8;
  unsigned int uVar9;
  int iVar10;
  unsigned int *puVar11;
  int bVar12;
  unsigned int uVar13;
  int local_8c [19];
  int local_40;
  int local_3c;
  int local_38;
  unsigned int local_34;
  int local_30;
  int local_2c;
  unsigned int local_28;
  int local_24;
  unsigned int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;

  iVar6 = 0;
  iVar7 = 0;
  uVar1 = (int)*(short *)(param_1 + 0x20) - (int)*(short *)(param_1 + 8);
  uVar3 = (int)uVar1 >> 0x1f;
  DAT_004a2f8c = (uVar1 ^ uVar3) - uVar3;
  uVar1 = (int)*(short *)(param_1 + 0x22) - (int)*(short *)(param_1 + 10);
  uVar3 = (int)uVar1 >> 0x1f;
  DAT_004a2f88 = (uVar1 ^ uVar3) - uVar3;
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
    iVar6 = local_8c[1];
    if (local_8c[5] < local_8c[1]) {
      iVar6 = local_8c[5];
    }
    uVar1 = (unsigned int)(local_8c[5] < local_8c[1]);
    if (local_8c[9] < iVar6) {
      uVar1 = 2;
      iVar6 = local_8c[9];
    }
    if (*(short *)(param_1 + 0x22) < iVar6) {
      uVar1 = 3;
    }
    if (uVar1 == 0) {
      uVar3 = 1;
    }
    else {
      uVar3 = 3;
      if (uVar1 != 1) {
        uVar3 = -(unsigned int)(uVar1 == 3) & 2;
      }
    }
    uVar9 = uVar1;
    if (local_8c[uVar3 * 4 + 1] == local_8c[uVar1 * 4 + 1]) {
      if (uVar1 == 0) {
        uVar9 = 1;
      }
      else if (uVar1 == 1) {
        uVar9 = 3;
      }
      else {
        uVar9 = -(unsigned int)(uVar1 == 3) & 2;
      }
    }
    if (uVar1 == 0) {
      uVar3 = 2;
    }
    else {
      uVar3 = 3;
      if (uVar1 != 2) {
        uVar3 = (unsigned int)(uVar1 == 3);
      }
    }
    if (local_8c[uVar3 * 4 + 1] == local_8c[uVar1 * 4 + 1]) {
      if (uVar1 == 0) {
        uVar1 = 2;
      }
      else if (uVar1 == 2) {
        uVar1 = 3;
      }
      else {
        uVar1 = (unsigned int)(uVar1 == 3);
      }
    }
    if (uVar9 == 0) {
      uVar3 = 1;
    }
    else {
      uVar3 = 3;
      if (uVar9 != 1) {
        uVar3 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_14 = uVar9 * 0x10;
    local_8 = local_8c[uVar9 * 4 + 1];
    if (local_8c[uVar3 * 4 + 1] == local_8) {
      return;
    }
    uVar3 = local_8 << 0x10;
    local_1c = local_8c[uVar9 * 4] << 0x10;
    local_2c = local_8c[uVar9 * 4 + 2] << 0x10;
    local_28 = local_8c[uVar9 * 4 + 3] << 0x10;
    if (uVar9 == 0) {
      uVar5 = 1;
    }
    else {
      uVar5 = 3;
      if (uVar9 != 1) {
        uVar5 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_8 = local_8c[uVar5 * 4 + 1] - local_8;
    if (uVar9 == 0) {
      uVar5 = 1;
    }
    else {
      uVar5 = 3;
      if (uVar9 != 1) {
        uVar5 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_8c[0x10] = ((local_8c[uVar5 * 4] - local_8c[uVar9 * 4]) * 0x10000) / local_8;
    if (uVar9 == 0) {
      uVar5 = 1;
    }
    else {
      uVar5 = 3;
      if (uVar9 != 1) {
        uVar5 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_8c[0x11] = ((local_8c[uVar5 * 4 + 2] - local_8c[uVar9 * 4 + 2]) * 0x10000) / local_8;
    if (uVar9 == 0) {
      uVar5 = 1;
    }
    else {
      uVar5 = 3;
      if (uVar9 != 1) {
        uVar5 = -(unsigned int)(uVar9 == 3) & 2;
      }
    }
    local_8c[0x12] = ((local_8c[uVar5 * 4 + 3] - local_8c[uVar9 * 4 + 3]) * 0x10000) / local_8;
    local_10 = uVar1 * 0x10;
    local_18 = local_8c[uVar1 * 4] << 0x10;
    local_24 = local_8c[uVar1 * 4 + 2] << 0x10;
    local_20 = local_8c[uVar1 * 4 + 3] << 0x10;
    if (uVar1 == 0) {
      uVar5 = 2;
    }
    else {
      uVar5 = 3;
      if (uVar1 != 2) {
        uVar5 = (unsigned int)(uVar1 == 3);
      }
    }
    local_c = local_8c[uVar5 * 4 + 1] - local_8c[uVar1 * 4 + 1];
    if (uVar1 == 0) {
      uVar5 = 2;
    }
    else {
      uVar5 = 3;
      if (uVar1 != 2) {
        uVar5 = (unsigned int)(uVar1 == 3);
      }
    }
    local_40 = ((local_8c[uVar5 * 4] - local_8c[uVar1 * 4]) * 0x10000) / local_c;
    if (uVar1 == 0) {
      uVar5 = 2;
    }
    else {
      uVar5 = 3;
      if (uVar1 != 2) {
        uVar5 = (unsigned int)(uVar1 == 3);
      }
    }
    local_3c = ((local_8c[uVar5 * 4 + 2] - local_8c[uVar1 * 4 + 2]) * 0x10000) / local_c;
    if (uVar1 == 0) {
      uVar5 = 2;
    }
    else {
      uVar5 = 3;
      if (uVar1 != 2) {
        uVar5 = (unsigned int)(uVar1 == 3);
      }
    }
    local_38 = ((local_8c[uVar5 * 4 + 3] - local_8c[uVar1 * 4 + 3]) * 0x10000) / local_c;
    DAT_004a2f6c = FUN_00402400(*(unsigned char *)(param_1 + 4),*(unsigned char *)(param_1 + 5),*(unsigned char *)(param_1 + 6)
                                ,(unsigned int)*(unsigned short *)(param_1 + 0xe),0x100);
    do {
      if (uVar1 == 0) {
        uVar5 = 2;
      }
      else {
        uVar5 = 3;
        if (uVar1 != 2) {
          uVar5 = (unsigned int)(uVar1 == 3);
        }
      }
      if (uVar9 == uVar5) {
        return;
      }
      if (local_8 == 0) {
FUN_004473B8:
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
          uVar3 = 1;
        }
        else {
          uVar3 = 3;
          if (uVar9 != 1) {
            uVar3 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8 = local_8c[uVar9 * 4 + 1];
        if (local_8c[uVar3 * 4 + 1] == local_8) {
          return;
        }
        uVar3 = local_8 << 0x10;
        local_1c = local_8c[uVar9 * 4] << 0x10;
        local_2c = local_8c[uVar9 * 4 + 2] << 0x10;
        local_28 = local_8c[uVar9 * 4 + 3] << 0x10;
        if (uVar9 == 0) {
          uVar5 = 1;
        }
        else {
          uVar5 = 3;
          if (uVar9 != 1) {
            uVar5 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8 = local_8c[uVar5 * 4 + 1] - local_8;
        if (uVar9 == 0) {
          uVar5 = 1;
        }
        else {
          uVar5 = 3;
          if (uVar9 != 1) {
            uVar5 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8c[0x10] = ((local_8c[uVar5 * 4] - local_8c[uVar9 * 4]) * 0x10000) / local_8;
        if (uVar9 == 0) {
          uVar5 = 1;
        }
        else {
          uVar5 = 3;
          if (uVar9 != 1) {
            uVar5 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8c[0x11] = ((local_8c[uVar5 * 4 + 2] - local_8c[uVar9 * 4 + 2]) * 0x10000) / local_8;
        if (uVar9 == 0) {
          uVar5 = 1;
        }
        else {
          uVar5 = 3;
          if (uVar9 != 1) {
            uVar5 = -(unsigned int)(uVar9 == 3) & 2;
          }
        }
        local_8c[0x12] = ((local_8c[uVar5 * 4 + 3] - local_8c[uVar9 * 4 + 3]) * 0x10000) / local_8;
      }
      else {
        do {
          if (local_c == 0) break;
          if ((7 < (int)uVar3 >> 0x10) && ((int)uVar3 >> 0x10 < 0xe8)) {
            iVar6 = local_18;
            iVar7 = local_1c;
            iVar10 = local_24;
            uVar5 = local_20;
            iVar4 = local_2c;
            uVar13 = local_28;
            if (local_1c <= local_18) {
              iVar6 = local_1c;
              iVar7 = local_18;
              iVar10 = local_2c;
              uVar5 = local_28;
              iVar4 = local_24;
              uVar13 = local_20;
            }
            FUN_00447680(iVar6,iVar7,iVar10,uVar5,iVar4,uVar13,uVar3,param_2);
          }
          uVar3 = uVar3 + 0x10000;
          local_1c = local_1c + local_8c[0x10];
          local_18 = local_18 + local_40;
          local_2c = local_2c + local_8c[0x11];
          local_28 = local_28 + local_8c[0x12];
          local_24 = local_24 + local_3c;
          local_c = local_c + -1;
          local_20 = local_20 + local_38;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        if (local_8 == 0) goto FUN_004473B8;
      }
      if (local_c == 0) {
        if (uVar1 == 0) {
          uVar1 = 2;
        }
        else if (uVar1 == 2) {
          uVar1 = 3;
        }
        else {
          uVar1 = (unsigned int)(uVar1 == 3);
        }
        if (uVar1 == 0) {
          uVar5 = 2;
        }
        else {
          uVar5 = 3;
          if (uVar1 != 2) {
            uVar5 = (unsigned int)(uVar1 == 3);
          }
        }
        if (local_8c[uVar5 * 4 + 1] == local_8c[uVar1 * 4 + 1]) {
          return;
        }
        local_18 = local_8c[uVar1 * 4] << 0x10;
        local_24 = local_8c[uVar1 * 4 + 2] << 0x10;
        local_20 = local_8c[uVar1 * 4 + 3] << 0x10;
        if (uVar1 == 0) {
          uVar5 = 2;
        }
        else {
          uVar5 = 3;
          if (uVar1 != 2) {
            uVar5 = (unsigned int)(uVar1 == 3);
          }
        }
        local_c = local_8c[uVar5 * 4 + 1] - local_8c[uVar1 * 4 + 1];
        if (uVar1 == 0) {
          uVar5 = 2;
        }
        else {
          uVar5 = 3;
          if (uVar1 != 2) {
            uVar5 = (unsigned int)(uVar1 == 3);
          }
        }
        local_40 = ((local_8c[uVar5 * 4] - local_8c[uVar1 * 4]) * 0x10000) / local_c;
        if (uVar1 == 0) {
          uVar5 = 2;
        }
        else {
          uVar5 = 3;
          if (uVar1 != 2) {
            uVar5 = (unsigned int)(uVar1 == 3);
          }
        }
        local_3c = ((local_8c[uVar5 * 4 + 2] - local_8c[uVar1 * 4 + 2]) * 0x10000) / local_c;
        if (uVar1 == 0) {
          uVar5 = 2;
        }
        else {
          uVar5 = 3;
          if (uVar1 != 2) {
            uVar5 = (unsigned int)(uVar1 == 3);
          }
        }
        local_38 = ((local_8c[uVar5 * 4 + 3] - local_8c[uVar1 * 4 + 3]) * 0x10000) / local_c;
      }
      if (uVar1 == uVar9) {
        return;
      }
    } while( 1 );
  }
  uVar1 = 0x100;
  if (*(unsigned char *)(param_1 + 0x24) != 0) {
    uVar1 = (unsigned int)*(unsigned char *)(param_1 + 0x24);
  }
  local_34 = (unsigned int)*(unsigned char *)(param_1 + 0xc);
  local_30 = (int)((uVar1 - local_34) * 0x10000) / DAT_004a2f8c;
  uVar1 = 0x100;
  if (*(unsigned char *)(param_1 + 0x25) != 0) {
    uVar1 = (unsigned int)*(unsigned char *)(param_1 + 0x25);
  }
  uVar1 = (int)((uVar1 - *(unsigned char *)(param_1 + 0xd)) * 0x10000) / DAT_004a2f88;
  if (*(short *)(param_1 + 0x20) < *(short *)(param_1 + 8)) {
    DAT_004a2f58 = local_34 + 1;
    iVar10 = (int)*(short *)(param_1 + 0x20);
    if (0x13f < iVar10) {
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
      iVar10 = 0x140;
      if (0x140 < DAT_004a2f8c) {
FUN_004469F5:
        DAT_004a2f8c = iVar10;
      }
    }
    else {
      DAT_004a2f60 = iVar10;
      if (0x140 < iVar10 + DAT_004a2f8c) {
        iVar6 = iVar10 + -0x140 + DAT_004a2f8c;
        iVar10 = DAT_004a2f8c - iVar6;
        goto FUN_004469F5;
      }
    }
    DAT_004a2f68 = -2;
    DAT_004a2f60 = DAT_004a2f60 + DAT_004a2f8c + -1;
  }
  else {
    iVar10 = (int)*(short *)(param_1 + 8);
    if (0x13f < iVar10) {
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
      iVar6 = -iVar10;
      DAT_004a2f60 = 0;
      iVar4 = 0x140;
      DAT_004a2f8c = DAT_004a2f8c + iVar10;
      if (0x140 < DAT_004a2f8c) {
FUN_00446AA3:
        DAT_004a2f8c = iVar4;
      }
    }
    else {
      DAT_004a2f60 = iVar10;
      if (0x140 < iVar10 + DAT_004a2f8c) {
        iVar4 = 0x140 - iVar10;
        goto FUN_00446AA3;
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
      iVar7 = DAT_004a2f64 + -0xe8 + DAT_004a2f88;
      DAT_004a2f88 = DAT_004a2f88 - iVar7;
    }
    DAT_004a2b24 = -0x800;
    DAT_004a2f64 = DAT_004a2f64 + DAT_004a2f88 + -1;
    goto FUN_00446C30;
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
    iVar7 = 8 - DAT_004a2f64;
    DAT_004a2f88 = DAT_004a2f88 - iVar7;
    DAT_004a2f64 = DAT_004a2f64 + iVar7;
    iVar10 = 0xe0;
    if (0xe0 < DAT_004a2f88) {
FUN_00446C20:
      DAT_004a2f88 = iVar10;
    }
  }
  else if (0xe8 < DAT_004a2f64 + DAT_004a2f88) {
    iVar10 = 0xe8 - DAT_004a2f64;
    goto FUN_00446C20;
  }
  DAT_004a2b24 = 0x800;
FUN_00446C30:
  DAT_004a2b24 = DAT_004a2b24 - DAT_004a2f68 * DAT_004a2f8c;
  DAT_004a2b2c = local_30 << 0x10;
  DAT_004a2b28 = local_30 >> 0x10;
  DAT_004a2b38 = uVar1 << 0x10;
  DAT_004a2b34 = (int)(uVar1 & 0xffff001f) >> 5;
  DAT_004a2b40 = iVar6 * local_30 * 0x10000;
  DAT_004a2b3c = (unsigned char *)(((int)(iVar6 * local_30 + DAT_004a2f58 * 0x10000) >> 0x10) +
                         ((int)(iVar7 * uVar1 + DAT_004a2f5c * 0x10000 & 0xffff001f) >> 5) +
                         DAT_004a2f78);
  DAT_004a33a8 = iVar7 * uVar1 * 0x10000;
  DAT_004a2f54 = (unsigned int *)(DAT_004a33ac + (DAT_004a2f64 * 0x400 + DAT_004a2f60) * 2);
  DAT_004a33a4 = DAT_004a2b40;
  puVar2 = FUN_00402400(*(unsigned char *)(param_1 + 4),*(unsigned char *)(param_1 + 5),*(unsigned char *)(param_1 + 6),
                        (unsigned int)*(unsigned short *)(param_1 + 0xe),0x100);
  iVar6 = DAT_004a2f8c;
  pbVar8 = DAT_004a2b3c;
  puVar11 = DAT_004a2f54;
  DAT_004a2f6c = puVar2;
  if (param_2 != 0) {
    do {
      do {
        iVar10 = DAT_004a2f68;
        bVar12 = CARRY4(DAT_004a33a4,DAT_004a2b2c);
        DAT_004a33a4 = DAT_004a33a4 + DAT_004a2b2c;
        iVar7 = (unsigned int)bVar12 + DAT_004a2b28;
        uVar1 = *(int *)((int)puVar2 + (unsigned int)*pbVar8 * 2 + -2) >> 0x10;
        if (uVar1 != 0) {
          if ((int)uVar1 < 0) {
            uVar1 = (uVar1 >> 1 & 0x3def) + ((*puVar11 & 0x7bde) >> 1);
          }
          *(short *)puVar11 = (short)uVar1;
        }
        puVar11 = (unsigned int *)((int)puVar11 + iVar10);
        iVar6 = iVar6 + -1;
        pbVar8 = pbVar8 + iVar7;
      } while (iVar6 != 0);
      bVar12 = CARRY4(DAT_004a33a8,DAT_004a2b38);
      DAT_004a33a8 = DAT_004a33a8 + DAT_004a2b38;
      DAT_004a33a4 = DAT_004a2b40;
      DAT_004a2b3c = DAT_004a2b3c + *(int *)(&DAT_004610cc + (unsigned int)bVar12 * -4) + DAT_004a2b34;
      DAT_004a2f88 = DAT_004a2f88 + -1;
      iVar6 = DAT_004a2f8c;
      pbVar8 = DAT_004a2b3c;
      puVar11 = (unsigned int *)((int)puVar11 + DAT_004a2b24);
    } while (DAT_004a2f88 != 0);
    return;
  }
  do {
    do {
      iVar4 = DAT_004a2f68;
      bVar12 = CARRY4(DAT_004a33a4,DAT_004a2b2c);
      DAT_004a33a4 = DAT_004a33a4 + DAT_004a2b2c;
      iVar10 = (unsigned int)bVar12 + DAT_004a2b28;
      iVar7 = *(int *)((int)puVar2 + (unsigned int)*pbVar8 * 2 + -2);
      if (iVar7 >> 0x10 != 0) {
        *(short *)puVar11 = (short)((unsigned int)iVar7 >> 0x10);
      }
      puVar11 = (unsigned int *)((int)puVar11 + iVar4);
      iVar6 = iVar6 + -1;
      pbVar8 = pbVar8 + iVar10;
    } while (iVar6 != 0);
    bVar12 = CARRY4(DAT_004a33a8,DAT_004a2b38);
    DAT_004a33a8 = DAT_004a33a8 + DAT_004a2b38;
    DAT_004a33a4 = DAT_004a2b40;
    DAT_004a2b3c = DAT_004a2b3c + *(int *)(&DAT_004610cc + (unsigned int)bVar12 * -4) + DAT_004a2b34;
    DAT_004a2f88 = DAT_004a2f88 + -1;
    iVar6 = DAT_004a2f8c;
    pbVar8 = DAT_004a2b3c;
    puVar11 = (unsigned int *)((int)puVar11 + DAT_004a2b24);
  } while (DAT_004a2f88 != 0);
  return;
}
