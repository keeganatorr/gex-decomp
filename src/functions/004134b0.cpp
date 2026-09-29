// Adapted from pc_decomp_backup/src/functions/FUN_004134B0.cpp
// Historical source SHA256: eb34b6188cc63d77e07e44f2dd50091ba1f510a2ac241560e106145e0d4b2f29
extern "C" {
extern "C" void __cdecl FUN_004138B0(void**);
extern "C" void __cdecl FUN_00412960(void**);
extern "C" int __cdecl FUN_00421f90(void**);
extern "C" int __cdecl FUN_00421f20_pStateUnk_Side(void**);
extern "C" void __cdecl FUN_00421cd0_xpos_ypos_related(void**);
extern "C" void __cdecl FUN_00421900(void**);
extern "C" void __cdecl FUN_00411160(void**);
extern "C" { extern int DAT_00458C78; }
extern "C" { extern int DAT_004A284C; }
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" void __cdecl PlayerSideSlap_004134b0(void** param1) {
    if (DAT_00458C78 != 0) { FUN_004138B0(param1); return; }
    if ((DAT_004A0294 != 0) || (FUN_00421f90(param1) == 0)) { FUN_004138B0(param1); return; }
    if ((DAT_004A0293 != 0) && (DAT_004A0295 == 0)) {
        FUN_00412960(param1); return;
    }
    DAT_004A284C = 1;
    int iVar2 = FUN_00421f20_pStateUnk_Side(param1);
    if (iVar2 == 0) return;
    FUN_00421cd0_xpos_ypos_related(param1);
    void* pGVar1 = param1[0x26];
    void* pGVar3 = (void*)((int)pGVar1 + 0x40);
    param1[0x26] = pGVar3;
    if ((int)pGVar3 < 0x10000) return;
    param1[0x26] = (void*)((int)pGVar1 + -0x40);
    if ((param1[0x27] == 0) || (param1[0x15] != 0))
        param1[0x15] = (void*)((int)param1[0x15] + 1);
    else
        param1[0x15] = (void*)3;
    if ((int)param1[0x15] < 5) { FUN_00421900(param1); return; }
    FUN_00411160(param1);
}
}
