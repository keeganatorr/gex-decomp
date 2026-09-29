extern "C" void *DAT_004875A0;
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);
extern "C" void __cdecl CloseVideoWindow_00404440()
{
    PostMessageA(DAT_004875A0, 0x65b, 0, 0);
}
