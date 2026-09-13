// Adapted from pc_decomp_backup/src/functions/FUN_00417500.cpp
// Historical source SHA256: 385b0f8f0e1524c39cbe0bac48831272a7cd514d99a45c5652a2d02a0a761e35
extern "C" {
extern "C" { extern int DAT_004A0218; }
extern "C" void __cdecl FUN_0041750B(int pendingSound, int unused, int player);

extern "C" void __cdecl GEX_Target(void* player)
{
    FUN_0041750B(DAT_004A0218, 0, (int)player);
}
}
