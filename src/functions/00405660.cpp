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
extern "C" {
__declspec(dllimport) HANDLE __stdcall LoadResource(HANDLE module, HANDLE resource);
__declspec(dllimport) void *__stdcall LockResource(HANDLE data);
__declspec(dllimport) int __stdcall FreeResource(HANDLE data);
__declspec(dllimport) HANDLE __stdcall GetDC(HANDLE window);
__declspec(dllimport) HANDLE __stdcall FindResourceA(HANDLE module, const char *name, const char *type);
__declspec(dllimport) int __stdcall ReleaseDC(HANDLE window, HANDLE dc);
__declspec(dllimport) HANDLE __stdcall SelectPalette(HANDLE dc, HANDLE palette, int background);
__declspec(dllimport) unsigned int __stdcall RealizePalette(HANDLE dc);
__declspec(dllimport) HANDLE __stdcall CreateDIBitmap(HANDLE dc, BITMAPINFOHEADER *header, unsigned long init,
    const void *bits, BITMAPINFOHEADER *info, unsigned int usage);
HANDLE __cdecl FUN_004055b0_GFXUnk(BITMAPINFOHEADER *info, int *colors);
HANDLE __cdecl FUN_00405660_GFXUnk(HANDLE module, const char *name, HANDLE *palette)
{
    HANDLE bitmap;
    HANDLE resource;
    HANDLE data;
    BITMAPINFOHEADER *info;
    HANDLE dc;
    int colors;
    bitmap = 0;
    resource = FindResourceA(module, name, (const char *)2);
    if (resource) {
        data = LoadResource(module, resource);
        info = (BITMAPINFOHEADER *)LockResource(data);
        dc = GetDC(0);
        if ((*palette = FUN_004055b0_GFXUnk(info, &colors)) != 0) {
            SelectPalette(dc, *palette, 0);
            RealizePalette(dc);
        }
        bitmap = CreateDIBitmap(dc, info, 4, (char *)info + info->biSize + colors * 4, info, 0);
        ReleaseDC(0, dc);
        FreeResource(data);
    }
    return bitmap;
}
}
