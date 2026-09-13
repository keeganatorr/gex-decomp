// Adapted from pc_decomp_backup/src/functions/FUN_00424320.cpp
// Historical source SHA256: 8d67caacca77b6383b774bd09528889aad9cf3cd86e7a8a95d239c3cb6e02709
extern "C" {
extern "C" { extern int DAT_0045D6A0; }
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004242E0(void**);

extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x1c] = (void*)0x28;
    p[0x15] = 0;
    p[0x14] = (void*)4;
    p[0x21] = (void*)DAT_0045D6A0;
    p[0x26] = 0;
    FUN_004242E0(p);
}
}
