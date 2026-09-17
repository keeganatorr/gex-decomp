extern "C" {
    extern char DAT_0045ACAC[];
    extern void __cdecl FUN_00405390(int, int);

    int __cdecl GEX_Target(unsigned char *passwordList, int bitOffset, int bitCount)
    {
        int iVar2;
        int iVar3;
        int iVar4;
        int levelNumber;
        int local_4;

        levelNumber = 0;
        local_4 = 0;
        passwordList = passwordList + bitOffset / 8;
        while (bitCount != 0) {
            iVar2 = 8 - (bitOffset & 7);
            iVar4 = iVar2 - bitCount;
            if (iVar4 < 0) {
                iVar4 = 0;
                iVar3 = iVar2;
            }
            else {
                iVar3 = bitCount;
            }
            bitOffset = bitOffset + iVar3;
            bitCount = bitCount - iVar3;
            levelNumber = levelNumber +
                (((unsigned int)(*passwordList >> iVar4) & ((1 << iVar3) - 1)) << local_4);
            local_4 = local_4 + iVar3;
            passwordList = passwordList + 1;
        }
        FUN_00405390((int)&DAT_0045ACAC, levelNumber);
        return levelNumber;
    }
}
