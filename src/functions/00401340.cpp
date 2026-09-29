typedef struct WindowRect { int X; int Y; int Width; int Height; } WindowRect;
extern "C" {
void *__cdecl memset(void *dst, int value, unsigned int count);
__declspec(dllimport) int __stdcall GetSystemMetrics(int index);
extern int gFullscreen_0045103c;
extern int gScreenResolution_00451038;
extern int lpData_00487a04;
extern int lpData_00487a08;
void __cdecl FUN_00401340_CalculateWindowRect(WindowRect *rect)
{
    int caption;
    memset(rect, 0, sizeof(*rect));
    switch (gFullscreen_0045103c) {
    case 1:
        caption = (GetSystemMetrics(15) + 1) & ~1;
        if (gScreenResolution_00451038 == 0x320240) {
            rect->Width = 320;
            rect->Height = 240 - caption;
        } else {
            rect->Width = 640;
            rect->Height = 480 - caption;
        }
        break;
    case 2:
        if (gScreenResolution_00451038 == 0x320240) {
            rect->Height = 240;
            rect->Width = 320;
        } else {
            rect->Height = 480;
            rect->Width = 640;
        }
        break;
    default:
        rect->Width = lpData_00487a04;
        rect->Height = lpData_00487a08;
        break;
    }
}
}
