typedef struct GXObject GXObject;
typedef void (__cdecl *GobFunc)(GXObject *);
struct GXObject {
    unsigned char pad0[0x5c];
    GobFunc gob_doit;           /* 0x5c */
};

typedef struct ObjectList {
    GXObject *head;
    int a;
    int b;
} ObjectList;

typedef struct LevelMap {
    int unk0;
    int width;                  /* 0x04 */
    int height;                 /* 0x08 */
} LevelMap;

typedef struct M1Level {
    int unk0;
    LevelMap *map;              /* 0x04 */
    unsigned char pad8[0x14 - 0x8];
    void *tileData;             /* 0x14 */
    unsigned char pad18[0x20 - 0x18];
    void *tiles;                /* 0x20 */
} M1Level;

struct InputRecord {
    unsigned int unknown0, unknown4, previous;
    unsigned int unknownC[6];
};

extern "C" {
extern M1Level *M1_CurrentLevel_004a2990;
extern int DAT_004626f4_InitialiseLevel;
extern int DAT_004a2948;
extern char M1_IsLevelDone_004a2a8c;
extern int gNoVFX_004a2958;
extern int M1_IsInMap_004a2a7c;
extern int level_004a2964;
extern void (__cdecl *PTR_GOB_DoIt_00458ed4)(GXObject *);
extern void (__cdecl *PTR_GOB_DrawList_00458ed8)(GXObject *);
extern char s_Intro_Objects_00455e28[];
extern char s_ProcessBlockAnims_00455e14[];
extern char s_ProcessTileAnims_00455e00[];
extern char s_Process_Objects_00455dec[];
extern char s_Process_Collisions_00455dd8[];
extern char s_Set_Scroll_Position_00455dc0[];
extern char s_Draw_Tiles_00455db4[];
extern char s_Draw_Objects_Mid_00455da0[];
extern char s_Draw_Objects_Hi_00455d8c[];
extern int gNoProcess_00455c4c;
extern int DAT_004a2ad0_Objects;
extern int M1_NumIntros_004626fc;
extern void **M1_ObjectIntroTrackerTable_004a2a78;
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int gNodrawLevel_004a288c;
extern GXObject *gPlayerObject_004a27fc;
extern ObjectList ListType_ARRAY_004a28a0[10];
extern int DAT_004a2974_CameraX_TrueCam2;
extern int DAT_004a2988_CameraY_TrueCam2;
extern short DAT_004a2a96_CameraX_After;
extern short M1_004a2a94;
extern int DAT_004a2abc_EnableParallaxBackground;
extern int DAT_004a293c_CameraX_After2;
extern int DAT_004a2978_CameraY_After2;
extern int gDrawObs_004a2a24;
extern void *PTR_004a2ae8;
extern int gNoDrawTiles_004a2a20;
extern int DAT_004a2960_PausedUnk;
extern int DAT_004626ec;
extern int gDemoShowing_004a2a0c;
extern int gTimer_004a2ac8;
extern char *STRING_DEMO_00488008;
extern char *STRING_PRESSJUMPTOSTART_0048a02c;
extern int gFreezeGame_004a294c;
extern int DAT_00455c48;
extern InputRecord *gInputRecords_004a27dc;
extern int DAT_004a2a3c;
extern int LEVELID_004a2a98;
extern int DAT_004626f0_PrevGameTypeSwitchCase;
extern int gGameState_00455c3c;
int __cdecl GEX_WidescreenWidth(void);
void __cdecl GFX_Fade_0043f490(int, int, int, int, int, int, int);
void __cdecl GXINP_ReadPads_0041fc40(void);
void __cdecl VFX_Update_0041faf0(void);
void __cdecl GOB_DoIt_0040ef40(GXObject *);
void __cdecl GOB_DrawList_0040efa0(GXObject *);
void __cdecl TracePrintf_Debug_00405390(const char *, ...);
void __cdecl OBI_IntroduceObjects_0040f910(void *, int, int, int);
void __cdecl M1_ProcessBlockAnims_0041f710(M1Level *);
void __cdecl M1_ProcessTileAnims_0041f7a0(M1Level *);
void __cdecl CheckInputCodes_00409f00(void);
void __cdecl CLD_ProcessCollisions_0041e5c0(void);
void __cdecl CAMERA_SomeKindOfLogic_00410280(void);
void __cdecl FUN_00410c60_CameraFollowGex(void);
void __cdecl RM_DrawTiles_0043fb40(LevelMap *, void *, int, int);
void __cdecl RM_LinkLoPriCels_00440510(void);
void __cdecl RM_LinkHiPriCels_00440560(void);
void __cdecl FUN_00410250_UpdateCameraBounds(void);
void __cdecl FUN_00417d90_COLLISIONS(void);
void __cdecl ProcessPaused_0041bfc0(GXObject *);
int __cdecl FUN_00402fa0_GetFrameTimingValue(void);
int __cdecl TXT_PixelLength_0043fae0(char *text);
void __cdecl TXT_DrawPrintFP_0043faa0(int x, int y, char *fmt, ...);
void __cdecl FUN_0043f310_InitializeGraphicsVariables(void);
int __cdecl UpdateTimer_00405120(void);
void __cdecl CEL_DrawCels_0043db70(int);
void __cdecl FUN_004053a0_SaveScreenshotAndPauseGame(void);
void __cdecl FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(int);
void __cdecl FUN_0040b2d0_InputProcessing(void);
void __cdecl FUN_0043db50_UpdateGraphicsState(void);
void __cdecl FUN_00409970_BetweenLevelsTVFuzz(void);
int __cdecl ReadControllerNoPlayback_0040f400(int);

int __cdecl M1_PlayLevel_0040a010(M1Level *level)
{
    int i;
    GobFunc doit;
    int running;
    int viewportFixed = GEX_WidescreenWidth() << 16;

    M1_CurrentLevel_004a2990 = level;
    if (DAT_004626f4_InitialiseLevel) {
        DAT_004626f4_InitialiseLevel = 0;
        if (DAT_004a2948 != 1)
            GFX_Fade_0043f490(8, 0, 0xff, 0, 0xff, 0, 0xff);
    }
    if (M1_IsLevelDone_004a2a8c) {
        if (!gNoVFX_004a2958 && (level_004a2964 < 0x3f || level_004a2964 > 0x45)) {
            level_004a2964 = 0x3f;
            M1_IsInMap_004a2a7c = 1;
        } else
            M1_IsLevelDone_004a2a8c = 0;
    }
    GXINP_ReadPads_0041fc40();
    if (!gNoVFX_004a2958)
        VFX_Update_0041faf0();
    PTR_GOB_DoIt_00458ed4 = GOB_DoIt_0040ef40;
    PTR_GOB_DrawList_00458ed8 = GOB_DrawList_0040efa0;
    TracePrintf_Debug_00405390(s_Intro_Objects_00455e28);
    i = 0;
    if (!gNoProcess_00455c4c && !DAT_004a2ad0_Objects)
        for (; i < M1_NumIntros_004626fc; i++)
            OBI_IntroduceObjects_0040f910(M1_ObjectIntroTrackerTable_004a2a78[i], CAMERA_XPos_004a2a38, CAMERA_YPos_004a2a1c, 0);
    if (!gNodrawLevel_004a288c) {
        TracePrintf_Debug_00405390(s_ProcessBlockAnims_00455e14);
        M1_ProcessBlockAnims_0041f710(M1_CurrentLevel_004a2990);
        TracePrintf_Debug_00405390(s_ProcessTileAnims_00455e00);
        M1_ProcessTileAnims_0041f7a0(M1_CurrentLevel_004a2990);
    }
    TracePrintf_Debug_00405390(s_Process_Objects_00455dec);
    CheckInputCodes_00409f00();
    if (!gNoProcess_00455c4c) {
        if (gPlayerObject_004a27fc) {
            doit = gPlayerObject_004a27fc->gob_doit;
            gPlayerObject_004a27fc->gob_doit = 0;
        }
        PTR_GOB_DoIt_00458ed4(ListType_ARRAY_004a28a0[0].head);
        PTR_GOB_DoIt_00458ed4(ListType_ARRAY_004a28a0[1].head);
        PTR_GOB_DoIt_00458ed4(ListType_ARRAY_004a28a0[2].head);
        PTR_GOB_DoIt_00458ed4(ListType_ARRAY_004a28a0[3].head);
        PTR_GOB_DoIt_00458ed4(ListType_ARRAY_004a28a0[4].head);
        PTR_GOB_DoIt_00458ed4(ListType_ARRAY_004a28a0[5].head);
        PTR_GOB_DoIt_00458ed4(ListType_ARRAY_004a28a0[6].head);
        PTR_GOB_DoIt_00458ed4(ListType_ARRAY_004a28a0[7].head);
        PTR_GOB_DoIt_00458ed4(ListType_ARRAY_004a28a0[8].head);
        if (gPlayerObject_004a27fc) {
            gPlayerObject_004a27fc->gob_doit = doit;
            doit(gPlayerObject_004a27fc);
        }
        TracePrintf_Debug_00405390(s_Process_Collisions_00455dd8);
        CLD_ProcessCollisions_0041e5c0();
        TracePrintf_Debug_00405390(s_Set_Scroll_Position_00455dc0);
        CAMERA_SomeKindOfLogic_00410280();
        PTR_GOB_DoIt_00458ed4(ListType_ARRAY_004a28a0[9].head);
        FUN_00410c60_CameraFollowGex();
    }
    DAT_004a2a96_CameraX_After = DAT_004a2974_CameraX_TrueCam2 >> 16;
    M1_004a2a94 = DAT_004a2988_CameraY_TrueCam2 >> 16;
    DAT_004a2974_CameraX_TrueCam2 = CAMERA_XPos_004a2a38 & 0xffff0000;
    DAT_004a2988_CameraY_TrueCam2 = CAMERA_YPos_004a2a1c & 0xffff0000;
    if (DAT_004a2974_CameraX_TrueCam2 < 0)
        DAT_004a2974_CameraX_TrueCam2 = 0;
    if (DAT_004a2988_CameraY_TrueCam2 < 0)
        DAT_004a2988_CameraY_TrueCam2 = 0;
    if (M1_CurrentLevel_004a2990->map->width - viewportFixed <= DAT_004a2974_CameraX_TrueCam2)
        DAT_004a2974_CameraX_TrueCam2 = M1_CurrentLevel_004a2990->map->width - viewportFixed - 0x10000;
    if (DAT_004a2974_CameraX_TrueCam2 < 0) DAT_004a2974_CameraX_TrueCam2 = 0;
    if (M1_CurrentLevel_004a2990->map->height - 0xf00000 <= DAT_004a2988_CameraY_TrueCam2)
        DAT_004a2988_CameraY_TrueCam2 = M1_CurrentLevel_004a2990->map->height - 0xf10000;
    DAT_004a2a96_CameraX_After = ((DAT_004a2974_CameraX_TrueCam2 >> 16) - DAT_004a2a96_CameraX_After) / 2;
    M1_004a2a94 = ((DAT_004a2988_CameraY_TrueCam2 >> 16) - M1_004a2a94) / 2;
    if (DAT_004a2abc_EnableParallaxBackground) {
        DAT_004a293c_CameraX_After2 = DAT_004a2974_CameraX_TrueCam2;
        DAT_004a2978_CameraY_After2 = DAT_004a2988_CameraY_TrueCam2;
    }
    if (gDrawObs_004a2a24 && !gNodrawLevel_004a288c) {
        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[0].head);
        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[1].head);
    }
    PTR_004a2ae8 = M1_CurrentLevel_004a2990->tileData;
    TracePrintf_Debug_00405390(s_Draw_Tiles_00455db4);
    if (!gNoDrawTiles_004a2a20 && !gNodrawLevel_004a288c) {
        RM_DrawTiles_0043fb40(M1_CurrentLevel_004a2990->map, M1_CurrentLevel_004a2990->tiles, DAT_004a2974_CameraX_TrueCam2, DAT_004a2988_CameraY_TrueCam2);
        RM_LinkLoPriCels_00440510();
    }
    TracePrintf_Debug_00405390(s_Draw_Objects_Mid_00455da0);
    if (gDrawObs_004a2a24 && !gNodrawLevel_004a288c) {
        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[2].head);
        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[3].head);
        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[4].head);
        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[5].head);
        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[6].head);
        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[7].head);
    }
    if (!gNoDrawTiles_004a2a20 && !gNodrawLevel_004a288c)
        RM_LinkHiPriCels_00440560();
    TracePrintf_Debug_00405390(s_Draw_Objects_Hi_00455d8c);
    if (gDrawObs_004a2a24 && !gNodrawLevel_004a288c) {
        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[8].head);
        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[9].head);
    }
    FUN_00410250_UpdateCameraBounds();
    if (gPlayerObject_004a27fc && !DAT_004a2960_PausedUnk)
        FUN_00417d90_COLLISIONS();
    if (gNoProcess_00455c4c && !DAT_004a2960_PausedUnk && gNodrawLevel_004a288c)
        ProcessPaused_0041bfc0(gPlayerObject_004a27fc);
    DAT_004626ec = FUN_00402fa0_GetFrameTimingValue();
    if (gDemoShowing_004a2a0c && (gTimer_004a2ac8 & 0x10)) {
        TXT_DrawPrintFP_0043faa0((viewportFixed / 2) - TXT_PixelLength_0043fae0(STRING_DEMO_00488008) / 2, 0x500000, STRING_DEMO_00488008);
        TXT_DrawPrintFP_0043faa0((viewportFixed / 2) - TXT_PixelLength_0043fae0(STRING_PRESSJUMPTOSTART_0048a02c) / 2, 0x640000, STRING_PRESSJUMPTOSTART_0048a02c);
    }
    FUN_0043f310_InitializeGraphicsVariables();
    running = UpdateTimer_00405120();
    running |= gFreezeGame_004a294c;
    CEL_DrawCels_0043db70(running);
    if (gFreezeGame_004a294c == 1) {
        FUN_004053a0_SaveScreenshotAndPauseGame();
        gFreezeGame_004a294c++;
    }
    FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(running);
    FUN_0040b2d0_InputProcessing();
    if (!DAT_00455c48)
        FUN_0043db50_UpdateGraphicsState();
    if (!gNoProcess_00455c4c)
        gTimer_004a2ac8++;
    FUN_00409970_BetweenLevelsTVFuzz();
    if (!gNoVFX_004a2958 && gDemoShowing_004a2a0c && (ReadControllerNoPlayback_0040f400(0) || !gInputRecords_004a27dc->unknownC[0])) {
        level_004a2964 = 0x3f;
        M1_IsInMap_004a2a7c = 1;
    }
    if ((DAT_004a2a3c || level_004a2964 == LEVELID_004a2a98) && DAT_004626f0_PrevGameTypeSwitchCase == gGameState_00455c3c)
        return 1;
    return 0;
}
}
