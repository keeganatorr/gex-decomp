typedef struct GXObject {
    unsigned char _pad0[0x98];
    int f98;
    unsigned char _pad9c[0x4];
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
} GXObject;
typedef struct LevelEntry {
    unsigned short info;
    unsigned char f2;
    unsigned char f3;
    unsigned char music;
    unsigned char next;
    unsigned char f6;
    unsigned char f7;
} LevelEntry;
typedef struct TitleEntry {
    char *name;
    int level;
} TitleEntry;
extern "C" {
extern int DAT_0045601c_LevelMusicUnk;
extern int DAT_00456020_MusicOnUnk;
extern unsigned char gInputControllers_004a0280[];
extern int gGameState_00455c3c;
extern int M1_IsInMap_004a2a7c;
extern int level_004a2964;
extern int DAT_004a291c_LoadLevelUnk1;
extern int DAT_004a2918_LevelObjectsListEnd;
extern int DAT_004a2920_LoadLevelUnk5;
extern int gSFXEnabled_00455c08;
extern int gVFXEnabled_00455c0c;
extern int gMUSEnabled_00455c10;
extern char DAT_00462c70;
extern int DAT_00462c68;
extern int DAT_004a2a00;
extern TitleEntry PTR_s_Title_00456038[];
extern LevelEntry DAT_004577B0[];
extern int DAT_00456228[];
int __cdecl FUN_00402eb0_Return1(void);
void __cdecl MUS_QueuePlay_00402e70(unsigned char music);
void __cdecl MUS_PlayMusic_00402f30(void);
void __cdecl MUS_Stop_00402f70(int a, int b);
void __cdecl FUN_0040c940(void);
void __cdecl SND_PlaySoundNoPosition_0041a360(int sound, int volume);
void __cdecl FUN_004099b0_CloseMusic(int flag);
void __cdecl FUN_0040ca70(GXObject *gob, int item);
void __cdecl FUN_0040cca0(GXObject *gob);
GXObject *__cdecl GOB_FindWithWork0_0040c110(int type, int work);
void __cdecl FUN_0040cb70_Set_Active_Gex_Object(int item, int *key);

void __cdecl ob212DoIt_0040c540(GXObject *gob)
{
    GXObject *button;
    int delta;
    int old;
    int music;
    int *key;

    if (DAT_0045601c_LevelMusicUnk && FUN_00402eb0_Return1()) {
        MUS_QueuePlay_00402e70(DAT_0045601c_LevelMusicUnk);
        DAT_0045601c_LevelMusicUnk = 0;
        MUS_PlayMusic_00402f30();
        DAT_00456020_MusicOnUnk = 1;
    }
    if (!gob->fa0 || !gob->fa4) {
        FUN_0040ca70(gob, gob->fa8);
        return;
    }
    if (gob->fa8 == 0x15 && gInputControllers_004a0280[0x14]) {
        FUN_0040c940();
        gGameState_00455c3c = 1;
        M1_IsInMap_004a2a7c = 1;
        level_004a2964 = 0x3f;
        SND_PlaySoundNoPosition_0041a360(0x44, 0xff);
        gSFXEnabled_00455c08 = DAT_004a291c_LoadLevelUnk1;
        gVFXEnabled_00455c0c = DAT_004a2918_LevelObjectsListEnd;
        if (DAT_00462c70)
            FUN_004099b0_CloseMusic(1);
        gMUSEnabled_00455c10 = DAT_004a2920_LoadLevelUnk5;
        return;
    }
    if (gInputControllers_004a0280[0x11]) {
        FUN_0040ca70(gob, gob->fa0);
        FUN_0040cca0(gob);
        SND_PlaySoundNoPosition_0041a360(0x45, 0xff);
        DAT_00462c68 = 0xd2;
        return;
    }
    if (gInputControllers_004a0280[0x12]) {
        FUN_0040ca70(gob, gob->fa4);
        FUN_0040cca0(gob);
        SND_PlaySoundNoPosition_0041a360(0x45, 0xff);
        DAT_00462c68 = 0xd2;
        return;
    }
    if (gob->fac == 1 && (gInputControllers_004a0280[0xf] || gInputControllers_004a0280[0x10])) {
        button = GOB_FindWithWork0_0040c110(0x7b, gob->fa8);
        old = button->fb0;
        button->fb0 = 0;
        if (!old)
            button->fb0 = 1;
        SND_PlaySoundNoPosition_0041a360(0x42, 0xff);
        if (button->f98 == 2) {
            if (button->fb0 == 1)
                DAT_004a291c_LoadLevelUnk1 = 1;
            else
                DAT_004a291c_LoadLevelUnk1 = 0;
        } else if (button->f98 == 6) {
            old = button->fb0;
            DAT_004a2918_LevelObjectsListEnd = 1;
            if (old != 1)
                DAT_004a2918_LevelObjectsListEnd = 0;
        }
        if (button->f98 == 4) {
            if (button->fb0 == 1) {
                GOB_FindWithWork0_0040c110(0x7b, 8);
                DAT_004a2920_LoadLevelUnk5 = 1;
            } else
                DAT_004a2920_LoadLevelUnk5 = 0;
        }
    } else if (gob->fac == 2) {
        if (gInputControllers_004a0280[0xf])
            delta = -1;
        else if (gInputControllers_004a0280[0x10])
            delta = 1;
        else {
            if (gInputControllers_004a0280[0x14]) {
                button = GOB_FindWithWork0_0040c110(0x7b, 8);
                music = DAT_004577B0[PTR_s_Title_00456038[button->fb0].level].music;
                if (!DAT_0045601c_LevelMusicUnk) {
                    if (DAT_00456020_MusicOnUnk)
                        MUS_Stop_00402f70(0, DAT_004a2a00);
                    MUS_QueuePlay_00402e70(music);
                    old = button->fb0;
                    DAT_00462c70 = 1;
                    DAT_0045601c_LevelMusicUnk = DAT_004577B0[PTR_s_Title_00456038[old].level].next;
                }
            }
            return;
        }
        button = GOB_FindWithWork0_0040c110(0x7b, gob->fa8);
        button->fb0 += delta;
        if (button->fb0 < 0)
            button->fb0 = 0x13;
        else if (button->fb0 >= 0x14)
            button->fb0 = 0;
        SND_PlaySoundNoPosition_0041a360(0x45, 0xff);
    } else if (gob->fac == 5) {
    } else if (gob->fac == 3) {
        if (gInputControllers_004a0280[0x13])
            key = &DAT_00456228[8];
        else if (gInputControllers_004a0280[0x14])
            key = &DAT_00456228[7];
        else if (gInputControllers_004a0280[0x15])
            key = &DAT_00456228[6];
        else if (gInputControllers_004a0280[0x18])
            key = &DAT_00456228[5];
        else if (gInputControllers_004a0280[0x17])
            key = &DAT_00456228[4];
        else if (gInputControllers_004a0280[0x1b])
            key = &DAT_00456228[3];
        else if (gInputControllers_004a0280[0x1d])
            key = &DAT_00456228[2];
        else if (gInputControllers_004a0280[0x1c])
            key = &DAT_00456228[1];
        else
            return;
        FUN_0040cb70_Set_Active_Gex_Object(gob->fa8, key);
        SND_PlaySoundNoPosition_0041a360(0x42, 0xff);
        DAT_00462c68 = 0;
    }
}
}
