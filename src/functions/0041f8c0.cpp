extern "C" {
    extern int DAT_004638c4_VoiceInner3;
    extern int DAT_004a2ad8_VoiceSetIndex;
    extern int DAT_004639dc_VoiceToLoad;
    extern void assertfail_00405350(char *, int);
    extern void VSIT_MarkForPlay_0041f860(unsigned int, int);
    extern char s_ERROR__vsit___ld_out_of_range____0045a10c[];
    extern char s_Error__Object_Typ__ld_with_colli_0045a130[];
}

extern "C" void VSIT_PlayVoiceSituation_0041f8c0(int VoiceToLoad)
{
    int voiceSetIndex;
    unsigned short *voiceEffectPtr;
    unsigned short voiceEffectId;

    if ((DAT_004638c4_VoiceInner3 == 0) || (DAT_004639dc_VoiceToLoad == VoiceToLoad)) {
        voiceSetIndex = DAT_004a2ad8_VoiceSetIndex;
        if (voiceSetIndex == 0) {
            voiceSetIndex = VoiceToLoad;
        }
        if ((voiceSetIndex <= 0) || (voiceSetIndex >= 0x77)) {
            assertfail_00405350(s_ERROR__vsit___ld_out_of_range____0045a10c, voiceSetIndex);
        } else {
            voiceEffectPtr = ((unsigned short **)0x459f30)[voiceSetIndex];
            if ((voiceEffectPtr != 0) && (*voiceEffectPtr != 0)) {
                do {
                    voiceEffectId = *voiceEffectPtr;
                    if ((voiceEffectId < 0x30) || (voiceEffectId >= 0x204)) {
                        assertfail_00405350(s_Error__Object_Typ__ld_with_colli_0045a130, (unsigned int)voiceEffectId);
                    } else {
                        VSIT_MarkForPlay_0041f860((unsigned int)voiceEffectId, VoiceToLoad);
                    }
                    voiceEffectPtr++;
                } while (*voiceEffectPtr != 0);
            }
        }
    }
}
