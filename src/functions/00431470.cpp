// Adapted from pc_decomp_backup/src/functions/FUN_00431470.cpp
// Historical source SHA256: e620a20dd01f57f2d146ba2f09c038ea2db52792da43a13f6f9e3b8fc3a1afa3
extern "C" {
extern int DAT_0045b13c;
extern int DAT_0045b09c;
extern int DAT_0045b0a0;
extern int DAT_0045b0a4;
extern int DAT_0045b0a8;
extern int DAT_0045b0ac;
extern int DAT_0045b130;
extern int FUN_004A2AD4;

extern "C" void __cdecl FUN_004339C0(int *);
extern "C" void __cdecl FUN_00430E20(int *);
extern "C" void *__cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419BE0(void *, void *);
extern "C" void __cdecl FUN_004372F0(int *);
extern "C" int __cdecl FUN_0042f5f0(int *, int);

extern "C" void __cdecl GEX_Target(int *param_1)
{
    int pGVar1;
    int *ppGVar2;

    if (param_1[0x26] == 0x400) {
        DAT_0045b13c = DAT_0045b13c + 1;
        FUN_004339C0(param_1);
        if (param_1[0x27] == 1) {
            DAT_0045b09c = 0;
        }
        if ((DAT_0045b13c % 8) == 0) {
            FUN_0042f5f0(param_1, 1);
            return;
        }
    } else if (param_1[0x26] == 0x80) {
        param_1[0x28] = param_1[0x28] - 1;
        if (param_1[0x28] == 0) {
            param_1[0x15] = 1;
        }
        param_1[0x2c] = param_1[0x2c] - 1;
        if (param_1[0x2c] < 1) {
            param_1[0x2c] = 3;
            param_1[0x2b] = param_1[0x2b] + 1;
            if (param_1[0x2b] == 10) {
                param_1[0x2b] = 0;
            }
            param_1[0x1f] = param_1[0x1f] + *(int *)((char *)0x45b0b0 + param_1[0x2b] * 4) * 0x80;
        }
        if (((DAT_0045b0a0 != 0 && param_1[0x27] == 0 && DAT_0045b0ac != 0) ||
             (DAT_0045b0a4 != 0 && param_1[0x27] == 2 && DAT_0045b0a8 != 0))) {
            ppGVar2 = (int *)FUN_004195D0(0xea, param_1[0x1e], param_1[0x1f], param_1[3]);
            if (ppGVar2 != 0) {
                ppGVar2[0x14] = 2;
                ppGVar2[0x15] = 0;
                pGVar1 = param_1[0x1b];
                ppGVar2[0x1b] = pGVar1;
                ppGVar2[0x1b] = pGVar1 | 0x200000;
                FUN_00419BE0(ppGVar2, param_1);
            }
            param_1[0x15] = 0;
            FUN_004372F0(param_1);
            DAT_0045b0a8 = (DAT_0045b0a4 == 0);
            DAT_0045b0ac = (DAT_0045b0a8 == 0);
            DAT_0045b0a4 = 0;
            DAT_0045b0a0 = 0;
        }
    } else {
        FUN_00430E20(param_1);
        if (DAT_0045b130 != 0) {
            DAT_0045b130 = 0;
            param_1[0x14] = 1;
            param_1[0x15] = 0;
            return;
        }
    }
}
}
