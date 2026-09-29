// Adapted from pc_decomp_backup/src/functions/FUN_00415BB0.cpp
// Historical source SHA256: c60c1c2d7a7efc0c0389a36ae670de3ac9d7bf4a4027c1eb1aee3141e1919ff9
extern "C" {
extern "C" void __cdecl FUN_00405350(const char*, int);

extern "C" { extern int FUN_004A2AC0; }
extern "C" { extern int FUN_004A2964; }
extern "C" { extern short FUN_004577B0[]; }
extern "C" { extern int FUN_004A2944; }
extern "C" { extern int FUN_004A2A7C; }
extern "C" { extern int FUN_00455C3C; }
extern "C" { extern const char DAT_00458c20[]; }

extern "C" void __cdecl M1_GoToMap_00415bb0()
{
    int MapLevel;

    if (FUN_004A2AC0 != 0) {
        FUN_004A2A7C = 1;
        FUN_004A2964 = FUN_004A2944;
    }
    else {
        MapLevel = (unsigned short)(FUN_004577B0[FUN_004A2964 * 4] & 0xf) + 0x30;
        if (MapLevel < 0x31 || MapLevel > 0x36) {
            FUN_00405350(DAT_00458c20, MapLevel);
        }
        FUN_004A2964 = MapLevel;
    }
    FUN_00455C3C = 1;
}
}
