// Adapted from pc_decomp_backup/src/functions/FUN_00410280_SetScrollPosition_ScrollScreen.cpp
// Historical source SHA256: 2ed79c2ac04a28f0079cc436eb02f507e429c936f5cf4349f3dfde0f5f4a3071
// Behavior candidate; original bytes are not claimed to match.
// The history tables below are byte-addressed: adding an index to an int *
// would scale their four-byte offsets a second time and corrupt camera state.
extern "C" {
extern int DAT_00455b8c;
extern int DAT_00455b90;
extern int DAT_00455b94;
extern int DAT_00455b98;
extern int DAT_00455b9c;
extern int DAT_00455ba0;
extern int DAT_00455ba4;
extern int DAT_00455ba8;
extern int DAT_00455bac;
extern int DAT_00455bb0;
extern int DAT_00455bb4;
extern int DAT_00455bb8;
extern int DAT_00455bbc;
extern int DAT_00455bc0;
extern int DAT_00455bc4;
extern int DAT_00455bc8;
extern int DAT_00455bcc;
extern int DAT_00455bd0;
extern int DAT_00455bd4;
extern int DAT_00455bd8;
extern int DAT_00455bdc;
extern int DAT_00455be0;
extern int DAT_00457e80;
extern int DAT_00457e84;
extern int DAT_00457e88;
extern int DAT_00457e8c;
extern int DAT_00462cb0;
extern int DAT_00462d30;
extern int DAT_00462d34;
extern int DAT_00462d38;
extern int DAT_00462d3c;
extern int DAT_00462d40;
extern int DAT_00462d44;
extern int DAT_00462d48;
extern int DAT_00462d4c;
extern int DAT_00462d50;
extern int DAT_00462d70;
extern int DAT_00462d80;
extern int DAT_00462d88;
extern int DAT_00462e08;
extern int DAT_004a2928;
extern int DAT_004a292c;
extern int DAT_004a2938;
extern int DAT_004a297c;
extern int DAT_004a2984;
extern int DAT_004a2990_BlockAnims;
extern int DAT_004a29fc;
extern int DAT_004a2a04;
extern int DAT_004a2a1c;
extern int DAT_004a2a30;
extern int DAT_004a2a34;
extern int DAT_004a2a38_Camera;
extern int* DAT_004a27fc_PlayerClassInstance;
unsigned int __cdecl FUN_004206d0(void);
int __cdecl GEX_WidescreenWidth(void);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

extern "C" void __cdecl FUN_0041028b_CameraStuff(void)

{
  int bVar1;
  int iVar2;
  unsigned int uVar3;
  int iVar4;
  unsigned int uVar5;
  int iVar6;
  unsigned int uVar7;
  int iVar8;
  unsigned int uVar9;
  int iVar10;
  unsigned int uVar11;
  int bVar12;
  int iStack_18;
  int iStack_14;
  int viewportFixed = GEX_WidescreenWidth() << 16;
  int halfViewportFixed = viewportFixed / 2;

  uVar11 = DAT_00455b98;
  if ((DAT_004a27fc_PlayerClassInstance != (int *)0) && (DAT_004a2a04 != 0)) {
    DAT_004a29fc = DAT_004a2a38_Camera;
    DAT_004a297c = DAT_004a2a1c;
    iVar2 = DAT_004a27fc_PlayerClassInstance[0x78 / 4];
    iVar8 = (iVar2 - DAT_004a2a38_Camera) + DAT_004a2984;
    iVar10 = DAT_004a27fc_PlayerClassInstance[0x7c / 4];
    iVar4 = (iVar10 - DAT_004a2a1c) + DAT_004a2938;
    if (DAT_00462d34 == 10) {
      iStack_18 = 0;
    }
    else {
      iStack_18 = iVar2 - DAT_004a292c;
    }
    bVar12 = -1 < iStack_18;
    bVar1 = 0 < iStack_18;
    iVar6 = iStack_18;
    if (iStack_18 < 0) {
      iVar6 = -iStack_18;
    }
    iVar6 = DAT_00455b94 + iVar6;
    uVar3 = iVar10 - DAT_004a2928;
    DAT_004a2928 = DAT_004a27fc_PlayerClassInstance[0x7c / 4];
    DAT_004a292c = iVar2;
    if ((DAT_00462d30 == 0) || (DAT_00462d30 == 1)) {
      iStack_14 = iVar2;
      if (DAT_00462d34 != 8) {
        uVar7 = FUN_004206d0();
        if (uVar7 == 6) {
          iStack_14 = 0;
          iVar2 = 1;
        }
        if (uVar7 == 10) {
          iStack_14 = 1;
          iVar2 = 0;
        }
      }
      if (bVar12) {
        if (bVar1) {
          iVar2 = *(int *)((char *)&DAT_00462d50 + DAT_00457e8c * 4);
          *(int *)((char *)&DAT_00462d50 + DAT_00457e8c * 4) = iStack_18;
          DAT_00462d48 = (DAT_00462d48 - iVar2) + iStack_18;
          DAT_00457e8c = DAT_00457e8c + 1 & 7;
          if (iStack_14 == 0) {
            if (0xd0000 < DAT_00462d48) {
              DAT_00455bb4 = halfViewportFixed - 0x80000;
              DAT_00455bb8 = halfViewportFixed;
            }
          }
          else if (0xd0000 < DAT_00462d48) {
            DAT_00455bb4 = DAT_00455bcc;
            DAT_00455bb8 = DAT_00455bd0;
          }
          DAT_00455bcc = DAT_00455ba4;
          DAT_00455bd0 = DAT_00455ba8;
        }
      }
      else {
        DAT_00462d48 = DAT_00462d48 - *(int *)((char *)&DAT_00462d50 + DAT_00457e8c * 4);
        *(int *)((char *)&DAT_00462d50 + DAT_00457e8c * 4) = iStack_18;
        DAT_00462d48 = DAT_00462d48 + iStack_18;
        DAT_00457e8c = DAT_00457e8c + 1 & 7;
        if (iVar2 == 0) {
          if (DAT_00462d48 < -0xd0000) {
            DAT_00455bb4 = halfViewportFixed;
            DAT_00455bb8 = halfViewportFixed + 0x80000;
          }
        }
        else if (DAT_00462d48 < -0xd0000) {
          DAT_00455bb4 = DAT_00455bc4;
          DAT_00455bb8 = DAT_00455bc8;
        }
        DAT_00455bc4 = DAT_00455b9c;
        DAT_00455bc8 = DAT_00455ba0;
      }
    }
    else if (DAT_00462d34 == 7) {
      if ((bVar12) || (DAT_00455bb4 <= iVar8)) {
        if ((bVar1) && (DAT_00455bb8 < iVar8)) {
          DAT_00455bb4 = DAT_00455bc4;
          DAT_00455bb8 = DAT_00455bc8;
          DAT_00455bc4 = DAT_00455b9c;
          DAT_00455bc8 = DAT_00455ba0;
        }
      }
      else {
        DAT_00455bb4 = DAT_00455bcc;
        DAT_00455bb8 = DAT_00455bd0;
        DAT_00455bcc = DAT_00455ba4;
        DAT_00455bd0 = DAT_00455ba8;
      }
    }
    else if ((bVar12) || (DAT_00455bb4 <= iVar8)) {
      if ((bVar1) && (DAT_00455bb8 < iVar8)) {
        DAT_00455bb4 = DAT_00455bcc;
        DAT_00455bb8 = DAT_00455bd0;
        DAT_00455bcc = DAT_00455ba4;
        DAT_00455bd0 = DAT_00455ba8;
      }
    }
    else {
      DAT_00455bb4 = DAT_00455bc4;
      DAT_00455bb8 = DAT_00455bc8;
      DAT_00455bc4 = DAT_00455b9c;
      DAT_00455bc8 = DAT_00455ba0;
    }
    DAT_00462d44 = iVar8;
    if (DAT_00462d30 == 4) {
      if ((bVar12) || (halfViewportFixed - 1 < iVar8)) {
        if ((bVar1) && (halfViewportFixed < iVar8)) {
          DAT_00455bb4 = DAT_00455bcc;
          uVar7 = iVar6 + 0x40000;
          DAT_00455bb8 = DAT_00455bd0;
          DAT_00455bcc = DAT_00455ba4;
          DAT_00462d44 = halfViewportFixed;
          DAT_00455bd0 = DAT_00455ba8;
        }
        else {
          uVar7 = 0;
        }
      }
      else {
        DAT_00455bb4 = DAT_00455bc4;
        uVar7 = iVar6 + 0x40000;
        DAT_00455bb8 = DAT_00455bc8;
        DAT_00455bc4 = DAT_00455b9c;
        DAT_00462d44 = halfViewportFixed;
        DAT_00455bc8 = DAT_00455ba0;
      }
    }
    else {
      if (iVar8 < DAT_00455bb4) {
        iVar6 = iVar6 + 0x40000;
        DAT_00462d44 = DAT_00455bb4;
      }
      else if (DAT_00455bb8 < iVar8) {
        iVar6 = iVar6 + 0x40000;
        DAT_00462d44 = DAT_00455bb8;
      }
      iVar2 = *(int *)((char *)&DAT_00462cb0 + DAT_00457e84 * 4);
      *(int *)((char *)&DAT_00462cb0 + DAT_00457e84 * 4) = iVar6;
      DAT_00462d38 = (DAT_00462d38 - iVar2) + iVar6;
      uVar7 = DAT_00462d38 >> 5;
      DAT_00457e84 = DAT_00457e84 + 1 & 0x1f;
    }
    iVar2 = DAT_00462d34;
    uVar5 = (int)uVar3 >> 0x1f;
    DAT_00462d4c = iVar4;
    if ((DAT_00462e08 == 0) || ((DAT_00462d30 != 0 && (DAT_00462d30 != 1)))) {
      DAT_00462d3c = DAT_00462d3c - *(int *)((char *)&DAT_00462d70 + DAT_00457e88 * 4);
      *(int *)((char *)&DAT_00462d70 + DAT_00457e88 * 4) = 0;
      iVar10 = DAT_00455be0;
      DAT_00462d4c = DAT_00455bd4;
      DAT_00457e88 = DAT_00457e88 + 1 & 1;
      if (iVar2 == 9) {
        DAT_00462d4c = 0x960000;
        uVar11 = (uVar11 - uVar5) + (uVar3 ^ uVar5);
      }
      else if (iVar4 < DAT_00455bbc) {
        DAT_00455bbc = DAT_00455bd4;
        DAT_00455bc0 = DAT_00455bd8;
        DAT_00455bd4 = DAT_00455bac;
        DAT_00455bd8 = DAT_00455bb0;
        iVar10 = (uVar11 - uVar5) + (uVar3 ^ uVar5);
        iVar2 = *(int *)((char *)&DAT_00462d88 + DAT_00462d80 * 4);
        *(int *)((char *)&DAT_00462d88 + DAT_00462d80 * 4) = iVar10;
        DAT_00462d40 = (DAT_00462d40 - iVar2) + iVar10;
        DAT_00462d80 = DAT_00462d80 + 1 & 0x1f;
        uVar11 = DAT_00462d40 >> 5;
      }
      else {
        DAT_00462d4c = iVar4;
        if (DAT_00455bc0 < iVar4) {
          DAT_00455bbc = DAT_00455bdc;
          DAT_00455bc0 = DAT_00455be0;
          DAT_00455bdc = DAT_00455bac;
          DAT_00455be0 = DAT_00455bb0;
          DAT_00462d4c = iVar10;
          uVar11 = (uVar11 - uVar5) + (uVar3 ^ uVar5);
          if (DAT_00462d30 != 4) {
            iVar2 = *(int *)((char *)&DAT_00462d88 + DAT_00462d80 * 4);
            *(unsigned int *)((char *)&DAT_00462d88 + DAT_00462d80 * 4) = uVar11;
            DAT_00462d40 = (DAT_00462d40 - iVar2) + uVar11;
            uVar11 = DAT_00462d40 >> 5;
            DAT_00462d80 = DAT_00462d80 + 1 & 0x1f;
          }
        }
      }
    }
    else {
      iVar2 = *(int *)((char *)&DAT_00462d70 + DAT_00457e88 * 4);
      *(unsigned int *)((char *)&DAT_00462d70 + DAT_00457e88 * 4) = uVar3;
      DAT_00462d3c = (DAT_00462d3c - iVar2) + uVar3;
      DAT_00457e88 = DAT_00457e88 + 1 & 1;
      if ((-1 < (int)uVar3) || (DAT_00455bbc <= iVar4)) {
        if ((0 < (int)uVar3) && (DAT_00455bc0 < iVar4)) {
          DAT_00455bc0 = DAT_00455be0;
          DAT_00455bdc = DAT_00455bac;
          DAT_00455be0 = DAT_00455bb0;
          DAT_00455bbc = 0x640000;
        }
      }
      else {
        DAT_00455bc0 = DAT_00455bd8;
        DAT_00455bd4 = DAT_00455bac;
        DAT_00455bd8 = DAT_00455bb0;
        DAT_00455bbc = 0x640000;
      }
      if (DAT_00462d3c < 0x30001) {
        if (DAT_00462d3c < -0x30000) {
          DAT_00457e80 = 2;
          iVar10 = (uVar11 - uVar5) + (uVar3 ^ uVar5);
          DAT_00462d4c = DAT_00455bc0;
          iVar2 = *(int *)((char *)&DAT_00462d88 + DAT_00462d80 * 4);
          *(int *)((char *)&DAT_00462d88 + DAT_00462d80 * 4) = iVar10;
          DAT_00462d40 = (DAT_00462d40 - iVar2) + iVar10;
          DAT_00462d80 = DAT_00462d80 + 1 & 0x1f;
          uVar11 = DAT_00462d40 >> 5;
        }
        else {
          if ((-1 < (int)uVar3) || (DAT_00455bbc <= iVar4)) {
            if ((0 < (int)uVar3) && (DAT_00455bc0 < iVar4)) {
              DAT_00462d4c = DAT_00455bc0;
            }
          }
          else {
            DAT_00462d4c = DAT_00455bbc;
          }
          iVar10 = (uVar11 - uVar5) + (uVar3 ^ uVar5);
          iVar2 = *(int *)((char *)&DAT_00462d88 + DAT_00462d80 * 4);
          *(int *)((char *)&DAT_00462d88 + DAT_00462d80 * 4) = iVar10;
          DAT_00462d40 = (DAT_00462d40 - iVar2) + iVar10;
          uVar11 = DAT_00462d40 >> 5;
          DAT_00462d80 = DAT_00462d80 + 1 & 0x1f;
        }
      }
      else {
        DAT_00457e80 = 2;
        iVar10 = (uVar11 - uVar5) + (uVar3 ^ uVar5);
        DAT_00462d4c = DAT_00455bbc;
        iVar2 = *(int *)((char *)&DAT_00462d88 + DAT_00462d80 * 4);
        *(int *)((char *)&DAT_00462d88 + DAT_00462d80 * 4) = iVar10;
        DAT_00462d40 = (DAT_00462d40 - iVar2) + iVar10;
        DAT_00462d80 = DAT_00462d80 + 1 & 0x1f;
        uVar11 = DAT_00462d40 >> 5;
      }
    }
    if ((DAT_00462d4c == iVar4) && (DAT_00457e80 == 1)) {
      DAT_00457e80 = 2;
    }
    iVar2 = DAT_00462d44;
    iVar10 = DAT_00462d4c;
    if (DAT_00462d30 == 5) {
      iVar2 = halfViewportFixed;
      iVar10 = 0x780000;
      uVar11 = 0x140000;
      uVar7 = 0x140000;
    }
    uVar9 = iVar8 - iVar2;
    uVar5 = iVar4 - iVar10;
    uVar3 = uVar9;
    if (((int)uVar7 < (int)((uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f))) &&
       (uVar3 = uVar7, (int)uVar9 < 1)) {
      uVar3 = -uVar7;
    }
    uVar7 = uVar5;
    if (((int)uVar11 < (int)((uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f))) &&
       (uVar7 = uVar11, (int)uVar5 < 1)) {
      uVar7 = -uVar11;
    }
    if (DAT_00455b8c == 0) {
      DAT_004a2a38_Camera = DAT_004a2a38_Camera + uVar3;
    }
    else if (DAT_00455b8c != 0x7fffffff) {
      DAT_004a2a38_Camera = DAT_004a2a38_Camera + DAT_00455b8c;
    }
    if (DAT_00455b90 == 0) {
      DAT_004a2a1c = DAT_004a2a1c + uVar7;
    }
    else if (DAT_00455b90 != 0x7fffffff) {
      DAT_004a2a1c = DAT_004a2a1c + DAT_00455b90;
    }
    if (DAT_004a2a38_Camera < 0) {
      DAT_004a2a38_Camera = 0;
    }
    if (DAT_004a2a1c < 0) {
      DAT_004a2a1c = 0;
    }
    iVar2 = *(int *)(*(int *)(DAT_004a2990_BlockAnims + 4) + 4);
    if (iVar2 - viewportFixed <= DAT_004a2a38_Camera) {
      DAT_004a2a38_Camera = iVar2 - viewportFixed - 0x10000;
    }
    if (DAT_004a2a38_Camera < 0) DAT_004a2a38_Camera = 0;
    iVar2 = *(int *)(*(int *)(DAT_004a2990_BlockAnims + 4) + 8);
    if (iVar2 + -0xf00000 <= DAT_004a2a1c) {
      DAT_004a2a1c = iVar2 + -0xf10000;
    }
    DAT_004a2a30 = DAT_004a2a38_Camera - DAT_004a29fc;
    DAT_004a2a34 = DAT_004a2a1c - DAT_004a297c;
  }
  return;
}
