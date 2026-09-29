// Adapted from pc_decomp_backup/src/functions/FUN_00439170.cpp
// Historical source SHA256: 0d22fb354aa0f174e29a46fba32ecd19c6c45e05b4e3bcd8b031015176a8805b
extern "C" {
extern "C" int __cdecl FUN_00439170(int sectorIndex)
{
    sectorIndex -= 0x400000;
    if (sectorIndex < 0) sectorIndex += 0x1000000;
    return sectorIndex;
}
}
