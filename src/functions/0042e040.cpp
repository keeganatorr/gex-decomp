// Adapted from pc_decomp_backup/src/functions/FUN_0042E040.cpp
// Historical source SHA256: 2c3ff27a953e67437c2c70bc4a0879e6c960187d003caa8a76e458ba198770a2
extern "C" {
extern "C" void __cdecl FUN_0041b700_ObjCallUnkInner(void*);
extern "C" void** __cdecl FUN_004195D0(int, int, int, int);
extern "C" int __cdecl FUN_0042da40_ObjCallUnk(void**);
extern void** FUN_004A27FC;
extern void** DAT_004a23d8;
extern "C" { extern int DAT_004a23c8; }
extern "C" { extern int DAT_004a2890_velocity_unk; }
extern int DAT_0045b008;
extern "C" int __cdecl GEX_Target(void** gOb) {
    if (gOb == FUN_004A27FC) {
        if (DAT_004a23d8 != 0) FUN_0041b700_ObjCallUnkInner(DAT_004a23d8);
        void** pp = FUN_004195D0(0x11c,(int)gOb[0x1e],(int)gOb[0x62],0);
        if (pp != 0) { DAT_004a23d8 = pp; pp[0x29] = (void*)2; }
        FUN_0042da40_ObjCallUnk(gOb);
        gOb[0x20] = (void*)*(int*)((int)&DAT_0045b008 + DAT_004a23c8 * 0xc);
        gOb[0x23] = (void*)*(int*)((int)&DAT_0045b008 + 4 + DAT_004a23c8 * 0xc);
        DAT_004a2890_velocity_unk = -*(int*)((int)&DAT_0045b008 + 8 + DAT_004a23c8 * 0xc);
        int i = DAT_004a23c8 + 1;
        if (i == 4) i = DAT_004a23c8;
        DAT_004a23c8 = i;
        return 0;
    }
    return FUN_0042da40_ObjCallUnk(gOb);
}
}
