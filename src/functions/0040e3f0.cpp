// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x20];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x1c];
    int gob_work1;              /* 0x9c */
    unsigned char _padA0[0x10];
    int gob_work6;              /* 0xb0 */
    unsigned int gob_work7;     /* 0xb4 */
    unsigned char _padB8[4];
    unsigned int gob_pixc;      /* 0xbc */
    unsigned char _padC0[0x138];
    int gob_last_x;             /* 0x1f8 */
    int gob_last_y;             /* 0x1fc */
} GXObject;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern unsigned char DAT_00456334;
GXObject *__cdecl GOB_FindWithWork0_0040c110(int type, unsigned int work0);
void __cdecl FUN_0040c1a0(int a, int b);
void __cdecl GOB_DisplayObject_00444590(GXObject *gob);
void __cdecl FUN_0040e3f0_frameIndex4(GXObject *gob)
{
    unsigned int pixc;
    int x;
    int y;
    int lastX;
    int lastY;
    int frame;
    GXObject *other;
    pixc = gob->gob_pixc;
    x = gob->gob_xpos;
    y = gob->gob_ypos;
    lastX = gob->gob_last_x;
    lastY = gob->gob_last_y;
    frame = gob->gob_currentFrameIndex;
    gob->gob_last_y = gob->gob_ypos = gob->gob_work1;
    gob->gob_last_x = gob->gob_xpos = 0x7d0000;
    gob->gob_currentFrameIndex = 4;
    if (gob->gob_work1 > 0x550000) {
        gob->gob_ypos = gob->gob_work1 -= 0x80000;
    } else {
        other = GOB_FindWithWork0_0040c110(0x7b, 1);
        if (!DAT_00456334) {
            DAT_00456334 = 1;
            other->gob_work7 &= ~1;
            other->gob_currentFrameIndex = 0;
            FUN_0040c1a0(1, 8);
            gob->gob_work6 = 1;
            other = GOB_FindWithWork0_0040c110(0x7b, 2);
            other->gob_work7 &= ~1;
            other->gob_currentFrameIndex = -1;
            other = GOB_FindWithWork0_0040c110(0x7b, 3);
            other->gob_work7 &= ~1;
            other->gob_currentFrameIndex = -1;
        }
    }
    GOB_DisplayObject_00444590(gob);
    gob->gob_xpos = x;
    gob->gob_ypos = y;
    gob->gob_last_x = lastX;
    gob->gob_last_y = lastY;
    gob->gob_currentFrameIndex = frame;
    gob->gob_pixc = pixc;
}
}
