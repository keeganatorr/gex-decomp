extern unsigned int DAT_0049FB90;

unsigned char * __cdecl SCRIPT_GetLinkField_00418fa0(unsigned char *p, unsigned int **obj)
{
    int i = *p++;
    int j = *p++;
    DAT_0049FB90 = obj[i + 0x1a][j + 0x1a];
    return p;
}
