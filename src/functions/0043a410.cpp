typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;

extern "C" {
extern int DAT_00458c7c;
extern int DAT_00464520;
extern int DAT_00458c80;
extern int DAT_004646f0;
extern int DAT_00455c54_DebugVar;
extern char s_HUNT_0045ffcc[];
extern char s_DIVE_0045ffc4[];
extern char s_END_WAIT_0045ffb8[];
extern int DAT_0045FFB4;
extern int DAT_00464524;
extern int DAT_004645a8;
extern int DAT_004646f4;
extern int DAT_004646fc;
extern int DAT_00464700;
extern int DAT_0046465c;
extern int DAT_004645ac;
int __cdecl printf(const char *, ...);
extern int CAMERA_YPos_004a2a1c;
extern int gGameState_00455c3c;
extern int M1_IsInMap_004a2a7c;
extern LevelEntry DAT_004577B0[];
extern int level_004a2964;
extern unsigned char BYTE_ARRAY_004a2540[];
void __cdecl FUN_00439390_HuntDiveInner(int *, int *, int *, int *);
int __cdecl FUN_00439110(int, int);
int __cdecl FUN_00439130_KFInner(int, int);
int __cdecl FUN_004391b0_HuntDiveInner(int);
void __cdecl FUN_004395b0_HuntDiveInner(int, int);
void __cdecl FUN_004397c0_HuntDiveInner(void);
int __cdecl FUN_004397f0_HuntDiveInner(void);
void __cdecl SND_PlaySoundNoPosition_0041a360(int, int);

void __cdecl GEX_Target(void)
{
    int p[4];
    if (DAT_00458c7c == 2) {
        if (!(DAT_00464520 % 3))
            DAT_00458c80++;
        if (DAT_00458c80 == 0xe)
            DAT_004646f0 = 4;
    }
    DAT_00464520++;
    switch (DAT_004646f0) {
    case 0:
        if (DAT_00455c54_DebugVar > 1)
            printf(s_HUNT_0045ffcc);
        FUN_00439390_HuntDiveInner(&p[0], &p[1], &p[2], &p[3]);
        if (p[0] == -1)
            break;
        DAT_00464524 = FUN_00439110(p[0] - p[2], p[1] - p[3]);
        DAT_004645a8 = FUN_004391b0_HuntDiveInner(FUN_00439130_KFInner((p[0] - p[2]) << 16, (p[1] - p[3]) << 16)) >> 16;
        DAT_004646f4 = (p[0] << 21) + 0x340000;
        DAT_004646fc = (p[1] + 1) << 21;
        FUN_004395b0_HuntDiveInner(DAT_004646f4, DAT_004646fc);
        FUN_004397c0_HuntDiveInner();
        DAT_004646f0 = 1;
        return;
    case 1:
        if (DAT_00455c54_DebugVar > 1)
            printf(s_DIVE_0045ffc4);
        if (FUN_004397f0_HuntDiveInner())
            DAT_004646f0 = 2;
        return;
    case 2:
        if (--DAT_0045FFB4 >= 0)
            break;
        if (DAT_00455c54_DebugVar > 1)
            printf(s_END_WAIT_0045ffb8);
        DAT_0045FFB4 = 0x1e;
        if (DAT_00464700) {
            DAT_004646f0 = 2;
            DAT_00464700 = 0;
            return;
        }
        DAT_004646f0 = 0;
        return;
    case 3:
        p[0] = 5;
        p[1] = 0x138;
        p[2] = 8;
        p[3] = 0x135;
        DAT_00464524 = FUN_00439110(p[0] - p[2], p[1] - p[3]);
        DAT_004645a8 = FUN_004391b0_HuntDiveInner(FUN_00439130_KFInner((p[0] - p[2]) << 16, (p[1] - p[3]) << 16)) >> 16;
        DAT_004646f4 = (p[0] << 21) + 0x340000;
        DAT_004646fc = (p[1] + 1) << 21;
        FUN_004395b0_HuntDiveInner(DAT_004646f4, DAT_004646fc);
        FUN_004397c0_HuntDiveInner();
        DAT_004646f0 = 1;
        return;
    case 4:
        p[1] = 0xcb;
        p[3] = 0xcc;
        DAT_00464524 = 0xea00000;
        p[0] = 4;
        p[2] = 4;
        DAT_004645a8 = 0;
        DAT_004646f4 = (p[0] << 21) + 0x340000;
        DAT_004646fc = (p[1] + 1) << 21;
        FUN_004395b0_HuntDiveInner(DAT_004646f4, DAT_004646fc);
        FUN_004397c0_HuntDiveInner();
        DAT_0046465c = 0xa200;
        DAT_004646f0 = 5;
        return;
    case 5:
        if (FUN_004397f0_HuntDiveInner()) {
            DAT_004645ac = 0xb4;
            DAT_004646f0 = 6;
            SND_PlaySoundNoPosition_0041a360(0x144, 0xff);
        }
        return;
    case 6:
        CAMERA_YPos_004a2a1c = 0x26d00000;
        if (--DAT_004645ac >= 0)
            break;
        DAT_004646f0 = 7;
        gGameState_00455c3c = 5;
        M1_IsInMap_004a2a7c = 3;
        DAT_004577B0[0x44].info |= 0x200;
        BYTE_ARRAY_004a2540[level_004a2964] |= 2;
        level_004a2964 = 0x33;
        break;
    }
}
}
