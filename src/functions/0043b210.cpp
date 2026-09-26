// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad1[0x20];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad2[0x178];
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
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int DAT_004649b8[64];
extern int DAT_00464bb8[64];
extern int DAT_00464ab8[64];
extern int DAT_004648b8[64];
extern int DAT_004647b8[64];
extern void __cdecl GOB_DisplayObject_00444590(GXObject *);
void __cdecl GEX_Target(GXObject *gob)
{
    int i, x, y;
    for (i = 0; i < 64; i++) {
        gob->gob_xpos = DAT_004649b8[i];
        gob->gob_ypos = DAT_00464bb8[i];
        gob->gob_last_x = gob->gob_xpos - DAT_00464ab8[i];
        gob->gob_last_y = gob->gob_ypos - DAT_004648b8[i];
        gob->gob_currentFrameGroup = 0;
        gob->gob_currentFrameIndex = DAT_004647b8[i];
        GOB_DisplayObject_00444590(gob);
    }
    gob->gob_currentFrameGroup = 2;
    gob->gob_currentFrameIndex = 0;
}
}
