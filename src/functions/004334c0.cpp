// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;     /* 0x78 */
    int gob_ypos;     /* 0x7c */
    unsigned char _pad1[0x48];
    int gob_xScale;   /* 0xc8 */
    int gob_yScale;   /* 0xcc */
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
extern void __cdecl GOB_RezzifyObject_00444530(GXObject *);
extern void __cdecl FUN_0042e850(GXObject *);
extern void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(GXObject *);
void __cdecl GEX_Target(GXObject *gob)
{
    int xpos = gob->gob_xpos;
    int ypos = gob->gob_ypos;
    int xScale = gob->gob_xScale;
    int yScale = gob->gob_yScale;
    GOB_RezzifyObject_00444530(gob);
    FUN_0042e850(gob);
    GOB_DisplayObjectScaleAndRotate_00441150(gob);
    gob->gob_xpos = xpos;
    gob->gob_ypos = ypos;
    gob->gob_xScale = xScale;
    gob->gob_yScale = yScale;
}
}
