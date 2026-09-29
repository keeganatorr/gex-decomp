extern "C" {
extern "C" void __cdecl FUN_004335F0(void**, int);

extern "C" { extern void* PTR_0049fb98; }
extern "C" { extern int DAT_0049fba0[]; }
extern "C" { extern void** DAT_0045b09c; }
extern "C" { extern int DAT_0045b130; }

extern "C" void __cdecl ob234Init_004313d0(void** param_1)
{
    int pGVar1;
    int pNVar2;
    int iVar3;
    int iVar4;
    int* piVar5;

    if (param_1[0x26] == (void*)0x400) {
        FUN_004335F0(param_1, 0);
        pGVar1 = (int)param_1[3];
        pNVar2 = *(int*)(pGVar1 + 4);
        if (pNVar2 != 0 && (pNVar2 = *(int*)pNVar2, pNVar2 != 0)) {
            PTR_0049fb98 = (void*)*(int*)(pNVar2 + 4);
            piVar5 = DAT_0049fba0;
            iVar4 = 8;
            do {
                iVar3 = *(int*)(*(int*)(*(int*)(pGVar1 + 4)) + iVar4);
                if (iVar3 != 0) {
                    *piVar5 = iVar3;
                }
                piVar5 = piVar5 + 8;
                iVar4 = iVar4 + 4;
            } while (iVar4 < 0x20);
        }
        DAT_0045b09c = param_1;
        param_1[0x38] = (void*)((unsigned int)param_1[0x38] | 0x40);
        DAT_0045b130 = 0;
        return;
    }
    if (param_1[0x26] == (void*)0x80) {
        param_1[0x14] = (void*)0;
        param_1[0x15] = (void*)0x1;
        ((int*)param_1)[0x38] |= 0x10;
    }
}
}
