// Adapted from pc_decomp_backup/src/functions/FUN_00432650.cpp
// Historical source SHA256: d3885aac53b7200bffa73e917fa290d89786e78841730913522b722bc24fa2a6
extern "C" {
extern "C" void __cdecl GEX_Target(void* param_1)
{
    unsigned int* p = (unsigned int*)param_1;
    p[0x14] = 0x1D;
    p[0x34] = 0x00200000;
    p[0x37] = 0xFFFFF600;
    p[0x28] = 2;
}
}
