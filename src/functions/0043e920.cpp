typedef unsigned char byte;

struct CD_IMAGE {
    byte unused_00[16];
    byte cdi_pixc;
    byte unused_11;
    short cacheSlot;
};

struct CD_UIMAGE {
    CD_IMAGE cdu_image;
    unsigned int cdu_data[1];
};

struct TileSlotStruct {
    TileSlotStruct *next;
    TileSlotStruct *prev;
    short *cacheSlot;
    unsigned int unused_0c;
    unsigned int unused_10;
};

extern "C" {
void __cdecl FUN_00405350(char *, int);
void __cdecl __debugbreak(void);
void __cdecl IMG_Unpack_0043e730(void *, void *, int);
void __cdecl FUN_0043e800_ProcessTileData(TileSlotStruct *, unsigned int *, CD_UIMAGE *, unsigned int);

extern char s_ERROR__empty_image__x_0046011c[];
extern char s_ERROR__invalid_cache_slot_number_004600f4[];
extern TileSlotStruct DrawCacheEntry_ARRAY_00467188[];
extern TileSlotStruct FUN_00465358;
extern byte *PTR_004a2ae4;
extern byte *DAT_004a2adc_Tiles2;
extern byte *DAT_004a2ae0_TilesBack1;
}

extern "C" TileSlotStruct * __cdecl FUN_0043e920_Image(CD_UIMAGE *Image)
{
    short sVar1;
    TileSlotStruct *pTVar3;
    unsigned int *puVar4;
    unsigned int uVar5;
    short *psVar7;
    unsigned int *dataStart;
    int byteSize;
    short sVar8;
    unsigned int uVar9;
    byte *dataEnd;
    TileSlotStruct *pTVar10;
    TileSlotStruct *local_c;

    puVar4 = Image->cdu_data;
    dataStart = puVar4;
    uVar5 = (byte)Image->cdu_image.cdi_pixc & 3;

    if ((short)*puVar4 == 0) {
        FUN_00405350(s_ERROR__empty_image__x_0046011c, (int)Image);
        __debugbreak();
    }

    psVar7 = &Image->cdu_image.cacheSlot;
    sVar1 = *psVar7;
    if (sVar1 < -1 || sVar1 >= 0x294) {
        FUN_00405350(s_ERROR__invalid_cache_slot_number_004600f4, (int)sVar1);
        __debugbreak();
    }

    sVar1 = *psVar7;
    if (sVar1 >= 0) {
        local_c = DrawCacheEntry_ARRAY_00467188 + sVar1;
        pTVar10 = local_c->next;
        sVar8 = (short)*puVar4;
        while (sVar8 != 0) {
            pTVar10 = pTVar10->prev;
            dataStart += 2;
            sVar8 = (short)*dataStart;
        }
        pTVar10->prev->next = local_c->next;
        local_c->next->prev = pTVar10->prev;
    } else {
        if ((Image->cdu_image.cdi_pixc & 4) != 0) {
            byteSize = 0;
            sVar8 = 0;
            sVar1 = (short)*puVar4;
            while (sVar1 != 0) {
                sVar1 = (short)*dataStart;
                if (sVar8 < sVar1) {
                    uVar9 = ((unsigned int)*((byte *)dataStart + 2) + 7) & 0xfffffff8U;
                    if (uVar5 == 1) {
                        byteSize += (unsigned int)*((byte *)dataStart + 3) * uVar9;
                    } else if (uVar5 == 2) {
                        byteSize += (unsigned int)*((byte *)dataStart + 3) * uVar9 * 2;
                    } else {
                        byteSize += ((int)((unsigned int)*((byte *)dataStart + 3) * uVar9)) >> 1;
                    }
                    sVar8 = sVar1;
                }
                dataStart += 2;
                sVar1 = (short)*dataStart;
            }

            PTR_004a2ae4 = PTR_004a2ae4 + byteSize;
            if (DAT_004a2adc_Tiles2 < PTR_004a2ae4) {
                PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + byteSize;
                dataEnd = DAT_004a2ae0_TilesBack1;
            } else {
                dataEnd = PTR_004a2ae4 - byteSize;
            }

            dataStart += 2;
            IMG_Unpack_0043e730(dataEnd, dataStart, byteSize);
            Image = (CD_UIMAGE *)(dataEnd - (byte *)dataStart + (byte *)Image);
        }

        pTVar3 = FUN_00465358.prev;
        pTVar10 = &FUN_00465358;
        local_c = pTVar3;
        sVar1 = (short)*puVar4;
        while (sVar1 != 0) {
            pTVar10 = pTVar10->prev;
            if (pTVar10->cacheSlot != 0) {
                *pTVar10->cacheSlot = -1;
                pTVar10->cacheSlot = 0;
            }
            FUN_0043e800_ProcessTileData(pTVar10, puVar4, Image, uVar5);
            puVar4 += 2;
            sVar1 = (short)*puVar4;
        }

        pTVar3->cacheSlot = psVar7;
        *psVar7 = (short)(pTVar3 - DrawCacheEntry_ARRAY_00467188);
        FUN_00465358.prev = pTVar10->prev;
        pTVar10->prev->next = &FUN_00465358;
    }

    local_c->next = FUN_00465358.next;
    FUN_00465358.next->prev = local_c;
    FUN_00465358.next = pTVar10;
    pTVar10->prev = &FUN_00465358;
    return local_c;
}
