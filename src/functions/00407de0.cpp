typedef struct Remap {
    char saved[16];
    char name[16];
    int defKey;
    int key;
    int id;
    char pad[16];
} Remap;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern int decl_pad_13;
extern int decl_pad_14;
__declspec(dllimport) long __stdcall CallWindowProcA(long prev, void *hwnd, unsigned int msg, unsigned int wParam, long lParam);
__declspec(dllimport) long __stdcall GetWindowLongA(void *hwnd, int index);
__declspec(dllimport) int __stdcall SetDlgItemTextA(void *dlg, int id, const char *text);
__declspec(dllimport) int __stdcall GetKeyNameTextA(long lParam, char *name, int size);
__declspec(dllimport) int __stdcall SetWindowTextA(void *hwnd, const char *text);
char *__cdecl strcpy(char *, const char *);
extern long DAT_004626c8;
extern void *DAT_004626d8;
extern Remap DAT_00455480[8];
extern unsigned int gRemapKeys_00455750[];
long __stdcall GEX_Target(void *hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    int i;
    int idx;
    int n;
    char *name;

    switch (msg) {
    case 0x100:
    case 0x104:
        if (lParam & 0x20000000)
            return 0;
        for (i = 0; gRemapKeys_00455750[i] && gRemapKeys_00455750[i] != wParam; i++)
            ;
        if (!gRemapKeys_00455750[i])
            return 0;
        idx = GetWindowLongA(hwnd, -0x15);
        lParam &= 0xffff0000;
        wParam |= lParam;
        for (n = 0; n != 8; n++) {
            if (n != idx && DAT_00455480[n].key == (int)wParam) {
                DAT_00455480[n].key = DAT_00455480[idx].key;
                strcpy(DAT_00455480[n].name, DAT_00455480[idx].name);
                SetDlgItemTextA(DAT_004626d8, DAT_00455480[n].id, DAT_00455480[n].name);
            }
        }
        name = DAT_00455480[idx].name;
        GetKeyNameTextA(lParam, name, 0xf);
        DAT_00455480[idx].key = wParam;
        SetWindowTextA(hwnd, name);
        return 0;
    case 0x102:
        return 0;
    }
    return CallWindowProcA(DAT_004626c8, hwnd, msg, wParam, lParam);
}
}
