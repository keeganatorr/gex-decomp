typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;
typedef struct M1Level {
    void *handle;
    void *levelData;
} M1Level;
typedef struct BUTTON_RECORD {
    unsigned char buttonLeft, buttonRight, buttonUp, buttonDown;
    unsigned char buttonA, buttonB, buttonC, buttonX, buttonL, buttonR, buttonStart;
    unsigned char unkB[4];
} BUTTON_RECORD;
typedef struct GXInputRecord {
    BUTTON_RECORD gxir_padButtons;        /* 0x0 */
    BUTTON_RECORD gxir_padJustOnButtons;  /* 0xf */
    unsigned char _pad1e[2];
    int gxir_dValue;                      /* 0x20 */
} GXInputRecord;
extern "C" {
extern GXInputRecord gInputControllers_004a0280[];
extern LevelEntry DAT_004577B0[];
extern int DAT_00455c44;
extern int level_004a2964;
extern M1Level *PTR_M1_00455b84;
extern M1Level *PTR_M1_00455b80;
extern void *gLevelDir_00455b7c;
extern int gNoVFX_004a2958;
extern int M1_IsLoadingMapLevel_004a296c;
extern int OIN_DefaultIntroDist_00455b70;
extern int OIN_DefaultIntroRemoveDist_00455b74;
extern int M1_004a2994;
extern int M1_IsInMap_004a2a7c;
extern int M1_004a2a80;
extern int gGameState_00455c3c;
void __cdecl M1_FreeLevel_0040aa60(void);
void __cdecl DRAW_CacheClear_0043e430(int all);
void __cdecl M1_OpenLevelDirs_0040a8c0(void);
void __cdecl M1_LoadLevel_0041ebe0(void *dir, M1Level *level, int mode);
void __cdecl M1_ResolveMap_0041f2d0(M1Level *level);
void __cdecl FUN_0040a990_LoadLevel_Clean1(void);
void __cdecl M1_EnterLevel_00409a30(M1Level *level);
void __cdecl FUN_00409fe0_RestartHWND(void);
int __cdecl M1_PlayLevel_0040a010(M1Level *level);
int __cdecl M1_StreamLevel_0041ecd0(M1Level *level);
void __cdecl M1_ExitLevel_0040a660(M1Level *level);
void __cdecl M1_UnloadLevel_0041f6f0(M1Level *level);
void __cdecl GEX_Target(void)
{
    M1_FreeLevel_0040aa60();
    if (DAT_00455c44 && (DAT_004577B0[level_004a2964].info & 0x40)) {
        DRAW_CacheClear_0043e430(0);
        M1_OpenLevelDirs_0040a8c0();
        gNoVFX_004a2958 = 1;
        M1_IsLoadingMapLevel_004a296c = 1;
        M1_LoadLevel_0041ebe0(gLevelDir_00455b7c, PTR_M1_00455b84, 5);
        while (!PTR_M1_00455b84->levelData)
            ;
        M1_ResolveMap_0041f2d0(PTR_M1_00455b84);
        M1_IsLoadingMapLevel_004a296c = 0;
    }
    FUN_0040a990_LoadLevel_Clean1();
    if (gNoVFX_004a2958) {
        OIN_DefaultIntroDist_00455b70 = 0xa00000;
        OIN_DefaultIntroRemoveDist_00455b74 = 0xc00000;
        M1_EnterLevel_00409a30(PTR_M1_00455b84);
        M1_004a2994 = 1;
        M1_IsInMap_004a2a7c = 1;
        FUN_00409fe0_RestartHWND();
        while (M1_PlayLevel_0040a010(PTR_M1_00455b84) && !gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonA && !gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB && !gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonC && !M1_004a2a80)
            M1_StreamLevel_0041ecd0(PTR_M1_00455b80);
        M1_ExitLevel_0040a660(PTR_M1_00455b84);
    }
    while (!M1_StreamLevel_0041ecd0(PTR_M1_00455b80))
        ;
    if (gNoVFX_004a2958) {
        M1_UnloadLevel_0041f6f0(PTR_M1_00455b84);
        gNoVFX_004a2958 = 0;
    }
    gGameState_00455c3c = 1;
    DRAW_CacheClear_0043e430(0);
}
}
