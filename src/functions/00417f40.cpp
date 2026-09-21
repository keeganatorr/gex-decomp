extern "C" unsigned long __cdecl GEX_Target(unsigned char **cursor)
{
    unsigned char **slot = cursor;
    unsigned char *p = *slot;
    unsigned long hi = p[1];
    unsigned long lo = p[0];
    *slot = p + 2;
    return (hi << 8) | lo;
}