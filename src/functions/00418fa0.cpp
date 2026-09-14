extern unsigned int DAT_0049FB90;
unsigned char *__cdecl GEX_Target(unsigned char *cursor, void *object)
{
    unsigned int index = cursor[0];
    unsigned int offset = cursor[1];
    unsigned int **table = (unsigned int **)((char *)object + 0x68);
    unsigned int *row = table[index];
    DAT_0049FB90 = row[offset + 0x1a];
    return cursor + 2;
}
