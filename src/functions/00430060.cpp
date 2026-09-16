typedef unsigned char byte;
int __cdecl GEX_Target(byte **cursor)
{
    byte *value = *cursor;
    short result = value[1];
    short low = value[0];
    result <<= 8;
    result |= low;
    *cursor = value + 2;
    return result;
}
