// Scaled object drawing reconstructed from a read-only decompilation of the
// pinned game's 004432c0 function. Ghidra field names are evidence, not proof.
typedef unsigned char byte;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned short ushort;
typedef unsigned int uint;
struct struct_select_tile_ptr { int value; };
struct ImageStruct {
    int width;
    int height;
    int x_offset;
    int y_offset;
    byte field16_0x10;
    byte pad11;
    short field_0x12_CacheSlotNumber;
    short field_0x14_Image;
    byte pad16[6];
    short field24_0x1c;
};
struct DrawStructUnk {
    DrawStructUnk *field_0x0_NextDrawStruct_unk;
    uint field_0x4_NextDrawStruct;
    ImageStruct *field_0x8_ImageObject;
    struct_select_tile_ptr *field3_0xc;
    uint field4_0x10;
};
struct SpriteStruct {
    byte pad0[0x18];
    DrawStructUnk *field_0x18_DrawStruct;
};
struct GXObject {
    byte pad0[0x6c];
    uint gob_flags;
    byte pad70[8];
    int gob_xpos;
    int gob_ypos;
    byte pad80[0x3c];
    uint gob_pixc;
    struct_select_tile_ptr *gob_plut;
    byte padc4[4];
    int gob_xScale;
    int gob_yScale;
    byte padd0[0x10];
    uint gob_flags2;
    byte pade4[0x110];
    int gob_lastShown;
    int gob_last_x;
    int gob_last_y;
};
struct M1Tile {
    void *mt_image;
    ushort *mt_plut;
    uint mt_pixc;
};
struct M1TileTable {
    int mtt_tileID;
    M1Tile mtt_tile;
};
extern "C" {
int __cdecl GEX_WidescreenWidth(void);
extern int DAT_004a2974_CameraX_TrueCam2;
extern int DAT_004a2988_CameraY_TrueCam2;
extern int DAT_004a2a96_CameraX_After;
extern int M1_004a2a94;
extern int gTimer_004a2ac8;
extern int gObjectTextureMap_00460f6c;
extern M1TileTable *PTR_004a2ae4;
extern M1TileTable *DAT_004a2adc_Tiles2;
extern M1TileTable *DAT_004a2ae0_TilesBack1;
extern M1TileTable *DAT_004a2b18_Draw1;
extern ushort **DAT_004a2b14_Draw4;
extern ushort _DAT_004a2b20_Draw6;
void __cdecl GOB_DisplayObject_00444590(GXObject *);
SpriteStruct *__cdecl GOB_GetCurrentFrameOrReset_0041a500(GXObject *);
uint __cdecl FUN_0043e2c0(uint);
int *__cdecl FUN_0043e580_Image_Clean1(ImageStruct *);
int *__cdecl FUN_0043e920_Image(ImageStruct *);
uint __cdecl FUN_0043ecf0_SelectTile_Clean1(struct_select_tile_ptr *);
void __cdecl FUN_004432c0_Graphics(GXObject *param_1)

{
  ushort *puVar1;
  short *psVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  struct_select_tile_ptr *psVar6;
  DrawStructUnk *pDVar7;
  ImageStruct *imageStruct;
  DrawStructUnk *pDVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  ushort uVar12;
  SpriteStruct *pSVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  struct_select_tile_ptr *tileSelectPtr;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  short *psVar24;
  M1TileTable *pMVar25;
  ushort **ppuVar26;
  M1TileTable *pMVar27;
  uint uVar28;
  ushort **ppuVar29;
  undefined2 local_5a;
  short local_58;
  short local_56;
  int local_50;
  int local_4c;
  int *local_48;
  int local_44;
  int local_40;
  ushort *local_3c;
  int *local_20;
  uint *local_1c;
  uint local_18;

  uVar4 = param_1->gob_xScale;
  uVar5 = param_1->gob_yScale;
  if ((uVar4 == 0x10000) && (uVar5 == 0x10000)) {
    GOB_DisplayObject_00444590(param_1);
    return;
  }
  pSVar13 = GOB_GetCurrentFrameOrReset_0041a500(param_1);
  if (pSVar13 == (SpriteStruct *)0x0) {
    return;
  }
  iVar14 = param_1->gob_xpos - DAT_004a2974_CameraX_TrueCam2;
  iVar15 = param_1->gob_ypos - DAT_004a2988_CameraY_TrueCam2;
  psVar6 = param_1->gob_plut;
  if (((param_1->gob_flags2 & 0x1000000U) == 0) && (param_1->gob_lastShown - gTimer_004a2ac8 == -1))
  {
    iVar19 = param_1->gob_xpos - param_1->gob_last_x;
    if (iVar19 < 0) {
      iVar19 = iVar19 + 0x10000;
    }
    local_58 = (short)(iVar19 >> 0x11) - DAT_004a2a96_CameraX_After;
    iVar19 = param_1->gob_ypos - param_1->gob_last_y;
    if (iVar19 < 0) {
      iVar19 = iVar19 + 0x10000;
    }
    local_56 = (short)(iVar19 >> 0x11) - M1_004a2a94;
    uVar20 = (int)local_56 >> 0x1f;
    uVar21 = (int)local_58 >> 0x1f;
    if ((int)(((((int)local_56 ^ uVar20) - uVar20) - uVar21) + ((int)local_58 ^ uVar21)) < 0x65)
    goto LAB_004433dc;
  }
  local_58 = 0;
  local_56 = 0;
LAB_004433dc:
  local_1c = (uint *)pSVar13->field_0x18_DrawStruct;
  if ((DrawStructUnk *)local_1c != (DrawStructUnk *)0x0) {
    pDVar7 = ((DrawStructUnk *)local_1c)->field_0x0_NextDrawStruct_unk;
    while (pDVar7 != (DrawStructUnk *)0x0) {
      local_1c = &((DrawStructUnk *)local_1c)->field_0x4_NextDrawStruct;
      imageStruct = pDVar7->field_0x8_ImageObject;
      psVar24 = &imageStruct->field_0x14_Image;
      if (*psVar24 != 0) {
        uVar20 = pDVar7->field_0x4_NextDrawStruct;
        pDVar8 = pDVar7->field_0x0_NextDrawStruct_unk;
        uVar21 = param_1->gob_flags >> 2 | uVar20;
        if ((uVar20 & 0x80000000) == 0) {
          local_50 = *(int *)&imageStruct->x_offset;
        }
        else {
          local_50 = *(int *)imageStruct - *(int *)&imageStruct->x_offset;
        }
        if ((uVar20 & 0x40000000) == 0) {
          local_4c = *(int *)&imageStruct->y_offset;
        }
        else {
          local_4c = *(int *)&imageStruct->height - *(int *)&imageStruct->y_offset;
        }
        if ((uVar21 & 0x20000000) == 0) {
          local_50 = local_50 + ((uint)pDVar8 & 0xffff0000) + iVar14;
        }
        else {
          local_50 = (iVar14 - local_50) - ((uint)pDVar8 & 0xffff0000);
        }
        if ((uVar21 & 0x10000000) == 0) {
          local_4c = local_4c + (int)pDVar8 * 0x10000 + iVar15;
        }
        else {
          local_4c = (iVar15 - local_4c) + (int)pDVar8 * -0x10000;
        }
        uVar21 = uVar21 ^ uVar21 * 4;
        uVar20 = uVar21 & 0x80000000;
        if (uVar20 == 0) {
          local_44 = local_50 + *(int *)imageStruct;
        }
        else {
          local_44 = local_50;
          local_50 = local_50 - *(int *)imageStruct;
        }
        uVar21 = uVar21 & 0x40000000;
        if (uVar21 == 0) {
          local_40 = local_4c + *(int *)&imageStruct->height;
        }
        else {
          local_40 = local_4c;
          local_4c = local_4c - *(int *)&imageStruct->height;
        }
        local_20 = &imageStruct->height;
        if (uVar4 == 0x10000) {
          local_50 = local_50 >> 0x10;
        }
        else {
          uVar28 = local_50 - iVar14;
          uVar16 = (uVar28 ^ (int)uVar28 >> 0x1f) - ((int)uVar28 >> 0x1f);
          uVar17 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
          uVar18 = uVar17 & 0xffff;
          iVar22 = (uVar17 & 0xffff0000) + uVar18;
          uVar23 = uVar16 & 0xffff;
          iVar19 = ((int)uVar16 >> 0x10) * iVar22 + ((int)(uVar18 * uVar23) >> 0x10) +
                   ((int)uVar17 >> 0x10) * uVar23;
          if (0 < (int)uVar28 != 0 < (int)uVar4) {
            iVar19 = -iVar19;
          }
          local_50 = iVar14 + iVar19 >> 0x10;
          uVar28 = local_44 - iVar14;
          uVar16 = (uVar28 ^ (int)uVar28 >> 0x1f) - ((int)uVar28 >> 0x1f);
          uVar23 = uVar16 & 0xffff;
          local_44 = ((int)(uVar18 * uVar23) >> 0x10) + ((int)uVar16 >> 0x10) * iVar22 +
                     ((int)uVar17 >> 0x10) * uVar23;
          if (0 < (int)uVar28 == 0 < (int)uVar4) {
            local_44 = local_44 + iVar14;
          }
          else {
            local_44 = iVar14 - local_44;
          }
        }
        local_44 = local_44 >> 0x10;
        iVar19 = local_44;
        if (uVar5 == 0x10000) {
          local_4c = local_4c >> 0x10;
          local_40 = local_40 >> 0x10;
        }
        else {
          uVar16 = local_4c - iVar15;
          uVar17 = (uVar16 ^ (int)uVar16 >> 0x1f) - ((int)uVar16 >> 0x1f);
          uVar18 = (uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f);
          uVar23 = uVar17 & 0xffff;
          uVar28 = uVar18 & 0xffff;
          iVar22 = ((int)uVar18 >> 0x10) * uVar23 +
                   ((uVar18 & 0xffff0000) + uVar28) * ((int)uVar17 >> 0x10) +
                   ((int)(uVar28 * uVar23) >> 0x10);
          if (0 < (int)uVar16 != 0 < (int)uVar5) {
            iVar22 = -iVar22;
          }
          local_4c = iVar15 + iVar22 >> 0x10;
          uVar17 = local_40 - iVar15;
          uVar16 = (uVar17 ^ (int)uVar17 >> 0x1f) - ((int)uVar17 >> 0x1f);
          iVar22 = ((uVar16 & 0xffff0000) + (uVar16 & 0xffff)) * ((int)uVar18 >> 0x10) +
                   ((int)uVar16 >> 0x10) * uVar28 + ((int)(uVar28 * (uVar16 & 0xffff)) >> 0x10);
          if (0 < (int)uVar17 == 0 < (int)uVar5) {
            local_40 = iVar22 + iVar15 >> 0x10;
          }
          else {
            local_40 = iVar15 - iVar22 >> 0x10;
          }
        }
        iVar22 = local_4c;
        if ((((local_50 < GEX_WidescreenWidth()) && (-1 < local_44)) && (local_4c < 0xf0)) && (-1 < local_40)) {
          bVar3 = imageStruct->field16_0x10;
          iVar9 = *(int *)imageStruct;
          iVar10 = *(int *)local_20;
          local_18 = param_1->gob_pixc;
          if (local_18 == 0) {
            local_18 = pDVar7->field4_0x10;
          }
          uVar16 = FUN_0043e2c0(local_18);
          if (uVar20 == 0) {
            if (uVar21 != 0) {
              local_4c = local_40;
              local_40 = iVar22;
            }
          }
          else {
            local_44 = local_50;
            local_50 = iVar19;
            if (uVar21 != 0) {
              local_4c = local_40;
              local_40 = iVar22;
            }
          }
          if ((imageStruct->field16_0x10 & 0x40) == 0) {
            if (imageStruct->field24_0x1c == 0) {
              local_48 = FUN_0043e580_Image_Clean1(imageStruct);
            }
            else {
              local_48 = FUN_0043e920_Image(imageStruct);
            }
          }
          else {
            local_3c = (ushort *)
                       (gObjectTextureMap_00460f6c + imageStruct->field_0x12_CacheSlotNumber * 8);
          }
          if ((bVar3 & 3) != 2) {
            tileSelectPtr = psVar6;
            if (psVar6 == (struct_select_tile_ptr *)0x0) {
              tileSelectPtr = (struct_select_tile_ptr *)pDVar7->field3_0xc;
            }
            uVar20 = FUN_0043ecf0_SelectTile_Clean1(tileSelectPtr);
            local_5a = (undefined2)uVar20;
          }
          if (*psVar24 != 0) {
            do {
              pMVar27 = PTR_004a2ae4 + 5;
              pMVar25 = PTR_004a2ae4;
              PTR_004a2ae4 = pMVar27;
              if (DAT_004a2adc_Tiles2 < pMVar27) {
                pMVar25 = DAT_004a2ae0_TilesBack1;
                PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + 5;
              }
              (pMVar25->mtt_tile).mt_image =
                   (void *)
                   (uVar16 | (-(uint)((local_18 & 0x8080) == 0) & 0xfe000000) + 0x2e000000);
              *(undefined2 *)((int)&(pMVar25->mtt_tile).mt_pixc + 2) = local_5a;
              sVar11 = (short)(((int)psVar24[2] * (local_44 - local_50)) / (iVar9 >> 0x10)) +
                       (short)local_50;
              *(short *)&pMVar25[1].mtt_tile.mt_plut = sVar11;
              *(short *)&(pMVar25->mtt_tile).mt_plut = sVar11;
              sVar11 = (short)((int)(((uint)*(byte *)(psVar24 + 1) + (int)psVar24[2]) *
                                    (local_44 - local_50)) / (iVar9 >> 0x10)) + (short)local_50;
              *(short *)&pMVar25[2].mtt_tileID = sVar11;
              *(short *)&pMVar25[1].mtt_tileID = sVar11;
              sVar11 = (short)(((int)psVar24[3] * (local_40 - local_4c)) / (iVar10 >> 0x10)) +
                       (short)local_4c;
              *(short *)((int)&pMVar25[1].mtt_tileID + 2) = sVar11;
              *(short *)((int)&(pMVar25->mtt_tile).mt_plut + 2) = sVar11;
              sVar11 = (short)((int)(((uint)*(byte *)((int)psVar24 + 3) + (int)psVar24[3]) *
                                    (local_40 - local_4c)) / (iVar10 >> 0x10)) + (short)local_4c;
              *(short *)((int)&pMVar25[2].mtt_tileID + 2) = sVar11;
              *(short *)((int)&pMVar25[1].mtt_tile.mt_plut + 2) = sVar11;
              if ((imageStruct->field16_0x10 & 0x40) == 0) {
                puVar1 = (ushort *)((int)&pMVar25[1].mtt_tile.mt_image + 2);
                uVar12 = *(ushort *)(local_48 + 4);
                if ((local_18 & 1) == 0) {
                  uVar12 = uVar12 | 0x20;
                }
                *puVar1 = uVar12;
                _DAT_004a2b20_Draw6 = *puVar1;
                *(undefined1 *)&(pMVar25->mtt_tile).mt_pixc = *(undefined1 *)((int)local_48 + 0x12);
                *(undefined1 *)((int)&(pMVar25->mtt_tile).mt_pixc + 1) =
                     *(undefined1 *)((int)local_48 + 0x13);
                *(byte *)&pMVar25[1].mtt_tile.mt_image =
                     *(byte *)(psVar24 + 1) + *(char *)((int)local_48 + 0x12) + -1;
                *(undefined1 *)((int)&pMVar25[1].mtt_tile.mt_image + 1) =
                     *(undefined1 *)((int)local_48 + 0x13);
                *(undefined1 *)&pMVar25[1].mtt_tile.mt_pixc = *(undefined1 *)((int)local_48 + 0x12);
                *(byte *)((int)&pMVar25[1].mtt_tile.mt_pixc + 1) =
                     *(byte *)((int)psVar24 + 3) + *(char *)((int)local_48 + 0x13) + -1;
                *(byte *)&pMVar25[2].mtt_tile.mt_image =
                     *(byte *)(psVar24 + 1) + *(char *)((int)local_48 + 0x12) + -1;
                *(byte *)((int)&pMVar25[2].mtt_tile.mt_image + 1) =
                     *(byte *)((int)psVar24 + 3) + *(char *)((int)local_48 + 0x13) + -1;
                local_48 = (int *)local_48[1];
              }
              else {
                puVar1 = (ushort *)((int)&pMVar25[1].mtt_tile.mt_image + 2);
                uVar12 = *local_3c;
                if ((local_18 & 1) == 0) {
                  uVar12 = uVar12 | 0x20;
                }
                *puVar1 = uVar12;
                _DAT_004a2b20_Draw6 = *puVar1;
                *(char *)&(pMVar25->mtt_tile).mt_pixc = (char)local_3c[1];
                *(undefined1 *)((int)&(pMVar25->mtt_tile).mt_pixc + 1) =
                     *(undefined1 *)((int)local_3c + 3);
                *(byte *)&pMVar25[1].mtt_tile.mt_image =
                     (char)local_3c[1] + *(byte *)(psVar24 + 1) + -1;
                *(undefined1 *)((int)&pMVar25[1].mtt_tile.mt_image + 1) =
                     *(undefined1 *)((int)local_3c + 3);
                *(char *)&pMVar25[1].mtt_tile.mt_pixc = (char)local_3c[1];
                *(byte *)((int)&pMVar25[1].mtt_tile.mt_pixc + 1) =
                     *(char *)((int)local_3c + 3) + *(byte *)((int)psVar24 + 3) + -1;
                *(byte *)&pMVar25[2].mtt_tile.mt_image =
                     (char)local_3c[1] + *(byte *)(psVar24 + 1) + -1;
                *(byte *)((int)&pMVar25[2].mtt_tile.mt_image + 1) =
                     *(char *)((int)local_3c + 3) + *(byte *)((int)psVar24 + 3) + -1;
                local_3c = local_3c + 4;
              }
              DAT_004a2b18_Draw1->mtt_tileID = (int)pMVar25;
              ppuVar26 = &pMVar25[2].mtt_tile.mt_plut;
              pMVar27 = pMVar25;
              ppuVar29 = ppuVar26;
              DAT_004a2b18_Draw1 = pMVar25;
              for (iVar19 = 10; iVar19 != 0; iVar19 = iVar19 + -1) {
                *ppuVar29 = (ushort *)pMVar27->mtt_tileID;
                pMVar27 = (M1TileTable *)&pMVar27->mtt_tile;
                ppuVar29 = ppuVar29 + 1;
              }
              if (local_58 != 0) {
                *(short *)&pMVar25[3].mtt_tileID = (short)pMVar25[3].mtt_tileID - local_58;
                ppuVar29 = &pMVar25[3].mtt_tile.mt_plut;
                *(short *)ppuVar29 = *(short *)ppuVar29 - local_58;
                *(short *)&pMVar25[4].mtt_tileID = (short)pMVar25[4].mtt_tileID - local_58;
                ppuVar29 = &pMVar25[4].mtt_tile.mt_plut;
                *(short *)ppuVar29 = *(short *)ppuVar29 - local_58;
              }
              if (local_56 != 0) {
                psVar2 = (short *)((int)&pMVar25[3].mtt_tileID + 2);
                *psVar2 = *psVar2 - local_56;
                psVar2 = (short *)((int)&pMVar25[3].mtt_tile.mt_plut + 2);
                *psVar2 = *psVar2 - local_56;
                psVar2 = (short *)((int)&pMVar25[4].mtt_tileID + 2);
                *psVar2 = *psVar2 - local_56;
                psVar2 = (short *)((int)&pMVar25[4].mtt_tile.mt_plut + 2);
                *psVar2 = *psVar2 - local_56;
              }
              psVar24 = psVar24 + 4;
              *DAT_004a2b14_Draw4 = (ushort *)ppuVar26;
              DAT_004a2b14_Draw4 = ppuVar26;
            } while (*psVar24 != 0);
          }
        }
      }
      pDVar7 = (DrawStructUnk *)*local_1c;
    }
  }
  return;
}


}
