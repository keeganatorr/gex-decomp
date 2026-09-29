typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;
typedef struct MapInfo {
    int f0;
    int width;
    int height;
} MapInfo;
typedef struct Level {
    int f0;
    MapInfo *map;
} Level;
typedef void (__cdecl *StateFunc)(int *);

extern "C" {
extern int DAT_004a022c;
extern int DAT_004A0240;
extern int DAT_004a021c;
extern int DAT_004a0220;
extern int DAT_004a0230;
extern int gStartDoorID_00456adc;
extern int LEVELID_00456ad8;
extern int DAT_00456af4;
extern int DAT_00456af0;
extern int DAT_00456af8;
extern int DAT_00456ae4;
extern int DAT_00456ae8;
extern int level_004a2964;
extern LevelEntry DAT_004577B0[];
extern int DAT_004a2880;
extern int DAT_004a285c;
extern unsigned int DAT_00457210[];
extern void *GEX_pGlob_004a2ad4;
extern StateFunc StateInitFuncs_00457378[];
extern StateFunc StateProcessFuncs_004574e0[];
extern int DAT_00455b8c_CamX2;
extern int DAT_00455b90_CamY2;
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int gTimer_004a2ac8;
extern int DAT_004632e4;
extern int DAT_00462e3c;
extern Level *M1_CurrentLevel_004a2990;
void __cdecl M1_GoToMap_00415bb0(void);
void __cdecl TILES_CheckHorizForcedScroll_0042cc90(int *, int);
void __cdecl TILES_CheckVertForcedScroll_0042cd90(int *, int);
void __cdecl PlayerKill_00417ca0(int);
void __cdecl VSIT_PlayVoiceSituation_0041f8c0(int);
void __cdecl VFX_Play_0041fa80(int);
void __cdecl EFECT_AddPuff_0042e480(int, int, unsigned int, int, unsigned int);

void __cdecl PlayerDoit2_00415c10(int *p)
{
    int d;
    DAT_004a022c = 0;
    DAT_004A0240 = 0;
    DAT_004a021c = 0;
    DAT_004a0220 = 0;
    DAT_004a0230 = 0;
    if (gStartDoorID_00456adc <= 0 && LEVELID_00456ad8 < 0) {
        if (DAT_00456af4 > 0) {
            gStartDoorID_00456adc = DAT_00456af4;
            LEVELID_00456ad8 = level_004a2964;
        }
        if (DAT_00456af0 >= 0)
            LEVELID_00456ad8 = DAT_00456af0;
        DAT_00456ae4 = DAT_00456af8;
        DAT_00456af8 = -1;
    }
    if (DAT_00456ae4 >= 0) {
        switch (DAT_00456ae4) {
        case 0:
        case 2:
        case 3:
            p[0x1d] = 2;
            break;
        case 1:
            M1_GoToMap_00415bb0();
            break;
        case 4:
            LEVELID_00456ad8 = (DAT_004577B0[level_004a2964].info & 0xf) + 0x30;
            p[0x1d] = 2;
            break;
        }
        DAT_00456ae8 = DAT_00456ae4;
        DAT_00456ae4 = -1;
    }
    if (DAT_004a2880 && DAT_004a285c && !(DAT_00457210[p[0x1c]] & 0x10))
        p[0x1d] = 0x56;
    if (p[0x1d] >= 0) {
        p[3] = (int)GEX_pGlob_004a2ad4;
        StateInitFuncs_00457378[p[0x1d]](p);
        p[0x1d] = -1;
    } else {
        StateProcessFuncs_004574e0[p[0x1c]](p);
    }
    TILES_CheckHorizForcedScroll_0042cc90(p, 0);
    TILES_CheckVertForcedScroll_0042cd90(p, 0);
    if (DAT_00455b8c_CamX2) {
        d = p[0x1e] - CAMERA_XPos_004a2a38;
        if (d < -0x140000 || d > 0x1540000)
            PlayerKill_00417ca0(0);
    }
    if (DAT_00455b90_CamY2) {
        d = p[0x1f] - CAMERA_YPos_004a2a1c;
        if (d < -0x140000 || d > 0x1040000)
            PlayerKill_00417ca0(0);
    }
    if ((p[0x38] & 0x100) && !(gTimer_004a2ac8 & 0x7f)) {
        VSIT_PlayVoiceSituation_0041f8c0(0x51);
        VFX_Play_0041fa80(0x51);
    }
    if (DAT_004632e4) {
        if (!DAT_00462e3c) {
            DAT_00462e3c = 3;
            DAT_004632e4--;
            EFECT_AddPuff_0042e480(p[0x1e], p[0x1f], p[0x1b] & 0x80000000, p[0x31], p[0x1b] & 0xf);
        }
        DAT_00462e3c--;
    }
    if (p[0x1e] < 0 || p[0x1e] >= M1_CurrentLevel_004a2990->map->width)
        p[0x1e] = M1_CurrentLevel_004a2990->map->width - 1;
    if (p[0x1f] >= M1_CurrentLevel_004a2990->map->height)
        p[0x1f] = M1_CurrentLevel_004a2990->map->height - 1;
}
}
