// Adapted from pc_decomp_backup/src/functions/FUN_00425250.cpp
// Historical source SHA256: aed9bdd81fab0498a9250d394f9285bbf3e363e28fccc2b097d80531b5b0a98a
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" { extern int FUN_0045A6D0; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x15] = 0;
    param_1[0x26] = 0;
    param_1[0x1c] = (void*)20;  
    param_1[0x14] = (void*)0x30;
    param_1[0x27] = (void*)0x14;
    param_1[0x25] = (void*)0x14000;
    param_1[0x24] = (void*)0xe0000;
    param_1[0x21] = (void*)FUN_0045A6D0;
    FUN_00420960(param_1);
}
}
