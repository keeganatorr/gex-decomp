typedef struct Remap {
    char saved[16];
    char name[16];
    int defKey;
    int key;
    int id;
    char regName[16];
} Remap;
typedef struct WINDOWPLACEMENT {
    unsigned int length;
    unsigned int flags;
    unsigned int showCmd;
    int ptMin[2];
    int ptMax[2];
    int left, top, right, bottom;
} WINDOWPLACEMENT;

extern "C" {
__declspec(dllimport) unsigned long __stdcall GetVersion(void);
__declspec(dllimport) long __stdcall RegCreateKeyA(void *, const char *, void **);
__declspec(dllimport) long __stdcall RegSetValueExA(void *, const char *, unsigned long, unsigned long, const void *, unsigned long);
__declspec(dllimport) long __stdcall RegFlushKey(void *);
__declspec(dllimport) long __stdcall RegCloseKey(void *);
__declspec(dllimport) int __cdecl wsprintfA(char *, const char *, ...);
__declspec(dllimport) int __stdcall GetWindowPlacement(void *, WINDOWPLACEMENT *);
void *__cdecl memset(void *, int, unsigned int);
extern char s_Software_Microsoft_Games_GEX_00455970[];
extern char s_fmt_dd_00455990[];
extern char s_Version_00455968[];
extern Remap DAT_00455480[12];
extern int DAT_00455018_JoystickEnabled;
extern char s_Joy_ID_00455954[];
extern void *gMainWindow_004875a0;
extern char s_Window_SizeX_00455944[];
extern char s_Window_SizeY_00455934[];
extern char s_Window_TopX_00455928[];
extern char s_Window_TopY_0045591c[];
extern int gVolumeForEffects_0045500c;
extern int gVolumeForVoice_00455010;
extern int gVolumeForMusic_00455014;
extern int gEnableSFX_00455000;
extern int gEnableVFX_00455004;
extern int gEnableMUS_00455008;
extern int lpData_0045501c;
extern char s_Volume_Effects_0045590c[];
extern char s_Volume_Voice_004558fc[];
extern char s_Volume_Music_004558ec[];
extern char s_Option_Effects_004558dc[];
extern char s_Option_Voice_004558cc[];
extern char s_Option_Music_004558bc[];
extern char s_Option_FullScreen_004558a8[];

void __cdecl SettingsSetFromRegistry_00408f40(void)
{
    void *key;
    int sizeX;
    int sizeY;
    int topX;
    int topY;
    WINDOWPLACEMENT wp;
    char buf[0x40];
    int i;
    unsigned long root;
    root = GetVersion() & 0x80000000 ? 0x80000002 : 0x80000001;
    RegCreateKeyA((void *)root, s_Software_Microsoft_Games_GEX_00455970, &key);
    RegSetValueExA(key, s_Version_00455968, 0, 1, buf, wsprintfA(buf, s_fmt_dd_00455990, 1, 0) + 1);
    for (i = 0; i != 8; i++)
        RegSetValueExA(key, DAT_00455480[i].regName, 0, 4, &DAT_00455480[i].key, 4);
    for (i = 8; i != 12; i++)
        RegSetValueExA(key, DAT_00455480[i].regName, 0, 4, &DAT_00455480[i].key, 4);
    RegSetValueExA(key, s_Joy_ID_00455954, 0, 4, &DAT_00455018_JoystickEnabled, 4);
    if (gMainWindow_004875a0) {
        memset(&wp, 0, sizeof wp);
        wp.length = 0x2c;
        GetWindowPlacement(gMainWindow_004875a0, &wp);
        sizeX = wp.right - wp.left;
        sizeY = wp.bottom - wp.top;
        topX = wp.left;
        topY = wp.top;
        RegSetValueExA(key, s_Window_SizeX_00455944, 0, 4, &sizeX, 4);
        RegSetValueExA(key, s_Window_SizeY_00455934, 0, 4, &sizeY, 4);
        RegSetValueExA(key, s_Window_TopX_00455928, 0, 4, &topX, 4);
        RegSetValueExA(key, s_Window_TopY_0045591c, 0, 4, &topY, 4);
    }
    RegSetValueExA(key, s_Volume_Effects_0045590c, 0, 4, &gVolumeForEffects_0045500c, 4);
    RegSetValueExA(key, s_Volume_Voice_004558fc, 0, 4, &gVolumeForVoice_00455010, 4);
    RegSetValueExA(key, s_Volume_Music_004558ec, 0, 4, &gVolumeForMusic_00455014, 4);
    RegSetValueExA(key, s_Option_Effects_004558dc, 0, 4, &gEnableSFX_00455000, 4);
    RegSetValueExA(key, s_Option_Voice_004558cc, 0, 4, &gEnableVFX_00455004, 4);
    RegSetValueExA(key, s_Option_Music_004558bc, 0, 4, &gEnableMUS_00455008, 4);
    RegSetValueExA(key, s_Option_FullScreen_004558a8, 0, 4, &lpData_0045501c, 4);
    RegFlushKey(key);
    RegCloseKey(key);
}
}
