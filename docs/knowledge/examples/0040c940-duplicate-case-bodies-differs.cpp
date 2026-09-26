typedef struct AnimEntry {
    int unk0;
    int key;              /* 0x4 */
    unsigned char remap;  /* 0x8 */
    unsigned char unk9[3];
} AnimEntry;
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
extern AnimEntry DAT_004560f0[8];
extern unsigned char DAT_0045A178[];
void __cdecl GEX_Target(void)
{
    int i;
    int value;
    for (i = 0; i < 8; i++) {
        switch (DAT_004560f0[i].key) {
        case 0xe:
            value = 6;
            break;
        case 0x10:
            value = 5;
            break;
        case 0x12:
            value = 8;
            break;
        case 0xc:
        case 0x70:
            value = 4;
            break;
        default:
            value = 9;
            break;
        }
        if (DAT_004560f0[i].remap == 4)
            DAT_0045A178[4] = value;
        else if (DAT_004560f0[i].remap == 5)
            DAT_0045A178[5] = value;
        else if (DAT_004560f0[i].remap == 6)
            DAT_0045A178[6] = value;
        else if (DAT_004560f0[i].remap == 8)
            DAT_0045A178[8] = value;
        else if (DAT_004560f0[i].remap == 9)
            DAT_0045A178[9] = value;
        else if (DAT_004560f0[i].remap == 12)
            DAT_0045A178[12] = value;
        else if (DAT_004560f0[i].remap == 13)
            DAT_0045A178[13] = value;
        else if (DAT_004560f0[i].remap == 14)
            DAT_0045A178[14] = value;
    }
}
}
