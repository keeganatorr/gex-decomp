extern "C" {
extern int DAT_004638c0_VoiceInner1;
extern int gIsVFXPlaying_004639d8;
extern int DAT_004638c4_VoiceInner3;
extern int DAT_004638bc_VoiceInnerCounter;
extern int DAT_004639dc_VoiceToLoad;
void __cdecl FUN_0041fa10_ProcessVoiceLoadingCompletion_Clean1(void);
int __cdecl VFX_VoiceFinished_0041fb50(void);
void __cdecl VFX_Reset_0041f840(void);
void __cdecl VSIT_PlayVoiceSituation_0041f8c0(int situation);
void __cdecl FUN_0041f950(void);
void __cdecl GEX_Target(void)
{
    FUN_0041fa10_ProcessVoiceLoadingCompletion_Clean1();
    VFX_VoiceFinished_0041fb50();
    if (DAT_004638c0_VoiceInner1 || gIsVFXPlaying_004639d8)
        return;
    if (DAT_004638c4_VoiceInner3) {
        VFX_Reset_0041f840();
        VSIT_PlayVoiceSituation_0041f8c0(DAT_004639dc_VoiceToLoad);
        FUN_0041f950();
    } else if (DAT_004638bc_VoiceInnerCounter <= 0)
        FUN_0041f950();
    else if (!DAT_004639dc_VoiceToLoad)
        DAT_004638bc_VoiceInnerCounter--;
}
}
