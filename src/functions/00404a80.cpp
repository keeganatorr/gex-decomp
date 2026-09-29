extern "C" {
    extern int DAT_00454FC8;
    extern int DAT_004626A8;
    __declspec(dllimport) unsigned int __stdcall mciSendCommandA(unsigned int, unsigned int, unsigned int, unsigned int);
}

extern "C" void FUN_00404a80_StopMCIMedia()
{
    if (DAT_00454FC8 > 8) return;
    int result;
    mciSendCommandA(DAT_004626A8, 0x840, 0x10000, (unsigned int)&result);
}
