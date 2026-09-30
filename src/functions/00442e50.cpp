// Adapted from pc_decomp_backup/src/functions/FUN_00442E50.cpp
// Historical source SHA256: c6396098f46628ffc911e46e811efaf1be28b54c2a0661eb23baa63fa543fd46
// Lookup bases and signs follow pinned instructions 00442eec, 004430ee,
// 0044310c, 0044311a and 00443135. The cosine paths include a quarter-turn
// offset already; using the sine-path bases there reads different table entries.
extern "C" {
extern "C" { extern int DAT_0045A2C8[]; }
extern "C" { extern int DAT_0045A3C8[]; }
extern "C" { extern int DAT_0045A4C8[]; }
extern "C" { extern int DAT_0045A5C8[]; }
extern "C" { extern int DAT_0045A6C8[]; }
extern "C" { extern int DAT_0045A7C8[]; }
extern "C" { extern int DAT_0045A8C8[]; }
extern "C" { extern int DAT_0045A9C8[]; }
extern "C" { extern int DAT_0045AAC8[]; }

extern "C" void __cdecl FUN_00442e50_GraphicsFlashingInner2(unsigned int* param_1, unsigned int* param_2, unsigned int param_3)
{
    unsigned int uVar1, uVar2, uVar5, uVar6, uVar7, uVar8, uVar9;
    unsigned int uVar11, uVar12, uVar19, uVar20;
    int iVar3, iVar13, iVar14, iVar15, iVar16, iVar17;
    int iVar9s;

    uVar2 = param_3 & 0xffff0000;
    iVar9s = (int)param_3 >> 16;

    if ((int)uVar2 < 0) {
        if ((int)uVar2 < -0x1000000) {
            uVar2 = (unsigned int)(-iVar9s) >> 31;
            iVar3 = (((int)(-iVar9s) ^ (int)uVar2) - (int)uVar2 & 0xff ^ (int)uVar2) - (int)uVar2;
            if (iVar3 < 0x81) {
                if (iVar3 < 0x41) {
                    iVar3 = DAT_0045A5C8[iVar3];
                } else {
                    iVar3 = DAT_0045A7C8[-iVar3];
                }
            } else if (iVar3 + -0x80 < 0x41) {
                iVar3 = -DAT_0045A3C8[iVar3];
            } else {
                iVar3 = -DAT_0045A9C8[-iVar3];
            }
FUN_00442FE6:
            uVar2 = -iVar3;
        } else if ((int)uVar2 < -0x800000) {
            if ((int)(-0x80 - iVar9s) < 0x41) {
                iVar3 = -DAT_0045A3C8[-iVar9s];
            } else {
                iVar3 = -DAT_0045A9C8[iVar9s];
            }
            goto FUN_00442FE6;
        } else {
            if (-0x400001 < (int)uVar2) {
                iVar3 = DAT_0045A5C8[-iVar9s];
            } else {
                iVar3 = DAT_0045A7C8[iVar9s];
            }
            goto FUN_00442FE6;
        }
    } else if ((int)uVar2 < 0x1000001) {
        if (0x800000 < (int)uVar2) {
            if ((int)(iVar9s - 0x80) < 0x41) {
                iVar3 = DAT_0045A3C8[iVar9s];
            } else {
                iVar3 = DAT_0045A9C8[-iVar9s];
            }
            goto FUN_00442FE6;
        }
        if ((int)uVar2 < 0x400001) {
            uVar2 = DAT_0045A5C8[iVar9s];
        } else {
            uVar2 = DAT_0045A7C8[-iVar9s];
        }
    } else {
        uVar2 = (int)param_3 >> 31;
        iVar3 = (((int)iVar9s ^ (int)uVar2) - (int)uVar2 & 0xff ^ (int)uVar2) - (int)uVar2;
        if (0x80 < iVar3) {
            if (iVar3 + -0x80 < 0x41) {
                iVar3 = DAT_0045A3C8[iVar3];
            } else {
                iVar3 = DAT_0045A9C8[-iVar3];
            }
            goto FUN_00442FE6;
        }
        if (iVar3 < 0x41) {
            uVar2 = DAT_0045A5C8[iVar3];
        } else {
            uVar2 = DAT_0045A7C8[-iVar3];
        }
    }

    
    uVar11 = (unsigned int)(iVar9s + 0x40);
    if ((int)uVar11 < 0) {
        if ((int)uVar11 < -0x100) {
            uVar11 = (unsigned int)(-iVar9s - 0x40) >> 31;
            iVar3 = (((int)(-iVar9s - 0x40) ^ (int)uVar11) - (int)uVar11 & 0xff ^ (int)uVar11) - (int)uVar11;
            if (iVar3 < 0x81) {
                if (0x40 < iVar3) {
                    uVar9 = DAT_0045A7C8[-iVar3];
                } else {
                    uVar9 = DAT_0045A5C8[iVar3];
                }
            } else if (iVar3 + -0x80 < 0x41) {
                uVar9 = -DAT_0045A3C8[iVar3];
            } else {
                uVar9 = -DAT_0045A9C8[-iVar3];
            }
        } else if ((int)uVar11 < -0x80) {
            if ((int)(-0xc0 - iVar9s) < 0x41) {
                uVar9 = -DAT_0045A2C8[-iVar9s];
            } else {
                uVar9 = -DAT_0045AAC8[iVar9s];
            }
        } else {
            if (-0x41 < (int)uVar11) {
                uVar9 = DAT_0045A4C8[-iVar9s];
            } else {
                uVar9 = DAT_0045A8C8[iVar9s];
            }
        }
        uVar9 = -uVar9;
    } else if ((int)uVar11 < 0x101) {
        if ((int)uVar11 < 0x81) {
            if ((int)uVar11 < 0x41) {
                uVar9 = DAT_0045A6C8[iVar9s];
            } else {
                uVar9 = DAT_0045A6C8[-iVar9s];
            }
        } else {
            if (0x40 < (int)(iVar9s - 0x40)) {
                uVar9 = -DAT_0045A8C8[-iVar9s];
            } else {
                uVar9 = -DAT_0045A4C8[iVar9s];
            }
        }
    } else {
        uVar11 = (unsigned int)(iVar9s + 0x40);
        uVar9 = (int)uVar11 >> 31;
        iVar3 = (((int)uVar11 ^ (int)uVar9) - (int)uVar9 & 0xff ^ (int)uVar9) - (int)uVar9;
        if (iVar3 < 0x81) {
            if (iVar3 < 0x41) {
                uVar9 = DAT_0045A5C8[iVar3];
            } else {
                uVar9 = DAT_0045A7C8[-iVar3];
            }
        } else {
            if (iVar3 + -0x80 < 0x41) {
                uVar9 = -(unsigned int)DAT_0045A3C8[iVar3];
            } else {
                uVar9 = -(unsigned int)DAT_0045A9C8[-iVar3];
            }
        }
    }

    
    uVar11 = *param_1;
    uVar5 = (uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f);
    uVar6 = (uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f);
    uVar12 = uVar6 & 0xffff;
    iVar13 = (int)(uVar12 + (uVar6 & 0xffff0000));
    iVar14 = (int)uVar5 >> 0x10;
    uVar5 = uVar5 & 0xffff;
    iVar3 = ((int)(uVar12 * uVar5) >> 0x10) + iVar13 * iVar14 + ((int)uVar6 >> 0x10) * (int)uVar5;
    if (0 < (int)uVar11 != 0 < (int)uVar9) {
        iVar3 = -iVar3;
    }
    uVar1 = *param_2;
    uVar7 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
    uVar8 = (uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f);
    uVar19 = uVar8 & 0xffff;
    iVar15 = (int)((uVar8 & 0xffff0000) + uVar19);
    uVar20 = uVar7 & 0xffff;
    iVar16 = (int)uVar7 >> 0x10;
    iVar17 = ((int)uVar8 >> 0x10) * (int)uVar20 + ((int)(uVar19 * uVar20) >> 0x10) + iVar15 * iVar16;
    if (0 < (int)uVar2 == 0 < (int)uVar1) {
        iVar17 = -iVar17;
    }
    iVar13 = ((int)(uVar12 * uVar20) >> 0x10) + iVar13 * iVar16 + ((int)uVar6 >> 0x10) * (int)uVar20;
    if (0 < (int)uVar1 != 0 < (int)uVar9) {
        iVar13 = -iVar13;
    }
    iVar14 = ((int)(uVar19 * uVar5) >> 0x10) + iVar15 * iVar14 + ((int)uVar8 >> 0x10) * (int)uVar5;
    if (0 < (int)uVar2 != 0 < (int)uVar11) {
        iVar14 = -iVar14;
    }
    *param_1 = (unsigned int)(iVar3 + iVar17);
    *param_2 = (unsigned int)(iVar13 + iVar14);
}
}
