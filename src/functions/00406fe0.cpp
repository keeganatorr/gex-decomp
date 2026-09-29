typedef struct PROPSHEETPAGE {
    unsigned long dwSize;
    unsigned long dwFlags;
    void *hInstance;
    const char *pszTemplate;
    const char *pszIcon;
    const char *pszTitle;
    void *pfnDlgProc;
    long lParam;
    void *pfnCallback;
    unsigned int *pcRefParent;
} PROPSHEETPAGE;
typedef struct PROPSHEETHEADER {
    unsigned long dwSize;
    unsigned long dwFlags;
    void *hwndParent;
    void *hInstance;
    const char *pszIcon;
    const char *pszCaption;
    unsigned int nPages;
    unsigned int nStartPage;
    PROPSHEETPAGE *ppsp;
    void *pfnCallback;
} PROPSHEETHEADER;
typedef struct JOYCAPS {
    unsigned short wMid;
    unsigned short wPid;
    char szPname[32];
    unsigned int wXmin;
    unsigned int wXmax;
    unsigned int wYmin;
    unsigned int wYmax;
    char rest[0x160];
} JOYCAPS;

extern "C" {
__declspec(dllimport) int __stdcall PropertySheetA(PROPSHEETHEADER *);
__declspec(dllimport) unsigned int __stdcall joyGetDevCapsA(unsigned int, JOYCAPS *, unsigned int);
extern int DAT_0047f0a8;
extern int gIDLDirectory_0047f030[];
extern int gSelectedWindowSizeType_0047f0c0;
extern int DAT_0047f03c;
extern int gEnableSFX_00455000;
extern int gEnableVFX_00455004;
extern int gEnableMUS_00455008;
extern int gVolumeForEffects_0045500c;
extern int gVolumeForVoice_00455010;
extern int gVolumeForMusic_00455014;
extern int DAT_00455018_JoystickEnabled;
extern int DAT_0047f040_OptionsEffects;
extern int DAT_0047f0a4_OptionsVoice;
extern int DAT_0047f048_OptionsMusic;
extern int DAT_0047f0ac_lParam_VolumeEffects;
extern int DAT_0047f044_VolumeVoice;
extern int DAT_0047f04c_VolumeMusic;
extern int DAT_0047f050_timeSetEventUnk2;
extern void *ghInstance_00487f90;
extern void *gMainWindow_004875a0;
extern char DAT_004875d0_Display_UIString[];
extern char DAT_004875b0_Sound_UIString[];
extern char DAT_00487610_Controller_UIString[];
extern char DAT_004875f0_Keyboard_UIString[];
extern char DAT_00487730_GexOptions_UIString[];
extern int gHasJoystick_00454fc4;
extern unsigned int JOYSTICK_xRange1_00487bc4;
extern unsigned int JOYSTICK_yRange1_00487bc8;
extern unsigned int JOYSTICK_xRange2_00487c58;
extern unsigned int JOYSTICK_yRange2_00487c54;
extern int gIsPaused_00487f88;
int __stdcall WindowSizeDialogProc_00407330(void *, unsigned int, unsigned int, long);
int __stdcall MusicDialogProc_00407710(void *, unsigned int, unsigned int, long);
int __stdcall InputDialogProc_00407f80(void *, unsigned int, unsigned int, long);
int __stdcall FUN_004083a0(void *, unsigned int, unsigned int, long);
void __cdecl FUN_004054c0_SetWindowSize(int, int);
void __cdecl FUN_004013e0_ExitFullscreen_Clean1(int);
void __cdecl SetSoundEffectVolume_00401e20(int, int);
void __cdecl SetVoiceVolume_00401e70(int, int);
void __cdecl SetMusicVolume_00401ed0(int, int);

int __cdecl GEX_Target(int startPage)
{
    PROPSHEETHEADER psh;
    PROPSHEETPAGE psp[4];
    JOYCAPS caps;
    int result;
    DAT_0047f0a8 = 0;
    DAT_0047f03c = 0;
    gSelectedWindowSizeType_0047f0c0 = 0;
    DAT_0047f040_OptionsEffects = gEnableSFX_00455000;
    DAT_0047f0a4_OptionsVoice = gEnableVFX_00455004;
    DAT_0047f048_OptionsMusic = gEnableMUS_00455008;
    DAT_0047f0ac_lParam_VolumeEffects = gVolumeForEffects_0045500c;
    DAT_0047f044_VolumeVoice = gVolumeForVoice_00455010;
    DAT_0047f04c_VolumeMusic = gVolumeForMusic_00455014;
    DAT_0047f050_timeSetEventUnk2 = DAT_00455018_JoystickEnabled;
    psp[0].dwSize = 0x28;
    psp[0].dwFlags = 0x28;
    psp[0].hInstance = ghInstance_00487f90;
    psp[0].pszTemplate = (const char *)0x6f;
    psp[0].pszIcon = 0;
    psp[0].pfnDlgProc = WindowSizeDialogProc_00407330;
    psp[0].pszTitle = DAT_004875d0_Display_UIString;
    psp[0].lParam = 0;
    psp[1].dwSize = 0x28;
    psp[1].dwFlags = 0x28;
    psp[1].hInstance = ghInstance_00487f90;
    psp[1].pszTemplate = (const char *)0x6e;
    psp[1].pszIcon = 0;
    psp[1].pfnDlgProc = MusicDialogProc_00407710;
    psp[1].pszTitle = DAT_004875b0_Sound_UIString;
    psp[1].lParam = 0;
    psp[2].dwSize = 0x28;
    psp[2].dwFlags = 0x28;
    psp[2].hInstance = ghInstance_00487f90;
    psp[2].pszTemplate = (const char *)0x71;
    psp[2].pszIcon = 0;
    psp[2].pfnDlgProc = FUN_004083a0;
    psp[2].pszTitle = DAT_00487610_Controller_UIString;
    psp[2].lParam = 0;
    psp[3].dwSize = 0x28;
    psp[3].dwFlags = 0x28;
    psp[3].hInstance = ghInstance_00487f90;
    psp[3].pszTemplate = (const char *)0x70;
    psp[3].pszIcon = 0;
    psp[3].pfnDlgProc = InputDialogProc_00407f80;
    psp[3].pszTitle = DAT_004875f0_Keyboard_UIString;
    psp[3].lParam = 0;
    psh.dwSize = 0x28;
    psh.dwFlags = 0x288;
    psh.hwndParent = gMainWindow_004875a0;
    psh.hInstance = ghInstance_00487f90;
    psh.pszIcon = 0;
    psh.ppsp = psp;
    psh.pszCaption = DAT_00487730_GexOptions_UIString;
    psh.nPages = 4;
    psh.nStartPage = startPage;
    result = PropertySheetA(&psh);
    if (gSelectedWindowSizeType_0047f0c0 == 1 && DAT_0047f03c != 1)
        FUN_004054c0_SetWindowSize(0x140, 0xe0);
    if (gSelectedWindowSizeType_0047f0c0 == 2 && DAT_0047f03c != 2)
        FUN_004054c0_SetWindowSize(0x280, 0x1c0);
    if (gSelectedWindowSizeType_0047f0c0 == 3 && DAT_0047f03c != 3)
    {
        if (gIsPaused_00487f88)
            FUN_004013e0_ExitFullscreen_Clean1(2);
        else
            FUN_004013e0_ExitFullscreen_Clean1(1);
    }
    gEnableSFX_00455000 = DAT_0047f040_OptionsEffects;
    gEnableVFX_00455004 = DAT_0047f0a4_OptionsVoice;
    gEnableMUS_00455008 = DAT_0047f048_OptionsMusic;
    gVolumeForEffects_0045500c = DAT_0047f0ac_lParam_VolumeEffects;
    gVolumeForVoice_00455010 = DAT_0047f044_VolumeVoice;
    gVolumeForMusic_00455014 = DAT_0047f04c_VolumeMusic;
    DAT_00455018_JoystickEnabled = DAT_0047f050_timeSetEventUnk2;
    if (gHasJoystick_00454fc4) {
        joyGetDevCapsA(DAT_00455018_JoystickEnabled, &caps, 0x194);
        JOYSTICK_xRange1_00487bc4 = (caps.wXmax - caps.wXmin) / 2;
        JOYSTICK_yRange1_00487bc8 = (caps.wYmax - caps.wYmin) / 2;
        JOYSTICK_xRange2_00487c58 = (caps.wXmax - caps.wXmin) / 5;
        JOYSTICK_yRange2_00487c54 = (caps.wYmax - caps.wXmin) / 5;
    }
    if (gEnableSFX_00455000)
        SetSoundEffectVolume_00401e20(gVolumeForEffects_0045500c, 0);
    else
        SetSoundEffectVolume_00401e20(0, 0);
    if (gEnableVFX_00455004)
        SetVoiceVolume_00401e70(gVolumeForVoice_00455010, 0);
    else
        SetVoiceVolume_00401e70(0, 0);
    if (gEnableMUS_00455008)
        SetMusicVolume_00401ed0(gVolumeForMusic_00455014, 0);
    else
        SetMusicVolume_00401ed0(0, 0);
    return result;
}
}
