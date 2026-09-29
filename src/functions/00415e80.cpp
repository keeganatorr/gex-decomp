// Adapted from pc_decomp_backup/src/functions/FUN_00415E80.cpp
// Historical source SHA256: 2447da9aa3f697b95b5ad19f090b70f6dd7aabd5a7bd1594d1a83a9d3ba46540
// Behavior candidate; original bytes are not claimed to match.

extern int DAT_004594A0;
extern int DAT_004594A4;
extern int DAT_004594A8;
extern int DAT_00459498;
extern int DAT_0045A6E0;
extern int DAT_004A0224;
extern int DAT_004A0254;
extern int DAT_004A284C;
extern int DAT_004A2850;
extern int DAT_004A27F8;
extern int DAT_00462E38;
extern int DAT_004A2878;
extern int DAT_004A2870;
extern int DAT_004A2828;
extern int DAT_00462E78;
extern int DAT_004A0264;
extern int DAT_004A2804;
extern int DAT_004A2824;
extern int DAT_004A2880;
extern int DAT_004A2890;
extern int DAT_004A2858;
extern int DAT_004A27F0;
extern int DAT_004A2814;
extern int DAT_004A2874;
extern int DAT_00458960;
extern int DAT_004630D8;
extern int DAT_004630DC;
extern int DAT_00457210;
extern int DAT_004A028F;
extern int FUN_004A281C;
extern int FUN_00455C4C;
extern int FUN_004577B0;
extern int FUN_004A2964;

extern "C" void __cdecl FUN_00422360(int);
extern "C" void __cdecl FUN_00415C10(int*);
extern "C" int __cdecl FUN_00428C80(int);
extern "C" void __cdecl FUN_0041F8C0(int);
extern "C" int __cdecl FUN_0041A480(int);
extern "C" void __cdecl FUN_00415BB0();
extern "C" int __cdecl FUN_00419C00(int*, int, int, int*, int*);
extern "C" void __cdecl FUN_0041E880(int*, int*);

extern "C" void __cdecl PlayerDoIt_00415e80(int* param_1)
{
    int pGVar1;
    int iVar2;
    int _local_save[2];
    int* _lp = _local_save;
    int _param = (int)param_1;
    int local_8, local_4;

    _lp[0] = _param;

    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    _lp[0] = 0;
    _lp[1] = 0;
    pGVar1 = param_1[0x38];
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    pGVar1 = (int)(((pGVar1 * 2) ^ (unsigned int)pGVar1) & 0x200 ^ (unsigned int)pGVar1);
    param_1[0x38] = pGVar1;
    param_1[0x38] = (int)((unsigned int)pGVar1 & 0xfffffeff);
    iVar2 = DAT_004594A8;
    DAT_004A284C = 0;
    DAT_004A27F8 = 0;

    if ((FUN_00455C4C != 0) || (DAT_004A2878 != 0)) {
        // goto FUN_004160BD
        goto after_eat;
    }

    if ((FUN_004A2964 != 0x44) && (FUN_004A281C <= 0)) return;
    if (DAT_00462E38 != 0) return;

    if (DAT_004A2850 == 0) {
        if (DAT_00459498 != -1) {
            DAT_004A0224 = DAT_00459498;
            DAT_0045A6E0 = -1;
            DAT_00459498 = -1;
            goto eat_done;
        }
    } else {
        DAT_004A2850 = 0;
        if (DAT_004594A0 >= 0) {
            DAT_004A0224 = DAT_004594A0;
            DAT_004594A0 = DAT_004594A4;
            DAT_004594A8 = -1;
            DAT_004594A4 = iVar2;
eat_done:
            DAT_004A0254 = 1;
            FUN_00422360((int)param_1);
        }
    }

    // More Collision check
    if ((DAT_004A2870 != 0) && (DAT_004A2828 == 0) && ((int)param_1[0x23] >= 0)) {
        DAT_004A2828 = 1;
        if (((int)param_1[0x1c] < 3) || (5 < (int)param_1[0x1c])) {
            param_1[0x1d] = 0x53;
        } else {
            param_1[0x1d] = 0x54;
        }
    }

    if (DAT_00462E78 < 0) {
        DAT_00462E78 = 100;
        iVar2 = FUN_00428C80(7);
        FUN_0041F8C0(*(int*)((int)&DAT_00458960 + iVar2 * 4));
    } else {
        DAT_00462E78 = DAT_00462E78 + -1;
    }

    FUN_00415C10(param_1);

    if ((DAT_004A0264 != 0) && ((*(int*)((int)&DAT_00457210 + (int)param_1[0x1c] * 4) & 1) != 0)) {
        iVar2 = FUN_0041A480((int)param_1);
        if (iVar2 == 0) {
            param_1[0x15] = 0;
        }
        *(unsigned char*)((int)&DAT_004A028F) = 0;
        // Clear input buttons
        DAT_004A2870 = 0;
    }

after_eat:
    DAT_004A2804 = param_1[0x1c];

    DAT_004A2874 = 0;
    DAT_004A2814 = 0;
    DAT_004A27F0 = 0;
    DAT_004A2824 = 0;
    DAT_004A2880 = 0;
    DAT_004A2890 = 0;
    DAT_004A2858 = (unsigned int)((*(int*)((int)&DAT_00457210 + (int)param_1[0x1c] * 4) & 0xf0000000) == 0x30000000);

    if (DAT_004A284C == 0) {
        if (*(int*)((int)&DAT_004630D8 + 0x60 * 4) != 0) {
            FUN_0041E880((int*)&DAT_004630D8, 0);
            if (*(int*)((int)&DAT_004630DC + 0x60 * 4) != 0) {
                FUN_0041E880((int*)&DAT_004630DC, 0);
            }
        }
    } else {
        iVar2 = FUN_00419C00(param_1, 0, 0, &local_8, &local_4);
        if (iVar2 != 0) {
            if (*(int*)((int)&DAT_004630D8 + 0x60 * 4) == 0) {
                FUN_0041E880((int*)&DAT_004630D8, (int*)2);
            }
            *(int*)((int)&DAT_004630D8 + 0x1e * 4) = (int)(*(int*)((int)param_1[0x1e] + 8) + local_8 + -0x1c);
            *(int*)((int)&DAT_004630D8 + 0x1f * 4) = (int)(*(int*)((int)param_1[0x1f] + 8) + local_4 + -0x1c);
        }
        iVar2 = FUN_00419C00(param_1, 0, 1, &local_8, &local_4);
        if (iVar2 != 0) {
            if (*(int*)((int)&DAT_004630DC + 0x60 * 4) == 0) {
                FUN_0041E880((int*)&DAT_004630DC, (int*)2);
            }
            *(int*)((int)&DAT_004630DC + 0x1e * 4) = (int)(*(int*)((int)param_1[0x1e] + 8) + local_8 + -0x1c);
            *(int*)((int)&DAT_004630DC + 0x1f * 4) = (int)(*(int*)((int)param_1[0x1f] + 8) + local_4 + -0x1c);
        }
    }

    DAT_004A2870 = 0;
}
