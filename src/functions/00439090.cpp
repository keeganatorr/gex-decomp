// Adapted from pc_decomp_backup/src/functions/FUN_00439090.cpp
// Historical source SHA256: 765abafe96e38fec3f6fb917acc261b6198487cb19370432e8928f7e0759c26e
extern "C" {
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
extern "C" void __cdecl FUN_00437F40(void*, int);

extern "C" void __cdecl GEX_Target(void** p)
{
    int b = (int)p[0x20];
    int a = (int)p[0x22];
    int sum = a + b;
    int bound = (int)p[0x21];
    p[0x20] = (void*)sum;
    if (sum > bound) {
        p[0x20] = (void*)bound;
    } else {
        int neg_bound = -bound;
        if (neg_bound > sum) {
            p[0x20] = (void*)neg_bound;
        }
    }
    FUN_00437F40(p, (int)p[0x20]);
}
}
