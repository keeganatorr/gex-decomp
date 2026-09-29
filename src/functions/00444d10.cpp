struct GraphicsFillRect {
    short x;
    short y;
    short width;
    short height;
};

extern "C" int __cdecl FUN_00444d10_GFX_OpenGraphics(GraphicsFillRect *rect,
                                                     unsigned char red,
                                                     unsigned char green,
                                                     unsigned char blue)
{
    unsigned short color = (unsigned short)((((blue & 0xf8) << 5) |
                                              (green & 0xf8)) << 2 |
                                             (red >> 3));
    unsigned short *pixels = *(unsigned short **)0x004a33ac;
    pixels += rect->y * 0x400 + rect->x;
    for (int row = 0; row < rect->height; ++row) {
        for (int column = 0; column < rect->width; ++column)
            pixels[column] = color;
        pixels += 0x400;
    }
    return 1;
}
