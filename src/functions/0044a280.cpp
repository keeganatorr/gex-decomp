extern "C" char * __cdecl _cftoe(double *, char *, unsigned int, int, int);

extern "C" char * __cdecl __cftoe(double *value, char *buffer,
                                  unsigned int digits, int mode, int caps)
{
    return _cftoe(value, buffer, digits, mode, caps);
}
