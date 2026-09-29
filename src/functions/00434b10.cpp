// Adapted from pc_decomp_backup/src/functions/FUN_00434b10.cpp
// Historical source SHA256: 2cfc40f09f57cbe2e38e33c510963463834dc289cd241fe16a3bf70cb7b2ac2c
// Provisional behavior candidate; original bytes and gameplay are not claimed to match.
extern "C" {
extern int _DAT_00459824;
extern int _DAT_0045B628;
extern int _DAT_004A27F0;
extern int _DAT_004A2814;
extern int _DAT_004A2860;
extern int _DAT_004A2864;
extern int _DAT_004A2874;
extern int DAT_00455c54_EventVar;
extern int DAT_004a0280_DirectionalMovement_Left;
extern int DAT_004a0281_DirectionalMovement_Right;
extern int* DAT_004a27fc_PlayerClassInstance;
extern int DAT_004a2858_PlayerStuff;
extern int DAT_004a2990_BlockAnims;
extern char s_Bad_Contour_in_Object_Type___ld__0045b750[];
void __cdecl FUN_00417b70_ProcessWalkingCollisions(void);
unsigned int* __cdecl FUN_0041A380(int);
int __cdecl FUN_0041A400(int);
void __cdecl FUN_0041CA70(int*);
void __cdecl FUN_00421D50(int, int, int);
void __cdecl FUN_00421f10_Stub(void);
void __cdecl FUN_0042D060(int, int*, void*);
void __cdecl FUN_0042D2C0(int, int*, void*);
void __cdecl FUN_00434A60(int, int);
void __cdecl FUN_00434AD0(int, int*);
void __cdecl FUN_00405390_EmptyStringDebugFunction(char*, ...);
}

static unsigned int CollisionDistance(int value)
{
  return value < 0 ? 0U - (unsigned int)value : (unsigned int)value;
}

// Resolve the old-frame left-side contact before the contour test. In the
// pinned routine this classification precedes its platform-height handling.
// The backup source lost the old-frame offsets and replaced every table mask
// with zero, so it could never take this branch.
static int HandleLeftSideContact(int *platform, unsigned int *event)
{
  int *other = (int *)platform[0x5e];
  if (other != DAT_004a27fc_PlayerClassInstance || !event[0] || event[1] ||
      !(platform[0x2d] & 0x80)) return 0;

  int oldOther[10] = {0};
  int oldPlatform[10] = {0};
  oldOther[0] = FUN_0041A400((int)other);
  oldPlatform[0] = FUN_0041A400((int)platform);
  if (!oldOther[0] || !oldPlatform[0]) return 0;
  oldOther[1] = (other[0x31] + 0x200000) & 0xc00000;
  oldOther[2] = other[0x35];
  oldOther[3] = other[0x36];
  oldOther[4] = (unsigned int)other[0x3f] >> 31;
  oldOther[5] = ((unsigned int)other[0x3f] >> 30) & 1;
  oldPlatform[1] = (platform[0x31] + 0x200000) & 0xc00000;
  oldPlatform[2] = platform[0x35];
  oldPlatform[3] = platform[0x36];
  oldPlatform[4] = (unsigned int)platform[0x3f] >> 31;
  oldPlatform[5] = ((unsigned int)platform[0x3f] >> 30) & 1;
  FUN_0041CA70(oldOther);
  FUN_0041CA70(oldPlatform);

  int highY = event[10] > event[20] ? event[10] : event[20];
  int lowY = event[11] < event[21] ? event[11] : event[21];
  int highX = event[8] > event[18] ? event[8] : event[18];
  int lowX = event[9] < event[19] ? event[9] : event[19];
  unsigned int bits =
      (CollisionDistance(highX - lowX) > CollisionDistance(highY - lowY) ? 16 : 0) |
      (oldOther[9] > oldPlatform[8] ? 0 : 4) |
      (oldPlatform[9] > oldOther[8] ? 0 : 8) |
      (oldOther[7] <= oldPlatform[6] ? 1 : 0) |
      (oldPlatform[7] > oldOther[6] ? 0 : 2);
  if (((int *)&_DAT_0045B628)[bits] != 1) return 0;

  int top = event[10];
  unsigned int *frame = (unsigned int *)event[2];
  if (frame && (frame[0] & 2)) {
    int *contour = (int *)frame[8];
    if (contour) {
      int index = event[6] ? contour[2] - 1 : 0;
      unsigned int height = ((unsigned char *)contour)[12 + index];
      if (height) top = (height - 1) * 0x10000 + contour[1] + event[5];
    }
  }
  if ((int)event[21] < top) {
    other[0x44] = (int)platform;
    other[0x45] = 4;
    return 1;
  }
  if (other[0x3a]) FUN_00434AD0((int)platform, other);
  other[0x39] = event[8];
  other[0x1e] += (int)event[8] - (int)event[19];
  if (platform[0x2d] & 0x1000) FUN_00421D50((int)platform, (int)event, 1);
  _DAT_004A2860 = 1;
  _DAT_004A27F0 = (int)platform;
  return 1;
}

