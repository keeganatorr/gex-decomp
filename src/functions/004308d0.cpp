// Adapted from pc_decomp_backup/src/functions/FUN_004308D0.cpp
// Historical source SHA256: 29890c9ea2c3ba1618407e33127e9dc07133d41417b9221037ae3240413f5efe
extern "C" {
extern "C" void __cdecl FUN_0042e850(int*);
extern "C" void __cdecl FUN_00441150(void*);
extern "C" void __cdecl FUN_0042f910_GRAPHICSDRAWING(int*, unsigned int);

extern "C" { extern int DAT_0045b128; }

extern "C" void __cdecl GEX_Target(int* param_1)
{
    int pGVar1;
    int pGVar2;
    int pGVar3;
    int pGVar4;
    int pGVar5;

    pGVar1 = param_1[0x1f];
    pGVar2 = param_1[0x1e];
    pGVar3 = param_1[0x32];
    pGVar4 = param_1[0x33];
    FUN_0042e850(param_1);
    pGVar5 = param_1[0x2e] - 1;
    param_1[0x2e] = pGVar5;
    if (pGVar5 < 1) {
        FUN_00441150((void*)param_1);
    }
    else {
        if (!(pGVar5 & 1)) {
            pGVar5 = param_1[0x2f];
            param_1[0x2f] = 0x1d001d00;
            FUN_00441150((void*)param_1);
            param_1[0x2f] = pGVar5;
        }
        else {
            FUN_00441150((void*)param_1);
        }
    }
    param_1[0x1e] = pGVar2;
    param_1[0x1f] = pGVar1;
    param_1[0x32] = pGVar3;
    param_1[0x33] = pGVar4;
    if (DAT_0045b128 != 0) {
        FUN_0042f910_GRAPHICSDRAWING(param_1, (unsigned int)param_1[0x2a]);
    }
}
}
