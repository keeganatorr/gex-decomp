extern "C" {
extern void* DAT_00455998;
extern void* DAT_004A2968;
extern "C" void __cdecl FUN_0043DAF0();
extern "C" void __cdecl FUN_004097A0();
extern "C" void __cdecl FUN_00401FB0();
extern "C" void __cdecl FUN_0043F000(int);
extern "C" void __cdecl FUN_0043F2F0();
extern "C" void __cdecl FUN_00409560();
extern "C" void* __cdecl FUN_004096C0(int);
extern "C" void __cdecl FUN_0043F450();
extern "C" void __cdecl FUN_0043F700(void*, void*, int);
extern "C" void __cdecl FUN_004194C0();
extern "C" void __cdecl FUN_0041CA10();
extern "C" void __cdecl FUN_0040B6F0();
extern "C" void __cdecl FUN_00417EE0();
extern "C" void __cdecl FUN_0040AF60();
extern "C" void __cdecl FUN_00409940();
extern "C" void __cdecl FUN_0040B830();
extern "C" void __cdecl FUN_0043F7D0(void*);
extern "C" void __cdecl FUN_004095C0();
extern "C" void __cdecl FUN_0043F050();
extern "C" void __cdecl FUN_00402080();
extern "C" void __cdecl FUN_004097B0();

extern "C" void __cdecl GEX_Run_0040b000()
{
    int loadedLevel[5];

    FUN_0043DAF0();
    FUN_004097A0();
    FUN_00401FB0();
    FUN_0043F000(2);
    FUN_0043F2F0();
    FUN_00409560();
    DAT_004A2968 = FUN_004096C0(0x3800);
    FUN_0043F450();
    FUN_0043F700((void*)loadedLevel, DAT_00455998, 1);
    FUN_004194C0();
    FUN_0041CA10();
    FUN_0040B6F0();
    FUN_00417EE0();
    FUN_0040AF60();
    FUN_00409940();
    FUN_0040B830();
    FUN_0043F7D0((void*)loadedLevel);
    FUN_004095C0();
    FUN_0043F050();
    FUN_00402080();
    FUN_004097B0();
}
}
