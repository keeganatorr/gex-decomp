extern unsigned int DAT_0049FB90;

unsigned char * __cdecl GEX_Target(unsigned char *param_1, unsigned int **param_2)
{
    unsigned int index = *param_1++;
    unsigned int offset = *param_1++;

    param_2[index + 0x1a][offset + 0x1a] = DAT_0049FB90;

    return param_1;
}
