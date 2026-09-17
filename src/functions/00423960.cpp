extern "C" void __cdecl FUN_00423780_pStateUnk(void**);
extern "C" char DAT_004a2868[];

extern "C" int __cdecl GEX_Target(void** param1) {
    int* p = (int*)param1;
    FUN_00423780_pStateUnk(param1);
    int n = (((p[0x31] + 0x200000) & 0x400000) == 0) ? 4 : 3;
    for (int i = 0; i < n; i++) {
        if (DAT_004a2868[i] == 0)
            return 0;
    }
    return 1;
}
