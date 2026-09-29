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

typedef struct GXObject {
    unsigned char pad0[0x0c];
    void *gob_glob;             /* 0x0c */
    unsigned char pad10[0xe0 - 0x10];
    unsigned int gob_flags2;    /* 0xe0 */
    unsigned char pade4[0x204 - 0xe4];
} GXObject;

typedef struct CDIODirectory {
    int unk0;
    int unk4;
    int unk8;
} CDIODirectory;

typedef struct LevelName {
    char *name;
    int level;
} LevelName;


extern int sl_004a026c;
extern LevelName *PTR_PTR_ARRAY_0045a580[];
extern int UINT_ARRAY_0045a578[];
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int DAT_004a2974_CameraX_TrueCam2;
extern int DAT_004a2988_CameraY_TrueCam2;
extern void *PTR_gIDLDirectory_00455998;
extern GXInputRecord gInputControllers_004a0280[];
extern int gLevelSelectSelectedIndex_00463aa0;
extern char DAT_0045a5bc_DebugMenuLevelString[];
extern char s_Press_JUMP_to_Start_0045a5a4[];
extern char s_Press_TAIL_WHIP_to_Exit_0045a588[];
extern int gFreezeGame_004a294c;
extern char M1_IsLevelDone_004a2a8c;
extern int gGameState_00455c3c;
extern int DAT_00455c1c_PlanetXLevelSelect;
extern int DAT_0045acc4_ProcessedTitleScreenCheat;
extern int M1_004a2a80;
extern int gHitpoints_004a281c;
extern int gHitpoints2_00456afc;
extern int level_004a2964;
void __cdecl FUN_004099b0_CloseMusic(int);
void __cdecl DRAW_CacheClear_0043e430(int);
void __cdecl LoadGex_00409880(void);
int __cdecl GX_Resolve_004098d0(void);
int __cdecl CDIO_OpenDirectory_00409350(void *idl, CDIODirectory *dir, int index);
void __cdecl CDIO_CloseDirectory_00409320(CDIODirectory *dir);
void __cdecl BLOC_LoadBlocks_0040b8c0(CDIODirectory *dir, int id, int *base, int **list);
void __cdecl BLOC_WaitForBlocksToLoad_0040b940(int **list);
void __cdecl BLOC_FreeBlocks_0040b860(int base);
int *__cdecl GOB_ResolveLoadObject_0040eb70(int base, int offset);
void __cdecl FUN_0043f450_Unk(void);
void __cdecl GXINP_ReadPads_0041fc40(void);
void __cdecl FUN_00409fe0_RestartHWND(void);
void __cdecl FUN_0043f080_ResetGraphics_Clean1(int);
void __cdecl GOB_DisplayObject_00444590(GXObject *gob);
int __cdecl TXT_PixelLength_0043fae0(char *text);
void __cdecl GFX_DrawRectHelper_00428cc0(int, int, int, int, int, int);
void __cdecl TXT_DrawPrintFP_0043faa0(int x, int y, char *fmt, ...);
int __cdecl UpdateTimer_00405120(void);
void __cdecl CEL_DrawCels_0043db70(int);
void __cdecl FUN_004053a0_SaveScreenshotAndPauseGame(void);
void __cdecl FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(int);
void __cdecl FUN_0040b2d0_InputProcessing(void);
void __cdecl GFX_Fade_0043f490(int, int, int, int, int, int, int);
void __cdecl PAL_WaitForFade_0043f580(void);
void *__cdecl memset(void *, int, unsigned int);

