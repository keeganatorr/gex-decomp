// Adapted from pc_decomp_backup/src/functions/FUN_00413050.cpp
// Historical source SHA256: 6f22819ba044b5d381ed0d0fa08fd49e6d9e17036392058dc572b4a772b6186e
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void*);
extern "C" int __cdecl FUN_004218A0(void*);
extern "C" void __cdecl FUN_00412F40(void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    int tmp;

    FUN_00420BC0(param_1);
    *(int*)((char*)param_1 + 0x54) = 0;
    *(int*)((char*)param_1 + 0x98) = 0;
    *(int*)((char*)param_1 + 0xa0) = 0;
    *(int*)((char*)param_1 + 0x70) = 0x3b;
    *(int*)((char*)param_1 + 0x50) = 0x53;
    tmp = FUN_004218A0(param_1);
    *(int*)((char*)param_1 + 0xa4) = tmp;
    FUN_00412F40(param_1);
}
}
