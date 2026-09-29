extern "C" {
extern int LEVELID_00455c40;
extern volatile int level_004a2964;
extern int DAT_004a2954_DrawTiles;
extern int nblocksFree_004a2924;
extern char *gLevelDir_00455b7c;
extern char *PTR_M1_00455b80;
extern char s_Load_Level_ld_00455e5c[];
extern char s_freeblocks_ld_00455cc4[];
void __cdecl DRAW_CacheClear_0043e430(int all);
void __cdecl FUN_0043f080_ResetGraphics_Clean1(int all);
void __cdecl PAR_ClearParallaxs_004202d0(void);
void __cdecl M1_OpenLevelDirs_0040a8c0(void);
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
int __cdecl M1_LoadLevel_0041ebe0(char *directory, char *name, int flags);
void __cdecl FUN_0040a990_LoadLevel_Clean1(void)
{
    if (LEVELID_00455c40 < 0) {
        DRAW_CacheClear_0043e430(1);
        FUN_0043f080_ResetGraphics_Clean1(1);
        PAR_ClearParallaxs_004202d0();
        DAT_004a2954_DrawTiles = 0;
        LEVELID_00455c40 = level_004a2964;
        M1_OpenLevelDirs_0040a8c0();
        TracePrintf_Debug_00405390(s_Load_Level_ld_00455e5c, level_004a2964);
        TracePrintf_Debug_00405390(s_freeblocks_ld_00455cc4, nblocksFree_004a2924);
        M1_LoadLevel_0041ebe0(gLevelDir_00455b7c, PTR_M1_00455b80, 4);
    }
}
}
