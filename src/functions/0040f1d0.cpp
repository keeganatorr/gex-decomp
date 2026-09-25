extern "C" int __cdecl FUN_0040F030(void*, unsigned int, unsigned int);

static inline int AbsI(int x)
{
    return x < 0 ? -x : x;
}

extern "C" unsigned int __cdecl GEX_Target(void* param_1, unsigned int* param_2)
{
    int uVar1;
    int iVar2;
    int uVar3;

    uVar1 = FUN_0040F030(param_1, param_2[0x1e], param_2[0x1f]);
    iVar2 = FUN_0040F030(param_1, param_2[0x1e], (unsigned int)((int)param_2[0x1f] - 0x200000));
    uVar3 = iVar2 - 0x200000;
    if (AbsI(uVar3) < AbsI(uVar1)) {
        uVar1 = uVar3;
    }
    iVar2 = FUN_0040F030(param_1, param_2[0x1e], (unsigned int)((int)param_2[0x1f] + 0x200000));
    uVar3 = iVar2 + 0x200000;
    if (AbsI(uVar3) >= AbsI(uVar1)) {
        uVar3 = uVar1;
    }
    return (unsigned int)uVar3;
}