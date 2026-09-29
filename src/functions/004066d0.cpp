// GDI surfaces, palette and 15-bit-to-palette lookup from GDI_Init_004066d0.
// Behavior candidate; the original bytes remain the comparison oracle.
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef void *HANDLE;

struct GexBitmapInfoHeader {
    DWORD size;
    long width, height;
    unsigned short planes, bits;
    DWORD compression, sizeImage;
    long xPixelsPerMeter, yPixelsPerMeter;
    DWORD colorsUsed, colorsImportant;
};
struct GexPaletteEntry { unsigned char red, green, blue, flags; };

extern "C" {
__declspec(dllimport) HANDLE __stdcall GetDC(HANDLE);
__declspec(dllimport) int __stdcall SetStretchBltMode(HANDLE, int);
__declspec(dllimport) HANDLE __stdcall CreateFileMappingA(HANDLE, void *, DWORD,
                                                           DWORD, DWORD, const char *);
__declspec(dllimport) UINT __stdcall SetSystemPaletteUse(HANDLE, UINT);
__declspec(dllimport) UINT __stdcall GetSystemPaletteEntries(HANDLE, UINT, UINT,
                                                              GexPaletteEntry *);
__declspec(dllimport) HANDLE __stdcall CreatePalette(const void *);
__declspec(dllimport) HANDLE __stdcall SelectPalette(HANDLE, HANDLE, int);
__declspec(dllimport) UINT __stdcall RealizePalette(HANDLE);
__declspec(dllimport) HANDLE __stdcall CreateCompatibleDC(HANDLE);
__declspec(dllimport) HANDLE __stdcall CreateDIBSection(HANDLE, const void *, UINT,
                                                         void **, HANDLE, DWORD);
__declspec(dllimport) HANDLE __stdcall CreateFontIndirectA(const void *);
__declspec(dllimport) HANDLE __stdcall SelectObject(HANDLE, HANDLE);
__declspec(dllimport) DWORD __stdcall SetTextColor(HANDLE, DWORD);
__declspec(dllimport) int __stdcall SetBkMode(HANDLE, int);
}

static void *&gdiPointer(unsigned long address) { return *(void **)address; }
static unsigned &gdiWord(unsigned long address) { return *(unsigned *)address; }
static void gdiClear(void *memory, unsigned size)
{
    unsigned char *bytes = (unsigned char *)memory;
    for (unsigned i = 0; i != size; ++i) bytes[i] = 0;
}

static void gdiBitmapInfo(GexBitmapInfoHeader *info, unsigned bits,
                          unsigned red, unsigned green, unsigned blue)
{
    gdiClear(info, 0x28 + (bits == 8 ? 0x400 : 0x0c));
    info->size = 0x28;
    info->width = bits == 8 ? 2048 : 1024;
    info->height = -512;
    info->planes = 1;
    info->bits = bits;
    if (bits == 16) {
        info->compression = 3;
        unsigned *masks = (unsigned *)((unsigned char *)info + 0x28);
        masks[0] = red;
        masks[1] = green;
        masks[2] = blue;
    }
}

