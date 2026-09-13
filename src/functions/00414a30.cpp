// Adapted from pc_decomp_backup/src/functions/FUN_00414A30.cpp
// Historical source SHA256: e2d5f042a73495898d09fcb79ed763bfe9a539bb7e478e27a79e70d5966ce132
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00414900(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = p[0x26] = p[0x28] = p[0x20] = p[0x22] = 0;
    p[0x1c] = (void*)0x1F;
    p[0x14] = (void*)0x36;
    FUN_00414900(p);
}
}
