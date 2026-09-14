typedef unsigned int uint;
extern "C" {
int __cdecl GEX_Target(uint param_1, uint param_2)
{
    uint second = param_2;
    uint first = param_1;
    return ((second & 0xffff0000) + (second & 0xffff)) *
               ((int)first >> 0x10) +
           ((int)second >> 0x10) * (first & 0xffff) +
           ((int)((second & 0xffff) * (first & 0xffff)) >> 0x10);
}
}
