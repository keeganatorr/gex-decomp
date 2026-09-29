extern "C" {
__declspec(dllimport) int __stdcall DeleteObject(void *object);
__declspec(dllimport) int __stdcall EndDialog(void *hwnd, int result);
__declspec(dllimport) void *__stdcall GetDlgItem(void *dlg, int id);
__declspec(dllimport) long __stdcall SetWindowLongA(void *hwnd, int index, long value);
__declspec(dllimport) int __stdcall SetDlgItemTextA(void *dlg, int id, const char *text);
__declspec(dllimport) unsigned int __stdcall GetDlgItemTextA(void *dlg, int id, char *text, int size);
__declspec(dllimport) int __cdecl wsprintfA(char *out, const char *format, ...);
extern void *DAT_00487fc4;
extern void *DAT_00487fcc;
extern long DAT_00487fc8;
extern void *ghInstance_00487f90;
extern char dwNewLong_00405850[];
extern char s_Version__1_00_00451784[];
extern char lpData_00487750[];
void *__cdecl FUN_00405660_GFXUnk(void *instance, int resource, void **palette);
int __stdcall FUN_00403590(void *hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    char format[128];
    char text[128];
    unsigned short id;

    switch (msg) {
    case 2:
        if (DAT_00487fc4) {
            DeleteObject(DAT_00487fc4);
            DAT_00487fc4 = 0;
        }
        if (DAT_00487fcc) {
            DeleteObject(DAT_00487fcc);
            DAT_00487fcc = 0;
        }
        break;
    case 0x110:
        DAT_00487fc4 = FUN_00405660_GFXUnk(ghInstance_00487f90, 0x7b, &DAT_00487fcc);
        DAT_00487fc8 = SetWindowLongA(GetDlgItem(hwnd, 0x417), -4, (long)dwNewLong_00405850);
        SetDlgItemTextA(hwnd, 0x410, s_Version__1_00_00451784);
        GetDlgItemTextA(hwnd, 0x411, format, 0x80);
        wsprintfA(text, format, lpData_00487750);
        SetDlgItemTextA(hwnd, 0x411, text);
        return 1;
    case 0x111:
        id = (unsigned short)wParam;
        if (id == 1 || id == 2)
            EndDialog(hwnd, 0);
        if (id == 3)
            EndDialog(hwnd, 1);
        return 1;
    }
    return 0;
}
}
