// Adapted from pc_decomp_backup/src/functions/FUN_0041D0E0.cpp
// Historical source SHA256: e3a37dd47ea129e67284075d192de5c634f0a623ce2772379bcccf383781c06e
extern "C" {
extern "C" void ** __cdecl FUN_0041A380(void **);
extern "C" void __cdecl FUN_0041CC70(int, int, int, int, int, unsigned int, int, int);

extern "C" int __cdecl GEX_Target(void **param_1, int param_2, int param_3, unsigned int param_4, int **param_5)
{
    void **ppGVar1;
    int iVar3;
    int iVar4;
    int pGVar5;
    int pGVar2;

    pGVar5 = (int)param_1[0x57];
    if (((int)param_1[0x14] < 0) || ((int)param_1[0x15] < 0)) {
        return 0;
    }
    ppGVar1 = FUN_0041A380(param_1);
    if ((ppGVar1 != (void **)0x0) && ((int)*ppGVar1 <= (int)ppGVar1[2])) {
        *param_5 = (int *)ppGVar1;
        if (((unsigned int)param_1[0x1b] & 0x80000000) == 0) {
            param_5[1] = (int *)*ppGVar1;
            param_5[3] = (int *)ppGVar1[2];
            param_5[5] = (int *)ppGVar1[2];
            pGVar2 = (int)*ppGVar1;
        }
        else {
            param_5[1] = (int *)-(int)ppGVar1[2];
            param_5[3] = (int *)-(int)*ppGVar1;
            param_5[5] = (int *)-(int)*ppGVar1;
            pGVar2 = -(int)ppGVar1[2];
        }
        param_5[7] = (int *)pGVar2;
        if (((unsigned int)param_1[0x1b] & 0x40000000) == 0) {
            param_5[2] = (int *)ppGVar1[1];
            param_5[4] = (int *)ppGVar1[1];
            param_5[6] = (int *)ppGVar1[3];
            param_5[8] = (int *)ppGVar1[3];
        }
        else {
            param_5[2] = (int *)-(int)ppGVar1[3];
            param_5[4] = (int *)-(int)ppGVar1[3];
            param_5[6] = (int *)-(int)ppGVar1[1];
            param_5[8] = (int *)-(int)ppGVar1[1];
        }
        if (pGVar5 == 0) {
            pGVar2 = (int)param_1[0x1e];
            pGVar5 = (int)param_1[0x1f];
        }
        else {
            iVar4 = 0;
            iVar3 = 0;
            pGVar2 = *(int *)(pGVar5 + 4);
            while (pGVar2 != 0) {
                iVar4 = iVar4 + *(int *)(pGVar5 + 8);
                iVar3 = iVar3 + *(int *)(pGVar5 + 12);
                pGVar5 = *(int *)(pGVar5 + 4);
                pGVar2 = *(int *)(pGVar5 + 4);
            }
            pGVar2 = (int)param_1[0x1e] + *(int *)(pGVar5 + 8) + iVar4 - 0x1c;
            pGVar5 = (int)param_1[0x1f] + *(int *)(pGVar5 + 12) + iVar3 - 0x1c;
        }
        FUN_0041CC70((int)param_5, pGVar2, pGVar5, param_2, param_3, param_4, (int)param_1[0x32], (int)param_1[0x33]);
        return 1;
    }
    return 0;
}
}
