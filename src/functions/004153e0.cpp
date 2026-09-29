extern "C" {
extern int DAT_00455BE4;
extern int DAT_00455BE8;
extern int DAT_00455BEC;
extern int DAT_00455BFC;
extern int DAT_00455C00;
extern int DAT_004588D8[];
extern void __cdecl FUN_004252B0(int*);
}

extern "C" void __cdecl FUN_004153e0_Falling_unk(int* param_1)
{
    int v2;
    int elem;
    int v3;

    v2 = param_1[0x26] - 1;
    param_1[0x26] = v2;
    if (v2 < 0) {
        DAT_00455BE4 = 0;
        FUN_004252B0(param_1);
        return;
    }

    elem = DAT_004588D8[v2];
    param_1[0x26] = v2 - 1;
    DAT_00455BE8 = elem;
    DAT_00455BEC = elem;
    DAT_00455BFC += param_1[0x2a];
    DAT_00455C00 += param_1[0x2b];

    v3 = param_1[0x27] + 0x5556;
    param_1[0x27] = v3;
    if (v3 >= 0x10000) {
        param_1[0x27] = v3 - 0x10000;
        param_1[0x15]++;
    }
}
