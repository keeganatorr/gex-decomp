
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern unsigned int UINT_ARRAY_004a02d0[];
extern unsigned int DAT_004639dc_VoiceToLoad;
extern unsigned int DAT_004638c4_VoiceInner3;
void __cdecl VSIT_ForceVoiceSituation_0041fb80(unsigned int voice)
{
    DAT_004639dc_VoiceToLoad = voice;
    if (UINT_ARRAY_004a02d0[0] != voice)
        DAT_004638c4_VoiceInner3 = 1;
}
