// Adapted from pc_decomp_backup/src/functions/FUN_004157E0.cpp
// Historical source SHA256: a0a2aa476d5818ff7cddb072fa59e590d872d01945d8b969cfb7f0976c4fcc84
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_0041A250(void**, int, int, int);
extern "C" void __cdecl FUN_00415790(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x1c] = (void*)0x56;
    p[0x26] = 0;
    FUN_0041A250(p, 0xEC, 0x80, 0x60);
    FUN_00415790(p);
}
}
