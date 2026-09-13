// Adapted from pc_decomp_backup/src/functions/FUN_00415170.cpp
// Historical source SHA256: 7ee44b7f04874656523989fb4f93688a0e223aec243d9211c8391a70df19ef9f
extern "C" {
extern int DAT_00458898[];
extern int DAT_00455be8;
extern int DAT_00455bec;
extern int DAT_00455bfc;
extern int DAT_00455c00;
extern int DAT_00456ae8;
extern int FUN_00455C3C;
extern unsigned int FUN_004A2660[];
extern int DAT_004a2678;
extern int FUN_004A2420[];
extern int FUN_004A2964;
extern int DAT_004588d0[];
extern unsigned char BYTE_ARRAY_004a2540[];
extern unsigned short FUN_004577B0[];
extern int FUN_00456AD8;
extern int FUN_004A2A7C;

extern "C" void __cdecl GEX_Target(void **param_1)
{
    int pGVar1;
    int iVar2;
    unsigned int *puVar4;

    pGVar1 = (int)param_1[0x28];
    iVar2 = *(int *)(pGVar1 + 0x2a * 4) + 0x1d;
    param_1[0x28] = (void *)iVar2;
    if (0xffff < iVar2) {
        param_1[0x28] = (void *)(*(int *)(pGVar1 + (-0x56) * 4) + 0x1d);
        param_1[0x15] = (void *)((int)param_1[0x15] + 1);
    }
    iVar2 = DAT_00458898[(int)param_1[0x26]];
    if (iVar2 != 0) {
        param_1[0x32] = (void *)((int)param_1[0x32] + -2);
        param_1[0x33] = (void *)((int)param_1[0x33] + -2);
        param_1[0x26] = (void *)((int)param_1[0x26] + 1);
        DAT_00455be8 = iVar2;
        DAT_00455bec = iVar2;
        DAT_00455bfc = (int)param_1[0x2a] + DAT_00455bfc + -0x1c;
        DAT_00455c00 = (int)param_1[0x2b] + DAT_00455c00 + -0x1c;
        return;
    }
    if (DAT_00456ae8 == 4) {
        FUN_00455C3C = 5;
        puVar4 = &FUN_004A2660[0];
        do {
            if ((*puVar4 & 0xff) < 3) {
                FUN_004A2420[FUN_004A2964] =
                    FUN_004A2420[FUN_004A2964] | (DAT_004588d0[*puVar4 & 0xff]);
            }
            puVar4 = puVar4 + 1;
        } while (puVar4 < &FUN_004A2660[6]);
        if (FUN_004A2420[FUN_004A2964] >> 4 ==
            (FUN_004A2420[FUN_004A2964] & 0xf)) {
            BYTE_ARRAY_004a2540[FUN_004A2964] = BYTE_ARRAY_004a2540[FUN_004A2964] | 2;
        }
    }
    else if ((FUN_004577B0[FUN_00456AD8 * 8] & 0x80) == 0) {
        if ((FUN_00456AD8 == 47) || (FUN_00456AD8 == 61)) {
            FUN_00456AD8 = FUN_004A2964;
        }
        FUN_00455C3C = 3;
    }
    else {
        FUN_00455C3C = 2;
    }
    if (FUN_004A2964 == FUN_00456AD8) {
        FUN_004A2A7C = 3;
        return;
    }
    FUN_004A2964 = FUN_00456AD8;
    FUN_004A2A7C = 1;
}
}