// The backup translation below erased field offsets and fixed-point constants.
// Recover the static contour-platform branch directly from the pinned routine:
// the frame's height bytes describe the surface under the player, and a close
// descending contact attaches the player to that platform.
static int HandleStaticContourPlatform(int *platform, unsigned int *event)
{
  int *other = (int *)platform[0x5e]; // gob_pgobClidWith at +0x178
  if (other != DAT_004a27fc_PlayerClassInstance || event[1] ||
      (platform[0x2d] & 0x100)) return 0;
  unsigned int *frame = FUN_0041A380((int)platform);
  if (!frame || !(frame[0] & 2)) return 0;
  if (platform[0x1e] != platform[0x35] ||
      platform[0x1f] != platform[0x36]) return 0;
  int *contour = (int *)frame[8];
  if (!contour || contour[2] <= 0) return 0;
  int distance = (platform[0x1b] & 0x80000000U) ?
      platform[0x1e] - other[0x1e] - contour[0] :
      other[0x1e] - platform[0x1e] - contour[0];
  int index = distance >> 16;
  if (index < 0 || index >= contour[2]) return 0;
  unsigned int height = ((unsigned char *)contour)[12 + index];
  if (!height) return 1;
  int top = height * 0x10000 + contour[1] + platform[0x1f];
  int y = other[0x1f];
  if ((top <= y && other[0x36] <= top + 0x20000 && other[0x23] >= 0) ||
      (y <= top && top - 0x80000 < y && other[0x37] == 0))
      other[0x44] = (int)platform;
  if (other[0x44] == (int)platform && other[0x23] >= 0) {
      platform[0x38] |= 0x800;
      other[0x45] = 0;
      other[0x3b] = top;
      other[0x1f] = top;
  }
  return 1;
}

