// Adapted from pc_decomp_backup/src/functions/FUN_00432AB0.cpp
// Historical source SHA256: e7298ea566917f1abce1a1a411dfe2dbf4f5ba57d182c14925050aa92b32f23e
extern "C" {
extern int FUN_004A2AD4;

extern "C" int __cdecl FUN_0040FCE0(int *);
extern "C" void __cdecl FUN_0040F260(int *);
extern "C" void __cdecl FUN_0040F2A0(int *);
extern "C" unsigned int __cdecl FUN_00431900_Movement_unk(int *);
extern "C" void __cdecl FUN_00431990(int *, int);
extern "C" void __cdecl FUN_00419520(int *);
extern "C" int __cdecl FUN_00428C80(int);
extern "C" void *__cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419BE0(void *, void *);

extern "C" void __cdecl GEX_Target(int *param_1)
{
    int pGVar1;
    int iVar2, iVar4;
    unsigned int uVar3;
    int *ppGVar5;

    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    pGVar1 = param_1[0x38];
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    pGVar1 = (((pGVar1 * 2) ^ (unsigned int)pGVar1) & 0x200) ^ (unsigned int)pGVar1;
    param_1[0x38] = pGVar1;
    param_1[0x38] = param_1[0x38] & 0xfffffeff;

    iVar2 = FUN_0040FCE0(param_1);
    if (iVar2 == 0) {
        FUN_0040F260(param_1);
        FUN_0040F2A0(param_1);
        uVar3 = FUN_00431900_Movement_unk(param_1);
        if (uVar3 != 0) {
            FUN_00431990(param_1, 1);
            FUN_00419520(param_1);
        }

        param_1[0x26] = param_1[0x26] + 1;
        if (param_1[0x26] > 1) {
            param_1[0x26] = 0;
            param_1[0x15] = param_1[0x15] + 1;
        }

        param_1[0x27] = param_1[0x27] - 1;
        if (param_1[0x27] == 0) {
            iVar2 = FUN_00428C80(4);
            param_1[0x27] = iVar2 + 2;
            iVar2 = FUN_00428C80(7);
            iVar2 = param_1[0x1f] + ((iVar2 + -3) * 0x8000 - param_1[0x23]) * 2;
            iVar4 = FUN_00428C80(7);
            ppGVar5 = (int *)FUN_004195D0(0x5c, param_1[0x1e] + ((iVar4 + -3) * 0x8000 - param_1[0x20]) * 2, iVar2, (int)FUN_004A2AD4);
            if (ppGVar5 != 0) {
                ppGVar5[0x1b] = ppGVar5[0x1b] | 0xc000;
                ppGVar5[0x21] = 0x7fff0000;
                ppGVar5[0x20] = param_1[0x20] >> 3;
                ppGVar5[0x24] = 0x7fff0000;
                ppGVar5[0x23] = param_1[0x23] >> 3;
                ppGVar5[0x14] = 0x20;
                ppGVar5[0x26] = 3;
                ppGVar5[0x1c] = 0x30;
                FUN_00419BE0(ppGVar5, param_1);
            }
        }
    }

    if (param_1[0x45] == -1) {
        param_1[0x44] = 0;
    }
    param_1[0x45] = -1;
}
}
