// Adapted from pc_decomp_backup/src/functions/FUN_00414FA0.cpp
// Historical source SHA256: 20b73b311264638a05d36e922d00bbe76db13d1db6e7e1e753aa6ad9a21d6389
extern "C" {
extern "C" { extern char DAT_004A0283; }
extern "C" { extern char DAT_004A0284; }
extern "C" { extern char DAT_004A0285; }
extern "C" void __cdecl FUN_00422360();
extern "C" void __cdecl FUN_004144E0(void**);
extern "C" void __cdecl FUN_00414C90(void**);
extern "C" void __cdecl FUN_00423800(void**);
extern "C" void __cdecl FUN_00426CA0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    if ((DAT_004A0283 != 0 || DAT_004A0284 != 0) && DAT_004A0285 == 0) {
        FUN_00422360();
        if (DAT_004A0284 != 0) {
            FUN_004144E0(param_1);
            return;
        }
        FUN_00414C90(param_1);
        return;
    }
    FUN_00423800(param_1);
    param_1[0x26] = (void*)((int)param_1[0x26] + 1);
    if ((int)param_1[0x26] > 2) {
        param_1[0x26] = (void*)0x0;
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        if ((int)param_1[0x15] > 3) {
            FUN_00422360();
            FUN_00426CA0(param_1);
        }
    }
}
}
