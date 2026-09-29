// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad1[0x44];
    int gob_work1;              /* 0x9c */
    unsigned char _pad2[0x4];
    unsigned int gob_work3;     /* 0xa4 */
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
extern unsigned char BYTE_ARRAY_004a2540[];
extern int DAT_0045acc0;
void __cdecl ob220Init_00429a00(GXObject *gob)
{
    int tv = gob->gob_work1;
    if (tv == -1)
        gob->gob_currentFrameIndex = -1;
    else if (gob->gob_work3 & 0x40000000) {
        gob->gob_currentFrameIndex = -1;
        if (BYTE_ARRAY_004a2540[tv] & 1)
            gob->gob_work3 &= ~0x400;
        else
            gob->gob_work3 |= 0x400;
    } else if (gob->gob_work3 & 0x200) {
        if (BYTE_ARRAY_004a2540[tv] & 1) {
            gob->gob_currentFrameIndex = 0;
            gob->gob_work3 &= ~0x400;
        } else {
            gob->gob_currentFrameIndex = -1;
            gob->gob_work3 |= 0x400;
        }
    } else
        gob->gob_currentFrameIndex = 0;
    if (gob->gob_work3 & 0x20000000) {
        if (BYTE_ARRAY_004a2540[tv] & 1)
            DAT_0045acc0 = 0;
        else
            DAT_0045acc0 = -1;
    }
}
}
