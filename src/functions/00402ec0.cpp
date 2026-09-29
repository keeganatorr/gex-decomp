extern "C" {
    extern int gMusicQueuedTrack_004626a0;
    extern int gMusicAndOffsetTable_00451530[];
    extern int gMusicAndOffsetTable_1__00451534[];
    extern int gMusicOffset_0049a050;
    extern int gMusicToPlay_0048a034;
    extern char s_Unknown_Sound_Num_Used__d_00451710[];
    extern void exit(int);
    __declspec(dllimport) void __stdcall OutputDebugStringA(const char*);
}

extern "C" void MUS_SetMusicPlaying_00402ec0(int param_1)
{
    int *piVar1 = gMusicAndOffsetTable_00451530;
    int musicFile = 0;
    while (1) {
        if (gMusicQueuedTrack_004626a0 == *piVar1) {
            gMusicOffset_0049a050 = gMusicAndOffsetTable_1__00451534[musicFile * 2];
            if (param_1 == 0) {
                gMusicOffset_0049a050 = -1;
            }
            gMusicToPlay_0048a034 = gMusicQueuedTrack_004626a0;
            return;
        }
        if (*piVar1 == 0) {
            OutputDebugStringA(s_Unknown_Sound_Num_Used__d_00451710);
            exit(0);
        }
        piVar1 += 2;
        musicFile++;
    }
}
