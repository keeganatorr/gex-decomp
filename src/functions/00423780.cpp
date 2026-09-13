// Adapted from pc_decomp_backup/src/functions/FUN_00423780.cpp
// Historical source SHA256: 0ccac6bcd1220bd7ada84ca8f667333d34cbd02e90d18d1d2bd015d485eb103d
extern "C" {
extern "C" void __cdecl FUN_00423760(void);
extern "C" void __cdecl FUN_00423350(void**, int);
extern "C" void __cdecl FUN_00423200(void**, void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00423760();
    FUN_00423350(p, 0);
    void** other = *(void***)0x004A2874;
    if (other) FUN_00423200(p, other);
    other = *(void***)0x004A2814;
    if (other) FUN_00423200(p, other);
}
}
