// Adapted from pc_decomp_backup/src/functions/FUN_00427850.cpp
// Historical source SHA256: 818ff2b52245a8caeddba83e813c882627c04d1cf32999e47fe8d5628fb7c134
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00427780(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x20] = p[0x22] = p[0x31] = 0;
    p[0x1c] = (void*)0x1E;
    p[0x14] = (void*)0x2C;
    p[0x15] = (void*)1;
    FUN_00427780(p);
}
}
