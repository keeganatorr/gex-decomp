// Script field block of a GXObject (0x68 in Ghidra is gob_points; scripts index words from there).
typedef struct GXObject {
    unsigned char _pad0[0x68];
    int gob_fields[61];                 /* 0x68 */
    struct GXObject *gob_parent;        /* 0x15c */
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
extern int SCRIPT_WorkRegister_0049fb90;
extern GXObject *DAT_0049fb94;
unsigned char * __cdecl GEX_Target(unsigned char *script, GXObject *gob)
{
    int field = *script++;
    int value = gob->gob_fields[field];
    while (gob->gob_parent)
        gob = gob->gob_parent;
    gob->gob_fields[field] = value;
    return script;
}
}
