extern "C" {
    extern void *GEX_pGlob_004a2ad4;
    extern int FUN_00462700;
    extern int *DAT_004626F8;
    extern int DAT_00462704_LoadObjectUnk2;
    extern long DAT_004A2924;
    extern void FUN_00405390(const char *, ...);
    extern void *FUN_0040EB70(int, int);

    int GX_Resolve_004098d0(void)
    {
        if (GEX_pGlob_004a2ad4 == 0 && FUN_00462700 != 0)
        {
            if (DAT_004626F8 == 0)
            {
                return 0;
            }
            FUN_00462700 = 0;
            FUN_00405390((const char *)0x455cd8);
            GEX_pGlob_004a2ad4 = FUN_0040EB70(DAT_00462704_LoadObjectUnk2, *DAT_004626F8);
            FUN_00405390((const char *)0x455cc4, DAT_004A2924);
        }
        return 1;
    }
}