// Adapted from pc_decomp_backup/src/functions/FUN_00417970.cpp
// Historical source SHA256: 8231c1253e82b431afcbd89a7e184d6dd5e9ef472f1a70f5b36b651f9434878e
extern "C" {
extern int FUN_004A2888;
extern int DAT_00462e50;

extern "C" void* __cdecl FUN_0041A380(void*);
extern "C" void* __cdecl FUN_0041A400(void*);
extern "C" void __cdecl FUN_00419BE0(void*, void*);
extern "C" void __cdecl FUN_00423130_pStateUnk_Eating(void*);
extern "C" void __cdecl FUN_0042e660(void*, int);

extern "C" void __cdecl PlayerClid_00417970(int *param_1, int *param_2)
{
    int gOb_param;
    unsigned int uVar2;
    int ppGVar3;
    int *puVar4;
    int pGVar5;
    int iVar6;
    int iVar1;

    if (*param_2 != 0) {
        gOb_param = param_1[0x5e];
        uVar2 = *(unsigned short *)param_1[0x5c];
        if (uVar2 == 3) {
            if (FUN_004A2888 == 0 && (*(int *)(gOb_param + 0x6c) & 0x200000) != 0) {
                FUN_004A2888 = gOb_param;
                FUN_00419BE0((void *)gOb_param, (void *)param_1);
                FUN_00423130_pStateUnk_Eating(param_1);
                return;
            }
        }
        else if (uVar2 == 1) {
            uVar2 = *(unsigned short *)(*(int *)(gOb_param + 0x170));
            if (uVar2 != 6 && uVar2 != 7 && uVar2 != 8 && param_1[0x1c] == 4) {
                uVar2 = *(int *)(gOb_param + 0x6c);
                ppGVar3 = (int)FUN_0041A380((void *)gOb_param);
                uVar2 = (uVar2 & 0xf00) >> 8;
                puVar4 = (int *)FUN_0041A400((void *)gOb_param);
                if (puVar4 != 0 && ppGVar3 != 0) {
                    if (uVar2 == 3 || uVar2 == 0xb || uVar2 == 10) {
                        if ((*(int *)ppGVar3 & 2) == 0) {
                            if (uVar2 == 3) {
                                iVar1 = param_2[10];
                                if (puVar4 == 0) {
                                    iVar6 = iVar1 - 0x100000;
                                }
                                else {
                                    iVar6 = iVar1;
                                    if ((*puVar4 & 2) != 0) {
                                        return;
                                    }
                                }
                                if (iVar1 <= *(int *)(gOb_param + 0x7c) && *(int *)(gOb_param + 0xd8) < iVar6) {
                                    DAT_00462e50 = 1;
                                    param_1[0x1d] = 3;
                                    FUN_0042e660(param_1, (int)param_2);
                                    *(int *)(gOb_param + 0x114) = 0;
                                    *(int *)(gOb_param + 0xec) = iVar1;
                                    *(int *)(gOb_param + 0x7c) = iVar1;
                                    return;
                                }
                            }
                            else {
                                FUN_0042e660(param_1, (int)param_2);
                                DAT_00462e50 = 1;
                                param_1[0x1d] = 3;
                            }
                        }
                    }
                    else {
                        if (*(int *)(gOb_param + 0x6c) & 0x40000000) {
                            pGVar5 = -((int *)ppGVar3)[3];
                        }
                        else {
                            pGVar5 = ((int *)ppGVar3)[1];
                        }
                        if (*(int *)(gOb_param + 0x6c) & 0x40000000) {
                            uVar2 = -puVar4[3];
                        }
                        else {
                            uVar2 = puVar4[1];
                        }
                        if (*(int *)(gOb_param + 0x7c) + (pGVar5 >> 0x10) * *(int *)(gOb_param + 0xcc) <= (unsigned int)param_1[0x1f] &&
                            (unsigned int)param_1[0x36] < *(int *)(gOb_param + 0xd8) + ((int)uVar2 >> 0x10) * *(int *)(gOb_param + 0xcc)) {
                            DAT_00462e50 = 1;
                            param_1[0x1d] = 3;
                            FUN_0042e660(param_1, (int)param_2);
                            return;
                        }
                    }
                }
            }
        }
    }
}
}
