extern "C" void __cdecl _cftog(double *, char *, unsigned int, int);

extern "C" void __cdecl __cftog(double *value, char *buffer,
                                 unsigned int digits, int mode)
{
    _cftog(value, buffer, digits, mode);
}
