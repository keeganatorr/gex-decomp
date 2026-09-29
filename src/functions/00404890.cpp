extern "C" {
    typedef unsigned int MCIERROR;
    typedef unsigned int MCIDEVICEID;
    typedef unsigned int DWORD;
    typedef unsigned int DWORD_PTR;

    __declspec(dllimport) MCIERROR __stdcall mciSendCommandA(MCIDEVICEID, unsigned int, DWORD_PTR, DWORD_PTR);
    void __cdecl FUN_004046b0_AVI(MCIERROR);
    void __cdecl FUN_00404710_Window(void);

    extern unsigned int gVideoWindow_00451794;
    extern unsigned int gMCIDevice_004626a8;
    extern unsigned int DAT_004626ac;
}

extern "C" void FUN_00404890_AVIWindow(void)
{
    MCIERROR MVar1;
    unsigned char local_4[4];
    if (gVideoWindow_00451794 != 0) {
        MVar1 = mciSendCommandA(gMCIDevice_004626a8, 0x809, 2, (DWORD_PTR)local_4);
        if (MVar1 != 0) {
            FUN_004046b0_AVI(MVar1);
            FUN_00404710_Window();
            return;
        }
        DAT_004626ac = 1;
    }
}
