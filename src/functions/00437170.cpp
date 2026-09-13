// Adapted from pc_decomp_backup/src/functions/FUN_00437170.cpp
// Historical source SHA256: e78ba134d5ce005ba757be90c04715204f93caca8e16151e9150ff047f93b401
extern "C" {
extern int FUN_0045C960[];
extern int DAT_0045c988[];
extern int DAT_004642e4;

extern "C" void __cdecl FUN_00436CF0();
extern "C" void __cdecl FUN_0042e850(void **param_1);
extern "C" void __cdecl FUN_00436cb0_Graphics_unk(void **param_1);
extern "C" void __cdecl FUN_00437010(void **param_1);

extern "C" void __cdecl GEX_Target(void **param_1)
{
    int pGVar4;
    int iVar2;
    int iVar3;
    int pGVar5;
    int local_14;
    int pGVar1;
    void *local_10;
    void *local_c;
    void *local_8;
    void *local_4;

    pGVar4 = (int)param_1[0x57];
    FUN_00436CF0();
    iVar3 = 0;
    if (pGVar4 != 0) {
        iVar2 = 0;
        pGVar5 = (int)param_1[0x1e];
        local_14 = (int)param_1[0x1f];
        pGVar1 = *(int *)(pGVar4 + 4);
        while (pGVar1 != 0) {
            iVar3 = iVar3 + *(int *)(pGVar4 + 8);
            iVar2 = iVar2 + *(int *)(pGVar4 + 12);
            pGVar4 = *(int *)(pGVar4 + 4);
            pGVar1 = *(int *)(pGVar4 + 4);
        }
        param_1[0x1e] = (void *)(pGVar5 + *(int *)(pGVar4 + 8) + iVar3 - 0x1c);
        param_1[0x1f] = (void *)(local_14 + *(int *)(pGVar4 + 12) + iVar2 - 0x1c);
    }
    pGVar1 = FUN_0045C960[(int)param_1[0x2e]];
    if (pGVar1 == 0) {
        param_1[0x2e] = (void *)0x0;
        param_1[0x18] = (void *)FUN_00437010;
        if (pGVar4 != 0) {
            param_1[0x1e] = (void *)pGVar5;
            param_1[0x1f] = (void *)local_14;
        }
        FUN_00437010(param_1);
    }
    else {
        if (((unsigned int)param_1[0x38] & 0x40) != 0) {
            local_10 = param_1[0x1e];
            local_c = param_1[0x1f];
            local_8 = param_1[0x32];
            local_4 = param_1[0x33];
            FUN_0042e850(param_1);
        }
        param_1[0x2f] = (void *)DAT_0045c988[(int)param_1[0x2e] * -1];
        param_1[0x2e] = (void *)((int)param_1[0x2e] + 1);
        param_1[0x30] = (void *)0x0;
        FUN_00436cb0_Graphics_unk(param_1);
        param_1[0x2f] = (void *)pGVar1;
        param_1[0x30] = (void *)&DAT_004642e4;
        FUN_00436cb0_Graphics_unk(param_1);
        if (((unsigned int)param_1[0x38] & 0x40) != 0) {
            param_1[0x1e] = local_10;
            param_1[0x1f] = local_c;
            param_1[0x32] = local_8;
            param_1[0x33] = local_4;
        }
    }
    if (pGVar4 != 0) {
        param_1[0x1e] = (void *)pGVar5;
        param_1[0x1f] = (void *)local_14;
    }
}
}
