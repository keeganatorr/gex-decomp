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
extern int DAT_004a2b00;
extern int DAT_004a2afc;
extern unsigned char DAT_004a2af8_InitUnk4;
extern unsigned char DAT_004a2af9_InitUnk5;
extern unsigned char DAT_004a2afa_InitUnk6;
extern int DAT_0046a640_InitUnk1;
extern int DAT_0046a644_InitUnk2;
extern int DAT_0046a648_InitUnk3;
extern int DAT_0046a64c;
extern int DAT_0046a650;
extern int DAT_0046a654;
extern int DAT_0046a658;
extern int DAT_0046a65c;
extern int DAT_0046a660;
void __cdecl FUN_0043f310_InitializeGraphicsVariables(void)
{
    int changed;
    if (!DAT_004a2b00)
        return;
    changed = 0;
    if (DAT_0046a648_InitUnk3 < DAT_0046a660) {
        changed = 1;
        DAT_0046a648_InitUnk3 += DAT_0046a650;
        if (DAT_0046a648_InitUnk3 > DAT_0046a660)
            DAT_0046a648_InitUnk3 = DAT_0046a660;
        DAT_004a2afa_InitUnk6 = DAT_0046a648_InitUnk3 >> 16;
    } else if (DAT_0046a648_InitUnk3 > DAT_0046a660) {
        changed = 1;
        DAT_0046a648_InitUnk3 += DAT_0046a650;
        if (DAT_0046a648_InitUnk3 < DAT_0046a660)
            DAT_0046a648_InitUnk3 = DAT_0046a660;
        DAT_004a2afa_InitUnk6 = DAT_0046a648_InitUnk3 >> 16;
    }
    if (DAT_0046a644_InitUnk2 < DAT_0046a65c) {
        changed = 1;
        DAT_0046a644_InitUnk2 += DAT_0046a654;
        if (DAT_0046a644_InitUnk2 > DAT_0046a65c)
            DAT_0046a644_InitUnk2 = DAT_0046a65c;
        DAT_004a2af9_InitUnk5 = DAT_0046a644_InitUnk2 >> 16;
    } else if (DAT_0046a644_InitUnk2 > DAT_0046a65c) {
        changed = 1;
        DAT_0046a644_InitUnk2 += DAT_0046a654;
        if (DAT_0046a644_InitUnk2 < DAT_0046a65c)
            DAT_0046a644_InitUnk2 = DAT_0046a65c;
        DAT_004a2af9_InitUnk5 = DAT_0046a644_InitUnk2 >> 16;
    }
    if (DAT_0046a640_InitUnk1 < DAT_0046a658) {
        changed = 1;
        DAT_0046a640_InitUnk1 += DAT_0046a64c;
        if (DAT_0046a640_InitUnk1 > DAT_0046a658)
            DAT_0046a640_InitUnk1 = DAT_0046a658;
        DAT_004a2af8_InitUnk4 = DAT_0046a640_InitUnk1 >> 16;
    } else if (DAT_0046a640_InitUnk1 > DAT_0046a658) {
        changed = 1;
        DAT_0046a640_InitUnk1 += DAT_0046a64c;
        if (DAT_0046a640_InitUnk1 < DAT_0046a658)
            DAT_0046a640_InitUnk1 = DAT_0046a658;
        DAT_004a2af8_InitUnk4 = DAT_0046a640_InitUnk1 >> 16;
    }
    DAT_004a2afc = (DAT_004a2af8_InitUnk4 * 256 + DAT_004a2af9_InitUnk5) * 256 + DAT_004a2afa_InitUnk6;
    if (!changed)
        DAT_004a2b00 = 0;
}
}
