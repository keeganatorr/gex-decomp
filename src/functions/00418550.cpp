typedef struct WallCollisionStruct {
    short unk0[3];
    unsigned short attribute;  /* 0x6 */
    short unk8;
    unsigned short switched;   /* 0xa: tile to show when the switch flips */
    int unkC;
} WallCollisionStruct;
typedef struct TileBlock { int unk0; int unk4; unsigned short cells[64]; } TileBlock;
typedef struct GexTileStruct {
    int unk0[3];
    int xTile;               /* 0xc */
    int yTile;               /* 0x10 */
    int unk14[6];
    TileBlock *blocks[1];    /* 0x2c */
} GexTileStruct;
typedef struct M1Level {
    int unk0;
    GexTileStruct *map;                /* 0x4 */
    int unk8[3];
    WallCollisionStruct **tileData;    /* 0x14 */
} M1Level;
typedef struct TileAttribute { unsigned int flags; int unk[7]; } TileAttribute;
extern "C" {
extern unsigned int SCRIPT_WorkRegister_0049fb90;
extern int gSwitch1_004a27bc;
extern int gSwitch1NumToggles_004a27c0;
extern int gSwitch2_004a27cc;
extern int gSwitch2NumToggles_004a27c4;
extern int gSwitch3_004a27c8;
extern int gSwitch3NumToggles_004a27d0;
extern M1Level *M1_CurrentLevel_004a2990;
extern TileAttribute DAT_0045B9A0[];
extern char s_ERROR_Bad_Switch_Number_ld_00458e4c[];
void __cdecl assertfail_00405350(const char *format, ...);
unsigned char *__cdecl SCRIPT_SwitchBlocks_00418550(unsigned char *script)
{
    unsigned int number;
    int valid;
    int count;
    TileBlock **blocks;
    TileBlock *block;
    int i;
    unsigned short *cell;
    WallCollisionStruct *wall;
    unsigned int index;
    number = SCRIPT_WorkRegister_0049fb90;
    switch (number) {
    case 1:
        valid = 1;
        gSwitch1_004a27bc = !gSwitch1_004a27bc;
        gSwitch1NumToggles_004a27c0++;
        break;
    case 2:
        valid = 1;
        gSwitch2_004a27cc = !gSwitch2_004a27cc;
        gSwitch2NumToggles_004a27c4++;
        break;
    case 3:
        valid = 1;
        gSwitch3_004a27c8 = !gSwitch3_004a27c8;
        gSwitch3NumToggles_004a27d0++;
        break;
    default:
        valid = 0;
        assertfail_00405350(s_ERROR_Bad_Switch_Number_ld_00458e4c, number);
        break;
    }
    if (valid) {
        count = M1_CurrentLevel_004a2990->map->xTile * M1_CurrentLevel_004a2990->map->yTile;
        blocks = M1_CurrentLevel_004a2990->map->blocks;
        for (; count; count--) {
            block = *blocks++;
            if (block) {
                cell = block->cells;
                for (i = 64; i; i--) {
                    index = *cell;
                    wall = M1_CurrentLevel_004a2990->tileData[index >> 5] + (index & 0x1f);
                    if ((DAT_0045B9A0[wall->attribute].flags & 0x300000) >> 20 == number)
                        *cell = wall->switched;
                    cell++;
                }
            }
        }
    }
    return script;
}
}
