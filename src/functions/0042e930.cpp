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
extern int CAMERA_XPos_004a2a38;
void __cdecl FUN_0042e930_GRAPHICSDRAWING_SetCamera(int x1, int x2, int x3, unsigned int order)
{
    switch (order) {
    case 1:
        CAMERA_XPos_004a2a38 = x1 - ((x1 - x3) + 0x1400000 >> 1);
        return;
    case 2:
        CAMERA_XPos_004a2a38 = x1 - ((x1 - x2) + 0x1400000 >> 1);
        return;
    case 3:
        CAMERA_XPos_004a2a38 = x2 - ((x2 - x3) + 0x1400000 >> 1);
        return;
    case 4:
        CAMERA_XPos_004a2a38 = x2 - ((x2 - x1) + 0x1400000 >> 1);
        return;
    case 5:
        CAMERA_XPos_004a2a38 = x3 - ((x3 - x2) + 0x1400000 >> 1);
        return;
    case 6:
        CAMERA_XPos_004a2a38 = x3 - ((x3 - x1) + 0x1400000 >> 1);
    }
}
}
