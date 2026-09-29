typedef struct Remap {
    char saved[16];
    char name[16];
    int defKey;
    int key;
    int id;
    char regName[16];
} Remap;
typedef struct JOYINFOEX {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwXpos;
    unsigned long dwYpos;
    unsigned long dwZpos;
    unsigned long dwRpos;
    unsigned long dwUpos;
    unsigned long dwVpos;
    unsigned long dwButtons;
    unsigned long dwButtonNumber;
    unsigned long dwPOV;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
} JOYINFOEX;

extern "C" {
__declspec(dllimport) short __stdcall GetAsyncKeyState(int);
__declspec(dllimport) unsigned int __stdcall joyGetPosEx(unsigned int, JOYINFOEX *);
void *__cdecl memset(void *, int, unsigned int);
extern int DAT_00454fc0_GameFocused;
extern unsigned char DAT_0048800c_InputKeyboard;
extern unsigned char VK_00487fd4;
extern int DAT_00487ff8_FreezeMovementInput;
extern Remap DAT_00455480[12];
extern unsigned int DAT_00455018_JoystickEnabled;
extern unsigned int JOYSTICK_xRange1_00487bc4;
extern unsigned int JOYSTICK_yRange1_00487bc8;
extern unsigned int JOYSTICK_xRange2_00487c58;
extern unsigned int JOYSTICK_yRange2_00487c54;

int __cdecl INPUT_GetActiveKeys_00404ba0(void)
{
    JOYINFOEX ji;
    int keys;
    keys = 0;
    if (!DAT_00454fc0_GameFocused)
        return 0;
    VK_00487fd4 = DAT_0048800c_InputKeyboard;
    if (VK_00487fd4)
        DAT_0048800c_InputKeyboard = 0;
    else if (GetAsyncKeyState(0x25) & 1)
        VK_00487fd4 = 0x25;
    else if (GetAsyncKeyState(0x27) & 1)
        VK_00487fd4 = 0x27;
    else if (GetAsyncKeyState(0x26) & 1)
        VK_00487fd4 = 0x26;
    else if (GetAsyncKeyState(0x28) & 1)
        VK_00487fd4 = 0x28;
    if (!DAT_00487ff8_FreezeMovementInput) {
        if (GetAsyncKeyState(DAT_00455480[0].key & 0xff) & 0x8000000)
            keys += 0x1000;
        if (GetAsyncKeyState(DAT_00455480[1].key & 0xff) & 0x8000000)
            keys += 0x4000;
        if (GetAsyncKeyState(DAT_00455480[2].key & 0xff) & 0x8000000)
            keys += 0x8000;
        if (GetAsyncKeyState(DAT_00455480[3].key & 0xff) & 0x8000000)
            keys += 0x2000;
        if (GetAsyncKeyState(DAT_00455480[4].key & 0xff) & 0x8000000)
            keys += 0x40;
        if (GetAsyncKeyState(DAT_00455480[5].key & 0xff) & 0x8000000)
            keys += 0x20;
        if (GetAsyncKeyState(DAT_00455480[6].key & 0xff) & 0x8000000)
            keys += 0x80;
        if (GetAsyncKeyState(DAT_00455480[7].key & 0xff) & 0x8000000)
            keys += 4;
    }
    if (DAT_00455018_JoystickEnabled != (unsigned int)-1) {
        memset(&ji, 0, sizeof ji);
        ji.dwSize = 0x34;
        ji.dwFlags = 0x83;
        joyGetPosEx(DAT_00455018_JoystickEnabled, &ji);
        if (ji.dwButtons & DAT_00455480[8].key)
            keys += 0x40;
        if (ji.dwButtons & DAT_00455480[9].key)
            keys += 0x20;
        if (ji.dwButtons & DAT_00455480[10].key)
            keys += 0x180;
        if (ji.dwButtons & DAT_00455480[11].key)
            keys += 4;
        if (JOYSTICK_yRange1_00487bc8 - JOYSTICK_yRange2_00487c54 > ji.dwYpos)
            keys += 0x1000;
        if (JOYSTICK_yRange1_00487bc8 + JOYSTICK_yRange2_00487c54 < ji.dwYpos)
            keys += 0x4000;
        if (JOYSTICK_xRange1_00487bc4 - JOYSTICK_xRange2_00487c58 > ji.dwXpos)
            keys += 0x8000;
        if (JOYSTICK_xRange1_00487bc4 + JOYSTICK_xRange2_00487c58 < ji.dwXpos)
            keys += 0x2000;
    }
    return keys;
}
}
