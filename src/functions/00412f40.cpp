extern "C" {
int __cdecl FUN_00421f20_pStateUnk_Side(void**);
void __cdecl FUN_00421cd0_xpos_ypos_related(void**);
void __cdecl FUN_00423120_Lash_unk(void**);
void __cdecl FUN_00422790_pStateUnk_Lash(void**);
void __cdecl FUN_00423130_pStateUnk_Eating(void**);
void __cdecl FUN_00415120(void**);
void __cdecl FUN_00411160(void**);
void __cdecl FUN_004138B0(void**);
void __cdecl FUN_00413170(void**);
extern void** FUN_004A2888;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0295;

void __cdecl GEX_Target(void** param1) {
    if ((DAT_004A0295 != 0 || DAT_004A0294 != 0) && DAT_004A0293 == 0) {
        FUN_00423120_Lash_unk(param1);
        if (FUN_004A2888 != 0) {
            FUN_00415120(param1);
            return;
        }
        if (DAT_004A0294 != 0) {
            FUN_004138B0(param1);
            return;
        }
        FUN_00413170(param1);
        return;
    }
    if (FUN_00421f20_pStateUnk_Side(param1) != 0) {
        FUN_00421cd0_xpos_ypos_related(param1);
        param1[0x26] = (void*)((int)param1[0x26] + 0x8000);
        if ((int)param1[0x26] >= 0x10000) {
            param1[0x26] = (void*)((int)param1[0x26] - 0x10000);
            if (param1[0x29] != 0 && param1[0x15] == (void*)1)
                param1[0x15] = (void*)7;
            else
                param1[0x15] = (void*)((int)param1[0x15] + 1);
            if ((int)param1[0x15] > 7) {
                FUN_00423120_Lash_unk(param1);
                if (FUN_004A2888 != 0) {
                    FUN_00415120(param1);
                    return;
                }
                FUN_00411160(param1);
                return;
            }
            FUN_00422790_pStateUnk_Lash(param1);
        }
        FUN_00423130_pStateUnk_Eating(param1);
    }
}
}
