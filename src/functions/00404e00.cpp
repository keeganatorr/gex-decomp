extern "C" {
    __declspec(dllimport) int __stdcall LoadStringA(void *hInstance, unsigned int uID, char *lpBuffer, int nBufferMax);
    extern void *ghInstance_00487f90;
    extern char *STRING_CurrentBufferPtr_00487fd8;
    extern int STRING_BufferSizeRemaining_00487fdc;
    unsigned int __cdecl strlen(const char *);

    char * __cdecl STRING_Load_00404e00(unsigned int param_1)
    {
        char *p = STRING_CurrentBufferPtr_00487fd8;
        int len;
        LoadStringA(ghInstance_00487f90, param_1, p, STRING_BufferSizeRemaining_00487fdc);
        len = strlen(p) + 1;
        STRING_CurrentBufferPtr_00487fd8 += len;
        STRING_BufferSizeRemaining_00487fdc -= len;
        return p;
    }
}