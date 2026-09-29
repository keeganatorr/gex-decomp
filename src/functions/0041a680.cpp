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
extern unsigned int gCollectibles_004a2660[6];
unsigned int __cdecl FUN_0041a680(void)
{
    int i;
    unsigned int v;
    for (i = 0; i < 6; i++) {
        v = gCollectibles_004a2660[i];
        if ((v & 0xff) != 4 && (v & 0xff) != 3) {
            gCollectibles_004a2660[i] = 4;
            return v;
        }
    }
    for (i = 0; i < 6; i++) {
        v = gCollectibles_004a2660[i];
        if ((unsigned char)v == 3) {
            gCollectibles_004a2660[i] = 4;
            return v;
        }
    }
    return 4;
}
}
