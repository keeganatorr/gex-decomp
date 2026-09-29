// Adapted from pc_decomp_backup/src/functions/FUN_00427940.cpp
// Historical source SHA256: db28d1d003cf77a8edb86dee095a49f7ba88a09c4beeac89710558e160b77c75
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004278A0(void**);
extern "C" void __cdecl InitPlayerUnDucking_00427940(void** p)
{
    FUN_00420BC0(p);
    p[0x1c] = (void*)0x24;
    p[0x14] = (void*)0x2C;
    p[0x15] = (void*)2;
    p[0x26] = 0;
    FUN_004278A0(p);
}
}
