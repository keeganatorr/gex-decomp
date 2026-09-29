extern "C" void __cdecl FUN_00434190(int *param_1, int param_2) {
    int cVar1;
    int cVar2;
    int pGVar4;
    int iVar5;
    unsigned int uVar6;
    int pGVar7;
    int iVar8;

    pGVar4 = param_1[0x2a];
    if (param_2 != 0) {
        uVar6 = (unsigned int)param_1[0x2d] & 8;
        do {
            cVar1 = *(signed char *)pGVar4;
            if (uVar6 != 0) {
                cVar2 = *(signed char *)(pGVar4 + 1);
                pGVar4 = pGVar4 - 2;
            }
            else {
                cVar2 = *(signed char *)(pGVar4 + 1);
                pGVar4 = pGVar4 + 2;
            }
            if ((char)cVar1 == -0x7f) {
                param_1[0x38] = param_1[0x38] | 0x20;
                pGVar4 = param_1[0x29];
                if (uVar6 != 0) {
                    pGVar7 = pGVar4 + *(unsigned short *)pGVar4;
                    cVar1 = *(signed char *)pGVar7;
                    cVar2 = *(signed char *)(pGVar7 + 1);
                    pGVar4 = pGVar7 - 2;
                }
                else {
                    cVar1 = *(signed char *)(pGVar4 + 4);
                    cVar2 = *(signed char *)(pGVar4 + 5);
                    pGVar7 = pGVar4 + 4;
                    pGVar4 = pGVar7 + 2;
                }
                if ((param_1[0x2d] & 1) != 0) {
                    param_1[0x2a] = pGVar7;
                    param_1[0x1d] = param_1[0x1c] + 1;
                    return;
                }
            }
            iVar5 = cVar1 * 0x2000000;
            iVar8 = cVar2 * 0x2000000;
            if (uVar6 != 0) {
                iVar5 = -iVar5;
                iVar8 = -iVar8;
            }
            param_1[0x1e] = param_1[0x1e] + (iVar5 >> 9);
            param_2 = param_2 + -1;
            param_1[0x1f] = param_1[0x1f] + (iVar8 >> 9);
        } while (param_2 != 0);
    }
    param_1[0x2a] = pGVar4;
}
