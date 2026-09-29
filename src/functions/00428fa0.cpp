typedef struct ColourHSV {
    int r, g, b;
    int h, s, v;
} ColourHSV;
extern "C" {
void __cdecl FUN_00428cf0(ColourHSV *c);
void __cdecl FUN_00428e50(ColourHSV *c);
void __cdecl AdjustPlut_00428fa0(unsigned short *src, unsigned short *dst, int dh, int ds, int dv)
{
    ColourHSV hsv;
    unsigned short c;
    int count;
    int i;
    int t;
    ds = ds * 255 / 100;
    dv = dv * 255 / 100;
    ((unsigned int *)dst)[-1] = ((unsigned int *)src)[-1] | 0xffffff00;
    if (dh || ds || dv) {
        count = ((unsigned char *)dst)[-4] ? 256 : 16;
        for (i = 0; i < count; i++) {
            c = *src++;
            if (!c)
                *dst = 0;
            else {
                hsv.r = (c & 0x1f) * 255 / 31;
                hsv.g = ((c & 0x3e0) >> 5) * 255 / 31;
                hsv.b = ((c & 0x7c00) >> 10) * 255 / 31;
                FUN_00428cf0(&hsv);
                hsv.h = (hsv.h + dh + 360) % 360;
                t = ds >= 0 ? 255 - hsv.s : hsv.s;
                hsv.s += ds * t / 255;
                hsv.s = hsv.s < 255 ? hsv.s : 255;
                hsv.s = hsv.s > 0 ? hsv.s : 0;
                t = dv >= 0 ? 255 - hsv.v : hsv.v;
                hsv.v += dv * t / 255;
                hsv.v = hsv.v < 255 ? hsv.v : 255;
                hsv.v = hsv.v > 0 ? hsv.v : 0;
                FUN_00428e50(&hsv);
                *dst = ((unsigned short)((unsigned short)((unsigned short)hsv.b & 0xfff8) << 5 | (unsigned short)hsv.g) & 0xfff8 | 0xe000) << 2 | hsv.r >> 3;
            }
            dst++;
        }
    }
}
}
