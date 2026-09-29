// Adapted from pc_decomp_backup/src/functions/FUN_0043ECF0.cpp
// Historical source SHA256: f0438524d4bbe477986ea485bff76290bb32e36fa33b3a9a09e1d0c8382c7761
extern "C" {
extern char DAT_00464e28_DrawCacheClear5[];
extern int FUN_00465370[];
extern char FUN_0046A518[];
extern int FUN_00464E58[];
extern int PTR_004a2ae4;
extern int DAT_004a2adc_Tiles2;
extern int DAT_004a2ae0_TilesBack1;
extern int PTR_004a2b1c;

extern "C" void __cdecl FUN_00405350(char *fmt, int val);

extern "C" unsigned int __cdecl FUN_0043ecf0_SelectTile_Clean1(void *tileSelectPtr)
{
    unsigned int crashResult;
    int *tilePtr;
    int *tileStruct;
    int *cacheSlotPtr;
    int *cacheArray;
    int slotIndexPtr;
    int cacheEnd;
    short cacheSlot;
    int crashFunc;
    char *errorFormat;
    int *tileDataPtr;

    // The pinned 0043ecf7 subtracts four from the palette-data pointer;
    // 0043ed00 reads the kind byte and 0043ed4e reads the slot at +2.
    if (*(char *)((int)tileSelectPtr - 4) == 0) {
        cacheEnd = (int)&DAT_00464e28_DrawCacheClear5;
        cacheArray = &FUN_00465370[0];
        cacheSlot = *(short *)((int)tileSelectPtr - 2);
        if ((-2 < cacheSlot) && (cacheSlot < 0x180)) goto FUN_0043ED6F;
        errorFormat = (char *)0x004601f8;
    }
    else {
        cacheEnd = (int)&FUN_0046A518;
        cacheArray = &FUN_00464E58[0];
        cacheSlot = *(short *)((int)tileSelectPtr - 2);
        if ((-2 < cacheSlot) && (cacheSlot < 0x40)) {
FUN_0043ED6F:
            slotIndexPtr = (int)tileSelectPtr - 2;
            if (*(short *)slotIndexPtr < 0) {
                cacheSlotPtr = *(int **)(cacheEnd + 4);
                *(int **)(cacheEnd + 4) = *(int **)(cacheSlotPtr + 1);
                *(int **)(*(int *)(cacheSlotPtr + 1)) = (int *)cacheEnd;
                if (*(int *)(cacheSlotPtr + 2) != 0) {
                    *(short *)(*(int *)(cacheSlotPtr + 2)) = -1;
                }
                *(int *)(cacheSlotPtr + 2) = slotIndexPtr;
                *(short *)slotIndexPtr = (short)(((int)cacheSlotPtr - (int)cacheArray) / 0x14);
                // 0043edd7 advances the command pool by 16 bytes.
                tilePtr = (int *)(PTR_004a2ae4 + 0x10);
                tileStruct = (int *)PTR_004a2ae4;
                PTR_004a2ae4 = (int)tilePtr;
                if (DAT_004a2adc_Tiles2 < (int)tilePtr) {
                    tileStruct = (int *)DAT_004a2ae0_TilesBack1;
                    PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + 0x10;
                }
                *(int *)PTR_004a2b1c = (int)tileStruct;
                tileDataPtr = (int *)*(int *)PTR_004a2b1c;
                PTR_004a2b1c = (int)tileDataPtr;
                tileDataPtr[1] = *(int *)(cacheSlotPtr + 3);
                *(short *)(tileDataPtr + 2) = (-(short)(*(char *)((int)tileSelectPtr - 4) == 0) & 0xff10) + 0x100;
                *(short *)((int)tileDataPtr + 10) = 1;
                tileDataPtr[3] = (int)tileSelectPtr;
            }
            else {
                cacheSlotPtr = (int *)(cacheArray + *(short *)slotIndexPtr * 5);
                *(int **)(*(int *)(cacheSlotPtr + 1)) = (int *)*cacheSlotPtr;
                // 0043ed92 stores the previous node, not the address of this
                // node's prev field. The latter corrupts the LRU list.
                *(int **)(*cacheSlotPtr + 4) = (int *)*(cacheSlotPtr + 1);
            }
            *cacheSlotPtr = *(int *)cacheEnd;
            *(int *)(cacheSlotPtr + 1) = cacheEnd;
            *(int *)(*cacheSlotPtr + 4) = (int)cacheSlotPtr;
            *(int *)cacheEnd = (int)cacheSlotPtr;
            return (unsigned int)((*(short *)(cacheSlotPtr + 4) & 0xffff) | ((unsigned int)(*cacheSlotPtr >> 16) << 16));
        }
        errorFormat = (char *)0x00460224;
    }
    FUN_00405350(errorFormat, (int)cacheSlot);
    return 0;
}
}
