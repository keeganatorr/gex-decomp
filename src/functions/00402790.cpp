typedef unsigned long DWORD;
typedef void *HANDLE;

extern "C" {
__declspec(dllimport) DWORD __stdcall SetFilePointer(HANDLE, long, long *, DWORD);
extern DWORD DAT_0049a058;
__declspec(dllimport) int __stdcall CloseHandle(HANDLE);
extern HANDLE gMusicFile_0048a04c;
extern DWORD DAT_0049a05c;
extern long gMusicOffset_0049a050;
extern unsigned char lpBuffer_0048a050[];
extern const char s_DS_ReadFile_failed_00451698[];
__declspec(dllimport) int __stdcall ReadFile(HANDLE, void *, DWORD, DWORD *, void *);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char *);

void __cdecl GEX_Target(void)
{
    DWORD bytesToRead;
    int remaining;
    DWORD bytesRead;

    if (gMusicFile_0048a04c != 0 && DAT_0049a05c < 0xe000) {
        remaining = 0x2000;
        for (;;) {
            if (remaining + DAT_0049a058 < 0x10000)
                bytesToRead = remaining;
            else
                bytesToRead = 0x10000 - DAT_0049a058;

            if (ReadFile(gMusicFile_0048a04c,
                         lpBuffer_0048a050 + DAT_0049a058,
                         bytesToRead, &bytesRead, 0) == 0)
                break;

            if (bytesRead != bytesToRead) {
                if (gMusicOffset_0049a050 == -1) {
                    CloseHandle(gMusicFile_0048a04c);
                    gMusicFile_0048a04c = 0;
                    remaining = bytesRead;
                } else {
                    SetFilePointer(gMusicFile_0048a04c,
                                   gMusicOffset_0049a050, 0, 0);
                }
            }

            remaining -= bytesRead;
            DAT_0049a058 += bytesRead;
            DAT_0049a05c += bytesRead;
            if (DAT_0049a058 == 0x10000)
                DAT_0049a058 = 0;
            if (remaining == 0)
                return;
        }

        OutputDebugStringA(s_DS_ReadFile_failed_00451698);
        CloseHandle(gMusicFile_0048a04c);
        gMusicFile_0048a04c = 0;
    }
}
}
