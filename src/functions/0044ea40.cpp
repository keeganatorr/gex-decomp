typedef unsigned int uint;
extern "C" {
void __cdecl ___shl_12(uint *param_1)
{
    uint first = *param_1;
    uint second = param_1[1];
    uint firstCarry = first >> 0x1f;
    uint secondCarry = second >> 0x1f;
    *param_1 = first * 2;
    param_1[1] = second * 2 | firstCarry;
    param_1[2] = param_1[2] * 2 | secondCarry;
}
}
