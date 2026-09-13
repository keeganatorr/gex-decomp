// Adapted from pc_decomp_backup/src/functions/FUN_004270B0.cpp
// Historical source SHA256: 2216115c686bb5fcfe05a09b843362a482b7dc904f4a9d0adfd18e0d7d900d8b
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00426FC0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar1;

    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x18;  
    param_1[0x14] = (void*)0x32;
    iVar1 = (int)param_1[0x20];
    param_1[0x15] = (void*)0;
    param_1[0x26] = (void*)0;
    param_1[0x22] = (void*)0;
    param_1[0x27] = (void*)((iVar1 > 0) - (iVar1 < 0));
    FUN_00426FC0(param_1);
}
}
