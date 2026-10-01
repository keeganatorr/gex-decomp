// Rez camera reconstruction from pinned 0042eaf0..0042f5bd instructions.
// Behavioral candidate; this does not claim a byte match or historical types.
extern "C" {
extern int DAT_0045B100;
extern int DAT_0045B104;
extern int DAT_0045B108;
extern int DAT_0045B10C;
extern int DAT_0045B110;
extern int DAT_0045B114;
extern int DAT_0045B118;
extern int DAT_0045B11C;
extern int DAT_00463E0C;
extern int DAT_00463E14[17];
extern int DAT_00463E54[17];
extern int DAT_00463F10;
extern int DAT_00463F14;
extern int DAT_00463F98;
extern int DAT_00463FA0[16];
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
int __cdecl GEX_WidescreenWidth(void);
void __cdecl FUN_0042e780(int *);
int __cdecl FUN_0042e720_GraphicsUnk(int, unsigned int);
int __cdecl FUN_0042e750_GraphicsUnk(int, unsigned int);
void __cdecl FUN_0042e930_GRAPHICSDRAWING_SetCamera(int, int, int, unsigned int);
void __cdecl FUN_0042ea10(int, int, int, unsigned int);
}

// Projection temporarily changes six fields; restore all after sampling.
static void sample(int *object, int *x, int *y)
{
    int xpos = object[0x1e], ypos = object[0x1f];
    int xscale = object[0x32], yscale = object[0x33];
    int oldx = object[0x7e], oldy = object[0x7f];
    FUN_0042e780(object);
    *x = object[0x1e]; *y = object[0x1f];
    object[0x1e] = xpos; object[0x1f] = ypos;
    object[0x32] = xscale; object[0x33] = yscale;
    object[0x7e] = oldx; object[0x7f] = oldy;
}

static int order(int a, int b, int c, int inclusive, int *span)
{
    // X's first branch is strict; Y includes equality. Branch order breaks ties.
    if ((inclusive ? a <= b : a < b) && (inclusive ? b <= c : b < c)) {
        *span = c - a; return 1;
    }
    if (a <= c && c <= b) { *span = b - a; return 2; }
    if (b <= a && a <= c) { *span = c - b; return 3; }
    if (b <= c && c <= a) { *span = a - b; return 4; }
    if (c <= a && a <= b) { *span = b - c; return 5; }
    *span = a - c; return 6;
}

static int edge(int a, int b, int c, int ordering, int space)
{
    switch (ordering) {
    case 1: case 2: return a - 0x400000;
    case 3:
        if (c - b > space && a - b > space) return a - space - 0x400000;
        return b - 0x400000;
    case 4: case 6: return a - space - 0x400000;
    case 5:
        if (b - c > space && a - c > space) return a - space - 0x400000;
        return c - 0x400000;
    }
    return 0;
}

static int project(int position, int centre, int scale)
{
    return ((position - centre) >> 8) * scale + centre;
}

