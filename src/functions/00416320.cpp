// Adapted from pc_decomp_backup/src/functions/FUN_00416320_MainProcessing.cpp
// Historical source SHA256: 5178b1c4d438e8fc8352fbf295f8e67d0e5910e0db9364a45dc3c0e776b6e9aa
// Provisional behavior candidate; original bytes and gameplay are not claimed to match.
struct PlayerStruct {
  int field_0x0;
  int field_0x4;
  unsigned char pad_08[4];
  int field12_0xc;
  unsigned char pad_10[0x0c];
  int field_0x1c;
  int field_0x20;
  int field_0x24;
  int field_0x28;
  int field_0x2c;
  int field_0x30;
  unsigned char pad_34[0x1c];
  int *Animation;
  int *field78_0x54;
  unsigned char pad_58[0x14];
  int field_0x6c;
  int *MovementSpeed;
  unsigned char pad_74[4];
  int field_0x78;
  int field_0x7c;
  unsigned char pad_80[0x1c];
};
struct astruct_3 {
  unsigned char pad_00[0x50];
  int field_0x50;
  unsigned char pad_54[0x18];
  int field105_0x6c;
  int field_0x70;
  unsigned char pad_74[0x0c];
  int field_0x80;
  int field_0x84;
  unsigned char pad_88[4];
  int field_0x8c;
  int field_0x90;
  int field_0x94;
  int field_0x98;
};
static unsigned int CONCAT22(unsigned short hi, unsigned short lo) { return ((unsigned int)hi << 16) | lo; }
extern "C" {
extern unsigned char *PTRDAT_00456ac8;
extern int DAT_00455c4c;
extern int DAT_00456888;
extern int DAT_00456998;
extern int DAT_00456afc_MaxHealth;
extern int DAT_00456b00;
extern int DAT_00456f40;
extern int DAT_004570a8;
extern int DAT_00457210;
extern int DAT_00457ee0;
extern int DAT_00458980;
extern int DAT_00458984;
extern int DAT_00458988;
extern int DAT_0045898c;
extern int DAT_004589d0;
extern int DAT_004589d4;
extern int DAT_00458a60;
extern int DAT_00458a64;
extern int DAT_00458a68;
extern int DAT_00458ad8;
extern int DAT_00458adc;
extern int DAT_00458b5c;
extern int DAT_00458b60;
extern int DAT_00458b70;
extern int DAT_00458b74;
extern int DAT_0045a6d8;
extern int DAT_0045a6dc;
extern int DAT_0045a6e0;
extern int DAT_00462e10;
extern int DAT_00462e18;
extern int DAT_00462e44;
extern int DAT_00462e48;
extern int DAT_00462e4c;
extern int DAT_00462e54;
extern int DAT_00462e58;
extern int DAT_00462e7c;
extern int DAT_00462e8c;
extern int DAT_00462e90;
extern int DAT_00462e94;
extern int DAT_00463098;
extern int DAT_004630b8;
extern int DAT_004630e4;
extern int DAT_004632ec;
extern int DAT_004634f0;
extern int DAT_00463510;
extern int DAT_00463530;
extern int DAT_00463550;
extern int DAT_00463570;
extern int DAT_004a0214;
extern int DAT_004a0224;
extern int DAT_004a0228;
extern int DAT_004a022c;
extern int DAT_004a0234;
extern int DAT_004a0238_HealthLost;
extern int DAT_004a023c;
extern int DAT_004a0248;
extern int DAT_004a024c;
extern int DAT_004a0250;
extern int DAT_004a0254;
extern int DAT_004a0258;
extern int DAT_004a0264;
extern int DAT_004a0268;
extern int DAT_004a27ec;
extern int DAT_004a281c_Health;
extern int DAT_004a2878_CollisionType;
extern int DAT_004a2ac0;
extern int DAT_004a2ac8_FrameCount;
extern int DAT_004a2ad4;
astruct_3* __cdecl FUN_004195d0_GameFunctions(int, int, int, int);
void __cdecl FUN_00419bc0(int*, int);
void __cdecl FUN_0041a250(int, int, int, int);
void __cdecl FUN_0041a340(int, int);
int __cdecl FUN_0041a380(int);
int __cdecl FUN_0041a480(int);
int __cdecl FUN_0041cb80(int, int*);
void __cdecl FUN_0041f8c0_LoadVoice(int);
void __cdecl FUN_0041fa80_SetUpVFXVariableForLoading(int);
void __cdecl FUN_004223d0(void);
unsigned int __cdecl FUN_00428c60(void);
int __cdecl FUN_00428c80(int);
void __cdecl FUN_00428fa0(unsigned short*, unsigned short*, int, int, int);
void __cdecl FUN_00441150_Flashing(int);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

extern "C" void __cdecl FUN_00416320_CollisionsProcessing(PlayerStruct *param_1)

{
  int uVar1;
  unsigned int uVar2;
  int uVar3;
  int uVar4;
  int *piVar5;
  int bVar6;
  int bVar7;
  astruct_3 *paVar8;
  short sVar9;
  int iVar10;
  int *piVar11;
  int *puVar12;
  unsigned int uVar13;
  int iVar14;
  PlayerStruct *pPVar15;
  int iVar16;
  unsigned int *puVar17;
  short *psVar18;
  int *puVar19;
  int iVar20;
  int uVar21;
  int uVar22;
  int local_22c [6];
  int local_214;
  int local_210;
  int local_20c;
  int local_208;
  int local_204 [20];
  int local_1b4;
  int local_1b0;
  int local_18c;
  int local_188;
  int local_148;
  unsigned char *local_144;
  int local_140;
  int local_13c;
  int local_138;

  bVar7 = 1;
  bVar6 = 0;
  uVar1 = param_1->field12_0xc;
  if (DAT_00455c4c == 0) goto switchD_004166d3_caseD_2;
  if (DAT_004a0238_HealthLost == 0) {
    if (DAT_004a2878_CollisionType != 0) {
      if ((DAT_004a2878_CollisionType < 10) && (*(int *)&param_1[1].field_0x1c != 0)) {
        uVar21 = *(int *)&param_1[1].field_0x28;
        iVar16 = (int)param_1->MovementSpeed * 4;
        piVar11 = param_1->Animation;
        piVar5 = param_1->field78_0x54;
        if ((*(unsigned int *)(&DAT_00457210 + iVar16) & 0xf0000000) == 0x10000000) {
          *(int *)&param_1[1].field_0x28 = 0;
        }
        param_1->Animation = *(int **)(&DAT_004570a8 + iVar16);
        param_1->field78_0x54 = (int *)0x0;
        param_1->field12_0xc = DAT_004a2ad4;
        FUN_00441150_Flashing((int)param_1);
        param_1->field12_0xc = uVar1;
        *(int *)&param_1[1].field_0x28 = uVar21;
        param_1->Animation = piVar11;
        param_1->field78_0x54 = piVar5;
      }
      goto switchD_004166d3_caseD_2;
    }
    goto FUN_004167B8;
  }
  iVar16 = 0;
  switch(DAT_004a0224) {
  case 0:
    if (DAT_00456b00 < 99) {
      DAT_00456b00 = DAT_00456b00 + 1;
    }
    bVar6 = 1;
    FUN_0041a340((int)param_1,0x7b);
    break;
  case 1:
    FUN_0041fa80_SetUpVFXVariableForLoading(0x4b);
  case 4:
  case 5:
  case 6:
  case 8:
  case 0xb1:
switchD_00416375_caseD_4:
    iVar16 = 0x73;
    break;
  case 2:
    FUN_0041fa80_SetUpVFXVariableForLoading(0x5d);
    goto switchD_00416375_caseD_4;
  case 3:
    break;
  case 7:
    if (DAT_00456afc_MaxHealth < 6) {
      DAT_00456afc_MaxHealth = DAT_00456afc_MaxHealth + 1;
      DAT_004a281c_Health = DAT_00456afc_MaxHealth;
    }
    iVar20 = 0x91;
    goto FUN_00416421;
  case 9:
    DAT_004a281c_Health = DAT_00456afc_MaxHealth;
    iVar20 = 0x93;
FUN_00416421:
    bVar6 = 1;
    FUN_0041a250((int)param_1,iVar20,0x80,0x60);
    break;
  default:
    FUN_0041a250((int)param_1,0x91,0x80,0x60);
    if (DAT_004a281c_Health < DAT_00456afc_MaxHealth) {
      DAT_004a281c_Health = DAT_004a281c_Health + 1;
    }
    bVar6 = 1;
  }
  if ((iVar16 != 0) && (DAT_004a0258 == 0)) {
    FUN_0041a250((int)param_1,iVar16,0x80,0x60);
  }
  if ((*(int *)(&DAT_004589d0 + DAT_004a0258 * 8) < 0) || (bVar6)) {
    DAT_00455c4c = DAT_00455c4c - DAT_004a27ec;
    DAT_004a27ec = 0;
    DAT_004a0238_HealthLost = 0;
    switch(DAT_004a0224) {
    case 1:
      FUN_0041fa80_SetUpVFXVariableForLoading(0x5c);
      break;
    case 4:
      FUN_0041fa80_SetUpVFXVariableForLoading(0x4e);
      FUN_0041f8c0_LoadVoice(0x4f);
      break;
    case 6:
      FUN_0041fa80_SetUpVFXVariableForLoading(0x52);
      break;
    case 8:
      FUN_0041a340((int)param_1,0x75);
    }
    goto switchD_004166d3_caseD_2;
  }
  if ((*(unsigned int *)(&DAT_004589d4 + DAT_004a0258 * 8) & 1) == 0) goto switchD_0041649a_caseD_3;
  switch(DAT_004a0224) {
  case 1:
    DAT_004a023c = 1;
    DAT_00462e54 = 8;
    DAT_00462e7c = 0;
    break;
  case 2:
    DAT_004a0264 = 1;
    DAT_00462e4c = 0;
    DAT_00462e48 = 600;
    break;
  case 4:
    FUN_004223d0();
    DAT_0045a6e0 = 4;
    DAT_004a0234 = 2;
    goto FUN_004165A8;
  case 5:
    FUN_004223d0();
    DAT_0045a6e0 = 5;
    DAT_004a0234 = 0;
    goto FUN_004165A8;
  case 6:
    FUN_004223d0();
    DAT_0045a6e0 = 6;
    DAT_004a0234 = 1;
    goto FUN_004165A8;
  case 7:
    DAT_0045a6d8 = 1;
    break;
  case 8:
    DAT_004a0214 = 1;
    DAT_004a0228 = 0;
    break;
  case 0xb1:
    FUN_004223d0();
    DAT_0045a6e0 = 0xb1;
    DAT_004a0234 = 3;
FUN_004165A8:
    DAT_004a0248 = 1;
    DAT_004a0268 = 0;
    DAT_004a0250 = 0;
  }
switchD_0041649a_caseD_3:
  pPVar15 = param_1;
  piVar11 = local_204;
  for (iVar16 = 0x81; iVar16 != 0; iVar16 = iVar16 + -1) {
    *piVar11 = *(int *)pPVar15;
    pPVar15 = (PlayerStruct *)&pPVar15->field_0x4;
    piVar11 = piVar11 + 1;
  }
  local_204[3] = DAT_004a2ad4;
  local_1b4 = 0x15;
  local_1b0 = *(int *)(&DAT_004589d0 + DAT_004a0258 * 8);
  local_13c = *(int *)(&DAT_004589d4 + DAT_004a0258 * 8);
  local_144 = (unsigned char *)&DAT_004632ec;
  local_148 = DAT_00458b5c;
  local_188 = local_188 -
              (-(unsigned int)(*(int *)(&DAT_00456f40 + (int)param_1->MovementSpeed * 4) == 0) & 0x180000);
  local_138 = local_13c;
  iVar16 = FUN_0041a480((int)local_204);
  if ((iVar16 != 0) && (*(int **)(iVar16 + 0x18) != (int *)0x0)) {
    FUN_00428fa0(*(unsigned short **)(**(int **)(iVar16 + 0x18) + 0xc),(unsigned short *)&DAT_004632ec,
                 *(int *)(&DAT_00458a60 + DAT_004a0224 * 0xc),
                 *(int *)(&DAT_00458a64 + DAT_004a0224 * 0xc),
                 *(int *)(&DAT_00458a68 + DAT_004a0224 * 0xc));
  }
  FUN_00441150_Flashing((int)local_204);
switchD_004166d3_caseD_2:
  if ((DAT_004a2878_CollisionType != 0) && (DAT_004a0238_HealthLost == 0)) goto FUN_004170FB;
FUN_004167B8:
  if ((DAT_00455c4c == 0) && (*(int *)&param_1[1].field_0x1c != 0)) {
    *(int *)&param_1[1].field_0x1c = *(int *)&param_1[1].field_0x1c + -1;
  }
  uVar21 = *(int *)(&DAT_00458b60 + (*(unsigned int *)&param_1[1].field_0x1c & 3) * 4);
  *(int *)&param_1[1].field_0x20 = uVar21;
  if (DAT_004a022c != 0) {
    uVar22 = *(int *)&param_1->field_0x78;
    iVar16 = *(int *)&param_1->field_0x7c;
    *(int *)&param_1->field_0x7c = iVar16 + 0x40000;
    *(int *)&param_1[1].field_0x20 = 0x810081;
    FUN_00441150_Flashing((int)param_1);
    *(int *)&param_1->field_0x78 = uVar22;
    *(int *)&param_1->field_0x7c = iVar16;
    *(int *)&param_1[1].field_0x20 = uVar21;
  }
  if ((DAT_004a023c != 0) && (DAT_004a0254 == 0)) {
    DAT_00462e8c = DAT_00462e8c + 1;
    uVar13 = *(unsigned int *)(&DAT_00457210 + (int)param_1->MovementSpeed * 4) >> 0x1c;
    if (2 < DAT_00462e8c) {
      DAT_00462e8c = 0;
    }
    pPVar15 = param_1;
    piVar11 = local_204;
    for (iVar16 = 0x81; iVar16 != 0; iVar16 = iVar16 + -1) {
      *piVar11 = *(int *)pPVar15;
      pPVar15 = (PlayerStruct *)&pPVar15->field_0x4;
      piVar11 = piVar11 + 1;
    }
    local_204[3] = DAT_004a2ad4;
    local_1b4 = 0x24;
    local_1b0 = DAT_00462e8c;
    local_148 = *(int *)(&DAT_00456888 + DAT_00462e7c * 4);
    local_144 = (unsigned char *)0x0;
    iVar16 = FUN_0041cb80((int)param_1,local_22c);
    if (iVar16 == 0) {
      local_18c = local_18c - *(int *)(&DAT_00458988 + uVar13 * 0x10);
      local_188 = local_188 - *(int *)(&DAT_0045898c + uVar13 * 0x10);
    }
    else {
      local_18c = local_210 + local_214 >> 1;
      local_188 = local_208 + local_20c >> 1;
    }
    local_13c = (*(int *)(&DAT_00458980 + uVar13 * 0x10) >> 8) * (local_13c >> 8);
    local_138 = (*(int *)(&DAT_00458984 + uVar13 * 0x10) >> 8) * (local_138 >> 8);
    if (uVar13 == 1) {
      local_140 = 0;
    }
    FUN_00441150_Flashing((int)local_204);
  }
  *(int *)&param_1[1].field_0x24 = 0;
  if ((DAT_004a2ac0 == 0) && (DAT_004a0248 != 0)) {
    uVar21 = *(int *)&param_1->field_0x78;
    local_204[0] = *(int *)&param_1->field_0x7c;
    bVar7 = 0;
    local_22c[0] = *(int *)&param_1[1].field_0x20;
    iVar16 = local_204[0];
    iVar20 = local_204[0];
    switch(DAT_004a0234) {
    case 0:
      iVar16 = 0;
      iVar20 = 1;
      break;
    case 1:
      iVar16 = 0;
      iVar20 = 1;
      break;
    case 2:
      iVar16 = 0;
      iVar20 = 1;
      break;
    case 3:
      iVar16 = 0;
      iVar20 = 1;
    }
    if (iVar16 != 0) {
      if ((&DAT_00458ad8)[DAT_004a0250] == -0x80000000) {
        DAT_004a0250 = 0;
      }
      *(int *)&param_1->field_0x78 = *(int *)&param_1->field_0x78 + (&DAT_00458ad8)[DAT_004a0250];
      DAT_004a0250 = DAT_004a0250 + 1;
      *(int *)&param_1->field_0x7c = *(int *)&param_1->field_0x7c + (&DAT_00458ad8)[DAT_004a0250];
      DAT_004a0250 = DAT_004a0250 + 1;
    }
    if (iVar20 == 0) {
      *(unsigned char **)&param_1[1].field_0x24 = (&PTRDAT_00456ac8)[DAT_004a0234] + 4;
    }
    else {
      iVar16 = FUN_0041a380((int)param_1);
      if (iVar16 != 0) {
        switch(DAT_004a0234) {
        case 0:
        case 2:
        case 3:
          uVar13 = (unsigned int)*(unsigned short *)((&PTRDAT_00456ac8)[DAT_004a0234] + DAT_004a0268 * 2 + 4);
          if (uVar13 == 0xffff) {
            DAT_004a0268 = 0;
FUN_00416A9E:
            uVar13 = (unsigned int)*(unsigned short *)((&PTRDAT_00456ac8)[DAT_004a0234] + 6);
          }
          else if (uVar13 == 0) goto FUN_00416A9E;
          puVar17 = *(unsigned int **)(**(int **)(iVar16 + 0x18) + 0xc);
          DAT_00462e90 = puVar17[-1] | 0xffffff00;
          iVar16 = 0x80;
          piVar11 = &DAT_00462e94;
          do {
            uVar2 = *puVar17;
            puVar17 = puVar17 + 1;
            iVar16 = iVar16 + -1;
            *piVar11 = ((uVar2 & 0x7bde7bde) >> 1) +
                       ((uVar13 | uVar13 << 0x10) >> 1 & 0x3def3def | 0x80008000);
            piVar11 = piVar11 + 1;
          } while (iVar16 != 0);
          *(unsigned short *)&DAT_00462e94 = 0;
          break;
        case 1:
          if (-1 < (int)param_1->field78_0x54) {
            sVar9 = *(short *)((&PTRDAT_00456ac8)[DAT_004a0234] + DAT_004a0268 * 2 + 4);
            if (sVar9 == -1) {
              DAT_004a0268 = 0;
FUN_00416B3B:
              sVar9 = *(short *)((&PTRDAT_00456ac8)[DAT_004a0234] + 6);
            }
            else if (sVar9 == 0) goto FUN_00416B3B;
            puVar12 = &DAT_00462e94;
            puVar19 = *(int **)(**(int **)(iVar16 + 0x18) + 0xc);
            DAT_00462e90 = puVar19[-1] | 0xffffff00;
            if ((char)puVar19[-1] == '\0') {
              iVar16 = 0x10;
              do {
                uVar22 = *puVar19;
                puVar19 = puVar19 + 1;
                *puVar12 = uVar22;
                puVar12 = puVar12 + 1;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
            }
            else {
              iVar16 = 0x80;
              do {
                uVar22 = *puVar19;
                puVar19 = puVar19 + 1;
                *puVar12 = uVar22;
                puVar12 = puVar12 + 1;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
              psVar18 = (short *)((int)&DAT_00462e94 + DAT_004a0250 * 8 + 2);
              for (iVar16 = 7; iVar16 != 0; iVar16 = iVar16 + -1) {
                *(unsigned int *)psVar18 = CONCAT22(sVar9,sVar9);
                psVar18 = psVar18 + 2;
              }
              *psVar18 = sVar9;
              DAT_004a0250 = DAT_004a0250 + 1 & 0x1f;
            }
          }
        }
        *(int **)&param_1[1].field_0x24 = &DAT_00462e94;
      }
      DAT_004a0268 = DAT_004a0268 + 1;
    }
    FUN_00441150_Flashing((int)param_1);
    *(int *)&param_1->field_0x78 = uVar21;
    *(int *)&param_1->field_0x7c = local_204[0];
    *(int *)&param_1[1].field_0x24 = 0;
    *(int *)&param_1[1].field_0x20 = local_22c[0];
  }
  if (DAT_004a0214 != 0) {
    DAT_004a0228 = DAT_004a0228 + -1;
    if (DAT_004a0228 < 1) {
      iVar16 = FUN_00428c80(2);
      DAT_004a0228 = iVar16 + 2;
      uVar21 = *(int *)&param_1->field_0x7c;
      uVar22 = DAT_004a2ad4;
      uVar13 = FUN_00428c60();
      paVar8 = FUN_004195d0_GameFunctions
                         (0x5c,
                          ((-(unsigned int)((uVar13 & 1) == 0) & 0x80000) - 0x40000) +
                          *(int *)&param_1->field_0x78,uVar21,uVar22);
      if (paVar8 != (astruct_3 *)0x0) {
        paVar8->field105_0x6c = paVar8->field105_0x6c | 0xc000;
        *(int *)&paVar8->field_0x84 = 0x7fff0000;
        iVar16 = FUN_00428c80(6);
        *(int *)&paVar8->field_0x80 = (3 - iVar16) * 0x10000 >> 1;
        *(int *)&paVar8->field_0x90 = 0x7fff0000;
        iVar16 = FUN_00428c80(0x20000);
        *(int *)&paVar8->field_0x8c = -iVar16;
        *(int *)&paVar8->field_0x94 = 0x1000;
        *(int *)&paVar8->field_0x50 = 0x22;
        *(int *)&paVar8->field_0x98 = 6;
        *(int *)&paVar8->field_0x70 = 0x30;
        FUN_00419bc0((int *)paVar8,(int)param_1);
      }
    }
    bVar7 = 1;
  }
  if (DAT_004a0264 != 0) {
    if ((DAT_004a2ac8_FrameCount & 7) == 0) {
      FUN_0041a340((int)param_1,0x74);
    }
    iVar16 = DAT_00462e10 - DAT_00462e4c;
    if (iVar16 < 0) {
      iVar16 = iVar16 + 8;
    }
    local_22c[0] = *(int *)&param_1->field_0x78;
    local_204[0] = *(int *)&param_1[1].field_0x20;
    iVar20 = *(int *)&param_1->field_0x7c;
    uVar21 = *(int *)&param_1->field_0x6c;
    uVar22 = *(int *)&param_1[1].field_0x30;
    uVar3 = *(int *)&param_1[1].field_0x28;
    uVar4 = *(int *)&param_1[1].field_0x2c;
    piVar11 = param_1->field78_0x54;
    piVar5 = param_1->Animation;
    iVar14 = 0;
    FUN_0041fa80_SetUpVFXVariableForLoading(0x4c);
    if (0 < DAT_00462e4c) {
      puVar19 = &DAT_00456998;
      do {
        *(int *)&param_1->field_0x78 = (&DAT_00463550)[iVar16];
        *(int *)&param_1->field_0x7c = (&DAT_00463530)[iVar16];
        *(int *)&param_1[1].field_0x20 = *puVar19;
        *(int *)&param_1[1].field_0x28 = (&DAT_004634f0)[iVar16];
        param_1->field12_0xc = (&DAT_00462e18)[iVar16];
        if (DAT_00458b70 != 0) {
          *(int *)&param_1->field_0x6c = (&DAT_00463570)[iVar16];
          param_1->field78_0x54 = (int *)(&DAT_00462e58)[iVar16];
          param_1->Animation = (int *)(&DAT_00463510)[iVar16];
        }
        iVar16 = iVar16 + 1;
        if (iVar16 == 8) {
          iVar16 = 0;
        }
        puVar19 = puVar19 + 1;
        iVar14 = iVar14 + 1;
        FUN_00441150_Flashing((int)param_1);
      } while (iVar14 < DAT_00462e4c);
    }
    *(int *)&param_1->field_0x78 = local_22c[0];
    *(int *)&param_1->field_0x7c = iVar20;
    *(int *)&param_1->field_0x6c = uVar21;
    *(int *)&param_1[1].field_0x20 = local_204[0];
    *(int *)&param_1[1].field_0x28 = uVar3;
    *(int *)&param_1[1].field_0x2c = uVar4;
    *(int *)&param_1[1].field_0x30 = uVar22;
    param_1->field78_0x54 = piVar11;
    param_1->Animation = piVar5;
    param_1->field12_0xc = uVar1;
    iVar16 = DAT_00462e10;
    DAT_00462e44 = DAT_00462e44 + -1;
    if (DAT_00462e44 < 1) {
      iVar10 = DAT_00462e10 * 4;
      DAT_00462e44 = DAT_00457ee0;
      iVar14 = (&DAT_00458adc)[DAT_004a2ac8_FrameCount & 0xe];
      (&DAT_00463550)[DAT_00462e10] = (&DAT_00458ad8)[DAT_004a2ac8_FrameCount & 0xe] + local_22c[0];
      (&DAT_00463530)[iVar16] = iVar14 + iVar20;
      (&DAT_00463570)[iVar16] = uVar21;
      (&DAT_00462e58)[iVar16] = (int)piVar11;
      (&DAT_00463510)[iVar16] = (int)piVar5;
      DAT_00462e10 = DAT_00462e10 + 1;
      (&DAT_004634f0)[iVar16] = uVar3;
      *(int *)(&DAT_004630b8 + iVar10) = uVar4;
      *(int *)(&DAT_00463098 + iVar10) = uVar22;
      (&DAT_00462e18)[iVar16] = uVar1;
      if (DAT_00462e10 == 8) {
        DAT_00462e10 = 0;
      }
      if (DAT_00462e4c < 8) {
        DAT_00462e4c = DAT_00462e4c + 1;
      }
    }
    DAT_00462e48 = DAT_00462e48 + -1;
    if (DAT_00462e48 < 0) {
      DAT_004a0264 = 0;
    }
    else if ((DAT_00462e48 < 0x5a) && (DAT_00462e4c = DAT_00462e48 / 10, 7 < DAT_00462e4c)) {
      DAT_00462e4c = 8;
    }
  }
  if (bVar7) {
    FUN_00441150_Flashing((int)param_1);
  }
  if ((DAT_004a023c != 0) && (DAT_004a0254 == 0)) {
    if ((DAT_004a2ac8_FrameCount & 3) == 0) {
      FUN_0041a340((int)param_1,0x7a);
    }
    uVar13 = *(unsigned int *)(&DAT_00457210 + (int)param_1->MovementSpeed * 4) >> 0x1c;
    pPVar15 = param_1;
    piVar11 = local_204;
    for (iVar16 = 0x81; iVar16 != 0; iVar16 = iVar16 + -1) {
      *piVar11 = *(int *)pPVar15;
      pPVar15 = (PlayerStruct *)&pPVar15->field_0x4;
      piVar11 = piVar11 + 1;
    }
    local_204[3] = DAT_004a2ad4;
    local_1b4 = 0x23;
    local_1b0 = DAT_00462e8c;
    local_148 = *(int *)(&DAT_00456888 + DAT_00462e7c * 4);
    local_144 = (unsigned char *)0x0;
    iVar16 = FUN_0041cb80((int)param_1,local_22c);
    if (iVar16 == 0) {
      local_18c = local_18c - *(int *)(&DAT_00458988 + uVar13 * 0x10);
      local_188 = local_188 - *(int *)(&DAT_0045898c + uVar13 * 0x10);
    }
    else {
      local_18c = local_210 + local_214 >> 1;
      local_188 = local_208 + local_20c >> 1;
    }
    local_13c = (*(int *)(&DAT_00458980 + uVar13 * 0x10) >> 8) * (local_13c >> 8);
    local_138 = (*(int *)(&DAT_00458984 + uVar13 * 0x10) >> 8) * (local_138 >> 8);
    if (uVar13 == 1) {
      local_140 = 0;
    }
    FUN_00441150_Flashing((int)local_204);
    if (DAT_00455c4c == 0) {
      DAT_00462e54 = DAT_00462e54 + -1;
    }
    if (DAT_00462e54 == 0) {
      DAT_00462e54 = 8;
      DAT_00462e7c = DAT_00462e7c + 1;
      if (*(int *)(&DAT_00456888 + DAT_00462e7c * 4) == 0) {
        DAT_004a023c = 0;
      }
    }
  }
FUN_004170FB:
  if (DAT_00455c4c != 0) {
    if (DAT_004a0238_HealthLost == 0) {
      if ((*(int *)&param_1[1].field_0x1c != 0) && (9 < DAT_004a2878_CollisionType)) {
        FUN_00441150_Flashing((int)param_1);
      }
    }
    else {
      pPVar15 = param_1;
      piVar11 = local_204;
      for (iVar16 = 0x81; iVar16 != 0; iVar16 = iVar16 + -1) {
        *piVar11 = *(int *)pPVar15;
        pPVar15 = (PlayerStruct *)&pPVar15->field_0x4;
        piVar11 = piVar11 + 1;
      }
      local_204[3] = DAT_004a2ad4;
      local_1b4 = 0x16;
      local_1b0 = *(int *)(&DAT_004589d0 + DAT_004a0258 * 8);
      local_13c = *(int *)(&DAT_004589d4 + DAT_004a0258 * 8);
      local_144 = (unsigned char *)&DAT_004630e4;
      local_148 = DAT_00458b74;
      local_188 = local_188 -
                  (-(unsigned int)(*(int *)(&DAT_00456f40 + (int)param_1->MovementSpeed * 4) == 0) &
                  0x180000);
      local_138 = local_13c;
      iVar16 = FUN_0041a480((int)local_204);
      if ((iVar16 != 0) && (*(int **)(iVar16 + 0x18) != (int *)0x0)) {
        FUN_00428fa0(*(unsigned short **)(**(int **)(iVar16 + 0x18) + 0xc),(unsigned short *)&DAT_004630e4,
                     *(int *)(&DAT_00458a60 + DAT_004a0224 * 0xc),
                     *(int *)(&DAT_00458a64 + DAT_004a0224 * 0xc),
                     *(int *)(&DAT_00458a68 + DAT_004a0224 * 0xc));
      }
      FUN_00441150_Flashing((int)local_204);
      DAT_004a024c = DAT_004a024c + -1;
      if (DAT_004a024c < 1) {
        DAT_004a024c = DAT_0045a6dc;
        DAT_004a0258 = DAT_004a0258 + 1;
        return;
      }
    }
  }
  return;
}
