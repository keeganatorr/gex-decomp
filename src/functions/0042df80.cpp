// Adapted from pc_decomp_backup/src/functions/FUN_0042DF80.cpp
// Historical source SHA256: 5e2046e8e831842d66a98add4e62b6ee8afeccbdc5e254f3fa101ef7d7ac4934
extern "C" {
extern "C" void __cdecl FUN_0041b700_ObjCallUnkInner(void*);
extern "C" void** __cdecl FUN_004195D0(int, int, int, int);
extern "C" int __cdecl FUN_0042dab0_gOb_GexFuncUnk(void**, int);

extern void** FUN_004A27FC;
extern void** DAT_004a23dc;
extern "C" { extern int DAT_004a23c8; }
extern "C" { extern int DAT_004a2890_velocity_unk; }
extern int DAT_0045b00c;

extern "C" int __cdecl GEX_Target(void** param1, int param2)
{
    if (FUN_004A27FC == param1)
    {
        if (DAT_004a23dc != 0)
            FUN_0041b700_ObjCallUnkInner(DAT_004a23dc);
        void** ppGVar1 = FUN_004195D0(0x11c, (int)param1[0x1e], (int)param1[0x62], 0);
        if (ppGVar1 != 0)
        {
            DAT_004a23dc = ppGVar1;
            ppGVar1[0x29] = (void*)3;
        }
        FUN_0042dab0_gOb_GexFuncUnk(param1, param2);
        param1[0x23] = (void*)-*(int*)(&DAT_0045b00c + DAT_004a23c8 * 0xc);
        int iVar3 = DAT_004a23c8 + 1;
        DAT_004a2890_velocity_unk = *(int*)((int)&DAT_0045b00c + 4 + (DAT_004a23c8 + -2 + iVar3 * 2) * 4);
        if (iVar3 == 4)
            iVar3 = DAT_004a23c8;
        DAT_004a23c8 = iVar3;
        return 0;
    }
    return FUN_0042dab0_gOb_GexFuncUnk(param1, param2);
}
}
