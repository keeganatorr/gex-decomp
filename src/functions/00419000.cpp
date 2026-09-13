// Adapted from pc_decomp_backup/src/functions/FUN_00419000.cpp
// Historical source SHA256: 403749992ee0d834120e326b961ec5e2d94dcb70ee3cd05b532682ec4fee81ce
extern "C" {
extern "C" void __cdecl FUN_0040BC70(void*, void*, unsigned int, int*, int*, int, char*, void**);
extern "C" unsigned char* __cdecl GEX_Target(unsigned char* param1, void** param2) {
    unsigned char* p = param1;
    unsigned int val = p[0];
    unsigned int idx = p[1];
    void** pp = param2;
    param1 = p + 1;
    FUN_0040BC70(pp[0x1e], pp[0x1f], val, 0, 0, -1, (char*)pp[idx + 0x1a], pp);
    return param1 + 1;
}
}
