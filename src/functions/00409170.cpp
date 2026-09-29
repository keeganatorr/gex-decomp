// CDIO file open with the original eight-handle table and retry prompt.
typedef unsigned long DWORD;
typedef void *HANDLE;

extern "C" {
__declspec(dllimport) HANDLE __stdcall CreateFileA(const char *, DWORD, DWORD,
    void *, DWORD, DWORD, HANDLE);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char *);
__declspec(dllimport) void __stdcall DebugBreak(void);
void __cdecl WinShowError_004063d0(int, const char *, ...);
}

extern "C" HANDLE __cdecl CDIO_FileOpen_00409170(const char *filename)
{
    unsigned &openCount = *(unsigned *)0x0047f004;
    HANDLE *handles = (HANDLE *)0x0047f010;
    if (openCount == 8) {
        OutputDebugStringA((const char *)0x0045599c);
        DebugBreak();
        return (HANDLE)-1;
    }
    HANDLE file;
    do {
        file = CreateFileA(filename, 0x80000000UL, 1, 0, 3, 0x08000000, 0);
        if (file == (HANDLE)-1)
            WinShowError_004063d0(1, (const char *)0x00487a10);
    } while (file == (HANDLE)-1);
    unsigned slot = 0;
    while (handles[slot]) ++slot;
    ++openCount;
    handles[slot] = file;
    return file;
}
