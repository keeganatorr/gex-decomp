// Adapted from pc_decomp_backup/src/functions/FUN_00430EA0.cpp
// Historical source SHA256: 05c5e60cdf53b29ad4046b98d2d651fc2774df07d7d839cb7449cd8191909626
extern "C" {
extern "C" void __cdecl FUN_0042E850(int*);
extern "C" void __cdecl FUN_00441150(void*);

extern "C" { extern int DAT_00463F10; }
extern "C" { extern int DAT_00463F98; }
extern "C" { extern int DAT_00463F14; }
extern "C" { extern int DAT_00463E0C; }

extern "C" void __cdecl GEX_Target(int* param_1)
{
    int pGVar1;
    int pGVar2;
    int pGVar3;
    int pGVar4;

    pGVar1 = param_1[0x1e];
    pGVar2 = param_1[0x1f];
    pGVar3 = param_1[0x32];
    pGVar4 = param_1[0x33];
    FUN_0042E850(param_1);
    if (DAT_00463F10 <= param_1[0x1e] && param_1[0x1e] < DAT_00463F98 &&
        DAT_00463F14 <= param_1[0x1f] && param_1[0x1f] < DAT_00463E0C) {
        FUN_00441150((void*)param_1);
    }
    param_1[0x1e] = pGVar1;
    param_1[0x1f] = pGVar2;
    param_1[0x32] = pGVar3;
    param_1[0x33] = pGVar4;
}
}
