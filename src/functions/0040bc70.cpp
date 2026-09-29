// Adapted from pc_decomp_backup/src/functions/FUN_0040bc70.cpp
// Historical source SHA256: 1080e510e2b13ed6894bbea2fd61cbb88cf855e9368bdf1da16c5e3e460aa2f9
// Behavior candidate; original bytes are not claimed to match.
extern "C" {
extern int DAT_004561c8;
extern int DAT_0045a5c8;
extern int DAT_0045a7c8;
extern int DAT_0045a9c8;
extern unsigned char FUN_0045A3C4[];
unsigned int __cdecl FUN_0040c110(int, int);
void __cdecl FUN_00444590_DrawBehindAndInfrontObjects(unsigned int);
}


extern "C" void __cdecl
PrintWithFont_0040bc70(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            char *param_7,unsigned int param_8)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int uVar4;
  int uVar5;
  int uVar6;
  int uVar7;
  int uVar8;
  int uVar9;
  int iVar10;
  int iVar11;
  unsigned int uVar12;
  int iVar13;
  int *puVar14;
  unsigned int uVar15;
  int iVar16;
  unsigned int uVar17;
  int local_20;

  if (param_7 != (char *)0x0) {
    if (param_3 == 0x5a) {
      if (param_8 == 0) {
        param_8 = FUN_0040c110(param_5,param_4);
      }
      uVar17 = 0x100000;
    }
    else {
      if (param_8 == 0) {
        param_8 = FUN_0040c110(param_5,param_4);
      }
      uVar17 = 0xb0000;
    }
    iVar3 = *(int *)(param_8 + 200);
    uVar4 = *(int *)(param_8 + 0xcc);
    uVar12 = (unsigned int)*(unsigned char *)(param_8 + 0xb5);
    if ((uVar12 != 0) && (uVar12 != 10)) {
      *(int *)(param_8 + 200) = (int)(uVar12 * iVar3) / 10;
      *(int *)(param_8 + 0xcc) = (int)(*(int *)(param_8 + 0xcc) * uVar12) / 10;
      uVar17 = (uVar12 * uVar17) / 10;
    }
    uVar5 = *(int *)(param_8 + 0x78);
    uVar6 = *(int *)(param_8 + 0x7c);
    uVar7 = *(int *)(param_8 + 0x1fc);
    uVar8 = *(int *)(param_8 + 0x54);
    *(int *)(param_8 + 0x78) = param_1;
    *(int *)(param_8 + 0x7c) = param_2;
    iVar10 = (int)uVar17 >> 1;
    if ((*(unsigned int *)(param_8 + 0xb4) & 2) == 0) {
      if (param_6 == -1) {
        cVar2 = *param_7;
        while (cVar2 != '\0') {
          if (*param_7 == 0x20) {
            *(int *)(param_8 + 0x78) = iVar10 + 0x20000 + *(int *)(param_8 + 0x78);
            iVar16 = *(int *)(param_8 + 0x1f8) + iVar10 + 0x20000;
          }
          else {
            *(int *)(param_8 + 0x54) = *param_7 + -0x20;
            *(unsigned int *)(param_8 + 0xe0) = *(unsigned int *)(param_8 + 0xe0) | 0x1000000;
            FUN_00444590_DrawBehindAndInfrontObjects(param_8);
            *(unsigned int *)(param_8 + 0x78) = uVar17 + 0x20000 + *(int *)(param_8 + 0x78);
            iVar16 = uVar17 + 0x20000 + *(int *)(param_8 + 0x1f8);
          }
          param_7 = param_7 + 1;
          *(int *)(param_8 + 0x1f8) = iVar16;
          cVar2 = *param_7;
        }
      }
      else {
        local_20 = *(int *)(param_8 + 0xbc);
        cVar2 = *param_7;
        while (cVar2 != '\0') {
          if (*param_7 == 0x20) {
            *(int *)(param_8 + 0x78) = iVar10 + 0x20000 + *(int *)(param_8 + 0x78);
            *(int *)(param_8 + 0x1f8) = *(int *)(param_8 + 0x1f8) + iVar10 + 0x20000;
          }
          else {
            iVar11 = *param_7 + -0x20;
            *(int *)(param_8 + 0x54) = iVar11;
            iVar16 = *(int *)(param_8 + 0x7c);
            iVar13 = (*(int *)(param_8 + 0x78) + iVar16 + param_6) * 0x17 >> 0x10;
            uVar12 = iVar11 * 0xd + iVar13;
            if ((int)uVar12 < 0) {
              if ((int)uVar12 < -0x100) {
                uVar15 = (int)-uVar12 >> 0x1f;
                uVar12 = ((-uVar12 ^ uVar15) - uVar15 & 0xff ^ uVar15) - uVar15;
                if ((int)uVar12 < 0x81) {
                  if (0x40 < (int)uVar12) {
                    puVar14 = &DAT_0045a7c8;
                    goto FUN_0040BFC1;
                  }
                  iVar11 = (&DAT_0045a5c8)[uVar12];
                }
                else if ((int)(uVar12 - 0x80) < 0x41) {
                  iVar11 = -*(int *)(FUN_0045A3C4 + uVar12 * 4 + 4);
                }
                else {
                  iVar11 = -(&DAT_0045a9c8)[-uVar12];
                }
              }
              else if ((int)uVar12 < -0x80) {
                if ((-0x80 - iVar13) + iVar11 * -0xd < 0x41) {
                  iVar11 = -*(int *)(FUN_0045A3C4 + uVar12 * -4 + 4);
                }
                else {
                  iVar11 = -(&DAT_0045a9c8)[uVar12];
                }
              }
              else {
                if (-0x41 < (int)uVar12) {
                  puVar14 = &DAT_0045a5c8;
                  goto FUN_0040BFC1;
                }
                iVar11 = (&DAT_0045a7c8)[uVar12];
              }
FUN_0040BFC8:
              iVar11 = -iVar11;
            }
            else if ((int)uVar12 < 0x101) {
              if (0x80 < (int)uVar12) {
                if (0x40 < (int)(uVar12 - 0x80)) {
                  puVar14 = &DAT_0045a9c8;
                  goto FUN_0040BFC1;
                }
                iVar11 = *(int *)(FUN_0045A3C4 + uVar12 * 4 + 4);
                goto FUN_0040BFC8;
              }
              if ((int)uVar12 < 0x41) {
                iVar11 = (&DAT_0045a5c8)[uVar12];
              }
              else {
                iVar11 = (&DAT_0045a7c8)[-uVar12];
              }
            }
            else {
              uVar15 = (int)uVar12 >> 0x1f;
              uVar12 = ((uVar12 ^ uVar15) - uVar15 & 0xff ^ uVar15) - uVar15;
              if (0x80 < (int)uVar12) {
                if ((int)(uVar12 - 0x80) < 0x41) {
                  iVar11 = *(int *)(FUN_0045A3C4 + uVar12 * 4 + 4);
                }
                else {
                  puVar14 = &DAT_0045a9c8;
FUN_0040BFC1:
                  iVar11 = puVar14[-uVar12];
                }
                goto FUN_0040BFC8;
              }
              if ((int)uVar12 < 0x41) {
                iVar11 = (&DAT_0045a5c8)[uVar12];
              }
              else {
                iVar11 = (&DAT_0045a7c8)[-uVar12];
              }
            }
            iVar11 = iVar11 * 3 + iVar16;
            *(int *)(param_8 + 0x7c) = iVar11;
            *(int *)(param_8 + 0x1fc) = iVar11;
            *(unsigned int *)(param_8 + 0xe0) = *(unsigned int *)(param_8 + 0xe0) | 0x1000000;
            FUN_00444590_DrawBehindAndInfrontObjects(param_8);
            *(int *)(param_8 + 0x7c) = iVar16;
            *(unsigned int *)(param_8 + 0x78) = uVar17 + 0x20000 + *(int *)(param_8 + 0x78);
            *(unsigned int *)(param_8 + 0x1f8) = uVar17 + 0x20000 + *(int *)(param_8 + 0x1f8);
          }
          pcVar1 = param_7 + 1;
          param_7 = param_7 + 1;
          cVar2 = *pcVar1;
        }
        *(int *)(param_8 + 0xbc) = local_20;
      }
    }
    else {
      uVar9 = *(int *)(param_8 + 0xbc);
      *(int *)(param_8 + 0xbc) =
           *(int *)(&DAT_004561c8 + ((*(unsigned int *)(param_8 + 0xb4) & 0xf00000) >> 0x12));
      cVar2 = *param_7;
      while (cVar2 != '\0') {
        if (*param_7 == 0x20) {
          *(int *)(param_8 + 0x78) = iVar10 + 0x20000 + *(int *)(param_8 + 0x78);
          *(int *)(param_8 + 0x1f8) = *(int *)(param_8 + 0x1f8) + iVar10 + 0x20000;
        }
        else {
          *(int *)(param_8 + 0x54) = *param_7 + -0x20;
          *(unsigned int *)(param_8 + 0xe0) = *(unsigned int *)(param_8 + 0xe0) | 0x1000000;
          FUN_00444590_DrawBehindAndInfrontObjects(param_8);
          *(unsigned int *)(param_8 + 0x78) = uVar17 + 0x20000 + *(int *)(param_8 + 0x78);
          *(unsigned int *)(param_8 + 0x1f8) = uVar17 + 0x20000 + *(int *)(param_8 + 0x1f8);
        }
        pcVar1 = param_7 + 1;
        param_7 = param_7 + 1;
        cVar2 = *pcVar1;
      }
      *(int *)(param_8 + 0xbc) = uVar9;
      uVar17 = *(unsigned int *)(param_8 + 0xb4);
      if ((uVar17 & 0xf00000) == 0xa00000) {
        *(unsigned int *)(param_8 + 0xb4) = uVar17 & 0xfffffffd;
      }
      else {
        *(unsigned int *)(param_8 + 0xb4) = uVar17 + 0x40000;
      }
    }
    *(int *)(param_8 + 0x1f8) = uVar7;
    *(int *)(param_8 + 0x78) = uVar5;
    // Original 0040c0de restores the saved +0x1fc field after drawing.
    *(int *)(param_8 + 0x1fc) = uVar7;
    *(int *)(param_8 + 0x7c) = uVar6;
    *(int *)(param_8 + 200) = iVar3;
    *(int *)(param_8 + 0xcc) = uVar4;
    *(int *)(param_8 + 0x54) = uVar8;
  }
  return;
}
