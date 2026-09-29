extern "C" {
extern int DAT_004642A8;
extern int DAT_004642AC;
extern int DAT_004642B0;
extern int FUN_004A2AC8;
int __cdecl FUN_0040FCE0(void**);
void __cdecl FUN_00419A80(void**);

void __cdecl CollectibleDoIt_00435ba0(void** param_1)
{
    void* pGVar1;
    int iVar2;
    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    param_1[0x38] = (void*)(((((int)param_1[0x38] * 2) ^ (unsigned int)param_1[0x38]) & 0x200) ^ (unsigned int)param_1[0x38]);
    param_1[0x38] = (void*)((unsigned int)param_1[0x38] & 0xfffffeff);
    iVar2 = FUN_0040FCE0(param_1);
    if (iVar2 == 0) {
        if (DAT_004642A8 != FUN_004A2AC8) {
            iVar2 = DAT_004642AC;
            DAT_004642A8 = FUN_004A2AC8;
            if (iVar2 > 0) {
                --iVar2;
                DAT_004642AC = iVar2;
                if (iVar2 == 0)
                    DAT_004642B0 = 0;
            }
        }
        if (param_1[0x27] == 0) {
            iVar2 = (int)param_1[0x26] - 1;
            param_1[0x26] = (void*)iVar2;
            if (iVar2 < 0) {
                param_1[0x26] = (void*)2;
                pGVar1 = param_1[0x15];
                param_1[0x15] = (void*)((int)pGVar1 + 1);
            }
        } else {
            pGVar1 = param_1[0x15];
            if (pGVar1 == (void*)11) {
                FUN_00419A80(param_1);
            } else {
                param_1[0x15] = (void*)((int)pGVar1 + 1);
            }
        }
    }
    if (param_1[0x45] == (void*)-1)
        param_1[0x44] = 0;
    param_1[0x45] = (void*)-1;
}
}
