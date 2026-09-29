extern "C" {
__declspec(dllimport) long __stdcall CallWindowProcA(long prev, void *hwnd, unsigned int msg, unsigned int wParam, long lParam);
extern long DAT_004626c8;
long __stdcall GEX_Target(void *hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    if (msg == 0x100 || msg == 0x102 || msg == 0x104)
        return 0;
    return CallWindowProcA(DAT_004626c8, hwnd, msg, wParam, lParam);
}
}
