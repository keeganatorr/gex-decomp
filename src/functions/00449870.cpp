typedef void (__cdecl *PFN)(void);

extern "C" void __cdecl __initterm(PFN *pfbegin, PFN *pfend)
{
    while (pfbegin < pfend)
    {
        if (*pfbegin != 0)
            (*pfbegin)();
        ++pfbegin;
    }
}
