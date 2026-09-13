// Adapted from pc_decomp_backup/src/functions/FUN_00438AA0.cpp
// Historical source SHA256: d0a4a915b349363253bc98e32f56250ee5ff82a3b97ef31976d4e17ff216b077
extern "C" {
extern "C" void __cdecl FUN_00405390(const char*, ...);
extern "C" { extern int DAT_00455c54; }
extern "C" { extern const char DAT_0045f088[]; }
extern "C" { extern const char DAT_0045f0c0[]; }
extern "C" int __cdecl GEX_Target(int param1) {
    if ((*(unsigned int*)(param1 + 0x6c) & 0x1f000000) == 0xa000000) {
        if (DAT_00455c54 > 1) {
            FUN_00405390(DAT_0045f088, *(int*)(param1 + 8));
            FUN_00405390(DAT_0045f0c0);
        }
        return 1;
    }
    return 0;
}
}
