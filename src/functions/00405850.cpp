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
__declspec(dllimport) long __stdcall CallWindowProcA(long prev, void *hwnd, unsigned int msg, unsigned int wParam, long lParam);
__declspec(dllimport) int __stdcall InvalidateRect(void *hwnd, const RECT *rc, int erase);
__declspec(dllimport) void *__stdcall BeginPaint(void *hwnd, PAINTSTRUCT *ps);
__declspec(dllimport) int __stdcall EndPaint(void *hwnd, const PAINTSTRUCT *ps);
__declspec(dllimport) int __stdcall GetObjectA(void *object, int size, void *buffer);
__declspec(dllimport) int __stdcall SetMapMode(void *dc, int mode);
__declspec(dllimport) void *__stdcall CreateCompatibleDC(void *dc);
__declspec(dllimport) void *__stdcall CreateCompatibleBitmap(void *dc, int w, int h);
__declspec(dllimport) void *__stdcall CreateBitmap(int w, int h, unsigned int planes, unsigned int bits, const void *data);
__declspec(dllimport) void *__stdcall SelectObject(void *dc, void *object);
__declspec(dllimport) unsigned long __stdcall GetPixel(void *dc, int x, int y);
__declspec(dllimport) unsigned long __stdcall SetBkColor(void *dc, unsigned long color);
__declspec(dllimport) int __stdcall BitBlt(void *dst, int x, int y, int w, int h, void *src, int sx, int sy, unsigned long rop);
__declspec(dllimport) void *__stdcall SelectPalette(void *dc, void *palette, int background);
__declspec(dllimport) unsigned int __stdcall RealizePalette(void *dc);
__declspec(dllimport) int __stdcall DeleteObject(void *object);
__declspec(dllimport) int __stdcall DeleteDC(void *dc);
extern void *DAT_00487fc4;
extern void *DAT_00487fcc;
extern long DAT_00487fc8;
long __stdcall FUN_00405850(void *hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    PAINTSTRUCT ps;
    BITMAP bm;
    void *dc;
    void *src;
    void *oldSrc;
    void *back;
    void *image;
    void *mask;
    void *invMask;
    void *backBitmap;
    void *imageBitmap;
    void *maskBitmap;
    void *invMaskBitmap;
    void *oldBack;
    void *oldImage;
    void *oldMask;
    void *oldInvMask;
    int oldMode;
    int w;
    int h;

    switch (msg) {
    case 6:
        InvalidateRect(hwnd, 0, 0);
        return 0;
    case 0xf:
        dc = BeginPaint(hwnd, &ps);
        if (GetObjectA(DAT_00487fc4, 0x18, &bm)) {
            oldMode = SetMapMode(dc, 1);
            src = CreateCompatibleDC(dc);
            oldSrc = SelectObject(src, DAT_00487fc4);
            w = bm.bmWidth;
            h = bm.bmHeight;
            back = CreateCompatibleDC(dc);
            backBitmap = CreateCompatibleBitmap(dc, w, h);
            oldBack = SelectObject(back, backBitmap);
            image = CreateCompatibleDC(dc);
            imageBitmap = CreateCompatibleBitmap(dc, w, h);
            oldImage = SelectObject(image, imageBitmap);
            mask = CreateCompatibleDC(dc);
            maskBitmap = CreateBitmap(w, h, 1, 1, 0);
            oldMask = SelectObject(mask, maskBitmap);
            invMask = CreateCompatibleDC(dc);
            invMaskBitmap = CreateBitmap(w, h, 1, 1, 0);
            oldInvMask = SelectObject(invMask, invMaskBitmap);
            SetBkColor(src, GetPixel(src, 0, 0));
            BitBlt(back, 0, 0, w, h, dc, 0, 0, 0xcc0020);
            BitBlt(image, 0, 0, w, h, src, 0, 0, 0xcc0020);
            BitBlt(mask, 0, 0, w, h, src, 0, 0, 0xcc0020);
            BitBlt(invMask, 0, 0, w, h, src, 0, 0, 0x330008);
            BitBlt(back, 0, 0, w, h, mask, 0, 0, 0x8800c6);
            BitBlt(image, 0, 0, w, h, invMask, 0, 0, 0x8800c6);
            BitBlt(back, 0, 0, w, h, image, 0, 0, 0xee0086);
            SelectPalette(dc, DAT_00487fcc, 1);
            RealizePalette(dc);
            BitBlt(dc, 0, 0, w, h, back, 0, 0, 0xcc0020);
            SelectObject(src, oldSrc);
            SelectObject(back, oldBack);
            SelectObject(image, oldImage);
            SelectObject(mask, oldMask);
            SelectObject(invMask, oldInvMask);
            DeleteObject(maskBitmap);
            DeleteObject(invMaskBitmap);
            DeleteObject(backBitmap);
            DeleteObject(imageBitmap);
            DeleteDC(src);
            DeleteDC(mask);
            DeleteDC(invMask);
            DeleteDC(back);
            DeleteDC(image);
            SetMapMode(dc, oldMode);
        }
        EndPaint(hwnd, &ps);
        return 0;
    case 0x14:
        InvalidateRect(hwnd, 0, 0);
        return 0;
    case 0x311:
        if ((void *)wParam == hwnd)
            return 0;
    case 0x30f:
        InvalidateRect(hwnd, 0, 0);
        return 1;
    }
    return CallWindowProcA(DAT_00487fc8, hwnd, msg, wParam, lParam);
}
}
