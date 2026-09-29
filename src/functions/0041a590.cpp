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
extern unsigned char BYTE_ARRAY_004a25d0[];
extern unsigned char BYTE_ARRAY_004a2540[];
extern unsigned int gCollectibles_004a2660[6];
int __cdecl GetRemoteStatus_0041a590(unsigned int RemoteLevelID)
{
    int status;
    int i;
    unsigned int kind;
    if (BYTE_ARRAY_004a25d0[RemoteLevelID] || (BYTE_ARRAY_004a2540[RemoteLevelID] & 1))
        status = 1;
    else
        status = 0;
    if (status)
        return status;
    for (i = 0; i < 6; i++) {
        kind = gCollectibles_004a2660[i] & 0xff;
        if ((kind == 0 || kind == 1 || kind == 2) && ((gCollectibles_004a2660[i] & 0xffff00) >> 8) == RemoteLevelID)
            return 2;
    }
    return status;
}
}
