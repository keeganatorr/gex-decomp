// Adapted from pc_decomp_backup/src/functions/FUN_0043F2D0.cpp
// Historical source SHA256: 42ca7aa072f2c4d204ba8c766526a923013722d95bae23aa9d99ca8fa593a8c1
extern "C" {
extern "C" { extern unsigned char DAT_0046067C; }

extern "C" void __cdecl FUN_0043F290(void);

extern "C" void __cdecl GEX_Target(int param_1)
{
    if (param_1)
        FUN_0043F290();

    DAT_0046067C = 1;
}
}
