typedef struct GXObject {
    unsigned char unk0[0x98];
    int gob_work0;
    void *gob_work1;
} GXObject;
typedef struct AnimEntry { int unk0; int key; int unk8; } AnimEntry;
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
extern int decl_pad_20;
extern int decl_pad_21;
extern int decl_pad_22;
extern int decl_pad_23;
extern int decl_pad_24;
extern int decl_pad_25;
extern int decl_pad_26;
extern AnimEntry DAT_004560f0[8];
extern unsigned char DAT_0045A178[];
void __cdecl FUN_0040c2c0_GameFunkUnk(GXObject *gob)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (DAT_004560f0[i].key == gob->gob_work0)
            gob->gob_work1 = &DAT_004560f0[i];
    }
    DAT_0045A178[4] = 4;
    DAT_0045A178[5] = 5;
    DAT_0045A178[6] = 6;
    DAT_0045A178[8] = 8;
    DAT_0045A178[9] = 9;
    DAT_0045A178[12] = 12;
    DAT_0045A178[13] = 13;
    DAT_0045A178[14] = 14;
}
}
