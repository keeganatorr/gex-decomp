// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
extern "C" int decl_pad_1;
extern "C" int decl_pad_2;
typedef struct ColourHSV {
    int r, g, b;
    int h, s, v;
} ColourHSV;
extern "C" {
void __cdecl GEX_Target(ColourHSV *c)
{
    int r;
    int g;
    int b;
    int max;
    int min;
    int delta;
    int s;
    int h;
    int rc;
    int gc;
    int bc;
    r = c->r;
    if (r >= 0) {
        if (r >= 255)
            r = 255;
    } else
        r = 0;
    g = c->g;
    if (g >= 0) {
        if (g >= 255)
            g = 255;
    } else
        g = 0;
    b = c->b;
    if (b >= 0) {
        if (b >= 255)
            b = 255;
    } else
        b = 0;
    max = b > g ? b : g;
    max = max > r ? max : r;
    min = b < g ? b : g;
    min = min < r ? min : r;
    delta = max - min;
    if (max)
        s = delta * 255 / max;
    else
        s = 0;
    if (s) {
        rc = (max - r << 8) / delta;
        gc = (max - g << 8) / delta;
        bc = (max - b << 8) / delta;
        if (max == r)
            h = min == g ? bc + 0x500 : 0x100 - gc;
        else if (max == g)
            h = min == b ? rc + 0x100 : 0x300 - bc;
        else
            h = min == r ? gc + 0x300 : 0x500 - rc;
        h = h * 360 / 0x600;
    } else
        h = c->h;
    c->h = h;
    c->v = max;
    c->s = s;
}
}
