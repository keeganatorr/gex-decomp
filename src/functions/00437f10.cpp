// Adapted from pc_decomp_backup/src/functions/FUN_00437F10.cpp
// Historical source SHA256: 4befb60fe7e2c954570d75b2cff4f50fe08339dd149835cc18dc1f3a19c723d1
extern "C" {
extern "C" void __cdecl FUN_004094C0(void*);
extern "C" int __cdecl GEX_Target(void* param1) {
    int status = *(int*)((char*)param1 + 0x58);
    if (status != 0) {
        if (status == 1) {
            FUN_004094C0((char*)param1 + 0x48);
            *(int*)((char*)param1 + 0x58) = 2;
        }
        return 1;
    }
    return 0;
}
}
