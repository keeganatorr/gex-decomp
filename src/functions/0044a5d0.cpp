// Adapted from pc_decomp_backup/src/functions/FUN_0044A5D0.cpp
// Historical source SHA256: 2a8a11c9dc38e093fef3f286cf8e832d0dc6579a4262b85a0ecb34a41bf36716
extern "C" {
extern "C" void __cdecl FUN_0044A280(double*, char*, int, int, int);
extern "C" void __cdecl FUN_0044A3C0(double*, char*, int, int);
extern "C" void __cdecl FUN_0044A4C0(double*, char*, int, int);

extern "C" void __cdecl GEX_Target(double* param_1, char* param_2, int param_3, int param_4, int param_5)
{
    if (param_3 != 0x65 && param_3 != 0x45) {
        if (param_3 == 0x66) {
            FUN_0044A3C0(param_1, param_2, param_4, 0);
            return;
        }
        FUN_0044A4C0(param_1, param_2, param_4, param_5);
        return;
    }
    FUN_0044A280(param_1, param_2, param_4, param_5, 0);
}
}
