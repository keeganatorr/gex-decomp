extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int gTrigTable_0045a5c8[];
int __cdecl GEX_Target(int a, int b, int c)
{
    return ((((c - a) << 7) / (b - a)) < 0 ? -((-(((c - a) << 7) / (b - a))) > 256 ? (((-(((c - a) << 7) / (b - a))) % 256) > 128 ? -((((-(((c - a) << 7) / (b - a))) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((-(((c - a) << 7) / (b - a))) % 256) - 128)] : gTrigTable_0045a5c8[((-(((c - a) << 7) / (b - a))) % 256) - 128]) : (((-(((c - a) << 7) / (b - a))) % 256) > 64 ? gTrigTable_0045a5c8[128 - ((-(((c - a) << 7) / (b - a))) % 256)] : gTrigTable_0045a5c8[(-(((c - a) << 7) / (b - a))) % 256])) : ((-(((c - a) << 7) / (b - a))) > 128 ? -(((-(((c - a) << 7) / (b - a))) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((-(((c - a) << 7) / (b - a))) - 128)] : gTrigTable_0045a5c8[(-(((c - a) << 7) / (b - a))) - 128]) : ((-(((c - a) << 7) / (b - a))) > 64 ? gTrigTable_0045a5c8[128 - (-(((c - a) << 7) / (b - a)))] : gTrigTable_0045a5c8[-(((c - a) << 7) / (b - a))]))) : ((((c - a) << 7) / (b - a)) > 256 ? (((((c - a) << 7) / (b - a)) % 256) > 128 ? -((((((c - a) << 7) / (b - a)) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((((c - a) << 7) / (b - a)) % 256) - 128)] : gTrigTable_0045a5c8[((((c - a) << 7) / (b - a)) % 256) - 128]) : (((((c - a) << 7) / (b - a)) % 256) > 64 ? gTrigTable_0045a5c8[128 - ((((c - a) << 7) / (b - a)) % 256)] : gTrigTable_0045a5c8[(((c - a) << 7) / (b - a)) % 256])) : ((((c - a) << 7) / (b - a)) > 128 ? -(((((c - a) << 7) / (b - a)) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((((c - a) << 7) / (b - a)) - 128)] : gTrigTable_0045a5c8[(((c - a) << 7) / (b - a)) - 128]) : ((((c - a) << 7) / (b - a)) > 64 ? gTrigTable_0045a5c8[128 - (((c - a) << 7) / (b - a))] : gTrigTable_0045a5c8[((c - a) << 7) / (b - a)]))));
}
}
