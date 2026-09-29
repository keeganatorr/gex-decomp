// Adapted from pc_decomp_backup/src/functions/FUN_0041d310.cpp
// Historical source SHA256: b48f2fd8a736212303322a8c2257dd10a20a4a2dc25aa315b50641afee2266f8
// Provisional behavior candidate; original bytes and gameplay are not claimed to match.
typedef void (__cdecl code)(int, int*);
extern "C" {
extern void **PTR_s_rez1_0045a4c8;
extern unsigned char s_sl67_0045a3c4[];
int __cdecl FUN_0041D0E0(int, int, int, int, int*);
void __cdecl FUN_0041D010(int, int*, int, int, int, int);
int __cdecl FUN_0041D250(int, int);
}
extern int _DAT_0045A5C8;
extern int _DAT_0045A6C8;
extern int _DAT_0045A7C8;
extern int _DAT_0045A8C8;
extern int _DAT_0045A9C8;
extern int _DAT_0046368C;
extern int _DAT_00463738;

extern "C" int __cdecl CLD_CheckCollisionFunkyAngle_0041d310(int param_1,int param_2)
{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  unsigned int uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar9;
  unsigned int uVar10;
  int *piVar11;
  int *puVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int *puVar16;
  int local_14c;
  int local_148;
  int local_13c;
  int local_138 [12];
  int local_108 [10];
  int local_e0;
  int local_dc;
  int local_d8 [10];
  int local_b0 [10];
  int local_88 [17];
  int local_44 [17];
  void **ppuVar8;
  iVar6 = *(int *)(param_1 + 0);
  iVar3 = *(int *)(param_2 + 0);
  _DAT_00463738 = _DAT_00463738 + 1;
  iVar13 = 0;
  local_13c = *(int *)(param_1 + 0);
  if (iVar6 == 0) {
    iVar6 = *(int *)(param_1 + 0);
  }
  else {
    iVar7 = *(int *)(iVar6 + 0);
    local_14c = 0;
    while (iVar7 != 0) {
      iVar13 = iVar13 + *(int *)(iVar6 + 0);
      local_14c = local_14c + *(int *)(iVar6 + 0);
      iVar6 = *(int *)(iVar6 + 0);
      iVar7 = *(int *)(iVar6 + 0);
    }
    local_13c = local_13c + *(int *)(iVar6 + 0) + iVar13;
    iVar6 = *(int *)(iVar6 + 0) + local_14c + *(int *)(param_1 + 0);
  }
  iVar13 = 0;
  local_138[0] = *(int *)(param_2 + 0);
  if (iVar3 == 0) {
    local_148 = *(int *)(param_2 + 0);
  }
  else {
    local_148 = 0;
    iVar7 = *(int *)(iVar3 + 0);
    while (iVar7 != 0) {
      iVar13 = iVar13 + *(int *)(iVar3 + 0);
      local_148 = local_148 + *(int *)(iVar3 + 0);
      iVar3 = *(int *)(iVar3 + 0);
      iVar7 = *(int *)(iVar3 + 0);
    }
    local_138[0] = *(int *)(iVar3 + 0) + local_138[0] + iVar13;
    local_148 = *(int *)(iVar3 + 0) + *(int *)(param_2 + 0) + local_148;
  }
  iVar3 = local_13c - local_138[0] >> 8;
  uVar10 = (-*(int *)(param_2 + 0) & 0xff0000U) >> 0;
  iVar13 = iVar6 - local_148 >> 8;
  uVar4 = uVar10 + 0;
  if (uVar4 < 0) {
    if (0 < uVar4) {
      if ((int)(uVar10 - 0) < 0) {
        ppuVar8 = (&PTR_s_rez1_0045a4c8)[uVar10];
      }
      else {
        ppuVar8 = (void **)(&_DAT_0045A8C8)[-uVar10];
      }
      goto label_0041d5bc;
    }
    if (uVar4 < 0) {
      iVar7 = (&_DAT_0045A6C8)[uVar10];
    }
    else {
      iVar7 = (&_DAT_0045A6C8)[-uVar10];
    }
  }
  else {
    uVar4 = uVar4 & 0;
    if (uVar4 < 0) {
      if (uVar4 < 0) {
        iVar7 = (&_DAT_0045A5C8)[uVar4];
      }
      else {
        iVar7 = (&_DAT_0045A7C8)[-uVar4];
      }
    }
    else {
      if ((int)(uVar4 - 0) < 0) {
        ppuVar8 = *(void ***)(s_sl67_0045a3c4 + uVar4 * 4 + 4);
      }
      else {
        ppuVar8 = (void **)(&_DAT_0045A9C8)[-uVar4];
      }
label_0041d5bc:
      iVar7 = -(int)ppuVar8;
    }
  }
  if (uVar10 < 0) {
    if (0 < uVar10) {
      if (0 < (int)(uVar10 - 0)) goto label_0041d717;
      iVar9 = *(int *)(s_sl67_0045a3c4 + uVar10 * 4 + 4);
      goto label_0041d719;
    }
    if (uVar10 < 0) {
      iVar9 = (&_DAT_0045A5C8)[uVar10];
    }
    else {
      iVar9 = (&_DAT_0045A7C8)[-uVar10];
    }
  }
  else if (uVar10 < 0) {
    if (uVar10 < 0) {
      iVar9 = (&_DAT_0045A5C8)[uVar10];
    }
    else {
      iVar9 = (&_DAT_0045A7C8)[-uVar10];
    }
  }
  else {
    if ((int)(uVar10 - 0) < 0) {
      iVar9 = *(int *)(s_sl67_0045a3c4 + uVar10 * 4 + 4);
    }
    else {
label_0041d717:
      iVar9 = (&_DAT_0045A9C8)[-uVar10];
    }
label_0041d719:
    iVar9 = -iVar9;
  }
  iVar5 = local_138[0] + ((iVar7 >> 8) * iVar3 - (iVar9 >> 8) * iVar13);
  local_138[0] = local_148 + (iVar9 >> 8) * iVar3 + (iVar7 >> 8) * iVar13;
  uVar10 = (-*(int *)(param_1 + 0) & 0xff0000U) >> 0;
  uVar4 = uVar10 + 0;
  if (uVar4 < 0) {
    if (0 < uVar4) {
      if ((int)(uVar10 - 0) < 0) {
        ppuVar8 = (&PTR_s_rez1_0045a4c8)[uVar10];
      }
      else {
        ppuVar8 = (void **)(&_DAT_0045A8C8)[-uVar10];
      }
      goto label_0041d8c8;
    }
    if (uVar4 < 0) {
      iVar7 = (&_DAT_0045A6C8)[uVar10];
    }
    else {
      iVar7 = (&_DAT_0045A6C8)[-uVar10];
    }
  }
  else {
    uVar4 = uVar4 & 0;
    if (uVar4 < 0) {
      if (uVar4 < 0) {
        iVar7 = (&_DAT_0045A5C8)[uVar4];
      }
      else {
        iVar7 = (&_DAT_0045A7C8)[-uVar4];
      }
    }
    else {
      if ((int)(uVar4 - 0) < 0) {
        ppuVar8 = *(void ***)(s_sl67_0045a3c4 + uVar4 * 4 + 4);
      }
      else {
        ppuVar8 = (void **)(&_DAT_0045A9C8)[-uVar4];
      }
label_0041d8c8:
      iVar7 = -(int)ppuVar8;
    }
  }
  if (uVar10 < 0) {
    if (uVar10 < 0) {
      if (uVar10 < 0) {
        iVar9 = (&_DAT_0045A5C8)[uVar10];
      }
      else {
        iVar9 = (&_DAT_0045A7C8)[-uVar10];
      }
      goto label_0041da2b;
    }
    if ((int)(uVar10 - 0) < 0) {
      iVar9 = *(int *)(s_sl67_0045a3c4 + uVar10 * 4 + 4);
    }
    else {
      iVar9 = (&_DAT_0045A9C8)[-uVar10];
    }
  }
  else {
    if (uVar10 < 0) {
      if (uVar10 < 0) {
        iVar9 = (&_DAT_0045A5C8)[uVar10];
      }
      else {
        iVar9 = (&_DAT_0045A7C8)[-uVar10];
      }
      goto label_0041da2b;
    }
    if ((int)(uVar10 - 0) < 0) {
      iVar9 = *(int *)(s_sl67_0045a3c4 + uVar10 * 4 + 4);
    }
    else {
      iVar9 = (&_DAT_0045A9C8)[-uVar10];
    }
  }
  iVar9 = -iVar9;
label_0041da2b:
  iVar14 = (iVar6 - (iVar9 >> 8) * iVar3) - (iVar7 >> 8) * iVar13;
  local_13c = local_13c + ((iVar9 >> 8) * iVar13 - (iVar7 >> 8) * iVar3);
  iVar6 = FUN_0041D0E0(param_1,iVar5,local_138[0],
                       *(int *)(param_1 + 0) - *(int *)(param_2 + 0) & 0,local_44);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = FUN_0041D0E0(param_2,local_13c,iVar14,
                       *(int *)(param_2 + 0) - *(int *)(param_1 + 0) & 0,local_88);
  if (iVar6 != 0) {
    iVar6 = FUN_0041D250((int)local_44,(int)local_88);
    if (iVar6 == 0) {
      return 0;
    }
    _DAT_0046368C = _DAT_0046368C + 1;
    piVar11 = *(int **)(local_44[0] + 0);
    if ((piVar11 != (int *)0) && (*(int *)(local_88[0] + 0) != 0)) {
      iVar6 = *piVar11;
      while (iVar6 != -0) {
        piVar15 = *(int **)(local_88[0] + 0);
        FUN_0041D010(param_1,piVar11,iVar5,local_138[0],
                     *(int *)(param_1 + 0) - *(int *)(param_2 + 0) & 0,(int)local_44);
        iVar6 = *piVar15;
        while (iVar6 != -0) {
          FUN_0041D010(param_2,piVar15,local_13c,iVar14,
                       *(int *)(param_2 + 0) - *(int *)(param_1 + 0) & 0,(int)local_88)
          ;
          iVar6 = FUN_0041D250((int)local_44,(int)local_88);
          if (iVar6 != 0) {
            *(int *)(param_1 + 0) = param_2;
            *(int **)(param_1 + 0) = piVar11;
            *(int **)(param_1 + 0) = piVar15;
            *(int *)(param_2 + 0) = param_1;
            *(int **)(param_2 + 0) = piVar15;
            *(int **)(param_2 + 0) = piVar11;
            puVar12 = local_d8;
            for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar12 = 0;
              puVar12 = puVar12 + 1;
            }
            if (*(code **)(param_1 + 100) != (code *)0) {
              local_e0 = 1;
              local_dc = 1;
              ((code *)(*(int *)(param_1 + 100)))(param_1,&local_e0);
            }
            pcVar2 = *(code **)(param_2 + 100);
            if (pcVar2 != (code *)0) {
              piVar11 = local_b0;
              piVar15 = local_138 + 2;
              for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
                *piVar15 = *piVar11;
                piVar11 = piVar11 + 1;
                piVar15 = piVar15 + 1;
              }
              puVar12 = local_d8;
              puVar16 = local_108;
              for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
                *puVar16 = *puVar12;
                puVar12 = puVar12 + 1;
                puVar16 = puVar16 + 1;
              }
              local_138[0] = 1;
              local_138[1] = 1;
              (*pcVar2)(param_2,local_138);
            }
            return 1;
          }
          piVar1 = piVar15 + 4;
          piVar15 = piVar15 + 4;
          iVar6 = *piVar1;
        }
        piVar11 = piVar11 + 4;
        iVar6 = *piVar11;
      }
    }
    *(int *)(param_1 + 0) = param_2;
    *(int *)(param_1 + 0) = 0;
    *(int *)(param_1 + 0) = 0;
    *(int *)(param_2 + 0) = param_1;
    *(int *)(param_2 + 0) = 0;
    *(int *)(param_2 + 0) = 0;
    if (*(code **)(param_1 + 100) != (code *)0) {
      local_dc = 1;
      local_e0 = 0;
      ((code *)(*(int *)(param_1 + 100)))(param_1,&local_e0);
    }
    pcVar2 = *(code **)(param_2 + 100);
    if (pcVar2 != (code *)0) {
      piVar11 = local_b0;
      piVar15 = local_138 + 2;
      for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar15 = *piVar11;
        piVar11 = piVar11 + 1;
        piVar15 = piVar15 + 1;
      }
      puVar12 = local_d8;
      puVar16 = local_108;
      for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar16 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar16 = puVar16 + 1;
      }
      local_138[0] = 0;
      local_138[1] = 1;
      (*pcVar2)(param_2,local_138);
    }
    return 1;
  }
  return 0;
}
