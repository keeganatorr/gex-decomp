// Adapted from pc_decomp_backup/src/functions/FUN_00434080.cpp
// Historical source SHA256: 3e560e8f15c2f27875e27c8add231a46c4af4d0af9ca378770d501bb53d17fa1
extern "C" {
extern "C" void __cdecl FUN_00444530(void**);
extern "C" void __cdecl FUN_00441150(void*);
extern "C" void __cdecl FUN_00433ec0(void**);
extern "C" void __cdecl GEX_Target(void** param1) {
    void* pGVar6 = param1[0x57];
    if (((unsigned int)param1[0x38] & 0x40000) != 0) FUN_00444530(param1);
    int iVar7 = 0;
    if (pGVar6 != 0) {
        void* pGVar1 = param1[0x1e];
        void* pGVar2 = param1[0x1f];
        void* pGVar3 = param1[0x7e];
        void* pGVar4 = param1[0x7f];
        int iVar8 = 0;
        void* pGVar5 = *(void**)pGVar6;
        while (pGVar5 != 0) {
            iVar7 += *(int*)((int)pGVar6 + 0x78);
            iVar8 += *(int*)((int)pGVar6 + 0x7c);
            pGVar6 = *(void**)pGVar6;
            pGVar5 = *(void**)pGVar6;
        }
        pGVar5 = (void*)((int)pGVar1 + *(int*)((int)pGVar6 + 0x78) + iVar7 + -0x1c);
        param1[0x1e] = pGVar5;
        param1[0x7e] = pGVar5;
        pGVar6 = (void*)((int)pGVar2 + *(int*)((int)pGVar6 + 0x7c) + iVar8 + -0x1c);
        param1[0x1f] = pGVar6;
        param1[0x7f] = pGVar6;
        if (((unsigned int)param1[0x38] & 0x200000) == 0) FUN_00441150(param1);
        else FUN_00433ec0(param1);
        param1[0x1e] = pGVar1;
        param1[0x1f] = pGVar2;
        param1[0x7e] = pGVar3;
        param1[0x7f] = pGVar4;
        return;
    }
    if (((unsigned int)param1[0x38] & 0x200000) != 0) { FUN_00433ec0(param1); return; }
    FUN_00441150(param1);
}
}
