// Adapted from pc_decomp_backup/src/functions/FUN_00425EF0.cpp
// Historical source SHA256: e177b1ec06bd40e0e242f57ff5b23c1012e0edc2c9650105cb9537058bc55f58
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00425E80(void**);

extern "C" void __cdecl InitPlayerRunJumpStart_00425ef0(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x2b;  
    param_1[0x14] = (void*)0x28;
    param_1[0x15] = (void*)0;
    param_1[0x21] = (void*)0x90000;
    param_1[0x26] = (void*)2;
    param_1[0x23] = (void*)-1;
    FUN_00425E80(param_1);
}
}
