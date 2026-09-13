// Adapted from pc_decomp_backup/src/functions/FUN_004153E0.cpp
// Historical source SHA256: 3cc009c6481ae34b2626fb91448a0df7219d9fd6acc7a310481d806df4d1a1de
extern "C" {
extern "C" { extern int DAT_00455BE4; }
extern "C" { extern int DAT_00455BE8; }
extern "C" { extern int DAT_00455BEC; }
extern "C" { extern int DAT_00455BFC; }
extern "C" { extern int DAT_00455C00; }
extern "C" { extern int DAT_004588D8; }
extern "C" void __cdecl FUN_004252B0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int pGVar1;
    int pGVar2;

    pGVar1 = (int)param_1[0x26];
    pGVar2 = pGVar1 - 8 + 3;
    param_1[0x26] = (void*)pGVar2;
    if (pGVar2 < 0) {
        DAT_00455BE4 = 0;
        FUN_004252B0(param_1);
        return;
    }
    DAT_00455BE8 = *(int*)((int)&DAT_004588D8 + pGVar2 * 4);
    param_1[0x26] = (void*)(pGVar1 - 8 + 2);
    DAT_00455BFC = (int)param_1[0x2a] + DAT_00455BFC - 0x1c;
    DAT_00455C00 = (int)param_1[0x2b] + DAT_00455C00 - 0x1c;
    pGVar1 = (int)param_1[0x27];
    pGVar2 = *(int*)(pGVar1 + 0x2a * 4) + 0x1d;
    DAT_00455BEC = DAT_00455BE8;
    param_1[0x27] = (void*)pGVar2;
    if (pGVar2 > 0xffff) {
        param_1[0x27] = (void*)(*(int*)(pGVar1 + (-0x56 * 4)) + 0x1d);
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
    }
}
}
