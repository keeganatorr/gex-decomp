// Adapted from pc_decomp_backup/src/functions/FUN_00425030.cpp
// Historical source SHA256: 11da722c9c8d0ff9f5c292697d8ee7dac443ad1d45e7188141c309db6d939ec0
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_00424E80(void**);
extern "C" { extern int FUN_0045A6D0; }
extern "C" { extern int FUN_004A2A0C; }
extern "C" { extern unsigned char DAT_004a0294; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)8;  
    param_1[0x27] = (void*)2;
    param_1[0x25] = (void*)0x14000;
    param_1[0x21] = (void*)FUN_0045A6D0;
    param_1[0x26] = (void*)1;
    param_1[0x25] = (void*)0x14000;
    param_1[0x24] = (void*)0xe0000;
    FUN_00420960(param_1);
    DAT_004a0294 = 0;
    if (FUN_004A2A0C != 0) {
        FUN_00424E80(param_1);
    }
}
}
