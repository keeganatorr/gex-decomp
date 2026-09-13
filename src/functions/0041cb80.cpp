// Adapted from pc_decomp_backup/src/functions/FUN_0041CB80.cpp
// Historical source SHA256: fd610f95fa33b9d1a8bfeeed05e3788f92efa1ebeb862ca84056e8b7747a81d6
extern "C" {
extern "C" int __cdecl FUN_0041A380(void**);
extern "C" int __cdecl FUN_0041CA70(int*);

extern "C" int __cdecl GEX_Target(void** param_1, int** param_2)
{
    int pGVar1 = (int)param_1[0x57];
    int ppGVar4 = FUN_0041A380(param_1);
    param_2[0] = (int*)ppGVar4;
    if (ppGVar4 == 0) return 0;
    if (*(int*)(ppGVar4 + 8) < *(int*)ppGVar4) return 0;

    int iVar7 = 0;
    if (pGVar1 == 0) {
        param_2[2] = (int*)param_1[0x1e];
        param_2[3] = (int*)param_1[0x1f];
    } else {
        int iVar6 = 0;
        int pGVar3 = *(int*)(pGVar1 + 0x15c);
        while (pGVar3 != 0) {
            iVar7 += *(int*)(pGVar1 + 0x78);
            iVar6 += *(int*)(pGVar1 + 0x7c);
            pGVar1 = pGVar3;
            pGVar3 = *(int*)(pGVar1 + 0x15c);
        }
        param_2[2] = (int*)((int)param_1[0x1e] + *(int*)(pGVar1 + 0x78) + iVar7);
        param_2[3] = (int*)((int)param_1[0x1f] + *(int*)(pGVar1 + 0x7c) + iVar6);
    }
    param_2[4] = (int*)((unsigned int)param_1[0x1b] >> 0x1f);
    param_2[5] = (int*)(((unsigned int)param_1[0x1b] & 0x40000000) >> 0x1e);
    param_2[1] = (int*)(((unsigned int)param_1[0x31] + 0x1000) & 0xc00000);
    return FUN_0041CA70((int*)param_2);
}
}
