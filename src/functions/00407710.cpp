typedef struct NMHDR {
    void *hwndFrom;
    unsigned int idFrom;
    int code;
} NMHDR;

extern "C" {
__declspec(dllimport) int __stdcall WinHelpA(void *, const char *, unsigned int, unsigned long);
__declspec(dllimport) long __stdcall SetWindowLongA(void *, int, long);
__declspec(dllimport) long __stdcall GetWindowLongA(void *, int);
__declspec(dllimport) int __stdcall DeleteObject(void *);
__declspec(dllimport) unsigned int __stdcall IsDlgButtonChecked(void *, int);
__declspec(dllimport) int __stdcall CheckDlgButton(void *, int, unsigned int);
__declspec(dllimport) void *__stdcall GetParent(void *);
__declspec(dllimport) void *__stdcall GetDlgItem(void *, int);
__declspec(dllimport) long __stdcall SendMessageA(void *, unsigned int, unsigned int, long);
__declspec(dllimport) int __stdcall EnableWindow(void *, int);
__declspec(dllimport) int __stdcall GetDlgCtrlID(void *);
extern void *gMainWindow_004875a0;
extern char DAT_00487DE0[];
extern void *DAT_00487fc4;
extern void *DAT_00487fcc;
extern long DAT_00487fc8;
extern long DAT_004626d0;
extern char dwNewLong_00405850[];
extern char dwNewLong_00408a30[];
extern void *ghInstance_00487f90;
extern int gEnableSFX_00455000;
extern int gEnableVFX_00455004;
extern int gEnableMUS_00455008;
extern int gVolumeForEffects_0045500c;
extern int gVolumeForVoice_00455010;
extern int gVolumeForMusic_00455014;
extern int DAT_0047f040_OptionsEffects;
extern int DAT_0047f0a4_OptionsVoice;
extern int DAT_0047f048_OptionsMusic;
extern int DAT_0047f0ac_lParam_VolumeEffects;
extern int DAT_0047f044_VolumeVoice;
extern int DAT_0047f04c_VolumeMusic;
extern void *gDirectSound_0049a070;
void *__cdecl FUN_00405660_GFXUnk(void *, int, void **);
void __cdecl SetSoundEffectVolume_00401e20(int, int);
void __cdecl SetVoiceVolume_00401e70(int, int);
void __cdecl SetMusicVolume_00401ed0(int, int);

int __stdcall GEX_Target(void *hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    int v;
    switch (msg) {
    case 0x4e:
        switch (((NMHDR *)lParam)->code) {
        case -205:
            WinHelpA(gMainWindow_004875a0, DAT_00487DE0, 1, 0x66);
            break;
        case -203:
            DAT_0047f040_OptionsEffects = gEnableSFX_00455000;
            DAT_0047f0a4_OptionsVoice = gEnableVFX_00455004;
            DAT_0047f048_OptionsMusic = gEnableMUS_00455008;
            DAT_0047f0ac_lParam_VolumeEffects = gVolumeForEffects_0045500c;
            DAT_0047f044_VolumeVoice = gVolumeForVoice_00455010;
            DAT_0047f04c_VolumeMusic = gVolumeForMusic_00455014;
            SetWindowLongA(hwnd, 0, 1);
            return 0;
        case -201:
            if (DAT_00487fc4) {
                DeleteObject(DAT_00487fc4);
                DAT_00487fc4 = 0;
            }
            if (DAT_00487fcc) {
                DeleteObject(DAT_00487fcc);
                DAT_00487fcc = 0;
            }
            SetWindowLongA(hwnd, 0, ((NMHDR *)lParam)->code == -202);
            return ((NMHDR *)lParam)->code != -202;
        case -200:
            DAT_00487fc4 = FUN_00405660_GFXUnk(ghInstance_00487f90, 0x78, &DAT_00487fcc);
            SetWindowLongA(GetParent(hwnd), -0x14, GetWindowLongA(GetParent(hwnd), -0x14) & ~0x400);
            SendMessageA(GetDlgItem(hwnd, 0x3fb), 0x406, 1, 0x640000);
            SendMessageA(GetDlgItem(hwnd, 0x3fb), 0x405, 1, 100 - DAT_0047f0ac_lParam_VolumeEffects);
            SendMessageA(GetDlgItem(hwnd, 0x3fc), 0x406, 1, 0x640000);
            SendMessageA(GetDlgItem(hwnd, 0x3fc), 0x405, 1, 100 - DAT_0047f044_VolumeVoice);
            SendMessageA(GetDlgItem(hwnd, 0x3fa), 0x406, 1, 0x640000);
            SendMessageA(GetDlgItem(hwnd, 0x3fa), 0x405, 1, 100 - DAT_0047f04c_VolumeMusic);
            CheckDlgButton(hwnd, 0x3fd, DAT_0047f040_OptionsEffects);
            CheckDlgButton(hwnd, 0x3fe, DAT_0047f0a4_OptionsVoice);
            CheckDlgButton(hwnd, 0x3ff, DAT_0047f048_OptionsMusic);
            if (!gDirectSound_0049a070) {
                EnableWindow(GetDlgItem(hwnd, 0x3fb), 0);
                EnableWindow(GetDlgItem(hwnd, 0x3fc), 0);
                EnableWindow(GetDlgItem(hwnd, 0x3fa), 0);
                EnableWindow(GetDlgItem(hwnd, 0x3fd), 0);
                EnableWindow(GetDlgItem(hwnd, 0x3fe), 0);
                EnableWindow(GetDlgItem(hwnd, 0x3ff), 0);
                EnableWindow(GetDlgItem(hwnd, 0x403), 0);
                return 0;
            }
            break;
        }
        break;
    case 0x53:
        WinHelpA(gMainWindow_004875a0, DAT_00487DE0, 1, 0x66);
        return 0;
    case 0x110:
        DAT_00487fc8 = SetWindowLongA(GetDlgItem(hwnd, 0x416), -4, (long)dwNewLong_00405850);
        DAT_004626d0 = SetWindowLongA(GetDlgItem(hwnd, 0x419), -4, (long)dwNewLong_00408a30);
        DAT_004626d0 = SetWindowLongA(GetDlgItem(hwnd, 0x41a), -4, (long)dwNewLong_00408a30);
        DAT_004626d0 = SetWindowLongA(GetDlgItem(hwnd, 0x41b), -4, (long)dwNewLong_00408a30);
        return 1;
    case 0x111:
        if ((unsigned short)(wParam >> 16))
            break;
        switch ((unsigned short)wParam) {
        case 0x3fd:
            DAT_0047f040_OptionsEffects = IsDlgButtonChecked(hwnd, 0x3fd);
            if (DAT_0047f040_OptionsEffects) {
                SetSoundEffectVolume_00401e20(DAT_0047f0ac_lParam_VolumeEffects, 1);
                return 0;
            }
            SetSoundEffectVolume_00401e20(0, 1);
            return 0;
        case 0x3fe:
            DAT_0047f0a4_OptionsVoice = IsDlgButtonChecked(hwnd, 0x3fe);
            if (DAT_0047f0a4_OptionsVoice) {
                SetVoiceVolume_00401e70(DAT_0047f044_VolumeVoice, 1);
                return 0;
            }
            SetVoiceVolume_00401e70(0, 1);
            return 0;
        case 0x3ff:
            DAT_0047f048_OptionsMusic = IsDlgButtonChecked(hwnd, 0x3ff);
            if (DAT_0047f048_OptionsMusic) {
                SetMusicVolume_00401ed0(DAT_0047f04c_VolumeMusic, 1);
                return 0;
            }
            SetMusicVolume_00401ed0(0, 1);
            return 0;
        case 0x403:
            DAT_0047f040_OptionsEffects = 1;
            DAT_0047f0a4_OptionsVoice = 1;
            DAT_0047f048_OptionsMusic = 1;
            DAT_0047f0ac_lParam_VolumeEffects = 0x64;
            DAT_0047f044_VolumeVoice = 0x64;
            DAT_0047f04c_VolumeMusic = 0x50;
            CheckDlgButton(hwnd, 0x3fd, 1);
            CheckDlgButton(hwnd, 0x3fe, 1);
            CheckDlgButton(hwnd, 0x3ff, 1);
            SendMessageA(GetDlgItem(hwnd, 0x3fb), 0x405, 1, 0);
            SendMessageA(GetDlgItem(hwnd, 0x3fc), 0x405, 1, 0);
            SendMessageA(GetDlgItem(hwnd, 0x3fa), 0x405, 1, 0x14);
            SetSoundEffectVolume_00401e20(0x64, 0);
            SetVoiceVolume_00401e70(0x64, 0);
            SetMusicVolume_00401ed0(0x50, 0);
            break;
        }
        return 0;
    case 0x115:
        v = 100 - SendMessageA((void *)lParam, 0x400, 0, 0);
        switch (GetDlgCtrlID((void *)lParam)) {
        case 0x3fa:
            DAT_0047f04c_VolumeMusic = v;
            if (DAT_0047f048_OptionsMusic) {
                SetMusicVolume_00401ed0(v, 1);
                return 0;
            }
            break;
        case 0x3fb:
            DAT_0047f0ac_lParam_VolumeEffects = v;
            if (DAT_0047f040_OptionsEffects) {
                SetSoundEffectVolume_00401e20(v, 1);
                return 0;
            }
            break;
        case 0x3fc:
            DAT_0047f044_VolumeVoice = v;
            if (DAT_0047f0a4_OptionsVoice)
                SetVoiceVolume_00401e70(v, 1);
            break;
        default:
            return 0;
        }
        return 0;
    }
    return 0;
}
}
