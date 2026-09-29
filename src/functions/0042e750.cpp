extern "C" int DAT_0045B108;

extern "C" int __cdecl FUN_0042e750_GraphicsUnk(int param_1, unsigned int param_2)
{
    int value = (param_1 - DAT_0045B108) * 16;
    if ((param_2 & 0xfffffff0U) != 0)
        value = value / ((int)param_2 >> 4);
    return value * 256 + DAT_0045B108;
}
