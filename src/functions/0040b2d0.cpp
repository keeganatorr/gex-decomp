extern "C" {
extern volatile int gFreezeGame_004a294c;
extern volatile int M1_004a2a84;
extern volatile int M1_004a2a80;
extern void __cdecl INPUT_GetActiveKeys_00404ba0(int);
__declspec(dllimport) void __stdcall Sleep(unsigned long);
void __cdecl FUN_0040b2d0_InputProcessing(void)
{
    if (gFreezeGame_004a294c == 2) {
        M1_004a2a84 = 0;
        while (gFreezeGame_004a294c) {
            if (M1_004a2a80)
                break;
            Sleep(0);
            INPUT_GetActiveKeys_00404ba0(0);
        }
        M1_004a2a84 = 1;
    }
}
}
