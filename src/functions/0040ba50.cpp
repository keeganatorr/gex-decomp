// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad1[0x20];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad2[0x1c];
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    int gob_work3;              /* 0xa4 */
    int gob_work4;              /* 0xa8 */
    unsigned char _pad3[0x1c];
    int gob_xScale;             /* 0xc8 */
    int gob_yScale;             /* 0xcc */
} GXObject;
extern "C" {
extern int M1_IsInMap_004a2a7c;
void __cdecl ob109Init_0040ba50(GXObject *gob)
{
    M1_IsInMap_004a2a7c = 1;
    gob->gob_work1 = 0x40;
    gob->gob_work2 = 0x40;
    gob->gob_currentFrameIndex = 0;
    gob->gob_xScale = 0x50000;
    gob->gob_yScale = 0x50000;
    gob->gob_work3 = 0;
    gob->gob_xpos = 0x9f0000;
    gob->gob_ypos = 0x5b0000;
    gob->gob_work4 = 0;
}
}
