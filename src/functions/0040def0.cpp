typedef struct GXObject GXObject;
struct GXObject {
    unsigned char _pad0[0x60];
    void (__cdecl *draw)(GXObject *gob);
    unsigned char _pad64[0xc];
    int f70;
    unsigned char _pad74[0xc];
    int f80;
    unsigned char _pad84[0x8];
    int f8c;
    unsigned char _pad90[0x4];
    int f94;
    unsigned char _pad98[0x4];
    int f9c;
    int fa0;
    unsigned char _pada4[0x4];
    int fa8;
    unsigned char _padac[0x4];
    int fb0;
    int fb4;
};
extern "C" {
extern char DAT_0045633c;
extern char DAT_00456338;
extern int gTimer_004a2ac8;
extern int DAT_00455c1c_PlanetXLevelSelect;
extern unsigned char gInputControllers_004a0280[];
extern int gxir_dValue_004a02a0;
extern int gGameState_00455c3c;
extern unsigned char gCurrentCheatCode_00455b38;
extern unsigned char BYTE_ARRAY_004a2540[];
extern int DAT_0045acc4_ProcessedTitleScreenCheat;
extern int level_004a2964;
extern int sl_004a026c;
extern char VK_00487fd4;
extern int DAT_00462c84;
extern int DAT_00455c34_LEV_Variable;
extern unsigned char gRemapTable5_0045a17d;
extern unsigned char gRemapTable6_0045a17e;
extern int gDemoLevels_00456340[];
extern int gDemoQueued_004a2ac4;
extern int M1_IsInMap_004a2a7c;
extern int DAT_004a291c_LoadLevelUnk1;
extern int DAT_004a2918_LevelObjectsListEnd;
extern int DAT_004a2920_LoadLevelUnk5;
extern int gSFXEnabled_00455c08;
extern int gVFXEnabled_00455c0c;
extern int gMUSEnabled_00455c10;
extern int gPasswordCurrentCharIndex_00462c7c;
extern int DAT_00462c80;
extern int DAT_00487ff8_FreezeMovementInput;
void __cdecl FUN_0040e520_Music_unk(GXObject *gob);
void __cdecl FUN_0040e3f0_frameIndex4(GXObject *gob);
void __cdecl FUN_0040e2f0_y_velocity(GXObject *gob);
int __cdecl FUN_0040c1a0(int item, int direction);
void __cdecl SND_PlaySoundNoPosition_0041a360(int sound, int volume);
int __cdecl GX_Resolve_004098d0(void);
void __cdecl MUS_Stop_00402f70(int a, int b);
void __cdecl PasswordEnterLevel_00429940(void);
void __cdecl FUN_004099b0_CloseMusic(int flag);
void __cdecl FUN_0040b9f0_Unk(void);
void __cdecl FUN_00404f70_PostMessage_Unk(void);
GXObject *__cdecl GOB_FindWithWork0_0040c110(int type, int work);
void __cdecl PasswordMenuDraw_0040e6a0(GXObject *gob);
void __cdecl PasswordKeyHintsDraw_0040ea90(GXObject *gob);

void __cdecl MainMenuControllerDraw_0040def0(GXObject *gob)
{
    int dir;
    GXObject *button;

    if (DAT_0045633c)
        return;
    FUN_0040e520_Music_unk(gob);
    switch (gob->f70) {
    case 0:
        if (gob->fb4 + 15 <= gTimer_004a2ac8) {
            gob->f9c = 0x12c0000;
            gob->fa0 = 0xf00000;
            gob->fa8 = 0xfe0000;
            gob->f8c = 0xc90000;
            gob->f94 = 0;
            gob->f80 = 0x10000;
            gob->f70++;
        }
        break;
    case 1:
        FUN_0040e3f0_frameIndex4(gob);
        if (gob->fb4 + 0x2d <= gTimer_004a2ac8)
            gob->f70++;
        break;
    case 2:
        FUN_0040e3f0_frameIndex4(gob);
        FUN_0040e2f0_y_velocity(gob);
        break;
    }
    if (DAT_00455c1c_PlanetXLevelSelect && gInputControllers_004a0280[0x16])
        gGameState_00455c3c = 0;
    if (gInputControllers_004a0280[0x11])
        dir = 0x10;
    else
        dir = gInputControllers_004a0280[0x12] ? 0x20 : 0;
    if (gob->fb0 && dir) {
        gob->fb0 = FUN_0040c1a0(gob->fb0, dir | 4);
        FUN_0040c1a0(gob->fb0, 10);
        SND_PlaySoundNoPosition_0041a360(0x45, 0xff);
    }
    switch (gCurrentCheatCode_00455b38) {
    case 9:
        BYTE_ARRAY_004a2540[28] |= 2;
        BYTE_ARRAY_004a2540[29] |= 2;
        BYTE_ARRAY_004a2540[30] |= 2;
        BYTE_ARRAY_004a2540[31] |= 2;
        BYTE_ARRAY_004a2540[62] |= 2;
        BYTE_ARRAY_004a2540[136] |= 2;
        BYTE_ARRAY_004a2540[137] |= 2;
        BYTE_ARRAY_004a2540[138] |= 2;
        gCurrentCheatCode_00455b38 = 0xb;
        gGameState_00455c3c = 4;
        DAT_0045acc4_ProcessedTitleScreenCheat = 1;
        break;
    case 10:
        gCurrentCheatCode_00455b38 = 0xb;
        level_004a2964 = 0;
        gGameState_00455c3c = 3;
        DAT_00455c1c_PlanetXLevelSelect = 1;
        sl_004a026c = 1;
        DAT_0045acc4_ProcessedTitleScreenCheat = 1;
        break;
    }
    if (gInputControllers_004a0280[0x14] || VK_00487fd4 == 0xd) {
        switch (gob->fb0) {
        case 1:
            PasswordEnterLevel_00429940();
            gSFXEnabled_00455c08 = DAT_004a291c_LoadLevelUnk1;
            gVFXEnabled_00455c0c = DAT_004a2918_LevelObjectsListEnd;
            FUN_004099b0_CloseMusic(1);
            M1_IsInMap_004a2a7c = 1;
            gMUSEnabled_00455c10 = DAT_004a2920_LoadLevelUnk5;
            FUN_0040b9f0_Unk();
            return;
        case 2:
            FUN_00404f70_PostMessage_Unk();
            SND_PlaySoundNoPosition_0041a360(0x44, 0xff);
            return;
        case 3:
            button = GOB_FindWithWork0_0040c110(0x7b, 1);
            button->fb4 |= 1;
            button = GOB_FindWithWork0_0040c110(0x7b, 2);
            button->fb4 |= 1;
            button = GOB_FindWithWork0_0040c110(0x7b, 3);
            button->draw = PasswordMenuDraw_0040e6a0;
            button = GOB_FindWithWork0_0040c110(0x7b, 4);
            button->fb4 &= ~1;
            button->draw = PasswordKeyHintsDraw_0040ea90;
            gPasswordCurrentCharIndex_00462c7c = 0;
            DAT_00462c80 = gTimer_004a2ac8 + 2;
            DAT_0045633c = 1;
            DAT_00456338 = 0;
            DAT_00487ff8_FreezeMovementInput = 1;
            SND_PlaySoundNoPosition_0041a360(0x44, 0xff);
            return;
        }
        return;
    }
    if (gxir_dValue_004a02a0) {
        DAT_00462c84 = 0;
        return;
    }
    if (++DAT_00462c84 > 0x384) {
        if (++DAT_00455c34_LEV_Variable >= 3)
            DAT_00455c34_LEV_Variable = 0;
        gRemapTable5_0045a17d = 6;
        gRemapTable6_0045a17e = 5;
        level_004a2964 = gDemoLevels_00456340[DAT_00455c34_LEV_Variable];
        gDemoQueued_004a2ac4 = 1;
        M1_IsInMap_004a2a7c = 1;
        while (!GX_Resolve_004098d0())
            ;
        gSFXEnabled_00455c08 = DAT_004a291c_LoadLevelUnk1;
        gVFXEnabled_00455c0c = DAT_004a2918_LevelObjectsListEnd;
        if (!DAT_004a2920_LoadLevelUnk5)
            MUS_Stop_00402f70(0, 0);
        gMUSEnabled_00455c10 = DAT_004a2920_LoadLevelUnk5;
    }
}
}
