extern "C" {
int FUN_0041CB80(int *param_1, int *local_28);
int FUN_0041A0A0(int *param_1, int iVar2);
int FUN_00421560_DrawCharacter(int level, int *param_1);
extern int DAT_004a025c;
extern int DAT_004a0218_pState;
extern int DAT_004a23c8;
extern int FUN_004A2990;

int __cdecl GEX_Target(int *param_1)
{
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int local_28[10];
    int pGVar1;

    pGVar1 = param_1[0x31];
    iVar5 = 0;
    param_1[0x31] = 0;
    iVar2 = FUN_0041CB80(param_1, local_28);
    if (iVar2 != 0) {
        iVar5 = local_28[9] - param_1[0x1f];
    }
    param_1[0x31] = pGVar1;
    iVar4 = -0x60000;
    iVar2 = param_1[0x36] + (DAT_004a025c - param_1[0x1f]);
    DAT_004a025c = iVar5;
    if (iVar2 < iVar5) {
        iVar4 = 0x60000;
    }
    do {
        iVar2 += iVar4;
        if (iVar4 > 0) {
            if (iVar2 > iVar5) iVar2 = iVar5;
        }
        else {
            if (iVar2 < iVar5) iVar2 = iVar5;
        }
        iVar3 = FUN_0041A0A0(param_1, iVar2);
        if (iVar3 != 0) {
            param_1[0x1f] = param_1[0x1f] + iVar2;
            if (param_1[0x23] >= 0) {
                FUN_00421560_DrawCharacter(FUN_004A2990, param_1);
            }
            break;
        }
        if (iVar2 == iVar5) {
            break;
        }
    } while (1);
    if (iVar3 != 0) {
        DAT_004a0218_pState = 0x81;
        DAT_004a23c8 = 0;
    }
    return iVar3;
}
}
