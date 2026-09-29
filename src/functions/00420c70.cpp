// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;            /* 0x78 */
    int gob_ypos;            /* 0x7c */
    unsigned char _pad80[0x60];
    unsigned int gob_flags2; /* 0xe0 */
} GXObject;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int DAT_00463ab4_FrameCount;
extern int gTimer_004a2ac8;
extern GXObject *DAT_00463ac0_PlayerStruct;
extern void *M1_CurrentLevel_004a2990;
int __cdecl M1_GetBlockAttributeIDAtPos_0040f170(void *level, int x, int y);
unsigned int __cdecl FUN_00420c70_GexWallCollisionInner(GXObject *gob)
{
    int attribute;
    if (gTimer_004a2ac8 != DAT_00463ab4_FrameCount || DAT_00463ac0_PlayerStruct != gob) {
        DAT_00463ac0_PlayerStruct = gob;
        DAT_00463ab4_FrameCount = gTimer_004a2ac8;
        attribute = M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos, gob->gob_ypos - 0x80000);
        if (attribute >= 0x50 && attribute <= 0x53)
            gob->gob_flags2 |= 0x100;
    }
    return (gob->gob_flags2 & 0x200) >> 9;
}
}
