// Adapted from pc_decomp_backup/src/functions/FUN_00421560.cpp
// Historical source SHA256: d280e3c9ff78020a294474d6689e92695a58a0c4207f444919457bf26163636f
extern "C" {
extern "C" int __cdecl FUN_0041A160(void*, void**);

extern "C" int __cdecl FUN_00421560_DrawCharacter(void* param_1, void** param_2)
{
    int bVar2;
    int iVar4;
    void* pGVar1;
    void* pGVar5;

    bVar2 = 0;
    iVar4 = 0x80000;
    pGVar1 = param_2[0x1f];
    pGVar5 = param_2[0x36];
    if ((int)pGVar1 <= (int)pGVar5) {
        iVar4 = -0x80000;
    }
    do {
        pGVar5 = (void*)((int)pGVar5 + iVar4 - 0x1c);
        if (iVar4 < 0) {
            if ((int)pGVar5 < (int)pGVar1) {
                bVar2 = 1;
                pGVar5 = pGVar1;
            }
        } else if ((int)pGVar1 < (int)pGVar5) {
            bVar2 = 1;
            pGVar5 = pGVar1;
        }
        param_2[0x1f] = pGVar5;
        int result = FUN_0041A160(param_1, param_2);
        if (result != 0 || bVar2 != 0) {
            return result;
        }
    } while (1);
}
}
