// Adapted from pc_decomp_backup/src/functions/FUN_004297B0.cpp
// Historical source SHA256: 6719adedfa083b154ec80db1d5f683dec809e1ba8efc6e805d118adcdb1b2d9d
extern "C" {
extern "C" { extern int DAT_0045ACAC; }
extern "C" void __cdecl FUN_00405390(int, int);

extern "C" int __cdecl GEX_Target(int* passwordList, unsigned int bitOffset, int bitCount)
{
    unsigned char* pbVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int levelNumber;
    int local_4;

    levelNumber = 0;
    local_4 = 0;
    pbVar1 = (unsigned char*)((int)passwordList + ((int)(bitOffset + ((int)bitOffset >> 0x1f & 7)) >> 3));
    while (bitCount != 0) {
        iVar2 = 8 - (bitOffset & 7);
        iVar4 = iVar2 - bitCount;
        iVar3 = bitCount;
        if (iVar4 < 0) {
            iVar4 = 0;
            iVar3 = iVar2;
        }
        bitOffset = bitOffset + iVar3;
        levelNumber = levelNumber + (((unsigned int)(*pbVar1 >> (iVar4 & 0x1f)) & ((1 << (iVar3 & 0x1f)) - 1)) << (local_4 & 0x1f));
        local_4 = local_4 + iVar3;
        pbVar1 = pbVar1 + 1;
        bitCount = bitCount - iVar3;
    }
    FUN_00405390((int)&DAT_0045ACAC, levelNumber);
    return levelNumber;
}
}
