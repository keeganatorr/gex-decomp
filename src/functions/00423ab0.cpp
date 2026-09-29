// Adapted from pc_decomp_backup/src/functions/FUN_00423AB0.cpp
// Historical source SHA256: 06fdd99ab39dba16d141b1a71a7ba03231d76c9c46932b23c4593fe1dd5ab435
extern "C" {
extern "C" { extern unsigned char FUN_004A0282; }
extern "C" { extern unsigned char FUN_004A0285; }
extern "C" int __cdecl FUN_00423AA0(void**);
extern "C" void __cdecl FUN_00414370(void**);

extern "C" int __cdecl FUN_00423ab0_AirToFaceCrawl(void** param_1)
{
    param_1[0x61] = param_1[0x1e];
    param_1[0x62] = param_1[0x1f];
    if (FUN_004A0282 != 0 && FUN_004A0285 == 0) {
        int iVar1 = FUN_00423AA0(param_1);
        if (iVar1 != 0) {
            FUN_00414370(param_1);
            return 1;
        }
    }
    return 0;
}
}
