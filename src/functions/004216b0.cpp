// Adapted from pc_decomp_backup/src/functions/FUN_004216B0.cpp
// Historical source SHA256: c30da33fc38092810f8648292b2003284339cd01917e5d9e2ee817462ff0d42e
extern "C" {
extern "C" { extern int DAT_004A2410; }
extern "C" void* __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419BE0(void*, void**);
extern "C" void __cdecl FUN_0041A340(void*, int);
extern "C" unsigned int __cdecl FUN_00420C10(unsigned int, unsigned int);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar3;
    unsigned int uVar4;
    void** ppGVar2;

    if (DAT_004A2410 != 0) {
        iVar3 = 0;
        uVar4 = (unsigned int)param_1[0x1f] & 0xffe00000;
        do {
            if ((FUN_00420C10((unsigned int)param_1[0x1e], uVar4) & 1) == 0) break;
            uVar4 = uVar4 - 0x200000;
            iVar3 = iVar3 + 1;
        } while (iVar3 < 3);
        if (iVar3 < 3) {
            ppGVar2 = (void**)FUN_004195D0(0x5c, (int)param_1[0x1e], uVar4 + 0x240000, DAT_004A2410);
            if (ppGVar2 != (void**)0x0) {
                ppGVar2[0x26] = (void*)0x3;
                ppGVar2[0x1c] = (void*)0x30;
                FUN_0041A340(ppGVar2, 0xfe);
                FUN_00419BE0(ppGVar2, param_1);
            }
        }
    }
}
}
