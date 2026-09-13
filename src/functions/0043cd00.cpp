// Adapted from pc_decomp_backup/src/functions/FUN_0043CD00.cpp
// Historical source SHA256: 971a703c4502ec5787bb083c51772ff822ee5acd6a86a144a6e9ca281890883b
extern "C" {
extern "C" int __cdecl FUN_0040FCE0(void**);

extern "C" void __cdecl GEX_Target(int* param_1)
{
    int pGVar1;
    int iVar2;

    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    pGVar1 = param_1[0x38];
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    pGVar1 = ((pGVar1 * 2 ^ (unsigned int)pGVar1) & 0x200 ^ (unsigned int)pGVar1);
    param_1[0x38] = pGVar1;
    param_1[0x38] = pGVar1 & 0xfffffeff;
    iVar2 = FUN_0040FCE0((void**)param_1);
    if (iVar2 == 0 && param_1[0x26] != 0) {
        pGVar1 = param_1[0x27] + param_1[0x26];
        param_1[0x27] = pGVar1;
        if (pGVar1 > 0x10000) {
            param_1[0x27] = pGVar1 - 0x80;
            param_1[0x15] = param_1[0x15] + 1;
        }
    }
    if (param_1[0x45] == -1) {
        param_1[0x44] = 0;
    }
    param_1[0x45] = -1;
}
}
