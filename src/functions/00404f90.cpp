typedef unsigned long DWORD;
typedef void *HANDLE;

extern "C" {
__declspec(dllimport) DWORD __stdcall GetTickCount(void);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char *);
__declspec(dllimport) int __stdcall GetExitCodeThread(HANDLE, DWORD *);
__declspec(dllimport) void __stdcall Sleep(DWORD);
__declspec(dllimport) int __stdcall TerminateThread(HANDLE, DWORD);
__declspec(dllimport) int __stdcall CloseHandle(HANDLE);

void __cdecl FUN_00404710_Window(void);
extern HANDLE gMusicThread_00487f8c;
extern HANDLE gGameThread_00487a00;
extern int DAT_0048a048;
extern int M1_004a2a80;
extern const char s_Ended_MusicThread_by_termination_00454f78[];
extern const char s_Ended_GameThread_by_termination_00454f54[];

void __cdecl FUN_00404f90_KillThreads(void)
{
    DWORD start;
    DWORD exitCode;

    FUN_00404710_Window();
    if (gMusicThread_00487f8c != 0) {
        DAT_0048a048 = 1;
        start = GetTickCount();
        while (GetExitCodeThread(gMusicThread_00487f8c, &exitCode) && exitCode == 0x103UL) {
            Sleep(0);
            if (GetTickCount() - start > 2000UL) {
                TerminateThread(gMusicThread_00487f8c, 0);
                OutputDebugStringA(s_Ended_MusicThread_by_termination_00454f78);
            }
        }
        CloseHandle(gMusicThread_00487f8c);
        gMusicThread_00487f8c = 0;
    }
    if (gGameThread_00487a00 != 0) {
        M1_004a2a80 = 2;
        start = GetTickCount();
        while (GetExitCodeThread(gGameThread_00487a00, &exitCode) && exitCode == 0x103UL) {
            Sleep(0);
            if (GetTickCount() - start > 2000UL) {
                TerminateThread(gGameThread_00487a00, 0);
                OutputDebugStringA(s_Ended_GameThread_by_termination_00454f54);
            }
        }
        CloseHandle(gGameThread_00487a00);
        gGameThread_00487a00 = 0;
    }
}
}
