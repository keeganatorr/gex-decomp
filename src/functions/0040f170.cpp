typedef struct TileMap { int unk0; int width; int height; } TileMap;
typedef struct Tile { unsigned short a, b, c, attribute; } Tile;
typedef struct Level { int unk0; TileMap *map; int unk8, unkc, unk10; void *tiles; } Level;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern int decl_pad_13;
extern int decl_pad_14;
extern int decl_pad_15;
extern int decl_pad_16;
extern int decl_pad_17;
extern int decl_pad_18;
extern int decl_pad_19;
extern int decl_pad_20;
extern int decl_pad_21;
extern int decl_pad_22;
extern int decl_pad_23;
extern int decl_pad_24;
extern Tile * __cdecl FUN_00440430_CheckWallCollisionInner(TileMap *, void *, int, int);
unsigned int __cdecl GEX_Target(Level *level, int x, int y)
{
    if (x < 0)
        return 1;
    if (y < 0)
        return 0;
    if (x >= level->map->width)
        return 1;
    if (y >= level->map->height)
        return 4;
    return FUN_00440430_CheckWallCollisionInner(level->map, level->tiles, x, y)->attribute;
}
}
