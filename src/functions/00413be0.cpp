extern "C" {
extern int DAT_00462E50;
extern int DAT_004A284C;
extern void* DAT_004A2990;
extern void __cdecl FUN_00414030(void**);
extern void __cdecl FUN_00420960(void**);
extern void __cdecl FUN_004213F0(void*);
extern void __cdecl FUN_004213C0(void*, void*);
extern int __cdecl FUN_00421560(void*, void*);
extern void __cdecl FUN_00421900(void**);

void __cdecl PlayerTailBounce_00413be0(void** param_1)
{
    int newVal;

    DAT_004A284C = 1;
    newVal = (int)param_1[0x26] + 0x8000;
    param_1[0x26] = (void*)newVal;
    if (newVal >= 0x10000) {
        param_1[0x26] = (void*)(newVal - 0x10000);
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        if ((int)param_1[0x15] == 9) {
            DAT_00462E50 = 0;
            FUN_00414030(param_1);
            return;
        }
        FUN_00420960(param_1);
        FUN_00421900(param_1);
    }
    FUN_004213F0((void*)param_1);
    FUN_004213C0(DAT_004A2990, (void*)param_1);
    if (DAT_00462E50 == 0) {
        FUN_00421560(DAT_004A2990, (void*)param_1);
    }
}
}
