// Adapted from pc_decomp_backup/src/functions/FUN_00428CF0.cpp
// Historical source SHA256: 7670edb1e7e9cbd7093c2ea9426b732e9faaf8d1040cd7da414774b7f0893476
extern "C" {
extern "C" void __cdecl GEX_Target(int *param_1)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    int local_c;

    iVar8 = *param_1;
    if (iVar8 < 0) {
        iVar8 = 0;
    }
    else if (0xfe < iVar8) {
        iVar8 = 0xff;
    }
    iVar5 = param_1[1];
    if (iVar5 < 0) {
        iVar5 = 0;
    }
    else if (0xfe < iVar5) {
        iVar5 = 0xff;
    }
    iVar6 = param_1[2];
    if (iVar6 < 0) {
        iVar6 = 0;
    }
    else if (0xfe < iVar6) {
        iVar6 = 0xff;
    }
    iVar7 = iVar6;
    if (iVar6 <= iVar5) {
        iVar7 = iVar5;
    }
    if (iVar7 <= iVar8) {
        iVar7 = iVar8;
    }
    iVar1 = iVar6;
    if (iVar5 <= iVar6) {
        iVar1 = iVar5;
    }
    if (iVar8 <= iVar1) {
        iVar1 = iVar8;
    }
    iVar2 = iVar7 - iVar1;
    if (iVar7 == 0) {
        local_c = 0;
    }
    else {
        local_c = (iVar2 * 0xff) / iVar7;
    }
    if (local_c == 0) {
        iVar8 = param_1[3];
        goto FUN_00428E35;
    }
    iVar3 = ((iVar7 - iVar8) * 0x100) / iVar2;
    iVar4 = ((iVar7 - iVar5) * 0x100) / iVar2;
    iVar2 = ((iVar7 - iVar6) * 0x100) / iVar2;
    if (iVar8 == iVar7) {
        if (iVar5 != iVar1) {
            iVar8 = 0x100;
            iVar3 = iVar4;
            goto FUN_00428E1D;
        }
        iVar2 = iVar2 + 0x500;
    }
    else if (iVar5 == iVar7) {
        if (iVar6 == iVar1) {
            iVar2 = iVar3 + 0x100;
        }
        else {
            iVar8 = 0x300;
            iVar3 = iVar2;
FUN_00428E1D:
            iVar2 = iVar8 - iVar3;
        }
    }
    else {
        if (iVar8 != iVar1) {
            iVar8 = 0x500;
            goto FUN_00428E1D;
        }
        iVar2 = iVar4 + 0x300;
    }
    iVar8 = (iVar2 * 0x168) / 0x600;
FUN_00428E35:
    param_1[3] = iVar8;
    param_1[5] = iVar7;
    param_1[4] = local_c;
}
}
