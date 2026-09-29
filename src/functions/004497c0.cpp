// VC4 exit dispatcher: reverse atexit callbacks, then CRT terminators.
typedef void (__cdecl *ExitCallback)(void);
extern "C" {
__declspec(dllimport) void * __stdcall GetCurrentProcess(void);
__declspec(dllimport) int __stdcall TerminateProcess(void *, unsigned);
__declspec(dllimport) void __stdcall ExitProcess(unsigned);
void __cdecl __initterm(ExitCallback *, ExitCallback *);
}

extern "C" void __cdecl _doexit(unsigned code, int quick, int returnToCaller)
{
    if (*(unsigned *)0x00461140 == 1)
        TerminateProcess(GetCurrentProcess(), code);
    *(unsigned *)0x0046113c = 1;
    *(unsigned char *)0x00461138 = (unsigned char)returnToCaller;
    if (!quick) {
        unsigned first = *(unsigned *)0x004a44dc;
        unsigned end = *(unsigned *)0x004a44d8;
        if (first && end >= first + 4) {
            unsigned *cursor = (unsigned *)(end - 4);
            do {
                if (*cursor) ((ExitCallback)*cursor)();
                --cursor;
            } while ((unsigned)cursor >= first);
        }
        __initterm((ExitCallback *)0x00451014, (ExitCallback *)0x0045101c);
    }
    __initterm((ExitCallback *)0x00451020, (ExitCallback *)0x00451024);
    if (!returnToCaller) {
        *(unsigned *)0x00461140 = 1;
        ExitProcess(code);
    }
}
