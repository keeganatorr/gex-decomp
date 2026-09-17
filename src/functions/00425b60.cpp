extern "C" {
extern char DAT_004A0280;
extern char DAT_004A0281;
extern char DAT_004A0294;
extern char DAT_004A0295;
extern char DAT_004A0293;
extern void* DAT_004A2990;
extern void __cdecl FUN_004213F0(void*);
extern void __cdecl FUN_004213C0(void*, void*);
extern void __cdecl FUN_00421560(void*, void*);
extern void __cdecl FUN_00424090(void**);
extern void __cdecl FUN_00424940(void**);

void __cdecl GEX_Target(void** param_1)
{
    if (DAT_004A0280 == 0 && DAT_004A0281 == 0 && DAT_004A0294 == 0 && DAT_004A0295 == 0 && DAT_004A0293 == 0) {
        if (param_1[0x26] != (void*)0x0) {
            param_1[0x26] = (void*)((int)param_1[0x26] - 1);
        } else {
            param_1[0x26] = (void*)0x0;
            if ((int)param_1[0x15] == 6) {
                FUN_00424090(param_1);
                return;
            }
            param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        }
        FUN_004213F0((void*)param_1);
        FUN_004213C0(DAT_004A2990, (void*)param_1);
        FUN_00421560(DAT_004A2990, (void*)param_1);
        return;
    }
    FUN_00424940(param_1);
}
}
