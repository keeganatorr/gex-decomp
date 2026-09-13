// Adapted from pc_decomp_backup/src/functions/FUN_004244A0.cpp
// Historical source SHA256: e6618df6b2f9fcbb26ff1d77e3295687482813eacd263ff0e602a7cb4eb1d3fa
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00424360(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = p[0x26] = p[0x20] = p[0x22] = 0;
    p[0x1c] = (void*)0xA;
    p[0x14] = (void*)0x38;
    FUN_00424360(p);
}
}
