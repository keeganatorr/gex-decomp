extern "C" unsigned short __cdecl FUN_004451a0_GFXInit4(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4)
{
    unsigned short v = (((unsigned short)param_1 & 3) << 2) | ((unsigned short)param_2 & 3);
    v = (v << 5) | ((unsigned short)(param_4 >> 4) & 0x10);
    v = v | ((unsigned short)(param_3 >> 6) & 0xf);
    return v;
}
