typedef unsigned char byte;
int __cdecl FUN_00430060_MovePos(byte **cursor)
{
    byte *value = *cursor;
    short result = value[1];
    short low = value[0];
    result <<= 8;
    result |= low;
    *cursor = value + 2;
    return result;
}
