// Adapted from pc_decomp_backup/src/functions/FUN_00424090.cpp
// Historical source SHA256: d97a65750ecee08be2f434a461eb2b184428c1e2797d29deb210810b1f7e694c
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00423C80(void**);
extern "C" void __cdecl FUN_00423DC0(void**);
extern "C" { extern int DAT_004a2980; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    if ((int)param_1[0x1c] == 12 || DAT_004a2980 != 0) { 
        param_1[0x2a] = (void*)0x64;
    } else {
        param_1[0x2a] = 0;
    }
    param_1[0x14] = (void*)0x29;
    param_1[0x1c] = 0;
    param_1[0x15] = 0;
    param_1[0x20] = 0;
    param_1[0x23] = 0;
    param_1[0x22] = 0;
    param_1[0x26] = (void*)3;
    param_1[0x25] = 0;
    FUN_00423C80(param_1);
    FUN_00423DC0(param_1);
}
}
