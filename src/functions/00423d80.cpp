// Adapted from pc_decomp_backup/src/functions/FUN_00423D80.cpp
// Historical source SHA256: dc3604be12821179da62ecae49678b048edac6086d1a758b07826774771d0db5
extern "C" {
extern "C" int __cdecl FUN_0040F1D0(void*, void**);
extern "C" int __cdecl GEX_Target(void* p1, void** p2, int p3, int p4)
{
    void* ox = p2[0x1e];
    void* oy = p2[0x1f];
    p2[0x1e] = (void*)p3;
    p2[0x1f] = (void*)p4;
    int result = FUN_0040F1D0(p1, p2);
    p2[0x1e] = ox;
    p2[0x1f] = oy;
    return result;
}
}
