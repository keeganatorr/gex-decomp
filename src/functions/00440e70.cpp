// Adapted from pc_decomp_backup/src/functions/FUN_00440E70.cpp
// Historical source SHA256: 7ef3be530953953badf123f5793930f465e1c1369e93d059348d9c9f9d820933
extern "C" {
extern int FUN_0046BD00;
extern int *FUN_00460F6C;
extern int FUN_004A2924;
extern int FUN_0046BCF8;

extern "C" void *__cdecl FUN_0040B390(int, unsigned int);
extern "C" void __cdecl FUN_00405390(char *, ...);
extern "C" void __cdecl FUN_0043ec20_TileLoadinPoss(void *);
extern "C" void __cdecl FUN_004451e0_LEV_SetUpDrawCacheWithFileData(void *, short *);
extern "C" void __cdecl FUN_0040B860(void *);

extern "C" void __cdecl GEX_Target(void *gexTileStruct, unsigned int param_2)
{
    int emptyLists = 0;
    int objectCellsCount = 0;
    FUN_00405390((char *)0x0046100c);

    unsigned int *lists = (unsigned int *)FUN_0040B390((int)gexTileStruct, param_2);
    unsigned int *listSlot = lists;
    do {
        if (*listSlot == 0) {
            ++emptyLists;
        } else {
            unsigned int *entries = (unsigned int *)FUN_0040B390(
                (int)gexTileStruct, *listSlot);
            *listSlot = (unsigned int)entries;
            while (*entries != 0) {
                unsigned short *cell = (unsigned short *)FUN_0040B390(
                    (int)gexTileStruct, *entries);
                *entries = (unsigned int)cell;
                if (*cell != 0) ++objectCellsCount;
                ++entries;
            }
        }
        ++listSlot;
    } while (emptyLists < 2);

    unsigned char *cache = (unsigned char *)&FUN_0046BD00;
    FUN_00460F6C = (int *)&FUN_0046BD00;
    emptyLists = 0;
    do {
        unsigned int *entries = (unsigned int *)*lists;
        if (entries == 0) {
            ++emptyLists;
        } else {
            unsigned short *cell = (unsigned short *)*entries;
            while (cell != 0) {
                ++entries;
                unsigned char *nextCache = cache;
                if (*cell != 0) {
                    struct DrawCache {
                        short x, y, width, height;
                    } drawCache;
                    drawCache.x = 0;
                    drawCache.y = 0;
                    drawCache.width = cell[0];
                    drawCache.height = cell[1];
                    FUN_0043ec20_TileLoadinPoss(&drawCache);
                    nextCache = cache + 8;
                    FUN_00405390((char *)0x00460fe0, cell,
                                 (int)(cache - (unsigned char *)FUN_00460F6C) >> 3,
                                 (int)drawCache.x, (int)drawCache.y);
                    FUN_00405390((char *)0x00460fcc,
                                 (unsigned int)cell[0], (unsigned int)cell[1]);
                    FUN_004451e0_LEV_SetUpDrawCacheWithFileData(
                        &drawCache, (short *)(cell + 2));
                    *(short *)(cache + 4) = drawCache.x;
                    *(short *)(cache + 6) = drawCache.y;
                }
                cache = nextCache;
                cell = (unsigned short *)*entries;
            }
        }
        ++lists;
    } while (emptyLists < 2);

    FUN_00405390((char *)0x00460f9c, objectCellsCount);
    FUN_0040B860(gexTileStruct);
    FUN_00405390((char *)0x00460f70, FUN_004A2924);
    FUN_0046BCF8 = 0;
}
}
