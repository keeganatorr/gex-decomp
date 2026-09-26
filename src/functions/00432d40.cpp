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
void __cdecl SND_PlaySound_0041a340(GXObject *gob, int id);
void __cdecl FUN_00432e60(GXObject *gob);
void __cdecl FUN_00432d10(GXObject *gob);
void __cdecl GOB_RemoveObject_00419520(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob)
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
    if (gob->gob_work0) {
        if (--gob->gob_work0 < 20) {
            gob->gob_work2->gob_xpos += (gob->gob_work0 & 1) ? 0x10000 : -0x10000;
            if (gob->gob_work1) {
                gob->gob_work1 = 0;
                SND_PlaySound_0041a340(gob, 0x7e);
            }
        }
    } else {
        SND_PlaySound_0041a340(gob, 0x7d);
        FUN_00432e60(gob);
        FUN_00432d10(gob->gob_work2);
        GOB_RemoveObject_00419520(gob);
    }
    if (gob->gob_platHitType == -1)
        gob->gob_platform = 0;
    gob->gob_platHitType = -1;
}
}
