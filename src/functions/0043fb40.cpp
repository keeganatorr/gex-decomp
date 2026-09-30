extern "C" {
int __cdecl abs(int);
extern short DAT_004a2a96_CameraX_After;
extern short FUN_004A2A94;
extern int *DAT_0046bc74_draw1data;
extern int *DAT_0046bc6c_drawunk1data;
extern int *DAT_0046bc70_draw4data;
extern int *DAT_0046bc68_drawunk4data;
extern int DAT_0046bc64_draw1ptr;
struct Tag { unsigned addr : 24; unsigned len : 8; };
extern int DAT_0046bc58_drawunk1ptr;
extern int DAT_0046bc60_draw4ptr;
extern int DAT_0046bc5c_drawunk4ptr;

struct TileMap {
    int f0;
    int f4;
    int f8;
    int width;
    int height;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int tiles[1];
};

void __cdecl FUN_0043fce0_DrawTilesInner(int, void *, int, int);
int __cdecl GEX_WidescreenWidth(void);

void __cdecl RM_DrawTiles_0043fb40(struct TileMap *map, void *gfx, int camX, int camY)
{
    int cols;
    int rows;
    int skip;
    int cx;
    int cy;
    int *p;
    int x;
    int n;
    cx = abs(DAT_004a2a96_CameraX_After) << 17;
    cy = abs(FUN_004A2A94) << 17;
    if (camY < cy)
        cy = camY;
    if (camX < cx)
        cx = camX;
    DAT_0046bc74_draw1data = &DAT_0046bc64_draw1ptr;
    DAT_0046bc6c_drawunk1data = &DAT_0046bc58_drawunk1ptr;
    DAT_0046bc58_drawunk1ptr = 0xffffff;
    DAT_0046bc64_draw1ptr = 0xffffff;
    ((struct Tag *)DAT_0046bc6c_drawunk1data)->len = 0;
    DAT_0046bc70_draw4data = &DAT_0046bc60_draw4ptr;
    DAT_0046bc68_drawunk4data = &DAT_0046bc5c_drawunk4ptr;
    DAT_0046bc5c_drawunk4ptr = 0xffffff;
    DAT_0046bc60_draw4ptr = 0xffffff;
    ((struct Tag *)DAT_0046bc68_drawunk4data)->len = 0;
    p = map->tiles + ((camY - cy) >> 24) * map->width + ((camX - cx) >> 24);
    skip = map->height - (camY >> 24);
    cols = skip != 1;
    rows = cols + 1;
    cols = map->width - ((camX - cx) >> 24);
    int visibleColumns = ((GEX_WidescreenWidth() + 255) >> 8) + 1;
    if (cols > visibleColumns)
        cols = visibleColumns;
    camX = -(camX & 0xff0000);
    camY = -(camY & 0xff0000);
    if (cx + camX > 0)
        camX -= 0x1000000;
    if (cy + camY > 0)
        camY -= 0x1000000;
    skip = map->width - cols;
    do {
        x = camX;
        n = cols;
        do {
            if (*p)
                FUN_0043fce0_DrawTilesInner(*p, gfx, x, camY);
            p++;
            x += 0x1000000;
        } while (--n);
        p += skip;
        camY += 0x1000000;
    } while (--rows);
}
}
