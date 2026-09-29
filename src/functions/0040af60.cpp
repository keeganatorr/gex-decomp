extern "C" {
extern volatile int M1_004a2a80;
extern int gGameState_00455c3c;
extern int level_004a2964;
void __cdecl DoLevelSelectScreen_00420300(void);
void __cdecl FUN_0040ab60_MainGame_Clean1(void);
void __cdecl FUN_0040abd0_TransitionMenu_and_Setup_Load_Next_Level(void);
void __cdecl M1_GameLoop_0040ad40(void);
void __cdecl FUN_004099b0_CloseMusic(int stop);
void __cdecl GEX_RunGameLoop_0040af60(void)
{
    int quit;
    int level;
    quit = 0;
    while (!M1_004a2a80) {
        switch (gGameState_00455c3c) {
        case 0:
            DoLevelSelectScreen_00420300();
            break;
        case 1:
            FUN_0040ab60_MainGame_Clean1();
            break;
        case 2:
            FUN_0040abd0_TransitionMenu_and_Setup_Load_Next_Level();
            break;
        case 4:
            M1_GameLoop_0040ad40();
            break;
        case 5:
            level = level_004a2964;
            level_004a2964 = 0x44;
            FUN_0040ab60_MainGame_Clean1();
            level_004a2964 = level;
        case 3:
            gGameState_00455c3c = 1;
            break;
        default:
            quit = 1;
            break;
        }
        if (quit)
            break;
    }
    FUN_004099b0_CloseMusic(1);
}
}
