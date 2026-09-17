extern "C" {
extern char DAT_004A0293;
extern char DAT_004A0294;
extern char DAT_004A0295;
extern void __cdecl FUN_00422360(void**);
extern void __cdecl FUN_004144E0(void**);
extern void __cdecl FUN_00414C90(void**);
extern void __cdecl FUN_00423800(void**);
extern void __cdecl FUN_00426CA0(void**);

void __cdecl GEX_Target(void** param_1)
{
    if ((DAT_004A0295 != 0 || DAT_004A0294 != 0) && DAT_004A0293 == 0) {
        FUN_00422360(param_1);
        if (DAT_004A0294 != 0) {
            FUN_004144E0(param_1);
            return;
        }
        FUN_00414C90(param_1);
        return;
    }
    FUN_00423800(param_1);
    param_1[0x26] = (void*)((int)param_1[0x26] + 1);
    if ((int)param_1[0x26] >= 3) {
        param_1[0x26] = (void*)0x0;
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        if ((int)param_1[0x15] > 3) {
            FUN_00422360(param_1);
            FUN_00426CA0(param_1);
        }
    }
}
}