extern "C" unsigned short __cdecl FUN_004451A0(int, int, int, int);

extern "C" int* __cdecl FUN_004452d0_GFXInit3(int* param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4, unsigned int param_5)
{
    int* p = param_1;
    for (int i = 0x17; i != 0; i--) { *p++ = 0; }
    *(unsigned short*)param_1 = (unsigned short)(param_2 & 0x3ff);
    *(unsigned short*)((char*)param_1 + 2) = (unsigned short)(param_3 & 0x1ff);
    *(unsigned short*)((char*)param_1 + 4) = (unsigned short)param_4;
    *(unsigned short*)((char*)param_1 + 6) = (unsigned short)param_5;
    *(unsigned short*)((char*)param_1 + 8) = (unsigned short)(param_2 & 0x3ff);
    *(unsigned short*)((char*)param_1 + 10) = (unsigned short)(param_3 & 0x1ff);
    unsigned short r = FUN_004451A0(0, 0, 0x280, 0);
    *(unsigned short*)((char*)param_1 + 0x14) = r;
    *(unsigned char*)((char*)param_1 + 0x16) = 1;
    *(unsigned char*)((char*)param_1 + 0x17) = 1;
    return param_1;
}
