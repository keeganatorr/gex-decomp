// Adapted from pc_decomp_backup/src/functions/FUN_00431730.cpp
// Historical source SHA256: feb0ce26cad3bff8a5237d234d6ca6e668c34b2ee17e8cc97355959fbf7e5cae
extern "C" {
extern "C" int __cdecl GEX_Target(void** param_1)
{
    int iVar3 = 0;
    void* pGVar2 = param_1[0x57];
    if (pGVar2 != 0) {
        int iVar4 = 0;
        void* pGVar1 = *(void**)((int)pGVar2 + 0x15c);
        while (pGVar1 != 0) {
            iVar3 = iVar3 + *(int*)((int)pGVar2 + 0x78);
            iVar4 = iVar4 + *(int*)((int)pGVar2 + 0x7c);
            pGVar2 = *(void**)((int)pGVar2 + 0x15c);
            pGVar1 = *(void**)((int)pGVar2 + 0x15c);
        }
        param_1[0x1e] = (void*)((int)param_1[0x1e] + iVar3 + *(int*)((int)pGVar2 + 0x78) - 0x1c);
        param_1[0x7e] = param_1[0x1e];
        param_1[0x1f] = (void*)((int)param_1[0x1f] + iVar4 + *(int*)((int)pGVar2 + 0x7c) - 0x1c);
        param_1[0x7f] = param_1[0x1f];
    }
    return 0;
}
}
