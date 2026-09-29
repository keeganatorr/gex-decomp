// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct Flags2 {
    unsigned int low:8;
    unsigned int hit:1;       /* bit 8 */
    unsigned int wasHit:1;    /* bit 9 */
    unsigned int high:22;
} Flags2;
typedef struct GXObject {
    unsigned char _pad0[0xc];
    void *gob_objectLoadData;   /* 0x0c */
    unsigned char _pad10[0x50 - 0x10];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x14];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[4];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x8c - 0x80];
    int gob_yVel;               /* 0x8c */
    unsigned char _pad90[0x94 - 0x90];
    int gob_yAccel;             /* 0x94 */
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    int gob_work3;              /* 0xa4 */
    int gob_work4;              /* 0xa8 */
    int gob_work5;              /* 0xac */
    int gob_work6;              /* 0xb0 */
    unsigned int gob_work7;     /* 0xb4 */
    unsigned char _padB8[0xc8 - 0xb8];
    int gob_xScale;             /* 0xc8 */
    int gob_yScale;             /* 0xcc */
    unsigned char _padD0[0xd4 - 0xd0];
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
typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;
extern "C" {
extern LevelEntry DAT_004577B0[];
extern unsigned char BYTE_ARRAY_004a2540[];
extern int level_004a2964;
extern int gGameState_00455c3c;
extern int M1_IsInMap_004a2a7c;
extern int DAT_00459048;
int __cdecl OBI_CheckRemoveObject_0040fce0(GXObject *gob);
int __cdecl GOB_LandedOnContours_0041a0a0(GXObject *gob, int offset);
void __cdecl RezInObject_004372f0(GXObject *gob);
void __cdecl ClearStartDoor_0041a600(void);
void __cdecl GOB_Remove_00419a80(GXObject *gob);
void __cdecl RemoteDoIt_0041ac70(GXObject *gob)
{
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
        if (gob->gob_work5 == 1) {
            gob->gob_yVel = -0x30000;
            gob->gob_yAccel = 0xa000;
            gob->gob_xScale = 0xa000;
            gob->gob_yScale = 0xa000;
            gob->gob_work5 = 2;
        } else if (gob->gob_work5 == 2) {
            gob->gob_yVel += gob->gob_yAccel;
            if (gob->gob_yVel > 0xf0000)
                gob->gob_yVel = 0xf0000;
            gob->gob_ypos += gob->gob_yVel;
            gob->gob_xScale = 0x30000 - gob->gob_yVel >> 4;
            if (gob->gob_xScale < 0)
                gob->gob_xScale = 0;
            gob->gob_yScale = gob->gob_xScale = 0x10000 - gob->gob_xScale;
            if (GOB_LandedOnContours_0041a0a0(gob, 0xc0000)) {
                gob->gob_yVel = 0;
                gob->gob_yAccel = 0;
                gob->gob_work5 = 0xff;
            }
        } else if (gob->gob_work5 == 3) {
            gob->gob_work5 = 4;
            RezInObject_004372f0(gob);
        }
        if (gob->gob_work5 && !--gob->gob_work6) {
            gGameState_00455c3c = 5;
            BYTE_ARRAY_004a2540[level_004a2964] |= 2;
            level_004a2964 = gob->gob_work3;
            M1_IsInMap_004a2a7c = 1;
            DAT_004577B0[0x44].info |= 0x200;
            ClearStartDoor_0041a600();
            GOB_Remove_00419a80(gob);
        }
        if (--gob->gob_work4 < 0 && (!gob->gob_work5 || gob->gob_work6 < 0)) {
            gob->gob_work4 = DAT_00459048;
            gob->gob_currentFrameIndex++;
        }
    }
    if (gob->gob_platHitType == -1)
        gob->gob_platform = 0;
    gob->gob_platHitType = -1;
}
}
