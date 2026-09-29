// Archived scale/rotate display translation adapted to a self-contained source.
// This is a behavior candidate with unresolved layout and type assumptions.


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

extern int FUN_0045A5C8;
extern int DAT_0045A6C8;
extern int DAT_0045A7C8;
extern int DAT_0045A8C8;
extern int DAT_0045A9C8;
extern int PTR_ARRAY_0045A4C8;
extern int SciFiLevelStrings;
extern int FUN_004A2AC8;
extern int DAT_004A2974;
extern int DAT_004A2988;
extern int DAT_004A2A96;
extern int DAT_004A2A94;
extern int DAT_004A2AE4;
extern int DAT_004A2ADC;
extern int DAT_004A2AE0;
extern int DAT_004A2B14;
extern int DAT_004A2B18;
extern short DAT_004A2B20;
extern int DAT_00460F6C;
extern int FUN_0045A2C0;
extern int FUN_0045AA9C;

extern "C" int __cdecl FUN_0041A500(int*);
extern "C" void __cdecl FUN_004432C0(int*);
extern "C" int __cdecl FUN_00442DE0_GraphicsFlashingInner(int, int);
extern "C" void __cdecl FUN_00442E50_GraphicsFlashingInner2(int*, int*, int);
extern "C" unsigned int __cdecl FUN_0043E2C0(unsigned int);
extern "C" int* __cdecl FUN_0043E580_Image_Clean1(int*);
extern "C" int* __cdecl FUN_0043E920_Image(int*);
extern "C" unsigned int __cdecl FUN_0043ECF0_SelectTile_Clean1(int*);

