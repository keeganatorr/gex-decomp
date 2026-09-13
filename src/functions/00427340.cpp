// Adapted from pc_decomp_backup/src/functions/FUN_00427340.cpp
// Historical source SHA256: bbffdc7085826483ec8673fbd0edc0f2b977c414270555a257f88616354ffb8e
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004271F0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar1;

    FUN_00420BC0(param_1);
    param_1[0x15] = (void*)0;
    param_1[0x26] = (void*)0;
    param_1[0x1c] = (void*)0x7;  
    param_1[0x14] = (void*)0x3e;

    iVar1 = ((int)param_1[0x1b] >> 31) & 1;
    param_1[0x22] = (void*)(0x28000 - iVar1 * 0x50000);
    FUN_004271F0(param_1);
}
}
