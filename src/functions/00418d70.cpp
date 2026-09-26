// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;                 /* 0x78 */
    int gob_ypos;                 /* 0x7c */
    unsigned char _pad80[0xdc];
    struct GXObject *gob_parent;  /* 0x15c */
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
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern int decl_pad_13;
extern int decl_pad_14;
void __cdecl FUN_00420770_Movement_unk(GXObject *gob, int voice);
unsigned char *__cdecl GEX_Target(unsigned char *script, GXObject *gob)
{
    GXObject *parent;
    int voice;
    int dx;
    int dy;
    int x;
    int y;
    voice = *script++;
    parent = gob->gob_parent;
    if (parent) {
        dx = 0;
        dy = 0;
        x = gob->gob_xpos;
        y = gob->gob_ypos;
        while (parent->gob_parent) {
            dx += parent->gob_xpos;
            dy += parent->gob_ypos;
            parent = parent->gob_parent;
        }
        gob->gob_xpos = parent->gob_xpos + dx + x;
        gob->gob_ypos = parent->gob_ypos + dy + y;
    }
    FUN_00420770_Movement_unk(gob, voice);
    if (parent) {
        gob->gob_xpos = x;
        gob->gob_ypos = y;
    }
    return script;
}
}
