// Adapted from pc_decomp_backup/src/functions/FUN_00423910.cpp
// Historical source SHA256: f40e924ea6495a2dcc1062b7fb490d71d3c56a6df5db778012c55ee5b9e56e35
extern "C" {
extern "C" void __cdecl FUN_00423780_pStateUnk(void**);
extern "C" { extern int DAT_004a2848[]; }

extern "C" int __cdecl GEX_Target(void** param1) {
    int* p = (int*)param1;
    FUN_00423780_pStateUnk(param1);
    unsigned int uVar1 = (unsigned int)(((unsigned int)(p[0x31] + 0x1000) & 0x400000) == 0);
    int i = 0;
    if (uVar1 != 0xfffffffd) {
        do {
            if (DAT_004a2848[i] == 0) return 0;
            i++;
        } while (i < (int)(uVar1 + 3));
    }
    return 1;
}
}
