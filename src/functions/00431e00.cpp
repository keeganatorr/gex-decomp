// Adapted from pc_decomp_backup/src/functions/FUN_00431E00.cpp
// Historical source SHA256: ba8d9f48eb9472d3f7bc1e495664a14641f74a3f71c99584d5a862635c673be5
extern "C" {
extern int FUN_004A2AD4;

extern "C" int __cdecl FUN_0040FCE0(void **);
extern "C" void __cdecl FUN_0040F260(void **);
extern "C" void __cdecl FUN_0040F2A0(void **);
extern "C" unsigned int __cdecl FUN_00431900_Movement_unk(void **);
extern "C" void __cdecl FUN_00431990(void **, int);
extern "C" void __cdecl FUN_00419520(void **);
extern "C" int __cdecl FUN_00428C80(int);
extern "C" void ** __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419BE0(void **, void **);

extern "C" void __cdecl GEX_Target(void **param_1)
{
    int pGVar1;
    int iVar2;
    unsigned int uVar3;
    void **ppGVar4;
    int p;

    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = (void *)0x0;
    pGVar1 = (int)param_1[0x38];
    param_1[0x3a] = (void *)0x0;
    param_1[0x3b] = (void *)0x0;
    param_1[0x3c] = (void *)0x0;
    pGVar1 = (((int)pGVar1 * 2 ^ (unsigned int)pGVar1) & 0x200) ^ (unsigned int)pGVar1;
    param_1[0x38] = (void *)pGVar1;
    param_1[0x38] = (void *)((unsigned int)pGVar1 & 0xfffffeff);
    iVar2 = FUN_0040FCE0(param_1);
    if (iVar2 == 0) {
        FUN_0040F260(param_1);
        FUN_0040F2A0(param_1);
        uVar3 = FUN_00431900_Movement_unk(param_1);
        if (uVar3 != 0) {
            FUN_00431990(param_1, 0);
            FUN_00419520(param_1);
        }
        p = (int)param_1[0x26] + 1;
        param_1[0x26] = (void *)p;
        if (1 < p) {
            param_1[0x26] = (void *)0x0;
            param_1[0x15] = (void *)((int)param_1[0x15] + 1);
        }
        ppGVar4 = param_1 + 0x27;
        *ppGVar4 = (void *)((int)*ppGVar4 + 7);
        if (*ppGVar4 == (void *)0x0) {
            iVar2 = FUN_00428C80(5);
            param_1[0x27] = (void *)(iVar2 + 1);
            ppGVar4 = FUN_004195D0(0x5c, (int)param_1[0x1e], (int)param_1[0x1f], (int)FUN_004A2AD4);
            if (ppGVar4 != (void **)0x0) {
                ppGVar4[0x1b] = (void *)((unsigned int)ppGVar4[0x1b] | 0x8000);
                ppGVar4[0x24] = (void *)0x7fff0000;
                iVar2 = FUN_00428C80(0x40000);
                ppGVar4[0x23] = (void *)-iVar2;
                ppGVar4[0x25] = (void *)0x4000;
                ppGVar4[0x14] = (void *)0x1b;
                ppGVar4[0x26] = (void *)0x6;
                ppGVar4[0x1c] = (void *)0x30;
                FUN_00419BE0(ppGVar4, param_1);
            }
        }
    }
    if (param_1[0x45] == (void *)0xffffffff) {
        param_1[0x44] = (void *)0x0;
    }
    param_1[0x45] = (void *)0xffffffff;
}
}
