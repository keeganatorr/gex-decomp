// Adapted from pc_decomp_backup/src/functions/FUN_0041D250.cpp
// Historical source SHA256: 23a062346a21567869546bfef8e3594396b389f1d2c128eaf1f451b747625e24
extern "C" {
extern "C" int __cdecl GEX_Target(int param_1, int param_2)
{
    int* piVar1;
    int iVar2;
    int p2_4;
    int p2_8;
    int p2_14;
    int p2_18;
    int p1_4;
    int p1_8;
    int p1_14;
    int p1_18;

    p2_4 = *(int*)(param_2 + 4);
    p2_8 = *(int*)(param_2 + 8);
    p2_14 = *(int*)(param_2 + 0x14);
    p2_18 = *(int*)(param_2 + 0x18);
    p1_4 = *(int*)(param_1 + 4);
    p1_8 = *(int*)(param_1 + 8);
    p1_14 = *(int*)(param_1 + 0x14);
    p1_18 = *(int*)(param_1 + 0x18);

    piVar1 = (int*)(param_1 + 0x24);
    iVar2 = 0;
    while (1) {
        if ((p2_4 <= *piVar1 && *piVar1 <= p2_14) &&
            (p2_8 <= piVar1[1] && piVar1[1] <= p2_18)) break;
        piVar1 = piVar1 + 2;
        iVar2 = iVar2 + 1;
        if (3 < iVar2) {
            piVar1 = (int*)(param_2 + 0x24);
            iVar2 = 0;
            while (1) {
                if ((p1_4 <= *piVar1 && *piVar1 <= p1_14) &&
                    (p1_8 <= piVar1[1] && piVar1[1] <= p1_18)) break;
                piVar1 = piVar1 + 2;
                iVar2 = iVar2 + 1;
                if (3 < iVar2) return 0;
            }
            return 1;
        }
    }
    return 1;
}
}
