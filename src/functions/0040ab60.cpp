// Adapted from pc_decomp_backup/src/functions/FUN_0040AB60.cpp
// Historical source SHA256: 5def4eeafd4dedc8f8a9905bb612fe8761be01328b5ae9a4aee1d3e498d15a3c
extern "C" {
extern "C" { extern void** FUN_004A2AD4; }
extern "C" void __cdecl FUN_0043F2F0();
extern "C" void __cdecl FUN_00409880();
extern "C" int __cdecl FUN_004098D0();
extern "C" { extern int FUN_00456ADC; }
extern "C" { extern int FUN_004A2964; }
extern "C" { extern int FUN_00455C40; }
extern "C" void __cdecl FUN_0040a990_LoadLevel_Clean1();
extern "C" void __cdecl FUN_0040AA10();
extern "C" void __cdecl FUN_0040ab00_EnterMainLoop();
extern "C" void __cdecl FUN_0040AA60();

extern "C" void __cdecl GEX_Target()
{
    if (FUN_004A2AD4 == 0) {
        FUN_0043F2F0();
        FUN_00409880();
        int loadResult;
        do { loadResult = FUN_004098D0(); } while (loadResult == 0);
    }
    if (FUN_00456ADC < 1 || FUN_004A2964 != FUN_00455C40) {
        FUN_0040a990_LoadLevel_Clean1();
    }
    FUN_0040AA10();
    FUN_0040ab00_EnterMainLoop();
    if (FUN_00456ADC > 0 && FUN_004A2964 == FUN_00455C40) return;
    FUN_0040AA60();
}
}
