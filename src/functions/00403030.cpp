typedef struct STARTUPINFOA {
    unsigned long cb;
    unsigned long rest[16];
} STARTUPINFOA;
typedef struct PROCESS_INFORMATION {
    void *hProcess;
    void *hThread;
    unsigned long dwProcessId;
    unsigned long dwThreadId;
} PROCESS_INFORMATION;

extern "C" {
__declspec(dllimport) long __stdcall RegOpenKeyA(void *hKey, const char *lpSubKey, void **phkResult);
__declspec(dllimport) long __stdcall RegQueryValueExA(void *hKey, const char *lpValueName, unsigned long *lpReserved, unsigned long *lpType, unsigned char *lpData, unsigned long *lpcbData);
__declspec(dllimport) long __stdcall RegCloseKey(void *hKey);
__declspec(dllimport) int __stdcall CreateProcessA(const char *, char *, void *, void *, int, unsigned long, void *, const char *, STARTUPINFOA *, PROCESS_INFORMATION *);
__declspec(dllimport) int __stdcall CloseHandle(void *);
__declspec(dllimport) int __stdcall MessageBoxA(void *, const char *, const char *, unsigned int);
extern void *gMainWindow_004875a0;
extern char DAT_00487970_WebAccessErrorString[];
extern char DAT_00487c60_WindowName_GexString[];
void *__cdecl memset(void *, int, unsigned int);
void *__cdecl memcpy(void *, const void *, unsigned int);
char *__cdecl strcat(char *, const char *);
char *__cdecl strcpy(char *, const char *);
char *__cdecl strncpy(char *, const char *, unsigned int);
char *__cdecl FUN_00449990_Registry2(char *, char *);
extern char lpSubKey_0045177c[];
extern char lpValueName_00451778[];
extern char s_shell_open_command_00451764[];
extern char s_http_0045173c[];

int __cdecl FUN_00403030_Registry(int dryRun)
{
    void *key;
    unsigned long size;
    unsigned long type;
    PROCESS_INFORMATION pi;
    STARTUPINFOA si;
    char buf[0x100];
    char cmd[0x100];
    char *p;
    char *tail;
    int n;
    size = 0x100;
    key = 0;
    if (!RegOpenKeyA((void *)0x80000000, lpSubKey_0045177c, &key)
        && !RegQueryValueExA(key, lpValueName_00451778, 0, &type, (unsigned char *)buf, &size)) {
        RegCloseKey(key);
        key = 0;
        strcat(buf, s_shell_open_command_00451764);
        size = 0x100;
        if (!RegOpenKeyA((void *)0x80000000, buf, &key)
            && !RegQueryValueExA(key, lpValueName_00451778, 0, &type, (unsigned char *)buf, &size)) {
            RegCloseKey(key);
            key = 0;
            p = FUN_00449990_Registry2(buf, s_shell_open_command_00451764 - 4);
            if (!p) {
                strcpy(cmd, buf);
                tail = s_http_0045173c;
            } else {
                n = p - buf;
                strncpy(cmd, buf, n);
                memcpy(cmd + n, s_http_0045173c, 36);
                tail = p + 2;
            }
            strcat(cmd, tail);
            if (!dryRun) {
                memset(&si, 0, sizeof si);
                si.cb = 0x44;
                if (CreateProcessA(0, cmd, 0, 0, 0, 0, 0, 0, &si, &pi)) {
                    CloseHandle(pi.hThread);
                    CloseHandle(pi.hProcess);
                    return 1;
                }
            } else
                return 1;
        }
    }
    if (key)
        RegCloseKey(key);
    if (!dryRun)
        MessageBoxA(gMainWindow_004875a0, DAT_00487970_WebAccessErrorString, DAT_00487c60_WindowName_GexString, 0x30);
    return 0;
}
}
