// Adapted from pc_decomp_backup/src/functions/FUN_004276E0.cpp
// Historical source SHA256: 704e9bb24a8767048c82de17c19a1c7d5dc0a69b338925c63a431386bbf604cf
extern "C" {
extern "C" { extern int DAT_004A0218; }
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" int __cdecl FUN_004206B0(int);
extern "C" void __cdecl FUN_004275E0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar1;

    FUN_00420BC0(param_1);
    if ((int)param_1[0x15] > 10) {
        param_1[0x15] = (void*)0x9;
    }
    if ((int)param_1[0x1c] == 0x16 || (int)param_1[0x1c] == 0x18) {
        param_1[0x29] = (void*)0x1;
    } else {
        param_1[0x29] = (void*)0x0;
    }
    param_1[0x26] = (void*)0x0;
    param_1[0x22] = (void*)0x0;
    param_1[0x1c] = (void*)0x1c;
    param_1[0x14] = (void*)0x2b;
    iVar1 = FUN_004206B0(0x47);
    if (iVar1 == 0) {
        DAT_004A0218 = 0x66;
    }
    FUN_004275E0(param_1);
}
}
