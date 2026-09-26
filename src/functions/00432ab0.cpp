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
    int gob_size;               /* 0x70 */
    unsigned char _pad74[4];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    int gob_xVel;               /* 0x80 */
    int gob_xMax;               /* 0x84 */
    unsigned char _pad88[4];
    int gob_yVel;               /* 0x8c */
    int gob_yMax;               /* 0x90 */
    unsigned char _pad94[4];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    struct GXObject *gob_work2; /* 0xa0 */
    unsigned char _padA4[0x30];
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
extern void *GEX_pGlob_004a2ad4;
int __cdecl OBI_CheckRemoveObject_0040fce0(GXObject *gob);
void __cdecl GOB_PhysicsStepX_0040f260(GXObject *gob);
void __cdecl GOB_PhysicsStepY_0040f2a0(GXObject *gob);
int __cdecl FUN_00431900_Movement_unk(GXObject *gob);
void __cdecl FUN_00431990(GXObject *gob, int flag);
void __cdecl GOB_RemoveObject_00419520(GXObject *gob);
int __cdecl UTL_ReallyRandom_00428c80(int range);
GXObject *__cdecl GOB_AddObject_004195d0(int type, int x, int y, void *loadData);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *behind, GXObject *front);
void __cdecl GEX_Target(GXObject *gob)
{
    GXObject *spark;
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
        GOB_PhysicsStepX_0040f260(gob);
        GOB_PhysicsStepY_0040f2a0(gob);
        if (FUN_00431900_Movement_unk(gob)) {
            FUN_00431990(gob, 1);
            GOB_RemoveObject_00419520(gob);
        }
        if (++gob->gob_work0 >= 2) {
            gob->gob_work0 = 0;
            gob->gob_currentFrameIndex++;
        }
        if (!--gob->gob_work1) {
            gob->gob_work1 = UTL_ReallyRandom_00428c80(4) + 2;
            spark = GOB_AddObject_004195d0(0x5c, gob->gob_xpos + (((UTL_ReallyRandom_00428c80(7) - 3) << 15) - gob->gob_xVel) * 2, gob->gob_ypos + (((UTL_ReallyRandom_00428c80(7) - 3) << 15) - gob->gob_yVel) * 2, GEX_pGlob_004a2ad4);
            if (spark) {
                spark->gob_flags |= 0xc000;
                spark->gob_xMax = 0x7fff0000;
                spark->gob_xVel = gob->gob_xVel >> 3;
                spark->gob_yMax = 0x7fff0000;
                spark->gob_yVel = gob->gob_yVel >> 3;
                spark->gob_currentFrameGroup = 0x20;
                spark->gob_work0 = 3;
                spark->gob_size = 0x30;
                GOB_PutObjectInfrontOfObject_00419be0(spark, gob);
            }
        }
    }
    if (gob->gob_platHitType == -1)
        gob->gob_platform = 0;
    gob->gob_platHitType = -1;
}
}
