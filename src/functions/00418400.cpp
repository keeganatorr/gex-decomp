// Adapted from pc_decomp_backup/src/functions/FUN_00418400.cpp
// Historical source SHA256: 62461b9e828309b01789400ce5de19d57d2bd58fb2be939697b7c76c1c5b32e3
extern "C" {
extern "C" void __cdecl FUN_00405390(const char*);
extern "C" { extern int DAT_00455c54; }
extern "C" { extern const char DAT_00458e3c[]; }
extern "C" int __cdecl GEX_Target(int param1, void** param2) {
    if (param2[0x57] == 0) return param1;
    int iVar6 = 0;
    void* pGVar3 = *(void**)((int)param2[0x57] + 4);
    if (DAT_00455c54 > 1) FUN_00405390(DAT_00458e3c);
    if (pGVar3 == param2) {
        *(void**)((int)param2[0x57] + 4) = param2[0x59];
    } else {
        void* pGVar4 = *(void**)((int)pGVar3 + 8);
        while (pGVar4 != param2) {
            pGVar3 = *(void**)((int)pGVar3 + 8);
            pGVar4 = *(void**)((int)pGVar3 + 8);
        }
        *(void**)((int)pGVar3 + 8) = param2[0x59];
    }
    pGVar3 = param2[0x57];
    void* pGVar4 = *(void**)((int)pGVar3 + 0);
    int iVar5 = 0;
    while (pGVar4 != 0) {
        iVar5 += *(int*)((int)pGVar3 + 0x10);
        iVar6 += *(int*)((int)pGVar3 + 0x14);
        pGVar3 = *(void**)((int)pGVar3 + 0);
        pGVar4 = *(void**)((int)pGVar3 + 0);
    }
    param2[0x1e] = (void*)((int)param2[0x1e] + *(int*)((int)pGVar3 + 0x10) + iVar5 - 0x1c);
    iVar5 = *(int*)((int)pGVar3 + 0x14);
    param2[0x57] = 0;
    param2[0x1f] = (void*)((int)param2[0x1f] + iVar5 + iVar6 - 0x1c);
    return param1;
}
}
