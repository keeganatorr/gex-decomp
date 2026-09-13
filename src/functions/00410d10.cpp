// Adapted from pc_decomp_backup/src/functions/FUN_00410D10.cpp
// Historical source SHA256: 98b7174ba730b0150e31e8fccf65dc2efc89c8c5a6bcc7f4e746aa163139cd48
extern "C" {
extern "C" { extern int DAT_00455B9C; }
extern "C" { extern int DAT_00455BA0; }
extern "C" { extern int DAT_00455BA4; }
extern "C" { extern int DAT_00455BA8; }
extern "C" { extern int DAT_00455BAC; }
extern "C" { extern int DAT_00455BB0; }
extern "C" { extern int DAT_00455BB4; }
extern "C" { extern int DAT_00455BB8; }
extern "C" { extern int DAT_00455BBC; }
extern "C" { extern int DAT_00455BC0; }

extern "C" void __cdecl GEX_Target(unsigned int param_1)
{
    if ((param_1 & 0x1000) != 0) {
        DAT_00455BBC = 0xb40000;
        DAT_00455BC0 = 0xbe0000;
        DAT_00455BAC = 0xb40000;
        DAT_00455BB0 = 0xbe0000;
    }
    if ((param_1 & 0x100) != 0) {
        DAT_00455BBC = 0xa00000;
        DAT_00455BC0 = 0xb40000;
        DAT_00455BAC = 0xa00000;
        DAT_00455BB0 = 0xb40000;
    }
    if ((param_1 & 0x10) != 0) {
        DAT_00455BB4 = 0xa00000;
        DAT_00455BB8 = 0xaa0000;
        DAT_00455B9C = 0xa00000;
        DAT_00455BA0 = 0xaa0000;
        DAT_00455BA4 = 0xa00000;
        DAT_00455BA8 = 0xaa0000;
    }
    if ((param_1 & 1) != 0) {
        DAT_00455BB4 = 0x960000;
        DAT_00455BB8 = 0xa00000;
        DAT_00455B9C = 0x960000;
        DAT_00455BA0 = 0xa00000;
        DAT_00455BA4 = 0x960000;
        DAT_00455BA8 = 0xa00000;
    }
}
}
