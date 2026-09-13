// Adapted from pc_decomp_backup/src/functions/FUN_0040AA60.cpp
// Historical source SHA256: d9c202fcd31b222988d538656cfc7fe89a07f972b6dd318f163ba0a39dd21cc9
extern "C" {
extern "C" { extern int DAT_004a2954_DrawTiles; }
extern "C" { extern int FUN_00455C40; }
extern "C" { extern int FUN_004A2924; }
extern "C" { extern void* PTR_M1_00455b80; }
extern "C" void __cdecl FUN_00405390(const char*, ...);
extern "C" void __cdecl FUN_004202D0();
extern "C" void __cdecl FUN_00441110();
extern "C" void __cdecl FUN_00440830();
extern "C" void __cdecl FUN_00401B40();
extern "C" void __cdecl FUN_0041F6F0(void*);
extern "C" void __cdecl FUN_0040A940();
extern "C" { extern const char FUN_00455E9C[]; }
extern "C" { extern const char FUN_00455CC4[]; }
extern "C" { extern const char FUN_00455E90[]; }
extern "C" { extern const char FUN_00455E70[]; }

extern "C" void __cdecl GEX_Target()
{
    if (DAT_004a2954_DrawTiles != 0 && FUN_00455C40 >= 0) {
        FUN_00405390(FUN_00455E9C);
        FUN_004202D0();
        FUN_00405390(FUN_00455CC4, FUN_004A2924);
        FUN_00441110();
        FUN_00440830();
        FUN_00401B40();
        FUN_00405390(FUN_00455E90);
        FUN_0041F6F0(PTR_M1_00455b80);
        FUN_00405390(FUN_00455CC4, FUN_004A2924);
        FUN_00405390(FUN_00455E70);
        FUN_00455C40 = -1;
        FUN_0040A940();
    }
}
}
