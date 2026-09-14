typedef unsigned char byte;
int __cdecl GEX_Target(byte **cursor)
{
    byte *value = *cursor;
    int high = value[1];
    int low = value[0];
    int result = (high << 8) | low;
    *cursor = value + 2;
    return (short)result;
}
