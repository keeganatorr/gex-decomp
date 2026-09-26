// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;                 /* 0x78 */
    int gob_ypos;                 /* 0x7c */
    unsigned char _pad80[0x54];
    int gob_xold;                 /* 0xd4 */
    int gob_yold;                 /* 0xd8 */
    unsigned char _padDC[0x80];
    struct GXObject *gob_parent;  /* 0x15c */
} GXObject;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
void __cdecl FUN_00434b10_EVENT_Collision_Unk(GXObject *gob, int *event);
void __cdecl GEX_Target(GXObject *gob, int *event)
{
    GXObject *parent;
    int x;
    int y;
    int xold;
    int yold;
    int dx;
    int dy;
    int dxold;
    int dyold;
    parent = gob->gob_parent;
    x = gob->gob_xpos;
    y = gob->gob_ypos;
    xold = gob->gob_xold;
    yold = gob->gob_yold;
    dx = 0;
    if (parent) {
        dy = 0;
        dxold = 0;
        dyold = 0;
        while (parent->gob_parent) {
            dx += parent->gob_xpos;
            dy += parent->gob_ypos;
            dxold += parent->gob_xold;
            dyold += parent->gob_yold;
            parent = parent->gob_parent;
        }
        gob->gob_xpos = parent->gob_xpos + dx + x;
        gob->gob_ypos = parent->gob_ypos + dy + y;
        gob->gob_xold = parent->gob_xold + dxold + xold;
        gob->gob_yold = parent->gob_yold + dyold + yold;
    }
    FUN_00434b10_EVENT_Collision_Unk(gob, event);
    if (gob->gob_parent) {
        gob->gob_xpos = x;
        gob->gob_ypos = y;
        gob->gob_xold = xold;
        gob->gob_yold = yold;
    }
}
}
