extern "C" void __cdecl doexit(int, int, int);

extern "C" void __cdecl GEX_Target(int code)
{
    doexit(code, 0, 0);
}
