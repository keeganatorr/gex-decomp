// Adapted from pc_decomp_backup/src/functions/FUN_00401E20.cpp
// Historical source SHA256: 8d69404e59e8835082d6f47b1c21fc788c7dda006b09a79a0cde5774f1d10eb4
extern "C" {
extern "C" { extern int DAT_0049FB20; }
extern "C" void __cdecl FUN_00401ED0(int, int);

extern "C" void __cdecl GEX_Target(int volume, int applyNow)
{
    if (volume == 0) return;
    int newVol = (volume * 4 - 500) * 4;
    if (newVol == DAT_0049FB20) return;
    DAT_0049FB20 = newVol;
    if (applyNow != 0) {
        FUN_00401ED0(0xe3, newVol);
    }
}
}
