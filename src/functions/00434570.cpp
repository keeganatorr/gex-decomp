extern "C" {
int __cdecl FUN_0040FCE0(void**);
extern int DAT_0045B608;
extern int DAT_0045B618;

void __cdecl PlatformDoIt_00434570(void** param1) {
    param1[0x35] = param1[0x1e];
    param1[0x36] = param1[0x1f];
    param1[0x3f] = param1[0x1b];
    param1[0x3d] = param1[0x14];
    param1[0x3e] = param1[0x15];
    param1[0x39] = 0;
    param1[0x3a] = 0;
    param1[0x3b] = 0;
    param1[0x3c] = 0;
    param1[0x38] = (void*)((((unsigned int)param1[0x38] * 2 ^ (unsigned int)param1[0x38]) & 0x200) ^ (unsigned int)param1[0x38]);
    param1[0x38] = (void*)((unsigned int)param1[0x38] & 0xfffffeff);
    int iVar2 = FUN_0040FCE0(param1);
    if (iVar2 == 0) {
        if ((int)param1[0x1d] >= 0) {
            ((void (__cdecl *)(void**))*(int*)((int)&DAT_0045B608 + (int)param1[0x1d] * 4))(param1);
            param1[0x1d] = (void*)-1;
        } else {
            ((void (__cdecl *)(void**))*(int*)((int)&DAT_0045B618 + (int)param1[0x1c] * 4))(param1);
        }
        void* pGVar1 = (void*)((int)param1[0x23] + (int)param1[0x26]);
        param1[0x23] = pGVar1;
        if ((int)pGVar1 > 0x10000) {
            param1[0x23] = (void*)((int)pGVar1 - 0x10000);
            param1[0x15] = (void*)((int)param1[0x15] + 1);
        }
    }
    if (param1[0x45] == (void*)-1) param1[0x44] = 0;
    param1[0x45] = (void*)-1;
}
}
