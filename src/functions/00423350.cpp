typedef struct GXObject {
    unsigned char _pad0[0x70];
    int type;          /* 0x70 */
    unsigned char _pad74[0x4];
    int xpos;          /* 0x78 */
    int ypos;          /* 0x7c */
    unsigned char _pad80[0x44];
    int angle;         /* 0xc4 */
} GXObject;
typedef struct TileMap {
    int unk0;
    int width;
    int height;
} TileMap;
typedef struct Level {
    int unk0;
    TileMap *map;
    int unk8[3];
    int tiles;
} Level;
typedef struct Tile {
    unsigned short unk0;
    unsigned short contour;
    unsigned short unk4;
    unsigned short info;
} Tile;
typedef struct TileInfo {
    unsigned int flags;
    int unk4[7];
} TileInfo;
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
extern Level *M1_CurrentLevel_004a2990;
extern int INT_ARRAY_00456f40[];
extern TileInfo DAT_0045B9A0[];
extern char DAT_004a286c[];
extern char DAT_004a2820[];
extern char DAT_004a2848[];
extern char DAT_004a2868[];
Tile *__cdecl FUN_00440430_CheckWallCollisionInner(TileMap *map, int tiles, int x, int y);
int __cdecl M1_GetContourDataFromID_0040f100(Level *level, int id, int x);

void __cdecl GEX_Target(GXObject *gob)
{
    int left;
    int right;
    int top;
    int bottom;
    int x;
    int y;
    int i;
    Tile *tile;
    unsigned int solid;
    int mask;
    int mask2;
    int contour;
    int id;
    unsigned int solid2;

    if ((gob->angle + 0x200000) & 0x400000) {
        left = gob->xpos - 0x180000;
        right = gob->xpos + 0x180000;
        top = gob->ypos - 0x100000;
        bottom = gob->ypos + 0x100000;
    } else {
        left = gob->xpos - 0x100000;
        right = gob->xpos + 0x100000;
        top = gob->ypos - 0x180000;
        bottom = gob->ypos + 0x180000;
    }
    top += INT_ARRAY_00456f40[gob->type] - 0x200000;
    bottom += INT_ARRAY_00456f40[gob->type] - 0x200000;
    i = 0;
    x = left;
    for (;;) {
        if (x >= 0 && x < M1_CurrentLevel_004a2990->map->width) {
            if (top >= 0 && top < M1_CurrentLevel_004a2990->map->height) {
                tile = FUN_00440430_CheckWallCollisionInner(M1_CurrentLevel_004a2990->map, M1_CurrentLevel_004a2990->tiles, x, top);
                if (tile && (id = tile->info) <= 0x7d) {
                    solid = (DAT_0045B9A0[id].flags & 0xf0000) >> 16;
                    mask = 1 << (((x & 0x100000) == 0) | ((top & 0x100000) ? 0 : 2));
                    if (tile->contour) {
                        contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, tile->contour, x);
                        if (contour && (top & 0x1f0000) >= contour - 0x10000)
                            solid = 0;
                    }
                    if (solid & mask)
                        DAT_004a286c[i] = 1;
                }
            }
            if (bottom >= 0 && bottom < M1_CurrentLevel_004a2990->map->height) {
                tile = FUN_00440430_CheckWallCollisionInner(M1_CurrentLevel_004a2990->map, M1_CurrentLevel_004a2990->tiles, x, bottom);
                if (tile && (id = tile->info) <= 0x7d) {
                    solid = (DAT_0045B9A0[id].flags & 0xf0000) >> 16;
                    mask = 1 << (((x & 0x100000) == 0) | ((bottom & 0x100000) ? 0 : 2));
                    if (tile->contour) {
                        contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, tile->contour, x);
                        if (contour && (bottom & 0x1f0000) >= contour - 0x10000)
                            solid = 0;
                    }
                    if (solid & mask)
                        DAT_004a2820[i] = 1;
                }
            }
        }
        if (x == right)
            break;
        i++;
        x += 0x100000;
        if (x > right)
            x = right;
    }
    i = 0;
    y = top;
    for (;;) {
        if (y >= 0 && y < M1_CurrentLevel_004a2990->map->height) {
            if (left >= 0 && left < M1_CurrentLevel_004a2990->map->width) {
                tile = FUN_00440430_CheckWallCollisionInner(M1_CurrentLevel_004a2990->map, M1_CurrentLevel_004a2990->tiles, left, y);
                if (tile && (id = tile->info) <= 0x7d) {
                    solid = (DAT_0045B9A0[id].flags & 0xf0000) >> 16;
                    mask = 1 << (((left & 0x100000) == 0) | ((y & 0x100000) ? 0 : 2));
                    if (tile->contour) {
                        contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, tile->contour, left);
                        if (contour && (y & 0x1f0000) >= contour - 0x10000)
                            solid = 0;
                    }
                    if (solid & mask)
                        DAT_004a2848[i] = 1;
                }
            }
            if (right >= 0 && right < M1_CurrentLevel_004a2990->map->width) {
                tile = FUN_00440430_CheckWallCollisionInner(M1_CurrentLevel_004a2990->map, M1_CurrentLevel_004a2990->tiles, right, y);
                if (tile && (id = tile->info) <= 0x7d) {
                    solid2 = (DAT_0045B9A0[id].flags & 0xf0000) >> 16;
                    mask2 = 1 << (((right & 0x100000) == 0) | ((y & 0x100000) ? 0 : 2));
                    if (tile->contour) {
                        contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, tile->contour, right);
                        if (contour && (y & 0x1f0000) >= contour - 0x10000)
                            solid2 = 0;
                    }
                    if (solid2 & mask2)
                        DAT_004a2868[i] = 1;
                }
            }
        }
        if (y == bottom)
            break;
        i++;
        y += 0x100000;
        if (y > bottom)
            y = bottom;
    }
}
}
