// Adapted from pc_decomp_backup/src/functions/FUN_0043bc80.cpp
// Historical source SHA256: 89cbd8706bd7410a93c67b13ebe9b61159ba96020cf88bcd3c24bff7d899bf8f
// Behavior candidate; original bytes are not claimed to match.
extern "C" {
extern int DAT_00460028;
extern int DAT_0046002c;
extern int DAT_00460030;
extern int DAT_00464dbc;
extern int DAT_00464dc0;
extern int DAT_00464dc4;
extern int DAT_00464dc8;
extern int DAT_00464dcc;
extern int DAT_00464dd4;
extern int DAT_00464dd8;
extern int DAT_00464ddc;
extern int DAT_00464de8;
extern int DAT_00464e00;
extern int DAT_00464e04;
extern int* DAT_00464e08;
extern int DAT_00464e0c;
extern int* DAT_00464e14;
extern int DAT_00464e1c;
extern int DAT_00464e20;
extern int DAT_004a2ac8_FrameCount;
void __cdecl FUN_00419b80(int*, int);
void __cdecl FUN_00419bc0(int*, int*);
void __cdecl FUN_00419be0(int*, int*);
void __cdecl FUN_0041a360(int, int);
}


extern "C" void __cdecl ob261DoIt_0043bc80(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  unsigned int uVar7;
  int iVar8;
  int iVar9;

  if (DAT_00464dc0 != 0) {
    if ((DAT_004a2ac8_FrameCount & 0xf) == 0) {
      FUN_0041a360(0x112, 0xa0);
    }
    DAT_00464e1c = DAT_00464e1c + -0x20000;
    if (DAT_00464e1c < 1) {
      DAT_00464e1c = 0;
      DAT_00464dcc = 1;
      DAT_00464dc0 = 0;
      DAT_00464e04 = 1;
      piVar6 = &DAT_00464de8;
      DAT_00464e20 = 0;
      *(int *)(DAT_00464e14 + 0xa4) = 0xc9;
      do {
        iVar1 = *piVar6;
        piVar6 = piVar6 + 1;
        *(int *)(iVar1 + 0xb8) = 0;
      } while (piVar6 < &DAT_00464e00);
    }
  }
  if (DAT_00464ddc != 0) {
    DAT_00464dd4 = DAT_00464dd4 + DAT_00464dd8;
    DAT_00464e1c = DAT_00464e1c + DAT_00464dd4;
    if (0xdc0000 < DAT_00464e1c) {
      piVar6 = &DAT_00464de8;
      do {
        iVar1 = *piVar6;
        piVar6 = piVar6 + 1;
        *(int *)(iVar1 + 0x54) = 0;
      } while (piVar6 < &DAT_00464e00);
      DAT_00464e1c = 0xdc0000;
      DAT_00464ddc = 0;
      *(int *)(DAT_00464e14 + 0xa4) = 0xc9;
    }
  }
  if (DAT_00464e04 != 0) {
    if (DAT_0046002c == 0) {
      DAT_00460030 = DAT_00460030 + -1;
      if (DAT_00460030 < -0x34) {
        DAT_00460030 = -0x34;
        DAT_0046002c = 1;
      }
    }
    else {
      DAT_00460030 = DAT_00460030 + 1;
      if (0x34 < DAT_00460030) {
        DAT_00460030 = 0x34;
        DAT_00464e20 = 1;
      }
    }
  }
  if (DAT_00464dc8 != 0) {
    DAT_00464dbc = DAT_00464dbc + DAT_00464dc4;
    DAT_00460028 = DAT_00460028 + DAT_00464dbc;
    if (0xc80000 < DAT_00460028) {
      piVar6 = &DAT_00464de8;
      do {
        iVar1 = *piVar6;
        piVar6 = piVar6 + 1;
        *(int *)(iVar1 + 0x54) = 0;
      } while (piVar6 < &DAT_00464e00);
      DAT_00460028 = 0x180000;
      DAT_00464dc8 = 0;
      *(int *)(DAT_00464e14 + 0xa4) = 0xc9;
    }
  }
  iVar5 = DAT_00464dcc;
  iVar1 = DAT_00464e0c * 3;
  iVar8 = 4;
  if (DAT_00464e0c < 0) {
    iVar8 = -4;
  }
  iVar9 = 0;
  do {
    iVar2 = (&DAT_00464de8)[iVar9];
    *(int *)(iVar2 + 0xd4) = *(int *)(iVar2 + 0x78);
    *(int *)(iVar2 + 0xd8) = *(int *)(iVar2 + 0x7c);
    *(int *)(iVar2 + 0xfc) = *(int *)(iVar2 + 0x6c);
    *(int *)(iVar2 + 0xf4) = *(int *)(iVar2 + 0x50);
    *(int *)(iVar2 + 0xf8) = *(int *)(iVar2 + 0x54);
    *(int *)(iVar2 + 0xe4) = 0;
    *(int *)(iVar2 + 0xe8) = 0;
    *(int *)(iVar2 + 0xec) = 0;
    *(int *)(iVar2 + 0xf0) = 0;
    uVar7 = *(unsigned int *)(iVar2 + 0xe0);
    uVar7 = (uVar7 * 2 ^ uVar7) & 0x200 ^ uVar7;
    *(unsigned int *)(iVar2 + 0xe0) = uVar7;
    *(unsigned int *)(iVar2 + 0xe0) = uVar7 & 0xfffffeff;
    *(int *)(iVar2 + 0xa0) = *(int *)(iVar2 + 0x9c);
    if (((iVar5 != 0) &&
        (*(int *)(iVar2 + 0x9c) = *(int *)(iVar2 + 0x9c) + (iVar1 / 2 >> 0x10) + iVar8, iVar9 == 0))
       && ((DAT_004a2ac8_FrameCount & 0xf) == 0)) {
      FUN_0041a360(0x113, 0xc0);
    }
    uVar7 = *(unsigned int *)(iVar2 + 0x9c) & 0xff;
    *(unsigned int *)(iVar2 + 0x9c) = uVar7;
    iVar3 = *(int *)(iVar2 + 0xa0);
    if ((iVar3 < 0xc9) || (0x31 < uVar7)) {
      if ((iVar3 < 0x32) && (200 < uVar7)) {
        if (((int *)(&DAT_00464de8)[(iVar9 + 2) % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0))
        {
          FUN_00419be0((int *)(&DAT_00464de8)[(iVar9 + 2) % 6],DAT_00464e08);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 1) % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0))
        {
          FUN_00419be0((int *)(&DAT_00464de8)[(iVar9 + 1) % 6],DAT_00464e08);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 3) % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0))
        {
          FUN_00419be0((int *)(&DAT_00464de8)[(iVar9 + 3) % 6],DAT_00464e08);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 5) % 6] != (int *)0x0) && (DAT_00464e14 != 0)) {
          FUN_00419bc0((int *)(&DAT_00464de8)[(iVar9 + 5) % 6],DAT_00464e14);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 4) % 6] != (int *)0x0) && (DAT_00464e14 != 0)) {
          FUN_00419bc0((int *)(&DAT_00464de8)[(iVar9 + 4) % 6],DAT_00464e14);
        }
        piVar6 = (int *)(&DAT_00464de8)[iVar9 % 6];
        goto joined_r0x0043c14e;
      }
      if (0x7f < iVar3) {
FUN_0043C289:
        if (0x7f < uVar7) goto FUN_0043C390;
        if (((int *)(&DAT_00464de8)[(iVar9 + 5) % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0))
        {
          FUN_00419be0((int *)(&DAT_00464de8)[(iVar9 + 5) % 6],DAT_00464e08);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 4) % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0))
        {
          FUN_00419be0((int *)(&DAT_00464de8)[(iVar9 + 4) % 6],DAT_00464e08);
        }
        if (((int *)(&DAT_00464de8)[iVar9 % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0)) {
          FUN_00419be0((int *)(&DAT_00464de8)[iVar9 % 6],DAT_00464e08);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 2) % 6] != (int *)0x0) && (DAT_00464e14 != 0)) {
          FUN_00419bc0((int *)(&DAT_00464de8)[(iVar9 + 2) % 6],DAT_00464e14);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 1) % 6] != (int *)0x0) && (DAT_00464e14 != 0)) {
          FUN_00419bc0((int *)(&DAT_00464de8)[(iVar9 + 1) % 6],DAT_00464e14);
        }
        piVar6 = (int *)(&DAT_00464de8)[(iVar9 + 3) % 6];
