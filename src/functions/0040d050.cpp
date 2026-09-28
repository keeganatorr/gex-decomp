typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;
typedef struct GXObject {
    char pad0[0x70];
    int state;
    int newState;
    int xpos;
    int ypos;
    char pad80[0x18];
    int work0;
    int work1;
    int work2;
    int work3;
    int work4;
} GXObject;

extern "C" {
extern int LEVELID_004a2a74;
extern LevelEntry DAT_004577B0[];
extern int DAT_004561f4;
extern int gHitpoints_004a281c;
extern int DAT_004594a0_EatenObject_unk[];
extern int gHitpoints2_00456afc;
extern int DAT_00456208;
extern int DAT_00462c60;
extern int DAT_00462c74;
extern int DAT_00462c64;
extern int gNumLives_00456b00;
extern GXObject *gPlayerObject_004a27fc;
extern int DAT_004a2a08_LoadLevelMusic4;
extern int DAT_00456018_gex_Init_unk;
extern int gGameState_00455c3c;
extern int M1_IsInMap_004a2a7c;
void __cdecl AddVisualScore_0041bde0(GXObject *, int, int, int);
void __cdecl SND_PlaySoundNoPosition_0041a360(int, int);
void __cdecl FUN_0040d3f0(int, int);
void __cdecl InitPlayerRun_00424aa0(GXObject *);
int __cdecl FUN_00402e90(void);

void __cdecl GEX_Target(GXObject *g)
{
    unsigned int flag;
    int found;
    flag = DAT_004577B0[LEVELID_004a2a74].info & 0x200;
    if (g->work2 & 0xffff0000) {
    switch (g->work0) {
    case 1:
        if (g->work3) {
            if (flag)
                g->work1 = 0x61a8;
            else if (g->work1)
                g->work1 += g->work1;
            else
                g->work1 = 0xfa;
            AddVisualScore_0041bde0(g, g->work1, g->xpos, g->ypos);
            SND_PlaySoundNoPosition_0041a360(0x72, 0xff);
            g->xpos += 0xe0000;
            FUN_0040d3f0(g->work0, g->work1);
            if (!flag) {
                gHitpoints_004a281c--;
                g->work3--;
            } else {
                g->work3 = 0;
                g->work0 = 2;
                g->work1 = 0;
            }
        } else {
            g->work0 = 2;
            g->work1 = 0;
            g->work3 = 2;
        }
        break;
    case 2:
        found = 0;
        if (!flag) {
            for (; g->work3 >= 0; g->work3--) {
                if (DAT_004594a0_EatenObject_unk[g->work3] >= 0)
                    found = 1;
            }
            if (!found) {
                if (gHitpoints2_00456afc <= 3) {
                    g->work0 = 4;
                    g->xpos = 0x640000;
                    g->ypos = DAT_00456208;
                    DAT_00462c60 = 0x26;
                    g->work4 = 0;
                    DAT_00462c74 = 9;
                    DAT_00462c64 = 0x40000;
                } else {
                    gHitpoints2_00456afc--;
                    found = 1;
                }
            }
            if (found) {
                if (g->work1 >= 0x1f40) {
                    AddVisualScore_0041bde0(g, g->work1, g->xpos, g->ypos);
                    SND_PlaySoundNoPosition_0041a360(0x72, 0xff);
                    FUN_0040d3f0(3, g->work1);
                } else {
                    if (!g->work1)
                        g->work1 = 0x7d0;
                    else
                        g->work1 += g->work1;
                    AddVisualScore_0041bde0(g, g->work1, g->xpos, g->ypos);
                    SND_PlaySoundNoPosition_0041a360(0x72, 0xff);
                    FUN_0040d3f0(2, g->work1);
                }
                g->xpos -= 0xe0000;
            } else {
                g->work0 = 4;
                g->xpos = 0x640000;
                g->ypos = DAT_00456208;
                DAT_00462c60 = 0x26;
                g->work4 = 0;
                DAT_00462c74 = 9;
                DAT_00462c64 = 0x40000;
            }
        } else if (g->work3 != gHitpoints_004a281c) {
            gNumLives_00456b00++;
            g->work3++;
            SND_PlaySoundNoPosition_0041a360(0x72, 0xff);
            FUN_0040d3f0(3, g->work3);
        } else {
            g->work0 = 4;
        }
        break;
    case 4:
        gPlayerObject_004a27fc->newState = 0xb;
        g->work0 = 5;
        break;
    case 5:
        if (gPlayerObject_004a27fc->state != 0xb) {
            g->work0 = 7;
            InitPlayerRun_00424aa0(gPlayerObject_004a27fc);
        }
        break;
    case 7:
        if ((!DAT_004a2a08_LoadLevelMusic4 || FUN_00402e90()) && gPlayerObject_004a27fc->xpos >= 0x1540000) {
            DAT_00456018_gex_Init_unk = 0;
            gGameState_00455c3c = 1;
            M1_IsInMap_004a2a7c = 1;
        }
        break;
    }
    g->work2 = 0;
    } else
        g->work2 += DAT_004561f4;
}
}
