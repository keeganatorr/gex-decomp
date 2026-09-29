extern "C" {
    extern unsigned char DAT_004a0293;
    extern unsigned char DAT_004a0294;
    extern unsigned char DAT_004a0295;

    void __cdecl FUN_00422360_COLLISION_HEALTHLOSTINHERE(void**);
    void __cdecl FUN_004138B0(void**);
    void __cdecl FUN_00413170(void**);
    int __cdecl FUN_00421f20_pStateUnk_Side(void**);
    void __cdecl FUN_00421cd0_xpos_ypos_related(void**);
    void __cdecl FUN_00411160(void**);

    void __cdecl PlayerSideSwallow_00415080(void** param_1)
    {
        if ((DAT_004a0295 != 0 || DAT_004a0294 != 0) && DAT_004a0293 == 0) {
            FUN_00422360_COLLISION_HEALTHLOSTINHERE(param_1);
            if (DAT_004a0294 != 0) {
                FUN_004138B0(param_1);
                return;
            }
            FUN_00413170(param_1);
            return;
        }
        if (FUN_00421f20_pStateUnk_Side(param_1) != 0) {
            FUN_00421cd0_xpos_ypos_related(param_1);
            ((int*)param_1)[0x26]++;
            if (((int*)param_1)[0x26] >= 3) {
                ((int*)param_1)[0x26] = 0;
                ((int*)param_1)[0x15]++;
                if (((int*)param_1)[0x15] > 3) {
                    FUN_00422360_COLLISION_HEALTHLOSTINHERE(param_1);
                    FUN_00411160(param_1);
                }
            }
        }
    }
}