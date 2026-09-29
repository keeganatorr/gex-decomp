// Adapted from pc_decomp_backup/src/functions/FUN_004405B0.cpp
// Historical source SHA256: fc82d62b44b305a619e460979b8e90ff43bb8cb1bd861702a0a0a88e5855f393
extern "C" {
extern int FUN_0046A678;
extern int *FUN_00460E08;
extern int FUN_004A2924;
extern int FUN_0046BC78;

extern "C" void *__cdecl FUN_0040B390(int, unsigned int);
extern "C" void __cdecl FUN_00405390(char *, ...);
extern "C" void __cdecl FUN_0043ec20_TileLoadinPoss(void *);
extern "C" void __cdecl FUN_004451e0_LEV_SetUpDrawCacheWithFileData(void *, short *);
extern "C" void __cdecl FUN_0040B860(void *);

extern "C" void __cdecl RM_LoadTextures_004405b0(void *blockTable, unsigned int rootLink)
{
    int cellCount = 0;
    int *listSlots;
    int *listSlot;
    unsigned char *cache;

    FUN_00405390((char *)0x00460ebc);
    listSlots = (int*)FUN_0040B390((int)blockTable, rootLink);

    
    
    for (listSlot = listSlots; *listSlot != 0; ++listSlot) {
        int *cellSlots = (int*)FUN_0040B390((int)blockTable,
                                            (unsigned int)*listSlot);
        *listSlot = (int)cellSlots;
        for (; *cellSlots != 0; ++cellSlots) {
            short *cell = (short*)FUN_0040B390((int)blockTable,
                                               (unsigned int)*cellSlots);
            *cellSlots = (int)cell;
            if (*cell != 0) ++cellCount;
        }
    }

    cache = (unsigned char*)&FUN_0046A678;
    FUN_00460E08 = (int*)&FUN_0046A678;
    for (listSlot = listSlots; *listSlot != 0; ++listSlot) {
        int *cellSlots = (int*)*listSlot;
        for (; *cellSlots != 0; ++cellSlots) {
            short *cell = (short*)*cellSlots;
            if (*cell != 0) {
                struct DrawCache {
                    short x, y, width, height;
                } drawCache;
                drawCache.x = 0;
                drawCache.y = 0;
                drawCache.width = cell[0];
                drawCache.height = cell[1];
                FUN_0043ec20_TileLoadinPoss(&drawCache);
                FUN_00405390((char *)0x00460e64, cell,
                             (int)drawCache.x, (int)drawCache.y);
                FUN_004451e0_LEV_SetUpDrawCacheWithFileData(
                    &drawCache, cell + 2);
                *(short *)(cache + 4) = drawCache.x;
                *(short *)(cache + 6) = drawCache.y;
                cache += 8;
            }
        }
    }

    FUN_00405390((char *)0x00460e38, cellCount);
    FUN_0040B860(blockTable);
    FUN_00405390((char *)0x00460e0c, FUN_004A2924);
    FUN_0046BC78 = 0;
}
}
