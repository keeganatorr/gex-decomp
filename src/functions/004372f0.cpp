// Adapted from pc_decomp_backup/src/functions/FUN_004372F0.cpp
// Historical source SHA256: 58065518e4f345513de3602a8fb82a2eecbf6a408d296571444f240e208e6833
extern "C" {
extern "C" void __cdecl FUN_00436ED0();

extern "C" void __cdecl GEX_Target(void** param_1)
{
    param_1[0x18] = (void*)&FUN_00436ED0;
    param_1[0x2e] = 0;
}
}
