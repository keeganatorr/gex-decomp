extern "C" {
extern "C" int __cdecl FUN_0041CB80(void**, int*);
extern "C" unsigned int __cdecl FUN_00420C10(unsigned int, unsigned int);

extern "C" int __cdecl GEX_Target(register void** param_1)
{
    int local_28[6];
    int local_10;
    int local_c;
    int iVar1;
    unsigned int uVar2;
    int pGVar3;

    iVar1 = FUN_0041CB80(param_1, local_28);
    if (iVar1 != 0) {
        pGVar3 = (int)param_1[0x1f] - 0x300000;
        uVar2 = FUN_00420C10(local_10 + 0x100000, (unsigned int)pGVar3);
        if ((uVar2 & 0x80000000) == 0) {
            uVar2 = FUN_00420C10(local_c - 0x100000, (unsigned int)pGVar3);
            if ((uVar2 & 0x80000000) == 0) {
                uVar2 = FUN_00420C10((unsigned int)param_1[0x1e], (unsigned int)pGVar3);
                if ((uVar2 & 0x80000000) == 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
}