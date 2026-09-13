// Adapted from pc_decomp_backup/src/functions/FUN_00411A40.cpp
// Historical source SHA256: 2513e943e5169b661b8d603add5e36e483d4655c68ccf469403db49402071c65
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00411380(void**);
extern "C" { extern int DAT_004A0218; }
extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x23] = 0;
    param_1[0x20] = 0;
    param_1[0x26] = 0;
    param_1[0x1c] = (void*)0x50; 
    param_1[0x14] = (void*)0x49;
    param_1[0x15] = (void*)4;
    DAT_004A0218 = 0x6b;
    FUN_00411380(param_1);
}
}
