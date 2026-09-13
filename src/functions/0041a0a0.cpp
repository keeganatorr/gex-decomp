// Adapted from pc_decomp_backup/src/functions/FUN_0041A0A0.cpp
// Historical source SHA256: bc23a734d123288eae99ea3fe81217348994884b810fa9fb8cd8b0113b12790b
extern "C" {
extern "C" int __cdecl FUN_0040F1D0(int, void**);
extern "C" void __cdecl FUN_00405390(const char*, int, int);
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int DAT_00455c54; }
extern "C" { extern void** DAT_004a27fc; }
extern "C" { extern const char DAT_00458f48[]; }
extern "C" { extern int DAT_00458edc; }
extern "C" int __cdecl GEX_Target(void** param1, int param2) {
    param1[0x1f] = (void*)((int)param1[0x1f] + param2 - 0x1c);
    int pGVar1 = FUN_0040F1D0(FUN_004A2990, param1);
    param1[0x1f] = (void*)((int)param1[0x1f] - param2);
    if (DAT_00455c54 > 2 && DAT_004a27fc == param1) {
        FUN_00405390(DAT_00458f48, pGVar1 >> 0x10, (int)param1[0x37] >> 0x10);
    }
    if (pGVar1 < 0x18001 && DAT_00458edc <= pGVar1 && ((int)param1[0x37] > -0x20001 || (int)param1[0x37] < -0x7e000000)) {
        param1[0x37] = 0;
        param1[0x1f] = (void*)((int)param1[0x1f] + (int)pGVar1);
        return 1;
    }
    param1[0x37] = (void*)pGVar1;
    if (param1[0x44] != 0 && param1[0x45] == 0) return 1;
    return 0;
}
}
