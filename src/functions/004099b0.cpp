// Adapted from pc_decomp_backup/src/functions/FUN_004099B0.cpp
// Historical source SHA256: dd058bc3cc2181bca8e503c05bc0bf32724bea1a066ee2d10e05d5aba99f9601
extern "C" {
extern "C" { extern int DAT_004a2a08_LoadLevelMusic4; }
extern "C" { extern int FUN_004A2964; }
extern "C" { extern unsigned char FUN_004577B4[]; }
extern "C" { extern unsigned char FUN_004577B1[]; }
extern "C" void __cdecl FUN_00402F70();

extern "C" void __cdecl GEX_Target(int param_1)
{
    if (DAT_004a2a08_LoadLevelMusic4 == 0) return;
    unsigned char bMusicLoad = DAT_004a2a08_LoadLevelMusic4;
    int idx = FUN_004A2964 * 8;
    if (param_1 == 0 && FUN_004577B4[idx] == bMusicLoad && (FUN_004577B1[idx] & 1) != 0) return;
    FUN_00402F70();
    DAT_004a2a08_LoadLevelMusic4 = 0;
}
}
