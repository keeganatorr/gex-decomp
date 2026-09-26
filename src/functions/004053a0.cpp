
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
void *__cdecl memcpy(void *dst, const void *src, unsigned int count);
extern unsigned char *PTR_00487f70;
extern short DAT_004517f0[];
void __cdecl GEX_Target(void)
{
    unsigned char *from;
    unsigned char *to;
    unsigned short *pixel;
    short key;
    short *src;
    short *dst;
    int x;
    int y;
    from = PTR_00487f70;
    to = PTR_00487f70 + 0x78000;
    for (y = 240; y; y--) {
        memcpy(to, from, 640);
        from += 0x800;
        to += 0x800;
    }
    pixel = (unsigned short *)(PTR_00487f70 + 0x78000);
    for (y = 240; y; y--) {
        for (x = 320; x; x--) {
            *pixel = (*pixel & 0x7bde) >> 1;
            pixel++;
        }
        pixel += 0x2c0;
    }
    key = DAT_004517f0[0];
    src = DAT_004517f0;
    dst = (short *)(PTR_00487f70 + 0xad0b6);
    for (y = 27; y; y--) {
        for (x = 138; x; x--) {
            if (key != *src)
                *dst = *src;
            dst++;
            src++;
        }
        dst += 0x376;
    }
}
