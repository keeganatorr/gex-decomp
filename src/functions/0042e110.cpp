// Adapted from pc_decomp_backup/src/functions/FUN_0042E110.cpp
// Historical source SHA256: 09090b0468b49e2671ef5df315a059a3ff39aec4636ab11624dcdefa79d0f651
extern "C" {
extern "C" void __cdecl FUN_0041b700_ObjCallUnkInner(void*);
extern "C" void** __cdecl FUN_004195D0(int, int, int, int);
extern "C" int __cdecl FUN_0042d7c0_ObjCallUnk(void**, int);
extern void** FUN_004A27FC;
extern void** DAT_004a23d0;
extern "C" { extern int DAT_004a23c8; }
extern "C" { extern int DAT_004a2890_velocity_unk; }
extern int DAT_0045b038;
extern "C" int __cdecl GEX_Target(void** gOb, int param2) {
    if (FUN_004A27FC == gOb) {
        if (DAT_004a23d0 != 0)
            FUN_0041b700_ObjCallUnkInner(DAT_004a23d0);
        void** ppGVar1 = FUN_004195D0(0x11c, (int)gOb[0x61], (int)gOb[0x1f], 0);
        if (ppGVar1 != 0) {
            DAT_004a23d0 = ppGVar1;
            ppGVar1[0x29] = 0;
        }
        FUN_0042d7c0_ObjCallUnk(gOb, param2);
        gOb[0x20] = (void*)*(int*)((int)&DAT_0045b038 + DAT_004a23c8 * 0xc);
        gOb[0x23] = (void*)*(int*)((int)&DAT_0045b038 + 4 + DAT_004a23c8 * 0xc);
        int iVar2 = DAT_004a23c8 + 1;
        DAT_004a2890_velocity_unk = *(int*)((int)&DAT_0045b038 + 8 + (DAT_004a23c8 + -2 + iVar2 * 2) * 4);
        if (iVar2 == 4)
            iVar2 = DAT_004a23c8;
        DAT_004a23c8 = iVar2;
        return 0;
    }
    return FUN_0042d7c0_ObjCallUnk(gOb, param2);
}
}
