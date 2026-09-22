struct IDirectSound;
struct IDirectSoundVtbl
{
    void *p0;
    void *p1;
    void *p2;
    void *p3;
    void *p4;
    void *p5;
    long (__stdcall *SetCooperativeLevel)(IDirectSound *, void *, unsigned long);
};
struct IDirectSound
{
    IDirectSoundVtbl *lpVtbl;
};

extern "C" int PTR_ARRAY_0049fb30[8];
extern "C" IDirectSound *gDirectSound_0049a070;
extern "C" int DAT_0049fb18_DirectSound2;
extern "C" void *gEnableSFX_00455000;
extern "C" unsigned char *gVolumeForEffects_0045500c;
extern "C" void SetSoundEffectVolume_00401e20(int, int);
extern "C" void *gEnableVFX_00455004;
extern "C" unsigned char *gVolumeForVoice_00455010;
extern "C" void SetVoiceVolume_00401e70(int, int);
extern "C" void *gEnableMUS_00455008;
extern "C" unsigned char *gVolumeForMusic_00455014;
extern "C" void SetMusicVolume_00401ed0(int, int);
extern "C" __declspec(dllimport) int __stdcall sndPlaySoundA(const char *, unsigned int);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);
extern "C" int __stdcall DirectSoundCreate_00409870(void *, IDirectSound **, void *);
extern "C" void *gMainWindow_004875a0;
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char *);
extern "C" const char s_Could_not_create_Direct_Sound_Ob_00451504[];

extern "C" void GEX_Target(void)
{
    int iVar1;
    int *puVar2;

    gDirectSound_0049a070 = 0;
    DAT_0049fb18_DirectSound2 = 0;
    puVar2 = PTR_ARRAY_0049fb30;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 - 1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }

    if (gEnableSFX_00455000 != 0)
        SetSoundEffectVolume_00401e20((int)gVolumeForEffects_0045500c, 0);
    else
        SetSoundEffectVolume_00401e20(0, 0);

    if (gEnableVFX_00455004 != 0)
        SetVoiceVolume_00401e70((int)gVolumeForVoice_00455010, 0);
    else
        SetVoiceVolume_00401e70(0, 0);

    if (gEnableMUS_00455008 != 0)
        SetMusicVolume_00401ed0((int)gVolumeForMusic_00455014, 0);
    else
        SetMusicVolume_00401ed0(0, 0);

    sndPlaySoundA(0, 0);
    Sleep(500);

    iVar1 = DirectSoundCreate_00409870(0, &gDirectSound_0049a070, 0);
    if (iVar1 == 0) {
        gDirectSound_0049a070->lpVtbl->SetCooperativeLevel(gDirectSound_0049a070, gMainWindow_004875a0, 1);
        return;
    }

    gDirectSound_0049a070 = 0;
    OutputDebugStringA(s_Could_not_create_Direct_Sound_Ob_00451504);
}
