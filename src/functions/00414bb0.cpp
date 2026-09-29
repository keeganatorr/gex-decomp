extern "C" {
int __cdecl FUN_00421820_pStateUnk_Duck(void**);
int __cdecl FUN_00421560_DrawCharacter(int, void**);
void __cdecl FUN_004250B0(void**);
void __cdecl FUN_00414A30(void**);
void __cdecl FUN_00424B80(void**);
void __cdecl FUN_00414E20(void**);
void __cdecl FUN_00421900(void**);
void __cdecl FUN_004213f0_GexMovementLeftandRight(void*);
void __cdecl FUN_004213c0(int, void**);
extern unsigned char DAT_004a0293;
extern unsigned char DAT_004a0294;
extern unsigned char DAT_004a0295;
extern int FUN_004A2990;
extern int FUN_004A284C;

void __cdecl PlayerDuckSpin_00414bb0(void** param_1)
{
    int stateResult = FUN_00421820_pStateUnk_Duck(param_1);
    int drawResult = FUN_00421560_DrawCharacter(FUN_004A2990, param_1);
    if (drawResult == 0) { FUN_004250B0(param_1); return; }
    if (DAT_004a0293 != 0 && DAT_004a0295 == 0) { FUN_00414A30(param_1); return; }
    if (stateResult == 0 && DAT_004a0294 != 0 && DAT_004a0295 == 0) { FUN_00424B80(param_1); return; }
    FUN_004A284C = 1;
    int val = ((int*)param_1)[0x26] + 0x8000;
    ((int*)param_1)[0x26] = val;
    if (val >= 0x10000) {
        ((int*)param_1)[0x26] = val - 0x10000;
        int frame = ((int*)param_1)[0x15] + 1;
        ((int*)param_1)[0x15] = frame;
        if (frame > 1) { FUN_00414E20(param_1); return; }
        FUN_00421900(param_1);
    }
    FUN_004213f0_GexMovementLeftandRight(param_1);
    FUN_004213c0(FUN_004A2990, param_1);
}
}
