typedef struct Remap {
    char saved[16];
    char name[16];
    int defKey;
    int key;
    int id;
    char pad[16];
} Remap;
typedef struct NMHDR {
    void *hwndFrom;
    unsigned int idFrom;
    int code;
} NMHDR;
typedef struct JOYINFO {
    unsigned int wXpos, wYpos, wZpos, wButtons;
} JOYINFO;
typedef struct JOYCAPSA {
    unsigned short wMid, wPid;
    char szPname[32];
    unsigned int wXmin, wXmax, wYmin, wYmax;
    unsigned char rest[0x194 - 0x34];
} JOYCAPSA;
typedef struct STARTUPINFOA {
    unsigned long cb;
    unsigned long rest[16];
} STARTUPINFOA;
typedef struct PROCESS_INFORMATION {
    void *hProcess;
    void *hThread;
    unsigned long dwProcessId;
    unsigned long dwThreadId;
} PROCESS_INFORMATION;
extern "C" {
__declspec(dllimport) int __stdcall WinHelpA(void *hwnd, const char *file, unsigned int command, unsigned long data);
__declspec(dllimport) long __stdcall SetWindowLongA(void *hwnd, int index, long value);
__declspec(dllimport) long __stdcall GetWindowLongA(void *hwnd, int index);
__declspec(dllimport) int __stdcall DeleteObject(void *object);
__declspec(dllimport) void *__stdcall GetParent(void *hwnd);
__declspec(dllimport) void *__stdcall GetDlgItem(void *dlg, int id);
__declspec(dllimport) int __stdcall EnableWindow(void *hwnd, int enable);
__declspec(dllimport) int __stdcall CheckDlgButton(void *dlg, int id, unsigned int check);
__declspec(dllimport) int __stdcall SetDlgItemTextA(void *dlg, int id, const char *text);
__declspec(dllimport) int __cdecl wsprintfA(char *out, const char *format, ...);
__declspec(dllimport) void *__stdcall GetFocus(void);
__declspec(dllimport) int __stdcall CreateProcessA(const char *app, char *cmd, void *pa, void *ta, int inherit, unsigned long flags, void *env, const char *dir, STARTUPINFOA *si, PROCESS_INFORMATION *pi);
__declspec(dllimport) int __stdcall CloseHandle(void *handle);
__declspec(dllimport) unsigned int __stdcall joyGetNumDevs(void);
__declspec(dllimport) unsigned int __stdcall joyGetDevCapsA(unsigned int id, JOYCAPSA *caps, unsigned int size);
__declspec(dllimport) unsigned int __stdcall joyGetPos(unsigned int id, JOYINFO *info);
char *__cdecl strcpy(char *, const char *);
extern void *DAT_004626d8;
extern void *gMainWindow_004875a0;
extern char DAT_00487DE0[];
extern Remap DAT_00455480[12];
extern int DAT_0047f050_timeSetEventUnk2;
extern int DAT_00455018_JoystickEnabled;
extern void *DAT_00488004_HWND_Unk;
extern void *DAT_00487fc4;
extern void *DAT_00487fcc;
extern long DAT_00487fc8;
extern long DAT_004626c8;
extern void *ghInstance_00487f90;
extern int gHasJoystick_00454fc4;
extern unsigned int JOYSTICK_xRange1_00487bc4;
extern unsigned int JOYSTICK_yRange1_00487bc8;
extern unsigned int JOYSTICK_xRange2_00487c58;
extern unsigned int JOYSTICK_yRange2_00487c54;
extern char dwNewLong_00405850[];
extern char DAT_00487fa0_Button_UIString[];
extern char DAT_00455898[];
extern STARTUPINFOA gStartupInfo_0047f060;
extern PROCESS_INFORMATION gProcessInfo_0047f0b0;
long __stdcall FUN_00408350(void *hwnd, unsigned int msg, unsigned int wParam, long lParam);
void *__cdecl FUN_00405660_GFXUnk(void *instance, int resource, void **palette);
int __cdecl FUN_00406fd0_timeSetEventInner(unsigned int bits);
void *__cdecl memset(void *, int, unsigned int);
int __stdcall FUN_004083a0(void *hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    int n;
    int j;
    int bit;
    JOYINFO info;
    JOYCAPSA caps;
    unsigned int range;

    DAT_004626d8 = hwnd;
    switch (msg) {
    case 0x4e:
        switch (((NMHDR *)lParam)->code) {
        case -205:
            WinHelpA(gMainWindow_004875a0, DAT_00487DE0, 1, 0x67);
            break;
        case -203:
            for (n = 8; n != 12; n++) {
                strcpy(DAT_00455480[n].name, DAT_00455480[n].saved);
                DAT_00455480[n].key = DAT_00455480[n].defKey;
            }
            DAT_0047f050_timeSetEventUnk2 = DAT_00455018_JoystickEnabled;
            DAT_00488004_HWND_Unk = 0;
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
            SetWindowLongA(hwnd, 0, 0);
            DAT_00488004_HWND_Unk = 0;
            return 1;
        case -200:
            DAT_00487fc4 = FUN_00405660_GFXUnk(ghInstance_00487f90, 0x79, &DAT_00487fcc);
            SetWindowLongA(GetParent(hwnd), -0x14, GetWindowLongA(GetParent(hwnd), -0x14) & ~0x400);
            gHasJoystick_00454fc4 = 0;
            if (joyGetNumDevs() && !joyGetDevCapsA(0, &caps, 0x194) && !joyGetPos(0, &info)) {
                gHasJoystick_00454fc4 = 1;
                range = caps.wXmax - caps.wXmin;
                JOYSTICK_xRange1_00487bc4 = range >> 1;
                JOYSTICK_yRange1_00487bc8 = (caps.wYmax - caps.wYmin) >> 1;
                JOYSTICK_xRange2_00487c58 = range / 5;
                JOYSTICK_yRange2_00487c54 = (caps.wYmax - caps.wXmin) / 5;
            }
            if (gHasJoystick_00454fc4) {
                DAT_00488004_HWND_Unk = hwnd;
                EnableWindow(GetDlgItem(hwnd, 0x418), 1);
                CheckDlgButton(hwnd, 0x418, DAT_0047f050_timeSetEventUnk2 != -1);
            } else {
                DAT_0047f050_timeSetEventUnk2 = -1;
                CheckDlgButton(hwnd, 0x418, 0);
                EnableWindow(GetDlgItem(hwnd, 0x418), 0);
            }
            break;
        }
        break;
    case 0x53:
        WinHelpA(gMainWindow_004875a0, DAT_00487DE0, 1, 0x67);
        break;
    case 0x110:
        DAT_00487fc8 = SetWindowLongA(GetDlgItem(hwnd, 0x413), -4, (long)dwNewLong_00405850);
        for (n = 0; n != 4; n++) {
            if (DAT_00455480[n + 8].key)
                wsprintfA(DAT_00455480[n + 8].name, DAT_00487fa0_Button_UIString, FUN_00406fd0_timeSetEventInner(DAT_00455480[n + 8].key) + 1);
            else
                DAT_00455480[n + 8].name[0] = 0;
            strcpy(DAT_00455480[n + 8].saved, DAT_00455480[n + 8].name);
            DAT_00455480[n + 8].defKey = DAT_00455480[n + 8].key;
            SetDlgItemTextA(hwnd, DAT_00455480[n + 8].id, DAT_00455480[n + 8].name);
            DAT_004626c8 = SetWindowLongA(GetDlgItem(hwnd, DAT_00455480[n + 8].id), -4, (long)FUN_00408350);
            SetWindowLongA(GetDlgItem(hwnd, DAT_00455480[n + 8].id), -0x15, n);
        }
        return 1;
    case 0x111:
        if (!(unsigned short)(wParam >> 16) && (unsigned short)wParam == 0x402) {
            memset(&gStartupInfo_0047f060, 0, sizeof(gStartupInfo_0047f060));
            gStartupInfo_0047f060.cb = 0x44;
            if (CreateProcessA(0, DAT_00455898, 0, 0, 0, 0, 0, 0, &gStartupInfo_0047f060, &gProcessInfo_0047f0b0)) {
                CloseHandle(gProcessInfo_0047f0b0.hThread);
                CloseHandle(gProcessInfo_0047f0b0.hProcess);
            }
            break;
        }
        if (!(unsigned short)(wParam >> 16) && (unsigned short)wParam == 0x3f8) {
            DAT_00455480[8].key = 2;
            DAT_00455480[9].key = 4;
            DAT_00455480[10].key = 1;
            DAT_00455480[11].key = 8;
            wsprintfA(DAT_00455480[8].name, DAT_00487fa0_Button_UIString, FUN_00406fd0_timeSetEventInner(DAT_00455480[8].key) + 1);
            wsprintfA(DAT_00455480[9].name, DAT_00487fa0_Button_UIString, FUN_00406fd0_timeSetEventInner(DAT_00455480[9].key) + 1);
            wsprintfA(DAT_00455480[10].name, DAT_00487fa0_Button_UIString, FUN_00406fd0_timeSetEventInner(DAT_00455480[10].key) + 1);
            wsprintfA(DAT_00455480[11].name, DAT_00487fa0_Button_UIString, FUN_00406fd0_timeSetEventInner(DAT_00455480[11].key) + 1);
            SetDlgItemTextA(hwnd, DAT_00455480[8].id, DAT_00455480[8].name);
            SetDlgItemTextA(hwnd, DAT_00455480[9].id, DAT_00455480[9].name);
            SetDlgItemTextA(hwnd, DAT_00455480[10].id, DAT_00455480[10].name);
            SetDlgItemTextA(hwnd, DAT_00455480[11].id, DAT_00455480[11].name);
        }
        if (!(unsigned short)(wParam >> 16) && (unsigned short)wParam == 0x418)
            DAT_0047f050_timeSetEventUnk2 = DAT_0047f050_timeSetEventUnk2 == -1 ? 0 : -1;
        break;
    case 0x590:
        if (GetFocus() && GetWindowLongA(GetFocus(), -4) == (long)FUN_00408350) {
            n = GetWindowLongA(GetFocus(), -0x15);
            bit = 1 << (wParam - 1);
            for (j = 0; j != 4; j++) {
                if (j != n && DAT_00455480[j + 8].key == bit) {
                    strcpy(DAT_00455480[j + 8].name, DAT_00455480[n + 8].name);
                    DAT_00455480[j + 8].key = DAT_00455480[n + 8].key;
                    SetDlgItemTextA(hwnd, DAT_00455480[j + 8].id, DAT_00455480[j + 8].name);
                }
            }
            wsprintfA(DAT_00455480[n + 8].name, DAT_00487fa0_Button_UIString, wParam);
            SetDlgItemTextA(hwnd, DAT_00455480[n + 8].id, DAT_00455480[n + 8].name);
            DAT_00455480[n + 8].key = bit;
        }
        break;
    }
    return 0;
}
}
