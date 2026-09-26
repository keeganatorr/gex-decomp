extern "C" {
__declspec(dllimport) unsigned long __stdcall timeGetTime(void);
__declspec(dllimport) void __stdcall Sleep(unsigned long milliseconds);
extern int DAT_004517e8_CurrentFrameCount;
int __cdecl GEX_Target(void)
{
    int now;
    int late;
    now = timeGetTime();
    if (!DAT_004517e8_CurrentFrameCount) {
        DAT_004517e8_CurrentFrameCount = now;
        return 1;
    }
    DAT_004517e8_CurrentFrameCount += 33;
    late = now - DAT_004517e8_CurrentFrameCount;
    if (late >= 333) {
        DAT_004517e8_CurrentFrameCount = now;
        return 1;
    }
    if (late >= 0)
        return late < 33;
    while (now < DAT_004517e8_CurrentFrameCount) {
        Sleep(0);
        now = timeGetTime();
    }
    return 1;
}
}
