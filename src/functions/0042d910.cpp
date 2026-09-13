// Adapted from pc_decomp_backup/src/functions/FUN_0042D910.cpp
// Historical source SHA256: b71e238985398955237b8cb774e5074b5eead12947984d51b6700eab9a6196e0
extern "C" {
extern "C" { extern void** FUN_004A27FC; }
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int DAT_004a01e0; }
extern "C" { extern int DAT_004a01e8; }
extern "C" unsigned int __cdecl FUN_0042d5c0_JumpingAboveScreen(void**, int);
extern "C" int __cdecl FUN_0040F100(int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_0042cc70_Object_unk(int, void**);

extern "C" unsigned int __cdecl GEX_Target(void** gOb, int param_2) {
    unsigned int uVar1;
    int iVar2;
    unsigned int uVar3;

    if (gOb != FUN_004A27FC) {
        uVar1 = FUN_0042d5c0_JumpingAboveScreen(gOb, param_2);
        return uVar1;
    }
    uVar3 = (unsigned int)gOb[0x61] & 0x1fffff;
    if ((*(unsigned short*)(param_2 + 2) & 0xfff) == 0) {
        DAT_004a01e0 = DAT_004a01e0 + 1;
        if ((int)DAT_004a01e8 < 0) {
            DAT_004a01e8 = (unsigned int)gOb[0x62] & 0xffe00000;
        }
        gOb[0x1e] = (void*)((int)gOb[0x1e] - (int)uVar3);
        gOb[0x39] = (void*)((unsigned int)gOb[0x61] & 0xffe00000);
        if (gOb[0x3a] != (void*)0x0) {
            FUN_0042cc70_Object_unk(0, gOb);
        }
        return 1;
    }
    iVar2 = FUN_0040F100((int)FUN_004A2990, (unsigned int)*(unsigned short*)(param_2 + 2), uVar3);
    if (iVar2 != 0 && iVar2 + -0x10000 <= (int)((unsigned int)gOb[0x62] & 0x1fffff)) {
        DAT_004a01e0 = DAT_004a01e0 + 1;
        if ((int)DAT_004a01e8 < 0) {
            DAT_004a01e8 = (((unsigned int)gOb[0x62] & 0xffe00000) + iVar2) - 0x10000;
        }
        gOb[0x1e] = (void*)((int)gOb[0x1e] - (int)uVar3);
        gOb[0x39] = (void*)((unsigned int)gOb[0x61] & 0xffe00000);
        if (gOb[0x3a] != (void*)0x0) {
            FUN_0042cc70_Object_unk(0, gOb);
        }
        return 1;
    }
    return 0;
}
}
