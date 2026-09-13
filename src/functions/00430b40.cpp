// Adapted from pc_decomp_backup/src/functions/FUN_00430B40.cpp
// Historical source SHA256: 5f5d4088b081710a659691b04fad819a574c6a1f6071f01a938d568b8e3fd1de
extern "C" {
extern "C" void** __cdecl FUN_0041A380(void**);
extern "C" int __cdecl FUN_00430990(int, int, int, int, int, int, int, int, int);
extern void** FUN_004A27FC;
extern "C" { extern int DAT_00463F04; }
extern "C" { extern int DAT_00463F0C; }
extern "C" { extern int DAT_00463F00; }
extern "C" { extern int DAT_00463F08; }
extern "C" int __cdecl GEX_Target() {
    void** ppGVar2 = FUN_0041A380(FUN_004A27FC);
    int pGVar8, pGVar6;
    if (((unsigned int)FUN_004A27FC[0x1b] & 0x80000000) == 0) {
        pGVar8 = (int)ppGVar2[2];
        pGVar6 = (int)ppGVar2[0];
    } else {
        pGVar8 = -(int)ppGVar2[0];
        pGVar6 = -(int)ppGVar2[2];
    }
    int iVar3 = FUN_00430990((int)FUN_004A27FC, (int)ppGVar2[1], (int)ppGVar2[3], pGVar6, pGVar8,
                            DAT_00463F04, DAT_00463F0C, DAT_00463F00, DAT_00463F08);
    if (iVar3 != 0) {
        pGVar8 = (int)ppGVar2[4];
        int pNVar5 = *(int*)(pGVar8);
        while (pNVar5 != (int)0x80000000) {
            int iVar3b, pNVar4, pGVar7;
            if (((unsigned int)FUN_004A27FC[0x1b] & 0x80000000) == 0) {
                pNVar5 = *(int*)(pGVar8);
                iVar3b = *(int*)(pGVar8 + 8);
            } else {
                pNVar5 = -*(int*)(pGVar8 + 8);
                iVar3b = -(int)*(int*)(pGVar8);
            }
            if (((unsigned int)FUN_004A27FC[0x1b] & 0x40000000) == 0) {
                pNVar4 = *(int*)(pGVar8 + 4);
                pGVar7 = *(int*)(pGVar8 + 0xc);
            } else {
                pNVar4 = -*(int*)(pGVar8 + 0xc);
                pGVar7 = -(int)*(int*)(pGVar8 + 4);
            }
            iVar3 = FUN_00430990((int)FUN_004A27FC, pNVar4, pGVar7, pNVar5, iVar3b,
                                DAT_00463F04, DAT_00463F0C, DAT_00463F00, DAT_00463F08);
            if (iVar3 != 0) return 1;
            pGVar8 = *(int*)(pGVar8 + 0x10);
            pNVar5 = *(int*)(pGVar8 + 0x14);
        }
    }
    return 0;
}
}
