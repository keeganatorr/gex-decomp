// Adapted from pc_decomp_backup/src/functions/FUN_00418AA0.cpp
// Historical source SHA256: cff3b77632a9ffced32de02afb169d8ca9d8163ad19f05c14894d760ce5f2532
extern "C" {
extern "C" unsigned int __cdecl FUN_00417F00(unsigned char**);
extern "C" unsigned int __cdecl FUN_0040F170(void*, unsigned int, unsigned int);

extern "C" { extern int DAT_0049FB90; }
extern "C" { extern void* DAT_004A2990; }

extern "C" unsigned char* __cdecl GEX_Target(unsigned char* param_1, void** param_2)
{
    unsigned int uVar1;
    unsigned int uVar2;

    uVar1 = FUN_00417F00(&param_1);
    uVar2 = FUN_00417F00(&param_1);
    DAT_0049FB90 =
        FUN_0040F170(
            DAT_004A2990,
            (unsigned int)((int)param_2[0x1e] + uVar1 * 0x80),
            (unsigned int)((int)param_2[0x1f] + uVar2 * 0x80));
    return param_1;
}
}
