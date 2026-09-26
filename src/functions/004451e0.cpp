typedef struct Rect16 { short x, y, w, h; } Rect16;
extern "C" {
extern unsigned short *gPaletteDataPtr_004a33ac;
int __cdecl GEX_Target(Rect16 *rect, unsigned short *data)
{
    unsigned short *dest = gPaletteDataPtr_004a33ac + (rect->y << 10) + rect->x;
    unsigned short *src = data;
    int skip = 0x400 - rect->w;
    int rows, n;
    for (rows = rect->h; rows; rows--) {
        for (n = rect->w; n; n--)
            *dest++ = *src++;
        dest += skip;
    }
    return 1;
}
}
