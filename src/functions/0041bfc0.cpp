// Adapted from pc_decomp_backup/src/functions/FUN_0041bfc0_MakesWordPauseAppear.cpp
// Historical source SHA256: accba9b15f74724701eb04231b7459ba56682853f2075911655f0803526b05b9
// Provisional behavior candidate; original bytes and gameplay are not claimed to match.
extern "C" {
extern int DAT_00455b38;
extern int DAT_00455c24;
extern int DAT_00455c28;
extern int DAT_00455c4c;
extern int DAT_00456b00;
extern int DAT_004593b8;
extern int DAT_00459498;
extern int DAT_004594ac;
extern int DAT_004594b0;
extern int DAT_004594b4;
extern int DAT_004594b8;
extern int DAT_004594c0;
extern int DAT_004594e4;
extern int DAT_004594e8;
extern int DAT_0045a5c8;
extern int DAT_0045a6c8;
extern int DAT_0045a7c8;
extern int DAT_0045a8c8;
extern int DAT_0045a9c8;
extern int DAT_004635c0;
extern int DAT_004635c4;
extern int DAT_004635c8;
extern int DAT_004635f0;
extern int DAT_00463618;
extern int DAT_0046363c;
extern int DAT_00463640;
extern int DAT_00463648;
extern int DAT_0046366c;
extern int DAT_00463670;
extern int DAT_00463674;
extern int DAT_00463678;
extern int DAT_0046367c;
extern int DAT_004a0299;
extern int DAT_004a288c_BlockAnims0;
extern int DAT_004a2a1c;
extern int DAT_004a2a38_Camera;
extern char FUN_004594EC[];
extern unsigned char FUN_0045A2C0[];
extern unsigned char FUN_0045A3C4[];
extern unsigned char FUN_0045AA9C[];
extern unsigned char **PTR_s_rez1_0045a4c8;
void __cdecl FUN_00402f30_ChangeMusicTrack(void);
void __cdecl FUN_00402f70_MUS_FFF(void);
void __cdecl FUN_0041beb0(void);
int __cdecl FUN_00437e50(int, int);
void __cdecl FUN_0043faa0_OutputText(int, int, char*);
int __cdecl FUN_0043fae0_LoadString(char*);
void __cdecl FUN_00441150_Flashing(int);
}


