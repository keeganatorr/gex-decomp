extern "C" char * __cdecl _cftof(double *, char *, unsigned int, int);

extern "C" char * __cdecl __cftof(double *value, char *buffer,
                                  unsigned int digits, int mode)
{
    return _cftof(value, buffer, digits, mode);
}
