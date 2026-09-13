// Adapted from pc_decomp_backup/src/functions/FUN_004097B0.cpp
// Historical source SHA256: 1ac63f6d13be174604d0e1bec1cdd2a4f87c2c3e26b5987a80a1985842ff12b2
extern "C" {
extern "C" void __cdecl FUN_00409740(void*);

extern "C" void __cdecl GEX_Target()
{
    int* ptr;
    for (ptr = (int*)0x0047EF80; ptr < (int*)0x0047F000; ptr++) {
        if (*ptr != 0) {
            FUN_00409740((void*)*ptr);
            *ptr = 0;
        }
    }
    *(int*)0x0047EF70 = 0;
}
}
