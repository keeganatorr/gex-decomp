// Adapted from pc_decomp_backup/src/functions/FUN_004215D0.cpp
// Historical source SHA256: 71ffc446c28ed6adfabf9a2d1ea654715bfad2af08600411b841e06dc2aa1d2e
extern "C" {
extern "C" int __cdecl FUN_0041CB80(void**, int*);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" int __cdecl FUN_0041A0A0(void**, int);
extern "C" { extern int DAT_004a025c; }
extern "C" { extern int DAT_004a0218_pState; }
extern "C" { extern int DAT_004a23c8; }
extern int FUN_004A2990;
extern "C" int __cdecl GEX_Target(void** param1) {
    int iVar5 = 0;
    void* pGVar1 = param1[0x31];
    param1[0x31] = 0;
    int local_28[9];
    int local_4;
    int iVar2 = FUN_0041CB80(param1, local_28);
    if (iVar2 != 0) iVar5 = local_4 - (int)param1[0x1f];
    param1[0x31] = pGVar1;
    int iVar4 = -0x60000;
    iVar2 = (int)param1[0x36] + (DAT_004a025c - (int)param1[0x1f]);
    DAT_004a025c = iVar5;
    if (iVar2 < iVar5) iVar4 = 0x60000;
    while (1) {
        iVar2 += iVar4;
        if (iVar4 < 1) { if (iVar2 < iVar5) iVar2 = iVar5; }
        else if (iVar5 < iVar2) iVar2 = iVar5;
        int iVar3 = FUN_0041A0A0(param1, iVar2);
        if (iVar3 != 0) {
            param1[0x1f] = (void*)((int)param1[0x1f] + iVar2 + -0x1c);
            if ((int)param1[0x23] >= 0) FUN_00421560_DrawCharacter(FUN_004A2990, param1);
            if (iVar3 != 0) { DAT_004a0218_pState = 0x81; DAT_004a23c8 = 0; }
            return iVar3;
        }
        if (iVar2 == iVar5) {
            if (iVar3 != 0) { DAT_004a0218_pState = 0x81; DAT_004a23c8 = 0; }
            return iVar3;
        }
    }
}
}
