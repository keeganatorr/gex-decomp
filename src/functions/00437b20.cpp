// Adapted from pc_decomp_backup/src/functions/FUN_00437B20.cpp
// Historical source SHA256: 398cf91ca42df3db934264a5810f2572e0beed4e8a60bf051f104227919d4b08
extern "C" {
extern "C" void __cdecl FUN_00405390(const char*);
extern "C" void __cdecl FUN_00417B70();
extern "C" { extern int DAT_00455c54; }
extern "C" { extern const char DAT_0045b140[]; }
extern "C" void __cdecl GEX_Target(int param1, int* param2) {
    if (*param2 != 0) {
        int val = *(int*)(param1 + 0x178);
        if (((*(unsigned int*)(val + 0x6c) >> 8) & 0xf) == 2) {
            if (DAT_00455c54 > 1) FUN_00405390(DAT_0045b140);
            FUN_00417B70();
        }
    }
}
}
