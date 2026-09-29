extern "C" {
extern int gMainState_004a2970;
extern volatile int gFreezeGame_004a294c;
extern volatile int M1_004a2a84;
extern int M1_004a2a80;
extern int DAT_004a295c_IsHWNDSetup;
extern void __cdecl FUN_004051a0_WindowDrawing2(void);
__declspec(dllimport) void __stdcall Sleep(unsigned long);
int __cdecl FUN_0040b320_WindowDrawing3(void)
{
    if (gMainState_004a2970 != 2 && gMainState_004a2970 != 6)
        return 0;
    gFreezeGame_004a294c = 1;
    while (M1_004a2a84) {
        if (M1_004a2a80)
            break;
        Sleep(0);
        if (DAT_004a295c_IsHWNDSetup)
            FUN_004051a0_WindowDrawing2();
    }
    return 1;
}
}
