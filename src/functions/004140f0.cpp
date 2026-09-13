// Adapted from pc_decomp_backup/src/functions/FUN_004140F0.cpp
// Historical source SHA256: 135148e54f6d936657bbf41eb8ccac60b73f8d1142baea567a35de07642e6a49
extern "C" {
extern "C" void __cdecl FUN_00411160(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    int count = (int)p[0x26] + 1;
    p[0x26] = (void*)count;
    if (count <= 0) return;
    if ((int)p[0x15] == 4) {
        FUN_00411160(p);
        return;
    }
    p[0x26] = 0;
    p[0x15] = (void*)((int)p[0x15] + 1);
}
}
