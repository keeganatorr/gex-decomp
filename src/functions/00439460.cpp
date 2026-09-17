extern "C" {
extern int DAT_00464520;
extern void __cdecl FUN_00419840(void*);
}

extern "C" void __cdecl GEX_Target(int* param_1)
{
    if (DAT_00464520 % 2 == 0) {
        param_1[0x15]++;
    }
    if (param_1[0x15] == 5) {
        FUN_00419840(param_1);
    }
    param_1[0x1e] += param_1[0x20];
    param_1[0x1f] += param_1[0x23];
}
