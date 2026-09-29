// Four-bit sprite rasterizer reconstructed from the pinned 00445390 body.
// Texture bytes hold two palette indexes; index zero is transparent.
extern "C" {
extern int DAT_00450008;
extern int DAT_0045000C;
extern int DAT_00450010;
extern int DAT_00450014;
extern int DAT_00450018;
extern int DAT_0045001C;
extern int DAT_004A2B24;
extern int DAT_004A2B30;
extern int DAT_004A2F58;
extern int DAT_004A2F5C;
extern int DAT_004A2F60;
extern int DAT_004A2F64;
extern unsigned short* DAT_004A2F6C;
extern unsigned char* DAT_004A2F78;
extern int DAT_004A2F88;
extern int DAT_004A2F8C;
extern unsigned short* DAT_004A33AC;

unsigned short* __cdecl FUN_00402400(unsigned char, unsigned char,
                                      unsigned char, unsigned short, int);

void __cdecl FUN_00445390_DrawTilesInner1(void* command)
{
    const unsigned char* bytes = static_cast<const unsigned char*>(command);
    DAT_004A2F58 = bytes[0x0c];
    DAT_004A2F5C = bytes[0x0d];
    DAT_004A2F60 = *reinterpret_cast<const short*>(bytes + 8);
    DAT_004A2F64 = *reinterpret_cast<const short*>(bytes + 0x0a);
    DAT_004A2F8C = *reinterpret_cast<const short*>(bytes + 0x10);
    DAT_004A2F88 = *reinterpret_cast<const short*>(bytes + 0x12);
    DAT_004A2F6C = FUN_00402400(bytes[4], bytes[5], bytes[6],
                                  *reinterpret_cast<const unsigned short*>(bytes + 0x0e), 16);

    int x = DAT_004A2F60;
    int y = DAT_004A2F64;
    int u = DAT_004A2F58;
    int v = DAT_004A2F5C;
    int width = DAT_004A2F8C;
    int height = DAT_004A2F88;
    if (width <= 0 || height <= 0 || x >= DAT_0045000C || y >= DAT_00450014)
        return;

    if (x < DAT_00450008) {
        int skip = DAT_00450008 - x;
        if (skip >= width)
            return;
        x += skip;
        u += skip;
        width -= skip;
        if (width > DAT_00450018)
            width = DAT_00450018;
    } else if (x + width > DAT_0045000C) {
        width = DAT_0045000C - x;
    }
    if (y < DAT_00450010) {
        int skip = DAT_00450010 - y;
        if (skip >= height)
            return;
        y += skip;
        v += skip;
        height -= skip;
        if (height > DAT_0045001C)
            height = DAT_0045001C;
    } else if (y + height > DAT_00450014) {
        height = DAT_00450014 - y;
    }

    DAT_004A2F58 = u;
    DAT_004A2F5C = v;
    DAT_004A2F60 = x;
    DAT_004A2F64 = y;
    DAT_004A2F8C = width;
    DAT_004A2F88 = height;
    DAT_004A2B24 = 0x800 - width * 2;
    DAT_004A2B30 = 0x800 - width / 2;

    unsigned short* palette = DAT_004A2F6C;
    for (int row = 0; row < height; ++row) {
        const unsigned char* texture = DAT_004A2F78 + (v + row) * 0x800;
        unsigned short* screen = DAT_004A33AC + (y + row) * 0x400 + x;
        for (int column = 0; column < width; ++column) {
            int texture_x = u + column;
            unsigned char packed = texture[texture_x >> 1];
            unsigned int index = (texture_x & 1) ? packed >> 4 : packed & 15;
            unsigned short colour = palette[index];
            if (colour != 0)
                screen[column] = colour;
        }
    }
    DAT_004A2F88 = 0;
}
}
