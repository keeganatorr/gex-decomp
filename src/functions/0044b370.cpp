extern "C" int __cdecl __setmbcp(int);

extern "C" void __cdecl GEX_Target(void)
{
    __setmbcp(-3);
}