extern "C" void __cdecl FUN_00434b10_EVENT_Collision_Unk(int param_1,unsigned int *param_2)
{
  if (HandleLeftSideContact((int *)param_1, param_2)) return;
  if (HandleStaticContourPlatform((int *)param_1, param_2)) return;
  int *paVar1;
  int *piVar2;
  unsigned int uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  unsigned int *puVar8;
  int iVar9;
  char *pcVar10;
  unsigned int uVar11;
  int iVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  int iVar15;
  int iVar16;
  unsigned int *puVar17;
  int iVar18;
  int bVar19;
  unsigned int *local_bc;
  unsigned int local_b0 [2];
  unsigned int *local_a8;
  int local_9c;
  int local_98;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  unsigned int local_58;
  int local_50;
  unsigned int local_4c;
  int local_48;
  int local_44;
  unsigned int local_40;
  unsigned int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  unsigned int local_24;
  int local_20;
  int local_1c;
  unsigned int local_18;
  unsigned int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  uVar11 = 0;
  iVar16 = -1;
  if (*param_2 != 0) {
    uVar11 = **(unsigned int **)(param_1 + 0) & 0;
  }
  iVar9 = *(int *)(param_1 + 0);
  iVar6 = *(int *)(param_1 + 0);
  iVar15 = *(int *)(param_1 + 0);
  iVar7 = *(int *)(param_1 + 0);
  paVar1 = *(int **)(param_1 + 0);
  uVar3 = *(unsigned int *)(param_1 + 0) & 0;
  bVar19 = DAT_004a27fc_PlayerClassInstance == paVar1;
  if ((uVar11 == 1) && (bVar19)) {
    FUN_00417b70_ProcessWalkingCollisions();
  }
  if ((*(unsigned int *)(param_1 + 0) & 0) == 0) {
    if (param_2[1] != 0) {
      return;
    }
    local_bc = (unsigned int *)FUN_0041A380(param_1);
    if (local_bc == (unsigned int *)0) {
      return;
    }
    uVar11 = *(unsigned int *)(param_1 + 0);
    if (((uVar11 & 0) != 0) ||
       ((((uVar11 & 0) != 0 && (bVar19)) && (DAT_004a2858_PlayerStuff != 0)))) {
      if ((_DAT_004A2864 != param_1) &&
         (((!bVar19 || ((uVar11 & 0) == 0)) ||
          ((DAT_004a0280_DirectionalMovement_Left != '\0' ||
           (DAT_004a0281_DirectionalMovement_Right != '\0')))))) {
        puVar8 = param_2;
        puVar17 = local_b0;
        for (iVar16 = 0; iVar16 != 0; iVar16 = iVar16 + -1) {
          *puVar17 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar17 = puVar17 + 1;
        }
        local_28 = FUN_0041A400((int)paVar1);
        local_20 = *(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x54));
        local_1c = *(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x58));
        local_18 = (unsigned int)(*(int *)((char *)paVar1 + 1 * 0x9c + 0x7c)) >> 0;
        local_14 = ((*(int *)((char *)paVar1 + 1 * 0x9c + 0x7c)) & 0x40000000U) >> 0;
        local_24 = *(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x44)) + 0x200000U & 0;
        FUN_0041CA70(&local_28);
        local_50 = FUN_0041A400(param_1);
        local_48 = *(int *)(param_1 + 0);
        local_44 = *(int *)(param_1 + 0);
        local_40 = *(unsigned int *)(param_1 + 0) >> 0;
        local_3c = (*(unsigned int *)(param_1 + 0) & 0) >> 0;
        local_4c = *(int *)(param_1 + 0) + 0x200000U & 0;
        FUN_0041CA70(&local_50);
        iVar16 = local_88;
        if (local_88 <= local_60) {
          iVar16 = local_60;
        }
        iVar18 = local_84;
        if (local_5c <= local_84) {
          iVar18 = local_5c;
        }
        uVar11 = iVar16 - iVar18 >> 0;
        iVar4 = local_68;
        if (local_68 <= local_90) {
          iVar4 = local_90;
        }
        iVar12 = local_8c;
        if (local_64 <= local_8c) {
          iVar12 = local_64;
        }
        uVar13 = iVar4 - iVar12 >> 0;
        iVar16 = *(int *)(&_DAT_0045B628 +
                         (((int)((iVar4 - iVar12 ^ uVar13) - uVar13) <=
                          (int)((iVar16 - iVar18 ^ uVar11) - uVar11)) - 1 & 0 |
                          (local_4 != local_30 && -1 < local_4 - local_30) - 1 & 4 |
                          (local_2c != local_8 && -1 < local_2c - local_8) - 1 & 8 |
                          (unsigned int)(local_c == local_38 || local_c - local_38 < 0) |
                         (local_34 != local_10 && -1 < local_34 - local_10) - 1 & 2) * 4);
        switch(iVar16) {
        case 0:
          iVar16 = 0;
          break;
        case 1:
          if ((*local_a8 & 2) != 0) {
            uVar11 = local_a8[8];
            iVar18 = 0;
            if (local_98 != 0) {
              iVar18 = *(int *)(uVar11 + 8) + -1;
            }
            uVar13 = (unsigned int)*(unsigned char *)(iVar18 + 0 + uVar11);
            if (uVar13 != 0) {
              local_88 = (uVar13 - 1) * 0 + *(int *)(uVar11 + 4) + local_9c;
            }
          }
          if (local_5c < local_88) {
            iVar16 = 0;
            *(int *)&(*(int *)((char *)paVar1 + 2 * 0x9c + 0x10)) = param_1;
            *(int *)&(*(int *)((char *)paVar1 + 2 * 0x9c + 0x14)) = 4;
          }
          else if ((local_60 < local_88) || (local_84 < local_5c)) {
            if (bVar19) {
              if ((local_88 <= local_5c) && (local_60 < local_88)) {
                FUN_00421f10_Stub();
              }
              if (*(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x68)) != 0) {
                FUN_00434AD0(param_1,paVar1);
              }
              _DAT_004A2860 = 1;
              _DAT_004A27F0 = param_1;
            }
            *(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x64)) = local_90;
            (*(int *)((char *)paVar1 + 0x78)) = (*(int *)((char *)paVar1 + 0x78)) + (local_90 - local_64);
          }
          else {
            if ((bVar19) && (*(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x68)) != 0)) {
              FUN_00434AD0(param_1,paVar1);
            }
            *(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x64)) = local_90;
            (*(int *)((char *)paVar1 + 0x78)) = (*(int *)((char *)paVar1 + 0x78)) + (local_90 - local_64);
            if (bVar19) {
              if ((*(unsigned int *)(param_1 + 0) & 0) != 0) {
                FUN_00421D50(param_1,(int)local_b0,1);
              }
              _DAT_004A2860 = 1;
              goto label_00435150;
            }
          }
          break;
        case 2:
          if ((*local_a8 & 2) != 0) {
            uVar11 = local_a8[8];
            iVar18 = 0;
            if (local_98 == 0) {
              iVar18 = *(int *)(uVar11 + 8) + -1;
            }
            uVar13 = (unsigned int)*(unsigned char *)(iVar18 + 0 + uVar11);
            if (uVar13 != 0) {
              local_88 = (uVar13 - 1) * 0 + *(int *)(uVar11 + 4) + local_9c;
            }
          }
          if (local_5c < local_88) {
            iVar16 = 0;
          }
          else if ((local_60 < local_88) || (local_84 < local_5c)) {
            if (bVar19) {
              if ((local_88 <= local_5c) && (local_60 < local_88)) {
                FUN_00421f10_Stub();
              }
              if (*(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x64)) != 0) {
                FUN_00434AD0(param_1,paVar1);
              }
              _DAT_004A2860 = 2;
              _DAT_004A27F0 = param_1;
            }
            (*(int *)((char *)paVar1 + 0x78)) = (*(int *)((char *)paVar1 + 0x78)) + (local_8c - local_68);
            *(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x68)) = local_8c;
          }
          else {
            if ((bVar19) && (*(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x64)) != 0)) {
              FUN_00434AD0(param_1,paVar1);
            }
            (*(int *)((char *)paVar1 + 0x78)) = (*(int *)((char *)paVar1 + 0x78)) + (local_8c - local_68);
            *(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x68)) = local_8c;
            if (bVar19) {
              if ((*(unsigned int *)(param_1 + 0) & 0) != 0) {
                FUN_00421D50(param_1,(int)local_b0,0);
              }
              _DAT_004A2860 = 2;
              goto label_00435150;
            }
          }
          break;
        case 3:
          if (bVar19) {
            if ((*(unsigned int *)(param_1 + 0) & 0) != 0) {
              FUN_00434AD0(param_1,paVar1);
              break;
            }
          }
          else if ((*(unsigned int *)(param_1 + 0) & 0) != 0) {
            FUN_00434A60(param_1,(int)paVar1);
          }
          (*(int *)((char *)paVar1 + 0x7c)) = (*(int *)((char *)paVar1 + 0x7c)) + (local_84 - local_60);
          *(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x70)) = local_84;
          if (bVar19) {
            (*(int *)((char *)paVar1 + 1 * 0x9c + 0xc)) = 0;
            if ((*(unsigned int *)(param_1 + 0) & 0) != 0) {
              FUN_00421D50(param_1,(int)local_b0,2);
            }
            _DAT_004A2860 = 3;
label_00435150:
            _DAT_004A27F0 = param_1;
          }
          break;
        default:
          iVar16 = 0;
        }
      }
    }
    else {
      iVar16 = 0;
    }
  }
  else if (bVar19) {
    if (_DAT_004A2874 == 0) {
      _DAT_004A2874 = param_1;
    }
    else {
      _DAT_004A2814 = param_1;
    }
  }
  if (iVar16 != 0) {
    return;
  }
  if (*(int *)&(*(int *)((char *)paVar1 + 2 * 0x9c + 0x10)) == param_1) {
    (*(int *)((char *)paVar1 + 0x78)) = (*(int *)((char *)paVar1 + 0x78)) + (iVar9 - iVar6);
    FUN_0042D060(DAT_004a2990_BlockAnims,paVar1,(void *)0);
    (*(int *)((char *)paVar1 + 0x7c)) = (*(int *)((char *)paVar1 + 0x7c)) + (iVar7 - iVar15);
    FUN_0042D2C0(DAT_004a2990_BlockAnims,paVar1,(void *)0);
  }
  if ((*local_bc & 2) == 0) {
    uVar11 = param_2[10];
label_00435420:
    puVar8 = (unsigned int *)FUN_0041A400(param_1);
    if (puVar8 == (unsigned int *)0) {
      local_58 = uVar11 - 0;
    }
    else if ((*puVar8 & 2) == 0) {
      local_58 = param_2[10];
    }
    else {
      piVar2 = (int *)puVar8[8];
      if ((*(unsigned int *)(param_1 + 0) & 0) == 0) {
        iVar16 = *(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x54));
        iVar9 = *(int *)(param_1 + 0);
      }
      else {
        iVar16 = *(int *)(param_1 + 0);
        iVar9 = *(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x54));
      }
      uVar3 = (iVar16 - iVar9) - *piVar2 >> 0;
      if ((int)uVar3 < 0) {
        uVar3 = 0;
      }
      else if ((unsigned int)piVar2[2] <= uVar3) {
        uVar3 = piVar2[2] - 1;
      }
      uVar3 = (unsigned int)*(unsigned char *)((int)piVar2 + uVar3 + 0);
      if (uVar3 == 0) {
        local_58 = uVar11 - 0;
      }
      else {
        local_58 = (uVar3 - 1) * 0 + piVar2[1] + *(int *)(param_1 + 0);
      }
    }
    // Debug tracing in the original has no gameplay effect in this source build.
    if ((((*(int *)&(*(int *)((char *)paVar1 + 2 * 0x9c + 0x10)) == param_1) && (-1 < (int)(*(int *)((char *)paVar1 + 1 * 0x9c + 0xc)))) ||
        (((int)uVar11 <= (*(int *)((char *)paVar1 + 0x7c)) &&
         ((*(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x58)) <= (int)(local_58 + 0) &&
          (-1 < (int)(*(int *)((char *)paVar1 + 1 * 0x9c + 0xc)))))))) &&
       ((bVar19 || (((unsigned char)((unsigned int)*(int *)&(*(int *)((char *)paVar1 + 0x6c)) >> 8) & 0) != 2)))) {
      *(int *)&(*(int *)((char *)paVar1 + 2 * 0x9c + 0x10)) = param_1;
      *(unsigned int *)(param_1 + 0) = *(unsigned int *)(param_1 + 0) | 0;
      *(int *)&(*(int *)((char *)paVar1 + 2 * 0x9c + 0x14)) = 0;
      *(unsigned int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x6c)) = uVar11;
      (*(int *)((char *)paVar1 + 0x7c)) = uVar11;
    }
    return;
  }
  piVar2 = (int *)local_bc[8];
  if (uVar3 == 0) {
    iVar16 = ((*(int *)((char *)paVar1 + 0x78)) - *(int *)(param_1 + 0)) - *piVar2;
  }
  else {
    iVar16 = (*(int *)(param_1 + 0) - (*(int *)((char *)paVar1 + 0x78))) - *piVar2;
  }
  uVar11 = iVar16 >> 0;
  if ((-1 < (int)uVar11) && (uVar11 < (unsigned int)piVar2[2])) {
    uVar3 = (unsigned int)*(unsigned char *)((int)piVar2 + uVar11 + 0);
    if (uVar3 == 0) {
      FUN_00405390_EmptyStringDebugFunction
                (s_Bad_Contour_in_Object_Type___ld__0045b750,*(int *)(param_1 + 8),uVar11);
      return;
    }
    iVar16 = (*(int *)((char *)paVar1 + 0x7c));
    uVar11 = piVar2[1] + uVar3 * 0 + *(int *)(param_1 + 0);
    if ((((int)uVar11 <= iVar16) && (iVar16 < (int)(uVar11 + 0))) ||
       ((iVar16 <= (int)uVar11 &&
        (((int)(uVar11 - 0) < iVar16 && (*(int *)&(*(int *)((char *)paVar1 + 1 * 0x9c + 0x0)) == 0)))))) {
      *(int *)&(*(int *)((char *)paVar1 + 2 * 0x9c + 0x10)) = param_1;
    }
    goto label_00435420;
  }
  if ((*(unsigned int *)(param_1 + 0) & 0) == 0) {
    return;
  }
  piVar5 = (int *)FUN_0041A380((int)paVar1);
  uVar13 = *(unsigned int *)(param_1 + 0) & 0;
  if (uVar13 == 0) {
    uVar14 = *(unsigned int *)&(*(int *)((char *)paVar1 + 0x6c));
    if (-1 < (int)uVar11) {
      if ((uVar14 & 0) == 0) {
        iVar16 = *piVar5;
      }
      else {
        iVar16 = -piVar5[2];
      }
      goto label_004352d0;
    }
  }
  else {
    if ((int)uVar11 < 0) {
      if ((*(unsigned int *)&(*(int *)((char *)paVar1 + 0x6c)) & 0) == 0) {
        iVar16 = *piVar5;
      }
      else {
        iVar16 = -piVar5[2];
      }
      goto label_004352d0;
    }
    uVar14 = *(unsigned int *)&(*(int *)((char *)paVar1 + 0x6c));
  }
  if ((uVar14 & 0) == 0) {
    iVar16 = piVar5[2];
  }
  else {
    iVar16 = -*piVar5;
  }
