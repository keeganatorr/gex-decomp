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
extern int decl_pad_23;
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
} GXObject;

int __cdecl GEX_Target(GXObject *gob, int top, int bottom, int left, int right, int x0, int y0, int x1, int y1)
{
    int dx;
    int dy;
    int xa;
    int xb;
    int ya;
    int yb;
    dx = x1 - x0;
    dy = y1 - y0;
    top += gob->gob_ypos;
    bottom += gob->gob_ypos;
    left += gob->gob_xpos;
    right += gob->gob_xpos;
    if (x0 < left && x1 < left || x0 > right && x1 > right || y0 < top && y1 < top || y0 > bottom && y1 > bottom)
        return 0;
    if (dy & 0xffff0000) {
        xa = (top - y0 >> 8) * (dx >> 8) / (dy >> 16);
        xb = (bottom - y0 >> 8) * (dx >> 8) / (dy >> 16);
    } else {
        xa = (top - y0 >> 8) * (dx >> 8);
        xb = (bottom - y0 >> 8) * (dx >> 8);
    }
    if (dx & 0xffff0000) {
        ya = (left - x0 >> 8) * (dy >> 8) / (dx >> 16);
        yb = (right - x0 >> 8) * (dy >> 8) / (dx >> 16);
    } else {
        ya = (left - x0 >> 8) * (dy >> 8);
        yb = (right - x0 >> 8) * (dy >> 8);
    }
    xa += x0;
    xb += x0;
    ya += y0;
    yb += y0;
    if (xa >= left && xa < right || xb >= left && xb < right || ya >= top && ya < bottom || yb >= top && yb < bottom)
        return 1;
    return 0;
}
