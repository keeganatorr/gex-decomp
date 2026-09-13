// Little-endian byte assembly, not an unaligned 32-bit load.
extern "C" unsigned long __cdecl GEX_Target(unsigned char** cursor)
{
    unsigned char* p = *cursor;
    unsigned long value = p[0] | ((unsigned long)p[1] << 8) |
                          ((unsigned long)p[2] << 16) | ((unsigned long)p[3] << 24);
    *cursor = p + 4;
    return value;
}
