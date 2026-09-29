typedef struct TilePos { short x; short y; } TilePos;
typedef struct DrawCache { TilePos pos; int data; } DrawCache;
typedef struct ImageCacheEntry { int id; TilePos pos; } ImageCacheEntry;
extern "C" {
extern ImageCacheEntry FUN_0046BD00[];
extern ImageCacheEntry *gObjectTextureMap_00460f6c;
extern int nblocksFree_004a2924;
extern int UINT_0046bcf8;
extern char s_Loaded_Object_Texture_data_0046100c[];
extern char s_Transferring_object_cell_00460fe0[];
extern char s_w_h_00460fcc[];
extern char s_All_texture_data_transferred_00460f9c[];
extern char s_After_GOB_LoadTextures_00460f70[];
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
int **__cdecl LINK_RESOLVE_0040b390(void *base, unsigned int offset);
void __cdecl FUN_0043ec20_TileLoadinPoss(DrawCache *cache);
void __cdecl FUN_004451e0_LEV_SetUpDrawCacheWithFileData(DrawCache *cache, short *data);
void __cdecl BLOC_FreeBlocks_0040b860(void *base);
void __cdecl GOB_LoadTextures_00440e70(void *base, unsigned int offset)
{
    int ***table;
    int ***p;
    int **tl;
    int **q;
    int *img;
    int nulls;
    int loaded;
    ImageCacheEntry *cache;
    DrawCache dc;
    nulls = 0;
    loaded = 0;
    TracePrintf_Debug_00405390(s_Loaded_Object_Texture_data_0046100c);
    table = (int ***)LINK_RESOLVE_0040b390(base, offset);
    p = table;
    do {
        if (*p) {
            tl = *p = LINK_RESOLVE_0040b390(base, (unsigned int)*p);
            for (; *tl; tl++) {
                *tl = (int *)LINK_RESOLVE_0040b390(base, (unsigned int)*tl);
                if (*(short *)*tl)
                    loaded++;
            }
        } else
            nulls++;
        p++;
    } while (nulls < 2);
    cache = FUN_0046BD00;
    gObjectTextureMap_00460f6c = cache;
    p = table;
    nulls = 0;
    do {
        q = *p;
        if (!q)
            nulls++;
        else {
            while ((img = *q++) != 0) {
                if (*(short *)img) {
                    dc.data = *img;
                    FUN_0043ec20_TileLoadinPoss(&dc);
                    TracePrintf_Debug_00405390(s_Transferring_object_cell_00460fe0, img, cache - gObjectTextureMap_00460f6c, dc.pos.x, dc.pos.y);
                    img++;
                    TracePrintf_Debug_00405390(s_w_h_00460fcc, ((unsigned short *)img)[-2], ((unsigned short *)img)[-1]);
                    cache++;
                    FUN_004451e0_LEV_SetUpDrawCacheWithFileData(&dc, (short *)img);
                    cache[-1].pos = dc.pos;
                }
            }
        }
        p++;
    } while (nulls < 2);
    TracePrintf_Debug_00405390(s_All_texture_data_transferred_00460f9c, loaded);
    BLOC_FreeBlocks_0040b860(base);
    TracePrintf_Debug_00405390(s_After_GOB_LoadTextures_00460f70, nblocksFree_004a2924);
    UINT_0046bcf8 = 0;
}
}
