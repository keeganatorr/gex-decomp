extern "C" unsigned int __cdecl FUN_00417F40(unsigned char **);
extern "C" void __cdecl FUN_0043F490(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

extern "C" unsigned char * __cdecl GEX_Target(unsigned char *param_1)
{
    unsigned int uVar1;
    unsigned int local_4;
    unsigned int local_8;
    unsigned int local_c;
    unsigned int local_10;
    unsigned int local_14;
    unsigned int local_18;

    uVar1 = FUN_00417F40(&param_1);
    local_4 = *param_1++;
    local_8 = *param_1++;
    local_c = *param_1++;
    local_10 = *param_1++;
    local_14 = *param_1++;
    local_18 = *param_1++;
    FUN_0043F490(uVar1, local_4, local_8, local_c, local_10, local_14, local_18);
    return param_1;
}
