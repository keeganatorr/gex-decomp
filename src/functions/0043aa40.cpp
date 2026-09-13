// Adapted from pc_decomp_backup/src/functions/FUN_0043AA40.cpp
// Historical source SHA256: 88cd33e95c9dcb9aa005c02a28a699f0add7eeb6cc4230c417291d745dfa36c9
extern "C" {
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;

extern "C" int __cdecl FUN_0041CB80(void **obj, int **arr);
extern "C" void __cdecl FUN_00443AE0(void **param_1, int flag, int a, int b, int c, int d, int e, int f, int g, int h);

extern "C" void __cdecl GEX_Target(void **param_1)
{
    int iVar3;
    unsigned int uVar4;
    int iVar5;
    int iVar6;
    int **ppiVar7;
    int *local_28[6];
    int local_10;
    int local_c;
    int local_8;
    int local_4;
    int *local_50[6];
    int local_38;
    int local_34;
    int local_30;
    int local_2c;
    int pGVar1;
    int pGVar2;

    pGVar1 = (int)param_1[0x1e];
    iVar6 = (int)param_1[0x1f] - CAMERA_YPos_004a2a1c;
    iVar3 = -0xa00000 - CAMERA_XPos_004a2a38;
    pGVar2 = (int)param_1[0x27];
    if (param_1[0x26] == (void *)0x0) {
        ppiVar7 = local_28;
        for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
            *ppiVar7 = (int *)0x0;
            ppiVar7 = ppiVar7 + 1;
        }
    }
    else {
        FUN_0041CB80((void **)param_1[0x26], local_28);
    }
    if (pGVar2 == 0) {
        ppiVar7 = local_50;
        for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
            *ppiVar7 = (int *)0x0;
            ppiVar7 = ppiVar7 + 1;
        }
    }
    else {
        FUN_0041CB80((void **)pGVar2, local_50);
    }
    if (iVar6 == 0x780000 || iVar6 + -0x780000 < 0) {
        uVar4 = local_2c - CAMERA_YPos_004a2a1c;
        iVar6 = local_4;
    }
    else {
        uVar4 = local_30 - CAMERA_YPos_004a2a1c;
        iVar6 = local_8;
    }
    FUN_00443AE0(param_1, 0,
        local_10 - CAMERA_XPos_004a2a38, iVar6 - CAMERA_YPos_004a2a1c,
        local_c - CAMERA_XPos_004a2a38, iVar6 - CAMERA_YPos_004a2a1c,
        local_34 - CAMERA_XPos_004a2a38, uVar4,
        local_38 - CAMERA_XPos_004a2a38, uVar4);
    if (0 < pGVar1 + iVar3) {
        FUN_00443AE0(param_1, 1,
            local_10 - CAMERA_XPos_004a2a38, local_8 - CAMERA_YPos_004a2a1c,
            local_38 - CAMERA_XPos_004a2a38, local_30 - CAMERA_YPos_004a2a1c,
            local_38 - CAMERA_XPos_004a2a38, local_2c - CAMERA_YPos_004a2a1c,
            local_10 - CAMERA_XPos_004a2a38, local_4 - CAMERA_YPos_004a2a1c);
        return;
    }
    FUN_00443AE0(param_1, 1,
        local_c - CAMERA_XPos_004a2a38, local_8 - CAMERA_YPos_004a2a1c,
        local_34 - CAMERA_XPos_004a2a38, local_30 - CAMERA_YPos_004a2a1c,
        local_34 - CAMERA_XPos_004a2a38, local_2c - CAMERA_YPos_004a2a1c,
        local_c - CAMERA_XPos_004a2a38, local_4 - CAMERA_YPos_004a2a1c);
}
}
