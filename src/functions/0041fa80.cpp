extern "C" {
extern int UINT_ARRAY_004a02d0[2];
int __cdecl VFX_VoiceFinished_0041fb50(void);
void __cdecl VFX_QueueToLoad_00401ad0(int slot);
void __cdecl FUN_0041f8b0_Stub(int voice);
extern int DAT_004638b8_VoiceInner6;
extern int DAT_004638bc_VoiceInnerCounter;
extern int gIsVFXPlaying_004639d8;
int __cdecl GEX_Target(int voice)
{
    int slot;
    if (VFX_VoiceFinished_0041fb50() && (UINT_ARRAY_004a02d0[0] == voice || UINT_ARRAY_004a02d0[1] == voice)) {
        slot = UINT_ARRAY_004a02d0[1] == voice;
        VFX_QueueToLoad_00401ad0(slot);
        UINT_ARRAY_004a02d0[slot] = 0;
        DAT_004638b8_VoiceInner6 = slot;
        gIsVFXPlaying_004639d8 = 0x5a;
        DAT_004638bc_VoiceInnerCounter = 0;
        FUN_0041f8b0_Stub(voice);
        return 1;
    }
    return 0;
}
}
