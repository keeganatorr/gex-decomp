extern "C" {
    extern int DAT_004a2954_DrawTiles;
    extern void *PTR_M1_00455b80;
    extern int nblocksFree_004a2924;
    extern char s_freeblocks_00455cc4[];
    void GFX_Init_0043f2f0(void);
    int M1_StreamLevel_0041ecd0(void *);
    void M1_ResolveMap_0041f2d0(void *);
    void TracePrintf_Debug_00405390(char *, int);
}

extern "C" void GEX_Target(void)
{
    int iVar1;
    if (DAT_004a2954_DrawTiles == 0) {
        DAT_004a2954_DrawTiles = 1;
        do {
            GFX_Init_0043f2f0();
            iVar1 = M1_StreamLevel_0041ecd0(PTR_M1_00455b80);
        } while (iVar1 == 0);
        M1_ResolveMap_0041f2d0(PTR_M1_00455b80);
        TracePrintf_Debug_00405390(s_freeblocks_00455cc4, nblocksFree_004a2924);
    }
}
