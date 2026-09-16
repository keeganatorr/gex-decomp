extern "C" void __cdecl __doexit(unsigned int, int, int);

extern "C" void __cdecl GEX_Target(unsigned int code)
{
    __doexit(code, 1, 0);
}
