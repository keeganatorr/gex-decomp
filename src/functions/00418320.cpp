// Adapted from pc_decomp_backup/src/functions/FUN_00418320.cpp
// Historical source SHA256: 60b016f608b9acc057cfcb88aefaf9ccd7aac4338ff70bddd8738e8f3906381b
extern "C" {
extern void* DAT_0049FB94;

extern "C" int __cdecl SCRIPT_LinkObject_00418320(int param_1, void** param_2)
{
    void* pGVar1;
    void* pGVar2;

    param_2[0x1e] = (void*)0x0;
    param_2[0x1f] = (void*)0x0;
    param_2[0x57] = DAT_0049FB94;
    pGVar1 = *(void**)((int)DAT_0049FB94 + 0x160);
    if (pGVar1 == (void*)0x0) {
        *(void**)((int)DAT_0049FB94 + 0x160) = (void*)param_2;
        return param_1;
    }
    pGVar2 = *(void**)((int)pGVar1 + 0x164);
    while (pGVar2 != (void*)0x0) {
        pGVar1 = *(void**)((int)pGVar1 + 0x164);
        pGVar2 = *(void**)((int)pGVar1 + 0x164);
    }
    *(void**)((int)pGVar1 + 0x164) = (void*)param_2;
    param_2[0x59] = (void*)0x0;
    return param_1;
}
}