extern "C" void __cdecl GEX_Target(int* param_1)
{
  short *psVar1;
  int bVar2;
  unsigned int uVar3;
  int *imageStruct;
  int *pDVar4;
  int bVar5;
  int bVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  unsigned short uVar10;
  int *pSVar11;
  int iVar12;
  int iVar13;
  unsigned int uVar14;
  unsigned int uVar15;
  int *puVar16;
  unsigned int uVar17;
  int *tileSelectPtr;
  unsigned short *puVar18;
  unsigned short *puVar19;
  unsigned short *puVar20;
  unsigned short *puVar21;
  unsigned short *puVar22;
  unsigned short *puVar23;
  int iVar24;
  short sVar25;
  int iVar26;
  unsigned int uVar27;
  unsigned int uVar28;
  unsigned int uVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int ***pppuVar33;
  short *psVar34;
  short sVar35;
  int *pMVar36;
  unsigned short **ppuVar37;
  unsigned int uVar38;
  int *pMVar39;
  unsigned int uVar40;
  int iVar41;
  int **ppuVar42;
  unsigned short **ppuVar43;
  short local_f6;
  short local_f4;
  short local_f2;
  int local_f0_0;
  int local_f0_1;
  int local_ec_0;
  int local_ec_1;
  int local_e0_0;
  int local_e0_1;
  int local_dc_0;
  int local_dc_1;
  unsigned int local_d4;
  unsigned int local_c0;
  int *local_b8;
  unsigned short *local_b0;
  short local_ac;
  short sStack_aa;
  short local_a8;
  short sStack_a6;
  short local_a4;
  short sStack_a2;
  short local_a0;
  short sStack_9e;
  unsigned int local_9c;
  unsigned int local_98;
  unsigned int local_94;
  unsigned int local_90;
  unsigned int local_8c;
  unsigned int local_88;
  unsigned int local_84;
  int *local_80;
  int local_7c_0;
  int local_7c_1;
  int local_78_0;
  int local_78_1;
  int local_74_0;
  int local_74_1;
  int local_70_0;
  int local_70_1;
  int *local_6c;
  unsigned int local_68;
  unsigned int local_64;
  unsigned int local_60;
  unsigned int local_5c;
  int *local_58;
  int local_54_0;
  int local_54_1;
  int local_50_0;
  int local_50_1;
  int local_4c_0;
  int local_4c_1;
  int local_48_0;
  int local_48_1;
  int local_44_0;
  int local_44_1;
  int local_40_0;
  int local_40_1;
  int local_3c_0;
  int local_3c_1;
  int local_38_0;
  int local_38_1;
  int local_34_0;
  int local_34_1;
  int local_30_0;
  int local_30_1;
  int local_2c_0;
  int local_2c_1;
  int local_28_0;
  int local_28_1;
  unsigned int local_24;
  unsigned int local_20;
  unsigned int local_1c;
  unsigned int local_18;
  unsigned int local_14;
  unsigned int local_10;
  unsigned int local_c;
  unsigned int local_8;
  int *local_4;

  uVar3 = (unsigned int)param_1[0x31];
  local_1c = (unsigned int)param_1[0x32];
  local_18 = (unsigned int)param_1[0x33];
  if (uVar3 == 0) {
    FUN_004432C0(param_1);
    return;
  }
  pSVar11 = (int*)FUN_0041A500(param_1);
  if (pSVar11 == (int*)0x0) {
    return;
  }
  iVar12 = param_1[0x1e] - DAT_004A2974;
  iVar13 = param_1[0x1f] - DAT_004A2988;
  if (iVar12 < -0xffffff) {
    return;
  }
  if (0x23fffff < iVar12) {
    return;
  }
  if (iVar13 < -0xffffff) {
    return;
  }
  if (0x1efffff < iVar13) {
    return;
  }
  local_4 = (int*)param_1[0x16];
  if (((param_1[0x38] & 0x1000000U) == 0) && (param_1[0x31] - FUN_004A2AC8 == -1))
  {
    iVar26 = param_1[0x1e] - param_1[0x1c];
    if (iVar26 < 0) {
      iVar26 = iVar26 + 0x10000;
    }
    local_f4 = (short)(iVar26 >> 0x11) - (short)DAT_004A2A96;
    iVar26 = param_1[0x1f] - param_1[0x1d];
    if (iVar26 < 0) {
      iVar26 = iVar26 + 0x10000;
    }
    local_f2 = (short)(iVar26 >> 0x11) - (short)DAT_004A2A94;
    uVar27 = (unsigned int)local_f2 >> 0x1f;
    uVar28 = (unsigned int)local_f4 >> 0x1f;
    if ((int)(((((int)local_f2 ^ uVar27) - uVar27) - uVar28) + ((int)local_f4 ^ uVar28)) < 0x65)
    goto FUN_004412C3;
  }
  local_f4 = 0;
  local_f2 = 0;
FUN_004412C3:
  local_6c = (int*)pSVar11[6];
  if (local_6c != (int*)0x0) {
    local_80 = (int*)local_6c[0];
    while (local_80 != (int*)0x0) {
      local_6c = (int*)((int)local_6c + 4);
      imageStruct = (int*)local_80[2];
      psVar34 = (short*)(imageStruct + 5);
      if (*psVar34 != 0) {
        pDVar4 = (int*)local_80[0];
        uVar27 = (unsigned int)local_80[1];
        local_14 = ((unsigned int)param_1[0x1a] >> 2) | uVar27;
        if ((uVar27 & 0x80000000) == 0) {
          iVar26 = imageStruct[2];
        }
        else {
          iVar26 = *imageStruct - imageStruct[2];
        }
        if ((uVar27 & 0x40000000) == 0) {
          iVar24 = imageStruct[3];
        }
        else {
          iVar24 = imageStruct[1] - imageStruct[3];
        }
        if ((local_14 & 0x20000000) == 0) {
          iVar26 = iVar26 + ((unsigned int)pDVar4 & 0xffff0000) + iVar12;
        }
        else {
          iVar26 = (iVar12 - ((unsigned int)pDVar4 & 0xffff0000)) - iVar26;
        }
        if ((local_14 & 0x10000000) == 0) {
          iVar24 = iVar24 + (int)pDVar4 * 0x10000 + iVar13;
        }
        else {
          iVar24 = (iVar13 - iVar24) + (int)pDVar4 * -0x10000;
        }
        local_14 = local_14 ^ local_14 * 4;
        local_8 = local_14 & 0x80000000;
        if (local_8 == 0) {
          iVar30 = iVar26 + *imageStruct;
        }
        else {
          iVar30 = iVar26;
          iVar26 = iVar26 - *imageStruct;
        }
        local_14 = local_14 & 0x40000000;
        if (local_14 == 0) {
          iVar41 = iVar24 + imageStruct[1];
        }
        else {
          iVar41 = iVar24;
          iVar24 = iVar24 - imageStruct[1];
        }
        local_58 = imageStruct + 1;
        local_94 = (unsigned int)(iVar26 - iVar12);
        local_8c = (unsigned int)(iVar30 - iVar12);
        local_60 = (unsigned int)(iVar24 - iVar13);
        local_90 = (unsigned int)(iVar41 - iVar13);
        uVar27 = uVar3 & 0xffff0000;
        uVar28 = (int)uVar3 >> 0x10;
        uVar17 = (int)uVar3 >> 0x1f;
        if ((int)uVar27 < 0) {
          if ((int)uVar27 < -0x1000000) {
            uVar38 = (int)-uVar28 >> 0x1f;
            iVar26 = ((-uVar28 ^ uVar38) - uVar38 & 0xff ^ uVar38) - uVar38;
            if (iVar26 < 0x81) {
              if (iVar26 < 0x41) {
                iVar26 = (&FUN_0045A5C8)[iVar26];
              }
              else {
                iVar26 = (&DAT_0045A7C8)[-iVar26];
              }
            }
            else if (iVar26 + -0x80 < 0x41) {
              iVar26 = -*(int *)((int)&SciFiLevelStrings + iVar26 * 4 + 4);
            }
            else {
              iVar26 = -(&DAT_0045A9C8)[-iVar26];
            }
          }
          else if ((int)uVar27 < -0x800000) {
            if ((int)(-0x80 - uVar28) < 0x41) {
              iVar26 = -*(int *)((int)&SciFiLevelStrings + uVar28 * -4 + 4);
            }
            else {
              iVar26 = -(&DAT_0045A9C8)[uVar28];
            }
          }
          else {
            if (-0x400001 < (int)uVar27) {
              puVar16 = &FUN_0045A5C8;
              goto FUN_004415DB;
            }
            iVar26 = (&DAT_0045A7C8)[uVar28];
          }
FUN_004415E6:
          uVar38 = -iVar26;
        }
        else if ((int)uVar27 < 0x1000001) {
          if (0x800000 < (int)uVar27) {
            if ((int)(uVar28 - 0x80) < 0x41) {
              iVar26 = *(int *)((int)&SciFiLevelStrings + uVar28 * 4 + 4);
            }
            else {
              puVar16 = &DAT_0045A9C8;
FUN_004415DB:
              iVar26 = puVar16[-uVar28];
            }
            goto FUN_004415E6;
          }
          if ((int)uVar27 < 0x400001) {
            uVar38 = (&FUN_0045A5C8)[uVar28];
          }
          else {
            uVar38 = (&DAT_0045A7C8)[-uVar28];
          }
        }
        else {
          iVar26 = ((uVar28 ^ uVar17) - uVar17 & 0xff ^ uVar17) - uVar17;
          if (0x80 < iVar26) {
            if (iVar26 + -0x80 < 0x41) {
              iVar26 = *(int *)((int)&SciFiLevelStrings + iVar26 * 4 + 4);
            }
            else {
              iVar26 = (&DAT_0045A9C8)[-iVar26];
            }
            goto FUN_004415E6;
          }
          if (iVar26 < 0x41) {
            uVar38 = (&FUN_0045A5C8)[iVar26];
          }
          else {
            uVar38 = (&DAT_0045A7C8)[-iVar26];
          }
        }
        uVar40 = uVar28 + 0x40;
        if ((int)uVar40 < 0) {
          if ((int)(uVar28 + 0x40) < -0x100) {
            uVar40 = (int)(-uVar28 - 0x40) >> 0x1f;
            iVar26 = ((-uVar28 - 0x40 ^ uVar40) - uVar40 & 0xff ^ uVar40) - uVar40;
            if (iVar26 < 0x81) {
              if (iVar26 < 0x41) {
                ppuVar42 = (int**)(&FUN_0045A5C8)[iVar26];
              }
              else {
                ppuVar42 = (int**)(&DAT_0045A7C8)[-iVar26];
              }
            }
            else if (iVar26 + -0x80 < 0x41) {
              ppuVar42 = (int**)-*(int *)((int)&SciFiLevelStrings + iVar26 * 4 + 4);
            }
            else {
              ppuVar42 = (int**)-(&DAT_0045A9C8)[-iVar26];
            }
          }
          else if ((int)(uVar28 + 0x40) < -0x80) {
            if ((int)(-0xc0 - uVar28) < 0x41) {
              ppuVar42 = (int**)-*(int *)((int)&FUN_0045A2C0 + uVar28 * -4 + 8);
            }
            else {
              ppuVar42 = (int**)-*(int *)((int)&FUN_0045AA9C + uVar28 * 4 + 0x2c);
            }
          }
          else {
            if (-0x41 < (int)(uVar28 + 0x40)) {
              puVar16 = &PTR_ARRAY_0045A4C8;
              goto FUN_00441755;
            }
            ppuVar42 = (int**)(&DAT_0045A8C8)[uVar28];
          }
FUN_00441760:
          uVar40 = -(int)ppuVar42;
        }
        else if ((int)uVar40 < 0x101) {
          if (0x80 < (int)(uVar28 + 0x40)) {
            if ((int)(uVar28 - 0x40) < 0x41) {
              ppuVar42 = (int**)(&PTR_ARRAY_0045A4C8)[uVar28];
            }
            else {
              puVar16 = (int*)&DAT_0045A8C8;
FUN_00441755:
              ppuVar42 = (int**)puVar16[-uVar28];
            }
            goto FUN_00441760;
          }
          if ((int)(uVar28 + 0x40) < 0x41) {
            uVar40 = (&DAT_0045A6C8)[uVar28];
          }
          else {
            uVar40 = (&DAT_0045A6C8)[-uVar28];
          }
        }
        else {
          uVar29 = (int)uVar40 >> 0x1f;
          iVar26 = ((uVar40 ^ uVar29) - uVar29 & 0xff ^ uVar29) - uVar29;
          if (0x80 < iVar26) {
            if (iVar26 + -0x80 < 0x41) {
              ppuVar42 = *(int***)((int)&SciFiLevelStrings + iVar26 * 4 + 4);
            }
            else {
              ppuVar42 = (int**)(&DAT_0045A9C8)[-iVar26];
            }
            goto FUN_00441760;
          }
          if (iVar26 < 0x41) {
            uVar40 = (&FUN_0045A5C8)[iVar26];
          }
          else {
            uVar40 = (&DAT_0045A7C8)[-iVar26];
          }
        }
        local_64 = (local_94 ^ (int)local_94 >> 0x1f) - ((int)local_94 >> 0x1f);
        uVar29 = (uVar40 ^ (int)uVar40 >> 0x1f) - ((int)uVar40 >> 0x1f);
        local_24 = uVar29 & 0xffff;
        iVar26 = local_24 + (uVar29 & 0xffff0000);
        iVar24 = (int)local_64 >> 0x10;
        local_64 = local_64 & 0xffff;
        iVar30 = ((int)(local_24 * local_64) >> 0x10) + iVar26 * iVar24 + ((int)uVar29 >> 0x10) * local_64;
        local_10 = (unsigned int)(0 < (int)local_94);
        if (0 < (int)uVar40 != (local_10 != 0)) {
          iVar30 = -iVar30;
        }
        uVar14 = (local_60 ^ (int)local_60 >> 0x1f) - ((int)local_60 >> 0x1f);
        uVar15 = (uVar38 ^ (int)uVar38 >> 0x1f) - ((int)uVar38 >> 0x1f);
        local_20 = uVar15 & 0xffff;
        iVar31 = local_20 + (uVar15 & 0xffff0000);
        local_68 = uVar14 & 0xffff;
        iVar32 = (int)uVar14 >> 0x10;
        iVar41 = ((int)uVar15 >> 0x10) * local_68 + ((int)(local_20 * local_68) >> 0x10) + iVar31 * iVar32;
        local_c = (unsigned int)(0 < (int)uVar38);
        if (0 < (int)local_60 == (local_c != 0)) {
          iVar41 = -iVar41;
        }
        local_9c = (unsigned int)(iVar30 + iVar41);
        iVar26 = ((int)(local_24 * local_68) >> 0x10) + iVar26 * iVar32 + ((int)uVar29 >> 0x10) * local_68;
        if ((unsigned int)(0 < (int)uVar40) != (unsigned int)(0 < (int)local_60)) {
          iVar26 = -iVar26;
        }
        iVar24 = ((int)uVar15 >> 0x10) * local_64 + ((int)(local_20 * local_64) >> 0x10) + iVar31 * iVar24;
        if (local_c != local_10) {
          iVar24 = -iVar24;
        }
        local_c0 = (unsigned int)(iVar26 + iVar24);
        local_98 = local_c0;
        if ((int)uVar27 < 0) {
          if ((int)uVar27 < -0x1000000) {
            uVar27 = (int)-uVar28 >> 0x1f;
            iVar26 = ((-uVar28 ^ uVar27) - uVar27 & 0xff ^ uVar27) - uVar27;
            if (iVar26 < 0x81) {
              if (iVar26 < 0x41) {
                iVar26 = (&FUN_0045A5C8)[iVar26];
              }
              else {
                iVar26 = (&DAT_0045A7C8)[-iVar26];
              }
            }
            else if (iVar26 + -0x80 < 0x41) {
              iVar26 = -*(int *)((int)&SciFiLevelStrings + iVar26 * 4 + 4);
            }
            else {
              iVar26 = -(&DAT_0045A9C8)[-iVar26];
            }
          }
          else if ((int)uVar27 < -0x800000) {
            if ((int)(-0x80 - uVar28) < 0x41) {
              iVar26 = -*(int *)((int)&SciFiLevelStrings + uVar28 * -4 + 4);
            }
            else {
              iVar26 = -(&DAT_0045A9C8)[uVar28];
            }
          }
          else {
            if (-0x400001 < (int)uVar27) {
              puVar16 = &FUN_0045A5C8;
              goto FUN_00441AE5;
            }
            iVar26 = (&DAT_0045A7C8)[uVar28];
          }
FUN_00441AF0:
          uVar27 = -iVar26;
        }
        else if ((int)uVar27 < 0x1000001) {
          if (0x800000 < (int)uVar27) {
            if ((int)(uVar28 - 0x80) < 0x41) {
              iVar26 = *(int *)((int)&SciFiLevelStrings + uVar28 * 4 + 4);
            }
            else {
              puVar16 = &DAT_0045A9C8;
FUN_00441AE5:
              iVar26 = puVar16[-uVar28];
            }
            goto FUN_00441AF0;
          }
          if ((int)uVar27 < 0x400001) {
            uVar27 = (&FUN_0045A5C8)[uVar28];
          }
          else {
            uVar27 = (&DAT_0045A7C8)[-uVar28];
          }
        }
        else {
          iVar26 = ((uVar28 ^ uVar17) - uVar17 & 0xff ^ uVar17) - uVar17;
          if (0x80 < iVar26) {
            if (iVar26 + -0x80 < 0x41) {
              iVar26 = *(int *)((int)&SciFiLevelStrings + iVar26 * 4 + 4);
            }
            else {
              iVar26 = (&DAT_0045A9C8)[-iVar26];
            }
            goto FUN_00441AF0;
          }
          if (iVar26 < 0x41) {
            uVar27 = (&FUN_0045A5C8)[iVar26];
          }
          else {
            uVar27 = (&DAT_0045A7C8)[-iVar26];
          }
        }
        uVar17 = uVar28 + 0x40;
        if ((int)uVar17 < 0) {
          if ((int)(uVar28 + 0x40) < -0x100) {
            uVar17 = (int)(-uVar28 - 0x40) >> 0x1f;
            iVar26 = ((-uVar28 - 0x40 ^ uVar17) - uVar17 & 0xff ^ uVar17) - uVar17;
            if (iVar26 < 0x81) {
              if (iVar26 < 0x41) {
                ppuVar42 = (int**)(&FUN_0045A5C8)[iVar26];
              }
              else {
                ppuVar42 = (int**)(&DAT_0045A7C8)[-iVar26];
              }
            }
            else if (iVar26 + -0x80 < 0x41) {
              ppuVar42 = (int**)-*(int *)((int)&SciFiLevelStrings + iVar26 * 4 + 4);
            }
            else {
              ppuVar42 = (int**)-(&DAT_0045A9C8)[-iVar26];
            }
          }
          else if ((int)(uVar28 + 0x40) < -0x80) {
            if ((int)(-0xc0 - uVar28) < 0x41) {
              ppuVar42 = (int**)-*(int *)((int)&FUN_0045A2C0 + uVar28 * -4 + 8);
            }
            else {
              ppuVar42 = (int**)-*(int *)((int)&FUN_0045AA9C + uVar28 * 4 + 0x2c);
            }
          }
          else {
            if (-0x41 < (int)(uVar28 + 0x40)) {
              puVar16 = &PTR_ARRAY_0045A4C8;
              goto FUN_00441C57;
            }
            ppuVar42 = (int**)(&DAT_0045A8C8)[uVar28];
          }
FUN_00441C5E:
          uVar28 = -(int)ppuVar42;
        }
        else if ((int)uVar17 < 0x101) {
          if (0x80 < (int)(uVar28 + 0x40)) {
            if ((int)(uVar28 - 0x40) < 0x41) {
              ppuVar42 = (int**)(&PTR_ARRAY_0045A4C8)[uVar28];
            }
            else {
              puVar16 = (int*)&DAT_0045A8C8;
FUN_00441C57:
              ppuVar42 = (int**)puVar16[-uVar28];
            }
            goto FUN_00441C5E;
          }
          if ((int)(uVar28 + 0x40) < 0x41) {
            uVar28 = (&DAT_0045A6C8)[uVar28];
          }
          else {
            uVar28 = (&DAT_0045A6C8)[-uVar28];
          }
        }
        else {
          uVar28 = (int)uVar17 >> 0x1f;
          iVar26 = ((uVar17 ^ uVar28) - uVar28 & 0xff ^ uVar28) - uVar28;
          if (0x80 < iVar26) {
            if (iVar26 + -0x80 < 0x41) {
              ppuVar42 = *(int***)((int)&SciFiLevelStrings + iVar26 * 4 + 4);
            }
            else {
              ppuVar42 = (int**)(&DAT_0045A9C8)[-iVar26];
            }
            goto FUN_00441C5E;
          }
          if (iVar26 < 0x41) {
            uVar28 = (&FUN_0045A5C8)[iVar26];
          }
          else {
            uVar28 = (&DAT_0045A7C8)[-iVar26];
          }
        }
        uVar17 = (local_8c ^ (int)local_8c >> 0x1f) - ((int)local_8c >> 0x1f);
        uVar38 = (uVar28 ^ (int)uVar28 >> 0x1f) - ((int)uVar28 >> 0x1f);
        uVar40 = uVar17 & 0xffff;
        iVar26 = ((int)((uVar38 & 0xffff) * uVar40) >> 0x10) + ((uVar38 & 0xffff0000) + (uVar38 & 0xffff)) * ((int)uVar17 >> 0x10) + ((int)uVar38 >> 0x10) * uVar40;
        if (0 < (int)uVar28 != 0 < (int)local_8c) {
          iVar26 = -iVar26;
        }
        local_88 = local_90;
        local_84 = local_9c;
        local_5c = local_8c;
        iVar24 = FUN_00442DE0_GraphicsFlashingInner((int)local_60, (int)uVar27);
        uVar17 = (unsigned int)(iVar26 - iVar24);
        iVar26 = FUN_00442DE0_GraphicsFlashingInner((int)local_60, (int)uVar28);
        iVar24 = FUN_00442DE0_GraphicsFlashingInner((int)local_5c, (int)uVar27);
        uVar28 = (unsigned int)(iVar24 + iVar26);
        FUN_00442E50_GraphicsFlashingInner2((int*)&local_94, (int*)&local_90, (int)uVar3);
        FUN_00442E50_GraphicsFlashingInner2((int*)&local_8c, (int*)&local_88, (int)uVar3);
        uVar27 = uVar17;
        if (local_1c != 0x10000) {
          uVar27 = (local_84 ^ (int)local_84 >> 0x1f) - ((int)local_84 >> 0x1f);
          uVar38 = (local_1c ^ (int)local_1c >> 0x1f) - ((int)local_1c >> 0x1f);
          iVar26 = (int)uVar38 >> 0x10;
          uVar40 = uVar38 & 0xffff;
          local_9c = ((int)(uVar40 * (uVar27 & 0xffff)) >> 0x10) + ((uVar27 & 0xffff0000) + (uVar27 & 0xffff)) * iVar26 + ((int)uVar27 >> 0x10) * uVar40;
          bVar5 = (0 < (int)local_1c) ? 1 : 0;
          if (0 < (int)local_84 != bVar5) {
            local_9c = -local_9c;
          }
          uVar27 = (uVar17 ^ (int)uVar17 >> 0x1f) - ((int)uVar17 >> 0x1f);
          iVar24 = (uVar38 & 0xffff0000) + uVar40;
          uVar38 = uVar27 & 0xffff;
          uVar27 = (unsigned int)(iVar26 * uVar38 + ((int)uVar27 >> 0x10) * iVar24 + ((int)(uVar40 * uVar38) >> 0x10));
          if (0 < (int)uVar17 != bVar5) {
            uVar27 = -uVar27;
          }
          uVar17 = (local_94 ^ (int)local_94 >> 0x1f) - ((int)local_94 >> 0x1f);
          uVar38 = uVar17 & 0xffff;
          uVar17 = (unsigned int)(((int)(uVar38 * uVar40) >> 0x10) + ((int)uVar17 >> 0x10) * iVar24 + uVar38 * iVar26);
          if (0 < (int)local_94 != bVar5) {
            uVar17 = -uVar17;
          }
          uVar38 = (local_8c ^ (int)local_8c >> 0x1f) - ((int)local_8c >> 0x1f);
          uVar29 = uVar38 & 0xffff;
          uVar38 = (unsigned int)(((int)(uVar40 * uVar29) >> 0x10) + ((int)uVar38 >> 0x10) * iVar24 + iVar26 * uVar29);
          bVar6 = (0 < (int)local_8c) ? 1 : 0;
          local_94 = uVar17;
          local_8c = uVar38;
          if (bVar6 != bVar5) {
            local_8c = -uVar38;
          }
        }
        uVar17 = uVar28;
        if (local_18 != 0x10000) {
          uVar17 = (local_c0 ^ (int)local_c0 >> 0x1f) - ((int)local_c0 >> 0x1f);
          uVar38 = (local_18 ^ (int)local_18 >> 0x1f) - ((int)local_18 >> 0x1f);
          iVar24 = (int)uVar38 >> 0x10;
          uVar40 = uVar38 & 0xffff;
          iVar26 = uVar40 + (uVar38 & 0xffff0000);
          uVar38 = uVar17 & 0xffff;
          local_98 = (unsigned int)(((int)uVar17 >> 0x10) * iVar26 + ((int)(uVar40 * uVar38) >> 0x10) + iVar24 * uVar38);
          bVar5 = (0 < (int)local_18) ? 1 : 0;
          if (0 < (int)local_c0 != bVar5) {
            local_98 = -local_98;
          }
          uVar17 = (uVar28 ^ (int)uVar28 >> 0x1f) - ((int)uVar28 >> 0x1f);
          uVar38 = uVar17 & 0xffff;
          uVar17 = (unsigned int)(((int)(uVar40 * uVar38) >> 0x10) + ((int)uVar17 >> 0x10) * iVar26 + iVar24 * uVar38);
          if (0 < (int)uVar28 != bVar5) {
            uVar17 = -uVar17;
          }
          uVar28 = (local_90 ^ (int)local_90 >> 0x1f) - ((int)local_90 >> 0x1f);
          uVar38 = uVar28 & 0xffff;
          uVar28 = (unsigned int)(((int)(uVar40 * uVar38) >> 0x10) + ((int)uVar28 >> 0x10) * iVar26 + iVar24 * uVar38);
          if (0 < (int)local_90 != bVar5) {
            uVar28 = -uVar28;
          }
          uVar38 = (local_88 ^ (int)local_88 >> 0x1f) - ((int)local_88 >> 0x1f);
          uVar38 = (unsigned int)(((uVar38 & 0xffff0000) + (uVar38 & 0xffff)) * iVar24 + ((int)uVar38 >> 0x10) * uVar40 + ((int)((uVar38 & 0xffff) * uVar40) >> 0x10));
          bVar6 = (0 < (int)local_88) ? 1 : 0;
          local_90 = uVar28;
          local_88 = uVar38;
          if (bVar6 != bVar5) {
            local_88 = -uVar38;
          }
        }
        if (local_8 == 0) {
          if (local_14 == 0) {
            local_dc_0 = (int)((int)uVar27 + iVar12) >> 0x10;
            local_dc_1 = (int)((int)uVar17 + iVar13) >> 0x10;
            local_ec_0 = (int)((int)local_9c + iVar12) >> 0x10;
            local_ec_1 = (int)((int)local_98 + iVar13) >> 0x10;
            local_f0_0 = (int)((int)local_94 + iVar12) >> 0x10;
            local_f0_1 = (int)((int)local_90 + iVar13) >> 0x10;
            local_e0_0 = (int)((int)local_8c + iVar12) >> 0x10;
            local_e0_1 = (int)((int)local_88 + iVar13) >> 0x10;
          }
          else {
            local_e0_0 = (int)((int)uVar27 + iVar12) >> 0x10;
            local_e0_1 = (int)((int)uVar17 + iVar13) >> 0x10;
            local_f0_0 = (int)((int)local_9c + iVar12) >> 0x10;
            local_f0_1 = (int)((int)local_98 + iVar13) >> 0x10;
            local_ec_0 = (int)((int)local_94 + iVar12) >> 0x10;
            local_ec_1 = (int)((int)local_90 + iVar13) >> 0x10;
            local_dc_0 = (int)((int)local_8c + iVar12) >> 0x10;
            local_dc_1 = (int)((int)local_88 + iVar13) >> 0x10;
          }
        }
        else if (local_14 == 0) {
          local_ec_0 = (int)((int)uVar27 + iVar12) >> 0x10;
          local_ec_1 = (int)((int)uVar17 + iVar13) >> 0x10;
          local_dc_0 = (int)((int)local_9c + iVar12) >> 0x10;
          local_dc_1 = (int)((int)local_98 + iVar13) >> 0x10;
          local_e0_0 = (int)((int)local_94 + iVar12) >> 0x10;
          local_e0_1 = (int)((int)local_90 + iVar13) >> 0x10;
          local_f0_0 = (int)((int)local_8c + iVar12) >> 0x10;
          local_f0_1 = (int)((int)local_88 + iVar13) >> 0x10;
        }
        else {
          local_f0_0 = (int)((int)uVar27 + iVar12) >> 0x10;
          local_f0_1 = (int)((int)uVar17 + iVar13) >> 0x10;
          local_e0_0 = (int)((int)local_9c + iVar12) >> 0x10;
          local_e0_1 = (int)((int)local_98 + iVar13) >> 0x10;
          local_dc_0 = (int)((int)local_94 + iVar12) >> 0x10;
          local_dc_1 = (int)((int)local_90 + iVar13) >> 0x10;
          local_ec_0 = (int)((int)local_8c + iVar12) >> 0x10;
          local_ec_1 = (int)((int)local_88 + iVar13) >> 0x10;
        }
        sVar25 = (short)local_e0_0;
        if ((short)local_e0_0 <= (short)local_f0_0) {
          sVar25 = (short)local_f0_0;
        }
        sVar7 = (short)local_dc_0;
        if ((short)local_dc_0 <= (short)local_ec_0) {
          sVar7 = (short)local_ec_0;
        }
        if (sVar25 <= sVar7) {
          sVar25 = sVar7;
        }
        sVar7 = (short)local_e0_1;
        if ((short)local_f0_1 <= (short)local_e0_1) {
          sVar7 = (short)local_f0_1;
        }
        sVar8 = (short)local_dc_1;
        if ((short)local_ec_1 <= (short)local_dc_1) {
          sVar8 = (short)local_ec_1;
        }
        if (sVar8 <= sVar7) {
          sVar7 = sVar8;
        }
        sVar8 = (short)local_e0_1;
        if ((short)local_e0_1 <= (short)local_f0_1) {
          sVar8 = (short)local_f0_1;
        }
        sVar9 = (short)local_dc_1;
        if ((short)local_dc_1 <= (short)local_ec_1) {
          sVar9 = (short)local_ec_1;
        }
        if (sVar8 <= sVar9) {
          sVar8 = sVar9;
        }
        sVar9 = (short)local_e0_0;
        if ((short)local_f0_0 <= (short)local_e0_0) {
          sVar9 = (short)local_f0_0;
        }
        sVar35 = (short)local_dc_0;
        if ((short)local_ec_0 <= (short)local_dc_0) {
          sVar35 = (short)local_ec_0;
        }
        if (sVar35 <= sVar9) {
          sVar9 = sVar35;
        }
        if ((((sVar9 < 0x140) && (-1 < sVar25)) && (sVar7 < 0xf0)) && (-1 < sVar8)) {
          bVar2 = *(int*)(imageStruct + 4);
          iVar26 = *imageStruct >> 0x10;
          iVar24 = *local_58 >> 0x10;
          local_d4 = (unsigned int)param_1[0x17];
          if (local_d4 == 0) {
            local_d4 = (unsigned int)local_80[4];
          }
          uVar27 = FUN_0043E2C0(local_d4);
          if ((bVar2 & 0x40) == 0) {
            if (imageStruct[7] == 0) {
              local_b8 = FUN_0043E580_Image_Clean1(imageStruct);
            }
            else {
              local_b8 = FUN_0043E920_Image(imageStruct);
            }
          }
          else {
            local_b0 = (unsigned short*)(DAT_00460F6C + imageStruct[4] * 8);
          }
          if ((bVar2 & 3) != 2) {
            tileSelectPtr = local_4;
            if (local_4 == (int*)0x0) {
              tileSelectPtr = (int*)local_80[3];
            }
            uVar28 = FUN_0043ECF0_SelectTile_Clean1(tileSelectPtr);
            local_f6 = (short)uVar28;
          }
          sVar25 = *psVar34;
          pMVar36 = (int*)DAT_004A2AE4;
          while (sVar25 != 0) {
            if (pMVar36[5] < (unsigned int)DAT_004A2ADC) {
              DAT_004A2AE4 = (int)(pMVar36 + 5);
            } else {
              pMVar36 = (int*)DAT_004A2AE0;
              DAT_004A2AE4 = (int)(pMVar36 + 5);
            }
            {
              int tile_val = (int)(uVar27 | (-(unsigned int)((local_d4 & 0x8080) == 0) & 0xfe000000) + 0x2e000000);
              pMVar36[0] = tile_val;
            }
            *(short*)((int)&pMVar36[0] + 6) = local_f6;
            sVar25 = psVar34[2];
            puVar18 = (unsigned short*)local_f0_0;
            if ((sVar25 != 0) && (iVar30 = (int)sVar25, puVar18 = (unsigned short*)local_e0_0, iVar26 != iVar30)) {
              local_54_0 = local_f0_0;
              if ((short)local_e0_0 != (short)local_f0_0) {
                local_54_0 = local_f0_0 + ((((int)(short)local_e0_0 - (int)(short)local_f0_0) * iVar30) / iVar26);
              }
              sVar7 = (short)local_f0_1;
              if ((short)local_e0_1 != (short)local_f0_1) {
                sVar7 = (short)local_f0_1 + ((((int)local_e0_1 - (int)local_f0_1) * iVar30) / iVar26);
              }
              local_54_1 = sVar7;
              puVar18 = (unsigned short*)((local_54_1 << 16) | (local_54_0 & 0xffff));
            }
            puVar19 = (unsigned short*)local_ec_0;
            if ((sVar25 != 0) && (iVar30 = (int)sVar25, puVar19 = (unsigned short*)local_dc_0, iVar26 != iVar30)) {
              local_50_0 = local_ec_0;
              if ((short)local_dc_0 != (short)local_ec_0) {
                local_50_0 = local_ec_0 + ((((int)(short)local_dc_0 - (int)(short)local_ec_0) * iVar30) / iVar26);
              }
              sVar25 = (short)local_ec_1;
              if ((short)local_dc_1 != (short)local_ec_1) {
                sVar25 = (short)local_ec_1 + ((((int)local_dc_1 - (int)local_ec_1) * iVar30) / iVar26);
              }
              local_50_1 = sVar25;
              puVar19 = (unsigned short*)((local_50_1 << 16) | (local_50_0 & 0xffff));
            }
            puVar20 = puVar19;
            if ((psVar34[3] != 0) && (iVar30 = (int)psVar34[3], puVar20 = puVar18, iVar24 != iVar30)) {
              local_7c_0 = (int)puVar18;
              local_ac = (short)(int)puVar19;
              local_4c_0 = local_ac;
              if (local_ac != (short)local_7c_0) {
                local_4c_0 = local_ac + (short)((((int)(short)local_7c_0 - (int)local_ac) * iVar30) / iVar24);
              }
              local_7c_1 = (short)((unsigned int)puVar18 >> 0x10);
              sStack_aa = (short)((unsigned int)puVar19 >> 0x10);
              if (sStack_aa != local_7c_1) {
                sStack_aa = sStack_aa + (short)((((int)local_7c_1 - (int)sStack_aa) * iVar30) / iVar24);
              }
              local_4c_1 = sStack_aa;
              puVar20 = (unsigned short*)((local_4c_1 << 16) | (local_4c_0 & 0xffff));
            }
            pMVar36[1] = (int)puVar20;
            iVar30 = (int)(unsigned char)*(unsigned char*)(psVar34 + 1) + (int)psVar34[2];
            puVar19 = (unsigned short*)local_f0_0;
            if ((iVar30 != 0) && (puVar19 = (unsigned short*)local_e0_0, iVar26 != iVar30)) {
              local_48_0 = local_f0_0;
              if ((short)local_e0_0 != (short)local_f0_0) {
                local_48_0 = local_f0_0 + ((((int)(short)local_e0_0 - (int)(short)local_f0_0) * iVar30) / iVar26);
              }
              sVar25 = (short)local_f0_1;
              if ((short)local_e0_1 != (short)local_f0_1) {
                sVar25 = (short)local_f0_1 + ((((int)local_e0_1 - (int)local_f0_1) * iVar30) / iVar26);
              }
              local_48_1 = sVar25;
              puVar19 = (unsigned short*)((local_48_1 << 16) | (local_48_0 & 0xffff));
            }
            puVar20 = (unsigned short*)local_ec_0;
            if ((iVar30 != 0) && (puVar20 = (unsigned short*)local_dc_0, iVar26 != iVar30)) {
              local_44_0 = local_ec_0;
              if ((short)local_dc_0 != (short)local_ec_0) {
                local_44_0 = local_ec_0 + ((((int)(short)local_dc_0 - (int)(short)local_ec_0) * iVar30) / iVar26);
              }
              sVar25 = (short)local_ec_1;
              if ((short)local_dc_1 != (short)local_ec_1) {
                sVar25 = (short)local_ec_1 + ((((int)local_dc_1 - (int)local_ec_1) * iVar30) / iVar26);
              }
              local_44_1 = sVar25;
              puVar20 = (unsigned short*)((local_44_1 << 16) | (local_44_0 & 0xffff));
            }
            puVar21 = puVar20;
            if ((psVar34[3] != 0) && (iVar30 = (int)psVar34[3], puVar21 = puVar19, iVar24 != iVar30)) {
              local_78_0 = (int)puVar19;
              local_a8 = (short)(int)puVar20;
              local_40_0 = local_a8;
              if (local_a8 != (short)local_78_0) {
                local_40_0 = local_a8 + (short)((((int)(short)local_78_0 - (int)local_a8) * iVar30) / iVar24);
              }
              local_78_1 = (short)((unsigned int)puVar19 >> 0x10);
              sStack_a6 = (short)((unsigned int)puVar20 >> 0x10);
              if (sStack_a6 != local_78_1) {
                sStack_a6 = sStack_a6 + (short)((((int)local_78_1 - (int)sStack_a6) * iVar30) / iVar24);
              }
              local_40_1 = sStack_a6;
              puVar21 = (unsigned short*)((local_40_1 << 16) | (local_40_0 & 0xffff));
            }
            pMVar36[2] = (int)puVar21;
            sVar25 = psVar34[2];
            puVar20 = (unsigned short*)local_f0_0;
            if ((sVar25 != 0) && (iVar30 = (int)sVar25, puVar20 = (unsigned short*)local_e0_0, iVar26 != iVar30)) {
              local_3c_0 = local_f0_0;
              if ((short)local_e0_0 != (short)local_f0_0) {
                local_3c_0 = local_f0_0 + ((((int)(short)local_e0_0 - (int)(short)local_f0_0) * iVar30) / iVar26);
              }
              sVar7 = (short)local_f0_1;
              if ((short)local_e0_1 != (short)local_f0_1) {
                sVar7 = (short)local_f0_1 + ((((int)local_e0_1 - (int)local_f0_1) * iVar30) / iVar26);
              }
              local_3c_1 = sVar7;
              puVar20 = (unsigned short*)((local_3c_1 << 16) | (local_3c_0 & 0xffff));
            }
            puVar21 = (unsigned short*)local_ec_0;
            if ((sVar25 != 0) && (iVar30 = (int)sVar25, puVar21 = (unsigned short*)local_dc_0, iVar26 != iVar30)) {
              local_38_0 = local_ec_0;
              if ((short)local_dc_0 != (short)local_ec_0) {
                local_38_0 = local_ec_0 + ((((int)(short)local_dc_0 - (int)(short)local_ec_0) * iVar30) / iVar26);
              }
              sVar25 = (short)local_ec_1;
              if ((short)local_dc_1 != (short)local_ec_1) {
                sVar25 = (short)local_ec_1 + ((((int)local_dc_1 - (int)local_ec_1) * iVar30) / iVar26);
              }
              local_38_1 = sVar25;
              puVar21 = (unsigned short*)((local_38_1 << 16) | (local_38_0 & 0xffff));
            }
            iVar30 = (int)(unsigned char)*(unsigned char*)((int)psVar34 + 3) + (int)psVar34[3];
            puVar22 = puVar21;
            if ((iVar30 != 0) && (puVar22 = puVar20, iVar24 != iVar30)) {
              local_74_0 = (int)puVar20;
              local_a4 = (short)(int)puVar21;
              local_34_0 = local_a4;
              if (local_a4 != (short)local_74_0) {
                local_34_0 = local_a4 + (short)((((int)(short)local_74_0 - (int)local_a4) * iVar30) / iVar24);
              }
              local_74_1 = (short)((unsigned int)puVar20 >> 0x10);
              sStack_a2 = (short)((unsigned int)puVar21 >> 0x10);
              if (sStack_a2 != local_74_1) {
                sStack_a2 = sStack_a2 + (short)((((int)local_74_1 - (int)sStack_a2) * iVar30) / iVar24);
              }
              local_34_1 = sStack_a2;
              puVar22 = (unsigned short*)((local_34_1 << 16) | (local_34_0 & 0xffff));
            }
            *(int*)((int)pMVar36 + 12) = (int)puVar22;
            iVar30 = (int)(unsigned char)*(unsigned char*)(psVar34 + 1) + (int)psVar34[2];
            puVar21 = (unsigned short*)local_f0_0;
            if ((iVar30 != 0) && (puVar21 = (unsigned short*)local_e0_0, iVar26 != iVar30)) {
              local_30_0 = local_f0_0;
              if ((short)local_e0_0 != (short)local_f0_0) {
                local_30_0 = local_f0_0 + ((((int)(short)local_e0_0 - (int)(short)local_f0_0) * iVar30) / iVar26);
              }
              sVar25 = (short)local_f0_1;
              if ((short)local_e0_1 != (short)local_f0_1) {
                sVar25 = (short)local_f0_1 + ((((int)local_e0_1 - (int)local_f0_1) * iVar30) / iVar26);
              }
              local_30_1 = sVar25;
              puVar21 = (unsigned short*)((local_30_1 << 16) | (local_30_0 & 0xffff));
            }
            puVar22 = (unsigned short*)local_ec_0;
            if ((iVar30 != 0) && (puVar22 = (unsigned short*)local_dc_0, iVar26 != iVar30)) {
              local_2c_0 = local_ec_0;
              if ((short)local_dc_0 != (short)local_ec_0) {
                local_2c_0 = local_ec_0 + ((((int)(short)local_dc_0 - (int)(short)local_ec_0) * iVar30) / iVar26);
              }
              sVar25 = (short)local_ec_1;
              if ((short)local_dc_1 != (short)local_ec_1) {
                sVar25 = (short)local_ec_1 + ((((int)local_dc_1 - (int)local_ec_1) * iVar30) / iVar26);
              }
              local_2c_1 = sVar25;
              puVar22 = (unsigned short*)((local_2c_1 << 16) | (local_2c_0 & 0xffff));
            }
            iVar30 = (int)(unsigned char)*(unsigned char*)((int)psVar34 + 3) + (int)psVar34[3];
            puVar23 = puVar22;
            if ((iVar30 != 0) && (puVar23 = puVar21, iVar24 != iVar30)) {
              local_70_0 = (int)puVar21;
              local_a0 = (short)(int)puVar22;
              local_28_0 = local_a0;
              if (local_a0 != (short)local_70_0) {
                local_28_0 = local_a0 + (short)((((int)(short)local_70_0 - (int)local_a0) * iVar30) / iVar24);
              }
              local_70_1 = (short)((unsigned int)puVar21 >> 0x10);
              sStack_9e = (short)((unsigned int)puVar22 >> 0x10);
              if (sStack_9e != local_70_1) {
                sStack_9e = sStack_9e + (short)((((int)local_70_1 - (int)sStack_9e) * iVar30) / iVar24);
              }
              local_28_1 = sStack_9e;
              puVar23 = (unsigned short*)((local_28_1 << 16) | (local_28_0 & 0xffff));
            }
            pMVar36[4] = (int)puVar23;
            if ((bVar2 & 0x40) == 0) {
              unsigned short* puVar22_u16 = (unsigned short*)((int)&pMVar36[1] + 2);
              uVar10 = *(unsigned short*)(local_b8 + 4);
              if ((local_d4 & 1) == 0) {
                uVar10 = uVar10 | 0x20;
              }
              *puVar22_u16 = uVar10;
              DAT_004A2B20 = *puVar22_u16;
              *(char*)&pMVar36[0] = *(char*)((int)local_b8 + 0x12);
              *(char*)((int)&pMVar36[0] + 1) = *(char*)((int)local_b8 + 0x13);
              *(unsigned char*)&pMVar36[1] = *(unsigned char*)(psVar34 + 1) + *(char*)((int)local_b8 + 0x12) + -1;
              *(char*)((int)&pMVar36[1] + 1) = *(char*)((int)local_b8 + 0x13);
              *(char*)((int)&pMVar36[1] + 4) = *(char*)((int)local_b8 + 0x12);
              *(char*)((int)&pMVar36[1] + 5) = *(char*)((int)local_b8 + 0x13) + *(unsigned char*)((int)psVar34 + 3) + -1;
              *(unsigned char*)&pMVar36[2] = *(unsigned char*)(psVar34 + 1) + *(char*)((int)local_b8 + 0x12) + -1;
              *(unsigned char*)((int)&pMVar36[2] + 1) = *(char*)((int)local_b8 + 0x13) + *(unsigned char*)((int)psVar34 + 3) + -1;
              local_b8 = (int*)local_b8[1];
            }
            else {
              unsigned short* puVar22_u16 = (unsigned short*)((int)&pMVar36[1] + 2);
              uVar10 = *local_b0;
              if ((local_d4 & 1) == 0) {
                uVar10 = uVar10 | 0x20;
              }
              *puVar22_u16 = uVar10;
              DAT_004A2B20 = *puVar22_u16;
              *(char*)&pMVar36[0] = (char)local_b0[1];
              *(char*)((int)&pMVar36[0] + 1) = *(char*)((int)local_b0 + 3);
              *(unsigned char*)&pMVar36[1] = (char)local_b0[1] + *(unsigned char*)(psVar34 + 1) + -1;
              *(char*)((int)&pMVar36[1] + 1) = *(char*)((int)local_b0 + 3);
              *(char*)((int)&pMVar36[1] + 4) = (char)local_b0[1];
              *(char*)((int)&pMVar36[1] + 5) = *(unsigned char*)((int)psVar34 + 3) + *(char*)((int)local_b0 + 3) + -1;
              *(unsigned char*)&pMVar36[2] = (char)local_b0[1] + *(unsigned char*)(psVar34 + 1) + -1;
              *(unsigned char*)((int)&pMVar36[2] + 1) = *(unsigned char*)((int)psVar34 + 3) + *(char*)((int)local_b0 + 3) + -1;
              local_b0 = local_b0 + 4;
            }
            *(int*)DAT_004A2B18 = (int)pMVar36;
            ppuVar37 = (unsigned short**)(pMVar36 + 2);
            pMVar39 = pMVar36;
            ppuVar43 = ppuVar37;
            for (iVar30 = 10; iVar30 != 0; iVar30 = iVar30 + -1) {
              *ppuVar43 = (unsigned short*)pMVar39[0];
              pMVar39 = (int*)((int)pMVar39 + 4);
              ppuVar43 = ppuVar43 + 1;
            }
            if (local_f4 != 0) {
              *(short*)&pMVar36[3] = *(short*)&pMVar36[3] - local_f4;
              ppuVar43 = (unsigned short**)(pMVar36 + 2);
              *(short*)ppuVar43 = *(short*)ppuVar43 - local_f4;
              *(short*)&pMVar36[4] = *(short*)&pMVar36[4] - local_f4;
              ppuVar43 = (unsigned short**)(pMVar36 + 2);
              *(short*)ppuVar43 = *(short*)ppuVar43 - local_f4;
            }
            if (local_f2 != 0) {
              short* ps1 = (short*)((int)&pMVar36[3] + 2);
              *ps1 = *ps1 - local_f2;
              ps1 = (short*)((int)&pMVar36[2] + 2);
              *ps1 = *ps1 - local_f2;
              ps1 = (short*)((int)&pMVar36[4] + 2);
              *ps1 = *ps1 - local_f2;
              ps1 = (short*)((int)&pMVar36[2] + 2);
              *ps1 = *ps1 - local_f2;
            }
            psVar34 = psVar34 + 4;
            *(unsigned short**)DAT_004A2B14 = (unsigned short*)ppuVar37;
            pMVar36 = (int*)DAT_004A2AE4;
            sVar25 = *psVar34;
          }
        }
      }
      local_80 = (int*)local_6c[0];
    }
  }
  return;
}
