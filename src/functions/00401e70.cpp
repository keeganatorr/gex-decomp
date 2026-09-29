extern "C" {
extern int FUN_0049FB50;
extern int FUN_00455C0C;
void __cdecl FUN_00401D00(int, int);
void __cdecl SetVoiceVolume_00401e70(int param_1, int param_2)
{
    int p_Var1;
    if (param_1 != 0) {
        p_Var1 = (param_1 * 5 - 500) * 5;
        FUN_00455C0C = 1;
        if (FUN_0049FB50 != p_Var1 && (FUN_0049FB50 = p_Var1, param_2 != 0)) {
            FUN_00401D00(0x76, p_Var1);
        }
    } else {
        FUN_0049FB50 = 0xffffd8f0;
        FUN_00455C0C = 0;
    }
}
}
