// Adapted from pc_decomp_backup/src/functions/FUN_0041E720.cpp
// Historical source SHA256: 012b49ac6b76e3ac76604d0fb670096a41ac3b864467920fd135ce1a93287eac
extern "C" {
extern "C" { extern int DAT_004594F8; }
extern "C" int __cdecl FUN_0041E190(void**, void*);

extern "C" void __cdecl GEX_Target(int param_1, int** param_2)
{
    int* piVar7;
    int* piVar1;
    int iVar2;
    int* piVar3;
    unsigned int* puVar9;

    piVar7 = *param_2;
    piVar1 = param_2[2];
    if (param_1 >= 0xc) return;
    puVar9 = (unsigned int*)((int)&DAT_004594F8 + param_1 * 4);
    int* list = (int*)(0x00463698 + param_1 * 12);
    do {
        if (((1 << (param_1 & 0x1f)) & *puVar9) != 0) {
            iVar2 = *piVar7;
            while (iVar2 != 0) {
                piVar3 = (int*)piVar7[2];
                piVar7 = (int*)*piVar7;
                if (piVar3 != (int*)0x0 && piVar1 != piVar3) {
                    void (*pcVar4)(int*, int*) = (void (*)(int*, int*))piVar3[0x5b];
                    int* piVar5 = piVar3;
                    int* piVar6 = piVar1;
                    if (pcVar4 == (void (*)(int*, int*))&FUN_0041E190) {
                        pcVar4 = (void (*)(int*, int*))piVar1[0x5b];
                        piVar5 = piVar1;
                        piVar6 = piVar3;
                    }
                    if (pcVar4 != (void*)0x0) {
                        pcVar4(piVar5, piVar6);
                    }
                }
                iVar2 = *piVar7;
            }
        }
        puVar9 = puVar9 + 1;
        list += 3;
        if ((int)puVar9 < 0x459525) {
            piVar7 = (int*)list[0];
        }
    } while ((int)puVar9 < 0x459525);
}
}
