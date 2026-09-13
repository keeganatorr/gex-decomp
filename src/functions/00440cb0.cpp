// Adapted from pc_decomp_backup/src/functions/FUN_00440CB0.cpp
// Historical source SHA256: 7200d35b2c53ef466a7bbf490b7363c860679cd50c6c0b565f90d62b996cba38
extern "C" {
extern "C" { extern short DAT_004A0270; }
extern "C" { extern short DAT_004A0272; }

extern "C" void __cdecl FUN_0043DC70(char*, short, short, unsigned int,
                                         unsigned int, unsigned int, short, short);

extern "C" void __cdecl GEX_Target(int *param_1, unsigned int param_2, unsigned int param_3)
{
    int *piVar1;
    int *puVar2;
    void *Image;
    unsigned int uVar3;
    unsigned int uVar4;
    int iVar5;
    unsigned int uVar6;
    int iVar7;
    unsigned int uVar8;
    int iVar9;
    int iVar10;
    int *local_10;

    if (((param_1[3] | param_1[2]) & 0x80000000) == 0) {
        piVar1 = *(int **)(*(int *)param_1[1] + param_1[2] * 4);
        iVar9 = piVar1[param_1[3]];
        if (iVar9 == 0) {
            iVar9 = *piVar1;
            param_1[3] = 0;
        }
        local_10 = *(int **)(iVar9 + 0x18);
        puVar2 = (int *)*local_10;
        while (puVar2 != 0) {
            local_10 = local_10 + 1;
            Image = (void *)puVar2[2];
            uVar3 = puVar2[1];
            iVar9 = *(int *)Image;
            uVar4 = *param_1;
            iVar5 = *(int *)((char *)Image + 4);
            if (*(int *)((char *)Image + 0x14) != 0) {
                uVar6 = *puVar2;
                if ((uVar3 & 0x80000000) == 0) {
                    iVar10 = *(int *)((char *)Image + 8);
                } else {
                    iVar10 = iVar9 - *(int *)((char *)Image + 8);
                }
                if ((uVar4 & 0x80000000) == 0) {
                    iVar10 = iVar10 + (uVar6 & 0xffff0000) + (param_2 & 0xffff0000);
                } else {
                    iVar10 = ((param_2 & 0xffff0000) - iVar10) - (uVar6 & 0xffff0000);
                }
                uVar8 = uVar4 ^ uVar3;
                if ((uVar8 & 0x80000000) == 0) {
                    iVar7 = iVar10;
                    if (iVar9 + iVar10 >= 0) goto LAB_0x00440dc4;
                } else if (iVar10 >= 0) {
                    iVar7 = iVar10 - iVar9;
LAB_0x00440dc4:
                    if (iVar7 < 0x1400000) {
                        if ((uVar3 & 0x40000000) == 0) {
                            iVar9 = *(int *)((char *)Image + 0xc);
                        } else {
                            iVar9 = iVar5 - *(int *)((char *)Image + 0xc);
                        }
                        if ((uVar4 & 0x40000000) == 0) {
                            iVar9 = iVar9 + uVar6 * 0x10000 + (param_3 & 0xffff0000);
                        } else {
                            iVar9 = ((param_3 & 0xffff0000) - iVar9) + (int)(-(int)(uVar6 * 0x10000));
                        }
                        if ((uVar8 & 0x40000000) == 0) {
                            iVar7 = iVar9;
                            if (iVar5 + iVar9 >= 0) goto LAB_0x00440e25;
                        } else if (iVar9 >= 0) {
                            iVar7 = iVar9 - iVar5;
LAB_0x00440e25:
                            if (iVar7 < 0xf00000) {
                                FUN_0043DC70((char*)Image,
                                             (short)((unsigned int)iVar10 >> 0x10),
                                             (short)((unsigned int)iVar9 >> 0x10),
                                             puVar2[3], puVar2[4], uVar8,
                                             DAT_004A0270, DAT_004A0272);
                            }
                        }
                    }
                }
            }
            puVar2 = (int *)*local_10;
        }
    }
}
}
