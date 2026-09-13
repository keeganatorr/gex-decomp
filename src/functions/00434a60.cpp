// Adapted from pc_decomp_backup/src/functions/FUN_00434A60.cpp
// Historical source SHA256: 7b1831429de815f9d352d4c0fddc1b26415c703916d2a560406b216fbd3ce53b
extern "C" {
extern "C" int __cdecl FUN_0041CB80(void**, int*);

extern "C" void __cdecl GEX_Target(void** param_1, void** param_2)
{
    int local_50[12];
    int local_28[8];
    int iVar2;

    iVar2 = FUN_0041CB80(param_1, local_50);
    if (iVar2 != 0) {
        iVar2 = FUN_0041CB80(param_2, local_28);
        if (iVar2 != 0) {
            if ((int)param_2[0x1e] < (int)param_1[0x1e]) {
                param_2[0x1e] = (void*)((local_50[8] - local_28[7]) + (int)param_2[0x1e]);
                return;
            }
            param_2[0x1e] = (void*)((local_50[9] - local_28[6]) + (int)param_2[0x1e]);
        }
    }
}
}
