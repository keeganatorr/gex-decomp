// Adapted from pc_decomp_backup/src/functions/FUN_00415720.cpp
// Historical source SHA256: 4df090703ab262a0a22d78109ce81eaaea4c4ce14986f16aa19a80fd8b48ef90
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004156E0(void**);
extern "C" { extern int DAT_004A287C; }
extern "C" { extern int DAT_004A2800; }
extern "C" { extern int DAT_0045A6D0; }

extern "C" void __cdecl InitPlayerLaunchTailBounce_00415720(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x54; 
    param_1[0x14] = (void*)0x2e;
    param_1[0x15] = (void*)8;
    param_1[0x26] = (void*)DAT_004A287C;
    param_1[0x27] = (void*)DAT_004A2800;
    param_1[0x23] = (void*)DAT_004A2800;
    param_1[0x25] = (void*)0x14000;
    param_1[0x24] = (void*)0xe0000;
    param_1[0x21] = (void*)DAT_0045A6D0;
    FUN_004156E0(param_1);
}
}
