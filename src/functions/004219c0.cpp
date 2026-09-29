// Adapted from pc_decomp_backup/src/functions/FUN_004219C0.cpp
// Historical source SHA256: edd14efa34090f3549c56aec705b0a2eedc4262c7604f80bf945e77ca9308855
extern "C" {
extern "C" { extern int DAT_00463acc_GexVelocityInAir; }
extern "C" { extern int DAT_004a2890_velocity_unk; }
extern "C" int __cdecl FUN_004219c0_Velocity(void** p) { if ((int)p[0x23] > 0) DAT_00463acc_GexVelocityInAir = 1; if (!DAT_004a2890_velocity_unk) p[0x23] = 0; return 1; }
}