extern "C" void __cdecl FUN_0042eaf0_GRAPHICSDRAWING(int *first, int *second, int *third)
{
    int x1, y1, x2, y2, x3, y3, xspan, yspan, xorder, yorder;
    int axis, reciprocal, scale, i, left, right, top, bottom, delta, divisor;
    int width = GEX_WidescreenWidth();
    int viewport = width << 16;
    int xspace = (width - 128) << 16;
    DAT_0045B100 = 0x10000;
    sample(first, &x1, &y1);
    x2 = x1; y2 = y1;
    if (second) sample(second, &x2, &y2);
    x3 = (x1 + x2) >> 1; y3 = (y1 + y2) >> 1;
    if (third) sample(third, &x3, &y3);
    xorder = order(x1, x2, x3, 0, &xspan);
    yorder = order(y1, y2, y3, 1, &yspan);
    DAT_0045B100 = yspan / 112;
    axis = 2;
    if (xspan / (width - 128) > DAT_0045B100) {
        axis = 1; DAT_0045B100 = xspan / (width - 128);
    }
    if (DAT_0045B100 < 0x10000) axis = 0;
    if (DAT_0045B100 > DAT_0045B11C) DAT_0045B100 = DAT_0045B11C;
    else if (DAT_0045B100 < DAT_0045B118) DAT_0045B100 = DAT_0045B118;
    for (i = 0; i < 15; ++i) DAT_00463FA0[i] = DAT_00463FA0[i + 1];
    DAT_00463FA0[15] = DAT_0045B100;
    DAT_0045B100 = 0;
    for (i = 0; i < 16; ++i) DAT_0045B100 += DAT_00463FA0[i];
    DAT_0045B100 >>= 4;

    sample(first, &x1, &y1);
    x2 = x1; y2 = y1;
    if (second) sample(second, &x2, &y2);
    x3 = (x1 + x2) >> 1; y3 = (y1 + y2) >> 1;
    if (third) sample(third, &x3, &y3);
    if ((DAT_0045B118 < DAT_0045B100 || DAT_0045B118 == DAT_0045B11C) && axis == 1) {
        CAMERA_XPos_004a2a38 = edge(x1, x2, x3, xorder, xspace);
        FUN_0042ea10(y1, y2, y3, yorder);
    } else if ((DAT_0045B118 < DAT_0045B100 || DAT_0045B118 == DAT_0045B11C) && axis == 2) {
        CAMERA_YPos_004a2a1c = edge(y1, y2, y3, yorder, 0x700000);
        FUN_0042e930_GRAPHICSDRAWING_SetCamera(x1, x2, x3, xorder);
    } else {
        FUN_0042e930_GRAPHICSDRAWING_SetCamera(x1, x2, x3, xorder);
        FUN_0042ea10(y1, y2, y3, yorder);
    }

    reciprocal = DAT_0045B100 > 16 ? 0x10000000 / (DAT_0045B100 >> 4) : 0x10000000;
    scale = reciprocal >> 8;
    left = project(0x1200000, DAT_0045B104, scale);
    right = project(0x5400000, DAT_0045B104, scale) - viewport;
    top = project(0xa00000, DAT_0045B108, scale);
    bottom = project(0x2800000, DAT_0045B108, scale) - 0xf00000;
    if (CAMERA_XPos_004a2a38 < left || DAT_0045B114 == 0x69) CAMERA_XPos_004a2a38 = left;
    if (CAMERA_XPos_004a2a38 > right || DAT_0045B114 == 0x6a) CAMERA_XPos_004a2a38 = right;
    if (CAMERA_YPos_004a2a1c < top) CAMERA_YPos_004a2a1c = top;
    else if (CAMERA_YPos_004a2a1c > bottom) CAMERA_YPos_004a2a1c = bottom;
    DAT_0045B104 = FUN_0042e720_GraphicsUnk(CAMERA_XPos_004a2a38 + (viewport >> 1), reciprocal);
    DAT_0045B108 = FUN_0042e750_GraphicsUnk(CAMERA_YPos_004a2a1c + 0x780000, reciprocal);
    // Histories overlap at 00463e54; preserve original shift/store order.
    for (i = 1; i < 16; ++i) {
        DAT_00463E54[i] = DAT_00463E54[i + 1];
        DAT_00463E14[i] = DAT_00463E14[i + 1];
    }
    DAT_00463E54[16] = DAT_0045B104;
    DAT_00463E54[0] = DAT_0045B108;
    DAT_0045B104 = 0; DAT_0045B108 = 0;
    for (i = 1; i <= 16; ++i) {
        DAT_0045B104 += DAT_00463E54[i];
        DAT_0045B108 += DAT_00463E14[i];
    }
    DAT_0045B104 >>= 4; DAT_0045B108 >>= 4;
    CAMERA_XPos_004a2a38 = DAT_0045B104 - (viewport >> 1);
    CAMERA_YPos_004a2a1c = DAT_0045B108 - 0x780000;
    left = project(0x1600000, DAT_0045B104, scale);
    right = project(0x5000000, DAT_0045B104, scale);
    if (left >= CAMERA_XPos_004a2a38 && left < CAMERA_XPos_004a2a38 + viewport)
        DAT_0045B10C = 0x1600000 - left;
    else if (right >= CAMERA_XPos_004a2a38 && right < CAMERA_XPos_004a2a38 + viewport)
        DAT_0045B10C = 0x3200000 - right;
    else {
        delta = CAMERA_XPos_004a2a38 - left;
        divisor = (right - CAMERA_XPos_004a2a38 + delta - viewport) >> 16;
        if (divisor) delta /= divisor;
        DAT_0045B10C = ((delta >> 8) << 15) + 0x1600000 - CAMERA_XPos_004a2a38;
    }
    top = project(0xa00000, DAT_0045B108, scale);
    bottom = project(0x2400000, DAT_0045B108, scale);
    if (bottom >= CAMERA_YPos_004a2a1c && bottom < CAMERA_YPos_004a2a1c + 0xf00000)
        DAT_0045B110 = 0x2400000 - bottom;
    else {
        delta = CAMERA_YPos_004a2a1c - top;
        divisor = (delta - CAMERA_YPos_004a2a1c + bottom - 0xf00000) >> 16;
        if (divisor) delta /= divisor;
        DAT_0045B110 = (delta >> 8) * 0x5000 + 0x1000000 - CAMERA_YPos_004a2a1c;
    }
    CAMERA_XPos_004a2a38 += DAT_0045B10C;
    CAMERA_YPos_004a2a1c += DAT_0045B110;
    if (CAMERA_XPos_004a2a38 < 0x1000000) CAMERA_XPos_004a2a38 = 0x1000000;
    else if (CAMERA_XPos_004a2a38 > 0x2400000) CAMERA_XPos_004a2a38 = 0x2400000;
    if (CAMERA_YPos_004a2a1c < 0x1000000) CAMERA_YPos_004a2a1c = 0x1000000;
    else if (CAMERA_YPos_004a2a1c > 0x1800000) CAMERA_YPos_004a2a1c = 0x1800000;
    DAT_00463F10 = CAMERA_XPos_004a2a38;
    DAT_00463F98 = CAMERA_XPos_004a2a38 + viewport;
    DAT_00463F14 = CAMERA_YPos_004a2a1c;
    DAT_00463E0C = CAMERA_YPos_004a2a1c + 0xf00000;
}
