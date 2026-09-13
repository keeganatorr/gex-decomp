// Adapted from pc_decomp_backup/src/functions/FUN_00415650.cpp
// Historical source SHA256: 1517a4a9d413a199a4df715a5ee04f58e57c1f9e404f3e4954a2ac13d4fd53e5
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00415600(void**);
extern "C" { extern int FUN_004A2800; }
extern "C" { extern int DAT_004a0214_HighJump; }
extern "C" { extern int FUN_004A287C; }
extern "C" { extern int DAT_004a2884; }
extern "C" { extern int FUN_0045A6D0; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x31;  
    param_1[0x14] = (void*)0x27;
    param_1[0x15] = (void*)1;
    param_1[0x23] = (void*)FUN_004A2800;
    param_1[0x26] = (void*)((-(unsigned int)(DAT_004a0214_HighJump == 0) & 0xfffffffd) + 8);
    param_1[0x27] = (void*)FUN_004A2800;
    param_1[0x28] = (void*)FUN_004A287C;
    param_1[0x25] = (void*)0x14000;
    param_1[0x24] = (void*)0xe0000;
    param_1[0x20] = (void*)DAT_004a2884;
    param_1[0x21] = (void*)FUN_0045A6D0;
    FUN_00415600(param_1);
}
}
