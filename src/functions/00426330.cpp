extern "C" {
extern char DAT_004A0280;
extern char DAT_004A0281;
extern char DAT_004A0294;
extern char DAT_004A0295;
extern char DAT_004A0293;
extern void* DAT_004A2990;
extern void __cdecl FUN_00421560(void*, void**);
extern void __cdecl FUN_00424090(void**);
extern void __cdecl FUN_00424AA0(void**);

void __cdecl PlayerRunStopFall_00426330(void** param_1)
{
    if (DAT_004A0280 == 0 && DAT_004A0281 == 0 && DAT_004A0294 == 0 && DAT_004A0295 == 0 && DAT_004A0293 == 0) {
        if (param_1[0x26] != (void*)0x0) {
            param_1[0x26] = (void*)((int)param_1[0x26] - 1);
        } else {
            param_1[0x26] = (void*)0x3;
            param_1[0x15] = (void*)((int)param_1[0x15] + 1);
            if ((int)param_1[0x15] == 8) {
                FUN_00424090(param_1);
                return;
            }
        }
        FUN_00421560(DAT_004A2990, param_1);
        return;
    }
    FUN_00424AA0(param_1);
}
}
