extern "C" {
extern unsigned int DAT_0049FB90;
unsigned char *__cdecl GEX_Target(unsigned char *cursor, void *object)
{
    unsigned int index = cursor[0];
    unsigned int *table = *(unsigned int **)((char *)object + 0x178);
    DAT_0049FB90 = table[index + 0x1a];
    return cursor + 1;
}
}
