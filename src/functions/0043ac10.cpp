// Adapted from pc_decomp_backup/src/functions/FUN_0043AC10.cpp
// Historical source SHA256: a6a227eadc242a92bc340b9f419db3c700912a48b05a77dc42c9f1b0d4bbdb97
extern "C" {
extern "C" { extern int DAT_004593bc; }
extern "C" { extern int FUN_004593C0; }
extern "C" { extern int DAT_004593c4; }
extern "C" { extern int DAT_004593c8; }

extern "C" void __cdecl FUN_0043ac10_ResetTotalHit(void* param_1, int param_2)
{
    if (param_2 != 0) {
        DAT_004593bc = 0;
        FUN_004593C0 = 0;
        DAT_004593c4 = 0;
        DAT_004593c8 = 0;
        return;
    }
    DAT_004593bc = *(int*)((char*)param_1 + 0x98);
    *(int*)((char*)param_1 + 0x9c) = 0x1e;
    *(int*)((char*)param_1 + 0xd0) = 0x30000000;
}
}