void __cdecl DoLevelSelectScreen_00420300(void)
{
    int running;
    unsigned short blink;
    int *list;
    int done;
    int j;
    CDIODirectory dir;
    int base;
    GXObject obj;
    LevelName *names;
    int i;
    int y;
    int count;

    names = PTR_PTR_ARRAY_0045a580[sl_004a026c];
    count = UINT_ARRAY_0045a578[sl_004a026c];
    CAMERA_XPos_004a2a38 = 0;
    CAMERA_YPos_004a2a1c = 0;
    DAT_004a2974_CameraX_TrueCam2 = 0;
    DAT_004a2988_CameraY_TrueCam2 = 0;
    FUN_004099b0_CloseMusic(1);
    memset(&obj, 0, sizeof(obj));
    DRAW_CacheClear_0043e430(1);
    LoadGex_00409880();
    while (!GX_Resolve_004098d0())
        ;
    CDIO_OpenDirectory_00409350(PTR_gIDLDirectory_00455998, &dir, 3);
    BLOC_LoadBlocks_0040b8c0(&dir, 1, &base, &list);
    BLOC_WaitForBlocksToLoad_0040b940(&list);
    list = GOB_ResolveLoadObject_0040eb70(base, *list);
    obj.gob_glob = list;
    obj.gob_flags2 |= 0x1000000;
    FUN_0043f450_Unk();
    do
        GXINP_ReadPads_0041fc40();
    while (gInputControllers_004a0280[0].gxir_padButtons.buttonStart);
    done = 0;
    FUN_00409fe0_RestartHWND();
    do {
        i = gLevelSelectSelectedIndex_00463aa0 - 4;
        if (i < 0)
            i = count - 1 + i;
        FUN_0043f080_ResetGraphics_Clean1(0);
        GOB_DisplayObject_00444590(&obj);
        if (count - 2 < gLevelSelectSelectedIndex_00463aa0)
            gLevelSelectSelectedIndex_00463aa0 = gLevelSelectSelectedIndex_00463aa0 - count + 1;
        j = i + 4;
        if (j >= count - 1)
            j = j - count + 1;
        j = TXT_PixelLength_0043fae0(names[j].name);
        GFX_DrawRectHelper_00428cc0(0x180000, 0xab0000, j + 0x1b0000, 0x90000, 0x7f00, 0x1f001f00);
        y = 0x8c0000;
        do {
            TXT_DrawPrintFP_0043faa0(0x180000, y, DAT_0045a5bc_DebugMenuLevelString, i, names[i].name);
            i++;
            if (!names[i].name)
                i = 0;
            y += 0x80000;
        } while (y < 0xd40000);
        blink++;
        if ((blink & 7) < 5) {
            TXT_DrawPrintFP_0043faa0(0x5a0000, 0x200000, s_Press_JUMP_to_Start_0045a5a4);
            TXT_DrawPrintFP_0043faa0(0x5a0000, 0x280000, s_Press_TAIL_WHIP_to_Exit_0045a588);
        }
        running = UpdateTimer_00405120();
        running |= gFreezeGame_004a294c;
        CEL_DrawCels_0043db70(running);
        if (gFreezeGame_004a294c == 1) {
            FUN_004053a0_SaveScreenshotAndPauseGame();
            gFreezeGame_004a294c++;
        }
        FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(running);
        FUN_0040b2d0_InputProcessing();
        GXINP_ReadPads_0041fc40();
        if (gInputControllers_004a0280[0].gxir_padButtons.buttonB) {
            done = 1;
            gGameState_00455c3c = 2;
        } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonC || M1_IsLevelDone_004a2a8c) {
            done = 1;
            gGameState_00455c3c = -1;
            M1_IsLevelDone_004a2a8c = 0;
            DAT_00455c1c_PlanetXLevelSelect = 0;
            sl_004a026c = 0;
            DAT_0045acc4_ProcessedTitleScreenCheat = 0;
        } else if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonUp) {
            if (--gLevelSelectSelectedIndex_00463aa0 < 0)
                gLevelSelectSelectedIndex_00463aa0 = count - 2;
        } else if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonLeft) {
            gLevelSelectSelectedIndex_00463aa0 -= 7;
            if (gLevelSelectSelectedIndex_00463aa0 < 0)
                gLevelSelectSelectedIndex_00463aa0 = count - 1 + gLevelSelectSelectedIndex_00463aa0;
        } else if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonDown) {
            gLevelSelectSelectedIndex_00463aa0++;
            if (!names[gLevelSelectSelectedIndex_00463aa0].name)
                gLevelSelectSelectedIndex_00463aa0 = 0;
        } else if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonRight) {
            gLevelSelectSelectedIndex_00463aa0 += 7;
            if (gLevelSelectSelectedIndex_00463aa0 > count - 2)
                gLevelSelectSelectedIndex_00463aa0 += 1 - count;
        }
    } while (!done && !M1_004a2a80);
    GFX_Fade_0043f490(2, 0, 0, 0, 0, 0, 0);
    PAL_WaitForFade_0043f580();
    BLOC_FreeBlocks_0040b860(base);
    CDIO_CloseDirectory_00409320(&dir);
    gHitpoints_004a281c = 3;
    gHitpoints2_00456afc = 3;
    level_004a2964 = names[gLevelSelectSelectedIndex_00463aa0].level - 1;
}
