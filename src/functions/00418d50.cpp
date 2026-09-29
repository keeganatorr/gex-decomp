// Adapted from pc_decomp_backup/src/functions/FUN_00418D50.cpp
// Historical source SHA256: 3f99bcb1d3758d35e423ebd432b4f8457ebb51d26cb2906932315f0a418f58a1
extern "C" {
extern "C" { extern int DAT_0049FB90; }

extern "C" unsigned int __cdecl FUN_0041FBA0(void);

extern "C" unsigned int __cdecl SCRIPT_ForcedVoiceSituationReady_00418d50(unsigned int param_1)
{
    DAT_0049FB90 = FUN_0041FBA0();
    return param_1;
}
}
