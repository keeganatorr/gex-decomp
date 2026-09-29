typedef struct GXObject GXObject;
struct GXObject {
    unsigned char _pad0[0x54];
    int f54;
    unsigned char _pad58[0x8];
    void (__cdecl *draw)(GXObject *gob);
    unsigned char _pad64[0x14];
    int xpos;      /* 0x78 */
    int ypos;      /* 0x7c */
    unsigned char _pad80[0x1c];
    char *text;    /* 0x9c */
    unsigned char _pada0[0x14];
    unsigned int fb4;
};
extern "C" {
extern int DAT_00462c80;
extern int gTimer_004a2ac8;
extern char DAT_00456338;
extern char DAT_0045633c;
extern unsigned char gInputControllers_004a0280[];
extern char VK_00487fd4;
extern unsigned char gPasswordEnter_004a0200[];
extern int DAT_00487ff8_FreezeMovementInput;
extern int gPasswordCurrentCharIndex_00462c7c;
extern int DAT_004a291c_LoadLevelUnk1;
extern int DAT_004a2918_LevelObjectsListEnd;
extern int DAT_004a2920_LoadLevelUnk5;
extern int gSFXEnabled_00455c08;
extern int gVFXEnabled_00455c0c;
extern int gMUSEnabled_00455c10;
extern int M1_IsInMap_004a2a7c;
extern char *STRING_WRONG_00487fe4;
void __cdecl SND_PlaySoundNoPosition_0041a360(int sound, int volume);
void __cdecl MainMenuButtonDraw_0040c340(GXObject *gob);
GXObject *__cdecl GOB_FindWithWork0_0040c110(int type, int work);
int __cdecl PasswordIsValid_004295c0(unsigned char *password);
void __cdecl PasswordEnterLevel_00429940(void);
void __cdecl FUN_004099b0_CloseMusic(int flag);
void __cdecl FUN_0040b9f0_Unk(void);

void __cdecl PasswordMenuDraw_0040e6a0(GXObject *gob)
{
    char *oldText;
    int oldX;
    int oldY;
    int oldFrame;
    GXObject *button;
    int i;
    char str[2];

    oldText = gob->text;
    oldX = gob->xpos;
    oldY = gob->ypos;
    oldFrame = gob->f54;
    gob->f54 = -1;
    if (gTimer_004a2ac8 > DAT_00462c80) {
        DAT_00456338 = 0;
        if (gInputControllers_004a0280[0x14] || VK_00487fd4 == 0xd) {
            if (PasswordIsValid_004295c0(gPasswordEnter_004a0200)) {
                PasswordEnterLevel_00429940();
                gSFXEnabled_00455c08 = DAT_004a291c_LoadLevelUnk1;
                gVFXEnabled_00455c0c = DAT_004a2918_LevelObjectsListEnd;
                FUN_004099b0_CloseMusic(1);
                M1_IsInMap_004a2a7c = 1;
                gMUSEnabled_00455c10 = DAT_004a2920_LoadLevelUnk5;
                FUN_0040b9f0_Unk();
                DAT_00487ff8_FreezeMovementInput = 0;
            } else {
                SND_PlaySoundNoPosition_0041a360(0x76, 0xff);
                DAT_00456338 = 1;
                DAT_00462c80 = gTimer_004a2ac8 + 0x1e;
            }
        } else if (gInputControllers_004a0280[0x15] || VK_00487fd4 == 0x1b) {
            gob->xpos = 0x280000;
            gob->ypos = 0x500000;
            gob->text = (char *)gPasswordEnter_004a0200;
            gob->f54 = 0;
            MainMenuButtonDraw_0040c340(gob);
            gob->draw = MainMenuButtonDraw_0040c340;
            DAT_0045633c = 0;
            button = GOB_FindWithWork0_0040c110(0x7b, 1);
            button->fb4 &= ~1;
            button = GOB_FindWithWork0_0040c110(0x7b, 2);
            button->fb4 &= ~1;
            button = GOB_FindWithWork0_0040c110(0x7b, 4);
            button->fb4 |= 1;
            button->draw = MainMenuButtonDraw_0040c340;
            SND_PlaySoundNoPosition_0041a360(0x44, 0xff);
            DAT_00487ff8_FreezeMovementInput = 0;
        } else if (gInputControllers_004a0280[0x11] || VK_00487fd4 == 0x26) {
            if (++gPasswordEnter_004a0200[gPasswordCurrentCharIndex_00462c7c] > 'Z')
                gPasswordEnter_004a0200[gPasswordCurrentCharIndex_00462c7c] = 'A';
            SND_PlaySoundNoPosition_0041a360(0x45, 0xff);
        } else if (gInputControllers_004a0280[0x12] || VK_00487fd4 == 0x28) {
            if (--gPasswordEnter_004a0200[gPasswordCurrentCharIndex_00462c7c] < 'A')
                gPasswordEnter_004a0200[gPasswordCurrentCharIndex_00462c7c] = 'Z';
            SND_PlaySoundNoPosition_0041a360(0x45, 0xff);
        } else if (gInputControllers_004a0280[0xf] || VK_00487fd4 == 0x25 || VK_00487fd4 == 8) {
            if (gPasswordCurrentCharIndex_00462c7c) {
                gPasswordCurrentCharIndex_00462c7c--;
                SND_PlaySoundNoPosition_0041a360(0x45, 0xff);
            }
        } else if (gInputControllers_004a0280[0x10] || VK_00487fd4 == 0x27) {
            if (gPasswordCurrentCharIndex_00462c7c < 7) {
                gPasswordCurrentCharIndex_00462c7c++;
                SND_PlaySoundNoPosition_0041a360(0x45, 0xff);
            }
        } else if ((VK_00487fd4 >= 'a' && VK_00487fd4 <= 'z') || (VK_00487fd4 >= 'A' && VK_00487fd4 <= 'Z')) {
            if (VK_00487fd4 > 'Z')
                VK_00487fd4 -= 0x20;
            if (gPasswordCurrentCharIndex_00462c7c != 7 || gPasswordEnter_004a0200[gPasswordCurrentCharIndex_00462c7c] != VK_00487fd4)
                SND_PlaySoundNoPosition_0041a360(0x45, 0xff);
            gPasswordEnter_004a0200[gPasswordCurrentCharIndex_00462c7c] = VK_00487fd4;
            if (gPasswordCurrentCharIndex_00462c7c < 7)
                gPasswordCurrentCharIndex_00462c7c++;
        }
    }
    if (DAT_00456338) {
        gob->text = STRING_WRONG_00487fe4;
        gob->xpos = 0x280000;
        gob->ypos = 0x500000;
        gob->f54 = 0;
        MainMenuButtonDraw_0040c340(gob);
    } else {
        gob->text = str;
        str[1] = 0;
        gob->xpos = 0x280000;
        gob->ypos = 0x500000;
        for (i = 0; i < 8; i++) {
            gob->f54 = gPasswordCurrentCharIndex_00462c7c == i ? 0 : -1;
            str[0] = gPasswordEnter_004a0200[i];
            MainMenuButtonDraw_0040c340(gob);
            gob->xpos += 0x120000;
        }
    }
    gob->text = oldText;
    gob->xpos = oldX;
    gob->ypos = oldY;
    gob->f54 = oldFrame;
}
}
