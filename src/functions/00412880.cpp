// Adapted from pc_decomp_backup/src/functions/FUN_00412880.cpp
// Historical source SHA256: 302b9cf81004d79d1fbab3317da56621611d160fc3afd3d6cfcfd4b0ea3b6943
extern "C" {
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0283; }
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern int FUN_004A2888; }
extern "C" int __cdecl FUN_00421F20(void*);
extern "C" void __cdecl FUN_00421CD0(void*);
extern "C" void __cdecl FUN_00422790(void*);
extern "C" void __cdecl FUN_00423130(void*);
extern "C" void __cdecl FUN_00423120(void*);
extern "C" void __cdecl FUN_00415120(void*);
extern "C" void __cdecl FUN_00411160(void*);
extern "C" void __cdecl FUN_004138B0(void*);
extern "C" void __cdecl FUN_00413170(void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    if ((DAT_004A0295 == 0 && DAT_004A0294 == 0) || DAT_004A0293 != 0) {
        if (FUN_00421F20(param_1) != 0) {
            FUN_00421CD0(param_1);
            {
                int v = *(int*)((char*)param_1 + 0x98) + 0x8000;
                *(int*)((char*)param_1 + 0x98) = v;
                if (v < 0) {
                    *(int*)((char*)param_1 + 0x98) = v;
                    (*(int*)((char*)param_1 + 0x54))++;
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
        return;
    }
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
}
}
