typedef struct RECT {
    long left, top, right, bottom;
} RECT;
typedef struct PAINTSTRUCT {
    void *hdc;
    int fErase;
    RECT rcPaint;
    int fRestore;
    int fIncUpdate;
    unsigned char rgbReserved[32];
} PAINTSTRUCT;
typedef struct BITMAP {
    long bmType;
    long bmWidth;
    long bmHeight;
    long bmWidthBytes;
    unsigned short bmPlanes;
    unsigned short bmBitsPixel;
    void *bmBits;
} BITMAP;
extern "C" {
__declspec(dllimport) int __stdcall DeleteObject(void *object);
__declspec(dllimport) int __stdcall InvalidateRect(void *hwnd, const RECT *rc, int erase);
__declspec(dllimport) int __stdcall GetObjectA(void *object, int size, void *buffer);
__declspec(dllimport) int __stdcall GetClientRect(void *hwnd, RECT *rc);
__declspec(dllimport) void *__stdcall BeginPaint(void *hwnd, PAINTSTRUCT *ps);
__declspec(dllimport) int __stdcall EndPaint(void *hwnd, const PAINTSTRUCT *ps);
__declspec(dllimport) int __stdcall SetMapMode(void *dc, int mode);
__declspec(dllimport) void *__stdcall SelectPalette(void *dc, void *palette, int background);
__declspec(dllimport) unsigned int __stdcall RealizePalette(void *dc);
__declspec(dllimport) void *__stdcall CreateCompatibleDC(void *dc);
__declspec(dllimport) void *__stdcall SelectObject(void *dc, void *object);
__declspec(dllimport) int __stdcall StretchBlt(void *dst, int x, int y, int w, int h, void *src, int sx, int sy, int sw, int sh, unsigned long rop);
__declspec(dllimport) int __stdcall DeleteDC(void *dc);
__declspec(dllimport) int __stdcall EndDialog(void *hwnd, int result);
extern void *DAT_00487fc4;
extern void *DAT_00487fcc;
extern void *ghInstance_00487f90;
void *__cdecl FUN_00405660_GFXUnk(void *instance, int resource, void **palette);
int __stdcall FUN_004036f0(void *hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    RECT rc;
    BITMAP bm;
    PAINTSTRUCT ps;
    void *dc;
    void *memdc;
    void *oldBitmap;
    void *oldPalette;
    int oldMode;

    switch (msg) {
    case 2:
        if (DAT_00487fc4) {
            DeleteObject(DAT_00487fc4);
            DAT_00487fc4 = 0;
        }
        if (DAT_00487fcc) {
            DeleteObject(DAT_00487fcc);
            DAT_00487fcc = 0;
        }
        break;
    case 6:
        InvalidateRect(hwnd, 0, 0);
        return 0;
    case 0xf:
        GetObjectA(DAT_00487fc4, 0x18, &bm);
        GetClientRect(hwnd, &rc);
        dc = BeginPaint(hwnd, &ps);
        oldMode = SetMapMode(dc, 1);
        oldPalette = SelectPalette(dc, DAT_00487fcc, 0);
        RealizePalette(dc);
        memdc = CreateCompatibleDC(dc);
        oldBitmap = SelectObject(memdc, DAT_00487fc4);
        StretchBlt(dc, 0, 0, rc.right, rc.bottom, memdc, 0, 0, bm.bmWidth, bm.bmHeight, 0xcc0020);
        SelectObject(memdc, oldBitmap);
        SelectObject(dc, oldPalette);
        DeleteDC(memdc);
        SetMapMode(dc, oldMode);
        EndPaint(hwnd, &ps);
        return 0;
    case 0x14:
        InvalidateRect(hwnd, 0, 0);
        return 1;
    case 0x110:
        DAT_00487fc4 = FUN_00405660_GFXUnk(ghInstance_00487f90, 0x7d, &DAT_00487fcc);
        return 1;
    case 0x111:
        if ((unsigned short)wParam == 1 || (unsigned short)wParam == 2)
            EndDialog(hwnd, 0);
        return 1;
    case 0x311:
        if ((void *)wParam == hwnd)
            return 0;
    case 0x30f:
        InvalidateRect(hwnd, 0, 0);
        return 1;
    }
    return 0;
}
}
