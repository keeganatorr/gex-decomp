// Adapted from pc_decomp_backup/src/functions/FUN_004391D0.cpp
// Historical source SHA256: 05b0c3e5fbbc3ab031bb66b583548571b88a3d138276ec972bcb37677512c417
extern "C" {
extern "C" { extern int DAT_0045A3C8[]; }
extern "C" { extern int DAT_0045A5C8[]; }
extern "C" { extern int DAT_0045A7C8[]; }
extern "C" { extern int DAT_0045A9C8[]; }

extern "C" int __cdecl GEX_Target(int param_1, int param_2, int param_3)
{
    int iVar2;
    unsigned int uVar1;
    int iVar4;

    iVar2 = param_2 - param_1;
    uVar1 = ((param_3 - param_1) * 0x80) / iVar2;

    if ((int)uVar1 < 0) {
        if ((int)uVar1 > -0x101) {
            if ((int)uVar1 > -0x81) {
                if ((int)uVar1 < -0x40) {
                    return -DAT_0045A7C8[(int)uVar1];
                }
                return -DAT_0045A5C8[((param_1 - param_3) * 0x80) / iVar2];
            }
            iVar4 = ((param_1 - param_3) * 0x80) / iVar2;
            if (iVar4 + -0x80 > 0x40) {
                return DAT_0045A9C8[(int)uVar1];
            }
            return DAT_0045A3C8[iVar4];
        }
        uVar1 = ((param_1 - param_3) * 0x80) / iVar2;
        iVar4 = ((int)uVar1 >> 0x1f);
        iVar4 = (((uVar1 ^ (unsigned int)iVar4) - (unsigned int)iVar4) & 0xff ^ (unsigned int)iVar4) - (unsigned int)iVar4;
        if (iVar4 < 0x81) {
            if (iVar4 > 0x40) {
                return -DAT_0045A7C8[-iVar4];
            }
            return -DAT_0045A5C8[iVar4];
        }
        if (iVar4 + -0x80 > 0x40) {
            return DAT_0045A9C8[-iVar4];
        }
        return DAT_0045A3C8[iVar4];
    }

    if ((int)uVar1 < 0x101) {
        if ((int)uVar1 < 0x81) {
            if ((int)uVar1 > 0x40) {
                return DAT_0045A7C8[((param_1 - param_3) * 0x80) / iVar2];
            }
            return DAT_0045A5C8[(int)uVar1];
        }
        if ((int)(uVar1 - 0x80) > 0x40) {
            return -DAT_0045A9C8[((param_1 - param_3) * 0x80) / iVar2];
        }
        return -DAT_0045A3C8[(int)uVar1];
    }

    iVar4 = ((int)uVar1 >> 0x1f);
    iVar4 = (((uVar1 ^ (unsigned int)iVar4) - (unsigned int)iVar4) & 0xff ^ (unsigned int)iVar4) - (unsigned int)iVar4;
    if (iVar4 < 0x81) {
        if (iVar4 > 0x40) {
            return DAT_0045A7C8[-iVar4];
        }
        return DAT_0045A5C8[iVar4];
    }
    if (iVar4 + -0x80 > 0x40) {
        return -DAT_0045A9C8[-iVar4];
    }
    return -DAT_0045A3C8[iVar4];
}
}
