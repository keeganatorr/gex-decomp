// Adapted from pc_decomp_backup/src/functions/FUN_00409940.cpp
// Historical source SHA256: d69e4bbe9a222252754af110fd39669e5acdf20c68490486d0b63a11be96fc3d
extern "C" {
extern "C" { extern void** DAT_004A2AD4; }
extern "C" { extern int DAT_00462704; }
extern "C" { extern int DAT_004626F8; }
extern "C" void __cdecl FUN_0040B860(int);
extern "C" void __cdecl GEX_Target()
{ if (DAT_004A2AD4 != 0) { FUN_0040B860(DAT_00462704); DAT_004A2AD4 = 0; DAT_004626F8 = 0; } }
}
