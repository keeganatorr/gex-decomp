typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef int BOOL;
struct HWND__;
struct HDC__;
struct HPALETTE__;
typedef HWND__ *HWND;
typedef HDC__ *HDC;
typedef HPALETTE__ *HPALETTE;
struct RECT { long left, top, right, bottom; };
struct MCI_GENERIC_PARMS { DWORD dwCallback; };
struct DirectDraw;
typedef long (__stdcall *CooperativeMethod)(DirectDraw *, HWND, DWORD);
struct DirectDraw { CooperativeMethod *lpVtbl; };

extern "C" {
__declspec(dllimport) void __stdcall Sleep(DWORD);
__declspec(dllimport) BOOL __stdcall ShowWindow(HWND, int);
__declspec(dllimport) BOOL __stdcall GetClientRect(HWND, RECT *);
__declspec(dllimport) BOOL __stdcall BitBlt(HDC, int, int, int, int, HDC, int, int, DWORD);
__declspec(dllimport) DWORD __stdcall mciSendCommandA(UINT, UINT, DWORD, DWORD);
__declspec(dllimport) BOOL __stdcall IsWindow(HWND);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char *);
__declspec(dllimport) HPALETTE __stdcall SelectPalette(HDC, HPALETTE, BOOL);
__declspec(dllimport) UINT __stdcall RealizePalette(HDC);

extern HWND gVideoWindow_00451794;
extern int DAT_00451040_FreezeInput;
extern HWND gMainWindow_004875a0;
extern HDC gHDC_00487f7c;
extern int gFullscreen_0045103c;
extern DirectDraw *gDirectDraw_00451030;
extern UINT gMCIDevice_004626a8;
extern const char s_Waiting_for_VideoWindow_to_go_aw_004517bc[];
extern int DAT_004626ac;
extern HPALETTE ghPalette_00455474;
extern int *DAT_004626a4;
extern int DAT_00451798_aviLoaded;
void __cdecl FUN_004046b0_AVI(DWORD);
void __cdecl FUN_004013e0_ExitFullscreen_Clean1(int);
}

extern "C" void __cdecl FUN_00404710_Window(void)
{
    RECT tRect;
    MCI_GENERIC_PARMS closeParameters;
    DWORD error;
    HWND videoWindow;

    if (gVideoWindow_00451794 != 0) {
        while (DAT_00451040_FreezeInput != 0) {
            Sleep(0);
        }
        ShowWindow(gVideoWindow_00451794, 0);
        GetClientRect(gMainWindow_004875a0, &tRect);
        BitBlt(gHDC_00487f7c, 0, 0, tRect.right, tRect.bottom,
               gHDC_00487f7c, 0, 0, 0x42);
        if (gFullscreen_0045103c != 0) {
            gDirectDraw_00451030->lpVtbl[20](gDirectDraw_00451030,
                                           gMainWindow_004875a0, 0x13);
        }
        error = mciSendCommandA(gMCIDevice_004626a8, 0x804, 2,
                                (DWORD)&closeParameters);
        videoWindow = gVideoWindow_00451794;
        gMCIDevice_004626a8 = 0;
        gVideoWindow_00451794 = 0;
        if (gFullscreen_0045103c != 0) {
            gDirectDraw_00451030->lpVtbl[20](gDirectDraw_00451030,
                                           gMainWindow_004875a0, 8);
        }
        if (error != 0) {
            FUN_004046b0_AVI(error);
        }
        while (IsWindow(videoWindow)) {
            OutputDebugStringA(s_Waiting_for_VideoWindow_to_go_aw_004517bc);
            Sleep(0);
        }
        DAT_004626ac = 0;
        if (gHDC_00487f7c != 0 && ghPalette_00455474 != 0) {
            SelectPalette(gHDC_00487f7c, ghPalette_00455474, 0);
            RealizePalette(gHDC_00487f7c);
        }
    }
    if (DAT_004626a4 != 0) {
        *DAT_004626a4 = 1;
        DAT_004626a4 = 0;
    }
    DAT_00451798_aviLoaded = 0;
    FUN_004013e0_ExitFullscreen_Clean1(gFullscreen_0045103c);
}
