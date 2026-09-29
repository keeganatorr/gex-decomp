// Adapted from pc_decomp_backup/src/functions/FUN_00402400.cpp
// Historical source SHA256: ab98ca2a9c27bb76b337e53b99d81156d92d826edd9d3e5752213ce42e89e7e4
extern "C" {
extern int FUN_004A33AC;
extern int DAT_004a2f70_TilesUnk1;
extern int DAT_004a2f80_TilesPixelRed;
extern int DAT_004a2f7c_TilesPixelGreen;
extern int DAT_004a2f74_TilesPixelBlue;
extern unsigned char DAT_004a2b50_TRUETILESMAYBE[];
extern int DAT_004a2fa0_TilesToDrawPointer;

extern "C" int *__cdecl FUN_00402400_InnerGraphicsTilesMostInner(unsigned char PixelRed, unsigned char PixelGreen, unsigned char PixelBlue, int ppvBitsPoss, int TileCount)
{
    if (PixelRed == 0x80 && PixelGreen == 0x80 && PixelBlue == 0x80) {
        return (int *)(FUN_004A33AC + ppvBitsPoss * 0x20);
    }

    if (DAT_004a2f70_TilesUnk1 != ppvBitsPoss ||
        (PixelRed >> 3) != (unsigned char)DAT_004a2f80_TilesPixelRed ||
        (PixelGreen >> 3) != (unsigned char)DAT_004a2f7c_TilesPixelGreen ||
        (PixelBlue >> 3) != (unsigned char)DAT_004a2f74_TilesPixelBlue)
    {
        DAT_004a2f70_TilesUnk1 = ppvBitsPoss;
        DAT_004a2f80_TilesPixelRed = (unsigned int)(PixelRed >> 3) << 5;
        DAT_004a2f7c_TilesPixelGreen = (unsigned int)(PixelGreen >> 3) << 5;
        DAT_004a2f74_TilesPixelBlue = (unsigned int)(PixelBlue >> 3) << 5;

        unsigned short* source = (unsigned short*)(FUN_004A33AC + ppvBitsPoss * 0x20);
        unsigned short* output = (unsigned short*)&DAT_004a2fa0_TilesToDrawPointer;
        for (int i = 0; i < TileCount; ++i) {
            unsigned short colour = source[i];
            unsigned int red = DAT_004a2b50_TRUETILESMAYBE[(colour & 0x1f) | DAT_004a2f80_TilesPixelRed];
            unsigned int green = DAT_004a2b50_TRUETILESMAYBE[((colour >> 5) & 0x1f) | DAT_004a2f7c_TilesPixelGreen];
            unsigned int blue = DAT_004a2b50_TRUETILESMAYBE[((colour >> 10) & 0x1f) | DAT_004a2f74_TilesPixelBlue];
            output[i] = (unsigned short)((colour & 0x8000) | (blue << 10) | (green << 5) | red);
        }

        DAT_004a2f80_TilesPixelRed = DAT_004a2f80_TilesPixelRed >> 5;
        DAT_004a2f7c_TilesPixelGreen = DAT_004a2f7c_TilesPixelGreen >> 5;
        DAT_004a2f74_TilesPixelBlue = DAT_004a2f74_TilesPixelBlue >> 5;
    }

    return &DAT_004a2fa0_TilesToDrawPointer;
}
}
