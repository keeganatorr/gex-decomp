// Adapted from pc_decomp_backup/src/functions/FUN_00419200.cpp
// Historical source SHA256: de4a79eb3407795b499d6cd628dbf3c2ab8c81931a1cd9f623bdd5c9f53c76c6
extern "C" {
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;

extern "C" unsigned int __cdecl FUN_00417F00(unsigned char **);
extern "C" int __cdecl FUN_00419C00(int *, int, int, int *, int *);
extern "C" void __cdecl FUN_00443AE0(int *, int, int, int, int, int, int, int, int, int);

extern "C" unsigned char *__cdecl GEX_Target(unsigned char *param_1, int *param_2)
{
    unsigned int local_48, local_44, uVar4, uVar5;
    int local_50, local_4c;
    int saved_14, saved_15;
    int local_40, local_3c;
    int local_38, local_34;
    int local_20[4];
    int local_30[4];
    int local_10[4];
    int ebp;
    int i, iVar6;
    int *ppGVar3;
    int pGVar2;
    int *puVar1;
    int *puVar7;
    int pGVar8;
    unsigned char *p;

    ppGVar3 = param_2;
    saved_14 = param_2[0x14];
    saved_15 = param_2[0x15];
    local_40 = (int)*param_1;
    local_3c = (int)param_1[1];
    p = param_1 + 2;

    local_48 = FUN_00417F00(&p);
    local_44 = FUN_00417F00(&p);
    uVar4 = FUN_00417F00(&p);
    uVar5 = FUN_00417F00(&p);

    local_10[0] = (int)p[0];
    local_10[1] = (int)p[1];
    local_10[2] = (int)p[2];
    local_10[3] = (int)p[3];
    p = p + 5;

    ebp = 0;
    do {
        iVar6 = FUN_00419C00(ppGVar3, *(int *)((int)local_10 + ebp), 0, &local_50, &local_4c);
        if (iVar6 != 0) {
            pGVar2 = ppGVar3[0x57];
            puVar1 = (int *)((int)local_20 + ebp);
            if (pGVar2 == 0) {
                pGVar8 = ppGVar3[0x1f];
                *puVar1 = (int)ppGVar3[0x1e] + local_50;
            } else {
                pGVar8 = *(int *)(pGVar2 + 0x7c);     
                *puVar1 = *(int *)(pGVar2 + 0x78) + local_50;  
            }
            puVar7 = (int *)((int)local_30 + ebp);
            *puVar7 = pGVar8 + local_4c;

            if (*puVar1 < (int)local_48) *puVar1 = local_48;
            if ((int)uVar4 < *puVar1) *puVar1 = uVar4;
            if (*puVar7 < (int)local_44) *puVar7 = local_44;
            if ((int)uVar5 < *puVar7) *puVar7 = uVar5;

            *puVar1 = *puVar1 - CAMERA_XPos_004a2a38;
            *puVar7 = *puVar7 - CAMERA_YPos_004a2a1c;
        }
        ebp = ebp + 4;
    } while (ebp < 0x10);

    ppGVar3[0x14] = local_40;
    ppGVar3[0x15] = local_3c;
    FUN_00443AE0(ppGVar3, 0, local_20[0], local_30[0], local_20[1], local_30[1], local_20[2], local_30[2], local_20[3], local_30[3]);
    ppGVar3[0x14] = saved_14;
    ppGVar3[0x15] = saved_15;
    return p;
}
}
