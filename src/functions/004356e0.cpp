extern "C" {
extern int DAT_0045b7d8_framecount_;
extern void __cdecl FUN_0041A340(void** param_1, int param_2);
extern void __cdecl FUN_00422470_EatObjects(void** param_1);

void __cdecl ob2Clid_004356e0(void** param_1, int* param_2)
{
    int iVar1;
    void* pGVar2;
    int iVar2;

    if (*param_2 != 0) {
        iVar2 = ((int*)param_1[0x5d])[0] & 0xffff;
        if (param_1[0x1c] == 0 && iVar2 == 1) {
            param_1[0x1c] = (void*)1;
            iVar1 = *((int*)&DAT_0045b7d8_framecount_ + (int)param_1[0x26]);
            param_1[0x15] = 0;
            param_1[0x14] = (void*)(iVar1 + 0xb);
            param_1[0x27] = 0;
            FUN_0041A340(param_1, 0x90);
            pGVar2 = param_1[2];
            param_1[2] = (void*)0x130;
            FUN_00422470_EatObjects(param_1);
            param_1[2] = pGVar2;
        }
    }
}
}
