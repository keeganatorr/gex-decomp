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
int __cdecl abs(int);

int __cdecl FUN_00429190(int param_1, int param_2, int param_3, int param_4)
{
    int dx;
    unsigned int flags = 0;
    int dy;
    int adx, ady;

    dx = param_3 - param_1;
    dy = param_4 - param_2;
    adx = abs(dx);
    ady = abs(dy);

    if (dx > 0)
        flags = 1;
    if (dy > 0)
        flags |= 2;

    if (ady < adx) {
        flags |= 4;
        if ((adx >> 1) > ady) {
            flags |= 8;
            return ((int *)0x45ab68)[flags];
        }
    } else {
        if ((ady >> 1) > adx)
            flags |= 8;
    }

    return ((int *)0x45ab68)[flags];
}
}
