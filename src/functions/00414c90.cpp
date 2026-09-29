// Adapted from pc_decomp_backup/src/functions/FUN_00414C90.cpp
// Historical source SHA256: ded292eaf75db8ecb4ae26592f868eee03c769e64e2484cd113f10242d207b1d
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00414BB0(void**);

extern "C" void __cdecl InitPlayerDuckSpin_00414c90(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x26] = (void*)0;
    param_1[0x27] = (void*)0;
    param_1[0x29] = (void*)0;
    param_1[0x15] = (void*)0;
    param_1[0x20] = (void*)0;
    param_1[0x1c] = (void*)0x21;  
    param_1[0x14] = (void*)0x33;
    param_1[0x22] = (void*)0;
    FUN_00414BB0(param_1);
}
}
