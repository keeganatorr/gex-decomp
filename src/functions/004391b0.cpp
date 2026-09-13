// Adapted from pc_decomp_backup/src/functions/FUN_004391B0.cpp
// Historical source SHA256: 27a440268f5b29929477f012f955eb1adb8f0db56fa54222ff951155d2ca1650
extern "C" {
extern "C" int __cdecl GEX_Target(int sectorIndex)
{
    sectorIndex -= 0xC00000;
    if (sectorIndex < 0) sectorIndex += 0x1000000;
    return sectorIndex;
}
}
