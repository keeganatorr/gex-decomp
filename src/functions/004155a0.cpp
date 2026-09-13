// Adapted from pc_decomp_backup/src/functions/FUN_004155A0.cpp
// Historical source SHA256: ed1d208b481115fa0ca87cac1fc7e2fa82545a3f4ba253f60c1f9563e935cfd0
extern "C" {
extern "C" void __cdecl FUN_00424090(void **);
extern "C" void __cdecl GEX_Target(void **p)
{
    void *v = (void *)((int)p[0x26] + 1);
    p[0x26] = v;
    if ((int)v > 0x2a)
        FUN_00424090(p);
}
}
