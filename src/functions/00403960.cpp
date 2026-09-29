// Window message handling from /EditedGex, with the F4 branch recovered from
// original PE bytes at 00403d91-00403e3d (Ghidra has an edited byte there).
// This is a behavior candidate, not a current byte-match proof.
typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef void *HWND;
typedef void *HANDLE;

struct GexPaint { unsigned char bytes[64]; };

extern "C" {
__declspec(dllimport) int __stdcall WinHelpA(HWND, const char *, UINT, DWORD);
__declspec(dllimport) void __stdcall PostQuitMessage(int);
__declspec(dllimport) HANDLE __stdcall BeginPaint(HWND, GexPaint *);
__declspec(dllimport) int __stdcall EndPaint(HWND, const GexPaint *);
__declspec(dllimport) int __stdcall InvalidateRect(HWND, const void *, int);
__declspec(dllimport) HWND __stdcall GetActiveWindow(void);
__declspec(dllimport) HANDLE __stdcall SetCursor(HANDLE);
__declspec(dllimport) int __stdcall DestroyWindow(HWND);
__declspec(dllimport) int __stdcall PostMessageA(HWND, UINT, UINT, long);
__declspec(dllimport) long __stdcall DefWindowProcA(HWND, UINT, UINT, long);
__declspec(dllimport) UINT __stdcall EnableMenuItem(HANDLE, UINT, UINT);
__declspec(dllimport) DWORD __stdcall CheckMenuItem(HANDLE, UINT, UINT);
__declspec(dllimport) HANDLE __stdcall SelectPalette(HANDLE, HANDLE, int);
__declspec(dllimport) UINT __stdcall RealizePalette(HANDLE);

void __cdecl FUN_00404a20_MoveWindow(void);
void __cdecl FUN_00404f90_KillThreads(void);
void __cdecl SettingsSetFromRegistry_00408f40(void);
void __cdecl GFX_Flush_00406c30(void);
unsigned __cdecl FUN_004052d0_ExitGexPopup(void);
void __cdecl GameUnpause_004051d0(void);
void __cdecl GamePause_00405240(void);
void __cdecl FUN_004013e0_ExitFullscreen_Clean1(int);
void __cdecl FUN_00402140_Sound(int);
unsigned __cdecl FUN_00405310_Fullscreen_Unk(void);
void __cdecl FUN_004054c0_SetWindowSize(int, int);
void __cdecl FUN_00404710_Window(void);
void __cdecl FUN_004044b0_MoveWindow(char *, long *);
int __cdecl FUN_004032a0_WM_COMMAND(HWND, UINT, UINT);
void __cdecl FUN_004097f0_ProcessCheatInputs(char);
int __cdecl FUN_00403030_Registry(int);
void __cdecl FUN_00404a80_StopMCIMedia(void);
}

static unsigned &windowWord(unsigned long address) { return *(unsigned *)address; }
static void *&windowPointer(unsigned long address) { return *(void **)address; }
static char *windowText(unsigned long address) { return (char *)address; }

static long windowPaletteChanged(HWND window)
{
    HANDLE dc = windowPointer(0x00487f7c);
    HANDLE palette = windowPointer(0x00455474);
    unsigned mode = windowWord(0x00454fc8);
    if (!dc || !palette || mode == 0x555 || mode == 0x565) return 0;
    if (!windowPointer(0x00451794)) {
        SelectPalette(dc, palette, 0);
        RealizePalette(dc);
        if (!windowWord(0x00487f88)) {
            InvalidateRect(window, 0, 1);
            return 1;
        }
    } else {
        FUN_00404a80_StopMCIMedia();
    }
    return 1;
}