joined_r0x0043c37a:
        if (piVar6 == (int *)0x0) goto FUN_0043C390;
        goto joined_r0x0043c384;
      }
      if (0x7f < uVar7) {
        if (((int *)(&DAT_00464de8)[(iVar9 + 4) % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0))
        {
          FUN_00419be0((int *)(&DAT_00464de8)[(iVar9 + 4) % 6],DAT_00464e08);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 3) % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0))
        {
          FUN_00419be0((int *)(&DAT_00464de8)[(iVar9 + 3) % 6],DAT_00464e08);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 5) % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0))
        {
          FUN_00419be0((int *)(&DAT_00464de8)[(iVar9 + 5) % 6],DAT_00464e08);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 1) % 6] != (int *)0x0) && (DAT_00464e14 != 0)) {
          FUN_00419bc0((int *)(&DAT_00464de8)[(iVar9 + 1) % 6],DAT_00464e14);
        }
        if (((int *)(&DAT_00464de8)[(iVar9 + 2) % 6] != (int *)0x0) && (DAT_00464e14 != 0)) {
          FUN_00419bc0((int *)(&DAT_00464de8)[(iVar9 + 2) % 6],DAT_00464e14);
        }
        piVar6 = (int *)(&DAT_00464de8)[iVar9 % 6];
        goto joined_r0x0043c37a;
      }
      if (0x7f < iVar3) goto FUN_0043C289;
    }
    else {
      if (((int *)(&DAT_00464de8)[(iVar9 + 1) % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0)) {
        FUN_00419be0((int *)(&DAT_00464de8)[(iVar9 + 1) % 6],DAT_00464e08);
      }
      if (((int *)(&DAT_00464de8)[(iVar9 + 2) % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0)) {
        FUN_00419be0((int *)(&DAT_00464de8)[(iVar9 + 2) % 6],DAT_00464e08);
      }
      if (((int *)(&DAT_00464de8)[iVar9 % 6] != (int *)0x0) && (DAT_00464e08 != (int *)0x0)) {
        FUN_00419be0((int *)(&DAT_00464de8)[iVar9 % 6],DAT_00464e08);
      }
      if (((int *)(&DAT_00464de8)[(iVar9 + 4) % 6] != (int *)0x0) && (DAT_00464e14 != 0)) {
        FUN_00419bc0((int *)(&DAT_00464de8)[(iVar9 + 4) % 6],DAT_00464e14);
      }
      if (((int *)(&DAT_00464de8)[(iVar9 + 3) % 6] != (int *)0x0) && (DAT_00464e14 != 0)) {
        FUN_00419bc0((int *)(&DAT_00464de8)[(iVar9 + 3) % 6],DAT_00464e14);
      }
      piVar6 = (int *)(&DAT_00464de8)[(iVar9 + 5) % 6];
joined_r0x0043c14e:
      if (piVar6 != (int *)0x0) {
joined_r0x0043c384:
        if (DAT_00464e14 != 0) {
          FUN_00419bc0(piVar6,DAT_00464e14);
        }
      }
    }
FUN_0043C390:
    if (DAT_00464e20 != 0) {
      iVar3 = *(int *)(iVar2 + 0x9c);
      if (iVar3 < 0x40) {
FUN_0043C3C1:
        if ((*(int *)(iVar2 + 0xa0) < 0x40) || (99 < *(int *)(iVar2 + 0xa0))) goto FUN_0043C461;
      }
      else if ((99 < iVar3) || (0x3f < *(int *)(iVar2 + 0xa0))) {
        if (0x3f < iVar3) goto FUN_0043C461;
        goto FUN_0043C3C1;
      }
      piVar6 = &DAT_00464de8;
      DAT_00464e20 = 0;
      do {
        *(int *)(*piVar6 + 0x9c) = *(int *)(*piVar6 + 0x9c) - (iVar3 + -0x40);
        iVar4 = ((int *)*piVar6)[0x27];
        if ((-1 < iVar4) && (iVar4 < 0x80)) {
          FUN_00419b80((int *)*piVar6,8);
        }
        piVar6 = piVar6 + 1;
      } while (piVar6 < &DAT_00464e00);
      DAT_0046002c = 0;
      DAT_00464dcc = 0;
      DAT_00464e04 = 0;
      DAT_00464dc8 = 1;
      *(int *)(DAT_00464e14 + 0xa4) = 200;
      DAT_00464dbc = -0x30000;
      DAT_00464dc4 = 0x4000;
    }
FUN_0043C461:
    if (*(int *)(iVar2 + 0x114) == -1) {
      *(int *)(iVar2 + 0x110) = 0;
    }
    *(int *)(iVar2 + 0x114) = 0xffffffff;
    iVar9 = iVar9 + 1;
    if (5 < iVar9) {
      return;
    }
  } while( 1 );
}
