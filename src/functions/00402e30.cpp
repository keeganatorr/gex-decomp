extern "C" volatile int DAT_0048a03c_MusicUnk1;
extern "C" volatile int DAT_0049a064_MusicUnk2;
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);

extern "C" void GEX_Target(void) {
    DAT_0048a03c_MusicUnk1 = 1;
    while (DAT_0049a064_MusicUnk2 != 0) {
        Sleep(0);
    }
}
