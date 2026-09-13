// Adapted from pc_decomp_backup/src/functions/FUN_00436ED0.cpp
// Historical source SHA256: 8a2cff4e677d54bbaa221998d07631257013b45e577880730985e124546143d1
extern "C" {
extern "C" { extern unsigned int FUN_0045C960; }
extern "C" { extern int DAT_004642e4; }
extern "C" void __cdecl FUN_00436CF0();
extern "C" void __cdecl FUN_00436D50(void**);
extern "C" void __cdecl FUN_0042e850(void**);
extern "C" void __cdecl FUN_00436cb0_Graphics_unk(void**);

extern "C" void __cdecl GEX_Target(void** param_1) {
    void* pGVar1;
    int iVar2;
    int iVar3;
    void* pGVar4;
    void* pGVar5;
    void* pGVar6;
    void* local_10;
    void* local_c;
    void* local_8;
    void* local_4;

    pGVar5 = param_1[0x57];
    FUN_00436CF0();
    iVar2 = 0;
    pGVar4 = local_10;
    pGVar6 = local_10;
    if (pGVar5 != (void*)0x0) {
        iVar3 = 0;
        pGVar6 = param_1[0x1e];
        pGVar4 = param_1[0x1f];
        pGVar1 = *(void**)((int)pGVar5 + 0x58);
        while (pGVar1 != (void*)0x0) {
            iVar2 = iVar2 + *(int*)((int)pGVar5 + 0x44);
            iVar3 = iVar3 + *(int*)((int)pGVar5 + 0x48);
            pGVar5 = *(void**)((int)pGVar5 + 0x58);
            local_10 = pGVar4;
            pGVar1 = *(void**)((int)pGVar5 + 0x58);
        }
        param_1[0x1e] = (void*)(*(int*)((int)pGVar6 + 0x18) + *(int*)((int)pGVar5 + 0x44) + iVar2 + -0x1c);
        param_1[0x1f] = (void*)(*(int*)((int)pGVar4 + 0x18) + *(int*)((int)pGVar5 + 0x48) + iVar3 + -0x1c);
    }
    pGVar1 = *(void**)((int)&FUN_0045C960 + (int)param_1[0x2e] * 4);
    param_1[0x2e] = (void*)((int)param_1[0x2e] + 1);
    if (pGVar1 == (void*)0x0) {
        param_1[0x18] = (void*)&FUN_00436D50;
        param_1[0x2e] = (void*)0x0;
        if (pGVar5 != (void*)0x0) {
            param_1[0x1e] = pGVar6;
            param_1[0x1f] = pGVar4;
        }
        FUN_00436D50(param_1);
    } else {
        param_1[0x2f] = pGVar1;
        param_1[0x30] = (void*)&DAT_004642e4;
        if (((unsigned int)param_1[0x38] & 0x40) != 0) {
            local_10 = param_1[0x1e];
            local_c = param_1[0x1f];
            local_8 = param_1[0x32];
            local_4 = param_1[0x33];
            FUN_0042e850(param_1);
        }
        FUN_00436cb0_Graphics_unk(param_1);
        if (((unsigned int)param_1[0x38] & 0x40) != 0) {
            param_1[0x1e] = local_10;
            param_1[0x1f] = local_c;
            param_1[0x32] = local_8;
            param_1[0x33] = local_4;
        }
    }
    if (pGVar5 != (void*)0x0) {
        param_1[0x1e] = pGVar6;
        param_1[0x1f] = pGVar4;
    }
}
}
