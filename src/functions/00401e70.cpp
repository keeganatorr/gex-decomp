// Adapted from pc_decomp_backup/src/functions/FUN_00401E70.cpp
// Historical source SHA256: 017ffea035dd25bd69cbf09ca3b87c4105ed25656946b53535e149468b2ef8f5
extern "C" {
extern "C" void __cdecl FUN_00401D00(int, int);

extern "C" { extern int FUN_0049FB50; }
extern "C" { extern int FUN_00455C0C; }

extern "C" void __cdecl GEX_Target(int param_1, int param_2)
{
    int p_Var1;

    if (param_1 == 0) {
        FUN_0049FB50 = 0xffffd8f0;
        FUN_00455C0C = 0;
    }
    else {
        FUN_00455C0C = 1;
        p_Var1 = (param_1 * 5 + -500) * 5;
        if (FUN_0049FB50 != p_Var1) {
            FUN_0049FB50 = p_Var1;
            if (param_2 != 0) {
                FUN_00401D00(0x76, p_Var1);
            }
        }
    }
}
}
