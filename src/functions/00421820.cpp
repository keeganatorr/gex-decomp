// Adapted from pc_decomp_backup/src/functions/FUN_00421820.cpp
// Historical source SHA256: 64a9aaba0164718cf532eda1ca80f4ad5ab4cce3185be024991bd8f6edae8f44
extern "C" {
extern "C" int __cdecl FUN_0041CB80(void**, int*);
extern "C" unsigned int __cdecl FUN_00420C10(unsigned int, unsigned int);

extern "C" int __cdecl GEX_Target(void** param_1)
{
    int local_28[6];
    int local_10;
    int local_c;
    int iVar1;
    unsigned int uVar2;

    iVar1 = FUN_0041CB80(param_1, local_28);
    if (iVar1 != 0) {
        uVar2 = FUN_00420C10(local_10 + 0x100000, (unsigned int)((int)param_1[0x1f] - 0x1800));
        if ((int)uVar2 >= 0) {
            uVar2 = FUN_00420C10(local_c - 0x100000, (unsigned int)((int)param_1[0x1f] - 0x1800));
            if ((int)uVar2 >= 0) {
                uVar2 = FUN_00420C10((unsigned int)param_1[0x1e], (unsigned int)((int)param_1[0x1f] - 0x1800));
                if ((int)uVar2 >= 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
}
