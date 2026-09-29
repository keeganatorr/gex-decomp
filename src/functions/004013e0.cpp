typedef struct WINDOWPLACEMENT {
    unsigned int length;
    unsigned int flags;
    unsigned int showCmd;
    int rest[8];
} WINDOWPLACEMENT;
typedef struct WRECT {
    int x, y, w, h;
} WRECT;

extern "C" {
__declspec(dllimport) int __stdcall ShowWindow(void *, int);
__declspec(dllimport) void *__stdcall GetForegroundWindow(void);
__declspec(dllimport) long __stdcall GetWindowLongA(void *, int);
__declspec(dllimport) long __stdcall SetWindowLongA(void *, int, long);
__declspec(dllimport) int __stdcall SetMenu(void *, void *);
__declspec(dllimport) int __stdcall IsIconic(void *);
__declspec(dllimport) int __stdcall SetWindowPlacement(void *, WINDOWPLACEMENT *);
__declspec(dllimport) void *__stdcall SelectPalette(void *, void *, int);
__declspec(dllimport) unsigned int __stdcall RealizePalette(void *);
__declspec(dllimport) int __stdcall MoveWindow(void *, int, int, int, int, int);
__declspec(dllimport) int __stdcall SetForegroundWindow(void *);
extern int gCurrentErrorTypeShown_00487f74;
extern int DAT_00451798_aviLoaded;
extern int DAT_0049fb8c_CurrentBPPType;
extern int gFullscreen_0045103c;
extern int gScreenDisplayMode_00454fc8;
extern void *gVideoWindow_00451794;
extern int gScreenResolution_00451038;
extern int DAT_00451040_FreezeInput;
extern void *volatile gMainWindow_004875a0;
extern void *gMenu_00487f78;
extern WINDOWPLACEMENT WINDOWPLACEMENT_0049fb60;
extern void *gHDC_00487f7c;
extern void *ghPalette_00455474;
int __cdecl DDRAW_SetResolution_00401100(int, int);
int __cdecl FUN_00401270_ChangeVideoMode(int, int, int);
void __cdecl FUN_00404a80_StopMCIMedia(void);
void __cdecl FUN_00401340_CalculateWindowRect(WRECT *);

void __cdecl FUN_004013e0_ExitFullscreen_Clean1(int mode)
{
    WRECT r;
    int m;
    int b;
    void *fg;
    m = gCurrentErrorTypeShown_00487f74 ? 0 : mode;
    b = DAT_00451798_aviLoaded && DAT_0049fb8c_CurrentBPPType == 8 ? 0 : 1;
    if (m == gFullscreen_0045103c) {
        if (m) {
            if (b) {
                if (gScreenDisplayMode_00454fc8 == 8) {
                    if (gVideoWindow_00451794)
                        ShowWindow(gVideoWindow_00451794, 0);
                    DDRAW_SetResolution_00401100(gScreenResolution_00451038, b);
                    if (gVideoWindow_00451794)
                        ShowWindow(gVideoWindow_00451794, 5);
                }
            } else if (gScreenDisplayMode_00454fc8 != 8) {
                if (gVideoWindow_00451794)
                    ShowWindow(gVideoWindow_00451794, 0);
                DDRAW_SetResolution_00401100(gScreenResolution_00451038, b);
                if (gVideoWindow_00451794)
                    ShowWindow(gVideoWindow_00451794, 5);
            }
        }
        return;
    }
    fg = GetForegroundWindow();
    if (gVideoWindow_00451794)
        ShowWindow(gVideoWindow_00451794, 0);
    DAT_00451040_FreezeInput = 1;
    switch (gFullscreen_0045103c << 4 | m) {
    case 0x1:
        if (!FUN_00401270_ChangeVideoMode(0x640480, 0, b))
            m = 0;
        break;
    case 0x2:
        if (!FUN_00401270_ChangeVideoMode(0x320240, 1, b))
            m = 0;
        break;
    case 0x10:
    case 0x20:
        DDRAW_SetResolution_00401100(0, 1);
        SetWindowLongA(gMainWindow_004875a0, -0x10, GetWindowLongA(gMainWindow_004875a0, -0x10) | 0xcf0000);
        SetMenu(gMainWindow_004875a0, gMenu_00487f78);
        if (IsIconic(gMainWindow_004875a0))
            WINDOWPLACEMENT_0049fb60.showCmd = 7;
        SetWindowPlacement(gMainWindow_004875a0, &WINDOWPLACEMENT_0049fb60);
        if (gScreenDisplayMode_00454fc8 == 8 && gHDC_00487f7c && ghPalette_00455474) {
            SelectPalette(gHDC_00487f7c, ghPalette_00455474, 0);
            RealizePalette(gHDC_00487f7c);
        }
        break;
    case 0x12:
        SetMenu(gMainWindow_004875a0, 0);
        if (!DDRAW_SetResolution_00401100(0x320240, b)) {
            SetMenu(gMainWindow_004875a0, gMenu_00487f78);
            m = gFullscreen_0045103c;
        }
        break;
    case 0x21:
        if (!DDRAW_SetResolution_00401100(0x640480, b))
            m = gFullscreen_0045103c;
        else
            SetMenu(gMainWindow_004875a0, gMenu_00487f78);
        break;
    }
    gFullscreen_0045103c = m;
    DAT_00451040_FreezeInput = 0;
    if (gVideoWindow_00451794) {
        FUN_00404a80_StopMCIMedia();
        FUN_00401340_CalculateWindowRect(&r);
        MoveWindow(gVideoWindow_00451794, r.x, r.y, r.w, r.h, 0);
        ShowWindow(gVideoWindow_00451794, 5);
    }
    SetForegroundWindow(fg);
}
}
