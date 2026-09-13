// Adapted from pc_decomp_backup/src/functions/FUN_0043BB70.cpp
// Historical source SHA256: e9be3df715f9288a11403dc333346d9655135b463ac29725b97fd2f936a90e24
extern "C" {
extern "C" { extern int CAMERA_XPos_004a2a38; }
extern "C" { extern void* PTR_00464e08; }
extern "C" void __cdecl FUN_00444590(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    *(int*)((char*)PTR_00464e08 + 0x78) = CAMERA_XPos_004a2a38 + 0xa00000;
    *(int*)((char*)PTR_00464e08 + 0x7c) = 0xe10000;
    FUN_00444590(param_1);
}
}
