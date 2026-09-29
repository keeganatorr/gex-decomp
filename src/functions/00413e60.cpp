// Adapted from pc_decomp_backup/src/functions/FUN_00413E60.cpp
// Historical source SHA256: de8b5f0ee7182321a242a6c3a09a2f5870957912aa95738c3c05b685acc47a2c
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00423C80(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_00413D60(void**);
extern "C" void __cdecl InitPlayerBounceFall_00413e60(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x15] = 0;
    param_1[0x26] = 0;
    param_1[0x1c] = (void*)4; 
    param_1[0x14] = (void*)0x2e;
    param_1[0x31] = 0;
    if ((int)param_1[0x23] > 0x20000) param_1[0x15] = (void*)1;
    if ((int)param_1[0x23] > 0x50000) param_1[0x15] = (void*)2;
    FUN_00423C80(param_1);
    FUN_00420960(param_1);
    FUN_00413D60(param_1);
}
}
