// Adapted from pc_decomp_backup/src/functions/FUN_00424B80.cpp
// Historical source SHA256: 8567a8939d004396b88b3a50e7316cf0b115171870e139c2d8a7c411dbab74db
extern "C" {
extern "C" { extern int DAT_0045A6D0; }
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00424AE0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x29;  
    param_1[0x15] = (void*)0;
    param_1[0x14] = (void*)0x27;
    param_1[0x21] = (void*)DAT_0045A6D0;
    param_1[0x26] = (void*)0;
    param_1[0x23] = (void*)-1;
    FUN_00424AE0(param_1);
}
}
