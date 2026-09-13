// Adapted from pc_decomp_backup/src/functions/FUN_004214D0.cpp
// Historical source SHA256: c394125a7e9e8514bb2edcd0d71b609da59b6ac7f1e5f2f787ab909c0b593025
extern "C" {
extern "C" void __cdecl GEX_Target(void **gex)
{
    int t;
    t = (int)gex[0x25] + (int)gex[0x23];
    gex[0x24] = (void *)((int)gex[0x24] + t);
    t = (int)gex[0x25] + (int)gex[0x23];
    gex[0x24] = (void *)((int)gex[0x24] + t);
    t = (int)gex[0x25] + (int)gex[0x23];
    gex[0x24] = (void *)((int)gex[0x24] + t);
    gex[0x23] = (void *)gex[0x22];
}
}
