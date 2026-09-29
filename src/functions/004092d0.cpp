// CDIO seek repeats after the game's file-access error prompt.
typedef unsigned long DWORD;
typedef void *HANDLE;

extern "C" {
__declspec(dllimport) DWORD __stdcall SetFilePointer(HANDLE, long, long *, DWORD);
void __cdecl WinShowError_004063d0(int, const char *, ...);
}

extern "C" void __cdecl CDIO_FileSeek_004092d0(HANDLE file, long distance,
                                                  DWORD origin)
{
    while (SetFilePointer(file, distance, 0, origin) == 0xffffffffUL)
        WinShowError_004063d0(1, (const char *)0x00487a10);
}
