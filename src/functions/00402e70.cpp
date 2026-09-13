// Adapted from pc_decomp_backup/src/functions/FUN_00402E70.cpp
// Historical source SHA256: f4c16b5a6c4ee86c4d37b0f549eb392a30498d20831309a3d95b02d2f03e0bc8
extern "C" {
extern "C" { extern int FUN_00455C10; }
extern "C" { extern int FUN_004626A0; }
extern "C" int __cdecl GEX_Target(int param_1)
{
    if (FUN_00455C10 != 0) FUN_004626A0 = param_1;
    return 1;
}
}
