extern "C" {
extern "C" int __cdecl FUN_0041CB80(void**, int*);

extern "C" void __cdecl FUN_00434a60(void** param_1, void** param_2)
{
    int local_50[10];
    int local_28[10];
    int iVar2;

    iVar2 = FUN_0041CB80(param_1, local_50);
    if (iVar2 != 0) {
        iVar2 = FUN_0041CB80(param_2, local_28);
        if (iVar2 != 0) {
            if ((int)param_2[0x1e] < (int)param_1[0x1e]) {
                param_2[0x1e] = (void*)((local_50[6] - local_28[7]) + (int)param_2[0x1e]);
                return;
            }
            param_2[0x1e] = (void*)((local_50[7] - local_28[6]) + (int)param_2[0x1e]);
        }
    }
}
}
