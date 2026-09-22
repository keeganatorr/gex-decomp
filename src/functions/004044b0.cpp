typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef unsigned int MCIDEVICEID;
typedef unsigned long MCIERROR;
typedef void *HWND;

struct MCI_DGV_SET_PARMS {
    DWORD dwCallback;
    DWORD dwTimeFormat;
    DWORD dwAudio;
    DWORD dwFileFormat;
    DWORD dwSpeed;
};

struct MCI_DGV_STATUS_PARMS {
    DWORD dwCallback;
    DWORD dwReturn;
    DWORD dwItem;
    DWORD dwTrack;
    char *lpstrDrive;
    DWORD dwReference;
};

struct MCI_GENERIC_PARMS {
    DWORD dwCallback;
};

struct MCI_DGV_WINDOW_PARMS {
    DWORD dwCallback;
    HWND hWnd;
    UINT nCmdShow;
    const char *lpstrText;
};

struct WindowRect {
    int X;
    int Y;
    int Width;
    int Height;
};

struct MCI_DGV_OPEN_PARMS {
    DWORD dwCallback;
    MCIDEVICEID wDeviceID;
    const char *lpstrDeviceType;
    const char *lpstrElementName;
    const char *lpstrAlias;
    DWORD dwStyle;
    HWND hWndParent;
};

struct MCI_PLAY_PARMS {
    DWORD dwCallback;
    DWORD dwFrom;
    DWORD dwTo;
};

extern "C" {
extern int gFullscreen_0045103c;
extern int DAT_00451798_aviLoaded;
extern int DAT_004626ac;
extern HWND gMainWindow_004875a0;
extern char s_avivideo_0045179c[];
extern MCIDEVICEID gMCIDevice_004626a8;
extern HWND gVideoWindow_00451794;
extern DWORD DAT_004626b0;
extern long *DAT_004626a4;

void __cdecl FUN_004013e0_ExitFullscreen_Clean1(int value);
void __cdecl FUN_00401340_CalculateWindowRect(WindowRect *rect);
void __cdecl GameUnpause_004051d0(void);
void __cdecl FUN_004046b0_AVI(MCIERROR error);

__declspec(dllimport) MCIERROR __stdcall mciSendCommandA(MCIDEVICEID device, UINT message, DWORD flags, DWORD parameters);
__declspec(dllimport) int __stdcall MoveWindow(HWND window, int x, int y, int width, int height, int repaint);
__declspec(dllimport) HWND __stdcall GetForegroundWindow(void);
}

extern "C" void __cdecl GEX_Target(char *param_1, long *param_2)
{
    MCI_DGV_SET_PARMS setParams;
    MCI_DGV_STATUS_PARMS statusParams;
    MCI_GENERIC_PARMS realizeParams;
    MCI_DGV_WINDOW_PARMS windowParams;
    WindowRect rect;
    MCI_PLAY_PARMS playParams;
    MCI_PLAY_PARMS *playParamsPtr = &playParams;
    MCI_DGV_OPEN_PARMS openParams;
    MCIERROR error;

    DAT_00451798_aviLoaded = 1;
    DAT_004626ac = 0;
    FUN_004013e0_ExitFullscreen_Clean1(gFullscreen_0045103c);

    openParams.dwCallback = 0;
    openParams.wDeviceID = 0;
    openParams.lpstrDeviceType = s_avivideo_0045179c;
    openParams.lpstrElementName = param_1;
    openParams.lpstrAlias = 0;
    openParams.dwStyle = 0x40000000UL;
    openParams.hWndParent = gMainWindow_004875a0;

    error = mciSendCommandA(0, 0x803, 0x32200UL, (DWORD)&openParams);
    if (error == 0) {
        gMCIDevice_004626a8 = openParams.wDeviceID;
        statusParams.dwItem = 0x4001;
        error = mciSendCommandA(openParams.wDeviceID, 0x814, 0x100UL, (DWORD)&statusParams);
        if (error == 0) {
            gVideoWindow_00451794 = (HWND)statusParams.dwReturn;
            setParams.dwTimeFormat = 0;
            error = mciSendCommandA(gMCIDevice_004626a8, 0x80d, 0x400UL, (DWORD)&setParams);
            if (error == 0) {
                statusParams.dwItem = 1;
                error = mciSendCommandA(gMCIDevice_004626a8, 0x814, 0x100UL, (DWORD)&statusParams);
                if (error == 0) {
                    DAT_004626b0 = statusParams.dwReturn + 2000;
                    error = mciSendCommandA(gMCIDevice_004626a8, 0x840, 0x10000UL, (DWORD)&realizeParams);
                    if (error == 0) {
                        FUN_00401340_CalculateWindowRect(&rect);
                        MoveWindow(gVideoWindow_00451794, rect.X, rect.Y, rect.Width, rect.Height, 0);

                        windowParams.dwCallback = 0;
                        windowParams.hWnd = 0;
                        windowParams.nCmdShow = 5;
                        windowParams.lpstrText = 0;
                        error = mciSendCommandA(gMCIDevice_004626a8, 0x841, 0x40000UL, (DWORD)&windowParams);
                        if (error == 0) {
                            playParamsPtr->dwCallback = (DWORD)gMainWindow_004875a0;
                            playParamsPtr->dwFrom = 0;
                            playParamsPtr->dwTo = 0;
                            error = mciSendCommandA(gMCIDevice_004626a8, 0x806, 0x1000001UL, (DWORD)playParamsPtr);
                            if (error == 0) {
                                DAT_004626a4 = param_2;
                                if (GetForegroundWindow() == gMainWindow_004875a0)
                                    return;
                                GameUnpause_004051d0();
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

    FUN_004046b0_AVI(error);
    gVideoWindow_00451794 = 0;
    *param_2 = 1;
}
