extern "C" {
extern "C" void __cdecl FUN_0044A280(double*, char*, int, int);
extern "C" void __cdecl FUN_0044A3C0(double*, char*, int);
extern "C" void __cdecl FUN_0044A4C0(double*, char*, int, int);

extern "C" void __cdecl GEX_Target(double* param_1, char* param_2, int param_3, int param_4, int param_5)
{
    if (param_3 != 0x65 && param_3 != 0x45) {
        if (param_3 == 0x66) {
            FUN_0044A3C0(param_1, param_2, param_4);
            return;
        }
        FUN_0044A4C0(param_1, param_2, param_4, param_5);
        return;
    }
    FUN_0044A280(param_1, param_2, param_4, param_5);
}
}
