// Adapted from pc_decomp_backup/src/functions/FUN_00427CE0.cpp
// Historical source SHA256: e00bc39ba3965999ce2f1f13bcd5f4a4c7bd3d2f6269a1ff8db398df8d72aa5c
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void*);
extern "C" void __cdecl FUN_00422410(void*);
extern "C" void __cdecl FUN_00427C00(void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    FUN_00420BC0(param_1);
    *(int*)((char*)param_1 + 0x54) = 0;
    *(int*)((char*)param_1 + 0x98) = 0;
    *(int*)((char*)param_1 + 0x80) = 0;
    *(int*)((char*)param_1 + 0x70) = 0x26;
    *(int*)((char*)param_1 + 0x50) = 0x35;
    *(int*)((char*)param_1 + 0x88) = 0;
    FUN_00422410(param_1);
    FUN_00427C00(param_1);
}
}
