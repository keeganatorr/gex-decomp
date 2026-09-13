// Adapted from pc_decomp_backup/src/functions/FUN_00401B00.cpp
// Historical source SHA256: bb0bb9acb99ba69c59a2faf24c40d5bd1d00576594e53b32a0ac3dd9d06b5cb5
extern "C" {
extern "C" { extern int DAT_00455C0C; }
extern "C" { extern int DAT_004A2A0C; }
extern "C" { extern int DAT_0048A048; }
extern "C" { extern int DAT_0049A068; }
extern "C" { extern int DAT_0049A054; }

extern "C" int __cdecl GEX_Target()
{
    return !DAT_00455C0C || DAT_004A2A0C || DAT_0048A048 || DAT_0049A068 || !DAT_0049A054;
}
}
