// Adapted from pc_decomp_backup/src/functions/FUN_00414B60.cpp
// Historical source SHA256: eca1bdd3f336be5343a6f61d91a52e8a34c5b7c832f7d4926f5dae381a491b0e
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void*);
extern "C" void __cdecl FUN_00422410(void*);
extern "C" void __cdecl FUN_00414A80(void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    FUN_00420BC0(param_1);
    *(int*)((char*)param_1 + 0x54) = 0;
    *(int*)((char*)param_1 + 0x98) = 0;
    *(int*)((char*)param_1 + 0x80) = 0;
    *(int*)((char*)param_1 + 0x70) = 0x20;
    *(int*)((char*)param_1 + 0x50) = 0x34;
    *(int*)((char*)param_1 + 0x88) = 0;
    FUN_00422410(param_1);
    FUN_00414A80(param_1);
}
}
