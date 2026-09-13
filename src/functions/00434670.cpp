// Adapted from pc_decomp_backup/src/functions/FUN_00434670.cpp
// Historical source SHA256: 7b21edcb5a3e371644a5019d6519f3f042a435e680509541f5d0f9baae462954
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
extern "C" { extern int DAT_004642A4; }
extern "C" { extern unsigned char DAT_004A02A8; }
extern "C" void __cdecl FUN_00441150(void**);
extern "C" void __cdecl FUN_00444590(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int pGVar1;
    unsigned int uVar2, uVar8;
    int iVar3;
    int pGVar6, pGVar7;

    pGVar1 = (int)DAT_004642A4 + 0x10000;
    if (pGVar1 > 0xffffff) pGVar1 = (int)DAT_004642A4 - 0xff0000;
    DAT_004642A4 = pGVar1;
    uVar2 = (unsigned int)DAT_004642A4 & 0xffff0000;
    uVar8 = (unsigned int)DAT_004642A4 >> 0x10;
    
    
    if ((int)uVar2 < 0) {
        if ((int)uVar2 < -0x1000000) {
            int neg = (int)(-uVar8) >> 0x1f;
            iVar3 = (((-uVar8 ^ neg) - neg & 0xff ^ neg) - neg);
            if (iVar3 < 0x81) {
                if (iVar3 < 0x41) iVar3 = DAT_0045A5C8[iVar3];
                else iVar3 = DAT_0045A7C8[-iVar3];
            } else if (iVar3 + -0x80 < 0x41) iVar3 = -DAT_0045A3C8[iVar3 + 1];
            else iVar3 = -DAT_0045A9C8[-iVar3];
        } else if ((int)uVar2 < -0x800000) {
            if ((-0x80 - uVar8) < 0x41) iVar3 = -DAT_0045A3C8[-uVar8 + 1];
            else iVar3 = -DAT_0045A9C8[uVar8];
        } else {
            if ((int)uVar2 > -0x400001) iVar3 = DAT_0045A5C8[-uVar8];
            else iVar3 = DAT_0045A7C8[uVar8];
        }
        iVar3 = -iVar3;
    } else if ((int)uVar2 < 0x1000001) {
        if ((int)uVar2 > 0x800000) {
            if ((uVar8 - 0x80) < 0x41) iVar3 = DAT_0045A3C8[uVar8 + 1];
            else iVar3 = DAT_0045A9C8[-uVar8];
            iVar3 = -iVar3;
        } else {
            if ((int)uVar2 < 0x400001) iVar3 = DAT_0045A5C8[uVar8];
            else iVar3 = DAT_0045A7C8[-uVar8];
        }
    } else {
        int sign = (int)DAT_004642A4 >> 0x1f;
        iVar3 = (((uVar8 ^ sign) - sign & 0xff ^ sign) - sign);
        if (iVar3 < 0x81) {
            if (iVar3 < 0x41) iVar3 = DAT_0045A5C8[iVar3];
            else iVar3 = DAT_0045A7C8[-iVar3];
        } else {
            if (iVar3 + -0x80 < 0x41) iVar3 = -DAT_0045A3C8[iVar3 + 1];
            else iVar3 = -DAT_0045A9C8[-iVar3];
        }
    }
    
    pGVar6 = iVar3 * 5;
    if (pGVar6 < 0) pGVar6 = iVar3 * -5;
    
    if (DAT_004A02A8 != 0) {
        param_1[0x32] = (void*)pGVar7;
        param_1[0x31] = (void*)pGVar1;
        param_1[0x33] = (void*)pGVar6;
        FUN_00441150(param_1);
        return;
    }
    param_1[0x33] = (void*)0x10000;
    param_1[0x32] = (void*)0x10000;
    param_1[0x31] = 0;
    FUN_00444590(param_1);
}
}
