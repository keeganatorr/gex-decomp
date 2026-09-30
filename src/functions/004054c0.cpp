typedef struct RECT {
    long left;
    long top;
    long right;
    long bottom;
} RECT;
typedef struct POINT {
    long x;
    long y;
} POINT;
typedef struct WINDOWPLACEMENT {
    unsigned int length;
    unsigned int flags;
    unsigned int showCmd;
    POINT ptMinPosition;
    POINT ptMaxPosition;
    RECT rcNormalPosition;
} WINDOWPLACEMENT;
extern "C" {
int __cdecl GEX_WidescreenConfiguredWidth(void);
extern int gFullscreen_0045103c;
extern void *gMainWindow_004875a0;
extern int DAT_00487768_ScreenWidth;
void __cdecl FUN_004013e0_ExitFullscreen_Clean1(int);
void *__cdecl memset(void *, int, unsigned int);
__declspec(dllimport) int __stdcall AdjustWindowRect(RECT *rect, unsigned long style, int menu);
__declspec(dllimport) int __stdcall GetWindowPlacement(void *hwnd, WINDOWPLACEMENT *wp);
__declspec(dllimport) int __stdcall SetWindowPlacement(void *hwnd, const WINDOWPLACEMENT *wp);
__declspec(dllimport) int __stdcall GetSystemMetrics(int index);
void __cdecl FUN_004054c0_SetWindowSize(int width, int height)
{
    RECT r;
    WINDOWPLACEMENT wp;
    int w;
    int h;

    if (gFullscreen_0045103c)
        FUN_004013e0_ExitFullscreen_Clean1(0);
    if (width > 0 && width % 320 == 0)
        width = GEX_WidescreenConfiguredWidth() * (width / 320);
    r.left = 0;
    r.top = 0;
    r.right = width;
    r.bottom = height;
    AdjustWindowRect(&r, 0xcf0000, 1);
    w = r.right - r.left;
    h = r.bottom - r.top;
    memset(&wp, 0, sizeof wp);
    wp.length = 0x2c;
    GetWindowPlacement(gMainWindow_004875a0, &wp);
    wp.rcNormalPosition.left = (GetSystemMetrics(0) - w) / 2;
    wp.rcNormalPosition.left = ((wp.rcNormalPosition.left + 2) & ~3) - DAT_00487768_ScreenWidth;
    wp.rcNormalPosition.top = (GetSystemMetrics(1) - h) / 2;
    wp.rcNormalPosition.right = w + wp.rcNormalPosition.left;
    wp.rcNormalPosition.bottom = h + wp.rcNormalPosition.top;
    wp.showCmd = 1;
    SetWindowPlacement(gMainWindow_004875a0, &wp);
}
}
