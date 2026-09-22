extern "C" {
extern int DAT_00455c44;
extern int level_004a2964;
extern signed char DAT_004577B0[];
extern unsigned int *PTR_M1_00455b84;
extern void *PTR_M1_00455b80;
extern void *gLevelDir_00455b7c;
extern int gNoVFX_004a2958;
extern int M1_IsLoadingMapLevel_004a296c;
extern int OIN_DefaultIntroDist_00455b70;
extern int OIN_DefaultIntroRemoveDist_00455b74;
extern int M1_004a2994;
extern int M1_IsInMap_004a2a7c;
extern int M1_004a2a80;
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern int gGameState_00455c3c;

void M1_FreeLevel_0040aa60(void);
void DRAW_CacheClear_0043e430(int);
void M1_OpenLevelDirs_0040a8c0(void);
void M1_LoadLevel_0041ebe0(void *, unsigned int *, int);
void M1_ResolveMap_0041f2d0(unsigned int *);
void FUN_0040a990_LoadLevel_Clean1(void);
void M1_EnterLevel_00409a30(unsigned int *);
void FUN_00409fe0_RestartHWND(void);
int M1_PlayLevel_0040a010(unsigned int *);
int M1_StreamLevel_0041ecd0(void *);
void M1_ExitLevel_0040a660(unsigned int *);
void M1_UnloadLevel_0041f6f0(unsigned int *);

void GEX_Target(void)
{
    M1_FreeLevel_0040aa60();
    if (DAT_00455c44 != 0 && (DAT_004577B0[level_004a2964 * 8] & 0x40) != 0) {
        DRAW_CacheClear_0043e430(0);
        M1_OpenLevelDirs_0040a8c0();
        gNoVFX_004a2958 = 1;
        M1_IsLoadingMapLevel_004a296c = 1;
        M1_LoadLevel_0041ebe0(gLevelDir_00455b7c, PTR_M1_00455b84, 5);
        while (PTR_M1_00455b84[1] == 0) {
        }
        M1_ResolveMap_0041f2d0(PTR_M1_00455b84);
        M1_IsLoadingMapLevel_004a296c = 0;
    }
    FUN_0040a990_LoadLevel_Clean1();
    if (gNoVFX_004a2958 != 0) {
        OIN_DefaultIntroDist_00455b70 = 0xa00000;
        OIN_DefaultIntroRemoveDist_00455b74 = 0xc00000;
        M1_EnterLevel_00409a30(PTR_M1_00455b84);
        M1_004a2994 = 1;
        M1_IsInMap_004a2a7c = 1;
        FUN_00409fe0_RestartHWND();
        int result = M1_PlayLevel_0040a010(PTR_M1_00455b84);
        while (result != 0 && DAT_004A0293 == 0 && DAT_004A0294 == 0 &&
               DAT_004A0295 == 0 && M1_004a2a80 == 0) {
            M1_StreamLevel_0041ecd0(PTR_M1_00455b80);
            result = M1_PlayLevel_0040a010(PTR_M1_00455b84);
        }
        M1_ExitLevel_0040a660(PTR_M1_00455b84);
    }
    while (M1_StreamLevel_0041ecd0(PTR_M1_00455b80) == 0) {
    }
    if (gNoVFX_004a2958 != 0) {
        M1_UnloadLevel_0041f6f0(PTR_M1_00455b84);
        gNoVFX_004a2958 = 0;
    }
    gGameState_00455c3c = 1;
    DRAW_CacheClear_0043e430(0);
}
}
