extern "C" {
extern long M1_004a2a84;
extern volatile unsigned long M1_004a2a80;
extern unsigned char M1_IsLevelDone_004a2a8c;
extern long sl_004a026c;
extern long DAT_00455c04;
extern volatile unsigned long gMainState_004a2970;
extern long level_004a2964;
extern long gGameState_00455c3c;
extern long gIsPaused_00487f88;

extern char DAT_00455ee0[];
extern char DAT_00455ed0[];
extern char DAT_00455ec0[];

void __cdecl FUN_00441130_VideoTiles(void);
void __cdecl DRAW_Init_0043daf0(void);
void __cdecl GFX_Init_0043ef30(void);
void __cdecl GXINP_InitPads_0041fc20(void);
void __cdecl FUN_00404410_LoadAvi_Clean1(char *, long);
int __cdecl INPUT_GetActiveKeys_00404ba0(long);
void __cdecl CloseVideoWindow_00404440(void);
void __cdecl GEX_Run_0040b000(void);
__declspec(dllimport) void __stdcall Sleep(unsigned long);

int __cdecl GEX_Target(int SkipIntro)
{
    long local_c;
    long local_8;
    long local_4;

    M1_004a2a84 = 1;
    FUN_00441130_VideoTiles();
    DRAW_Init_0043daf0();
    GFX_Init_0043ef30();
    sl_004a026c = 0;
    DAT_00455c04 = 0;
    GXINP_InitPads_0041fc20();

    if (SkipIntro != 0)
        gMainState_004a2970 = 2;

    while (M1_004a2a80 < 2) {
        if (M1_004a2a80 == 1) {
            M1_004a2a80 = 0;
            gMainState_004a2970 = 2;
        }

        switch (gMainState_004a2970) {
        case 0:
            local_c = 0;
            FUN_00404410_LoadAvi_Clean1(DAT_00455ee0, (long)&local_c);
            while (local_c == 0 && M1_004a2a80 == 0) {
                Sleep(0);
                if (INPUT_GetActiveKeys_00404ba0(0) != 0 && gIsPaused_00487f88 != 0)
                    CloseVideoWindow_00404440();
            }
            gMainState_004a2970 = 1;
            break;

        case 1:
            if (M1_IsLevelDone_004a2a8c == 0) {
                local_8 = 0;
                FUN_00404410_LoadAvi_Clean1(DAT_00455ed0, (long)&local_8);
                while (local_8 == 0 && M1_004a2a80 == 0) {
                    Sleep(0);
                    if (INPUT_GetActiveKeys_00404ba0(0) != 0 && gIsPaused_00487f88 != 0)
                        CloseVideoWindow_00404440();
                }
            }
            M1_IsLevelDone_004a2a8c = 0;
            gMainState_004a2970 = 2;
            break;

        case 2:
            level_004a2964 = 63;
            gGameState_00455c3c = 1;
            GEX_Run_0040b000();
            level_004a2964 = 63;
            gGameState_00455c3c = 1;
            break;

        case 3:
            gMainState_004a2970 = 2;
            break;

        case 5:
            local_4 = 0;
            FUN_00404410_LoadAvi_Clean1(DAT_00455ec0, (long)&local_4);
            while (local_4 == 0 && M1_004a2a80 == 0) {
                Sleep(100);
                if (INPUT_GetActiveKeys_00404ba0(0) != 0 && gIsPaused_00487f88 != 0)
                    CloseVideoWindow_00404440();
            }
            gMainState_004a2970 = 6;
            break;

        case 6:
            gGameState_00455c3c = 4;
            GEX_Run_0040b000();
            break;
        }
    }

    M1_004a2a84 = 0;
    return 0;
}
}
