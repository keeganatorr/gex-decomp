typedef struct GXObject {
    unsigned char pad0[0xe0];
    unsigned int gob_flags2;    /* 0xe0 */
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
void __cdecl EFECT_MakeSplash_004216b0(GXObject *gob);

void __cdecl GEX_Target(GXObject *gob)
{
    int wasHit;
    int hit;

    wasHit = (gob->gob_flags2 & 0x200) != 0;
    hit = (gob->gob_flags2 & 0x100) != 0;
    if (wasHit != hit) {
        if (gob->gob_flags2 & 0x100)
            EFECT_MakeSplash_004216b0(gob);
        else
            EFECT_MakeSplash_004216b0(gob);
    }
}
}
