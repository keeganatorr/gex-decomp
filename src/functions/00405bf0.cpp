// Startup candidate from WinMain_00405bf0 in /EditedGex, cross-checked against
// the pinned PE's stdcall return. The Ghidra body contains one edited byte at
// 004060a1: the pinned PE skips VRAM_Show when 00487bc0 is zero. This is
// behavioral source, not a byte-match claim.
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef void *HANDLE;
typedef void *HWND;
typedef void *HINSTANCE;

struct GexWindowClass {
    UINT style;
    long (__stdcall *proc)(HWND, UINT, UINT, long);
    int classExtra;
    int windowExtra;
    HINSTANCE instance;
    HANDLE icon;
    HANDLE cursor;
    HANDLE background;
    const char *menu;
    const char *name;
};
struct GexMessage {
    HWND window;
    UINT message;
    UINT wParam;
    long lParam;
    DWORD time;
    long x;
    long y;
};
struct GexWindowPlacement {
    UINT length;
    UINT flags;
    UINT show;
    long minX, minY, maxX, maxY;
    long left, top, right, bottom;
};
struct GexJoyInfo { UINT x, y, z, buttons; };
struct GexJoyCaps { unsigned char bytes[0x194]; };

extern "C" {
__declspec(dllimport) DWORD __stdcall timeGetTime(void);
__declspec(dllimport) int __stdcall LoadStringA(HINSTANCE, UINT, char *, int);
__declspec(dllimport) DWORD __stdcall GetCurrentDirectoryA(DWORD, char *);
__declspec(dllimport) DWORD __stdcall GetVersion(void);
__declspec(dllimport) HWND __stdcall FindWindowA(const char *, const char *);
__declspec(dllimport) long __stdcall RegOpenKeyA(HANDLE, const char *, HANDLE *);
__declspec(dllimport) long __stdcall RegQueryValueExA(HANDLE, const char *, DWORD *, DWORD *, unsigned char *, DWORD *);
__declspec(dllimport) long __stdcall RegSetValueExA(HANDLE, const char *, DWORD, DWORD, const unsigned char *, DWORD);
__declspec(dllimport) long __stdcall RegFlushKey(HANDLE);
__declspec(dllimport) long __stdcall RegCloseKey(HANDLE);
__declspec(dllimport) int __stdcall SystemParametersInfoA(UINT, UINT, void *, UINT);
__declspec(dllimport) HANDLE __stdcall LoadCursorA(HINSTANCE, const char *);
__declspec(dllimport) HANDLE __stdcall LoadIconA(HINSTANCE, const char *);
__declspec(dllimport) HANDLE __stdcall GetStockObject(int);
__declspec(dllimport) unsigned short __stdcall RegisterClassA(const GexWindowClass *);
__declspec(dllimport) HWND __stdcall CreateWindowExA(DWORD, const char *, const char *, DWORD,
                                                       int, int, int, int, HWND, HANDLE, HINSTANCE, void *);
__declspec(dllimport) int __stdcall ShowWindow(HWND, int);
__declspec(dllimport) int __stdcall UpdateWindow(HWND);
__declspec(dllimport) HANDLE __stdcall GetMenu(HWND);
__declspec(dllimport) int __stdcall DeleteMenu(HANDLE, UINT, UINT);
__declspec(dllimport) void __stdcall InitializeCriticalSection(void *);
__declspec(dllimport) UINT __stdcall joyGetNumDevs(void);
__declspec(dllimport) UINT __stdcall joyGetDevCapsA(UINT, GexJoyCaps *, UINT);
__declspec(dllimport) UINT __stdcall joyGetPos(UINT, GexJoyInfo *);
__declspec(dllimport) UINT __stdcall timeBeginPeriod(UINT);
__declspec(dllimport) UINT __stdcall timeSetEvent(UINT, UINT,
    void (__stdcall *)(UINT, UINT, DWORD, DWORD, DWORD), DWORD, UINT);
__declspec(dllimport) HANDLE __stdcall CreateThread(void *, DWORD,
    DWORD (__stdcall *)(void *), void *, DWORD, DWORD *);
__declspec(dllimport) int __stdcall PostMessageA(HWND, UINT, UINT, long);
__declspec(dllimport) int __stdcall GetMessageA(GexMessage *, HWND, UINT, UINT);
__declspec(dllimport) int __stdcall TranslateMessage(const GexMessage *);
__declspec(dllimport) long __stdcall DispatchMessageA(const GexMessage *);
__declspec(dllimport) int __stdcall GetWindowPlacement(HWND, GexWindowPlacement *);
__declspec(dllimport) int __stdcall SetForegroundWindow(HWND);

void __cdecl SettingsGetFromRegistry_00408b60(void);
void __cdecl WND_CleanUp_004064d0(void);
void __cdecl WinShowError_004063d0(int, const char *, ...);
void __cdecl VRAM_Show_00405700(void);
int __cdecl DDRAW_Create_004010a0(void);
void __cdecl GDI_Init_004066d0(void);
void __cdecl SFX_Open_00401f20(void);
void __cdecl SettingsSetFromRegistry_00408f40(void);
void __cdecl STRING_Init_00404e40(void);
void __cdecl GameUnpause_004051d0(void);
void __cdecl FUN_004013e0_ExitFullscreen_Clean1(int);
DWORD __stdcall GameThread_004050e0(void *);
DWORD __stdcall SoundThread_00402c00(void *);
void __stdcall FUN_00404ab0_timeSetEvent(UINT, UINT, DWORD, DWORD, DWORD);
long __stdcall WndProc_00403960(HWND, UINT, UINT, long);
long __stdcall DebugVramWndProc_00404230(HWND, UINT, UINT, long);
void __cdecl GEX_WidescreenInit(void);
}

