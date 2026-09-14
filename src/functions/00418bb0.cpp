typedef unsigned char byte;
extern "C" {
extern void *DAT_0049FB94;
byte *__cdecl GEX_Target(byte *cursor, void **object)
{
    byte *value = cursor;
    object[*value + 0x1a] = DAT_0049FB94;
    return value + 1;
}
}