extern "C" long __stdcall WndProc_00403960(HWND window, UINT message,
                                             UINT wParam, long lParam)
{
    HWND mainWindow = windowPointer(0x004875a0);
    char input = (char)wParam;
    switch (message) {
    case 0x0005: // WM_SIZE
        windowWord(0x00487a04) = (unsigned)lParam & 0xffff;
        windowWord(0x00487a08) = (unsigned)lParam >> 16;
        FUN_00404a20_MoveWindow();
        break;
    case 0x0002: // WM_DESTROY
        WinHelpA(mainWindow, windowText(0x00487de0), 2, 0);
        FUN_00404f90_KillThreads();
        SettingsSetFromRegistry_00408f40();
        PostQuitMessage(0);
        windowPointer(0x004875a0) = 0;
        return 0;
    case 0x000f: { // WM_PAINT
        GexPaint paint;
        BeginPaint(window, &paint);
        if (windowPointer(0x00487f7c) && windowPointer(0x0047f0c8) &&
            !windowWord(0x00451040) && !windowPointer(0x00451794) &&
            !windowWord(0x00487f88)) GFX_Flush_00406c30();
        EndPaint(window, &paint);
        if (!windowWord(0x00487f88) && !windowWord(0x00451040) &&
            windowPointer(0x00451794))
            InvalidateRect(windowPointer(0x00451794), 0, 0);
        return 1;
    }
    case 0x0007: // WM_SETFOCUS
        if (window == mainWindow) windowWord(0x00454fc0) = 1;
        break;
    case 0x0008: // WM_KILLFOCUS
        if (mainWindow != (HWND)wParam) windowWord(0x00454fc0) = 0;
        break;
    case 0x0014: // WM_ERASEBKGND
        if (windowPointer(0x00487a00) && GetActiveWindow() == window) return 1;
        break;
    case 0x0010: // WM_CLOSE
        if (!FUN_004052d0_ExitGexPopup()) return 0;
        windowPointer(0x0045501c) = (void *)(windowWord(0x0045103c) != 0);
        FUN_004013e0_ExitFullscreen_Clean1(0);
        DestroyWindow(window);
        break;
    case 0x001c: // WM_ACTIVATEAPP
        if (!wParam) GameUnpause_004051d0();
        if (wParam != windowWord(0x00454fbc)) FUN_00402140_Sound(wParam);
        windowWord(0x00454fbc) = wParam;
        break;
    case 0x0020: // WM_SETCURSOR
        if (windowWord(0x0045103c) == 2) {
            SetCursor(0);
            return 1;
        }
        break;
    case 0x0100: // WM_KEYDOWN
        if (wParam == 0x70) { // F1
            GameUnpause_004051d0();
            WinHelpA(mainWindow, windowText(0x00487de0), 3, 100);
            return 0;
        }
        if (wParam == 0x71) { // F2
            if (!windowWord(0x004a2958) && windowWord(0x004a2a98) != 0x3f &&
                !windowWord(0x00456018)) {
                if (windowWord(0x004a2a0c)) {
                    windowWord(0x004a2a8c) = 1;
                    GamePause_00405240();
                    return 0;
                }
                if (windowPointer(0x00451794)) {
                    windowWord(0x004a2a8c) = 1;
                    GamePause_00405240();
                    FUN_00404710_Window();
                    return 0;
                }
                GameUnpause_004051d0();
                if (FUN_00405310_Fullscreen_Unk()) {
                    windowWord(0x004a2a8c) = 1;
                    GamePause_00405240();
                }
            }
            return 0;
        }
        if (input == 0x13 || input == 0x72) { // Pause or F3
            if (windowWord(0x00487f88)) GameUnpause_004051d0();
            else GamePause_00405240();
            return 0;
        }
        if (wParam == 0x73) { // F4: original bytes, absent from edited decompile
            unsigned fullscreen = windowWord(0x0045103c);
            unsigned paused = windowWord(0x00487f88);
            if (fullscreen == 2) FUN_004013e0_ExitFullscreen_Clean1(0);
            else if (fullscreen == 1) FUN_004013e0_ExitFullscreen_Clean1(paused ? 2 : 0);
            else if (fullscreen == 0) FUN_004013e0_ExitFullscreen_Clean1(paused ? 2 : 1);
            return 0;
        }
        if (wParam == 0x74) { FUN_004054c0_SetWindowSize(320, 224); return 0; }
        if (wParam == 0x75) { FUN_004054c0_SetWindowSize(640, 448); return 0; }
        if (wParam == 0x1b) { // Escape
            if (!windowWord(0x0045633c) || windowWord(0x004a2a98) != 0x3f) {
                if (windowPointer(0x00451794) && windowWord(0x00487f88)) {
                    FUN_00404710_Window();
                    return 0;
                }
                PostMessageA(window, 0x10, 0, 0);
            } else if (!windowWord(0x00487f88)) {
                GamePause_00405240();
            }
            return 0;
        }
        if ((wParam == 0x0d || wParam == 0x20) && windowPointer(0x00451794) &&
            windowWord(0x00487f88)) {
            FUN_00404710_Window();
            return 0;
        }
        break;
    case 0x0046: // WM_WINDOWPOSCHANGING
        if (!windowWord(0x0045103c) && !windowWord(0x00451040)) {
            int width = windowWord(0x00487768);
            int *position = (int *)lParam;
            position[2] = (position[2] + width) & ~3;
            position[2] -= width;
            position[4] = (position[4] - width * 2 + 3) & ~3;
            position[4] += width * 2;
            return 0;
        }
        break;
    case 0x0111: // WM_COMMAND
        return FUN_004032a0_WM_COMMAND(window, message, (short)wParam);
    case 0x0101: // WM_KEYUP
        FUN_004097f0_ProcessCheatInputs(input);
        break;
    case 0x0102: // WM_CHAR
        windowWord(0x0048800c) = (unsigned char)input;
        break;
    case 0x0104: // WM_SYSKEYDOWN
    case 0x0105: // WM_SYSKEYUP
    case 0x0106: // WM_SYSCHAR
        if (wParam == 0x79) return 0; // F10
        break;
    case 0x0211: { // WM_ENTERMENULOOP
        GameUnpause_004051d0();
        windowWord(0x00454fc0) = 0;
        UINT enable = windowWord(0x004a2958) || windowWord(0x004a2a98) == 0x3f;
        HANDLE menu = windowPointer(0x00487f78);
        EnableMenuItem(menu, 0x9c46, enable);
        EnableMenuItem(menu, 0x9c54, FUN_00403030_Registry(1) == 0);
        CheckMenuItem(menu, 0x9c53, windowWord(0x00487f88) == 0 ? 8 : 0);
        return 0;
    }
    case 0x0112: // WM_SYSCOMMAND
        if (wParam == 0xf140 || wParam == 0xf170) return 0;
        break;
    case 0x030f: // WM_QUERYNEWPALETTE
        return windowPaletteChanged(window);
    case 0x0212: // WM_EXITMENULOOP
        if (mainWindow == window) windowWord(0x00454fc0) = 1;
        return 0;
    case 0x03b9: // MM_MCINOTIFY
        if (wParam == 1 || wParam == 8) FUN_00404710_Window();
        return 0;
    case 0x0311: // WM_PALETTECHANGED
        if (mainWindow == (HWND)wParam) return 0;
        return windowPaletteChanged(window);
    case 0x0658:
        if (windowWord(0x00454fc0) && windowWord(0x00487f88)) SetCursor(0);
        return 0;
    case 0x0659:
        FUN_004044b0_MoveWindow((char *)wParam, (long *)lParam);
        return 1;
    case 0x065a:
        FUN_004013e0_ExitFullscreen_Clean1(2);
        return 1;
    case 0x065b:
        FUN_00404710_Window();
        return 1;
    }
    return DefWindowProcA(window, message, wParam, lParam);
}
