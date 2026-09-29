extern "C" {
extern volatile unsigned int DAT_004A02D0;
extern unsigned int DAT_004639DC;
unsigned int __cdecl VSIT_ForcedVoiceSituationReady_0041fba0(void)
{
    return DAT_004A02D0 == DAT_004639DC;
}
}
