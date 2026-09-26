// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x7c];
    int gob_ypos;     /* 0x7c */
    unsigned char _pad80[0xc];
    int gob_yVel;     /* 0x8c */
    int gob_maxyVel;  /* 0x90 */
    int gob_yAccl;    /* 0x94 */
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
void __cdecl FUN_004211d0(GXObject *gob);
int __cdecl FUN_00420ce0_GexWallCollision(GXObject *gob);
void __cdecl GEX_Target(GXObject *gex)
{
    int slowdown;
    gex->gob_yVel += gex->gob_yAccl;
    if (gex->gob_yVel < 0) {
        if (gex->gob_yVel < -gex->gob_maxyVel)
            gex->gob_yVel = -gex->gob_maxyVel;
    } else if (gex->gob_yVel > gex->gob_maxyVel)
        gex->gob_yVel = gex->gob_maxyVel;
    FUN_004211d0(gex);
    slowdown = FUN_00420ce0_GexWallCollision(gex);
    if (slowdown) {
        if (gex->gob_yVel > 0)
            gex->gob_ypos += gex->gob_yVel / slowdown;
        else
            gex->gob_ypos += (gex->gob_yVel >> 8) * ((0x18000 / slowdown) >> 8);
    } else
        gex->gob_ypos += gex->gob_yVel;
}
}
