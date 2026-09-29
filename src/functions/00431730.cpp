// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
extern "C" int decl_pad_1;
extern "C" int decl_pad_2;
extern "C" int decl_pad_3;
extern "C" int decl_pad_4;
extern "C" int decl_pad_5;
extern "C" int decl_pad_6;
extern "C" int decl_pad_7;
extern "C" int decl_pad_8;
extern "C" int decl_pad_9;
extern "C" int decl_pad_10;
// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;                 /* 0x78 */
    int gob_ypos;                 /* 0x7c */
    unsigned char _pad80[0xdc];
    struct GXObject *gob_parent;  /* 0x15c */
    unsigned char _pad160[0x98];
    int gob_last_x;               /* 0x1f8 */
    int gob_last_y;               /* 0x1fc */
} GXObject;
extern "C" {
void __cdecl FUN_00431730(GXObject *gob)
{
    GXObject *parent;
    int dx;
    int dy;
    int x;
    int y;
    dx = 0;
    parent = gob->gob_parent;
    if (parent) {
        dy = 0;
        x = gob->gob_xpos;
        y = gob->gob_ypos;
        while (parent->gob_parent) {
            dx += parent->gob_xpos;
            dy += parent->gob_ypos;
            parent = parent->gob_parent;
        }
        gob->gob_xpos = x + parent->gob_xpos + dx;
        gob->gob_last_x = gob->gob_xpos;
        gob->gob_ypos = y + parent->gob_ypos + dy;
        gob->gob_last_y = gob->gob_ypos;
    }
}
}
