typedef struct NMHDR {
    void *hwndFrom;
    unsigned int idFrom;
    int code;
} NMHDR;
typedef struct Remap {
    char saved[16];
    char name[16];
    int defKey;
    int key;
    int id;
    char pad[16];
} Remap;

extern "C" {
__declspec(dllimport) int __stdcall WinHelpA(void *, const char *, unsigned int, unsigned long);
__declspec(dllimport) int __stdcall GetKeyNameTextA(long, char *, int);
__declspec(dllimport) long __stdcall SetWindowLongA(void *, int, long);
__declspec(dllimport) long __stdcall GetWindowLongA(void *, int);
__declspec(dllimport) int __stdcall DeleteObject(void *);
__declspec(dllimport) void *__stdcall GetParent(void *);
__declspec(dllimport) void *__stdcall GetDlgItem(void *, int);
__declspec(dllimport) long __stdcall SendDlgItemMessageA(void *, int, unsigned int, unsigned int, long);
__declspec(dllimport) int __stdcall SetDlgItemTextA(void *, int, const char *);
char *__cdecl strcpy(char *, const char *);
extern void *gMainWindow_004875a0;
extern char DAT_00487DE0[];
extern void *DAT_00487fc4;
extern void *DAT_00487fcc;
extern long DAT_00487fc8;
extern long DAT_004626c8;
extern void *DAT_004626d8;
extern char dwNewLong_00405850[];
extern char dwNewLong_00407de0[];
extern void *ghInstance_00487f90;
extern Remap DAT_00455480[8];
void *__cdecl FUN_00405660_GFXUnk(void *, int, void **);

int __stdcall InputDialogProc_00407f80(void *hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    int i;
    Remap *e;
    DAT_004626d8 = hwnd;
    switch (msg) {
    case 0x4e:
        switch (((NMHDR *)lParam)->code) {
        case -205:
            WinHelpA(gMainWindow_004875a0, DAT_00487DE0, 1, 0x68);
            break;
        case -203:
            for (i = 0; i != 8; i++) {
                strcpy(DAT_00455480[i].name, DAT_00455480[i].saved);
                DAT_00455480[i].key = DAT_00455480[i].defKey;
            }
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
            return 1;
        case -200:
            DAT_00487fc4 = FUN_00405660_GFXUnk(ghInstance_00487f90, 0x7a, &DAT_00487fcc);
            SetWindowLongA(GetParent(hwnd), -0x14, GetWindowLongA(GetParent(hwnd), -0x14) & ~0x400);
            break;
        }
        break;
    case 0x53:
        WinHelpA(gMainWindow_004875a0, DAT_00487DE0, 1, 0x68);
        break;
    case 0x110:
        DAT_00487fc8 = SetWindowLongA(GetDlgItem(hwnd, 0x414), -4, (long)dwNewLong_00405850);
        for (i = 0; i != 8; i++) {
            strcpy(DAT_00455480[i].saved, DAT_00455480[i].name);
            DAT_00455480[i].defKey = DAT_00455480[i].key;
            SendDlgItemMessageA(hwnd, DAT_00455480[i].id, 0xc, 0, (long)DAT_00455480[i].name);
            DAT_004626c8 = SetWindowLongA(GetDlgItem(hwnd, DAT_00455480[i].id), -4, (long)dwNewLong_00407de0);
            SetWindowLongA(GetDlgItem(hwnd, DAT_00455480[i].id), -0x15, i);
        }
        return 1;
    case 0x111:
        if (!(unsigned short)(wParam >> 16) && (unsigned short)wParam == 0x404) {
            DAT_00455480[0].key = 0x9480026;
            DAT_00455480[1].key = 0x9500028;
            DAT_00455480[2].key = 0x94b0025;
            DAT_00455480[3].key = 0x94d0027;
            DAT_00455480[4].key = 0x82d0058;
            DAT_00455480[5].key = 0x82c005a;
            DAT_00455480[6].key = 0x82e0043;
            DAT_00455480[7].key = 0x82f0056;
            for (i = 0; i != 8; i++) {
                GetKeyNameTextA(DAT_00455480[i].key & 0xffff0000, DAT_00455480[i].name, 0xf);
                SetDlgItemTextA(hwnd, DAT_00455480[i].id, DAT_00455480[i].name);
            }
        }
        break;
    }
    return 0;
}
}
