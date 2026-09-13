// Adapted from pc_decomp_backup/src/functions/FUN_00412DE0.cpp
// Historical source SHA256: 745bc8bc52ff9e335d4a2044af021326e9ba308132c4214ca186727e740451f5
extern "C" {
extern "C" void __cdecl FUN_00423800_pStateUnk(void**);
extern "C" int __cdecl FUN_00412a00_CheckInput(int);
extern "C" void __cdecl FUN_004144E0(void**);
extern "C" void __cdecl FUN_00413BA0(void**);
extern "C" void __cdecl FUN_00421900(void**);
extern "C" void __cdecl FUN_00426CA0(void**);
extern "C" { extern int DAT_00458C78; }
extern "C" { extern int DAT_00462E80; }
extern "C" { extern int DAT_004A022C; }
extern int FUN_004A284C;
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" void __cdecl GEX_Target(void** param1) {
    FUN_00423800_pStateUnk(param1);
    if ((DAT_00458C78 != 0) || (DAT_004A0294 != 0)) {
        param1[0x31] = (void*)((unsigned int)((int)param1[0x31] + 0x1000) & 0xc00000);
        param1[0x31] = (void*)FUN_00412a00_CheckInput((int)param1);
        FUN_004144E0(param1);
        return;
    }
    if ((DAT_004A0293 != 0) && (DAT_004A0295 == 0)) {
        param1[0x31] = (void*)((unsigned int)((int)param1[0x31] + 0x1000) & 0xc00000);
        param1[0x31] = (void*)FUN_00412a00_CheckInput((int)param1);
        FUN_00413BA0(param1);
        return;
    }
    FUN_004A284C = 1;
    param1[0x31] = (void*)DAT_00462E80;
    void* pGVar1 = param1[0x26];
    void* pGVar2 = (void*)((int)pGVar1 + 0x40);
    param1[0x26] = pGVar2;
    if ((int)pGVar2 > 0xffff) {
        param1[0x26] = (void*)((int)pGVar1 + -0x40);
        pGVar1 = (void*)((int)param1[0x15] + 1);
        param1[0x15] = pGVar1;
        if ((int)pGVar1 < 8) FUN_00421900(param1);
        else FUN_00426CA0(param1);
    }
    DAT_004A022C = 1;
}
}
