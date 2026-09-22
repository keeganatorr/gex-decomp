extern "C" {
__declspec(dllimport) int __stdcall wvsprintfA(char *, const char *, char *);
__declspec(dllimport) void * __stdcall GetActiveWindow(void);
__declspec(dllimport) int __stdcall MessageBoxA(void *, const char *, const char *, unsigned int);
__declspec(dllimport) int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);
__declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);
__declspec(dllimport) void __stdcall Sleep(unsigned long);
void __cdecl FUN_004013e0_ExitFullscreen_Clean1(int);
extern int gCurrentErrorTypeShown_00487f74;
extern void *gMainWindow_004875a0;
extern char DAT_00487770_recvBuffer[];
extern const char WindowTitle_GEX[];
extern unsigned long DAT_0048776c_VideoThread;
extern unsigned long DAT_004879f0_AudioThread;
}

extern "C" void __cdecl GEX_Target(int dialogType, const char *formatString, ...)
{
    char *arguments;
    void *windowHandle;
    unsigned long threadId;
    int shouldContinue;
    int msgBoxResult;

    gCurrentErrorTypeShown_00487f74 = dialogType;
    if (dialogType != 0)
        FUN_004013e0_ExitFullscreen_Clean1(0);

    arguments = (char *)(&formatString + 1);
    wvsprintfA(DAT_00487770_recvBuffer, formatString, arguments);
    windowHandle = GetActiveWindow();
    if (windowHandle == 0)
        windowHandle = gMainWindow_004875a0;

    switch (gCurrentErrorTypeShown_00487f74) {
    case 0:
        MessageBoxA(windowHandle, DAT_00487770_recvBuffer, WindowTitle_GEX, 0x30);
        shouldContinue = 1;
        break;
    case 1:
        msgBoxResult = MessageBoxA(windowHandle, DAT_00487770_recvBuffer, WindowTitle_GEX, 0x15);
        shouldContinue = (msgBoxResult != 2);
        break;
    case 2:
        MessageBoxA(windowHandle, DAT_00487770_recvBuffer, WindowTitle_GEX, 0x10);
        shouldContinue = 0;
        break;
    }

    if (shouldContinue <= 0) {
        if (gMainWindow_004875a0 != 0)
            PostMessageA(gMainWindow_004875a0, 0x12, 0, 0);
        threadId = GetCurrentThreadId();
        if (threadId == DAT_0048776c_VideoThread || threadId == DAT_004879f0_AudioThread) {
            Sleep(0xffffffffUL);
            return;
        }
    } else {
        gCurrentErrorTypeShown_00487f74 = 0;
    }
}
