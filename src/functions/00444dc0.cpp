extern "C" void __cdecl FUN_00448710_InnerGraphicsTiles1(void *, unsigned int);
extern "C" void __cdecl FUN_00446890_InnerGraphicsTiles2(void *, unsigned int);
extern "C" void __cdecl FUN_00447850_InnerGraphicsTiles3(void *, unsigned int);
extern "C" void __cdecl FUN_004466a0_DrawBoxBehindText(int, int, unsigned int,
                                                      int, unsigned int, int);
extern "C" __declspec(dllimport) void __stdcall DebugBreak(void);

static unsigned int __cdecl TileColour_00444dc0(const unsigned char *data)
{
    return (unsigned short)((((data[6] & 0xf8) << 5) |
                             (data[5] & 0xf8)) << 2 | (data[4] >> 3));
}

extern "C" void __cdecl FUN_00444dc0_InnerGraphics_Tiles(void *command)
{
    unsigned char *data = (unsigned char *)command;
    unsigned int type = data[7];
    unsigned int transparent = type & 2;
    if (type == 0x2c || type == 0x2e) {
        unsigned int texture = *(unsigned short *)(data + 0x16);
        unsigned int palette = *(unsigned int *)0x004a33ac +
                               (texture & 0xf) * 0x80;
        if (texture & 0x10)
            palette += 0x80000;
        *(unsigned int *)0x004a2f78 = palette;
        unsigned int mode = (texture >> 7) & 3;
        *(unsigned char *)0x004a2f90 = (unsigned char)mode;
        if (mode == 0)
            FUN_00448710_InnerGraphicsTiles1(command, transparent);
        else if (mode == 1)
            FUN_00446890_InnerGraphicsTiles2(command, transparent);
        else if (mode == 2)
            FUN_00447850_InnerGraphicsTiles3(command, transparent);
        else
            DebugBreak();
        return;
    }

    if (type == 0x60 || type == 0x62) {
        FUN_004466a0_DrawBoxBehindText(*(short *)(data + 8),
                                        *(short *)(data + 0xa),
                                        (unsigned int)(short)*(short *)(data + 0xc),
                                        *(short *)(data + 0xe),
                                        TileColour_00444dc0(data), transparent);
        return;
    }
    if (type == 0x64 || type == 0x66) {
        unsigned int mode = *(unsigned char *)0x004a2f90;
        unsigned int table = transparent ? 0x004610e8 : 0x004610d8;
        void (__cdecl *draw)(void *) = ((void (__cdecl **)(void *))table)[mode];
        draw(command);
        return;
    }
    if (type == 0x68 || type == 0x6a || type == 0x70 || type == 0x72 ||
        type == 0x78 || type == 0x7a) {
        int dimension = type >= 0x78 ? 16 : type >= 0x70 ? 8 : 1;
        FUN_004466a0_DrawBoxBehindText(*(short *)(data + 8),
                                        *(short *)(data + 0xa), dimension,
                                        dimension, TileColour_00444dc0(data),
                                        transparent);
        return;
    }
    if (type == 0xe1) {
        unsigned int texture = *(unsigned int *)(data + 4);
        unsigned int palette = *(unsigned int *)0x004a33ac +
                               (texture & 0xf) * 0x80;
        if (texture & 0x10)
            palette += 0x80000;
        *(unsigned int *)0x004a2f78 = palette;
        *(unsigned char *)0x004a2f90 = (unsigned char)((texture & 0x1ff) >> 7);
        *(unsigned int *)0x004a33a0 = (texture & 0x30) ? 0x30 : 0;
    }
}
