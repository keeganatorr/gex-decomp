typedef void *HANDLE;
typedef HANDLE HWND;
typedef HANDLE HDC;
typedef HANDLE HMENU;
typedef HANDLE HINSTANCE;
typedef unsigned long DWORD;
typedef int BOOL;

struct WindowRect {
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" {
__declspec(dllimport) BOOL __stdcall AdjustWindowRect(WindowRect *, DWORD, BOOL);
__declspec(dllimport) int __stdcall GetSystemMetrics(int);
__declspec(dllimport) HWND __stdcall CreateWindowExA(DWORD, const char *, const char *, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, void *);
__declspec(dllimport) BOOL __stdcall ShowWindow(HWND, int);
__declspec(dllimport) BOOL __stdcall UpdateWindow(HWND);
__declspec(dllimport) HDC __stdcall GetDC(HWND);
__declspec(dllimport) int __stdcall SetStretchBltMode(HDC, int);
__declspec(dllimport) DWORD __stdcall CheckMenuItem(HMENU, unsigned int, unsigned int);

extern int DAT_00487768_ScreenWidth;
extern HINSTANCE DAT_00487F90;
extern int gIsShowingVRAM_00487bc0;
extern char s_Debug_Vram_00454f9c[];
extern HWND gDebugVRAMWindow_0048750c;
extern HDC gVRAMHDC_00487510;
extern HMENU gMenu_00487f78;

void VRAM_Show_00405700(void)
{
    int screenWidth;
    WindowRect windowRect = { 0, 0, 0x400, 0x200 };

    AdjustWindowRect(&windowRect, 0xcf0000, 0);

    screenWidth = GetSystemMetrics(0);
    if (screenWidth > 0x400) {
        screenWidth = (GetSystemMetrics(0) - 0x400) / 2;
    } else {
        screenWidth = -DAT_00487768_ScreenWidth;
    }

    gDebugVRAMWindow_0048750c = CreateWindowExA(
        0,
        s_Debug_Vram_00454f9c,
        s_Debug_Vram_00454f9c,
        gIsShowingVRAM_00487bc0 == 0 ? 0xf0cf0000UL : 0x00cf0000UL,
        screenWidth,
        0x180,
        windowRect.right - windowRect.left,
        windowRect.bottom - windowRect.top,
        0,
        0,
        DAT_00487F90,
        0);

    ShowWindow(gDebugVRAMWindow_0048750c, 10);
    UpdateWindow(gDebugVRAMWindow_0048750c);
    gVRAMHDC_00487510 = GetDC(gDebugVRAMWindow_0048750c);
    SetStretchBltMode(gVRAMHDC_00487510, 3);
    gIsShowingVRAM_00487bc0 = 1;
    CheckMenuItem(gMenu_00487f78, 0x9c43, 8);
}
}