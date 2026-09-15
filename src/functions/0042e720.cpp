extern "C" int DAT_0045B104;

extern "C" int __cdecl GEX_Target(int param_1, unsigned int param_2)
{
    int value = (param_1 - DAT_0045B104) * 16;
    if ((param_2 & 0xfffffff0U) != 0)
        value /= ((int)param_2 >> 4);
    return value * 256 + DAT_0045B104;
}
