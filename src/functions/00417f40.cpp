// Assembly reads two bytes; Ghidra's uint** pseudocode obscures that access width.
extern "C" unsigned long __cdecl GEX_Target(unsigned char** cursor)
{
    unsigned char* p = *cursor;
    unsigned long value = p[0] | ((unsigned long)p[1] << 8);
    *cursor = p + 2;
    return value;
}
