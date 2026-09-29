// Adapted from pc_decomp_backup/src/functions/FUN_004432c0.cpp
// Historical source SHA256: a29d1793b2e215751d94d80df002e255d36f4804bdbcb8c67e82068c7a35ad5e
// Provisional behavior candidate; original bytes and gameplay are not claimed to match.
extern "C" {
extern int _DAT_00460F6C;
extern int _DAT_004A2988;
extern int _DAT_004A2A94;
extern int _DAT_004A2A96;
extern int* _DAT_004A2ADC;
extern int* _DAT_004A2AE0;
extern int* _DAT_004A2AE4;
extern int* _DAT_004A2B14;
extern int* _DAT_004A2B18;
extern int _DAT_004A2B20;
extern int DAT_004a2974_Camera;
extern int DAT_004a2ac8_FrameCount;
int __cdecl FUN_0041A500(int);
unsigned int __cdecl FUN_0043E2C0(unsigned int);
int* __cdecl FUN_0043E580(const char*);
int* __cdecl FUN_0043E920(const char*);
unsigned int __cdecl FUN_0043ECF0(unsigned int);
void __cdecl FUN_00444590_DrawBehindAndInfrontObjects(int);
}

extern "C" void __cdecl FUN_004432c0_Graphics(int param_1)
{
  unsigned char bVar1;
  unsigned int uVar2;
  unsigned int uVar3;
  unsigned int uVar4;
  unsigned int *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  unsigned short uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  unsigned int uVar14;
  int uVar15;
  unsigned int uVar16;
  int iVar17;
  unsigned int uVar18;
  unsigned int uVar19;
  unsigned int uVar20;
  int *piVar21;
  int *puVar22;
  int *puVar23;
  unsigned int uVar24;
  int *puVar25;
  unsigned int uVar26;
  int *puVar27;
  unsigned short local_5a;
  short local_58;
  short local_56;
  int local_50;
  int local_4c;
  int *local_48;
  int local_44;
  int local_40;
  unsigned short *local_3c;
  int *local_20;
  int *local_1c;
  unsigned int local_18;
  uVar2 = *(unsigned int *)(param_1 + 200);
  uVar3 = *(unsigned int *)(param_1 + 0);
  if ((uVar2 == 0) && (uVar3 == 0)) {
    FUN_00444590_DrawBehindAndInfrontObjects(param_1);
    return;
  }
  iVar11 = FUN_0041A500(param_1);
  if (iVar11 == 0) {
    return;
  }
  iVar12 = *(int *)(param_1 + 0) - DAT_004a2974_Camera;
  iVar13 = *(int *)(param_1 + 0) - _DAT_004A2988;
  uVar4 = *(unsigned int *)(param_1 + 0);
  if (((*(unsigned int *)(param_1 + 0) & 0) == 0) &&
     (*(int *)(param_1 + 500) - DAT_004a2ac8_FrameCount == -1)) {
    iVar17 = *(int *)(param_1 + 0) - *(int *)(param_1 + 0);
    if (iVar17 < 0) {
      iVar17 = iVar17 + 0;
    }
    local_58 = (short)(iVar17 >> 0) - _DAT_004A2A96;
    iVar17 = *(int *)(param_1 + 0) - *(int *)(param_1 + 0);
    if (iVar17 < 0) {
      iVar17 = iVar17 + 0;
    }
    local_56 = (short)(iVar17 >> 0) - _DAT_004A2A94;
    uVar18 = (int)local_56 >> 0;
    uVar19 = (int)local_58 >> 0;
    if ((int)(((((int)local_56 ^ uVar18) - uVar18) - uVar19) + ((int)local_58 ^ uVar19)) < 0)
    goto label_004433dc;
  }
  local_58 = 0;
  local_56 = 0;
label_004433dc:
  local_1c = *(int **)(iVar11 + 0);
  if (local_1c != (int *)0) {
    puVar5 = (unsigned int *)*local_1c;
    while (puVar5 != (unsigned int *)0) {
      local_1c = local_1c + 1;
      piVar6 = (int *)puVar5[2];
      piVar21 = piVar6 + 5;
      if ((short)*piVar21 != 0) {
        uVar18 = puVar5[1];
        uVar19 = *puVar5;
        uVar24 = *(unsigned int *)(param_1 + 0) >> 2 | uVar18;
        if ((uVar18 & 0) == 0) {
          local_50 = piVar6[2];
        }
        else {
          local_50 = *piVar6 - piVar6[2];
        }
        if ((uVar18 & 0) == 0) {
          local_4c = piVar6[3];
        }
        else {
          local_4c = piVar6[1] - piVar6[3];
        }
        if ((uVar24 & 0) == 0) {
          local_50 = local_50 + (uVar19 & 0) + iVar12;
        }
        else {
          local_50 = (iVar12 - local_50) - (uVar19 & 0);
        }
        if ((uVar24 & 0) == 0) {
          local_4c = local_4c + uVar19 * 0 + iVar13;
        }
        else {
          local_4c = (iVar13 - local_4c) + uVar19 * -0;
        }
        uVar24 = uVar24 ^ uVar24 * 4;
        uVar18 = uVar24 & 0;
        if (uVar18 == 0) {
          local_44 = local_50 + *piVar6;
        }
        else {
          local_44 = local_50;
          local_50 = local_50 - *piVar6;
        }
        uVar24 = uVar24 & 0;
        if (uVar24 == 0) {
          local_40 = local_4c + piVar6[1];
        }
        else {
          local_40 = local_4c;
          local_4c = local_4c - piVar6[1];
        }
        local_20 = piVar6 + 1;
        if (uVar2 == 0) {
          local_50 = local_50 >> 0;
        }
        else {
          uVar26 = local_50 - iVar12;
          uVar19 = (uVar26 ^ (int)uVar26 >> 0) - ((int)uVar26 >> 0);
          uVar14 = (uVar2 ^ (int)uVar2 >> 0) - ((int)uVar2 >> 0);
          uVar16 = uVar14 & 0;
          iVar17 = (uVar14 & 0) + uVar16;
          uVar20 = uVar19 & 0;
          iVar11 = ((int)uVar19 >> 0) * iVar17 + ((int)(uVar16 * uVar20) >> 0) +
                   ((int)uVar14 >> 0) * uVar20;
          if (0 < (int)uVar26 != 0 < (int)uVar2) {
            iVar11 = -iVar11;
          }
          local_50 = iVar12 + iVar11 >> 0;
          uVar26 = local_44 - iVar12;
          uVar19 = (uVar26 ^ (int)uVar26 >> 0) - ((int)uVar26 >> 0);
          uVar20 = uVar19 & 0;
          local_44 = ((int)(uVar16 * uVar20) >> 0) + ((int)uVar19 >> 0) * iVar17 +
                     ((int)uVar14 >> 0) * uVar20;
          if (0 < (int)uVar26 == 0 < (int)uVar2) {
            local_44 = local_44 + iVar12;
          }
          else {
            local_44 = iVar12 - local_44;
          }
        }
        local_44 = local_44 >> 0;
        iVar11 = local_44;
        if (uVar3 == 0) {
          local_4c = local_4c >> 0;
          local_40 = local_40 >> 0;
        }
        else {
          uVar19 = local_4c - iVar13;
          uVar14 = (uVar19 ^ (int)uVar19 >> 0) - ((int)uVar19 >> 0);
          uVar16 = (uVar3 ^ (int)uVar3 >> 0) - ((int)uVar3 >> 0);
          uVar20 = uVar14 & 0;
          uVar26 = uVar16 & 0;
          iVar17 = ((int)uVar16 >> 0) * uVar20 +
                   ((uVar16 & 0) + uVar26) * ((int)uVar14 >> 0) +
                   ((int)(uVar26 * uVar20) >> 0);
          if (0 < (int)uVar19 != 0 < (int)uVar3) {
            iVar17 = -iVar17;
          }
          local_4c = iVar13 + iVar17 >> 0;
          uVar14 = local_40 - iVar13;
          uVar19 = (uVar14 ^ (int)uVar14 >> 0) - ((int)uVar14 >> 0);
          iVar17 = ((uVar19 & 0) + (uVar19 & 0)) * ((int)uVar16 >> 0) +
                   ((int)uVar19 >> 0) * uVar26 + ((int)(uVar26 * (uVar19 & 0)) >> 0);
          if (0 < (int)uVar14 == 0 < (int)uVar3) {
            local_40 = iVar17 + iVar13 >> 0;
          }
          else {
            local_40 = iVar13 - iVar17 >> 0;
          }
        }
        iVar17 = local_4c;
        if ((((local_50 < 0) && (-1 < local_44)) && (local_4c < 0)) && (-1 < local_40)) {
          bVar1 = *(unsigned char *)(piVar6 + 4);
          iVar7 = *piVar6;
          iVar8 = *local_20;
          local_18 = *(unsigned int *)(param_1 + 0);
          if (local_18 == 0) {
            local_18 = puVar5[4];
          }
          uVar19 = FUN_0043E2C0(local_18);
          if (uVar18 == 0) {
            if (uVar24 != 0) {
              local_4c = local_40;
              local_40 = iVar17;
            }
          }
          else {
            local_44 = local_50;
            local_50 = iVar11;
            if (uVar24 != 0) {
              local_4c = local_40;
              local_40 = iVar17;
            }
          }
          if ((*(unsigned char *)(piVar6 + 4) & 0) == 0) {
            if ((short)piVar6[7] == 0) {
              local_48 = FUN_0043E580((const char*)piVar6);
            }
            else {
              local_48 = FUN_0043E920((const char*)piVar6);
            }
          }
          else {
            local_3c = (unsigned short *)(_DAT_00460F6C + *(short *)((int)piVar6 + 0) * 8);
          }
          if ((bVar1 & 3) != 2) {
            uVar18 = uVar4;
            if (uVar4 == 0) {
              uVar18 = puVar5[3];
            }
            uVar15 = FUN_0043ECF0(uVar18);
            local_5a = (unsigned short)uVar15;
          }
          if ((short)*piVar21 != 0) {
            do {
              puVar25 = _DAT_004A2AE4 + 0;
              puVar22 = _DAT_004A2AE4;
              _DAT_004A2AE4 = puVar25;
              if (_DAT_004A2ADC < puVar25) {
                puVar22 = _DAT_004A2AE0;
                _DAT_004A2AE4 = _DAT_004A2AE0 + 0;
              }
              puVar22[1] = uVar19 | (-(unsigned int)((local_18 & 0) == 0) & 0) + 0;
              *(unsigned short *)((int)puVar22 + 0) = local_5a;
              sVar9 = (short)(((int)(short)piVar21[1] * (local_44 - local_50)) / (iVar7 >> 0)) +
                      (short)local_50;
              *(short *)(puVar22 + 6) = sVar9;
              *(short *)(puVar22 + 2) = sVar9;
              sVar9 = (short)((int)(((unsigned int)*(unsigned char *)((int)piVar21 + 2) + (int)(short)piVar21[1]) *
                                   (local_44 - local_50)) / (iVar7 >> 0)) + (short)local_50;
              *(short *)(puVar22 + 8) = sVar9;
              *(short *)(puVar22 + 4) = sVar9;
              sVar9 = (short)(((int)*(short *)((int)piVar21 + 6) * (local_40 - local_4c)) /
                             (iVar8 >> 0)) + (short)local_4c;
              *(short *)((int)puVar22 + 0) = sVar9;
              *(short *)((int)puVar22 + 10) = sVar9;
              sVar9 = (short)((int)(((unsigned int)*(unsigned char *)((int)piVar21 + 3) +
                                    (int)*(short *)((int)piVar21 + 6)) * (local_40 - local_4c)) /
                             (iVar8 >> 0)) + (short)local_4c;
              *(short *)((int)puVar22 + 0) = sVar9;
              *(short *)((int)puVar22 + 0) = sVar9;
              if ((*(unsigned char *)(piVar6 + 4) & 0) == 0) {
                uVar10 = *(unsigned short *)(local_48 + 4);
                if ((local_18 & 1) == 0) {
                  uVar10 = uVar10 | 0;
                }
                *(unsigned short *)((int)puVar22 + 0) = uVar10;
                _DAT_004A2B20 = *(unsigned short *)((int)puVar22 + 0);
                *(unsigned char *)(puVar22 + 3) = *(unsigned char *)((int)local_48 + 0);
                *(unsigned char *)((int)puVar22 + 0) = *(unsigned char *)((int)local_48 + 0);
                *(char *)(puVar22 + 5) =
                     *(char *)((int)piVar21 + 2) + *(char *)((int)local_48 + 0) + -1;
                *(unsigned char *)((int)puVar22 + 0) = *(unsigned char *)((int)local_48 + 0);
                *(unsigned char *)(puVar22 + 7) = *(unsigned char *)((int)local_48 + 0);
                *(char *)((int)puVar22 + 0) =
                     *(char *)((int)piVar21 + 3) + *(char *)((int)local_48 + 0) + -1;
                *(char *)(puVar22 + 9) =
                     *(char *)((int)piVar21 + 2) + *(char *)((int)local_48 + 0) + -1;
                *(char *)((int)puVar22 + 0) =
                     *(char *)((int)piVar21 + 3) + *(char *)((int)local_48 + 0) + -1;
                local_48 = (int *)local_48[1];
              }
              else {
                uVar10 = *local_3c;
                if ((local_18 & 1) == 0) {
                  uVar10 = uVar10 | 0;
                }
                *(unsigned short *)((int)puVar22 + 0) = uVar10;
                _DAT_004A2B20 = *(unsigned short *)((int)puVar22 + 0);
                *(char *)(puVar22 + 3) = (char)local_3c[1];
                *(unsigned char *)((int)puVar22 + 0) = *(unsigned char *)((int)local_3c + 3);
                *(char *)(puVar22 + 5) = (char)local_3c[1] + *(char *)((int)piVar21 + 2) + -1;
                *(unsigned char *)((int)puVar22 + 0) = *(unsigned char *)((int)local_3c + 3);
                *(char *)(puVar22 + 7) = (char)local_3c[1];
                *(char *)((int)puVar22 + 0) =
                     *(char *)((int)local_3c + 3) + *(char *)((int)piVar21 + 3) + -1;
                *(char *)(puVar22 + 9) = (char)local_3c[1] + *(char *)((int)piVar21 + 2) + -1;
                *(char *)((int)puVar22 + 0) =
                     *(char *)((int)local_3c + 3) + *(char *)((int)piVar21 + 3) + -1;
                local_3c = local_3c + 4;
              }
              *(int**)_DAT_004A2B18 = puVar22;
              puVar23 = puVar22 + 10;
              puVar25 = puVar22;
              puVar27 = puVar23;
              _DAT_004A2B18 = puVar22;
              for (iVar11 = 10; iVar11 != 0; iVar11 = iVar11 + -1) {
                *puVar27 = *puVar25;
                puVar25 = puVar25 + 1;
                puVar27 = puVar27 + 1;
              }
              if (local_58 != 0) {
                *(short *)(puVar22 + 0) = *(short *)(puVar22 + 0) - local_58;
                *(short *)(puVar22 + 0) = *(short *)(puVar22 + 0) - local_58;
                *(short *)(puVar22 + 0) = *(short *)(puVar22 + 0) - local_58;
                *(short *)(puVar22 + 0) = *(short *)(puVar22 + 0) - local_58;
              }
              if (local_56 != 0) {
                *(short *)((int)puVar22 + 0) = *(short *)((int)puVar22 + 0) - local_56;
                *(short *)((int)puVar22 + 0) = *(short *)((int)puVar22 + 0) - local_56;
                *(short *)((int)puVar22 + 0) = *(short *)((int)puVar22 + 0) - local_56;
                *(short *)((int)puVar22 + 0) = *(short *)((int)puVar22 + 0) - local_56;
              }
              piVar21 = piVar21 + 2;
              *(int**)_DAT_004A2B14 = puVar23;
              _DAT_004A2B14 = puVar23;
            } while ((short)*piVar21 != 0);
          }
        }
      }
      puVar5 = (unsigned int *)*local_1c;
    }
  }
  return;
}
