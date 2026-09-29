typedef struct ImageCache {
    short packed;           /* 0x0 */
    unsigned char offset;   /* 0x2 */
    unsigned char row;      /* 0x3 */
    unsigned short source;  /* 0x4 */
    unsigned short page;    /* 0x6 */
} ImageCache;
typedef struct TilePTRStruct {
    unsigned char unk0[0x10];
    unsigned char bank;     /* 0x10 */
    unsigned char unk11;
    short cacheSlot;        /* 0x12 */
    short count;            /* 0x14 */
} TilePTRStruct;
extern "C" {
extern int gNumImageCaches_0046bc78;
extern ImageCache *gImageCache_00460e08;
extern char s_RM_ExtraResolve_on_x_tile_d_00460f24[];
extern char s_Tile_already_loaded_at_position_00460eec[];
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
void __cdecl RM_ExtraResolve_00440750(TilePTRStruct *tile)
{
    ImageCache *cache;
    int bank;
    unsigned short source;
    unsigned short page;
    if (tile->cacheSlot < 0 && tile->count) {
        TracePrintf_Debug_00405390(s_RM_ExtraResolve_on_x_tile_d_00460f24, tile, gNumImageCaches_0046bc78);
        cache = &gImageCache_00460e08[gNumImageCaches_0046bc78];
        tile->cacheSlot = (short)gNumImageCaches_0046bc78;
        gNumImageCaches_0046bc78++;
        bank = tile->bank & 3;
        source = cache->source;
        page = cache->page;
        cache->packed = (short)(((source & 0x3c0) >> 2) | (page & 0x100)) >> 4 | (bank & 3) << 7;
        cache->row = (unsigned char)page;
        switch (bank) {
        case 1:
            cache->offset = (source & 0x3f) * 2;
            break;
        case 2:
            cache->offset = source & 0x3f;
            break;
        default:
            cache->offset = source << 2;
            break;
        }
    } else
        TracePrintf_Debug_00405390(s_Tile_already_loaded_at_position_00460eec, gNumImageCaches_0046bc78, tile->cacheSlot);
}
}
