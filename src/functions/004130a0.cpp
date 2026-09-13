// Adapted from pc_decomp_backup/src/functions/FUN_004130A0.cpp
// Historical source SHA256: 641b33c8c9668dea50bff57f743ab4f64e579a042cf02c813ab0a949df986621
extern "C" {
extern "C" void __cdecl FUN_004138B0(void**);
extern "C" void __cdecl FUN_00412960(void**);
extern "C" int __cdecl FUN_00421f20_pStateUnk_Side(void**);
extern "C" int __cdecl FUN_00421f90(void**);
extern "C" void __cdecl FUN_00421900(void**);
extern "C" void __cdecl FUN_00421cd0_xpos_ypos_related(void**);
extern "C" void __cdecl FUN_00413350(void**);
extern "C" { extern int DAT_00458c78; }
extern "C" { extern int DAT_004a284c; }
extern "C" void __cdecl GEX_Target(void** param1) {
    if (DAT_00458c78 != 0) { FUN_004138B0(param1); return; }
    int iVar1 = FUN_00421f90(param1);
    if (iVar1 == 0) { FUN_004138B0(param1); return; }
    DAT_004a284c = 1;
    iVar1 = FUN_00421f20_pStateUnk_Side(param1);
    if (iVar1 == 0) return;
    FUN_00421cd0_xpos_ypos_related(param1);
    int v26 = (int)param1[0x26];
    param1[0x26] = (void*)(v26 + 0x40);
    if ((int)param1[0x26] < 0x10000) return;
    param1[0x26] = (void*)(v26 - 0x40);
    param1[0x15] = (void*)((int)param1[0x15] + 1);
    if ((int)param1[0x15] < 3) { FUN_00421900(param1); return; }
    FUN_00413350(param1);
}
}
