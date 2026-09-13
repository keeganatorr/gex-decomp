// Adapted from pc_decomp_backup/src/functions/FUN_0043D3E0.cpp
// Historical source SHA256: 6314f7c863be19fcf63bce7b4758366c32944211e0267f09c67221ce4e63aab4
extern "C" {
extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" void* __cdecl FUN_00435D90(void**, void*, void*);
extern "C" void __cdecl FUN_00434260(void**);
extern "C" void __cdecl GEX_Target(void** param1) {
    param1[0x35] = param1[0x1e];
    param1[0x36] = param1[0x1f];
    param1[0x3f] = param1[0x1b];
    param1[0x3d] = param1[0x14];
    param1[0x3e] = param1[0x15];
    param1[0x39] = 0;
    void* pGVar1 = param1[0x38];
    param1[0x3a] = 0; param1[0x3b] = 0; param1[0x3c] = 0;
    pGVar1 = (void*)((((int)pGVar1 * 2 ^ (unsigned int)pGVar1) & 0x200) ^ (unsigned int)pGVar1);
    param1[0x38] = pGVar1;
    param1[0x38] = (void*)((unsigned int)pGVar1 & 0xfffffeff);
    int iVar2 = FUN_0040FCE0(param1);
    if (iVar2 == 0) {
        if (param1[4] != 0) *(void**)(param1 + 4) = FUN_00435D90(param1, param1 + 4, param1[4]);
        if (param1[0xc] != 0) *(void**)(param1 + 0xc) = FUN_00435D90(param1, param1 + 0xc, param1[0xc]);
        if (param1[0x26] != 0) {
            pGVar1 = (void*)((int)param1[0x23] + (int)param1[0x26] + -0x28);
            param1[0x23] = pGVar1;
            if ((int)pGVar1 > 0xffff) {
                param1[0x23] = (void*)((int)pGVar1 + -0x80);
                param1[0x15] = (void*)((int)param1[0x15] + 1);
            }
        }
        FUN_00434260(param1);
    }
    if (param1[0x45] == (void*)-1) param1[0x44] = 0;
    param1[0x45] = (void*)-1;
}
}
