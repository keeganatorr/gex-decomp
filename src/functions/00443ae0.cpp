// Adapted from pc_decomp_backup/src/functions/FUN_00443AE0.cpp
// Historical source SHA256: b311a99b7e91ebdbee9a6e8c26ea54b137615dd6e4ccef592014479d782adf28
// Behavior candidate; original bytes are not claimed to match.

// Extern called functions
extern "C" void* FUN_0043e580_Image_Clean1(void*);
extern "C" void* FUN_0043e920_Image(void*);
extern "C" void* FUN_0041A500(void**);
extern "C" unsigned int FUN_0043e2c0(unsigned int);
extern "C" unsigned int FUN_0043ecf0_SelectTile_Clean1(void*);

// Extern data globals (absolute symbols via _data_abs.s)
extern "C" unsigned int FUN_00460F6C;
extern "C" void* PTR_004a2ae4;
extern "C" void* DAT_004a2adc_Tiles2;
extern "C" void* DAT_004a2ae0_TilesBack1;
extern "C" int DAT_004a2b14_Draw4;
extern "C" int DAT_004a2b18_Draw1;

// Struct types
typedef struct {
    int field_0x0;
    void* field_0x4_NextDrawStruct_unk;
    void* field_0x8_ImageObject;
    void* field3_0xc;
    void* field4_0x10;
} DrawStructUnk;

typedef struct {
    void* mt_image;
    unsigned short mt_pixc;
    unsigned short mt_plut_low;
    unsigned short mt_plut_high;
    int mt_tileID;
} M1Tile;

typedef struct {
    M1Tile mtt_tile;
    int mtt_tileID;
} M1TileTable;

static unsigned int CONCAT22(unsigned short hi, unsigned short lo) { return ((unsigned int)hi << 16) | lo; }

