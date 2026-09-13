// Adapted from pc_decomp_backup/src/functions/FUN_0043B090.cpp
// Historical source SHA256: becf46c979653b88c3bb791a13dade64739b951d14c140e6d227784007d6211a
extern "C" {
extern "C" { extern int DAT_00464cb8[]; }
extern "C" { extern int DAT_0045ffdc; }

extern "C" void __cdecl GEX_Target(int param_1)
{
    int i;
    for (i = 0; i < 0x40; i++) {
        DAT_00464cb8[i] = 0;
    }
    *(int*)(param_1 + 0x50) = 2;
    *(int*)(param_1 + 0x54) = 0;
    DAT_0045ffdc = *(int*)(param_1 + 0x98);
}
}
