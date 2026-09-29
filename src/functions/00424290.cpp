// Adapted from pc_decomp_backup/src/functions/FUN_00424290.cpp
// Historical source SHA256: 11085bee39af6136eacec176a166c82e51b42dd1881715dedbec347d0d0771b6
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void*);
extern "C" void __cdecl FUN_00424110(void*);

extern "C" void __cdecl InitPlayerSlide45_00424290(void* param_1)
{
    FUN_00420BC0(param_1);
    *(int*)((char*)param_1 + 0x54) = 0;
    *(int*)((char*)param_1 + 0x98) = 0;
    *(int*)((char*)param_1 + 0x70) = 9;
    *(int*)((char*)param_1 + 0x50) = 0x31;
    *(int*)((char*)param_1 + 0x84) = 0x80000;
    *(int*)((char*)param_1 + 0x9c) = 2;
    FUN_00424110(param_1);
}
}
