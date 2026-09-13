// Adapted from pc_decomp_backup/src/functions/FUN_00439190.cpp
// Historical source SHA256: d0085fef017887201f9cdc53606d0aa87eaea7714f76aaf569c3f6304bbbcafe
extern "C" {
extern "C" int __cdecl GEX_Target(int sectorIndex)
{
    sectorIndex -= 0x800000;
    if (sectorIndex < 0) sectorIndex += 0x1000000;
    return sectorIndex;
}
}
