// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;                 /* 0x78 */
    int gob_ypos;                 /* 0x7c */
    unsigned char _pad80[0x60];
    unsigned int gob_flags2;      /* 0xe0 */
    unsigned char _padE4[0x78];
    struct GXObject *gob_parent;  /* 0x15c */
    unsigned char _pad160[0x98];
    int gob_last_x;               /* 0x1f8 */
    int gob_last_y;               /* 0x1fc */
} GXObject;

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
void __cdecl GOB_RezzifyObject_00444530(GXObject *gob);
void __cdecl FUN_00433ec0(GXObject *gob);
void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(GXObject *gob);
void __cdecl KFBossDraw_00434080(GXObject *gob)
{
    GXObject *parent;
    int dx;
    int dy;
    int x;
    int y;
    int lastX;
    int lastY;
    parent = gob->gob_parent;
    if (gob->gob_flags2 & 0x40000)
        GOB_RezzifyObject_00444530(gob);
    dx = 0;
    if (parent) {
        x = gob->gob_xpos;
        y = gob->gob_ypos;
        lastX = gob->gob_last_x;
        lastY = gob->gob_last_y;
        dy = 0;
        while (parent->gob_parent) {
            dx += parent->gob_xpos;
            dy += parent->gob_ypos;
            parent = parent->gob_parent;
        }
        gob->gob_last_x = gob->gob_xpos = parent->gob_xpos + dx + x;
        gob->gob_last_y = gob->gob_ypos = parent->gob_ypos + dy + y;
        if (gob->gob_flags2 & 0x200000)
            FUN_00433ec0(gob);
        else
            GOB_DisplayObjectScaleAndRotate_00441150(gob);
        gob->gob_xpos = x;
        gob->gob_ypos = y;
        gob->gob_last_x = lastX;
        gob->gob_last_y = lastY;
        return;
    }
    if (gob->gob_flags2 & 0x200000) {
        FUN_00433ec0(gob);
        return;
    }
    GOB_DisplayObjectScaleAndRotate_00441150(gob);
}
