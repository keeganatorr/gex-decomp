// Adapted from pc_decomp_backup/src/functions/FUN_0043fce0_DrawObjectsMid.cpp
// Historical source SHA256: 2dfcb1186eb746d1439442848e31baee86bb98afc7df3f21d1752bacdd18968b
// Behavior candidate; original bytes are not claimed to match.
extern "C" {
extern int DAT_004a2ae8;
extern short DAT_004a2a96;
extern short DAT_004a2a94;
extern unsigned char DAT_004a2af8;
extern unsigned char DAT_004a2af9;
extern unsigned char DAT_004a2afa;
extern int DAT_00460e08;
extern int* DAT_0046bc74;
extern int* DAT_0046bc70;
extern int* DAT_0046bc6c;
extern int* DAT_0046bc68;
extern int* DAT_004a2adc;
extern int* DAT_004a2ae0;
extern int* DAT_004a2ae4;
}


extern "C" unsigned int __cdecl FUN_0043ECF0(void*);
extern "C" void __cdecl FUN_00445350(int, int, int, int);


extern "C" void __cdecl FUN_0043fce0_DrawTilesInner(int param_1, int param_2,
                                    int param_3, int param_4)

{
  unsigned char bVar1;
  unsigned short uVar2;
  unsigned short *puVar3;
  short sVar4;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int uVar10;
  unsigned int uVar11;
  int iVar12;
  unsigned short uVar13;
  unsigned short uVar14;
  int *piVar15;
  int *piVar16;
  int *piVar17;
  int *piVar18;
  unsigned short local_44 [4];
  unsigned short *local_3c;
  unsigned short *local_38;
  int *local_34;
  int **local_30;
  int **local_2c;
  int local_28;
  int local_24;
  int local_20;
  int *local_1c;
  unsigned int local_18;
  unsigned short *local_14;
  unsigned int local_10;
  int local_c;
  int local_8;
  int local_4;
  short sVar5;

  local_c = DAT_004a2ae8;
  uVar11 = (int)DAT_004a2a96 >> 0x1f;
  iVar6 = ((int)DAT_004a2a96 ^ uVar11) - uVar11;
  iVar7 = iVar6 * 0x20000;
  uVar11 = (int)DAT_004a2a94 >> 0x1f;
  iVar8 = ((int)DAT_004a2a94 ^ uVar11) - uVar11;
  iVar9 = iVar8 * 0x20000;
  local_10 = ((unsigned int)DAT_004a2af8 * 0x100 + (unsigned int)DAT_004a2af9) * 0x100 + (unsigned int)DAT_004a2afa;
  local_44[0] = 0xffff;
  local_44[1] = 0xffff;
  if ((param_3 < iVar7 + 0x1400000) && (param_4 < iVar9 + 0xf00000)) {
    local_38 = (unsigned short *)(param_1 + 8);
    local_24 = 8;
    local_20 = 8;
    if (-param_3 != iVar7 && param_3 <= iVar6 * -0x20000) {
      iVar12 = iVar7 + param_3 + 0x1f0000 >> 0x15;
      local_38 = local_38 + -iVar12;
      local_24 = iVar12 + 8;
      param_3 = param_3 + iVar12 * -0x200000;
    }
    if (iVar7 + 0x400000 <= param_3) {
      local_24 = local_24 - (param_3 + iVar6 * -0x20000 + -0x400000 >> 0x15);
    }
    if (-param_4 != iVar9 && param_4 <= iVar8 * -0x20000) {
      iVar6 = param_4 + iVar9 + 0x1f0000 >> 0x15;
      local_38 = local_38 + iVar6 * -8;
      local_20 = iVar6 + 8;
      param_4 = param_4 + iVar6 * -0x200000;
    }
    if (iVar9 + -0x100000 <= param_4) {
      local_20 = local_20 - (param_4 + iVar8 * -0x20000 + 0x100000 >> 0x15);
    }
    local_4 = 8 - local_24;
    do {
      local_8 = local_24;
      local_28 = param_3;
      do {
        uVar14 = *local_38;
        if (uVar14 != 0) {
          local_44[2] = 2;
          uVar14 = *(unsigned short *)(*(int *)((uVar14 >> 3 & 0xfffc) + local_c) + (uVar14 & 0x1f) * 0x10);
          do {
            local_1c = (int *)(param_2 + (uVar14 & 0xfff) * 0xc);
            iVar6 = *local_1c;
            if (((iVar6 != 0) && (*(short *)(iVar6 + 0x14) != 0)) && (-1 < *(int *)(iVar6 + 8))) {
              bVar1 = *(unsigned char *)(iVar6 + 0x16);
              local_18 = (unsigned int)*(unsigned char *)(iVar6 + 0x17);
              local_3c = (unsigned short *)(DAT_00460e08 + *(short *)(iVar6 + 0x12) * 8);
              if ((uVar14 & 0x2000) == 0) {
                local_30 = &DAT_0046bc74;
                local_2c = &DAT_0046bc70;
                local_14 = local_44 + 1;
              }
              else {
                local_30 = &DAT_0046bc6c;
                local_2c = &DAT_0046bc68;
                local_14 = local_44;
              }
              if ((*(unsigned char *)(iVar6 + 0x10) & 3) != 2) {
                uVar10 = FUN_0043ECF0((void*)local_1c[1]);
                local_44[3] = (unsigned short)uVar10;
              }
              puVar3 = local_3c;
              uVar2 = local_44[3];
              uVar13 = (unsigned short)bVar1;
              sVar4 = (short)((unsigned int)param_4 >> 0x10);
              sVar5 = (short)((unsigned int)local_28 >> 0x10);
              if ((uVar14 & 0xc000) == 0) {
                piVar16 = DAT_004a2ae4 + 10;
                piVar15 = DAT_004a2ae4;
                DAT_004a2ae4 = piVar16;
                if (DAT_004a2adc < piVar16) {
                  piVar15 = DAT_004a2ae0;
                  DAT_004a2ae4 = DAT_004a2ae0 + 10;
                }
                local_34 = piVar15 + 5;
                piVar15[1] = (-(unsigned int)((local_1c[2] & 0x8080U) == 0) & 0xfe000000) + 0x66000000 |
                             local_10;
                *(short *)(piVar15 + 2) = sVar5 + *(short *)(iVar6 + 0x18);
                *(short *)((int)piVar15 + 10) = sVar4 + *(short *)(iVar6 + 0x1a);
                *(unsigned short *)(piVar15 + 4) = uVar13;
                *(short *)((int)piVar15 + 0x12) = (short)local_18;
                *(unsigned short *)(piVar15 + 3) = local_3c[1];
                *(unsigned short *)((int)piVar15 + 0xe) = local_44[3];
                piVar16 = piVar15;
                piVar17 = local_34;
                for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *piVar17 = *piVar16;
                  piVar16 = piVar16 + 1;
                  piVar17 = piVar17 + 1;
                }
                *(short *)(piVar15 + 7) = (short)piVar15[7] + DAT_004a2a96;
                *(short *)((int)piVar15 + 0x1e) = *(short *)((int)piVar15 + 0x1e) + DAT_004a2a94;
                if (*local_14 == *local_3c) {
                  *(int **)*local_30 = piVar15;
                  *local_30 = piVar15;
                  *(int **)*local_2c = local_34;
                  *local_2c = local_34;
                }
                else {
                  piVar17 = DAT_004a2ae4 + 6;
                  piVar16 = DAT_004a2ae4;
                  DAT_004a2ae4 = piVar17;
                  if (DAT_004a2adc < piVar17) {
                    piVar16 = DAT_004a2ae0;
                    DAT_004a2ae4 = DAT_004a2ae0 + 6;
                  }
                  *local_14 = *local_3c;
                  FUN_00445350((int)piVar16,0,1,(unsigned int)*puVar3);
                  *piVar16 = (int)piVar15;
                  *(int **)*local_30 = piVar16;
                  piVar17 = piVar16 + 3;
                  *local_30 = piVar15;
                  *piVar17 = *piVar16;
                  piVar16[4] = piVar16[1];
                  piVar16[5] = piVar16[2];
                  *piVar17 = (int)local_34;
                  *(int **)*local_2c = piVar17;
                  *local_2c = local_34;
                }
              }
              else {
                piVar16 = DAT_004a2ae4 + 0x14;
                piVar15 = DAT_004a2ae4;
                DAT_004a2ae4 = piVar16;
                if (DAT_004a2adc < piVar16) {
                  piVar15 = DAT_004a2ae0;
                  DAT_004a2ae4 = DAT_004a2ae0 + 0x14;
                }
                piVar15[1] = (-(unsigned int)((local_1c[2] & 0x8080U) == 0) & 0xfe000000) + 0x2e000000 |
                             local_10;
                if ((uVar14 & 0x4000) == 0) {
                  *(short *)(piVar15 + 2) = *(short *)(iVar6 + 0x18) + sVar5;
                  *(short *)((int)piVar15 + 10) = (sVar4 - *(short *)(iVar6 + 0x1a)) + 0x20;
                  *(unsigned short *)(piVar15 + 4) = *(short *)(iVar6 + 0x18) + sVar5 + uVar13;
                  *(short *)((int)piVar15 + 0x12) = (sVar4 - *(short *)(iVar6 + 0x1a)) + 0x20;
                  *(short *)(piVar15 + 6) = *(short *)(iVar6 + 0x18) + sVar5;
                  *(short *)((int)piVar15 + 0x1a) =
                       ((sVar4 - *(short *)(iVar6 + 0x1a)) - (short)local_18) + 0x20;
                  *(unsigned short *)(piVar15 + 8) = *(short *)(iVar6 + 0x18) + sVar5 + uVar13;
FUN_004402B3:
                  *(short *)((int)piVar15 + 0x22) =
                       ((sVar4 - *(short *)(iVar6 + 0x1a)) - (short)local_18) + 0x20;
                }
                else {
                  if ((uVar14 & 0x8000) != 0) {
                    *(short *)(piVar15 + 2) = (sVar5 - *(short *)(iVar6 + 0x18)) + 0x20;
                    *(short *)((int)piVar15 + 10) = (sVar4 - *(short *)(iVar6 + 0x1a)) + 0x20;
                    *(unsigned short *)(piVar15 + 4) = ((sVar5 - *(short *)(iVar6 + 0x18)) - uVar13) + 0x20;
                    *(short *)((int)piVar15 + 0x12) = (sVar4 - *(short *)(iVar6 + 0x1a)) + 0x20;
                    *(short *)(piVar15 + 6) = (sVar5 - *(short *)(iVar6 + 0x18)) + 0x20;
                    *(short *)((int)piVar15 + 0x1a) =
                         ((sVar4 - *(short *)(iVar6 + 0x1a)) - (short)local_18) + 0x20;
                    *(unsigned short *)(piVar15 + 8) = ((sVar5 - *(short *)(iVar6 + 0x18)) - uVar13) + 0x20;
                    goto FUN_004402B3;
                  }
                  *(short *)(piVar15 + 2) = (sVar5 - *(short *)(iVar6 + 0x18)) + 0x20;
                  *(short *)((int)piVar15 + 10) = *(short *)(iVar6 + 0x1a) + sVar4;
                  *(unsigned short *)(piVar15 + 4) = ((sVar5 - *(short *)(iVar6 + 0x18)) - uVar13) + 0x20;
                  *(short *)((int)piVar15 + 0x12) = *(short *)(iVar6 + 0x1a) + sVar4;
                  *(short *)(piVar15 + 6) = (sVar5 - *(short *)(iVar6 + 0x18)) + 0x20;
                  *(short *)((int)piVar15 + 0x1a) =
                       *(short *)(iVar6 + 0x1a) + sVar4 + (short)local_18;
                  *(unsigned short *)(piVar15 + 8) = ((sVar5 - *(short *)(iVar6 + 0x18)) - uVar13) + 0x20;
                  *(short *)((int)piVar15 + 0x22) =
                       *(short *)(iVar6 + 0x1a) + sVar4 + (short)local_18;
                }
                uVar14 = *local_3c;
                *(unsigned short *)((int)piVar15 + 0x16) = uVar14;
                *local_14 = uVar14;
                *(unsigned short *)((int)piVar15 + 0xe) = uVar2;
                *(char *)(piVar15 + 3) = (char)local_3c[1];
                *(unsigned char *)((int)piVar15 + 0xd) = *(unsigned char *)((int)local_3c + 3);
                *(unsigned char *)(piVar15 + 5) = (char)local_3c[1] + bVar1 + -1;
                *(unsigned char *)((int)piVar15 + 0x15) = *(unsigned char *)((int)local_3c + 3);
                *(char *)(piVar15 + 7) = (char)local_3c[1];
                *(char *)((int)piVar15 + 0x1d) = *(char *)((int)local_3c + 3) + (char)local_18 + -1;
                *(unsigned char *)(piVar15 + 9) = (char)local_3c[1] + bVar1 + -1;
                *(char *)((int)piVar15 + 0x25) = *(char *)((int)local_3c + 3) + (char)local_18 + -1;
                *(int **)*local_30 = piVar15;
                piVar16 = piVar15 + 10;
                *local_30 = piVar15;
                piVar17 = piVar15;
                piVar18 = piVar16;
                for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *piVar18 = *piVar17;
                  piVar17 = piVar17 + 1;
                  piVar18 = piVar18 + 1;
                }
                if (DAT_004a2a96 != 0) {
                  *(short *)(piVar15 + 0xc) = (short)piVar15[0xc] + DAT_004a2a96;
                  *(short *)(piVar15 + 0xe) = (short)piVar15[0xe] + DAT_004a2a96;
                  *(short *)(piVar15 + 0x10) = (short)piVar15[0x10] + DAT_004a2a96;
                  *(short *)(piVar15 + 0x12) = (short)piVar15[0x12] + DAT_004a2a96;
                }
                if (DAT_004a2a94 != 0) {
                  *(short *)((int)piVar15 + 0x32) = *(short *)((int)piVar15 + 0x32) + DAT_004a2a94;
                  *(short *)((int)piVar15 + 0x3a) = *(short *)((int)piVar15 + 0x3a) + DAT_004a2a94;
                  *(short *)((int)piVar15 + 0x42) = *(short *)((int)piVar15 + 0x42) + DAT_004a2a94;
                  *(short *)((int)piVar15 + 0x4a) = *(short *)((int)piVar15 + 0x4a) + DAT_004a2a94;
                }
                *(int **)*local_2c = piVar16;
                *local_2c = piVar16;
              }
            }
            local_44[2] = local_44[2] + -1;
            uVar14 = *(unsigned short *)
                      (*(int *)((*local_38 >> 3 & 0xfffc) + local_c) + 8 + (*local_38 & 0x1f) * 0x10
                      );
          } while (local_44[2] != 0);
        }
        local_28 = local_28 + 0x200000;
        local_38 = local_38 + 1;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
      param_4 = param_4 + 0x200000;
      local_38 = local_38 + local_4;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  return;
}
