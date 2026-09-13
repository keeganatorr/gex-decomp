// Adapted from pc_decomp_backup/src/functions/FUN_00413AC0.cpp
// Historical source SHA256: b401c26a3058f5692560d3cfb7afafc2b89c62256039ddcb0a4b8cc74eeb999b
extern "C" {
extern "C" void __cdecl FUN_00423800(void**);
extern "C" void __cdecl FUN_00423120(void**);
extern "C" void __cdecl FUN_00415040(void**);
extern "C" void __cdecl FUN_00426CA0(void**);
extern "C" void __cdecl FUN_00422790(void**);
extern "C" void __cdecl FUN_00423130(void**);
extern "C" void __cdecl FUN_004144E0(void**);
extern "C" void __cdecl FUN_00412AF0(void**);
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern void** DAT_004A2888; }
extern "C" { extern int DAT_004A022C; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    if ((DAT_004A0295 == 0 && DAT_004A0294 == 0) || DAT_004A0293 != 0) {
        
        FUN_00423800(param_1);
        int* p26 = (int*)&param_1[0x26];
        int val = *p26 + 0x8000;
        *p26 = val;
        if (val >= 0x10000) {
            *p26 = val - 0x10000;
            int* p15 = (int*)&param_1[0x15];
            (*p15)++;
            if (*p15 > 8) {
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
        return;
    }
    
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
}
}
