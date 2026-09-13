// Adapted from pc_decomp_backup/src/functions/FUN_00413BA0.cpp
// Historical source SHA256: fdbfee609e5bcf39ec37bfa4495bc2930b25c7c8b96563d395d9a6999dcc32f2
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00413AC0(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = p[0x26] = p[0x28] = 0;
    p[0x1c] = (void*)0x2F;
    p[0x14] = (void*)0x44;
    FUN_00413AC0(p);
}
}
