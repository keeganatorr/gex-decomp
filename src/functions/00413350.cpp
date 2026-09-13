// Adapted from pc_decomp_backup/src/functions/FUN_00413350.cpp
// Historical source SHA256: 9c2d97013fba88b29c07bf9ffda445ff8e02c2f6851ca2ef817346662770ef1f
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00413230(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x1c] = (void*)0x49;
    p[0x26] = 0;
    p[0x14] = (void*)0x55;
    p[0x15] = (void*)3;
    *(int*)0x004A0218 = 0x67;
    FUN_00413230(p);
}
}
