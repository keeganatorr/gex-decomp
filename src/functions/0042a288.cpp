// Adapted from pc_decomp_backup/src/functions/FUN_0042a288_MapFunkUnk.cpp
// Historical source SHA256: 778ff1c1a51edbeb1cfee4e808108dcc886bad1b92823734e16e2bb70fbb0fd3
extern "C" {
extern "C" int __cdecl FUN_0042A630_Gex_Frames(void**);
extern "C" { extern int DAT_00463b68; }
extern "C" void __cdecl FUN_0042a288_MapFunkUnk() { void** GexObject; if (FUN_0042A630_Gex_Frames(GexObject)) { GexObject[0x1c] = 0; DAT_00463b68 = 0; } }
}
