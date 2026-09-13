// Adapted from pc_decomp_backup/src/functions/FUN_004355D0.cpp
// Historical source SHA256: bb9042f8b5cae6b45bae35a970e2a3f4334e54d64609d8378291e3115732eec9
extern "C" {
extern "C" void __cdecl FUN_00434b10_EVENT_Collision_Unk(void*, unsigned int*);
extern "C" void __cdecl GEX_Target(void** param1, unsigned int* param2) {
    void* pGVar1 = param1[0x1e];
    void* pGVar2 = param1[0x57];
    void* pGVar3 = param1[0x1f];
    void* pGVar4 = param1[0x35];
    void* pGVar5 = param1[0x36];
    int iVar7 = 0;
    if (pGVar2 != 0) {
        int iVar9 = 0, iVar10 = 0, iVar8 = 0;
        void* pGVar6 = *(void**)pGVar2;
        while (pGVar6 != 0) {
            iVar7 += *(int*)((int)pGVar2 + 0x78);
            iVar9 += *(int*)((int)pGVar2 + 0x7c);
            iVar10 += *(int*)((int)pGVar2 + 0x88);
            iVar8 += *(int*)((int)pGVar2 + 0x8c);
            pGVar2 = *(void**)pGVar2;
            pGVar6 = *(void**)pGVar2;
        }
        param1[0x1e] = (void*)((int)pGVar1 + *(int*)((int)pGVar2 + 0x78) + iVar7 + -0x1c);
        param1[0x1f] = (void*)((int)pGVar3 + *(int*)((int)pGVar2 + 0x7c) + iVar9 + -0x1c);
        param1[0x35] = (void*)((int)pGVar4 + *(int*)((int)pGVar2 + 0x88) + iVar10 + -0x1c);
        param1[0x36] = (void*)((int)pGVar5 + *(int*)((int)pGVar2 + 0x8c) + iVar8 + -0x1c);
    }
    FUN_00434b10_EVENT_Collision_Unk(param1, param2);
    if (param1[0x57] != 0) {
        param1[0x1e] = pGVar1;
        param1[0x1f] = pGVar3;
        param1[0x35] = pGVar4;
        param1[0x36] = pGVar5;
    }
}
}
