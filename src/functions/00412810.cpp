// Adapted from pc_decomp_backup/src/functions/FUN_00412810.cpp
// Historical source SHA256: e469d082d3d75f2ac4acffaa00e84564500f7d8089b905589556c0e171fc1d30
extern "C" {
extern "C" void __cdecl FUN_00420BC0(int*);
extern "C" void __cdecl FUN_00412800(int*);

extern "C" void __cdecl InitPlayerPlatSideGetup_00412810(int* p)
{
    int* esi = p;
    FUN_00420BC0(esi);
    esi[0x70 / 4] = 0x4f;
    FUN_00412800(esi);
}
}
