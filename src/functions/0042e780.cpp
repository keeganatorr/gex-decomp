extern "C" int DAT_0045B100;
extern "C" int DAT_0045B104;
extern "C" int DAT_0045B108;
extern "C" int __cdecl abs(int);

extern "C" void __cdecl FUN_0042e780(int *param_1)
{
    int value;
    int scale;

    if (param_1[2] == 1)
        value = DAT_0045B100;
    else
        value = param_1[0x28] + DAT_0045B100;

    if (abs(value) < 16)
        scale = 0x10000000;
    else
        scale = 0x10000000 / (value >> 4);

    scale >>= 8;
    param_1[0x32] = (param_1[0x32] >> 8) * scale;
    param_1[0x33] = (param_1[0x33] >> 8) * scale;
    param_1[0x1e] = ((param_1[0x1e] - DAT_0045B104) >> 8) * scale + DAT_0045B104;
    param_1[0x1f] = ((param_1[0x1f] - DAT_0045B108) >> 8) * scale + DAT_0045B108;
    param_1[0x7e] = ((param_1[0x7e] - DAT_0045B104) >> 8) * scale + DAT_0045B104;
    param_1[0x7f] = ((param_1[0x7f] - DAT_0045B108) >> 8) * scale + DAT_0045B108;
}
