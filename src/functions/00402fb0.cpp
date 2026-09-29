typedef void *HANDLE;
typedef struct STARTUPINFOA {
    unsigned long cb;
    char *lpReserved;
    char *lpDesktop;
    char *lpTitle;
    unsigned long dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars, dwFillAttribute, dwFlags;
    unsigned short wShowWindow, cbReserved2;
    unsigned char *lpReserved2;
    HANDLE hStdInput, hStdOutput, hStdError;
} STARTUPINFOA;
typedef struct PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    unsigned long dwProcessId;
    unsigned long dwThreadId;
} PROCESS_INFORMATION;
extern "C" {
void *__cdecl memset(void *dst, int value, unsigned int count);
__declspec(dllimport) int __stdcall CreateProcessA(const char *application, char *commandLine, void *processAttributes,
    void *threadAttributes, int inheritHandles, unsigned long flags, void *environment, const char *directory,
    STARTUPINFOA *startup, PROCESS_INFORMATION *process);
__declspec(dllimport) int __stdcall CloseHandle(HANDLE handle);
__declspec(dllimport) int __stdcall MessageBoxA(void *window, const char *text, const char *caption, unsigned int type);
extern char s_write_gex_wri_0045172c[];
extern char WINSTRING_Cannot_find_readme_00487520[];
extern char DAT_00487c60_WindowName_GexString[];
void __cdecl FUN_00402fb0_GEX_wri(void)
{
    PROCESS_INFORMATION process;
    STARTUPINFOA startup;
    memset(&startup, 0, sizeof(startup));
    startup.cb = sizeof(startup);
    if (CreateProcessA(0, s_write_gex_wri_0045172c, 0, 0, 0, 0, 0, 0, &startup, &process)) {
        CloseHandle(process.hThread);
        CloseHandle(process.hProcess);
    } else
        MessageBoxA(0, WINSTRING_Cannot_find_readme_00487520, DAT_00487c60_WindowName_GexString, 0x30);
}
}
