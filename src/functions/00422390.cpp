// Adapted from pc_decomp_backup/src/functions/FUN_00422390.cpp
// Historical source SHA256: 16f113c6c50fd6f019e50c2b990f26bce7c0ee958ac71ee313ca933546c49632
extern "C" {
extern "C" { extern int DAT_004a0264; }
extern "C" { extern int DAT_004a0248; }
extern "C" { extern int DAT_004a0244; }
extern "C" { extern int DAT_004a0214; }
extern "C" { extern int DAT_004a023c; }
extern "C" { extern int DAT_00456b04; }
extern "C" void __cdecl FUN_00422390_Reset_Powerups(void** param1) {
    DAT_004a0264 = 0;
    DAT_004a0248 = 0;
    DAT_004a0244 = 0;
    DAT_004a0214 = 0;
    DAT_004a023c = 0;
    if (param1 != 0 && DAT_00456b04 != 0) {
        param1[0x32] = (void*)0x10000;
        param1[0x33] = (void*)0x10000;
    }
}
}
