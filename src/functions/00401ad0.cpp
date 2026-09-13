// Adapted from pc_decomp_backup/src/functions/FUN_00401AD0.cpp
// Historical source SHA256: 0df5f741b544ba1eb86e15c21b454bda37211796589af6a4fbdd6f3d20ea5f94
extern "C" {
extern "C" { extern int DAT_00455C0C; }
extern "C" { extern int DAT_004A2A0C; }
extern "C" { extern int DAT_0049A054; }
extern "C" { extern int DAT_0049A078[]; }

extern "C" void __cdecl GEX_Target(int vfxId)
{
    if (DAT_00455C0C == 0) return;
    if (DAT_004A2A0C != 0) return;
    if (DAT_0049A054 != 0) return;
    
    DAT_0049A054 = DAT_0049A078[vfxId];
}
}
