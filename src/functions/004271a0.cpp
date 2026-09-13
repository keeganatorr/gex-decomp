// Adapted from pc_decomp_backup/src/functions/FUN_004271A0.cpp
// Historical source SHA256: e6e4fbf4a7bba19ba526b2e30efa548f4b3fca0384fbd069e8c94bcfb5b67a77
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00427110(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x26] = p[0x20] = p[0x22] = 0;
    p[0x1c] = (void*)8;
    p[0x14] = (void*)0x3E;
    p[0x15] = (void*)1;
    FUN_00427110(p);
}
}
