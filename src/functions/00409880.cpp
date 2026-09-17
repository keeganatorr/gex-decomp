extern "C" {
extern void *GEX_pGlob_004a2ad4;
extern void DRAW_CacheClear_0043e430(int);
extern char s_Loading_GX_Data_00455cb0[];
extern void TracePrintf_Debug_00405390(char *);
extern void *PTR_gIDLDirectory_00455998;
extern void BLOC_LoadBlocks_0040b8c0(void *, int, void *, void *);
extern int DAT_00462704_LoadObjectUnk2;
extern int pGlobOffset_004626f8;
extern int GEX_IsResolving_00462700;
}

extern "C" void GEX_Target(void)
{
    if (GEX_pGlob_004a2ad4 == 0) {
        DRAW_CacheClear_0043e430(1);
        TracePrintf_Debug_00405390(s_Loading_GX_Data_00455cb0);
        BLOC_LoadBlocks_0040b8c0(PTR_gIDLDirectory_00455998, 2, &DAT_00462704_LoadObjectUnk2, &pGlobOffset_004626f8);
        GEX_IsResolving_00462700 = 1;
    }
}
