extern "C" void __cdecl _FF_MSGBANNER(void);
extern "C" void __cdecl _NMSG_WRITE(int);

extern "C" void __cdecl __amsg_exit(int code)
{
    if (*(int *)0x00461178 == 1)
        _FF_MSGBANNER();
    _NMSG_WRITE(code);
    (*(void (__cdecl **)(int))0x00461174)(0xff);
}
