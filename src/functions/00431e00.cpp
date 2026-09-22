extern "C" {
extern int FUN_004A2AD4;
int __cdecl FUN_0040FCE0(void **);
void __cdecl FUN_0040F260(void **);
void __cdecl FUN_0040F2A0(void **);
unsigned int __cdecl FUN_00431900_Movement_unk(void **);
void __cdecl FUN_00431990(void **, int);
void __cdecl FUN_00419520(void **);
int __cdecl FUN_00428C80(int);
void ** __cdecl FUN_004195D0(int, int, int, int);
void __cdecl FUN_00419BE0(void **, void **);

void __cdecl GEX_Target(void **param_1)
{
    void *pGVar1;
    int iVar2;
    unsigned int uVar3;
    void **ppGVar4;
    int p;

    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = (void *)0;
    pGVar1 = param_1[0x38];
    param_1[0x3a] = (void *)0;
    param_1[0x3b] = (void *)0;
    param_1[0x3c] = (void *)0;
    pGVar1 = (void *)((((int)pGVar1 * 2 ^ (unsigned int)pGVar1) & 0x200) ^ (unsigned int)pGVar1);
    param_1[0x38] = pGVar1;
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
        if (p >= 2) {
            param_1[0x26] = (void *)0;
            param_1[0x15] = (void *)((int)param_1[0x15] + 1);
        }
        if (--*(int *)&param_1[0x27] == 0) {
            iVar2 = FUN_00428C80(5);
            param_1[0x27] = (void *)(iVar2 + 1);
            ppGVar4 = FUN_004195D0(0x5c, (int)param_1[0x1e], (int)param_1[0x1f], FUN_004A2AD4);
            if (ppGVar4 != (void **)0) {
                ppGVar4[0x1b] = (void *)((unsigned int)ppGVar4[0x1b] | 0x8000);
                ppGVar4[0x24] = (void *)0x7fff0000;
                iVar2 = FUN_00428C80(0x40000);
                ppGVar4[0x23] = (void *)-iVar2;
                ppGVar4[0x25] = (void *)0x4000;
                ppGVar4[0x14] = (void *)0x1b;
                ppGVar4[0x26] = (void *)6;
                ppGVar4[0x1c] = (void *)0x30;
                FUN_00419BE0(ppGVar4, param_1);
            }
        }
    }
    if (param_1[0x45] == (void *)0xffffffff) {
        param_1[0x44] = (void *)0;
    }
    param_1[0x45] = (void *)0xffffffff;
}
}
