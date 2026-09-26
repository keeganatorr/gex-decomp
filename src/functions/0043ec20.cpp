typedef struct CachePos { short x; short y; } CachePos;
typedef struct DrawCache { CachePos pos; short width; short height; } DrawCache;
extern "C" {
extern CachePos DAT_00460040_MAIN_GAME_WIDTH;
extern short DAT_004600c8_DrawCacheCount;
void __cdecl FUN_0043eb50_LoadTilePoss(DrawCache *cache, int initialise);
void __cdecl GEX_Target(DrawCache *tile)
{
    if (DAT_00460040_MAIN_GAME_WIDTH.y <= 0x100 && tile->height + DAT_00460040_MAIN_GAME_WIDTH.y > 0x100)
        DAT_00460040_MAIN_GAME_WIDTH.y = 0x100;
    if (tile->height + DAT_00460040_MAIN_GAME_WIDTH.y > 0x1e0) {
        DAT_00460040_MAIN_GAME_WIDTH.x += DAT_004600c8_DrawCacheCount;
        DAT_00460040_MAIN_GAME_WIDTH.y = 0;
        DAT_004600c8_DrawCacheCount = 0;
    }
    if (((tile->width + DAT_00460040_MAIN_GAME_WIDTH.x - 1) & ~0x3f) > DAT_00460040_MAIN_GAME_WIDTH.x) {
        DAT_00460040_MAIN_GAME_WIDTH.x = (DAT_00460040_MAIN_GAME_WIDTH.x + tile->width - 1) & ~0x3f;
        DAT_00460040_MAIN_GAME_WIDTH.y = 0;
        DAT_004600c8_DrawCacheCount = 0;
    }
    if (tile->width > DAT_004600c8_DrawCacheCount)
        DAT_004600c8_DrawCacheCount = tile->width;
    tile->pos = DAT_00460040_MAIN_GAME_WIDTH;
    DAT_00460040_MAIN_GAME_WIDTH.y += tile->height;
    FUN_0043eb50_LoadTilePoss(tile, 0);
}
}
