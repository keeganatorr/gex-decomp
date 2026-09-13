// Adapted from pc_decomp_backup/src/functions/FUN_00435BA0.cpp
// Historical source SHA256: d741a3a69445b47165d39b6d38d8a92979fdb4f0f045ad75c865b690a70afe98
extern "C" {
extern "C" { extern int DAT_004642A8; }
extern "C" { extern int DAT_004642AC; }
extern "C" { extern int DAT_004642B0; }
extern "C" { extern int FUN_004A2AC8; }
extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" void __cdecl FUN_00419A80(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    void* pGVar1;
    int iVar2;

    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    pGVar1 = param_1[0x38];
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;

    pGVar1 = (void*)((((int)pGVar1 * 2) ^ (unsigned int)pGVar1) & 0x200 ^ (unsigned int)pGVar1);
    param_1[0x38] = pGVar1;
    param_1[0x38] = (void*)((unsigned int)pGVar1 & 0xfffffeff);

    iVar2 = FUN_0040FCE0(param_1);
    if (iVar2 == 0) {
        if (DAT_004642A8 != FUN_004A2AC8) {
            iVar2 = DAT_004642AC;
            DAT_004642A8 = FUN_004A2AC8;
            if (iVar2 > 0) {
                iVar2--;
                DAT_004642AC = iVar2;
                if (iVar2 == 0) {
                    DAT_004642B0 = 0;
                }
            }
        }

        if (param_1[0x27] != 0) {
            if ((int)param_1[0x15] == 0xb) {
                FUN_00419A80(param_1);
            } else {
                iVar2 = (int)param_1[0x15] + 1;
                param_1[0x15] = (void*)iVar2;
            }
        } else {
            iVar2 = (int)param_1[0x26];
            iVar2--;
            param_1[0x26] = (void*)iVar2;
            if (iVar2 < 0) {
                param_1[0x26] = (void*)2;
                iVar2 = (int)param_1[0x15] + 1;
                param_1[0x15] = (void*)iVar2;
            }
        }
    }

    if (param_1[0x45] == (void*)-1) {
        param_1[0x44] = 0;
    }
    param_1[0x45] = (void*)-1;
}
}
