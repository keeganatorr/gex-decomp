// VC4 multibyte classification helper used by __ismbblead.
extern "C" int __cdecl _x_ismbbtype(unsigned char value, unsigned mask,
                                     unsigned char byteMask)
{
    const unsigned char *byteTypes = (const unsigned char *)0x004614a8;
    if (byteMask & byteTypes[(unsigned)value + 1]) return 1;
    if (mask) {
        const unsigned short *wideTypes = (const unsigned short *)0x004611a2;
        if (wideTypes[value] & mask) return 1;
    }
    return 0;
}
