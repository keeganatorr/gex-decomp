extern "C" {
extern int DAT_0049FB90;
unsigned char *__cdecl GEX_Target(unsigned char *cursor, unsigned int **object)
{
    DAT_0049FB90 = (int)object[cursor[0] + 0x1a] -
                   (int)object[cursor[1] + 0x1a];
    return cursor + 2;
}
}
