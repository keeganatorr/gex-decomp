// Adapted from pc_decomp_backup/src/functions/FUN_00424980.cpp
// Historical source SHA256: a1b2af1dca24f891b053663298ef53678163503e3405520a8456112e69c37738
extern "C" {
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" void __cdecl FUN_00427760(void**);
extern "C" void __cdecl FUN_00424B80(void**);
extern "C" void __cdecl FUN_00427B80(void**);

extern "C" int __cdecl FUN_00424980_CheckGexInputs(void** param_1)
{
    if (DAT_004A0295 != 0) {
        FUN_00427760(param_1);
        return 1;
    }
    if (DAT_004A0294 != 0) {
        FUN_00424B80(param_1);
        return 1;
    }
    if (DAT_004A0293 == 0) {
        return 0;
    }
    FUN_00427B80(param_1);
    return 1;
}
}
