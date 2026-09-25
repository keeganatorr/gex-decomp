extern "C" {
extern int FUN_004638D0;
extern int FUN_004638D4[];
extern int FUN_00463954[];
extern int DAT_004638b4;

void __cdecl GEX_Target(int voiceEffectId, int voiceSetId)
{
    int nextIndex = FUN_004638D0;
    int effect = voiceEffectId;
    int set = voiceSetId;
    nextIndex++;
    FUN_004638D0 = nextIndex;
    FUN_004638D4[nextIndex] = effect;
    FUN_00463954[nextIndex] = set;
    if (nextIndex >= 0x20) {
        FUN_004638D0 = 0;
    }
    if (DAT_004638b4 < 0x20) {
        DAT_004638b4 = DAT_004638b4 + 1;
    }
}
}
