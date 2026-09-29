extern "C" int __cdecl __setmbcp(int);

extern "C" void __cdecl ___initmbctable(void)
{
    __setmbcp(-3);
}
