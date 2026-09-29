typedef unsigned int uint;
typedef unsigned int undefined4;
extern "C" {
undefined4 __cdecl ___addl(uint param_1, uint param_2, uint *param_3)
{
    uint sum = param_1 + param_2;
    undefined4 carry = 0;
    if (param_1 > sum)
        carry = 1;
    else if (param_2 > sum)
        carry = 1;
    *param_3 = sum;
    return carry;
}
}
