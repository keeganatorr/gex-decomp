// Adapted from pc_decomp_backup/src/functions/FUN_00415120.cpp
// Historical source SHA256: ce60fe822d7af9835616f889a4a048d5b1b6b8a76bb3fa34b3d9e5a9c9ae2c96
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" { extern int FUN_004A2888; }
extern "C" void __cdecl FUN_00422410_EatingObject_pState_Call(void**);
extern "C" void __cdecl FUN_00415080(void**);

extern "C" void __cdecl InitPlayerSideSwallow_00415120(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = 0;
    p[0x26] = 0;
    p[0x1c] = (void*)0x3c;
    p[0x14] = (void*)0x57;
    if (FUN_004A2888 != 0) {
        FUN_00422410_EatingObject_pState_Call(p);
    }
    FUN_00415080(p);
}
}
