// Adapted from pc_decomp_backup/src/functions/FUN_00404A80.cpp
// Historical source SHA256: f8e6a1e20ae5943e6ff4886117cf18956b6de3206724e841da1287a655ee3135
extern "C" {
extern "C" { extern int DAT_00454FC8; }
extern "C" { extern int DAT_004626A8; }
extern "C" void __cdecl FUN_004A5684(int, int, int, void*);

extern "C" void __cdecl GEX_Target()
{
    if (DAT_00454FC8 > 8) return;
    int result;
    FUN_004A5684(DAT_004626A8, 0x840, 0x10000, &result);
}
}
