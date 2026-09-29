extern "C" {
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern int FUN_004A2888;
int __cdecl FUN_00421F20(void*);
void __cdecl FUN_00421CD0(void*);
void __cdecl FUN_00422790(void*);
void __cdecl FUN_00423130(void*);
void __cdecl FUN_00423120(void*);
void __cdecl FUN_00415120(void*);
void __cdecl FUN_00411160(void*);
void __cdecl FUN_004138B0(void*);
void __cdecl FUN_00413170(void*);

void __cdecl PlayerSideTongueLash_00412880(void* param_1)
{
    if ((DAT_004A0295 != 0 || DAT_004A0294 != 0) && DAT_004A0293 == 0) {
        FUN_00423120(param_1);
        if (FUN_004A2888 != 0) {
            FUN_00415120(param_1);
            return;
        }
        if (DAT_004A0294 != 0) {
            FUN_004138B0(param_1);
            return;
        }
        FUN_00413170(param_1);
        return;
    }
    if (FUN_00421F20(param_1) != 0) {
        FUN_00421CD0(param_1);
        int v = *(int*)((char*)param_1 + 0x98) + 0x10000;
        *(int*)((char*)param_1 + 0x98) = v;
        if (v >= 0x10000) {
            *(int*)((char*)param_1 + 0x98) = v - 0x10000;
            ++*(int*)((char*)param_1 + 0x54);
            if (*(int*)((char*)param_1 + 0x54) > 12) {
                FUN_00423120(param_1);
                if (FUN_004A2888 != 0) {
                    FUN_00415120(param_1);
                    return;
                }
                FUN_00411160(param_1);
                return;
            }
            FUN_00422790(param_1);
        }
        FUN_00423130(param_1);
    }
}
}
