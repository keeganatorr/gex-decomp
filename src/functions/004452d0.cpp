// Adapted from pc_decomp_backup/src/functions/FUN_004452D0.cpp
// Historical source SHA256: a6be9d1e98ddb875d613c489ca637107895ea7200db4ae68261df8b78b219f36
extern "C" {
extern "C" unsigned short __cdecl FUN_004451A0(int, int, int, int);

extern "C" int* __cdecl GEX_Target(int* param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4, unsigned int param_5)
{
    int* p = param_1;
    for (int i = 0x17; i != 0; i--) { *p++ = 0; }
    *(unsigned short*)param_1 = param_2 & 0x3ff;
    *(unsigned short*)((char*)param_1 + 2) = param_3 & 0x1ff;
    *((short*)param_1 + 1) = (short)param_4;
    *(unsigned short*)((char*)param_1 + 6) = param_5;
    *((unsigned short*)param_1 + 2) = param_2 & 0x3ff;
    *(unsigned short*)((char*)param_1 + 10) = param_3 & 0x1ff;
    unsigned int r = FUN_004451A0(0, 0, 0x280, 0);
    *((short*)param_1 + 5) = (short)r;
    *(unsigned char*)((char*)param_1 + 0x16) = 1;
    *(unsigned char*)((char*)param_1 + 0x17) = 1;
    return param_1;
}
}
