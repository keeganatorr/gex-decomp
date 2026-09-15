extern "C" void *DAT_004875A0;
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);

extern "C" void GEX_Target(void)
{
    void *window = DAT_004875A0;
    PostMessageA(window, 0x10u, 0u, 0L);
}
