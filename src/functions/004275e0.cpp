// Adapted from pc_decomp_backup/src/functions/FUN_004275E0.cpp
// Historical source SHA256: 00795aa7517d2bb77475e0b5a72cc687fc5f5f73ea48a6fbab5d0d8855c3a6c4
extern "C" {
extern "C" void __cdecl FUN_00424B80(void**);
extern "C" void __cdecl FUN_00427B80(void**);
extern "C" void __cdecl FUN_00421900(void**);
extern "C" void __cdecl FUN_004275A0(void**, int);
extern "C" void __cdecl FUN_004213f0_GexMovementLeftandRight(void*);
extern "C" void __cdecl FUN_004213c0(int, void**);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_004250B0(void**);
extern "C" void __cdecl FUN_00425AF0(void**);
extern "C" void __cdecl FUN_00424AA0(void**);
extern "C" void __cdecl FUN_00424090(void**);
extern int FUN_004A284C;
extern int FUN_004A2990;
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" void __cdecl GEX_Target(void** param1) {
    if ((DAT_004A0294 != 0) && (DAT_004A0295 == 0)) { FUN_00424B80(param1); return; }
    if ((DAT_004A0293 != 0) && (DAT_004A0295 == 0)) { FUN_00427B80(param1); return; }
    FUN_004A284C = 1;
    void* pGVar1 = (void*)((int)param1[0x26] + 1);
    param1[0x26] = pGVar1;
    if ((int)pGVar1 > 0) {
        param1[0x26] = 0;
        pGVar1 = (void*)((int)param1[0x15] + 1);
        param1[0x15] = pGVar1;
        if ((int)pGVar1 > 10) {
            if (param1[0x29] != 0) { FUN_00424AA0(param1); return; }
            FUN_00424090(param1); return;
        }
        FUN_00421900(param1);
    }
    FUN_004275A0(param1, 0x8000);
    FUN_004213f0_GexMovementLeftandRight(param1);
    FUN_004213c0(FUN_004A2990, param1);
    int iVar2 = FUN_00421560_DrawCharacter(FUN_004A2990, param1);
    if (iVar2 == 0) {
        if ((int)param1[0x15] > 2) { FUN_004250B0(param1); return; }
        FUN_00425AF0(param1);
    }
}
}
