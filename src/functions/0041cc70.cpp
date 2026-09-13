// Adapted from pc_decomp_backup/src/functions/FUN_0041CC70.cpp
// Historical source SHA256: 66a39be618b72a852fd039d0fcc9b5c8ae8401c55061e1df370d8873f47b83ee
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

extern "C" void __cdecl GEX_Target(int param_1, int param_2, int param_3, int param_4, int param_5, unsigned int param_6, int param_7, int param_8)
{
    unsigned int uVar1;
    int iVar2, iVar4, iVar8, iVar10;
    int local_8, local_4;

    uVar1 = param_6 & 0xffff0000;
    int uVar5 = (int)param_6 >> 0x10;
    
    if ((int)uVar1 < 0) {
        if ((int)uVar1 < -0x1000000) {
            int neg = (int)(-uVar5) >> 0x1f;
            iVar2 = (((-uVar5 ^ neg) - neg & 0xff ^ neg) - neg);
            if (iVar2 < 0x81) {
                if (iVar2 < 0x41) iVar2 = DAT_0045A5C8[iVar2];
                else iVar2 = DAT_0045A7C8[-iVar2];
            } else if (iVar2 + -0x80 < 0x41) iVar2 = -DAT_0045A3C8[iVar2 + 1];
            else iVar2 = -DAT_0045A9C8[-iVar2];
        } else if ((int)uVar1 < -0x800000) {
            if ((-0x80 - uVar5) < 0x41) iVar2 = -DAT_0045A3C8[-uVar5 + 1];
            else iVar2 = -DAT_0045A9C8[uVar5];
        } else {
            if ((int)uVar1 > -0x400001) iVar2 = DAT_0045A5C8[-uVar5];
            else iVar2 = DAT_0045A7C8[uVar5];
        }
        iVar2 = -iVar2;
    } else if ((int)uVar1 < 0x1000001) {
        if ((int)uVar1 > 0x800000) {
            if ((uVar5 - 0x80) < 0x41) iVar2 = DAT_0045A3C8[uVar5 + 1];
            else iVar2 = DAT_0045A9C8[-uVar5];
            iVar2 = -iVar2;
        } else {
            if ((int)uVar1 < 0x400001) iVar2 = DAT_0045A5C8[uVar5];
            else iVar2 = DAT_0045A7C8[-uVar5];
        }
    } else {
        int sign = (int)param_6 >> 0x1f;
        iVar2 = (((uVar5 ^ sign) - sign & 0xff ^ sign) - sign);
        if (iVar2 > 0x80) {
            if (iVar2 + -0x80 < 0x41) iVar2 = DAT_0045A3C8[iVar2 + 1];
            else iVar2 = DAT_0045A9C8[-iVar2];
            iVar2 = -iVar2;
        } else {
            if (iVar2 < 0x41) iVar2 = DAT_0045A5C8[iVar2];
            else iVar2 = DAT_0045A7C8[-iVar2];
        }
    }
    
    
    uVar1 = uVar5 + 0x40;
    if ((int)uVar1 < 0) {
        if ((int)uVar1 < -0x100) {
            int neg = (int)(-uVar5 - 0x40) >> 0x1f;
            iVar4 = (((-uVar5 - 0x40 ^ neg) - neg & 0xff ^ neg) - neg);
            if (iVar4 < 0x81) {
                if (iVar4 > 0x40) iVar4 = -DAT_0045A7C8[-iVar4];
                else iVar4 = DAT_0045A5C8[iVar4];
            } else if (iVar4 + -0x80 < 0x41) iVar4 = -DAT_0045A3C8[iVar4 + 1];
            else iVar4 = -DAT_0045A9C8[-iVar4];
        } else if ((int)uVar1 < -0x80) {
            if ((-0xc0 - uVar5) < 0x41) iVar4 = -DAT_0045A3C8[-uVar5 + 1];
            else iVar4 = -DAT_0045A9C8[uVar5];
        } else {
            if ((int)uVar1 > -0x41) iVar4 = DAT_0045A5C8[-uVar5];
            else iVar4 = DAT_0045A7C8[uVar5];
        }
    } else if ((int)uVar1 < 0x101) {
        if ((int)uVar1 > 0x80) {
            if ((uVar5 - 0x40) < 0x41) iVar4 = DAT_0045A3C8[uVar5 + 1];
            else iVar4 = DAT_0045A9C8[-uVar5];
        } else {
            if ((int)uVar1 < 0x41) iVar4 = DAT_0045A5C8[uVar5];
            else iVar4 = DAT_0045A7C8[-uVar5];
        }
    } else {
        int sign = (int)(uVar5 + 0x40) >> 0x1f;
        iVar4 = (((uVar5 + 0x40 ^ sign) - sign & 0xff ^ sign) - sign);
        if (iVar4 > 0x80) {
            if (iVar4 + -0x80 < 0x41) iVar4 = DAT_0045A3C8[iVar4 + 1];
            else iVar4 = -DAT_0045A9C8[-iVar4];
        } else {
            if (iVar4 < 0x41) iVar4 = DAT_0045A5C8[iVar4];
            else iVar4 = DAT_0045A7C8[-iVar4];
        }
    }
    
    { int _cnt = 4;
    int* piVar7 = (int*)(param_1 + 4);
    int* local_8 = (int*)(param_1 + 0x24);
    do {
        iVar10 = (piVar7[0] >> 8) * param_7 >> 8;
        iVar8 = (piVar7[1] >> 8) * param_8 >> 8;
        local_8[0] = ((iVar10 * (iVar4 >> 8) >> 8) - (iVar8 * (iVar2 >> 8) >> 8)) + param_4;
        local_8[1] = (iVar8 * (iVar4 >> 8) >> 8) + (iVar10 * (iVar2 >> 8) >> 8) + param_5;
        piVar7[0] = piVar7[0] + param_2;
        _cnt--;
        piVar7[1] = piVar7[1] + param_3;
        piVar7 += 2;
        local_8 += 2;
    } while (_cnt != 0);
    }
}
}
