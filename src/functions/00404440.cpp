extern "C" void *DAT_004875A0;
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);
extern "C" void __cdecl GEX_Target()
{
    PostMessageA(DAT_004875A0, 0x65b, 0, 0);
}
