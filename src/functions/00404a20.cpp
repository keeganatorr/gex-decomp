extern "C" {
    typedef void* HWND;
    typedef int BOOL;
    extern HWND gVideoWindow_00451794;
    extern int gFullscreen_0045103c;
    extern int DAT_00451040_FreezeInput;
    void __cdecl FUN_00401340_CalculateWindowRect(void*);
    extern void (__stdcall *PTR_MoveWindow_004a55b0)(HWND, int, int, int, int, BOOL);
}

struct WinX_t {
    int X;
    int Y;
    int Width;
    int Height;
};

extern "C" void __cdecl FUN_00404a20_MoveWindow(void) {
    WinX_t WinX;
    if (gVideoWindow_00451794 != 0 && gFullscreen_0045103c == 0 && DAT_00451040_FreezeInput == 0) {
        FUN_00401340_CalculateWindowRect(&WinX);
        PTR_MoveWindow_004a55b0(gVideoWindow_00451794, WinX.X, WinX.Y, WinX.Width, WinX.Height, 0);
    }
}
