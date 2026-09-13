// Adapted from pc_decomp_backup/src/functions/FUN_0042A630.cpp
// Historical source SHA256: 065f63d4fae0a7ed90a1d81480881e8e43f7b23cd980953877881bf292a421ca
extern "C" {
extern "C" int __cdecl GEX_Target(void** param1) {
    int pGVar1 = (int)param1[0x29];
    int pGVar2 = (int)param1[0x26];
    if (pGVar2 < pGVar1) {
        param1[0x26] = (void*)(pGVar2 + 0x200);
        if ((int)param1[0x26] >= pGVar1) { param1[0x26] = (void*)pGVar1; return 1; }
    } else {
        if (pGVar2 <= pGVar1) return 1;
        param1[0x26] = (void*)(pGVar2 - 0x200);
        if ((int)param1[0x26] <= pGVar1) { param1[0x26] = (void*)pGVar1; return 1; }
    }
    return 0;
}
}
