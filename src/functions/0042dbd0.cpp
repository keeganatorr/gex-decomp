// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x7c];
    int gob_ypos;         /* 0x7c */
    unsigned char _pad80[0x6c];
    int gob_topEdge;      /* 0xec */
    int gob_bottomEdge;   /* 0xf0 */
    unsigned char _padF4[0x90];
    int gob_checkXpos;    /* 0x184 */
    int gob_checkYpos;    /* 0x188 */
} GXObject;
typedef struct TileAttribute { unsigned int flags; int unk[7]; } TileAttribute;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern TileAttribute DAT_0045B9A0[];
void __cdecl FUN_0042cc70_Object_unk(int reason, GXObject *object);
int __cdecl FUN_0042d680_ObjCallUnk(GXObject *gob, unsigned short *block);
int __cdecl GEX_Target(GXObject *gob, unsigned short *block)
{
    int xoffset;
    int ypos;
    int yoffset;
    int limit;
    xoffset = gob->gob_checkXpos & 0x1fffff;
    ypos = gob->gob_checkYpos;
    yoffset = ypos & 0x1fffff;
    switch (DAT_0045B9A0[block[3]].flags & 0xf000000) {
    case 0x1000000:
        if (yoffset <= xoffset) {
            gob->gob_ypos += xoffset - yoffset;
            gob->gob_bottomEdge = (ypos & 0xffe00000) + xoffset;
            if (gob->gob_topEdge)
                FUN_0042cc70_Object_unk(0, gob);
            return 1;
        }
        break;
    case 0x2000000:
        limit = 0x1f0000 - xoffset;
        if (yoffset <= limit) {
            gob->gob_ypos += limit - yoffset;
            gob->gob_bottomEdge = (ypos & 0xffe00000) + limit;
            if (gob->gob_topEdge)
                FUN_0042cc70_Object_unk(0, gob);
            return 1;
        }
        break;
    case 0x4000000:
        return FUN_0042d680_ObjCallUnk(gob, block);
    case 0x8000000:
        return FUN_0042d680_ObjCallUnk(gob, block);
    }
    return 0;
}
}
