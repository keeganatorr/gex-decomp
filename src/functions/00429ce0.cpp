typedef struct GXObject {
    char pad0[8];
    int type;                   /* 0x08 */
    char pad0c[0x48];
    int frame;                  /* 0x54 */
    char pad58[0x18];
    int state;                  /* 0x70 */
    int tvX;                    /* 0x74 */
    int xpos;                   /* 0x78 */
    int ypos;                   /* 0x7c */
    int zoomStepX;              /* 0x80 */
    int timer;                  /* 0x84 */
    int zoomX;                  /* 0x88 */
    int zoomStepY;              /* 0x8c */
    int zoomScale;              /* 0x90 */
    int zoomY;                  /* 0x94 */
    int scale;                  /* 0x98 */
    int work1;                  /* 0x9c */
    int selection;              /* 0xa0 */
    int targetScale;            /* 0xa4 */
    int chosenLevel;            /* 0xa8 */
    struct GXObject *remote;    /* 0xac */
    int delay;                  /* 0xb0 */
    int remoteCount;            /* 0xb4 */
    int remoteId;               /* 0xb8 */
    char padbc[0x20];
    int tvY;                    /* 0xdc */
    char pade0[4];
    int steps;                  /* 0xe4 */
    char pade8[0x18];
    int tvTargetX;              /* 0x100 */
    int tvScale;                /* 0x104 */
    int tvStepX;                /* 0x108 */
    int tvStepY;                /* 0x10c */
} GXObject;
typedef struct BUTTON_RECORD {
    unsigned char buttonLeft, buttonRight, buttonUp, buttonDown;
    unsigned char buttonA, buttonB, buttonC, buttonX, buttonL, buttonR, buttonStart;
    unsigned char unkB[4];
} BUTTON_RECORD;
typedef struct GXInputRecord {
    BUTTON_RECORD gxir_padButtons;
    BUTTON_RECORD gxir_padJustOnButtons;
    unsigned char _pad1e[2];
    int gxir_dValue;
} GXInputRecord;
extern "C" {
extern GXInputRecord gInputControllers_004a0280[];
extern char VK_00487fd4;
extern int DAT_00463b68;
extern int gHasShownMapRemoteTutorial_00463b08;
extern int gShowMapTutorials_004a0210;
extern char *STRING_PRESSTAILWHIPTOTURNONATV_00487ff4;
extern char *STRING_CHOOSEREMOTEANDPRESSJUMP_0048a020;
extern char *DAT_0048a024_PressAnyKeyToContinue;
extern int level_004a2964;
extern unsigned char BYTE_ARRAY_004a2540[];
extern unsigned char BYTE_ARRAY_004a25d0[];
extern unsigned char DAT_0045adf8[];
extern unsigned char gStartDoorIDs_004a2710[];
extern int DAT_0045acc4_ProcessedTitleScreenCheat;
extern int INT_ARRAY_ARRAY_00463b10[][2];
extern unsigned char gCurrentCheatCode_00455b38;
extern int M1_IsInMap_004a2a7c;
extern int gGameState_00455c3c;
extern int DAT_0045acd0_animationFrame[];
extern int DAT_0045ad00[];
extern char s_ERROR__Couldn_t_find_GX_on_map_0045af04[];
extern char s_ERROR__Remote_is_not_for_TV_in_t_0045aed4[];
unsigned int __cdecl FUN_0041a680(void);
int __cdecl FUN_0042a630_Gex_Frames(GXObject *gob);
void __cdecl HelpBoxNew_0040d5f0(int x, int y, char *text, int kind);
int __cdecl GetRemoteStatus_0041a590(int n);
void __cdecl SND_PlaySoundNoPosition_0041a360(int sound, int volume);
GXObject *__cdecl FUN_00429bd0_Object_unk(void);
GXObject *__cdecl GOB_FindFirstWithType_00429c60(int type);
void __cdecl assertfail_00405350(char *format, ...);
int __cdecl FUN_00429c90_RemoteUnk(void);
int __cdecl FUN_0042a5d0_RemoteUnk(GXObject *gob, int id);
int __cdecl FUN_0042a560_RemoteUnk(GXObject *gob, int id);
int __cdecl FUN_00429cb0_RemoteTVSelect_Unk1(int a, int b);
GXObject *__cdecl RemoteFindWithLevel_00429b40(int lvl);
GXObject *__cdecl FUN_00429b80_Object_unk(void);
GXObject *__cdecl FUN_00429c10_Object_unk(int lvl);
void __cdecl GEX_Target(GXObject *gob)
{
    unsigned int r;
    GXObject *o;
    int lvl;
    GXObject *remote;

    switch (gob->state) {
    case 0:
        r = FUN_0041a680();
        if (r != 4) {
            if (r == 3) {
                if (!DAT_0045acc4_ProcessedTitleScreenCheat) {
                    gob->targetScale = 0xffc00000;
                    gob->state = 6;
                    SND_PlaySoundNoPosition_0041a360(0x48, 0xff);
                    o = FUN_00429bd0_Object_unk();
                    if (o) {
                        gob->zoomStepX = (o->xpos - 0xa00000 + 19) / 20;
                        gob->zoomStepY = (o->ypos - 0x500000 + 19) / 20;
                    } else {
                        gob->zoomStepX = 0;
                        gob->zoomStepY = 0x20000;
                    }
                    gob->zoomX = 0xa00000;
                    gob->zoomY = 0x500000;
                    gob->zoomScale = 0x10000;
                    gob->timer = 0x32;
                    return;
                }
            } else {
                o = GOB_FindFirstWithType_00429c60(0xdf);
                if (!o)
                    assertfail_00405350(s_ERROR__Couldn_t_find_GX_on_map_0045af04);
                gob->remoteId = (r & 0xffff00) >> 8;
                BYTE_ARRAY_004a25d0[gob->remoteId] = (r >> 24 & 0xf) + 1;
                BYTE_ARRAY_004a2540[gob->remoteId] |= DAT_0045adf8[r & 0xff];
                gob->targetScale = 0x180000;
                gob->remoteCount = FUN_00429c90_RemoteUnk();
                DAT_00463b68 = 1;
                gob->state = 7;
                if (gob->scale != gob->targetScale)
                    SND_PlaySoundNoPosition_0041a360(0x48, 0xff);
                gob->selection = FUN_0042a5d0_RemoteUnk(gob, gob->remoteId);
                gob->tvX = o->xpos;
                gob->tvY = o->ypos;
                gob->tvTargetX = FUN_0042a560_RemoteUnk(gob, gob->remoteId);
                gob->tvScale = 0x4000;
                gob->steps = 0x14;
                gob->tvStepX = (gob->tvTargetX - gob->tvX + 19) / 20;
                gob->tvStepY = (0x360000 - gob->tvY + 19) / 20;
                return;
            }
        } else {
            if (!gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonC && VK_00487fd4 != 9) {
                FUN_0042a630_Gex_Frames(gob);
                DAT_00463b68 = 0;
                if (gob->remoteCount && gob->scale == 0xffc00000 && !gHasShownMapRemoteTutorial_00463b08 && gShowMapTutorials_004a0210) {
                    gHasShownMapRemoteTutorial_00463b08 = 1;
                    HelpBoxNew_0040d5f0(0xa00000, 0x6e0000, STRING_PRESSTAILWHIPTOTURNONATV_00487ff4, 1);
                }
                if (level_004a2964 == 0x37 && GetRemoteStatus_0041a590(0x15))
                    BYTE_ARRAY_004a2540[52] |= 1;
            } else {
                DAT_00463b68 = 1;
                gob->targetScale = 0x180000;
                gob->state = 1;
                SND_PlaySoundNoPosition_0041a360(0x48, 0xff);
                return;
            }
        }
        break;
    case 1:
        if (FUN_0042a630_Gex_Frames(gob)) {
            if (gob->remoteCount && !INT_ARRAY_ARRAY_00463b10[6][0] && gShowMapTutorials_004a0210) {
                INT_ARRAY_ARRAY_00463b10[6][0] = 1;
                HelpBoxNew_0040d5f0(0xa00000, 0x6e0000, STRING_CHOOSEREMOTEANDPRESSJUMP_0048a020, 2);
            }
            gob->state = 2;
            return;
        }
        break;
    case 2:
        if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonC || VK_00487fd4 == 9 || VK_00487fd4 == 0x1b) {
            gob->targetScale = 0xffc00000;
            SND_PlaySoundNoPosition_0041a360(0x48, 0xff);
            gob->state = 3;
        } else if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonLeft) {
            if (--gob->selection < 0)
                gob->selection = 0;
        } else if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonRight) {
            if (++gob->selection > gob->remoteCount)
                gob->selection = gob->remoteCount;
        } else if ((gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB || VK_00487fd4 == 0xd) && !gob->selection) {
            HelpBoxNew_0040d5f0(0xa00000, 0x6e0000, STRING_CHOOSEREMOTEANDPRESSJUMP_0048a020, 2);
        } else if ((gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB || VK_00487fd4 == 0xd) && gob->remoteCount) {
            lvl = FUN_00429cb0_RemoteTVSelect_Unk1(0, gob->work1 + gob->selection);
            if (level_004a2964 == lvl)
                return;
            if (gInputControllers_004a0280[0].gxir_padButtons.buttonL && gInputControllers_004a0280[0].gxir_padButtons.buttonR)
                gStartDoorIDs_004a2710[lvl] = 0;
            remote = RemoteFindWithLevel_00429b40(lvl);
            if (!remote) {
                if (level_004a2964 == 0x37 || lvl < 0x31 || lvl > 0x36) {
                    assertfail_00405350(s_ERROR__Remote_is_not_for_TV_in_t_0045aed4);
                    return;
                }
                remote = FUN_00429b80_Object_unk();
                if (!remote) {
                    assertfail_00405350(s_ERROR__Remote_is_not_for_TV_in_t_0045aed4);
                    return;
                }
            }
            SND_PlaySoundNoPosition_0041a360(99, 0xff);
            gob->chosenLevel = lvl;
            gob->targetScale = 0xffc00000;
            gob->remote = remote;
            gob->state = 4;
            SND_PlaySoundNoPosition_0041a360(0x48, 0xff);
        }
        switch (gCurrentCheatCode_00455b38) {
        case 0:
            gCurrentCheatCode_00455b38 = 0xb;
            while ((o = GOB_FindFirstWithType_00429c60(0xdc)) != 0) {
                if (o->work1 >= 0)
                    BYTE_ARRAY_004a2540[o->work1] |= 1;
                o->type = -1;
            }
            while ((o = GOB_FindFirstWithType_00429c60(-1)) != 0)
                o->type = 0xdc;
            gob->targetScale = 0xffc00000;
            gob->state = 3;
            SND_PlaySoundNoPosition_0041a360(0x48, 0xff);
            DAT_0045acc4_ProcessedTitleScreenCheat = 1;
            return;
        case 1:
            M1_IsInMap_004a2a7c = 1;
            DAT_0045acc4_ProcessedTitleScreenCheat = 1;
            gCurrentCheatCode_00455b38 = 0xb;
            gGameState_00455c3c = 0;
        }
        return;
    case 3:
        if (FUN_0042a630_Gex_Frames(gob)) {
            gob->state = 0;
            DAT_00463b68 = 0;
            return;
        }
        break;
    case 4:
        if (FUN_0042a630_Gex_Frames(gob)) {
            SND_PlaySoundNoPosition_0041a360(100, 0xff);
            gob->delay = 0x1e;
            gob->state = 5;
            return;
        }
        break;
    case 5:
        if (!gob->delay) {
            BYTE_ARRAY_004a2540[gob->chosenLevel] |= 1;
            if (gob->chosenLevel >= 0x31 && gob->chosenLevel <= 0x36) {
                o = FUN_00429c10_Object_unk(gob->remote->work1);
                gob->remote->work1 = gob->chosenLevel;
                o->work1 = gob->chosenLevel << 16 | o->work1 & 0xffff;
                o->delay = gob->chosenLevel & 0xf | o->delay & 0xffff0000;
                o->selection = (DAT_0045ad00[o->delay & 0xf] + DAT_0045acd0_animationFrame[o->delay & 0xf] - 1) << 16 | DAT_0045acd0_animationFrame[o->delay & 0xf] & 0xffff;
                o->frame = DAT_0045acd0_animationFrame[o->delay & 0xf];
                o->targetScale = o->frame << 16;
                gob->remote->work1 = gob->chosenLevel;
            } else
                BYTE_ARRAY_004a25d0[gob->chosenLevel] = 0;
            gob->remote = 0;
            gob->remoteCount = FUN_00429c90_RemoteUnk();
            gob->selection = 0;
            gob->state = 0;
            DAT_00463b68 = 0;
            return;
        }
        break;
    case 6:
        FUN_0042a630_Gex_Frames(gob);
        if (gob->timer) {
            if (gob->timer == 0x19)
                HelpBoxNew_0040d5f0(gob->xpos, gob->ypos - 0x180000, DAT_0048a024_PressAnyKeyToContinue, 0);
            if (--gob->timer <= 0x14) {
                gob->zoomX += gob->zoomStepX;
                gob->zoomY += gob->zoomStepY;
                gob->zoomScale -= 0xb34;
                return;
            }
        } else
            gob->state = 0;
        break;
    case 7:
        if (FUN_0042a630_Gex_Frames(gob)) {
            gob->state = 8;
            SND_PlaySoundNoPosition_0041a360(100, 0xff);
            return;
        }
        break;
    case 8:
        if (gob->steps) {
            gob->steps--;
            gob->tvX += gob->tvStepX;
            gob->tvY += gob->tvStepY;
            gob->tvScale += 0x99a;
            return;
        }
        gob->targetScale = 0xffc00000;
        gob->remoteId = -1;
        gob->state = 0;
        break;
    }
}
}
