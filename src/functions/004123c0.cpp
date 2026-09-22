extern "C" {
extern int DAT_00457EE8[];
extern int DAT_00457F68[][2];
extern int DAT_00458548[];
extern int DAT_004585E8[][2];
extern int DAT_004A2864;
extern void __cdecl FUN_00420BC0(void**);
extern void __cdecl FUN_004112E0(void**, int);
extern void __cdecl FUN_00412290(void**);

void __cdecl GEX_Target(void** param_1)
{
    unsigned int uVar3;

    FUN_00420BC0(param_1);

    param_1[0x1c] = (void*)0x44;
    param_1[0x26] = (void*)0;
    param_1[0x14] = (void*)0x52;
    param_1[0x15] = (void*)0;

    uVar3 = (((unsigned int)param_1[0x1b] & 0x80000000) >> 0x1c)
          | ((int)param_1[0x31] >> 0x15);

    if (DAT_004A2864 == 0) {
        param_1[0x1e] = (void*)((unsigned int)param_1[0x1e] & 0xffe00000);
        param_1[0x1f] = (void*)((unsigned int)param_1[0x1f] & 0xffe00000);
    } else {
        FUN_004112E0(param_1, DAT_00457EE8[uVar3]);
    }

    param_1[0x1e] = (void*)((int)param_1[0x1e] + DAT_00457F68[uVar3][0]);
    param_1[0x1f] = (void*)((int)param_1[0x1f] + DAT_00457F68[uVar3][1]);
    param_1[0x1e] = (void*)((int)param_1[0x1e]
        + DAT_00458548[(int)param_1[0x15] + DAT_004585E8[uVar3][0] * 5]);
    param_1[0x1f] = (void*)((int)param_1[0x1f]
        + DAT_00458548[(int)param_1[0x15] + DAT_004585E8[uVar3][1] * 5]);

    FUN_00412290(param_1);
}
}
