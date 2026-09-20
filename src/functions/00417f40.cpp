struct GEX_UShortBytes
{
    unsigned char low;
    unsigned char high;
};

extern "C" unsigned long __cdecl GEX_Target(GEX_UShortBytes **cursor)
{
    GEX_UShortBytes *p = *cursor;
    unsigned long value = ((unsigned long)p->high << 8) | p->low;
    *cursor = (GEX_UShortBytes *)((unsigned char *)p + 2);
    return value;
}
