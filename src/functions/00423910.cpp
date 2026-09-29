extern "C" {
extern "C" void __cdecl FUN_00423780_pStateUnk(void**);
extern "C" char DAT_004a2848[];

extern "C" int __cdecl FUN_00423910_pStateUnk(void** param1) {
    int* p = (int*)param1;
    FUN_00423780_pStateUnk(param1);
    int limit = ((p[0x31] + 0x200000) & 0x400000) == 0 ? 4 : 3;
    int i, j;
    for (i = 0, j = 0; j < limit; j++, i++) {
        if (DAT_004a2848[j] == 0) return 0;
    }
    return 1;
}
}