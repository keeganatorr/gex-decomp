// Adapted from pc_decomp_backup/src/functions/FUN_0043AE90.cpp
// Historical source SHA256: 380711ed99fff82715ca302a9f3c40228f28f163344953db21f610365705067f
extern "C" {
extern "C" { extern int DAT_00464788; }
extern "C" { extern int DAT_00464794; }
extern "C" void __cdecl FUN_0043F490(int, int, int, int, int, int, int);

extern "C" void __cdecl GEX_Target(int param_1, int param_2)
{
    if (param_2 == 0) {
        if (DAT_00464794 == 0) {
            *(int*)(param_1 + 0xd0) = 0x30000000;
            DAT_00464794 = param_1;
        }
        *(int*)(param_1 + 0x9c) = 0;
        return;
    }
    if (param_1 == DAT_00464794) {
        DAT_00464794 = 0;
        DAT_00464788 = 0;
        FUN_0043F490(0, 0, 0xff, 0, 0xff, 0, 0xff);
    }
}
}
