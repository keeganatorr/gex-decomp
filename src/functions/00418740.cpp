typedef unsigned char byte;
extern "C" {
extern void __cdecl FUN_0041E880(void *, int);
unsigned char *__cdecl GEX_Target(byte *cursor, unsigned int *object)
{
    byte value = *cursor;
    FUN_0041E880(object, (int)value);
    object[0x1b] = (object[0x1b] & 0xfffff0ff) | ((unsigned int)value << 8);
    return cursor + 1;
}
}
