// Adapted from pc_decomp_backup/src/functions/FUN_00412F40.cpp
// Historical source SHA256: 68b090c6ef70523036f9986f9160c74d0eb050abf0e0edbc55cdbbbf3eef6436
extern "C" {
extern "C" int __cdecl FUN_00421f20_pStateUnk_Side(void**);
extern "C" void __cdecl FUN_00421cd0_xpos_ypos_related(void**);
extern "C" void __cdecl FUN_00423120_Lash_unk();
extern "C" void __cdecl FUN_00422790_pStateUnk_Lash(void**);
extern "C" void __cdecl FUN_00423130_pStateUnk_Eating(void**);
extern "C" void __cdecl FUN_00415120(void**);
extern "C" void __cdecl FUN_00411160(void**);
extern "C" void __cdecl FUN_004138B0(void**);
extern "C" void __cdecl FUN_00413170(void**);
extern void** FUN_004A2888;
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" void __cdecl GEX_Target(void** param1) {
    if (((DAT_004A0295 == 0) && (DAT_004A0294 == 0)) || (DAT_004A0293 != 0)) {
        int iVar2 = FUN_00421f20_pStateUnk_Side(param1);
        if (iVar2 != 0) {
            FUN_00421cd0_xpos_ypos_related(param1);
            void* pGVar1 = param1[0x26];
            void* pGVar3 = (void*)((int)pGVar1 + 0x40);
            param1[0x26] = pGVar3;
            if ((int)pGVar3 > 0xffff) {
                param1[0x26] = (void*)((int)pGVar1 + -0x40);
                if ((param1[0x29] == 0) || (param1[0x15] != (void*)1))
                    param1[0x15] = (void*)((int)param1[0x15] + 1);
                else param1[0x15] = (void*)7;
                if ((int)param1[0x15] > 7) {
                    FUN_00423120_Lash_unk();
                    if (FUN_004A2888 != 0) { FUN_00415120(param1); return; }
                    FUN_00411160(param1); return;
                }
                FUN_00422790_pStateUnk_Lash(param1);
            }
            FUN_00423130_pStateUnk_Eating(param1);
        }
        return;
    }
    FUN_00423120_Lash_unk();
    if (FUN_004A2888 != 0) { FUN_00415120(param1); return; }
    if (DAT_004A0294 != 0) { FUN_004138B0(param1); return; }
    FUN_00413170(param1);
}
}
