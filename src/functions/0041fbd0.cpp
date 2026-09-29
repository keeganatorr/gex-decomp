extern "C" {
extern unsigned __cdecl VFX_Reset_0041f840(...);extern unsigned __cdecl VSIT_ForceVoiceSituation_0041fb80(...);extern unsigned __cdecl VSIT_PlayVoiceSituation_0041f8c0(...);extern unsigned __cdecl VSIT_UnforceVoiceSituation_0041fbc0(...);
void __cdecl FUN_0041FBD0(int param_1)

{
  if (*(int *)(param_1 + 0x98) != 0) {
    VSIT_PlayVoiceSituation_0041f8c0(*(int *)(param_1 + 0x98));
  }
  if (*(int *)(param_1 + 0x9c) != 0) {
    VSIT_ForceVoiceSituation_0041fb80(*(int *)(param_1 + 0x9c));
  }
  if (*(int *)(param_1 + 0xa0) != 0) {
    VFX_Reset_0041f840();
  }
  if (*(int *)(param_1 + 0xa4) != 0) {
    VSIT_UnforceVoiceSituation_0041fbc0();
  }
  return;
}
}
