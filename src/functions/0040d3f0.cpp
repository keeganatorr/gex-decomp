extern "C" void *GOB_FindWithWork0_0040c110(int objectType, int frame);
extern "C" int sprintf(char *buffer, const char *format, ...);
extern "C" unsigned int strlen(const char *string);

extern "C" void GEX_Target(int param_1, int param_2)
{
    char local_8[8];
    char *pDest;
    int nDigits;
    int nLen;

    pDest = *(char **)((char *)GOB_FindWithWork0_0040c110(0x7b, param_1) + 0x9c);
    sprintf(local_8, (const char *)0x4562a8, param_2);

    nDigits = (int)strlen(local_8);
    nLen = (int)strlen(pDest);
    pDest += nLen - 1;

    while (nLen > 0) {
        if (nDigits != 0) {
            *pDest = local_8[nDigits - 1];
            nDigits--;
        } else {
            *pDest = '0';
        }
        nLen--;
        pDest--;
    }
}
