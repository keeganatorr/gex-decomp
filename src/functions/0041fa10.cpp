// Adapted from pc_decomp_backup/src/functions/FUN_0041FA10.cpp
// Historical source SHA256: 007d9d93ef7138f29163728d8c3576324d3d142c72ccdb9636b076e73677667b
extern "C" {
extern "C" int __cdecl FUN_004019C0(void);
extern "C" int __cdecl FUN_0041FBA0(void);
extern "C" { extern int DAT_004638C0; }
extern "C" { extern int DAT_004598B0; }
extern "C" { extern int DAT_004638B0; }
extern "C" { extern int DAT_004638B8; }
extern "C" { extern int DAT_004638bc_VoiceInnerCounter; }
extern "C" { extern int DAT_004638C4; }
extern "C" { extern int DAT_004A02D0[]; }

extern "C" int __cdecl GEX_Target(void) {
    if (DAT_004638C0 != 0) {
        if (FUN_004019C0() == 0) return 0;
        DAT_004638C0 = 0;
        DAT_004A02D0[DAT_004638B8] = DAT_004638B0;
        DAT_004638B8 ^= 1;
        DAT_004638bc_VoiceInnerCounter = DAT_004598B0;
        if (DAT_004638C4 != 0) {
            if (FUN_0041FBA0() != 0) {
                DAT_004638C4 = 0;
            }
        }
    }
    return 1;
}
}
