// Adapted from pc_decomp_backup/src/functions/FUN_00432680.cpp
// Historical source SHA256: ff49845654d2bc14dcd489bfc281076746c91ed23b26c382715a112f95a41e18
extern "C" {
extern int FUN_004A2AD4;

extern "C" int __cdecl FUN_0040FCE0(void **param_1);
extern "C" void __cdecl FUN_0040F260(void **param_1);
extern "C" void __cdecl FUN_0040F2A0(void **param_1);
extern "C" unsigned int __cdecl FUN_00431900_Movement_unk(void **param_1);
extern "C" void ** __cdecl FUN_004195D0(int type, int x, int y, int flags);
extern "C" void __cdecl FUN_00419BE0(void **obj1, void **obj2);
extern "C" void __cdecl FUN_00419520(void **param_1);

extern "C" void __cdecl GEX_Target(void **param_1)
{
    void *pGVar1;
    int iVar2;
    unsigned int uVar3;
    void **ppGVar4;

    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = (void *)0x0;
    pGVar1 = param_1[0x38];
    param_1[0x3a] = (void *)0x0;
    param_1[0x3b] = (void *)0x0;
    param_1[0x3c] = (void *)0x0;
    pGVar1 = (void *)((((int)pGVar1 * 2 ^ (unsigned int)pGVar1) & 0x200) ^ (unsigned int)pGVar1);
    param_1[0x38] = pGVar1;
    param_1[0x38] = (void *)((unsigned int)pGVar1 & 0xfffffeff);
    iVar2 = FUN_0040FCE0(param_1);
    if (iVar2 == 0) {
        FUN_0040F260(param_1);
        FUN_0040F2A0(param_1);
        uVar3 = FUN_00431900_Movement_unk(param_1);
        if (uVar3 != 0) {
            ppGVar4 = FUN_004195D0(0x5c, (int)param_1[0x1e], (int)param_1[0x1f], (int)FUN_004A2AD4);
            if (ppGVar4 != (void **)0x0) {
                ppGVar4[0x14] = (void *)0x1e;
                ppGVar4[0x2e] = (void *)0x6;
                ppGVar4[0x28] = (void *)0x320000;
                ppGVar4[0x1c] = (void *)0x41;
                ppGVar4[0x32] = (void *)0x8000;
                ppGVar4[0x33] = (void *)0x8000;
                ppGVar4[0x31] = (void *)0x10000;
                ppGVar4[0x2f] = (void *)0x1f801f00;
                FUN_00419BE0(ppGVar4, param_1);
            }
            FUN_00419520(param_1);
        }
        pGVar1 = (void *)((int)param_1[0x26] + 1);
        param_1[0x26] = pGVar1;
        if (1 < (int)pGVar1) {
            param_1[0x26] = (void *)0x0;
            param_1[0x15] = (void *)((int)param_1[0x15] + 1);
        }
    }
    if (param_1[0x45] == (void *)0xffffffff) {
        param_1[0x44] = (void *)0x0;
    }
    param_1[0x45] = (void *)0xffffffff;
}
}
