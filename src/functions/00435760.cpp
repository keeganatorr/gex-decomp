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
    unsigned char _pad90[0x98 - 0x90];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    unsigned char _padA4[0xac - 0xa4];
    int gob_work5;              /* 0xac */
    int gob_work6;              /* 0xb0 */
    unsigned int gob_work7;     /* 0xb4 */
    unsigned char _padB8[0xd4 - 0xb8];
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
extern void *M1_CurrentLevel_004a2990;
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int DAT_0045b7cc;
extern int DAT_0045b7d0;
extern int DAT_0045b7d8_framecount_[];
extern int DAT_0045b7b0;
extern int DAT_0045b7b8;
extern int DAT_0045b798;
extern int DAT_0045b7a0;
extern int DAT_0045b7a4;
int __cdecl OBI_CheckRemoveObject_0040fce0(GXObject *gob);
void __cdecl FUN_00420770_Movement_unk(GXObject *gob, int type);
void __cdecl GOB_PhysicsStepX_0040f260(GXObject *gob);
void __cdecl GOB_PhysicsStepY_0040f2a0(GXObject *gob);
int __cdecl GOB_LandedOnContours_0041a0a0(GXObject *gob, int offset);
void __cdecl GOB_LandedOnContoursWithOffset_0041a160(void *level, GXObject *gob);
void __cdecl GOB_Remove_00419a80(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob)
{
    int v;
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
        switch (gob->gob_state) {
        case 0:
            if (DAT_0045b7cc) {
                gob->gob_state = 1;
                gob->gob_currentFrameGroup = DAT_0045b7d8_framecount_[gob->gob_work0] + 0xb;
                gob->gob_currentFrameIndex = 0;
                gob->gob_work1 = 0;
                return;
            }
            if (DAT_0045b7d0) {
                gob->gob_xpos = gob->gob_work5 + CAMERA_XPos_004a2a38;
                gob->gob_ypos = gob->gob_work6 + CAMERA_YPos_004a2a1c;
            }
            FUN_00420770_Movement_unk(gob, 0x45);
            gob->gob_objectLoadData = GEX_pGlob_004a2ad4;
            if ((gob->gob_work1 += DAT_0045b7b0) > 0x10000) {
                gob->gob_work1 -= 0x10000;
                gob->gob_work2++;
            }
            if (gob->gob_work7 & 2) {
                GOB_PhysicsStepX_0040f260(gob);
                GOB_PhysicsStepY_0040f2a0(gob);
                if (GOB_LandedOnContours_0041a0a0(gob, DAT_0045b798)) {
                    v = DAT_0045b7a0 - gob->gob_yVel;
                    gob->gob_yVel = v < DAT_0045b7a4 ? v : DAT_0045b7a4;
                    GOB_LandedOnContoursWithOffset_0041a160(M1_CurrentLevel_004a2990, gob);
                    gob->gob_ypos -= DAT_0045b798;
                }
            }
            gob->gob_currentFrameGroup = 0;
            gob->gob_currentFrameIndex = gob->gob_work0;
            break;
        case 1:
            if ((gob->gob_work1 += DAT_0045b7b8) > 0x10000) {
                gob->gob_work1 -= 0x10000;
                if (gob->gob_currentFrameIndex == 4)
                    GOB_Remove_00419a80(gob);
                else
                    gob->gob_currentFrameIndex++;
            }
            break;
        }
    }
    if (gob->gob_platHitType == -1)
        gob->gob_platform = 0;
    gob->gob_platHitType = -1;
}
}
