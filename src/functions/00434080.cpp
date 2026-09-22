extern "C" void __cdecl FUN_00444530(void*);
extern "C" void __cdecl FUN_00441150(void*);
extern "C" void __cdecl FUN_00433ec0(void*);
extern "C" void __cdecl GEX_Target(int* param1) {
    int pGVar1;
    int pGVar2;
    int pGVar3;
    int pGVar4;
    int* pGVar5;
    int* pGVar6;
    int iVar7;
    int iVar8;
    pGVar6 = (int*)param1[0x57];
    if ((param1[0x38] & 0x40000) != 0) FUN_00444530(param1);
    iVar7 = 0;
    if (pGVar6 != 0) {
        pGVar1 = param1[0x1e];
        pGVar2 = param1[0x1f];
        pGVar3 = param1[0x7e];
        pGVar4 = param1[0x7f];
        iVar8 = 0;
        pGVar5 = (int*)pGVar6[0x57];
        while (pGVar5 != 0) {
            iVar7 += pGVar6[0x1e];
            iVar8 += pGVar6[0x1f];
            pGVar6 = (int*)pGVar6[0x57];
            pGVar5 = (int*)pGVar6[0x57];
        }
        pGVar5 = (int*)(pGVar1 + (pGVar6[0x1e] + iVar7));
        param1[0x1e] = (int)pGVar5;
        param1[0x7e] = (int)pGVar5;
        pGVar6 = (int*)(pGVar2 + (pGVar6[0x1f] + iVar8));
        param1[0x1f] = (int)pGVar6;
        param1[0x7f] = (int)pGVar6;
        if ((param1[0x38] & 0x200000) != 0) FUN_00433ec0(param1);
        else FUN_00441150(param1);
        param1[0x1e] = pGVar1;
        param1[0x1f] = pGVar2;
        param1[0x7e] = pGVar3;
        param1[0x7f] = pGVar4;
        return;
    }
    if ((param1[0x38] & 0x200000) != 0) {
        FUN_00433ec0(param1);
        return;
    }
    FUN_00441150(param1);
}
