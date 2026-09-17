extern "C" {
    extern int DAT_004a2954_DrawTiles;
    extern int FUN_00455C40;
    extern int FUN_004A2924;
    extern void* PTR_M1_00455b80;
    extern void __cdecl FUN_00405390(const char*, ...);
    extern void __cdecl FUN_004202D0();
    extern void __cdecl FUN_00441110();
    extern void __cdecl FUN_00440830();
    extern void __cdecl FUN_00401B40(int);
    extern void __cdecl FUN_0041F6F0(void*);
    extern void __cdecl FUN_0040A940();
    extern const char FUN_00455E9C[];
    extern const char FUN_00455CC4[];
    extern const char FUN_00455E90[];
    extern const char FUN_00455E70[];
}

extern "C" void __cdecl GEX_Target()
{
    if (DAT_004a2954_DrawTiles != 0 && FUN_00455C40 >= 0) {
        FUN_00405390(FUN_00455E9C);
        FUN_004202D0();
        FUN_00405390(FUN_00455CC4, FUN_004A2924);
        FUN_00441110();
        FUN_00440830();
        FUN_00401B40(2);
        FUN_00405390(FUN_00455E90);
        FUN_0041F6F0(PTR_M1_00455b80);
        FUN_00405390(FUN_00455CC4, FUN_004A2924);
        FUN_00405390(FUN_00455E70);
        FUN_00455C40 = -1;
        FUN_0040A940();
    }
}
