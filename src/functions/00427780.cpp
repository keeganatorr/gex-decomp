extern "C" {
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0280;
extern unsigned char DAT_004A0281;
extern unsigned char DAT_004A0283;
extern int FUN_004A2990;
extern int __cdecl FUN_00421820(void*);
extern void __cdecl FUN_00424B80(void*);
extern void __cdecl FUN_00414C90(void*);
extern void __cdecl FUN_00414A30(void*);
extern void __cdecl FUN_004250B0(void*);
extern void __cdecl FUN_00427940(void*);
extern int __cdecl FUN_00421560(int, void*);
extern void __cdecl FUN_004213F0(void*);
extern void __cdecl FUN_004213C0(int, void*);

void __cdecl PlayerDuck_00427780(void* param_1)
{
    int iVar1;
    int iVar2;

    iVar1 = FUN_00421820(param_1);
    if (iVar1 == 0 && DAT_004A0294 != 0) {
        FUN_00424B80(param_1);
        return;
    }
    if (DAT_004A0295 != 0) {
        FUN_00414C90(param_1);
        return;
    }
    if (DAT_004A0293 == 0) {
        iVar2 = FUN_00421560(FUN_004A2990, param_1);
        if (iVar2 == 0) {
            FUN_004250B0(param_1);
            return;
        }
        if (DAT_004A0280 != 0) {
            *(int*)((char*)param_1 + 0x6c) &= 0x7fffffff;
        }
        if (DAT_004A0281 != 0) {
            *(int*)((char*)param_1 + 0x6c) |= 0x80000000;
        }
        if (DAT_004A0283 == 0 && iVar1 == 0) {
            FUN_00427940(param_1);
        }
        FUN_004213F0(param_1);
        FUN_004213C0(FUN_004A2990, param_1);
        return;
    }
    FUN_00414A30(param_1);
}
}