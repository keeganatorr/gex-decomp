typedef struct NMHDR {
    void *hwndFrom;
    unsigned int idFrom;
    int code;
} NMHDR;

extern "C" {
__declspec(dllimport) int __stdcall WinHelpA(void *, const char *, unsigned int, unsigned long);
__declspec(dllimport) long __stdcall SetWindowLongA(void *, int, long);
__declspec(dllimport) long __stdcall GetWindowLongA(void *, int);
__declspec(dllimport) int __stdcall DeleteObject(void *);
__declspec(dllimport) unsigned int __stdcall IsDlgButtonChecked(void *, int);
__declspec(dllimport) void *__stdcall GetParent(void *);
__declspec(dllimport) unsigned int __stdcall GetDlgItemTextA(void *, int, char *, int);
__declspec(dllimport) int __cdecl wsprintfA(char *, const char *, ...);
__declspec(dllimport) int __stdcall SetDlgItemTextA(void *, int, const char *);
__declspec(dllimport) void *__stdcall GetDlgItem(void *, int);
__declspec(dllimport) int __stdcall CheckRadioButton(void *, int, int, int);
extern void *gMainWindow_004875a0;
extern char DAT_00487DE0[];
extern int gSelectedWindowSizeType_0047f0c0;
extern void *DAT_00487fc4;
extern void *DAT_00487fcc;
extern long DAT_00487fc8;
extern int DAT_0047f0a8;
extern int gFullscreen_0045103c;
extern int lpData_00487a08;
extern int lpData_00487a04;
extern char s_fmt_s_s_00455890[];
extern char s_fmt_s_dxd_00455880[];
extern char dwNewLong_00405850[];
extern void *ghInstance_00487f90;
void *__cdecl FUN_00405660_GFXUnk(void *, int, void **);

int __stdcall WindowSizeDialogProc_00407330(void *hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    char name[0x80];
    char text[0x80];
    char mode[0x80];
    NMHDR *nm;
    switch (msg) {
    case 0x4e:
        nm = (NMHDR *)lParam;
        switch (nm->code) {
        case -205:
            WinHelpA(gMainWindow_004875a0, DAT_00487DE0, 1, 0x65);
            break;
        case -203:
            gSelectedWindowSizeType_0047f0c0 = 0;
            SetWindowLongA(hwnd, 0, 1);
            break;
        case -201:
            if (DAT_00487fc4) {
                DeleteObject(DAT_00487fc4);
                DAT_00487fc4 = 0;
            }
            if (DAT_00487fcc) {
                DeleteObject(DAT_00487fcc);
                DAT_00487fcc = 0;
            }
            if (IsDlgButtonChecked(hwnd, 0x3f9))
                gSelectedWindowSizeType_0047f0c0 = 0;
            if (IsDlgButtonChecked(hwnd, 0x3fa))
                gSelectedWindowSizeType_0047f0c0 = 1;
            if (IsDlgButtonChecked(hwnd, 0x3fb))
                gSelectedWindowSizeType_0047f0c0 = 2;
            if (IsDlgButtonChecked(hwnd, 0x3fc))
                gSelectedWindowSizeType_0047f0c0 = 3;
            SetWindowLongA(hwnd, 0, nm->code == -202);
            return nm->code != -202;
        case -200:
            DAT_00487fc4 = FUN_00405660_GFXUnk(ghInstance_00487f90, 0x77, &DAT_00487fcc);
            SetWindowLongA(GetParent(hwnd), -0x14, GetWindowLongA(GetParent(hwnd), -0x14) & ~0x400);
            if (!DAT_0047f0a8) {
                DAT_0047f0a8++;
                GetDlgItemTextA(hwnd, 0x3f9, name, 0x80);
                if (gFullscreen_0045103c) {
                    GetDlgItemTextA(hwnd, 0x3fc, mode, 0x80);
                    wsprintfA(text, s_fmt_s_s_00455890, name, mode);
                } else {
                    wsprintfA(text, s_fmt_s_dxd_00455880, name, lpData_00487a04, lpData_00487a08);
                }
                SetDlgItemTextA(hwnd, 0x3f9, text);
            }
            CheckRadioButton(hwnd, 0x3f9, 0x3fc, gSelectedWindowSizeType_0047f0c0 + 0x3f9);
            break;
        }
        break;
    case 0x53:
        WinHelpA(gMainWindow_004875a0, DAT_00487DE0, 1, 0x65);
        break;
    case 0x110:
        DAT_00487fc8 = SetWindowLongA(GetDlgItem(hwnd, 0x415), -4, (long)dwNewLong_00405850);
        return 1;
    case 0x111:
        if (!(unsigned short)(wParam >> 16) && (unsigned short)wParam == 0x41c) {
            gSelectedWindowSizeType_0047f0c0 = 3;
            CheckRadioButton(hwnd, 0x3f9, 0x3fc, 0x3fc);
        }
        break;
    }
    return 0;
}
}
