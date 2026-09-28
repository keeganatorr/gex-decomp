// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
extern "C" {
int __cdecl GEX_Target(int a, int b)
{
    int ub;
    int ahi;
    int alo;
    int bhi;
    int blo;
    int ua;
    int result;
    ua = a < 0 ? -a : a;
    ub = b < 0 ? -b : b;
    ahi = ua >> 16;
    blo = ub & 0xffff;
    alo = ua & 0xffff;
    bhi = ub >> 16;
    result = ((ub & 0xffff0000) + blo) * ahi + bhi * alo + ((blo * alo) >> 16);
    if ((a > 0) != (b > 0))
        result = -result;
    return result;
}
}
