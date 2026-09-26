// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x7c];
    int gob_ypos;      /* 0x7c */
    unsigned char _pad80[0xc];
    int gob_yVel;      /* 0x8c */
    unsigned char _pad90[0x34];
    int gob_angle;     /* 0xc4 */
    unsigned char _padC8[0x10];
    int gob_yold;      /* 0xd8 */
} GXObject;
typedef struct AngleBox {
    int unk0[6];
    int left;    /* 0x18 */
    int right;   /* 0x1c */
    int top;     /* 0x20 */
    int bottom;  /* 0x24 */
} AngleBox;
typedef struct GexTileStruct GexTileStruct;
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
extern int decl_pad_15;
extern int decl_pad_16;
extern int decl_pad_17;
extern int decl_pad_18;
extern int decl_pad_19;
extern int DAT_004a025c;
extern int DAT_004a0218_pState;
extern int DAT_004a23c8;
extern GexTileStruct *M1_CurrentLevel_004a2990;
int __cdecl CLD_ComputeAngleEdges_0041cb80(GXObject *gob, AngleBox *box);
int __cdecl GOB_LandedOnContours_0041a0a0(GXObject *gob, int offset);
int __cdecl FUN_00421560_DrawCharacter(GexTileStruct *tile, GXObject *gob);
int __cdecl GEX_Target(GXObject *gex)
{
    AngleBox box;
    int landed;
    int target;
    int angle;
    int offset;
    int step;
    target = 0;
    angle = gex->gob_angle;
    gex->gob_angle = 0;
    if (CLD_ComputeAngleEdges_0041cb80(gex, &box))
        target = box.bottom - gex->gob_ypos;
    gex->gob_angle = angle;
    offset = gex->gob_yold - gex->gob_ypos + DAT_004a025c;
    DAT_004a025c = target;
    step = -0x60000;
    if (offset < target)
        step = 0x60000;
    do {
        offset += step;
        if (step > 0) {
            if (offset > target)
                offset = target;
        } else if (offset < target)
            offset = target;
        landed = GOB_LandedOnContours_0041a0a0(gex, offset);
        if (landed) {
            gex->gob_ypos += offset;
            if (gex->gob_yVel >= 0)
                FUN_00421560_DrawCharacter(M1_CurrentLevel_004a2990, gex);
            break;
        }
    } while (offset != target);
    if (landed) {
        DAT_004a0218_pState = 0x81;
        DAT_004a23c8 = 0;
    }
    return landed;
}
}
