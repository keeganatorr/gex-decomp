extern "C" void GameUnpause_004051d0(void);
extern "C" void FUN_004013E0(int);
extern "C" int DAT_0045103C;
extern "C" const char* STRING_SUREYOUWANTTOENDTHECURRENTGAME_00487fe8;
extern "C" const char WindowTitle_GEX[];
extern "C" void* DAT_004875A0;
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption, unsigned int uType);

extern "C" unsigned int GEX_Target(void)
{
    GameUnpause_004051d0();
    if (DAT_0045103C == 2) {
        FUN_004013E0(1);
    }
    return MessageBoxA(DAT_004875A0, STRING_SUREYOUWANTTOENDTHECURRENTGAME_00487fe8, WindowTitle_GEX, 0x31) == 1;
}
