// Adapted from pc_decomp_backup/src/functions/FUN_0042FF10.cpp
// Historical source SHA256: cdfce3507699d57e207bbe44ea19c81e04f78285b1600fc2a56ad66831b8c9f5
extern "C" {
extern "C" { extern int DAT_0049fc60; }
extern "C" { extern void** FUN_004A27FC; }
extern "C" { extern int DAT_004a2a04; }
extern "C" { extern int DAT_0049fba0; }
extern "C" { extern int PTR_00463d80; }
extern "C" { extern int DAT_0045b124; }
extern "C" { extern int DAT_0045b120; }
extern "C" { extern int DAT_00458c84; }
extern "C" { extern int DAT_00458c80; }
extern "C" { extern int DAT_00458c7c; }
extern "C" { extern int DAT_00463e10; }
extern "C" { extern int DAT_00463d78; }
extern "C" { extern int PTR_00463d7c; }
extern "C" { extern int DAT_0045b0a0; }
extern "C" { extern int DAT_0045b0ac; }
extern "C" { extern int DAT_0045b0a4; }
extern "C" { extern int DAT_0045b0a8; }
extern "C" { extern int DAT_0045b12c; }
extern "C" { extern int DAT_0045b114_zoomstate; }
extern "C" { extern int DAT_0045b098; }
extern "C" { extern int DAT_0045b09c; }
extern "C" { extern int DAT_004a2948; }
extern "C" { extern int DAT_0045b118; }
extern "C" { extern int DAT_0045b11c; }
extern "C" { extern int DAT_00463eb8; }
extern "C" { extern int DAT_004a2b00; }
extern "C" void __cdecl FUN_0043F490(int, int, int, int, int, int, int);

extern "C" void __cdecl GEX_Target(int param_1, int param_2) {
    int iVar1;
    int iVar2;
    int iVar3;

    if (*(int*)(param_1 + 0x98) == 0x40) {
        if (param_2 != 0) {
            PTR_00463d7c = 0;
            return;
        }
        iVar3 = *(int*)(param_1 + 0xc);
        {
            int* piVar5 = *(int**)(iVar3 + 4);
            if (piVar5 != (int*)0x0 && *piVar5 != 0) {
                piVar5 = &DAT_0049fc60;
                iVar2 = 0;
                do {
                    iVar1 = *(int*)(**(int**)(iVar3 + 4) + iVar2);
                    if (iVar1 != 0) {
                        *piVar5 = iVar1;
                    }
                    piVar5 = piVar5 + 8;
                    iVar2 = iVar2 + 4;
                } while (iVar2 < 0xa0);
            }
        }
        FUN_004A27FC[0x38] = (void*)((unsigned int)FUN_004A27FC[0x38] | 0x40);
        *(unsigned int*)(param_1 + 0xe0) = *(unsigned int*)(param_1 + 0xe0) | 0x40;
        DAT_004a2a04 = 0;
        {
            int* puVar4 = &DAT_0049fba0;
            int* puVar6 = (int*)(param_1 + 0x10);
            for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar6 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar6 = puVar6 + 1;
            }
        }
        *(unsigned int*)(param_1 + 0x6c) = *(unsigned int*)(param_1 + 0x6c) | 0x80000000;
        PTR_00463d80 = param_1;
        DAT_0045b124 = 0;
        DAT_0045b120 = 0;
        DAT_00458c84 = 0;
        DAT_00458c80 = 0;
        DAT_00458c7c = 0;
        DAT_00463e10 = 0;
        DAT_00463d78 = 0;
        PTR_00463d7c = 0;
        DAT_0045b0a0 = 1;
        DAT_0045b0ac = 1;
        DAT_0045b0a4 = 0;
        DAT_0045b0a8 = 0;
        DAT_0045b12c = 0;
        DAT_0045b114_zoomstate = 0;
        DAT_0045b098 = -1;
        DAT_0045b09c = 0;
        DAT_004a2948 = 1;
        DAT_0045b118 = 0x10000;
        DAT_0045b11c = 0x20000;
        DAT_00463eb8 = 6;
        if (DAT_004a2b00 == 0) {
            FUN_0043F490(1, 0, 0, 0, 0, 0, 0);
        }
    }
}
}
