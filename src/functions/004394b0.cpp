// Adapted from pc_decomp_backup/src/functions/FUN_004394B0.cpp
// Historical source SHA256: e8af8e2c9470acc393295756bf1b225db3e5a09d4df812447766742773d0544c
extern "C" {
extern "C" int __cdecl FUN_00428C80(int);
extern "C" void** __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419BE0(void**, void**);
extern "C" void __cdecl FUN_00439460_HuntDiveInner();
extern "C" void __cdecl GEX_Target(void** param1) {
    int iVar1 = FUN_00428C80(2);
    if (iVar1 == 0) { iVar1 = FUN_00428C80(8); iVar1 *= -0x10000; }
    else { iVar1 = FUN_00428C80(8); iVar1 <<= 0x10; }
    int iVar2 = FUN_00428C80(2);
    if (iVar2 == 0) { iVar2 = FUN_00428C80(8); iVar2 *= -0x10000; }
    else { iVar2 = FUN_00428C80(8); iVar2 <<= 0x10; }
    void** ppGVar3 = FUN_004195D0(0x13b, (int)param1[0x1e] + iVar2 + -0x1c, (int)param1[0x1f] + iVar1 + -0x1c, (int)param1[3]);
    if (ppGVar3 != 0) {
        ppGVar3[0x17] = (void*)FUN_00439460_HuntDiveInner;
        iVar1 = FUN_00428C80(2);
        void* pGVar4;
        if (iVar1 == 0) { iVar1 = FUN_00428C80(0x50000); pGVar4 = (void*)-iVar1; }
        else { pGVar4 = (void*)FUN_00428C80(0x50000); }
        ppGVar3[0x20] = pGVar4;
        iVar1 = FUN_00428C80(2);
        if (iVar1 == 0) { iVar1 = FUN_00428C80(0x50000); pGVar4 = (void*)-iVar1; }
        else { pGVar4 = (void*)FUN_00428C80(0x50000); }
        ppGVar3[0x23] = pGVar4;
        ppGVar3[0x14] = (void*)3;
        FUN_00419BE0(ppGVar3, param1);
    }
}
}
