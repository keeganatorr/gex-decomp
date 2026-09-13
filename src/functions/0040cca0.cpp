// Adapted from pc_decomp_backup/src/functions/FUN_0040CCA0.cpp
// Historical source SHA256: b905afd74d56202e184e7a9b5f8f70f8aad49b19aa15f9f43353040bf54a87cc
extern "C" {
extern "C" { extern int DAT_00456168; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int pGVar1;
    int pGVar2;

    pGVar1 = (int)param_1[0x2c];
    pGVar2 = (int)param_1[0x2a];
    if (pGVar2 == 0x10) {
        param_1[0x2c] = (void*)0x1;
    } else if (pGVar2 == 0xe) {
        param_1[0x2c] = (void*)0x2;
    } else if (pGVar2 == 0xc) {
        param_1[0x2c] = (void*)0x3;
    } else if (pGVar2 == 0x70) {
        param_1[0x2c] = (void*)0x4;
    } else {
        param_1[0x2c] = (void*)0x5;
        if (pGVar2 != 0x12) {
            param_1[0x2c] = (void*)0x0;
        }
    }
    if (pGVar1 != (int)param_1[0x2c]) {
        *(int*)((int)&DAT_00456168 + (int)param_1[0x2c] * 0x10) = 0;
    }
}
}