label_004352d0:
  iVar9 = (*(int *)((char *)paVar1 + 0x78));
  iVar16 = iVar16 + iVar9;
  if ((*(unsigned int *)&(*(int *)((char *)paVar1 + 0x6c)) & 0) == 0) {
    iVar6 = piVar5[3];
  }
  else {
    iVar6 = -piVar5[1];
  }
  if ((int)uVar11 < 0) {
    uVar14 = *local_bc;
    if (uVar13 != 0) {
      uVar14 = -uVar14;
    }
  }
  else {
    uVar14 = local_bc[2];
    if (uVar13 != 0) {
      uVar14 = -uVar14;
    }
  }
  iVar15 = uVar14 + *(int *)(param_1 + 0);
  if (uVar3 == 0) {
    iVar7 = (iVar16 - *piVar2) - *(int *)(param_1 + 0);
  }
  else {
    iVar7 = (*(int *)(param_1 + 0) - *piVar2) - iVar16;
  }
  local_b0[0] = (unsigned int)*(unsigned char *)((iVar7 >> 0) + 0 + (int)piVar2);
  if (local_b0[0] == 0) {
    return;
  }
  if (iVar6 + (*(int *)((char *)paVar1 + 0x7c)) + -0 <=
      (int)((local_b0[0] - 1) * 0 + piVar2[1] + *(int *)(param_1 + 0))) {
    return;
  }
  if ((int)uVar11 < 0) {
    if (uVar13 != 0) {
      (*(int *)((char *)paVar1 + 0x78)) = (iVar15 - iVar16) + iVar9 + 0;
      return;
    }
    (*(int *)((char *)paVar1 + 0x78)) = (iVar15 - iVar16) + iVar9 + -0;
    return;
  }
  if (uVar13 != 0) {
    (*(int *)((char *)paVar1 + 0x78)) = (iVar15 - iVar16) + iVar9 + -0;
    return;
  }
  (*(int *)((char *)paVar1 + 0x78)) = (iVar15 - iVar16) + iVar9 + 0;
  return;
}
