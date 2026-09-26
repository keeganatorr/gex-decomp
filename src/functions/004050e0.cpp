extern "C" {
extern volatile int gIsPaused_00487f88;
extern volatile int M1_004a2a80;
extern int SkipIntroBool;
extern int __cdecl GameMain_0040b0a0(int);
__declspec(dllimport) void __stdcall Sleep(unsigned long);
unsigned long __stdcall GEX_Target(void *parameter)
{
    while (!gIsPaused_00487f88 && !M1_004a2a80)
        Sleep(0);
    return GameMain_0040b0a0(SkipIntroBool);
}
}
