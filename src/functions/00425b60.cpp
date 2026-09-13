// Adapted from pc_decomp_backup/src/functions/FUN_00425B60.cpp
// Historical source SHA256: a5d0d8367c66590050bc695d4be87dcbe561c22da1152b15c405f95ade28e60f
extern "C" {
extern "C" { extern char DAT_004A0280; }
extern "C" { extern char DAT_004A0281; }
extern "C" { extern char DAT_004A0282; }
extern "C" { extern char DAT_004A0283; }
extern "C" { extern char DAT_004A0284; }
extern void* DAT_004A2990;
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(void*, void*);
extern "C" int __cdecl FUN_00421560(void*, void*);
extern "C" void __cdecl FUN_00424090(void**);
extern "C" void __cdecl FUN_00424940(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    if (DAT_004A0280 == 0 && DAT_004A0281 == 0 && DAT_004A0282 == 0 && DAT_004A0283 == 0 && DAT_004A0284 == 0) {
        if (param_1[0x26] == (void*)0x0) {
            param_1[0x26] = (void*)0x0;
            if ((int)param_1[0x15] == 6) {
                FUN_00424090(param_1);
                return;
            }
            param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        } else {
            param_1[0x26] = (void*)((int)param_1[0x26] - 1);
        }
        FUN_004213F0((void*)param_1);
        FUN_004213C0(DAT_004A2990, (void*)param_1);
        FUN_00421560(DAT_004A2990, (void*)param_1);
        return;
    }
    FUN_00424940(param_1);
}
}
