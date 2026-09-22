struct WindowRect {
    int X, Y, Width, Height;
};
struct GenericParams {
    unsigned long callback;
};
struct PutParams {
    unsigned long callback;
    WindowRect rect;
};
struct StatusParams {
    unsigned long callback;
    unsigned long value;
    unsigned long item;
    unsigned long track;
    unsigned long slot4;
    unsigned long slot5;
};

extern "C" {
extern void *gVideoWindow_00451794;
extern unsigned int gMCIDevice_004626a8;
extern int DAT_004626ac;
void __cdecl FUN_00401340_CalculateWindowRect(WindowRect *);
void __cdecl FUN_00404710_Window(void);
void __cdecl FUN_004046b0_AVI(unsigned long);
__declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int, unsigned int, unsigned long, unsigned long);
__declspec(dllimport) void __stdcall Sleep(unsigned long);
__declspec(dllimport) int __stdcall MoveWindow(void *, int, int, int, int, int);

void __cdecl GEX_Target(void)
{
    GenericParams generic;
    PutParams put;
    StatusParams status;
    WindowRect rect;
    unsigned long error;
    int retries;

    if (gVideoWindow_00451794 != 0 && DAT_004626ac != 0) {
        FUN_00401340_CalculateWindowRect(&rect);
        put.callback = 0;
        put.rect.X = rect.X;
        put.rect.Y = rect.Y;
        put.rect.Width = rect.Width;
        put.rect.Height = rect.Height;
        error = mciSendCommandA(gMCIDevice_004626a8, 0x842, 0x210002, (unsigned long)&put);
        retries = 20;
        do {
            if (error != 0)
                goto report_error;
            mciSendCommandA(gMCIDevice_004626a8, 0x855, 0, (unsigned long)&generic);
            status.callback = 0;
            status.value = 0;
            status.track = 0;
            status.slot4 = 0;
            status.item = 4;
            status.slot5 = 0;
            error = mciSendCommandA(gMCIDevice_004626a8, 0x814, 0x102, (unsigned long)&status);
            if (status.value != 0x211)
                goto finished_waiting;
            Sleep(250);
            --retries;
        } while (retries != 0);
        FUN_00404710_Window();
finished_waiting:
        if (error != 0) {
report_error:
            FUN_004046b0_AVI(error);
            FUN_00404710_Window();
        }
        FUN_00401340_CalculateWindowRect(&rect);
        MoveWindow(gVideoWindow_00451794, rect.X, rect.Y, rect.Width, rect.Height, 0);
        DAT_004626ac = 0;
    }
}
}
