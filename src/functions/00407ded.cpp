typedef void *HWND;
typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef long LONG;
typedef long LRESULT;

struct InputRemapInfo {
    DWORD unknown0;
    DWORD keycode;
    int controlId;
    DWORD unknown1[4];
    DWORD field4_0x1c[8];
};

extern "C" InputRemapInfo InputRemapInfo_ARRAY_004554a0[];
extern "C" char DAT_00455490[];
extern "C" void *DAT_004626c8;
extern "C" HWND DAT_004626d8;

extern "C" __declspec(dllimport) LRESULT __stdcall CallWindowProcA(void *, HWND, UINT, DWORD, DWORD);
extern "C" __declspec(dllimport) LONG __stdcall GetWindowLongA(HWND, int);
extern "C" __declspec(dllimport) int __stdcall GetKeyNameTextA(LONG, char *, int);
extern "C" __declspec(dllimport) int __stdcall SetDlgItemTextA(HWND, int, const char *);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(HWND, const char *);
extern "C" char *__cdecl strcpy(char *, const char *);

extern "C" LRESULT __cdecl FUN_00407ded_Window_Unk(HWND window, UINT message, DWORD key, DWORD keyData)
{
    if (message != 0x100) {
        if (message == 0x102)
            return 0;
        if (message != 0x104)
            return CallWindowProcA(DAT_004626c8, window, message, key, keyData);
    }

    if (keyData & 0x20000000)
        return 0;

    DWORD *keyList = InputRemapInfo_ARRAY_004554a0[11].field4_0x1c;
    int keyIndex = 0;
    if (*keyList != 0) {
        DWORD *scan = keyList;
        do {
            if (*scan == key)
                break;
            ++scan;
            ++keyIndex;
        } while (*scan != 0);
    }

    if (keyList[keyIndex] == 0)
        return 0;

    LONG selected = GetWindowLongA(window, -21);
    DWORD highKeyData = keyData;
    DWORD *currentKey = &InputRemapInfo_ARRAY_004554a0[0].keycode;
    highKeyData &= 0xffff0000;
    key |= highKeyData;
    keyData = highKeyData;
    int currentIndex = 0;

    do {
        if (currentIndex != selected && *currentKey == key) {
            *currentKey = InputRemapInfo_ARRAY_004554a0[selected].keycode;
            char *destination = (char *)(currentKey - 5);
            strcpy(destination, DAT_00455490 + selected * 60);
            SetDlgItemTextA(DAT_004626d8, (int)currentKey[1], destination);
        }

        currentKey += 15;
        ++currentIndex;
    } while (currentKey != &InputRemapInfo_ARRAY_004554a0[8].keycode);

    char *selectedName = DAT_00455490 + selected * 60;
    GetKeyNameTextA((LONG)keyData, selectedName, 15);
    InputRemapInfo_ARRAY_004554a0[selected].keycode = key;
    SetWindowTextA(window, selectedName);
    return 0;
}
