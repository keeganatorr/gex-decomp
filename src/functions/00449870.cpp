typedef void (__cdecl *PFN)(void);

extern "C" void __cdecl GEX_Target(PFN *pfbegin, PFN *pfend)
{
    while (pfbegin < pfend)
    {
        if (*pfbegin != 0)
            (*pfbegin)();
        ++pfbegin;
    }
}
