// Adapted from pc_decomp_backup/src/functions/FUN_00434570.cpp
// Historical source SHA256: c1eb1243f167393c6f242ae00eff5796a1e8d3edbd4ef110769566840ae8d707
extern "C" {
extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" { extern int DAT_0045B608; }
extern "C" { extern int DAT_0045B618; }
extern "C" void __cdecl GEX_Target(void** param1) {
    param1[0x35] = param1[0x1e];
    param1[0x36] = param1[0x1f];
    param1[0x3f] = param1[0x1b];
    param1[0x3d] = param1[0x14];
    param1[0x3e] = param1[0x15];
    param1[0x39] = 0;
    void* pGVar1 = param1[0x38];
    param1[0x3a] = 0;
    param1[0x3b] = 0;
    param1[0x3c] = 0;
    pGVar1 = (void*)((((int)pGVar1 * 2 ^ (unsigned int)pGVar1) & 0x200) ^ (unsigned int)pGVar1);
    param1[0x38] = pGVar1;
    param1[0x38] = (void*)((unsigned int)pGVar1 & 0xfffffeff);
    int iVar2 = FUN_0040FCE0(param1);
    if (iVar2 == 0) {
        if ((int)param1[0x1d] < 0) {
            ((void (*)(void**))*(int*)((int)&DAT_0045B618 + (int)param1[0x1c] * 4))(param1);
        } else {
            ((void (*)())*(int*)((int)&DAT_0045B608 + (int)param1[0x1d] * 4))();
            param1[0x1d] = (void*)-1;
        }
        pGVar1 = (void*)((int)param1[0x23] + (int)param1[0x26] + -0x28);
        param1[0x23] = pGVar1;
        if ((int)pGVar1 > 0x10000) {
            param1[0x23] = (void*)((int)pGVar1 + -0x80);
            param1[0x15] = (void*)((int)param1[0x15] + 1);
        }
    }
    if (param1[0x45] == (void*)-1) param1[0x44] = 0;
    param1[0x45] = (void*)-1;
}
}
