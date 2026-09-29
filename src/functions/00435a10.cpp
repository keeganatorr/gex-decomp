// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad1[0x40];
    int gob_work0;              /* 0x98 */
    unsigned char _pad2[0x4];
    int gob_work2;              /* 0xa0 */
    unsigned char _pad3[0x18];
    unsigned int gob_pixc;      /* 0xbc */
} GXObject;
extern "C" {
// DAT_0045b7c0: three pixel-colour words, then a frame-group table at +0x18.
extern unsigned int DAT_0045b7c0[];
extern void __cdecl GOB_DisplayObject_00444590(GXObject *);
void __cdecl FUN_00435a10(GXObject *gob)
{
    unsigned int pixc = gob->gob_pixc;
    gob->gob_pixc = DAT_0045b7c0[0];
    gob->gob_currentFrameGroup = DAT_0045b7c0[6 + gob->gob_work0] + 1;
    gob->gob_currentFrameIndex = 2;
    GOB_DisplayObject_00444590(gob);
    switch (gob->gob_work2 & 3) {
    case 1:
    case 3:
        gob->gob_pixc = DAT_0045b7c0[1];
        gob->gob_currentFrameIndex = 0;
        GOB_DisplayObject_00444590(gob);
        break;
    case 2:
        gob->gob_pixc = DAT_0045b7c0[2];
        gob->gob_currentFrameIndex = 1;
        GOB_DisplayObject_00444590(gob);
        break;
    }
    gob->gob_pixc = pixc;
}
}
