// Adapted from pc_decomp_backup/src/functions/FUN_0042DE00.cpp
// Historical source SHA256: 4205a004328803049eedf6ee0342b43336f37913f569ef6523dc128f16d5a812
extern "C" {
extern "C" void __cdecl FUN_0042dcf0_Object_unk(void**, void**);
extern "C" int __cdecl GEX_Target(void** param_1, void** param_2)
{ if ((int)((unsigned int)param_1[0x62] & 0x1f0000) >= 0x100000) { FUN_0042dcf0_Object_unk(param_1, param_2); return 1; } return 0; }
}
