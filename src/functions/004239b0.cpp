extern "C" void __cdecl FUN_00423780(void*);
extern "C" unsigned char DAT_004a286c[];

extern "C" int __cdecl FUN_004239b0_pStateUnk(void** param_1)
{
    int iVar1;
    int iVar2;

    FUN_00423780(param_1);
    iVar1 = ((((unsigned int)param_1[0x31] + 0x200000U) & 0x400000U) == 0) ? 3 : 4;
    iVar2 = 0;
    if (0 < iVar1) {
        do {
            if (DAT_004a286c[iVar2] == 0) {
                return 0;
            }
            iVar2 = iVar2 + 1;
        } while (iVar2 < iVar1);
    }
    return 1;
}
