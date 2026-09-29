// Palette adjustment helper. Reconstructed from the original instructions;
// the archived C translation scaled the table index twice.
extern "C" unsigned int DAT_00460048;
extern "C" unsigned int DAT_004A2AFC;
extern "C" unsigned char DAT_004A2AF8;
extern "C" unsigned char DAT_004A2AF9;
extern "C" unsigned char DAT_004A2AFA;

extern "C" unsigned int __cdecl GEX_Target(unsigned int color)
{
    if (color & 0x8000) {
        if ((color & 0xc0) == 0xc0)
            return DAT_004A2AFC;
        return (DAT_004A2AFC & 0xfefefe) >> 1;
    }

    unsigned int entry = (&DAT_00460048)[(color & 0x1f00) >> 8];
    if (DAT_004A2AFC == 0x808080)
        return entry;

    unsigned int level = entry & 0xff;
    unsigned int red = ((DAT_004A2AF8 * level) & 0x7f80) >> 7;
    unsigned int green = ((DAT_004A2AF9 * level) & 0x7f80) >> 7;
    unsigned int blue = ((DAT_004A2AFA * level) & 0x7f80) >> 7;
    return (red << 16) + (green << 8) + blue;
}
