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
extern "C" {
__declspec(dllimport) long __stdcall CallWindowProcA(long prev, void *hwnd, unsigned int msg, unsigned int wParam, long lParam);
__declspec(dllimport) void *__stdcall BeginPaint(void *hwnd, PAINTSTRUCT *ps);
__declspec(dllimport) int __stdcall EndPaint(void *hwnd, const PAINTSTRUCT *ps);
__declspec(dllimport) int __stdcall SetMapMode(void *dc, int mode);
__declspec(dllimport) int __stdcall GetClientRect(void *hwnd, RECT *rc);
__declspec(dllimport) unsigned long __stdcall GetSysColor(int index);
__declspec(dllimport) void *__stdcall CreatePen(int style, int width, unsigned long color);
__declspec(dllimport) void *__stdcall SelectObject(void *dc, void *object);
__declspec(dllimport) int __stdcall DeleteObject(void *object);
__declspec(dllimport) int __stdcall MoveToEx(void *dc, int x, int y, void *point);
__declspec(dllimport) int __stdcall LineTo(void *dc, int x, int y);
extern long DAT_004626d0;
long __stdcall GEX_Target(void *hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    PAINTSTRUCT ps;
    RECT rc;
    void *dc;
    void *light;
    void *dark;
    void *oldPen;
    int oldMode;

    switch (msg) {
    case 0xf:
        dc = BeginPaint(hwnd, &ps);
        oldMode = SetMapMode(dc, 1);
        GetClientRect(hwnd, &rc);
        light = CreatePen(0, 1, GetSysColor(0x14));
        dark = CreatePen(0, 1, GetSysColor(0x10));
        oldPen = SelectObject(dc, dark);
        MoveToEx(dc, rc.right, 0, 0);
        LineTo(dc, rc.right, rc.bottom);
        SelectObject(dc, light);
        LineTo(dc, 0, 0);
        LineTo(dc, rc.right, 0);
        SelectObject(dc, oldPen);
        DeleteObject(light);
        DeleteObject(dark);
        SetMapMode(dc, oldMode);
        EndPaint(hwnd, &ps);
        return 0;
    case 0x14:
        return 0;
    }
    return CallWindowProcA(DAT_004626d0, hwnd, msg, wParam, lParam);
}
}
