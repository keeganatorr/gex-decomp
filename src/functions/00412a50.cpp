extern "C" {

extern int  DAT_00458c78;
extern int  DAT_004A284C;
extern int  DAT_004A022C;
extern char DAT_004A0293;
extern char DAT_004A0294;
extern char DAT_004A0295;

void __cdecl FUN_00423800(void *);
void __cdecl FUN_004144E0(void *);
void __cdecl FUN_00413BA0(void *);
void __cdecl FUN_00421900(void *);
void __cdecl FUN_00412D00(void *);

void __cdecl GEX_Target(int *param_1)
{
    int angle;
    int step;

    FUN_00423800(param_1);

    if (DAT_00458c78 != 0 || DAT_004A0294 != 0) {
        FUN_004144E0(param_1);
        return;
    }

    if (DAT_004A0293 != 0 && DAT_004A0295 == 0) {
        FUN_00413BA0(param_1);
        return;
    }

    DAT_004A284C = 1;

    angle = param_1[0x26] + 0x8000;
    param_1[0x26] = angle;
    if (angle >= 0x10000) {
        param_1[0x26] = angle - 0x10000;

        step = param_1[0x15] + 1;
        param_1[0x15] = step;
        if (step > 2) {
            FUN_00412D00(param_1);
        }
        else {
            FUN_00421900(param_1);
        }
    }

    DAT_004A022C = 1;
}
}
