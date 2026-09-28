typedef void *HANDLE;
typedef struct BITMAPINFOHEADER {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
} BITMAPINFOHEADER;
typedef struct RGBQUAD { unsigned char rgbBlue, rgbGreen, rgbRed, rgbReserved; } RGBQUAD;
typedef struct BITMAPINFO { BITMAPINFOHEADER bmiHeader; RGBQUAD bmiColors[1]; } BITMAPINFO;
typedef struct PALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; } PALETTEENTRY;
typedef struct LOGPALETTE { unsigned short palVersion; unsigned short palNumEntries; PALETTEENTRY palPalEntry[1]; } LOGPALETTE;
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
__declspec(dllimport) HANDLE __stdcall GlobalAlloc(unsigned int flags, unsigned long bytes);
__declspec(dllimport) void *__stdcall GlobalLock(HANDLE memory);
__declspec(dllimport) int __stdcall GlobalUnlock(HANDLE memory);
__declspec(dllimport) HANDLE __stdcall GlobalFree(HANDLE memory);
__declspec(dllimport) HANDLE __stdcall CreatePalette(const LOGPALETTE *palette);
HANDLE __cdecl GEX_Target(BITMAPINFO *info, int *colors)
{
    HANDLE palette;
    HANDLE memory;
    LOGPALETTE *logical;
    int i;
    palette = 0;
    if (info->bmiHeader.biBitCount <= 8)
        *colors = 1 << info->bmiHeader.biBitCount;
    else
        *colors = 0;
    if (*colors) {
        memory = GlobalAlloc(0x42, *colors * 4 + 8);
        logical = (LOGPALETTE *)GlobalLock(memory);
        logical->palVersion = 0x300;
        logical->palNumEntries = (unsigned short)*colors;
        for (i = 0; i < *colors; i++) {
            logical->palPalEntry[i].peRed = info->bmiColors[i].rgbRed;
            logical->palPalEntry[i].peGreen = info->bmiColors[i].rgbGreen;
            logical->palPalEntry[i].peBlue = info->bmiColors[i].rgbBlue;
            logical->palPalEntry[i].peFlags = 0;
        }
        palette = CreatePalette(logical);
        GlobalUnlock(memory);
        GlobalFree(memory);
    }
    return palette;
}
}
