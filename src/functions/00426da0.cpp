// Adapted from pc_decomp_backup/src/functions/FUN_00426DA0.cpp
// Historical source SHA256: 008eb2125e56671065e8825b3b687dce387ab1ec4b82931145d1f7640e3f8ce3
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00426D20(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x26] = p[0x20] = p[0x22] = 0;
    p[0x1c] = (void*)0x1A;
    p[0x14] = (void*)0x32;
    p[0x15] = (void*)3;
    FUN_00426D20(p);
}
}
