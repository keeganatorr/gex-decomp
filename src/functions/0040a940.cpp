// Adapted from pc_decomp_backup/src/functions/FUN_0040A940.cpp
// Historical source SHA256: 9d5afc5cd0b97968cb24a3fa7452d3a864ac4118fc295dba25644e8536c326aa
extern "C" {
extern "C" { extern int DAT_004A298C; }
extern "C" { extern int DAT_004A2A28; }
extern "C" { extern void* DAT_00455B78; }
extern "C" { extern void* DAT_00455B7C; }
extern "C" void __cdecl FUN_00409320(void*);

extern "C" void __cdecl M1_CloseLevelDirs_0040a940()
{
    if (DAT_004A298C != 0) { FUN_00409320(DAT_00455B78); DAT_004A298C = 0; }
    if (DAT_004A2A28 != 0) { FUN_00409320(DAT_00455B7C); DAT_004A2A28 = 0; }
}
}
