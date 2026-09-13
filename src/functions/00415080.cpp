// Adapted from pc_decomp_backup/src/functions/FUN_00415080.cpp
// Historical source SHA256: 3b2dbf6f602ba7a1c86e39876c28389fe8b15baf567c9818ee12f9241fceb641
extern "C" {
extern "C" { extern unsigned char DAT_004a0293; } extern "C" { extern unsigned char DAT_004a0294; } extern "C" { extern unsigned char DAT_004a0295; }
extern "C" void __cdecl FUN_00422360_COLLISION_HEALTHLOSTINHERE();
extern "C" void __cdecl FUN_004138B0(void**);
extern "C" void __cdecl FUN_00413170(void**);
extern "C" int __cdecl FUN_00421f20_pStateUnk_Side(void**);
extern "C" void __cdecl FUN_00421cd0_xpos_ypos_related(void**);
extern "C" void __cdecl FUN_00411160(void**);
extern "C" void __cdecl GEX_Target(void** param_1)
{
    if ((DAT_004a0295 != 0 || DAT_004a0294 != 0) && DAT_004a0293 == 0) {
        FUN_00422360_COLLISION_HEALTHLOSTINHERE();
        if (DAT_004a0294 != 0) { FUN_004138B0(param_1); return; }
        FUN_00413170(param_1); return;
    }
    if (FUN_00421f20_pStateUnk_Side(param_1) != 0) {
        FUN_00421cd0_xpos_ypos_related(param_1);
        int* p26 = (int*)&param_1[0x26]; (*p26)++;
        if (*p26 > 2) {
            param_1[0x26] = 0;
            int* p15 = (int*)&param_1[0x15]; (*p15)++;
            if (*p15 > 3) { FUN_00422360_COLLISION_HEALTHLOSTINHERE(); FUN_00411160(param_1); }
        }
    }
}
}
