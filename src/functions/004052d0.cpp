extern "C" void GameUnpause_004051d0(void);
extern "C" int gFullscreen_0045103c;
extern "C" void FUN_004013e0_ExitFullscreen_Clean1(int);
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*, const char*, const char*, unsigned int);
extern "C" void* gMainWindow_004875a0;
extern "C" const char* AreYouSureYouWantToExitGEX_0048a014;
extern "C" char WindowTitle_GEX[];

extern "C" unsigned int FUN_004052d0_ExitGexPopup(void)
{
    int iVar1;
    GameUnpause_004051d0();
    if (gFullscreen_0045103c == 2) {
        FUN_004013e0_ExitFullscreen_Clean1(1);
    }
    iVar1 = MessageBoxA(gMainWindow_004875a0, AreYouSureYouWantToExitGEX_0048a014, WindowTitle_GEX, 0x31);
    return (unsigned int)(iVar1 == 1);
}
