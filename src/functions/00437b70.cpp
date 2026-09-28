// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct Flags2 {
    unsigned int low:8;
    unsigned int hit:1;       /* bit 8 */
    unsigned int wasHit:1;    /* bit 9 */
    unsigned int high:22;
} Flags2;
typedef struct GXObject {
    unsigned char _pad0[0xc];
    void *gob_loadData;         /* 0xc */
    unsigned char _pad10[0x40];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    void *gob_initFunc;         /* 0x58 */
    void *gob_doitFunc;         /* 0x5c */
    void *gob_drawFunc;         /* 0x60 */
    void *gob_hitFunc;          /* 0x64 */
    unsigned char _pad68[4];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char _pad70[8];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x18];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    struct GXObject *gob_work2; /* 0xa0 */
    unsigned char _padA4[0xb0 - 0xa4];
    int gob_speed;              /* 0xb0 */
    unsigned char _padB4[0xc4 - 0xb4];
    int gob_angle;              /* 0xc4 */
    int gob_c8;                 /* 0xc8 */
    int gob_cc;                 /* 0xcc */
    unsigned char _padD0[4];
    int gob_xold;               /* 0xd4 */
    int gob_yold;               /* 0xd8 */
    int gob_oldContourDist;     /* 0xdc */
    Flags2 gob_flags2;          /* 0xe0 */
    int gob_leftEdge;           /* 0xe4 */
    int gob_rightEdge;          /* 0xe8 */
    int gob_topEdge;            /* 0xec */
    int gob_bottomEdge;         /* 0xf0 */
    int gob_oldGroup;           /* 0xf4 */
    int gob_oldIndex;           /* 0xf8 */
    unsigned int gob_oldFlags;  /* 0xfc */
    unsigned char _pad100[0x10];
    struct GXObject *gob_platform;  /* 0x110 */
    int gob_platHitType;        /* 0x114 */
} GXObject;

int __cdecl printf(const char *, ...);
extern char s_This_sucks_0045c9dc[];
extern GXObject *PTR_ARRAY_004644e8[10];
void __cdecl FUN_004379d0_KFBossStateInner_MoveGex(GXObject *);
GXObject *__cdecl GOB_AddObject_004195d0(int, int, int, void *);
int __cdecl FUN_00437b20_DamageToGex(GXObject *);
void __cdecl KFBossDraw_00434080(GXObject *);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *, GXObject *);
void __cdecl GOB_RemoveMapObject_00419840(GXObject *);
void __cdecl FUN_00437500_KFBossStateInner(GXObject *);
void __cdecl FUN_00437790_KFBossStateInner(GXObject *);
extern GXObject *PTR_00464518;
extern int DAT_0045c994;
extern GXObject *PTR_00464510;
extern int DAT_0045c9a0;
extern int DAT_0045c99c;
extern int DAT_00458c7c;
extern int KFBossState_0045c990;
int __cdecl OBI_CheckRemoveObject_0040fce0(GXObject *gob);
int __cdecl GOB_GetHotSpot_00419c00(GXObject *gob, int group, int index, int *x, int *y);
int __cdecl FUN_004373c0_KFInner(int d);
void __cdecl FUN_004374a0(int *dx, int *dy);
int __cdecl FUN_00439130_KFInner(int dx, int dy);
int __cdecl FUN_00439190_KFInner(int angle);
int __cdecl GEX_Target(GXObject *gob)
{
    int x;
    int y;
    int i;
    GXObject *o;
    GXObject **p;
    PTR_00464510 = gob;
    switch (KFBossState_0045c990) {
    case 0:
        FUN_004379d0_KFBossStateInner_MoveGex(gob);
        if (GOB_GetHotSpot_00419c00(gob, 0, 0, &x, &y)) {
            o = GOB_AddObject_004195d0(0xe4, x, y, gob->gob_loadData);
            if (o) {
                PTR_00464518 = o;
                o->gob_currentFrameGroup = 0xc;
                o->gob_currentFrameIndex = 0;
                o->gob_flags = gob->gob_flags;
                o->gob_xpos = gob->gob_xpos + x;
                o->gob_ypos = gob->gob_ypos + y;
                o->gob_doitFunc = 0;
                o->gob_hitFunc = FUN_00437b20_DamageToGex;
                o->gob_drawFunc = KFBossDraw_00434080;
                o->gob_c8 = gob->gob_c8;
                o->gob_cc = gob->gob_cc;
                GOB_PutObjectInfrontOfObject_00419be0(o, PTR_00464510);
            }
            for (i = 0; i < 10; i++) {
                o = GOB_AddObject_004195d0(0xe4, x, y, gob->gob_loadData);
                if (o) {
                    o->gob_currentFrameGroup = 0xd;
                    o->gob_currentFrameIndex = 0;
                    o->gob_flags = gob->gob_flags;
                    o->gob_xpos = gob->gob_xpos + x;
                    o->gob_ypos = gob->gob_ypos + y;
                    o->gob_doitFunc = 0;
                    o->gob_hitFunc = FUN_00437b20_DamageToGex;
                    o->gob_drawFunc = KFBossDraw_00434080;
                    o->gob_speed = i;
                    PTR_ARRAY_004644e8[i] = o;
                    o->gob_c8 = gob->gob_c8;
                    o->gob_cc = gob->gob_cc;
                    GOB_PutObjectInfrontOfObject_00419be0(o, PTR_00464510);
                }
            }
        }
        KFBossState_0045c990 = 1;
        break;
    case 1:
        if (++DAT_0045c994 < 8 && PTR_00464518->gob_xpos <= 0x1960000 && PTR_00464518->gob_ypos <= 0xda0000 && PTR_00464518->gob_xpos >= 0x200000) {
            FUN_00437500_KFBossStateInner(PTR_00464518);
            for (p = PTR_ARRAY_004644e8; p < PTR_ARRAY_004644e8 + 10; p++)
                FUN_00437790_KFBossStateInner(*p);
            break;
        }
        DAT_0045c994--;
        KFBossState_0045c990 = 2;
        return 0;
    case 2:
        DAT_0045c994--;
        FUN_00437500_KFBossStateInner(PTR_00464518);
        for (p = PTR_ARRAY_004644e8; p < PTR_ARRAY_004644e8 + 10; p++)
            FUN_00437790_KFBossStateInner(*p);
        if (DAT_0045c994 <= 0)
            KFBossState_0045c990 = 3;
        break;
    case 3:
        KFBossState_0045c990 = 4;
        break;
    case 4:
        GOB_RemoveMapObject_00419840(PTR_00464518);
        PTR_00464518 = 0;
        for (p = PTR_ARRAY_004644e8; p < PTR_ARRAY_004644e8 + 10; p++) {
            GOB_RemoveMapObject_00419840(*p);
            *p = 0;
        }
        KFBossState_0045c990 = 0;
        return 1;
    default:
        printf(s_This_sucks_0045c9dc, KFBossState_0045c990);
        return 0;
    }
}
