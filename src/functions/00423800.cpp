extern "C" {
void __cdecl FUN_00423760_pStateUnk();
void __cdecl FUN_00423200_pStateUnk(void**, void**);
int __cdecl FUN_004237c0_pStateUnk();
void __cdecl FUN_00423350_xpos_ypos_movement(void**);
void __cdecl FUN_0042D060(int, void**, void*);
void __cdecl FUN_0042D2C0(int, void**, void*);
extern int DAT_004A2874;
extern int DAT_004A2814;
extern int DAT_00463AD8;
extern int FUN_004A2AC8;
extern int FUN_004A2990;

void __cdecl GEX_Target(void** param1) {
    void** ppGVar4 = (void**)DAT_004A2874;
    void** ppGVar3 = (void**)DAT_004A2814;
    int iVar7 = 0;
    int local_4 = 0;
    if (((DAT_004A2874 != 0) || (DAT_004A2814 != 0)) && (FUN_004A2AC8 != DAT_00463AD8)) {
        DAT_00463AD8 = FUN_004A2AC8;
        if (DAT_004A2874 != 0) {
            FUN_00423760_pStateUnk();
            FUN_00423200_pStateUnk(param1, ppGVar4);
            iVar7 = FUN_004237c0_pStateUnk();
        }
        if (ppGVar3 != 0) {
            FUN_00423760_pStateUnk();
            FUN_00423200_pStateUnk(param1, ppGVar3);
            local_4 = FUN_004237c0_pStateUnk();
        }
        FUN_00423760_pStateUnk();
        FUN_00423350_xpos_ypos_movement(param1);
        long iVar5 = FUN_004237c0_pStateUnk();
        void** ppGVar6 = ppGVar4;
        if ((ppGVar4 != 0) && (ppGVar3 != 0) && (ppGVar6 = ppGVar3, local_4 < iVar7))
            ppGVar6 = ppGVar4;
        if (iVar5 > (long)iVar7) ppGVar6 = 0;
        if (ppGVar6 != 0) {
            int dy = (int)ppGVar6[0x1f] - (int)ppGVar6[0x36];
            int dx = (int)ppGVar6[0x1e] - (int)ppGVar6[0x35];
            ((int*)param1)[0x1e] += dx;
            FUN_0042D060(FUN_004A2990, param1, 0);
            param1[0x1f] = (void*)((int)param1[0x1f] + dy);
            FUN_0042D2C0(FUN_004A2990, param1, 0);
        }
    }
}
}
