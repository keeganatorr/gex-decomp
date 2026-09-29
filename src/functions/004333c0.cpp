extern "C" {
int __cdecl FUN_0040FCE0(void**);
void __cdecl FUN_0040F260(void**);
void __cdecl FUN_0040F2A0(void**);
unsigned int __cdecl FUN_00431900_Movement_unk(void**);
void __cdecl FUN_00433370_Stub(void**);
void __cdecl FUN_00419520(void**);

void __cdecl ob369DoIt_004333c0(void** param1) {
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
        FUN_0040F260(param1);
        FUN_0040F2A0(param1);
        unsigned int uVar3 = FUN_00431900_Movement_unk(param1);
        if (uVar3 != 0) {
            FUN_00433370_Stub(param1);
            FUN_00419520(param1);
        }
        pGVar1 = (void*)((int)param1[0x26] + 1);
        param1[0x26] = pGVar1;
        if ((int)pGVar1 >= 2) {
            param1[0x26] = 0;
            param1[0x15] = (void*)((int)param1[0x15] + 1);
        }
        param1[0x27] = (void*)((int)param1[0x27] - 1);
    }
    if (param1[0x45] == (void*)-1) param1[0x44] = 0;
    param1[0x45] = (void*)-1;
}
}
