// Adapted from pc_decomp_backup/src/functions/FUN_00419C00.cpp
// Historical source SHA256: f0061627d38946f3d6b4a9921050c57a54af98bf9af461a7b434aa7cdaac8f1c
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
extern "C" void** __cdecl FUN_0041A380(void**);

extern "C" int __cdecl GEX_Target(void** param_1, int param_2, int param_3, int* param_4, int* param_5)
{
    void** ppGVar2;
    int pGVar1;
    int pNVar7, pNVar11;
    unsigned int uVar3, uVar8;
    int iVar4;

    ppGVar2 = FUN_0041A380(param_1);
    if (ppGVar2 == 0) return 0;
    
    pGVar1 = (int)ppGVar2[5];
    if ((pGVar1 == 0) || (*(int*)(pGVar1 + 4) < param_2) ||
        (*(int*)(pGVar1 + 8 + param_2 * 8) == 0) ||
        (*(int*)(*(int*)(pGVar1 + 8 + param_2 * 8) + 4) <= param_3)) return 0;
    
    pNVar7 = *(int*)(*(int*)(pGVar1 + 8 + param_2 * 8) + 8 + param_3 * 8);
    pNVar11 = *(int*)(*(int*)(pGVar1 + 8 + param_2 * 8) + 12 + param_3 * 8);
    
    if ((unsigned int)param_1[0x1b] & 0x80000000) pNVar7 = -pNVar7;
    if ((unsigned int)param_1[0x1b] & 0x40000000) pNVar11 = -pNVar11;
    if (param_1[0x32] != (void*)0x10000) pNVar7 = (pNVar7 >> 0x10) * (int)param_1[0x32];
    if (param_1[0x33] != (void*)0x10000) pNVar11 = (pNVar11 >> 0x10) * (int)param_1[0x33];
    
    if (param_1[0x31] == 0) {
        *param_4 = pNVar7;
        *param_5 = pNVar11;
        return 1;
    }
    
    
    uVar3 = (unsigned int)param_1[0x31] & 0xffff0000;
    uVar8 = (int)param_1[0x31] >> 0x10;
    
    if ((int)uVar3 < 0) {
        if ((int)uVar3 < -0x1000000) {
            int neg = (int)(-uVar8) >> 0x1f;
            iVar4 = (((-uVar8 ^ neg) - neg & 0xff ^ neg) - neg);
            if (iVar4 < 0x81) {
                if (iVar4 < 0x41) iVar4 = DAT_0045A5C8[iVar4];
                else iVar4 = DAT_0045A7C8[-iVar4];
            } else if (iVar4 + -0x80 < 0x41) iVar4 = -DAT_0045A3C8[iVar4 + 1];
            else iVar4 = -DAT_0045A9C8[-iVar4];
        } else if ((int)uVar3 < -0x800000) {
            if ((-0x80 - uVar8) < 0x41) iVar4 = -DAT_0045A3C8[-uVar8 + 1];
            else iVar4 = -DAT_0045A9C8[uVar8];
        } else {
            if ((int)uVar3 > -0x400001) iVar4 = DAT_0045A5C8[-uVar8];
            else iVar4 = DAT_0045A7C8[uVar8];
        }
        iVar4 = -iVar4;
    } else if ((int)uVar3 < 0x1000001) {
        if ((int)uVar3 > 0x800000) {
            if ((uVar8 - 0x80) < 0x41) iVar4 = DAT_0045A3C8[uVar8 + 1];
            else iVar4 = DAT_0045A9C8[-uVar8];
            iVar4 = -iVar4;
        } else {
            if ((int)uVar3 < 0x400001) iVar4 = DAT_0045A5C8[uVar8];
            else iVar4 = DAT_0045A7C8[-uVar8];
        }
    } else {
        int sign = (int)param_1[0x31] >> 0x1f;
        iVar4 = (((uVar8 ^ sign) - sign & 0xff ^ sign) - sign);
        if (iVar4 < 0x81) {
            if (iVar4 < 0x41) iVar4 = DAT_0045A5C8[iVar4];
            else iVar4 = DAT_0045A7C8[-iVar4];
        } else if (iVar4 + -0x80 < 0x41) iVar4 = -DAT_0045A3C8[iVar4 + 1];
        else iVar4 = -DAT_0045A9C8[-iVar4];
        iVar4 = -iVar4;
    }
    
    
    *param_4 = (pNVar7 * (iVar4 >> 8) >> 8) - (pNVar11 * ((int)(uVar8 + 0x40) >> 8) >> 8);
    *param_5 = (pNVar11 * (iVar4 >> 8) >> 8) + (pNVar7 * ((int)(uVar8 + 0x40) >> 8) >> 8);
    return 1;
}
}