/* WARNING: Removing unreachable block (ram,0x0041c4f1) */
/* WARNING: Removing unreachable block (ram,0x0041c556) */
/* WARNING: Removing unreachable block (ram,0x0041c58b) */
/* WARNING: Removing unreachable block (ram,0x0041c59e) */
/* WARNING: Removing unreachable block (ram,0x0041c592) */
/* WARNING: Removing unreachable block (ram,0x0041c55d) */
/* WARNING: Removing unreachable block (ram,0x0041c577) */
/* WARNING: Removing unreachable block (ram,0x0041c56c) */
/* WARNING: Removing unreachable block (ram,0x0041c4f8) */
/* WARNING: Removing unreachable block (ram,0x0041c53a) */
/* WARNING: Removing unreachable block (ram,0x0041c54d) */
/* WARNING: Removing unreachable block (ram,0x0041c53f) */
/* WARNING: Removing unreachable block (ram,0x0041c514) */
/* WARNING: Removing unreachable block (ram,0x0041c52f) */
/* WARNING: Removing unreachable block (ram,0x0041c51c) */
/* WARNING: Removing unreachable block (ram,0x0041c668) */
/* WARNING: Removing unreachable block (ram,0x0041c6ca) */
/* WARNING: Removing unreachable block (ram,0x0041c6f6) */
/* WARNING: Removing unreachable block (ram,0x0041c704) */
/* WARNING: Removing unreachable block (ram,0x0041c6fb) */
/* WARNING: Removing unreachable block (ram,0x0041c6cf) */
/* WARNING: Removing unreachable block (ram,0x0041c6e6) */
/* WARNING: Removing unreachable block (ram,0x0041c6db) */
/* WARNING: Removing unreachable block (ram,0x0041c66f) */
/* WARNING: Removing unreachable block (ram,0x0041c6ae) */
/* WARNING: Removing unreachable block (ram,0x0041c6c1) */
/* WARNING: Removing unreachable block (ram,0x0041c6b3) */
/* WARNING: Removing unreachable block (ram,0x0041c68b) */
/* WARNING: Removing unreachable block (ram,0x0041c6a3) */
/* WARNING: Removing unreachable block (ram,0x0041c693) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

extern "C" void __cdecl ProcessPaused_0041bfc0(int *param_1)

{
  int uVar1;
  unsigned int uVar2;
  int *puVar3;
  int iVar4;
  unsigned int uVar5;
  int iVar6;
  int iVar7;
  unsigned int uVar8;
  unsigned char ***pppuVar9;
  int *puVar10;
  unsigned char **ppuVar11;
  char *text;
  int local_204 [129];

  puVar3 = param_1;
  puVar10 = local_204;
  for (iVar7 = 0x81; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar10 = puVar10 + 1;
  }
  if (DAT_004594e4 != 0) {
    DAT_004594e4 = 0;
    FUN_00402f70_MUS_FFF();
    FUN_0041beb0();
    DAT_004635c0 = 0;
    DAT_00463670 = 0;
    DAT_0046366c = 0x1518;
  }
  if ((DAT_004594e4 == 0) && (DAT_004a0299 != '\0')) {
    DAT_004a0299 = '\0';
    DAT_004594e8 = 1;
  }
  if (DAT_004594e8 != 0) {
    DAT_004594e8 = 0;
    DAT_004a288c_BlockAnims0 = 0;
    DAT_004594e4 = 1;
    DAT_00455c4c = DAT_00455c4c + -1;
    FUN_00402f30_ChangeMusicTrack();
    goto switchD_0041c8fe_caseD_7;
  }
  if ((((DAT_0046363c < 0) || (0x13fffff < DAT_0046363c)) || (DAT_00463640 < 0)) ||
     (0xefffff < DAT_00463640)) {
    FUN_0041beb0();
  }
                    /* check what this does? */
  if (DAT_0046366c < 1) {
    uVar2 = DAT_0046367c & 0xffff0000;
    uVar8 = (int)DAT_0046367c >> 0x10;
    if ((int)uVar2 < 0) {
      if ((int)uVar2 < -0x1000000) {
        uVar2 = (int)-uVar8 >> 0x1f;
        iVar7 = ((-uVar8 ^ uVar2) - uVar2 & 0xff ^ uVar2) - uVar2;
        if (iVar7 < 0x81) {
          if (iVar7 < 0x41) {
            iVar7 = (&DAT_0045a5c8)[iVar7];
          }
          else {
            iVar7 = (&DAT_0045a7c8)[-iVar7];
          }
        }
        else if (iVar7 + -0x80 < 0x41) {
          iVar7 = -*(int *)(FUN_0045A3C4 + iVar7 * 4 + 4);
        }
        else {
          iVar7 = -(&DAT_0045a9c8)[-iVar7];
        }
      }
      else if ((int)uVar2 < -0x800000) {
        if ((int)(-0x80 - uVar8) < 0x41) {
          iVar7 = -*(int *)(FUN_0045A3C4 + uVar8 * -4 + 4);
        }
        else {
          iVar7 = -(&DAT_0045a9c8)[uVar8];
        }
      }
      else {
        if (-0x400001 < (int)uVar2) {
          puVar3 = &DAT_0045a5c8;
          goto FUN_0041C243;
        }
        iVar7 = (&DAT_0045a7c8)[uVar8];
      }
FUN_0041C24E:
      uVar2 = -iVar7;
    }
    else if ((int)uVar2 < 0x1000001) {
      if (0x800000 < (int)uVar2) {
        if ((int)(uVar8 - 0x80) < 0x41) {
          iVar7 = *(int *)(FUN_0045A3C4 + uVar8 * 4 + 4);
        }
        else {
          puVar3 = &DAT_0045a9c8;
FUN_0041C243:
          iVar7 = puVar3[-uVar8];
        }
        goto FUN_0041C24E;
      }
      if ((int)uVar2 < 0x400001) {
        uVar2 = (&DAT_0045a5c8)[uVar8];
      }
      else {
        uVar2 = (&DAT_0045a7c8)[-uVar8];
      }
    }
    else {
      uVar2 = (int)DAT_0046367c >> 0x1f;
      iVar7 = ((uVar8 ^ uVar2) - uVar2 & 0xff ^ uVar2) - uVar2;
      if (0x80 < iVar7) {
        if (iVar7 + -0x80 < 0x41) {
          iVar7 = *(int *)(FUN_0045A3C4 + iVar7 * 4 + 4);
        }
        else {
          iVar7 = (&DAT_0045a9c8)[-iVar7];
        }
        goto FUN_0041C24E;
      }
      if (iVar7 < 0x41) {
        uVar2 = (&DAT_0045a5c8)[iVar7];
      }
      else {
        uVar2 = (&DAT_0045a7c8)[-iVar7];
      }
    }
    uVar5 = uVar8 + 0x40;
    if ((int)uVar5 < 0) {
      if ((int)uVar5 < -0x100) {
        uVar5 = (int)(-uVar8 - 0x40) >> 0x1f;
        iVar7 = ((-uVar8 - 0x40 ^ uVar5) - uVar5 & 0xff ^ uVar5) - uVar5;
        if (iVar7 < 0x81) {
          if (iVar7 < 0x41) {
            ppuVar11 = (unsigned char **)(&DAT_0045a5c8)[iVar7];
          }
          else {
            ppuVar11 = (unsigned char **)(&DAT_0045a7c8)[-iVar7];
          }
        }
        else if (iVar7 + -0x80 < 0x41) {
          ppuVar11 = (unsigned char **)-*(int *)(FUN_0045A3C4 + iVar7 * 4 + 4);
        }
        else {
          ppuVar11 = (unsigned char **)-(&DAT_0045a9c8)[-iVar7];
        }
      }
      else if ((int)uVar5 < -0x80) {
        if ((int)(-0xc0 - uVar8) < 0x41) {
          ppuVar11 = (unsigned char **)-*(int *)(FUN_0045A2C0 + uVar8 * -4 + 8);
        }
        else {
          ppuVar11 = (unsigned char **)
                     -*(int *)(FUN_0045AA9C + uVar8 * 4 + 0x2c);
        }
      }
      else {
        if (-0x41 < (int)uVar5) {
          pppuVar9 = &PTR_s_rez1_0045a4c8;
          goto FUN_0041C3A6;
        }
        ppuVar11 = (unsigned char **)(&DAT_0045a8c8)[uVar8];
      }
FUN_0041C3AD:
      uVar8 = -(int)ppuVar11;
    }
    else if ((int)uVar5 < 0x101) {
      if (0x80 < (int)uVar5) {
        if ((int)(uVar8 - 0x40) < 0x41) {
          ppuVar11 = (&PTR_s_rez1_0045a4c8)[uVar8];
        }
        else {
          pppuVar9 = (unsigned char ***)&DAT_0045a8c8;
FUN_0041C3A6:
          ppuVar11 = pppuVar9[-uVar8];
        }
        goto FUN_0041C3AD;
      }
      if ((int)uVar5 < 0x41) {
        uVar8 = (&DAT_0045a6c8)[uVar8];
      }
      else {
        uVar8 = (&DAT_0045a6c8)[-uVar8];
      }
    }
    else {
      uVar8 = (int)uVar5 >> 0x1f;
      iVar7 = ((uVar5 ^ uVar8) - uVar8 & 0xff ^ uVar8) - uVar8;
      if (0x80 < iVar7) {
        if (iVar7 + -0x80 < 0x41) {
          ppuVar11 = *(unsigned char ***)(FUN_0045A3C4 + iVar7 * 4 + 4);
        }
        else {
          ppuVar11 = (unsigned char **)(&DAT_0045a9c8)[-iVar7];
        }
        goto FUN_0041C3AD;
      }
      if (iVar7 < 0x41) {
        uVar8 = (&DAT_0045a5c8)[iVar7];
      }
      else {
        uVar8 = (&DAT_0045a7c8)[-iVar7];
      }
    }
    iVar7 = FUN_00437e50(uVar8,0);
    iVar4 = FUN_00437e50(uVar2,-DAT_004594ac);
    DAT_0046363c = DAT_0046363c + (iVar7 - iVar4);
    iVar7 = FUN_00437e50(uVar8,-DAT_004594ac);
    iVar4 = FUN_00437e50(uVar2,0);
    DAT_00463640 = DAT_00463640 + (iVar7 - iVar4);
    uVar2 = (-(unsigned int)(DAT_004635c4 == 0) & 0x800000) + 0x400000 + DAT_0046367c & 0xff0000;
    uVar8 = (int)uVar2 >> 0x10;
    if (uVar2 < 0x1000001) {
      if (0x800000 < uVar2) {
        if ((int)(uVar8 - 0x80) < 0x41) {
          iVar7 = *(int *)(FUN_0045A3C4 + uVar8 * 4 + 4);
        }
        else {
          iVar7 = (&DAT_0045a9c8)[-uVar8];
        }
        goto FUN_0041C5B1;
      }
      if (uVar2 < 0x400001) {
        uVar2 = (&DAT_0045a5c8)[uVar8];
      }
      else {
        uVar2 = (&DAT_0045a7c8)[-uVar8];
      }
    }
    else if (uVar8 < 0x81) {
      if (uVar8 < 0x41) {
        uVar2 = (&DAT_0045a5c8)[uVar8];
      }
      else {
        uVar2 = (&DAT_0045a7c8)[-uVar8];
      }
    }
    else {
      if ((int)(uVar8 - 0x80) < 0x41) {
        iVar7 = *(int *)(FUN_0045A3C4 + uVar8 * 4 + 4);
      }
      else {
        iVar7 = (&DAT_0045a9c8)[-uVar8];
      }
FUN_0041C5B1:
      uVar2 = -iVar7;
    }
    uVar5 = uVar8 + 0x40;
    if (uVar5 < 0x101) {
      if (0x80 < uVar5) {
        if ((int)(uVar8 - 0x40) < 0x41) {
          ppuVar11 = (&PTR_s_rez1_0045a4c8)[uVar8];
        }
        else {
          ppuVar11 = (unsigned char **)(&DAT_0045a8c8)[-uVar8];
        }
        goto FUN_0041C710;
      }
      if (uVar5 < 0x41) {
        uVar8 = (&DAT_0045a6c8)[uVar8];
      }
      else {
        uVar8 = (&DAT_0045a6c8)[-uVar8];
      }
    }
    else {
      uVar5 = uVar5 & 0xff;
      if (uVar5 < 0x81) {
        if (uVar5 < 0x41) {
          uVar8 = (&DAT_0045a5c8)[uVar5];
        }
        else {
          uVar8 = (&DAT_0045a7c8)[-uVar5];
        }
      }
      else {
        if ((int)(uVar5 - 0x80) < 0x41) {
          ppuVar11 = *(unsigned char ***)(FUN_0045A3C4 + uVar5 * 4 + 4);
        }
        else {
          ppuVar11 = (unsigned char **)(&DAT_0045a9c8)[-uVar5];
        }
FUN_0041C710:
        uVar8 = -(int)ppuVar11;
      }
    }
    iVar7 = FUN_00437e50(uVar8,0);
    iVar4 = FUN_00437e50(uVar2,-DAT_004594b0);
    DAT_00463674 = (iVar7 - iVar4) + DAT_0046363c;
    iVar4 = FUN_00437e50(uVar8,-DAT_004594b0);
    iVar6 = FUN_00437e50(uVar2,0);
    uVar8 = DAT_0046367c;
    iVar7 = DAT_004635c0;
    iVar4 = (iVar4 - iVar6) + DAT_00463640;
    uVar2 = (unsigned int)(DAT_004635c4 == 0);
    DAT_0046366c = DAT_004594b8;
    DAT_004635c4 = uVar2;
    DAT_00463678 = iVar4;
    if (DAT_004593b8 != 0) {
      (&DAT_004635f0)[DAT_004635c0] = DAT_004a2a38_Camera + DAT_00463674;
      (&DAT_00463618)[iVar7] = uVar8;
      (&DAT_004635c8)[iVar7] = DAT_004a2a1c + iVar4;
      if (uVar2 == 0) {
        uVar2 = param_1[0x1b] & 0x7fffffff;
      }
      else {
        uVar2 = param_1[0x1b] | 0x80000000;
      }
      (&DAT_00463648)[iVar7] = uVar2;
      DAT_004635c0 = DAT_004635c0 + 1;
      if (DAT_004635c0 == 9) {
        DAT_004635c0 = 0;
      }
      if (DAT_00463670 < 9) {
        DAT_00463670 = DAT_00463670 + 1;
      }
      iVar7 = 0;
      if (0 < DAT_00463670) {
        puVar3 = &DAT_004594c0;
        iVar4 = DAT_004635c0;
        do {
          iVar4 = iVar4 + -1;
          if (iVar4 < 0) {
            iVar4 = 8;
          }
          iVar7 = iVar7 + 1;
          uVar1 = *(int *)(DAT_004593b8 + 0xc);
          param_1[0x14] = 2;
          param_1[0x15] = 1;
          param_1[3] = uVar1;
          param_1[0x1e] = (&DAT_004635f0)[iVar4];
          param_1[0x1f] = (&DAT_004635c8)[iVar4];
          param_1[0x31] = (&DAT_00463618)[iVar4];
          param_1[0x32] = DAT_004594b4;
          param_1[0x33] = DAT_004594b4;
          param_1[0x1b] = (&DAT_00463648)[iVar4];
          param_1[0x2f] = *puVar3;
          FUN_00441150_Flashing((int)param_1);
          puVar3 = puVar3 + 1;
        } while (iVar7 < DAT_00463670);
      }
    }
  }
  else {
    DAT_0046366c = DAT_0046366c + -1;
  }
  text = FUN_004594EC;
  iVar4 = 0x6e0000;
  iVar7 = FUN_0043fae0_LoadString(FUN_004594EC);
  FUN_0043faa0_OutputText(0xa00000 - iVar7 / 2,iVar4,text);
  switch(DAT_00455b38) {
  case 2:
    DAT_00456b00 = 99;
    DAT_00455c24 = 1;
    goto FUN_0041C9CA;
  case 3:
    DAT_00455b38 = 0xb;
    DAT_00459498 = 5;
    DAT_004594e8 = 1;
    break;
  case 4:
    DAT_00455b38 = 0xb;
    DAT_00459498 = 4;
    DAT_004594e8 = 1;
    break;
  case 5:
    DAT_00455b38 = 0xb;
    DAT_00459498 = 6;
    DAT_004594e8 = 1;
    break;
  case 6:
    DAT_00455b38 = 0xb;
    DAT_00459498 = 2;
    DAT_004594e8 = 1;
    break;
  case 7:
    DAT_00455b38 = 0xb;
    DAT_00459498 = 8;
    DAT_004594e8 = 1;
    break;
  case 8:
    DAT_00455c28 = 1;
FUN_0041C9CA:
    DAT_00455b38 = 0xb;
    DAT_004594e8 = 1;
  }
switchD_0041c8fe_caseD_7:
  puVar3 = local_204;
  for (iVar7 = 0x81; iVar7 != 0; iVar7 = iVar7 + -1) {
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  return;
}
