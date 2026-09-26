typedef struct DR_MODE {
    void *tag;
    unsigned int code[2];
} DR_MODE;
typedef struct TILE {
    void *tag;
    unsigned char r0, g0, b0, code;
    short x0, y0;
    short w, h;
} TILE;
extern "C" {
extern char *DAT_004a2adc_Tiles2;
extern char *PTR_004a2ae4;
extern char *DAT_004a2ae0_TilesBack1;
extern void **DAT_004a2b18_Draw1;
extern void **DAT_004a2b14_Draw4;
extern short DAT_004a2b20;
void __cdecl FUN_00445350_CalculateTileOffset_Clean1(DR_MODE *p, int dfe, int dtd, int tpage, void *tw);
void __cdecl GEX_Target(int unused, int x, int y, int w, int h, unsigned int colour, unsigned int flags)
{
    TILE *tile;
    DR_MODE *mode;
    if (DAT_004a2adc_Tiles2 < PTR_004a2ae4 + 0x20) {
        PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + 0x20;
        tile = (TILE *)DAT_004a2ae0_TilesBack1;
    } else {
        PTR_004a2ae4 += 0x20;
        tile = (TILE *)(PTR_004a2ae4 - 0x20);
    }
    if (DAT_004a2adc_Tiles2 < PTR_004a2ae4 + 0x18) {
        PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + 0x18;
        mode = (DR_MODE *)DAT_004a2ae0_TilesBack1;
    } else {
        PTR_004a2ae4 += 0x18;
        mode = (DR_MODE *)(PTR_004a2ae4 - 0x18);
    }
    FUN_00445350_CalculateTileOffset_Clean1(mode, 1, 1, 0, 0);
    DAT_004a2b20 = 0;
    tile->code = 0x60;
    tile->x0 = x >> 16;
    tile->y0 = y >> 16;
    tile->w = w >> 16;
    tile->h = h >> 16;
    tile->r0 = (colour >> 7) & 0xf8;
    tile->g0 = (colour >> 2) & 0xf8;
    tile->b0 = colour << 3;
    if (flags & 0x8080)
        tile->code |= 2;
    mode->tag = tile;
    *DAT_004a2b18_Draw1 = mode;
    DAT_004a2b18_Draw1 = (void **)tile;
    mode[1] = mode[0];
    tile[1] = tile[0];
    mode[1].tag = &tile[1];
    *DAT_004a2b14_Draw4 = &mode[1];
    DAT_004a2b14_Draw4 = (void **)&tile[1];
}
}
