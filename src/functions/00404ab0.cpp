typedef void *HWND;
typedef struct JOYINFOEX {
    unsigned long dwSize, dwFlags, dwXpos, dwYpos, dwZpos, dwRpos, dwUpos, dwVpos;
    unsigned long dwButtons, dwButtonNumber, dwPOV, dwReserved1, dwReserved2;
} JOYINFOEX;

void *__cdecl memset(void *dst, int value, unsigned int count);
__declspec(dllimport) int __cdecl wsprintfA(char *buffer, const char *format, ...);
__declspec(dllimport) unsigned int __stdcall joyGetPosEx(unsigned int id, JOYINFOEX *info);
__declspec(dllimport) int __stdcall PostMessageA(HWND window, unsigned int message, unsigned int wparam, long lparam);
extern int DAT_004517e0_timeSetEventUnk1;
extern int DAT_004517e4_timeSetEventUnk2;
extern int DAT_00487ee4_ShowFPS;
extern int DAT_00487a90_FPS;
extern char DAT_00454f50_FPSBufferFormat[];
extern char lpString_00454fa8[];
extern int DAT_00454fb4_FPSBufferLength;
extern HWND DAT_00488004_HWND_Unk;
extern unsigned int DAT_0047f050_timeSetEventUnk2;
extern int DAT_004626b4_timeSetEventUnk3;
extern void *gVideoWindow_00451794;
int __cdecl FUN_00406fd0_timeSetEventInner(unsigned long bits);
void __cdecl FUN_00404460_timeSetEventInner(void);
void __stdcall FUN_00404ab0_timeSetEvent(unsigned int id, unsigned int message, unsigned long user, unsigned long dw1, unsigned long dw2)
{
    JOYINFOEX info;
    DAT_004517e4_timeSetEventUnk2++;
    DAT_004517e0_timeSetEventUnk1++;
    if (DAT_00487ee4_ShowFPS && DAT_004517e0_timeSetEventUnk1 >= 60) {
        DAT_00454fb4_FPSBufferLength = wsprintfA(lpString_00454fa8, DAT_00454f50_FPSBufferFormat, DAT_00487a90_FPS);
        DAT_00487a90_FPS = 0;
        DAT_004517e0_timeSetEventUnk1 = 0;
    }
    if (DAT_00488004_HWND_Unk && DAT_0047f050_timeSetEventUnk2 != (unsigned int)-1) {
        if (++DAT_004626b4_timeSetEventUnk3 >= 10) {
            DAT_004626b4_timeSetEventUnk3 = 0;
            memset(&info, 0, sizeof(info));
            info.dwSize = sizeof(info);
            info.dwFlags = 0x80;
            joyGetPosEx(DAT_0047f050_timeSetEventUnk2, &info);
            if (info.dwButtons)
                PostMessageA(DAT_00488004_HWND_Unk, 0x590, FUN_00406fd0_timeSetEventInner(info.dwButtons) + 1, 0);
        }
    }
    if (gVideoWindow_00451794)
        FUN_00404460_timeSetEventInner();
}
