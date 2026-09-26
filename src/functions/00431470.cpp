typedef struct GXObject {
    unsigned char _pad0[0xc];
    void *gob_objectLoadData;   /* 0x0c */
    unsigned char _pad10[0x50 - 0x10];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char _pad70[0x78 - 0x70];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    unsigned char _pada4[0xac - 0xa4];
    int gob_work5;              /* 0xac */
    int gob_work6;              /* 0xb0 */
} GXObject;
extern "C" {
extern int DAT_0045b13c;
extern int DAT_0045b09c;
extern int DAT_0045b130;
extern int DAT_0045b0b0[];
extern char DAT_0045b0a0;
extern char DAT_0045b0a4;
extern char DAT_0045b0a8;
extern char DAT_0045b0ac;
void __cdecl DefDoIt_004339c0(GXObject *gob);
void __cdecl FUN_0042f5f0(GXObject *gob, int flag);
void __cdecl ob231DoIt_00430e20(GXObject *gob);
GXObject *__cdecl GOB_AddObject_004195d0(int type, int x, int y, void *loadData);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *behind, GXObject *front);
void __cdecl RezInObject_004372f0(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob)
{
    GXObject *copy;
    if (gob->gob_work0 == 0x400) {
    DAT_0045b13c++;
    DefDoIt_004339c0(gob);
    if (gob->gob_work1 == 1)
        DAT_0045b09c = 0;
    if (!(DAT_0045b13c % 8)) {
        FUN_0042f5f0(gob, 1);
        return;
    }
    } else if (gob->gob_work0 != 0x80) {
    ob231DoIt_00430e20(gob);
    if (DAT_0045b130) {
        DAT_0045b130 = 0;
        gob->gob_currentFrameGroup = 1;
        gob->gob_currentFrameIndex = 0;
        return;
    }
    } else {
    if (!--gob->gob_work2)
        gob->gob_currentFrameIndex = 1;
    if (--gob->gob_work6 <= 0) {
        gob->gob_work6 = 3;
        if (++gob->gob_work5 == 10)
            gob->gob_work5 = 0;
        gob->gob_ypos += DAT_0045b0b0[gob->gob_work5] << 16;
    }
    if (DAT_0045b0a0 && !gob->gob_work1 && DAT_0045b0ac || DAT_0045b0a4 && gob->gob_work1 == 2 && DAT_0045b0a8) {
        copy = GOB_AddObject_004195d0(0xea, gob->gob_xpos, gob->gob_ypos, gob->gob_objectLoadData);
        if (copy) {
            copy->gob_currentFrameGroup = 2;
            copy->gob_currentFrameIndex = 0;
            copy->gob_flags = gob->gob_flags;
            copy->gob_flags |= 0x200000;
            GOB_PutObjectInfrontOfObject_00419be0(copy, gob);
        }
        gob->gob_currentFrameIndex = 0;
        RezInObject_004372f0(gob);
        if (DAT_0045b0a4) {
            DAT_0045b0ac = 1;
            DAT_0045b0a8 = 0;
        } else {
            DAT_0045b0a8 = 1;
            DAT_0045b0ac = 0;
        }
        DAT_0045b0a4 = 0;
        DAT_0045b0a0 = 0;
    }
    }
}
}
