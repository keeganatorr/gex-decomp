// Adapted from pc_decomp_backup/src/functions/FUN_004146D0.cpp
// Historical source SHA256: 6d5cb6b81056d7325b06e55f4f1d575eae7424a112596132eb32412c64781763
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00414600(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = p[0x26] = p[0x20] = p[0x22] = 0;
    p[0x1c] = (void*)6;
    p[0x14] = (void*)0x37;
    FUN_00414600(p);
}
}
