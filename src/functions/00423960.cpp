// Adapted from pc_decomp_backup/src/functions/FUN_00423960.cpp
// Historical source SHA256: 05109aa6ba10faeaac11a9c68bd567e0fabe681068956089295a52b8a5ebe7a4
extern "C" {
extern "C" void __cdecl FUN_00423780_pStateUnk(void**);
extern "C" { extern int DAT_004a2868[]; }
extern "C" int __cdecl GEX_Target(void** param1) {
    int* p = (int*)param1;
    FUN_00423780_pStateUnk(param1);
    unsigned int uVar1 = (unsigned int)(((unsigned int)(p[0x31] + 0x1000) & 0x400000) == 0);
    int i = 0;
    if (uVar1 != 0xfffffffd) {
        do {
            if (DAT_004a2868[i] == 0) return 0;
            i++;
        } while (i < (int)(uVar1 + 3));
    }
    return 1;
}
}
