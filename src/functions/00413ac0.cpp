extern "C" {
void __cdecl FUN_00423800(void**);
void __cdecl FUN_00423120(void**);
void __cdecl FUN_00415040(void**);
void __cdecl FUN_00426CA0(void**);
void __cdecl FUN_00422790(void**);
void __cdecl FUN_00423130(void**);
void __cdecl FUN_004144E0(void**);
void __cdecl FUN_00412AF0(void**);
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern void** DAT_004A2888;
extern int DAT_004A022C;

void __cdecl PlayerFaceTongueLash_00413ac0(void** param_1)
{
    if ((DAT_004A0295 != 0 || DAT_004A0294 != 0) && DAT_004A0293 == 0) {
        FUN_00423120(param_1);
        if (DAT_004A2888 != 0) {
            FUN_00415040(param_1);
            return;
        }
        if (DAT_004A0294 != 0) {
            FUN_004144E0(param_1);
            return;
        }
        FUN_00412AF0(param_1);
        return;
    }

    FUN_00423800(param_1);
    int val = ((int*)param_1)[0x26] + 0x8000;
    ((int*)param_1)[0x26] = val;
    if (val >= 0x10000) {
        ((int*)param_1)[0x26] = val - 0x10000;
        int frame = ((int*)param_1)[0x15] + 1;
        ((int*)param_1)[0x15] = frame;
        if (frame > 8) {
            FUN_00423120(param_1);
            if (DAT_004A2888 != 0) {
                FUN_00415040(param_1);
                return;
            }
            FUN_00426CA0(param_1);
            return;
        }
        FUN_00422790(param_1);
    }
    DAT_004A022C = 1;
    FUN_00423130(param_1);
}
}
