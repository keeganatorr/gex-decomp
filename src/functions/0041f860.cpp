// Adapted from pc_decomp_backup/src/functions/FUN_0041F860.cpp
// Historical source SHA256: 899d686b04e15c0fdd194efbe4bf0a2914f484b4cd69b42555302adba7a46cce
extern "C" {
extern "C" { extern int FUN_004638D0; }
extern "C" { extern int FUN_004638D4[]; }
extern "C" { extern int FUN_00463954[]; }
extern "C" { extern int DAT_004638b4; }

extern "C" void __cdecl GEX_Target(int voiceEffectId, int voiceSetId)
{
    int nextIndex = FUN_004638D0 + 1;
    FUN_004638D0 = nextIndex;
    FUN_004638D4[nextIndex] = voiceEffectId;
    FUN_00463954[nextIndex] = voiceSetId;
    if (nextIndex > 0x1f) {
        FUN_004638D0 = 0;
    }
    if (DAT_004638b4 < 0x20) {
        DAT_004638b4 = DAT_004638b4 + 1;
    }
}
}
