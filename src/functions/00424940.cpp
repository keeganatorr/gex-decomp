// Adapted from pc_decomp_backup/src/functions/FUN_00424940.cpp
// Historical source SHA256: 3e690dc9ec5b66a158eac41c7260125d5c6b8f2d5f05dbc7d62264d8c3924dfc
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004248E0(void**);
extern "C" { extern unsigned char DAT_004A0280; }

extern "C" void __cdecl GEX_Target(void** p) {
    FUN_00420BC0(p);
    p[0x20] = (void*)((DAT_004A0280 != 0) ? -0x30000 : 0x30000);
    FUN_004248E0(p);
}
}
