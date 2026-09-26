// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x20];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x20];
    int gob_work2;              /* 0xa0 */
    unsigned char _padA4[0x30];
    int gob_xold;               /* 0xd4 */
    int gob_yold;               /* 0xd8 */
} GXObject;
typedef struct DiveTrack { int x0; int y0; int x1; int y1; } DiveTrack;
typedef struct DiveSpeed { int a; int b; int c; int d; } DiveSpeed;
typedef struct DiveState { int a; int b; int c; } DiveState;
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
extern DiveState UINT_ARRAY_ARRAY_004645b0[8];
extern GXObject *PTR_ARRAY_00464610[8];
extern DiveTrack DAT_00464528[8];
extern DiveSpeed DAT_00464660[8];
void __cdecl GEX_Target(int x, int y)
{
    int i;
    for (i = 0; i < 8; i++) {
        UINT_ARRAY_ARRAY_004645b0[i].a = 0;
        UINT_ARRAY_ARRAY_004645b0[i].b = 0;
        UINT_ARRAY_ARRAY_004645b0[i].c = 0;
        PTR_ARRAY_00464610[i]->gob_work2 = 0;
        PTR_ARRAY_00464610[i]->gob_currentFrameIndex = 0;
        DAT_00464528[i].x1 = x;
        DAT_00464660[i].a = 0;
        DAT_00464528[i].y1 = y;
        DAT_00464660[i].b = 0;
        DAT_00464528[i].x0 = x;
        DAT_00464660[i].c = 0;
        DAT_00464528[i].y0 = y;
        PTR_ARRAY_00464610[i]->gob_xold = x;
        PTR_ARRAY_00464610[i]->gob_yold = y;
        PTR_ARRAY_00464610[i]->gob_xpos = x;
        PTR_ARRAY_00464610[i]->gob_ypos = y;
    }
}
}
