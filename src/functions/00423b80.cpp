// Adapted from pc_decomp_backup/src/functions/FUN_00423B80.cpp
// Historical source SHA256: dced99645db27b76701022159375a7b0218820ea00f9de1aef40bf5e403a6cf2
extern "C" {
extern "C" void __cdecl FUN_00420960(void**);
extern int FUN_00456B04;
extern "C" void __cdecl GEX_Target(void** param1) {
    void* pGVar2 = param1[0x31];
    if (pGVar2 != 0) {
        void* pGVar3 = (void*)-(int)pGVar2;
        int iVar1 = ((unsigned int)pGVar3 ^ (int)pGVar3 >> 0x1f) - ((int)pGVar3 >> 0x1f);
        if (iVar1 > 0x800000) pGVar3 = pGVar2;
        if (iVar1 > 0x1fffff) iVar1 = 0x200000;
        if ((int)pGVar3 < 1) param1[0x31] = (void*)((int)pGVar2 - iVar1);
        else param1[0x31] = (void*)((int)pGVar2 + iVar1 + -0x1c);
        param1[0x31] = (void*)((unsigned int)param1[0x31] & 0xff0000);
        FUN_00420960(param1);
    }
    if (FUN_00456B04 == 0) return;
    pGVar2 = param1[0x32];
    if ((int)pGVar2 < 0x10000) {
        pGVar2 = (void*)((int)pGVar2 + 0x10);
        param1[0x32] = pGVar2;
        if ((int)pGVar2 > 0xffff) pGVar2 = (void*)0x10000;
    } else if ((int)pGVar2 <= 0x10000) goto LAB_23c2d; else {
        pGVar2 = (void*)((int)pGVar2 + -0x10);
        param1[0x32] = pGVar2;
        if ((int)pGVar2 <= 0x10000) pGVar2 = (void*)0x10000;
    }
    param1[0x32] = pGVar2;
LAB_23c2d:
    pGVar2 = param1[0x33];
    if ((int)pGVar2 > 0xffff) {
        if ((int)pGVar2 > 0x10000) {
            pGVar2 = (void*)((int)pGVar2 + -0x10);
            param1[0x33] = pGVar2;
            if ((int)pGVar2 <= 0x10000) pGVar2 = (void*)0x10000;
            param1[0x33] = pGVar2;
        }
        return;
    }
    pGVar2 = (void*)((int)pGVar2 + 0x10);
    param1[0x33] = pGVar2;
    if ((int)pGVar2 <= 0x10000) pGVar2 = (void*)0x10000;
    param1[0x33] = pGVar2;
}
}