extern "C" void __cdecl GDI_Init_004066d0(void)
{
    HANDLE window = gdiPointer(0x004875a0);
    HANDLE destination = GetDC(window);
    gdiPointer(0x00487f7c) = destination;
    SetStretchBltMode(destination, 3);
    HANDLE mapping = CreateFileMappingA((HANDLE)-1, 0, 0x8000004, 0,
                                        0x100000, 0);
    gdiPointer(0x0045547c) = mapping;
    if (!mapping) return;

    GexBitmapInfoHeader *info = (GexBitmapInfoHeader *)0x004870e0;
    gdiBitmapInfo(info, 8, 0, 0, 0);
    GexPaletteEntry *palette = (GexPaletteEntry *)0x00455074;
    GexPaletteEntry *colors = (GexPaletteEntry *)((unsigned char *)info + 0x28);
    SetSystemPaletteUse(destination, 2);
    SetSystemPaletteUse(destination, 1);
    GetSystemPaletteEntries(destination, 0, 10, palette);
    GetSystemPaletteEntries(destination, 246, 10, palette + 246);
    for (unsigned edge = 0; edge != 10; ++edge) {
        palette[edge].flags = 0;
        colors[edge].red = palette[edge].blue;
        colors[edge].green = palette[edge].green;
        colors[edge].blue = palette[edge].red;
        colors[edge].flags = 0;
        palette[246 + edge].flags = 0;
        colors[246 + edge].red = palette[246 + edge].blue;
        colors[246 + edge].green = palette[246 + edge].green;
        colors[246 + edge].blue = palette[246 + edge].red;
        colors[246 + edge].flags = 0;
    }
    unsigned slot = 10;
    for (unsigned r = 0; r != 6; ++r) {
        for (unsigned g = 0; g != 9; ++g) {
            for (unsigned b = 0; b != 4; ++b, ++slot) {
                palette[slot].red = (unsigned char)(r * 51);
                palette[slot].green = (unsigned char)(g * 255 / 8);
                palette[slot].blue = (unsigned char)(b * 85);
                palette[slot].flags = 4;
                colors[slot].red = palette[slot].blue;
                colors[slot].green = palette[slot].green;
                colors[slot].blue = palette[slot].red;
                colors[slot].flags = 4;
            }
        }
    }
    for (; slot != 246; ++slot) {
        palette[slot].red = palette[slot].green = palette[slot].blue = 0;
        palette[slot].flags = 4;
        colors[slot].red = colors[slot].green = colors[slot].blue = 0;
        colors[slot].flags = 4;
    }

    unsigned char *lookup = (unsigned char *)0x0047f0d0;
    for (unsigned pixel = 0; pixel != 0x8000; ++pixel) {
        int red = ((int)(pixel & 0x1f) * 6 - 3) / 31;
        int green = ((int)((pixel & 0x3e0) >> 5) * 9 - 4) / 31;
        int blue = ((int)((pixel & 0x7c00) >> 8) - 2) / 31;
        if (red < 0) red = 0; else if (red > 31) red = 31;
        if (green < 0) green = 0; else if (green > 31) green = 31;
        if (blue < 0) blue = 0; else if (blue > 31) blue = 31;
        lookup[pixel] = (unsigned char)(blue + (red * 9 + green) * 4 + 10);
    }

    *(unsigned short *)0x00455070 = 0x300;
    *(unsigned short *)0x00455072 = 256;
    HANDLE paletteHandle = CreatePalette((void *)0x00455070);
    gdiPointer(0x00455474) = paletteHandle;
    gdiPointer(0x00455478) = SelectPalette(destination, paletteHandle, 0);
    RealizePalette(destination);

    HANDLE memoryDC = CreateCompatibleDC(destination);
    gdiPointer(0x0047f0c8) = memoryDC;
    void *bits = 0;
    gdiPointer(0x0047f0c4) = CreateDIBSection(memoryDC, info, 0, &bits, mapping, 0);
    gdiPointer(0x00487f70) = bits;
    gdiPointer(0x004a33ac) = bits;

    unsigned char font[60];
    gdiClear(font, sizeof(font));
    *(long *)font = 20;
    font[27] = 16;
    HANDLE fontHandle = CreateFontIndirectA(font);
    gdiPointer(0x00487ab8) = fontHandle;
    gdiPointer(0x00487a94) = SelectObject(memoryDC, fontHandle);
    SetTextColor(memoryDC, 0xff);
    SetBkMode(memoryDC, 1);

    gdiBitmapInfo(info, 16, 0x7c00, 0x03e0, 0x001f);
    gdiPointer(0x004870d4) = CreateDIBSection(memoryDC, info, 0, &bits, mapping, 0);
    gdiPointer(0x00487f70) = bits;
    gdiPointer(0x004a33ac) = bits;
    gdiBitmapInfo(info, 16, 0xf800, 0x07e0, 0x001f);
    gdiPointer(0x00487508) = CreateDIBSection(memoryDC, info, 0, &bits, mapping, 0);
    gdiPointer(0x00487f70) = bits;
    gdiPointer(0x004a33ac) = bits;
    unsigned mode = gdiWord(0x00454fc8);
    HANDLE selected = mode == 0x565 ? gdiPointer(0x00487508)
                    : mode == 0x555 ? gdiPointer(0x004870d4)
                                    : gdiPointer(0x0047f0c4);
    gdiPointer(0x004870d0) = SelectObject(memoryDC, selected);
}
