typedef void *HANDLE;
typedef void *HWND;
typedef void *HDC;
typedef void *HGDIOBJ;
typedef void *HKEY;
extern "C" {
extern HWND gMainWindow_004875a0;
extern int gGameThread_00487a00;
extern int gMusicThread_00487f8c;
extern unsigned int DAT_004626bc_timeSetEvent;
extern unsigned char DAT_00487aa0_lpCriticalSection[24];
extern HDC ghDC_0047f0c8;
extern HGDIOBJ HGDIOBJ_00487a94;
extern HGDIOBJ HGDIOBJ_004870d0;
extern HGDIOBJ ghDIBSection_0047f0c4;
extern HGDIOBJ HBITMAP_004870d4;
extern HGDIOBJ HBITMAP_00487508;
extern HANDLE ghDIBSectionFileMapping_0045547c;
extern HWND gDebugVRAMWindow_0048750c;
extern int DAT_004626c0;
extern HKEY phkResult_004626b8;
extern char s_Control_Panel_desktop_00455058[];
extern char s_ScreenSaveLowPowerActive_0045503c[];
extern char s_ScreenSavePowerOffActive_00455020[];
extern int lpData_00454fec;
extern int lpData_00454ff0;
extern int gScreenSaveActive_00454fe8;
void __cdecl SettingsSetFromRegistry_00408f40(void);
void __cdecl FUN_004013e0_ExitFullscreen_Clean1(int);
void __cdecl FUN_00404f90_KillThreads(void);
void __cdecl DDRAW_Destroy_004010e0(void);
void __cdecl SND_Destroy_00401f90(void);
void __cdecl VRAM_Hide_00405810(void);
void __cdecl exit_00449780(int);
__declspec(dllimport) int __stdcall WinHelpA(void *, const char *, unsigned int, unsigned long);
__declspec(dllimport) unsigned int __stdcall timeKillEvent(unsigned int);
__declspec(dllimport) unsigned int __stdcall timeEndPeriod(unsigned int);
__declspec(dllimport) void __stdcall DeleteCriticalSection(void *);
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) int __stdcall DeleteObject(HGDIOBJ);
__declspec(dllimport) int __stdcall DeleteDC(HDC);
__declspec(dllimport) int __stdcall CloseHandle(HANDLE);
__declspec(dllimport) int __stdcall DestroyWindow(HWND);
__declspec(dllimport) long __stdcall RegOpenKeyA(HKEY, const char *, HKEY *);
__declspec(dllimport) long __stdcall RegSetValueExA(HKEY, const char *, unsigned long, unsigned long, const unsigned char *, unsigned long);
__declspec(dllimport) long __stdcall RegFlushKey(HKEY);
__declspec(dllimport) long __stdcall RegCloseKey(HKEY);
__declspec(dllimport) int __stdcall SystemParametersInfoA(unsigned int, unsigned int, void *, unsigned int);

void __cdecl WND_CleanUp_004064d0(void)
{
    SettingsSetFromRegistry_00408f40();
    FUN_004013e0_ExitFullscreen_Clean1(0);
    if (gMainWindow_004875a0)
        WinHelpA(gMainWindow_004875a0, 0, 2, 0);
    if (gGameThread_00487a00 || gMusicThread_00487f8c)
        FUN_00404f90_KillThreads();
    DDRAW_Destroy_004010e0();
    SND_Destroy_00401f90();
    VRAM_Hide_00405810();
    if (DAT_004626bc_timeSetEvent) {
        timeKillEvent(DAT_004626bc_timeSetEvent);
        timeEndPeriod(0x11);
        DeleteCriticalSection(DAT_00487aa0_lpCriticalSection);
        DAT_004626bc_timeSetEvent = 0;
    }
    if (ghDC_0047f0c8) {
        DeleteObject(SelectObject(ghDC_0047f0c8, HGDIOBJ_00487a94));
        SelectObject(ghDC_0047f0c8, HGDIOBJ_004870d0);
        DeleteDC(ghDC_0047f0c8);
        ghDC_0047f0c8 = 0;
    }
    if (ghDIBSection_0047f0c4) {
        DeleteObject(ghDIBSection_0047f0c4);
        ghDIBSection_0047f0c4 = 0;
    }
    if (HBITMAP_004870d4) {
        DeleteObject(HBITMAP_004870d4);
        HBITMAP_004870d4 = 0;
    }
    if (HBITMAP_00487508) {
        DeleteObject(HBITMAP_00487508);
        HBITMAP_00487508 = 0;
    }
    if (ghDIBSectionFileMapping_0045547c) {
        CloseHandle(ghDIBSectionFileMapping_0045547c);
        ghDIBSectionFileMapping_0045547c = 0;
    }
    if (gMainWindow_004875a0) {
        DestroyWindow(gMainWindow_004875a0);
        gMainWindow_004875a0 = 0;
    }
    if (gDebugVRAMWindow_0048750c) {
        DestroyWindow(gDebugVRAMWindow_0048750c);
        gDebugVRAMWindow_0048750c = 0;
    }
    if (DAT_004626c0 && !RegOpenKeyA((HKEY)0x80000001, s_Control_Panel_desktop_00455058, &phkResult_004626b8)) {
        RegSetValueExA(phkResult_004626b8, s_ScreenSaveLowPowerActive_0045503c, 0, 1, (const unsigned char *)&lpData_00454fec, 2);
        RegSetValueExA(phkResult_004626b8, s_ScreenSavePowerOffActive_00455020, 0, 1, (const unsigned char *)&lpData_00454ff0, 2);
        RegFlushKey((HKEY)0x80000001);
        RegCloseKey(phkResult_004626b8);
    }
    SystemParametersInfoA(0x11, gScreenSaveActive_00454fe8, 0, 2);
    exit_00449780(0);
}
}