static unsigned &startupWord(unsigned long address) { return *(unsigned *)address; }
static void *&startupPointer(unsigned long address) { return *(void **)address; }
static char *startupText(unsigned long address) { return (char *)address; }

extern "C" int __stdcall WinMain_00405bf0(HINSTANCE instance, HINSTANCE,
                                             char *commandLine, int)
{
    startupPointer(0x00487f90) = instance;
    startupWord(0x00487f88) = 0;
    startupPointer(0x004870d0) = 0;
    startupWord(0x004626c0) = 0;
    startupPointer(0x0048750c) = 0;
    startupPointer(0x004875a0) = 0;
    startupPointer(0x00487a00) = 0;
    startupWord(0x004626bc) = 0;
    startupWord(0x00487ee4) = 0;
    startupWord(0x00487a98) = 0;
    startupWord(0x004879f4) = 0;
    startupWord(0x00487a90) = 0;
    startupWord(0x004875a4) = timeGetTime();
    startupWord(0x00487bc0) = 0;

    LoadStringA(instance, 1, startupText(0x00487c60), 128);
    LoadStringA(instance, 2, startupText(0x00487ce0), 128);
    char *directory = startupText(0x00487de0);
    GetCurrentDirectoryA(260, directory);
    unsigned length = 0;
    while (directory[length]) ++length;
    unsigned offset = length;
    if (length && directory[length - 1] != '\\') {
        directory[length++] = '\\';
        directory[length] = 0;
        offset = length;
    }
    LoadStringA(instance, 3, directory + offset, 260 - offset);
    LoadStringA(instance, 6, startupText(0x00487b40), 128);
    LoadStringA(instance, 12, startupText(0x00487ac0), 128);
    LoadStringA(instance, 17, startupText(0x00487ae0), 128);
    LoadStringA(instance, 19, startupText(0x00487d60), 128);
    LoadStringA(instance, 36, startupText(0x00487a10), 128);
    LoadStringA(instance, 38, startupText(0x00487970), 128);
    LoadStringA(instance, 39, startupText(0x004879b0), 128);
    LoadStringA(instance, 40, startupText(0x00487ef0), 128);
    LoadStringA(instance, 43, startupText(0x00487630), 256);
    LoadStringA(instance, 7, startupText(0x004875d0), 32);
    LoadStringA(instance, 8, startupText(0x004875b0), 32);
    LoadStringA(instance, 9, startupText(0x00487610), 32);
    LoadStringA(instance, 10, startupText(0x004875f0), 32);
    LoadStringA(instance, 11, startupText(0x00487730), 32);
    LoadStringA(instance, 13, startupText(0x00487fa0), 32);
    startupWord(0x00487c50) = (GetVersion() & 0x80000000UL) == 0;
    SettingsGetFromRegistry_00408b60();

    HWND existing = FindWindowA(startupText(0x00487ce0), startupText(0x00487c60));
    if (existing) {
        GexWindowPlacement placement;
        placement.length = sizeof(placement);
        GetWindowPlacement(existing, &placement);
        SetForegroundWindow(existing);
        if (placement.show == 2) ShowWindow(existing, 9);
        return 0;
    }

    GEX_WidescreenInit();

    // The replacement starts directly, without LOADER.EXE's password. Keep
    // the original J intro switch and skip the intro for a bare launch.
    // GameThread reads this word at 00405108.
    if (commandLine == 0 || commandLine[0] == 0 || commandLine[0] == 'J')
        startupWord(0x00487fc0) = 1;

    HANDLE desktop = 0;
    if (RegOpenKeyA((HANDLE)0x80000001UL, startupText(0x00455058), &desktop) == 0) {
        RegQueryValueExA(desktop, startupText(0x0045503c), 0, 0,
                         (unsigned char *)0x00454fec, (DWORD *)0x00454ffc);
        RegQueryValueExA(desktop, startupText(0x00455020), 0, 0,
                         (unsigned char *)0x00454ff0, (DWORD *)0x00454ffc);
        RegSetValueExA(desktop, startupText(0x0045503c), 0, 1,
                       (const unsigned char *)0x00454ff4, startupWord(0x00454ffc));
        RegSetValueExA(desktop, startupText(0x00455020), 0, 1,
                       (const unsigned char *)0x00454ff4, startupWord(0x00454ffc));
        RegFlushKey((HANDLE)0x80000001UL);
        RegCloseKey(desktop);
        startupWord(0x004626c0) = 1;
    }
    SystemParametersInfoA(0x10, 0, (void *)0x00454fe8, 0);
    SystemParametersInfoA(0x11, 0, 0, 2);

    GexWindowClass windowClass;
    windowClass.style = 0x1023;
    windowClass.classExtra = 0;
    windowClass.windowExtra = 0;
    windowClass.instance = instance;
    windowClass.icon = LoadIconA(instance, (const char *)0x6c);
    windowClass.cursor = LoadCursorA(0, (const char *)0x7f00);
    windowClass.background = GetStockObject(4);
    windowClass.menu = 0;
    windowClass.name = startupText(0x00454f9c);
    windowClass.proc = DebugVramWndProc_00404230;
    if (!RegisterClassA(&windowClass)) WND_CleanUp_004064d0();
    windowClass.menu = (const char *)0x65;
    windowClass.name = startupText(0x00487ce0);
    windowClass.proc = WndProc_00403960;
    if (!RegisterClassA(&windowClass)) WND_CleanUp_004064d0();
    if (startupWord(0x00487bc0) != 0) VRAM_Show_00405700();

    HWND window = CreateWindowExA(0, startupText(0x00487ce0), startupText(0x00487c60),
        0xcf0000, startupWord(0x00487f80), startupWord(0x00487f84),
        startupWord(0x00487a04), startupWord(0x00487a08), 0, 0, instance, 0);
    startupPointer(0x004875a0) = window;
    ShowWindow(window, 10);
    UpdateWindow(window);
    HANDLE menu = GetMenu(window);
    startupPointer(0x00487f78) = menu;
    if (!DDRAW_Create_004010a0()) {
        WinShowError_004063d0(2, startupText(0x00487ae0));
        WND_CleanUp_004064d0();
    }
    GDI_Init_004066d0();
    startupWord(0x00487a90) = 0;
    startupWord(0x004875a4) = timeGetTime();
    startupWord(0x00487ee4) = 1;
    const UINT deletedMenus[] = {0x9c4e, 0x9c4b, 0x9c45, 0x9c43, 0x9c47};
    for (unsigned menuIndex = 0; menuIndex != 5; ++menuIndex)
        DeleteMenu(menu, deletedMenus[menuIndex], 0);
    startupWord(0x00487ee4) = 0;
    SFX_Open_00401f20();
    InitializeCriticalSection((void *)0x00487aa0);

    startupWord(0x00454fc4) = 0;
    GexJoyCaps caps;
    GexJoyInfo info;
    if (joyGetNumDevs() && joyGetDevCapsA(0, &caps, sizeof(caps)) == 0 &&
        joyGetPos(0, &info) == 0) {
        const UINT *axis = (const UINT *)(caps.bytes + 36);
        startupWord(0x00454fc4) = 1;
        startupWord(0x00487bc4) = (axis[1] - axis[0]) >> 1;
        startupWord(0x00487c58) = (axis[1] - axis[0]) / 5;
        startupWord(0x00487bc8) = (axis[3] - axis[2]) >> 1;
        startupWord(0x00487c54) = (axis[3] - axis[0]) / 5;
    }
    if (!startupWord(0x00454fc4)) startupPointer(0x00455018) = (void *)-1;
    else if (startupWord(0x0045633c)) startupPointer(0x00455018) = 0;
    SettingsSetFromRegistry_00408f40();
    STRING_Init_00404e40();
    if (timeBeginPeriod(0x11) != 0 ||
        (startupWord(0x004626bc) = timeSetEvent(0x11, 0x11,
            FUN_00404ab0_timeSetEvent, 0, 1)) == 0) {
        WinShowError_004063d0(2, startupText(0x00487b40));
        WND_CleanUp_004064d0();
    }
    startupPointer(0x00487a00) = CreateThread(0, 0, GameThread_004050e0, 0, 0,
                                              (DWORD *)0x0048776c);
    startupPointer(0x00487f8c) = CreateThread(0, 0, SoundThread_00402c00, 0, 0,
                                              (DWORD *)0x004879f0);
    PostMessageA(window, 0x658, 0, 0);
    if (startupPointer(0x0045501c)) PostMessageA(window, 0x65a, 0, 0);
    startupWord(0x00487f88) = 1;
    GexMessage message;
    while (GetMessageA(&message, 0, 0, 0) != 0) {
        TranslateMessage(&message);
        if ((message.message == 0x104 || message.message == 0x105) &&
            startupWord(0x00451040)) continue;
        if (message.message == 0x104 && startupWord(0x0045103c) == 2) {
            GameUnpause_004051d0();
            FUN_004013e0_ExitFullscreen_Clean1(1);
        }
        DispatchMessageA(&message);
    }
    WND_CleanUp_004064d0();
    return 0;
}
