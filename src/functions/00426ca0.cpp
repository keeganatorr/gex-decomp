// Adapted from pc_decomp_backup/src/functions/FUN_00426CA0.cpp
// Historical source SHA256: 98578ec63c0a115d1a0e666b444f3d8bc9b5c66c4e9666cd687f93155ab9bcda
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void*);
extern "C" void __cdecl FUN_00426690(void*);
extern "C" { extern int DAT_004A23C8; }

extern "C" void __cdecl GEX_Target(void* param_1)
{
    FUN_00420BC0(param_1);
    *(int*)((char*)param_1 + 0x8c) = 0;
    *(int*)((char*)param_1 + 0x80) = 0;
    *(int*)((char*)param_1 + 0x98) = 0;
    *(int*)((char*)param_1 + 0x70) = 0x2e;
    *(int*)((char*)param_1 + 0x50) = 0x43;
    *(int*)((char*)param_1 + 0x54) = 6;
    DAT_004A23C8 = 0;
    FUN_00426690(param_1);
}
}
