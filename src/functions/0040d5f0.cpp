// Adapted from pc_decomp_backup/src/functions/FUN_0040D5F0.cpp
// Historical source SHA256: 3587c5cce23aa97f0c09454802fcead5bfe3c866aef5c55d96e6f688b9241567
extern "C" {
extern "C" void* __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_0040D740(void**);
extern "C" void __cdecl FUN_0041E7C0(void**);
extern "C" void __cdecl FUN_00419520(void**);
extern "C" { extern int DAT_00455c04; }
extern "C" { extern int DAT_004a2964; }
extern "C" { extern void** DAT_004a2400[]; }
extern "C" void __cdecl GEX_Target(int param1, int param2, int inputString, int param4) {
    void** gOb = (void**)FUN_004195D0(0x55, param1, param2, 0);
    if (gOb != 0) {
        gOb[0x26] = (void*)inputString;
        gOb[0x27] = (void*)0x6000a;
        gOb[0x28] = (void*)0x70000;
        if (DAT_004a2964 == 0) gOb[0x20] = (void*)0xa;
        else gOb[0x20] = (void*)0xe;
        void* pGVar2 = DAT_004a2400[param4];
        gOb[0x21] = pGVar2;
        if (DAT_00455c04 == 4 && pGVar2 == 0) { FUN_00419520(gOb); return; }
        FUN_0040D740(gOb);
        gOb[0x28] = (void*)((unsigned int)gOb[0x28] & 0xfffffff1 | 1);
        gOb[0x29] = 0; gOb[0x2a] = 0;
        gOb[0x20] = (void*)((unsigned int)gOb[0x20] | 8);
        FUN_0041E7C0(gOb);
        gOb[0x19] = 0;
    }
}
}
