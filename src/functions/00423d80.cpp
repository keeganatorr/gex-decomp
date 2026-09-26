// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;  /* 0x78 */
    int gob_ypos;  /* 0x7c */
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
extern int __cdecl GetGlueDist_0040f1d0(void *, GXObject *);
int __cdecl GEX_Target(void *level, GXObject *gob, int x, int y)
{
    int result;
    int xpos = gob->gob_xpos;
    int ypos = gob->gob_ypos;
    gob->gob_xpos = x;
    gob->gob_ypos = y;
    result = GetGlueDist_0040f1d0(level, gob);
    gob->gob_xpos = xpos;
    gob->gob_ypos = ypos;
    return result;
}
}
