// Adapted from pc_decomp_backup/src/functions/FUN_00401ED0.cpp
// Historical source SHA256: 5f5b5269c24cbd59bfd3c3d553f04815211ba84d43809d482067b98a0010a7cf
extern "C" {
extern "C" { extern int DAT_0049A030; }
extern "C" void __cdecl GEX_Target(int, int);

extern "C" void __cdecl GEX_Target(int volume, int applyNow)
{
    if (volume == 0) return;
    int newVol = (volume * 4 - 500) * 4;
    if (newVol == DAT_0049A030) return;
    DAT_0049A030 = newVol;
    if (applyNow != 0) {
        GEX_Target(0x158, newVol);
    }
}
}
