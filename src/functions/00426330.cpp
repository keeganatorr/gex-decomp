// Adapted from pc_decomp_backup/src/functions/FUN_00426330.cpp
// Historical source SHA256: bf66ae295770c2ea56d08bda97be80b1ca56fa85d5ca8df608ac56377f2366a0
extern "C" {
extern "C" { extern char DAT_004A0280; }
extern "C" { extern char DAT_004A0281; }
extern "C" { extern char DAT_004A0282; }
extern "C" { extern char DAT_004A0283; }
extern "C" { extern char DAT_004A0284; }
extern void* DAT_004A2990;
extern "C" void __cdecl FUN_00421560(void*, void**);
extern "C" void __cdecl FUN_00424090(void**);
extern "C" void __cdecl FUN_00424AA0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    if (DAT_004A0280 == 0 && DAT_004A0281 == 0 && DAT_004A0282 == 0 && DAT_004A0283 == 0 && DAT_004A0284 == 0) {
        if (param_1[0x26] == (void*)0x0) {
            param_1[0x26] = (void*)0x3;
            param_1[0x15] = (void*)((int)param_1[0x15] + 1);
            if ((int)param_1[0x15] == 8) {
                FUN_00424090(param_1);
                return;
            }
        } else {
            param_1[0x26] = (void*)((int)param_1[0x26] - 1);
        }
        FUN_00421560(DAT_004A2990, param_1);
        return;
    }
    FUN_00424AA0(param_1);
}
}
