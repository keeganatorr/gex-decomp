// Adapted from pc_decomp_backup/src/functions/FUN_0043D350.cpp
// Historical source SHA256: 938231f244a9764e4b9696b3ca4e5bb245c0ce0fd8c07072cfeed18617f6e2ad
extern "C" {
extern "C" int __cdecl FUN_0041A380(int**);
extern "C" void __cdecl FUN_00434A20(int*);

extern "C" void __cdecl GEX_Target(int** param_1)
{
    int pNVar1;
    int pGVar2;
    int** ppGVar5;
    int bVar4;

    bVar4 = 0;
    pNVar1 = (int)param_1[3];
    ppGVar5 = (int**)FUN_0041A380(param_1);
    if (ppGVar5 != (int**)0 && ((int)*ppGVar5 & 1) != 0) {
        param_1[0x29] = (int*)ppGVar5[7];
    }
    pGVar2 = *(int*)(pNVar1 + 4);
    if (pGVar2 != 0 &&
        (pGVar2 = *(int*)pGVar2, pGVar2 != 0) &&
        (pGVar2 = *(int*)pGVar2, pGVar2 != 0)) {
        bVar4 = 1;
        param_1[4] = (int*)pGVar2;
        pGVar2 = *(int*)(*(int*)(*(int*)(pNVar1 + 4)) + 4);
        if (pGVar2 != 0) {
            param_1[0xc] = (int*)pGVar2;
        }
    }
    if (bVar4) {
        param_1[0x26] = (int*)0;
    }
    else if (param_1[0x26] == (int*)0) {
        param_1[0x26] = (int*)0x4000;
    }
    FUN_00434A20((int*)param_1);
}
}
