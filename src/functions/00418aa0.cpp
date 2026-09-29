extern "C" {
extern "C" unsigned int __cdecl FUN_00417F00(unsigned char**);
extern "C" unsigned int __cdecl FUN_0040F170(void*, unsigned int, unsigned int);

extern "C" { extern int DAT_0049FB90; }
extern "C" { extern void* DAT_004A2990; }

extern "C" unsigned char* __cdecl SCRIPT_GetTileAttribute_00418aa0(unsigned char* param_1, int* param_2)
{
    unsigned int uVar1;
    unsigned int uVar2;

    uVar1 = FUN_00417F00(&param_1);
    uVar2 = FUN_00417F00(&param_1);
    DAT_0049FB90 =
        FUN_0040F170(
            DAT_004A2990,
            (unsigned int)(param_2[0x1e] + (uVar1 << 16)),
            (unsigned int)(param_2[0x1f] + (uVar2 << 16)));
    return param_1;
}
}