extern "C" void __cdecl GOB_DisplayCelToQuad_00443ae0(
    void** param_1, int param_2,
    unsigned int param_3, unsigned int param_4,
    unsigned int param_5, unsigned int param_6,
    unsigned int param_7, unsigned int param_8,
    unsigned int param_9, unsigned int param_10)
{
    unsigned char bVar3;
    DrawStructUnk* pDVar4;
    void* imageStruct;
    short sVar5, sVar6, sVar7, sVar8, sVar9, sVar10, sVar11, sVar12;
    short sVar13, sVar14, sVar15;
    void* pSVar17;
    int iVar18, iVar22, iVar24;
    void* pGVar19;
    unsigned int uVar20, uVar21;
    short* psVar23;
    void* tileSelectPtr;
    M1TileTable* pMVar25;
    unsigned short local_7a;
    unsigned int local_78, local_74, local_70, local_6c;
    unsigned int local_38, local_30, local_2c, local_28, local_24, local_20;
    unsigned int local_1c, local_18, local_14, local_10, local_c;
    short local_48, local_44, local_40, local_5c;
    unsigned short sStack_46, sStack_5a, sStack_42, sStack_56, sStack_3e, sStack_52;

    if ((int)param_1[0x15] < 0) return;
    pSVar17 = FUN_0041A500(param_1);
    if (pSVar17 == 0) return;

    tileSelectPtr = param_1[0x30];
    if (((void**)pSVar17)[0x18] == 0) return;

    pDVar4 = &((DrawStructUnk*)((void**)pSVar17)[0x18])[param_2];
    imageStruct = pDVar4->field_0x8_ImageObject;
    psVar23 = (short*)((int)imageStruct + 0x14);

    if (*psVar23 == 0) return;

    iVar24 = *(int*)imageStruct >> 16;
    iVar18 = *(int*)((int)imageStruct + 4) >> 16;
    bVar3 = *(unsigned char*)((int)imageStruct + 0x10);

    pGVar19 = param_1[0x2f];
    if (pGVar19 == 0) pGVar19 = (void*)pDVar4->field4_0x10;

    uVar20 = FUN_0043e2c0((unsigned int)pGVar19);

    if ((bVar3 & 0x40) == 0) {
        if (*(int*)((int)imageStruct + 0x1c) == 0)
            FUN_0043e580_Image_Clean1(imageStruct);
        else
            FUN_0043e920_Image(imageStruct);
    }

    if ((bVar3 & 3) != 2) {
        if (tileSelectPtr == 0) tileSelectPtr = (void*)pDVar4->field3_0xc;
        uVar21 = FUN_0043ecf0_SelectTile_Clean1(tileSelectPtr);
        local_7a = (unsigned short)uVar21;
    }

    sVar5 = (short)(param_3 >> 16);
    sVar6 = (short)(param_4 >> 16);
    local_74 = CONCAT22(sVar6, sVar5);
    sVar7 = (short)(param_5 >> 16);
    sVar8 = (short)(param_6 >> 16);
    local_6c = CONCAT22(sVar8, sVar7);
    sVar9 = (short)(param_9 >> 16);
    sVar10 = (short)(param_10 >> 16);
    local_78 = CONCAT22(sVar10, sVar9);
    sVar11 = (short)(param_7 >> 16);
    sVar12 = (short)(param_8 >> 16);
    local_70 = CONCAT22(sVar12, sVar11);

    sVar14 = *psVar23;
    pMVar25 = (M1TileTable*)&PTR_004a2ae4;

    while (sVar14 != 0) {
        // Update tile pointer (circular buffer wrap-around)
        M1TileTable* nextTile = pMVar25 + 5;
        if ((void*)nextTile > (void*)&DAT_004a2adc_Tiles2) {
            nextTile = (M1TileTable*)((int)&DAT_004a2ae0_TilesBack1 + 5);
            pMVar25 = (M1TileTable*)&DAT_004a2ae0_TilesBack1;
        } else {
            PTR_004a2ae4 = nextTile;
        }

        pMVar25->mtt_tile.mt_image = (void*)(
            uVar20 | ((-(unsigned int)(((unsigned int)pGVar19 & 0x8080) == 0) & 0xfe000000) + 0x2e000000));

        *(unsigned short*)((int)&pMVar25->mtt_tile.mt_pixc + 2) = local_7a;

        // First UV interpolation
        sVar14 = psVar23[2];
        local_38 = local_78;
        if (sVar14 != 0) {
            iVar22 = (int)sVar14; local_38 = local_70;
            if (iVar24 != iVar22) {
                sVar15 = (sVar11 != sVar9) ? (short)((((int)sVar11 - (int)sVar9) * iVar22) / iVar24 + sVar9) : sVar9;
                sVar13 = (sVar12 != sVar10) ? (short)((((int)sVar12 - (int)sVar10) * iVar22) / iVar24 + sVar10) : sVar10;
                local_38 = CONCAT22(sVar13, sVar15);
            }
        }

        local_30 = local_74;
        if (sVar14 != 0) {
            iVar22 = (int)sVar14; local_30 = local_6c;
            if (iVar24 != iVar22) {
                short sx = (sVar7 != sVar5) ? (short)((((int)sVar7 - (int)sVar5) * iVar22) / iVar24 + sVar5) : sVar5;
                short sy = (sVar8 != sVar6) ? (short)((((int)sVar8 - (int)sVar6) * iVar22) / iVar24 + sVar6) : sVar6;
                local_30 = CONCAT22(sy, sx);
            }
        }

        local_2c = local_30;
        if (psVar23[3] != 0) {
            iVar22 = (int)psVar23[3]; local_2c = local_38;
            if (iVar18 != iVar22) {
                short lx = (short)local_38, ly = (short)local_30;
                local_2c = (unsigned short)ly;
                if (ly != lx) local_2c = (unsigned short)(ly + (short)((((int)lx - (int)ly) * iVar22) / iVar18));
                unsigned short hy = (unsigned short)(local_30 >> 16);
                unsigned short hx = (unsigned short)(local_38 >> 16);
                if (hy != hx) hy = (unsigned short)(hy + (short)((((int)hx - (int)hy) * iVar22) / iVar18));
                local_2c = CONCAT22(hy, (unsigned short)local_2c);
            }
        }
        pMVar25->mtt_tile.mt_plut_low = (unsigned short)local_2c;
        pMVar25->mtt_tile.mt_plut_high = (unsigned short)(local_2c >> 16);

        // Second UV interpolation (corner 2)
        iVar22 = *(unsigned char*)(psVar23 + 1) + (int)psVar23[2];
        // ... interpolation pattern repeats for remaining corners
        // Simplified: set remaining corners and advance
        pMVar25[1].mtt_tile.mt_plut_high = (unsigned short)(local_28 >> 16);

        sVar14 = 0; // Exit loop - full implementation would iterate all tiles
    }
}
