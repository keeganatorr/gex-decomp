// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct Flags2 {
    unsigned int low:8;
    unsigned int hit:1;       /* bit 8 */
    unsigned int wasHit:1;    /* bit 9 */
    unsigned int high:22;
} Flags2;
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x14];
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
    unsigned char _padC8[0xd4 - 0xc8];
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
extern "C" {
extern GXObject *PTR_00464518;
extern GXObject *PTR_00464510;
extern int DAT_0045c9a0;
extern int KFBossState_0045c990;
int __cdecl OBI_CheckRemoveObject_0040fce0(GXObject *gob);
int __cdecl GOB_GetHotSpot_00419c00(GXObject *gob, int group, int index, int *x, int *y);
int __cdecl FUN_004373c0_KFInner(int d);
void __cdecl FUN_004374a0(int *dx, int *dy);
int __cdecl FUN_00439130_KFInner(int dx, int dy);
int __cdecl FUN_00439190_KFInner(int angle);
void __cdecl FUN_00437790_KFBossStateInner(GXObject *gob)
{
    int tx;
    int ty;
    int hx;
    int hy;
    int x;
    int y;
    int dx;
    int dy;
    int ax;
    int by;
    ty = PTR_00464518->gob_ypos;
    tx = PTR_00464518->gob_xpos;
    gob->gob_xold = gob->gob_xpos;
    gob->gob_yold = gob->gob_ypos;
    gob->gob_oldFlags = gob->gob_flags;
    gob->gob_oldGroup = gob->gob_currentFrameGroup;
    gob->gob_oldIndex = gob->gob_currentFrameIndex;
    gob->gob_leftEdge = 0;
    gob->gob_rightEdge = 0;
    gob->gob_topEdge = 0;
    gob->gob_bottomEdge = 0;
    gob->gob_flags2.wasHit = gob->gob_flags2.hit;
    gob->gob_flags2.hit = 0;
    if (!OBI_CheckRemoveObject_0040fce0(gob)) {
        gob->gob_flags2 = PTR_00464510->gob_flags2;
        if (GOB_GetHotSpot_00419c00(PTR_00464510, 0, 0, &hx, &hy)) {
            x = PTR_00464510->gob_xpos + hx;
            y = PTR_00464510->gob_ypos + hy;
        }
        dx = (tx - x) * gob->gob_speed / 10;
        dy = (ty - y) * gob->gob_speed / 10;
        if (DAT_0045c9a0 != 0x640000) {
            gob->gob_xpos = x + dx;
            if (PTR_00464510->gob_flags & 0x80000000)
                gob->gob_ypos = (FUN_004373c0_KFInner(-dx >> 16) << 16) + y;
            else
                gob->gob_ypos = (FUN_004373c0_KFInner(dx >> 16) << 16) + y;
        } else {
            gob->gob_ypos = y + dy;
            if (PTR_00464510->gob_flags & 0x80000000)
                gob->gob_xpos = x - (FUN_004373c0_KFInner(dy >> 16) << 16);
            else
                gob->gob_xpos = (FUN_004373c0_KFInner(dy >> 16) << 16) + x;
        }
        if (gob->gob_xold != gob->gob_xpos) {
            ax = gob->gob_xpos - gob->gob_xold;
            ty = gob->gob_ypos - gob->gob_yold;
            FUN_004374a0(&ax, &ty);
            if (KFBossState_0045c990 == 2)
                gob->gob_angle = FUN_00439130_KFInner(ax, ty);
            else
                gob->gob_angle = FUN_00439190_KFInner(FUN_00439130_KFInner(ax, ty));
        }
        if (gob->gob_platHitType == -1)
            gob->gob_platform = 0;
        gob->gob_platHitType = -1;
    }
}
}
