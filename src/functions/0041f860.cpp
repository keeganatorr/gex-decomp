extern "C" {
extern int gNumPlayingVoices_004638d0;
extern int gPlayingVFX_004638d4[];
extern int gPlayingVSIT_00463954[];
extern int DAT_004638b4_LoadedVoiceCounter;

void __cdecl VSIT_MarkForPlay_0041f860(int voiceEffectId, int voiceSetId)
{
    gPlayingVFX_004638d4[gNumPlayingVoices_004638d0 + 1] = voiceEffectId;
    gPlayingVSIT_00463954[gNumPlayingVoices_004638d0 + 1] = voiceSetId;
    gNumPlayingVoices_004638d0++;
    if (gNumPlayingVoices_004638d0 >= 0x20)
        gNumPlayingVoices_004638d0 = 0;
    if (DAT_004638b4_LoadedVoiceCounter < 0x20)
        DAT_004638b4_LoadedVoiceCounter++;
}
}
