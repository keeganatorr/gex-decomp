extern "C" {
unsigned int* __cdecl FUN_0040C110(int, int);
extern int DAT_00456034;

int __cdecl GEX_Target(int param_1, unsigned int param_2)
{
    unsigned int* obj = FUN_0040C110(0x7b, param_1);
    if (param_2 & 1) obj[0x2d] &= 0xfffffffe;
    if (param_2 & 2) obj[0x15] = 0;
    if (param_2 & 4) obj[0x15] = 0xffffffff;
    if (param_2 & 8) DAT_00456034 = 0;
    if (param_2 & 0x10) return (int)obj[0x28];
    if (param_2 & 0x20) return (int)obj[0x29];
    return 0;
}
}
