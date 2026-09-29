// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
extern "C" int decl_pad_1;
extern "C" int decl_pad_2;
extern "C" int decl_pad_3;
extern "C" int decl_pad_4;
extern "C" int decl_pad_5;
extern "C" int decl_pad_6;
extern "C" int decl_pad_7;
extern "C" int decl_pad_8;
extern "C" int decl_pad_9;
extern "C" int decl_pad_10;
extern "C" int decl_pad_11;
extern "C" int decl_pad_12;
extern "C" int decl_pad_13;
extern "C" int decl_pad_14;
extern "C" int decl_pad_15;
extern "C" int decl_pad_16;
extern "C" int decl_pad_17;
extern "C" int decl_pad_18;
extern "C" {
unsigned int __cdecl EVENT_ExtractUShort_00417f40(unsigned char **cursor)
{
    unsigned int v = ((*cursor)[1] << 8) | (*cursor)[0];
    *cursor += 2;
    return v;
}
}
