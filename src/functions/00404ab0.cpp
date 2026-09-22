struct JOYINFOEX {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwXpos;
    unsigned long dwYpos;
    unsigned long dwZpos;
    unsigned long dwRpos;
    unsigned long dwUpos;
    unsigned long dwVpos;
    unsigned long dwButtons;
    unsigned long dwButtonNumber;
    unsigned long dwPOV;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
};

extern "C" {
    void* __cdecl memset(void*, int, unsigned int);
    __declspec(dllimport) int __cdecl wsprintfA(char*, const char*, ...);
    __declspec(dllimport) unsigned int __stdcall joyGetPosEx(unsigned int, JOYINFOEX*);
    __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, long);

    extern int DAT_004517e0_timeSetEventUnk1;
    extern int DAT_004517e4_timeSetEventUnk2;
    extern int DAT_00487ee4_ShowFPS;
    extern int DAT_00487a90_FPS;
    extern char DAT_00454f50_FPSBufferFormat[];
    extern char lpString_00454fa8[];
    extern int DAT_00454fb4_FPSBufferLength;
    extern void* DAT_00488004_HWND_Unk;
    extern unsigned int DAT_0047f050_timeSetEventUnk2;
    extern int DAT_004626b4_timeSetEventUnk3;
    extern int gVideoWindow_00451794;

    int __cdecl FUN_00406fd0_timeSetEventInner(unsigned long);
    void __cdecl FUN_00404460_timeSetEventInner(void);
}

extern "C" void __cdecl GEX_Target(unsigned int, unsigned int, unsigned long, unsigned long, unsigned long)
{
    JOYINFOEX joy;
    ++DAT_004517e4_timeSetEventUnk2;
    int ticks = ++DAT_004517e0_timeSetEventUnk1;

    if (DAT_00487ee4_ShowFPS && ticks >= 60) {
        DAT_00454fb4_FPSBufferLength = wsprintfA(lpString_00454fa8, DAT_00454f50_FPSBufferFormat, DAT_00487a90_FPS);
        DAT_00487a90_FPS = 0;
        DAT_004517e0_timeSetEventUnk1 = 0;
    }

    if (DAT_00488004_HWND_Unk &&
        DAT_0047f050_timeSetEventUnk2 != (unsigned int)-1 &&
        ++DAT_004626b4_timeSetEventUnk3 >= 10) {
        DAT_004626b4_timeSetEventUnk3 = 0;
        memset(&joy, 0, sizeof(joy));
        joy.dwSize = sizeof(joy);
        joy.dwFlags = 0x80;
        joyGetPosEx(DAT_0047f050_timeSetEventUnk2, &joy);
        if (joy.dwButtons) {
            PostMessageA(DAT_00488004_HWND_Unk, 0x590,
                         FUN_00406fd0_timeSetEventInner(joy.dwButtons) + 1, 0);
        }
    }

    if (gVideoWindow_00451794)
        FUN_00404460_timeSetEventInner();
}
