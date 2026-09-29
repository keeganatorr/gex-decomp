extern "C" {
extern void *gVideoWindow_00451794;
extern int DAT_004626ac;
extern int DAT_004626b0;
extern void *gMainWindow_004875a0;
__declspec(dllimport) int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);
void __cdecl FUN_00404460_timeSetEventInner(void)
{
    if (gVideoWindow_00451794 && DAT_004626b0 && !DAT_004626ac) {
        DAT_004626b0 -= 0x11;
        if (DAT_004626b0 <= 0) {
            DAT_004626b0 = 0;
            PostMessageA(gMainWindow_004875a0, 0x65b, 0, 0);
        }
    }
}
}
