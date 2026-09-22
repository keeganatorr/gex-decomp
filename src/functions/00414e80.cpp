extern "C" {
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern int FUN_004A2990;
extern int DAT_004A284C;
int __cdecl FUN_00421820(void*);
int __cdecl FUN_00421560(int, void*);
void __cdecl FUN_004250B0(void*);
void __cdecl FUN_00414A30(void*);
void __cdecl FUN_00424B80(void*);
void __cdecl FUN_00421900(void*);
void __cdecl FUN_00427850(void*);
void __cdecl FUN_004213F0(void*);
void __cdecl FUN_004213C0(int, void*);

void __cdecl GEX_Target(void* param_1)
{
    int iVar1 = FUN_00421820(param_1);
    if (FUN_00421560(FUN_004A2990, param_1) == 0) {
        FUN_004250B0(param_1);
        return;
    }
    if (DAT_004A0293 != 0 && DAT_004A0295 == 0) {
        FUN_00414A30(param_1);
        return;
    }
    if (iVar1 == 0 && DAT_004A0294 != 0 && DAT_004A0295 == 0) {
        FUN_00424B80(param_1);
        return;
    }
    DAT_004A284C = 1;
    FUN_00421900(param_1);
    int v = *(int*)((char*)param_1 + 0x98) + 0x8000;
    *(int*)((char*)param_1 + 0x98) = v;
    if (v >= 0x10000) {
        *(int*)((char*)param_1 + 0x98) = v - 0x10000;
        int frame = *(int*)((char*)param_1 + 0x54) + 1;
        *(int*)((char*)param_1 + 0x54) = frame;
        if (frame > 5) {
            FUN_00427850(param_1);
            return;
        }
    }
    FUN_004213F0(param_1);
    FUN_004213C0(FUN_004A2990, param_1);
}
}
