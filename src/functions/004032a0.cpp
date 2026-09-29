extern "C" {
__declspec(dllimport) int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);
__declspec(dllimport) unsigned long __stdcall CheckMenuItem(void *, unsigned int, unsigned int);
__declspec(dllimport) unsigned long __stdcall timeGetTime(void);
__declspec(dllimport) int __stdcall WinHelpA(void *, const char *, unsigned int, unsigned long);
__declspec(dllimport) int __stdcall DialogBoxParamA(void *, const char *, void *, int (__stdcall *)(void *, unsigned int, unsigned int, long), long);
int __stdcall AboutDialogProc_00403590(void *, unsigned int, unsigned int, long);
int __stdcall CreditsDialogProc_004036f0(void *, unsigned int, unsigned int, long);
extern int gIsShowingVRAM_00487bc0;
extern int gDebugInfo_004879f4;
extern void *gMenu_00487f78;
extern int gNoVFX_004a2958;
extern int LEVELID_004a2a98;
extern int DAT_00456018_gex_Init_unk;
extern int gDemoShowing_004a2a0c;
extern char M1_IsLevelDone_004a2a8c;
extern void *gVideoWindow_00451794;
extern int DAT_00487a90_FPS;
extern int gMainWindow_004875a0[];
extern int DAT_00487ee4_ShowFPS;
extern int HGDIOBJ_00487a94[];
extern char DAT_00487DE0[];
extern char lpValueName_00451778[];
extern int gIsPaused_00487f88;
extern void *ghInstance_00487f90;
void __cdecl VRAM_Hide_00405810(void);
void __cdecl VRAM_Show_00405700(void);
void __cdecl GamePause_00405240(void);
void __cdecl FUN_00404710_Window(void);
void __cdecl GameUnpause_004051d0(void);
int __cdecl FUN_00405310_Fullscreen_Unk(void);
void __cdecl FUN_00406fe0_InitWindowVars(int);
int __cdecl FUN_00403030_Registry(int);
void __cdecl FUN_00402fb0(void);

int __cdecl FUN_004032a0_WM_COMMAND(void *hwnd, unsigned int msg, unsigned int wParam)
{
    switch (wParam & 0xffff) {
    case 0x9c41:
        PostMessageA(hwnd, 0x10, 0, 0);
        return 0;
    case 0x9c43:
        if (gIsShowingVRAM_00487bc0) {
            VRAM_Hide_00405810();
            return 0;
        }
        VRAM_Show_00405700();
        return 0;
    case 0x9c45:
        gDebugInfo_004879f4 = !gDebugInfo_004879f4;
        if (gDebugInfo_004879f4) {
            CheckMenuItem(gMenu_00487f78, 0x9c45, 8);
            return 0;
        }
        CheckMenuItem(gMenu_00487f78, 0x9c45, 0);
        return 0;
    case 0x9c46:
        if (!gNoVFX_004a2958 && LEVELID_004a2a98 != 0x3f && !DAT_00456018_gex_Init_unk) {
            if (gDemoShowing_004a2a0c) {
                M1_IsLevelDone_004a2a8c = 1;
                GamePause_00405240();
                return 0;
            }
            if (gVideoWindow_00451794) {
                M1_IsLevelDone_004a2a8c = 1;
                GamePause_00405240();
                FUN_00404710_Window();
                return 0;
            }
            GameUnpause_004051d0();
            if (FUN_00405310_Fullscreen_Unk()) {
                M1_IsLevelDone_004a2a8c = 1;
                GamePause_00405240();
                return 0;
            }
        }
        break;
    case 0x9c47:
        DAT_00487a90_FPS = 0;
        gMainWindow_004875a0[1] = timeGetTime();
        DAT_00487ee4_ShowFPS = !DAT_00487ee4_ShowFPS;
        if (DAT_00487ee4_ShowFPS) {
            CheckMenuItem(gMenu_00487f78, 0x9c47, 8);
            return 0;
        }
        CheckMenuItem(gMenu_00487f78, 0x9c47, 0);
        return 0;
    case 0x9c4b:
        HGDIOBJ_00487a94[1] = 2;
        return 0;
    case 0x9c4c:
        FUN_00406fe0_InitWindowVars(0);
        return 0;
    case 0x9c4d:
        WinHelpA((void *)gMainWindow_004875a0[0], DAT_00487DE0, 3, 0x64);
        return 0;
    case 0x9c4e:
        WinHelpA((void *)gMainWindow_004875a0[0], DAT_00487DE0, 0x105, (unsigned long)lpValueName_00451778);
        return 0;
    case 0x9c4f:
        WinHelpA((void *)gMainWindow_004875a0[0], 0, 4, 0);
        return 0;
    case 0x9c50:
        FUN_00406fe0_InitWindowVars(1);
        return 0;
    case 0x9c51:
        FUN_00406fe0_InitWindowVars(2);
        return 0;
    case 0x9c52:
        FUN_00406fe0_InitWindowVars(3);
        return 0;
    case 0x9c53:
        if (gIsPaused_00487f88) {
            GameUnpause_004051d0();
            return 0;
        }
        GamePause_00405240();
        return 0;
    case 0x9c54:
        FUN_00403030_Registry(0);
        return 0;
    case 0x9c55:
        FUN_00402fb0();
        return 0;
    case 0x9c59:
        if (DialogBoxParamA(ghInstance_00487f90, (const char *)0x6d, (void *)gMainWindow_004875a0[0], AboutDialogProc_00403590, 0))
            DialogBoxParamA(ghInstance_00487f90, (const char *)0x7e, (void *)gMainWindow_004875a0[0], CreditsDialogProc_004036f0, 0);
        break;
    }
    return 0;
}
}
