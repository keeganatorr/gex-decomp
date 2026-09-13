// Adapted from pc_decomp_backup/src/functions/FUN_0040BA50.cpp
// Historical source SHA256: 232ccf7f8e6efd7cc32d8eb9d8813792c0ca94bab49f24299e8e2ac379e50dfb
extern "C" {
extern "C" { extern int FUN_004A2A7C; }

extern "C" void __cdecl GEX_Target(int* param_1)
{
    int x = 0x40;
    int y = 0x50000;

    FUN_004A2A7C = 1;
    param_1[0x27] = x;
    param_1[0x28] = x;
    param_1[0x32] = y;
    param_1[0x33] = y;
    param_1[0x15] = 0;
    param_1[0x29] = 0;
    param_1[0x1e] = 0x9f0000;
    param_1[0x1f] = 0x5b0000;
    param_1[0x2a] = 0;
}
}
