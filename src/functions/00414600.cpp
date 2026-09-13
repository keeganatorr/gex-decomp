// Adapted from pc_decomp_backup/src/functions/FUN_00414600.cpp
// Historical source SHA256: 55291ad4caf5008477bac8cbf269abb3b25b6fcd3dbbfdf55a22c0c6a7ce0765
extern "C" {
extern "C" { extern int DAT_004a0220; }
extern "C" { extern unsigned char DAT_004a0282; }
extern "C" { extern unsigned char DAT_004a0293; }
extern "C" { extern unsigned char DAT_004a0294; }
extern "C" { extern unsigned char DAT_004a0295; }
extern "C" { extern int FUN_004A2990; }
extern "C" void __cdecl FUN_00424090(void**);
extern "C" void __cdecl FUN_00427760(void**);
extern "C" void __cdecl FUN_00424B80(void**);
extern "C" void __cdecl FUN_00414890(void**);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_004250B0(void**);
extern "C" void __cdecl FUN_004213f0_GexMovementLeftandRight(void*);
extern "C" void __cdecl FUN_004213c0(int, void**);

extern "C" void __cdecl GEX_Target(void** param1) {
    if (DAT_004a0220 == 0) {
        DAT_004a0220 = 1;
        if (DAT_004a0282 == 0) {
            FUN_00424090(param1);
            return;
        }
        if (DAT_004a0295 != 0) {
            FUN_00427760(param1);
            return;
        }
        if (DAT_004a0294 != 0) {
            FUN_00424B80(param1);
            return;
        }
        if (DAT_004a0293 != 0) {
            FUN_00414890(param1);
            return;
        }
        if (FUN_00421560_DrawCharacter(FUN_004A2990, param1) == 0) {
            FUN_004250B0(param1);
            return;
        }
    }
    if ((int)param1[0x26] == 3) {
        param1[0x15] = (void*)1;
    } else {
        param1[0x26] = (void*)((int)param1[0x26] + 1);
    }
    FUN_004213f0_GexMovementLeftandRight((void*)param1);
    FUN_004213c0(FUN_004A2990, param1);
}
}
