// Adapted from pc_decomp_backup/src/functions/FUN_00433170.cpp
// Historical source SHA256: 38abedc87039a1535552d82de1b096da68c65cccb32c941091e3b8cfcb234386
extern "C" {
extern int FUN_004A2AD4;

extern "C" int __cdecl FUN_0041E9D0(int *, int);
extern "C" void __cdecl FUN_0041FA80(int);
extern "C" void __cdecl FUN_0041A340(int *, int);
extern "C" void __cdecl FUN_00433140(int *);
extern "C" int __cdecl FUN_0041CB80(int *, int **);
extern "C" void __cdecl FUN_00419BE0(void *, void *);
extern "C" void __cdecl FUN_0041E880(int *, int *);
extern "C" void *__cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419520(int *);
extern "C" void __cdecl FUN_00432D40();
extern "C" void __cdecl FUN_00432F30();
extern "C" void __cdecl FUN_00432FA0();

extern "C" void __cdecl ob95Clid_00433170(int *param_1, int *param_2)
{
    int iVar3;
    unsigned int uVar4;
    int pGVar6;
    int *ppGVar5;
    int *piVar7;
    int *local_28[6];
    int local_10;
    int local_c;
    int local_8;
    int local_4;
    int bVar2;

    if (*param_2 != 0) {
        iVar3 = FUN_0041E9D0(param_1, (int)param_2);
        if (iVar3 == 0) {
            bVar2 = 0;
            uVar4 = (unsigned int)*(unsigned short *)param_1[0x5d];
            if ((uVar4 == 2 || uVar4 == 0) &&
                (pGVar6 = param_1[0x5e], (*(int *)(pGVar6 + 0x6c) & 0x400000) != 0)) {
                FUN_0041FA80(0x4f);
                FUN_0041A340((int *)pGVar6, 0x7c);
                FUN_00433140((int *)pGVar6);
                param_1[0x1e] = *(int *)(pGVar6 + 0x78);
                param_1[0x1f] = *(int *)(pGVar6 + 0x7c) - 0x2d0000;

                iVar3 = FUN_0041CB80((int *)pGVar6, (int **)local_28);
                if (iVar3 != 0) {
                    param_1[0x1e] = local_10 + ((local_c - local_10) + 1) / 2;
                    param_1[0x1f] = local_8 + ((local_4 - local_8) + 1) / 2;
                }
                param_1[0x17] = (int)&FUN_00432D40;
                param_1[0x15] = 0;
                param_1[0x32] = 0x10000;
                param_1[0x33] = 0x10000;
                param_1[0x31] = 0;
                param_1[0x18] = (int)&FUN_00432F30;
                param_1[0x19] = (int)&FUN_00432FA0;
                bVar2 = 1;
                param_1[0x30] = 0;
                param_1[0x27] = 1;
                param_1[0x28] = pGVar6;
                param_1[0x14] = 0x21;
                param_1[0x2f] = (int)0x90c090c1;
                param_1[0x26] = 0x78;
                {
                    int pGVar1 = *(int *)(pGVar6 + 0x160);
                    if (*(int *)(pGVar6 + 8) != 0x25) {
                        while (pGVar1 != 0) {
                            pGVar6 = pGVar1;
                            pGVar1 = *(int *)(pGVar6 + 0x160);
                        }
                    }
                    FUN_00419BE0(param_1, (void *)pGVar6);
                }
                FUN_0041E880(param_1, (int *)3);
            }
            piVar7 = (int *)0x45b32c;
            do {
                ppGVar5 = (int *)FUN_004195D0(0x5c, param_1[0x1e] + piVar7[-1], param_1[0x1f] + *piVar7, (int)FUN_004A2AD4);
                if (ppGVar5 != 0) {
                    ppGVar5[0x1b] = ppGVar5[0x1b] | 0xc000;
                    ppGVar5[0x21] = 0x7fff0000;
                    ppGVar5[0x20] = piVar7[1];
                    ppGVar5[0x24] = 0x7fff0000;
                    ppGVar5[0x23] = piVar7[2];
                    ppGVar5[0x14] = 0x20;
                    ppGVar5[0x26] = 3;
                    ppGVar5[0x1c] = 0x30;
                    FUN_00419BE0(ppGVar5, param_1);
                }
                piVar7 = piVar7 + 4;
            } while ((int)piVar7 < 0x45b3ac);

            if (!bVar2) {
                FUN_00419520(param_1);
            }
        }
    }
}
}
