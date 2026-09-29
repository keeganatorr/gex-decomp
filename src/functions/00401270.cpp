typedef unsigned int UINT;
typedef long LONG;
typedef int BOOL;
typedef void* HWND;
typedef void* HMENU;

struct POINT { long x; long y; };
struct RECT { long left; long top; long right; long bottom; };

struct WINDOWPLACEMENT {
    UINT length;
    UINT flags;
    UINT showCmd;
    POINT ptMinPosition;
    POINT ptMaxPosition;
    RECT rcNormalPosition;
};

extern "C" {
    __declspec(dllimport) BOOL __stdcall GetWindowPlacement(HWND, WINDOWPLACEMENT*);
    __declspec(dllimport) LONG __stdcall GetWindowLongA(HWND, int);
    __declspec(dllimport) LONG __stdcall SetWindowLongA(HWND, int, LONG);
    __declspec(dllimport) BOOL __stdcall SetMenu(HWND, HMENU);
    __declspec(dllimport) BOOL __stdcall SetWindowPlacement(HWND, const WINDOWPLACEMENT*);

    extern HWND gMainWindow_004875a0;
    extern HMENU gMenu_00487f78;
    extern WINDOWPLACEMENT WINDOWPLACEMENT_0049fb60;
    int __cdecl DDRAW_SetResolution_00401100(int, int);
}

extern "C" int __cdecl FUN_00401270_ChangeVideoMode(int WidthAndHeight, int param_2, int param_3)
{
    UINT uVar1;
    int iVar2;

    WINDOWPLACEMENT_0049fb60.length = 0x2c;
    GetWindowPlacement(gMainWindow_004875a0, &WINDOWPLACEMENT_0049fb60);
    uVar1 = GetWindowLongA(gMainWindow_004875a0, -0x10);
    SetWindowLongA(gMainWindow_004875a0, -0x10, uVar1 & 0xff30ffff);
    if (param_2 != 0) {
        SetMenu(gMainWindow_004875a0, 0);
    }
    iVar2 = DDRAW_SetResolution_00401100(WidthAndHeight, param_3);
    if (iVar2 != 0) {
        return 1;
    }
    uVar1 = GetWindowLongA(gMainWindow_004875a0, -0x10);
    SetWindowLongA(gMainWindow_004875a0, -0x10, uVar1 | 0xcf0000);
    SetMenu(gMainWindow_004875a0, gMenu_00487f78);
    SetWindowPlacement(gMainWindow_004875a0, &WINDOWPLACEMENT_0049fb60);
    return 0;
}
