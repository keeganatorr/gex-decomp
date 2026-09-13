// Adapted from pc_decomp_backup/src/functions/FUN_00426FC0.cpp
// Historical source SHA256: 87d585ba59fbc83d9fcc9eeb5307c359615a33d3661d1d2f1d3cd8e8e59abb0a
extern "C" {
extern "C" void __cdecl FUN_00424AA0(void**);
extern "C" int __cdecl FUN_00424980_CheckGexInputs(void**);
extern "C" void __cdecl FUN_00426F60(void**);
extern "C" void __cdecl FUN_004213f0_GexMovementLeftandRight(void*);
extern "C" void __cdecl FUN_004213c0(int, void**);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_004252B0(void**);
extern "C" void __cdecl FUN_0042CEC0(int, void**, void*, int);
extern "C" void __cdecl FUN_00424090(void**);
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int DAT_00463ABC; }
extern "C" void __cdecl GEX_Target(void** param1) {
    unsigned int flags = (unsigned int)param1[0x1b];
    if ((flags & 0x80000000) != 0) {
        FUN_00424AA0(param1);
        return;
    }
    int iVar1 = FUN_00424980_CheckGexInputs(param1);
    if (iVar1 == 0) {
        param1[0x26] = (void*)((int)param1[0x26] + 1);
        if (1 < (int)param1[0x26]) {
            param1[0x26] = 0;
            param1[0x15] = (void*)((int)param1[0x15] + 1);
            if (param1[0x15] == (void*)2) {
                FUN_00426F60(param1);
                return;
            }
        }
        FUN_004213f0_GexMovementLeftandRight((void*)param1);
        FUN_004213c0(FUN_004A2990, param1);
        iVar1 = FUN_00421560_DrawCharacter(FUN_004A2990, param1);
        if (iVar1 == 0) {
            FUN_004252B0(param1);
            return;
        }
        DAT_00463ABC = 0;
        FUN_0042CEC0(FUN_004A2990, param1, 0, -0x180000);
        if (DAT_00463ABC != 0) FUN_00424090(param1);
    }
}
}
