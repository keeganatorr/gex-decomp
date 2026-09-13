// Adapted from pc_decomp_backup/src/functions/FUN_00421900.cpp
// Historical source SHA256: 7795dcc0247fcda74482e1d754ba05c2bfd41dc2b28854841b65cc253fcd1bff
extern "C" {
extern "C" int __cdecl FUN_00419C00(void**, int, int, int*, int*);
extern "C" unsigned int __cdecl FUN_0041B140(int, int);

extern "C" unsigned int __cdecl GEX_Target(void** param_1)
{
    unsigned int result = 0;
    int local_4, local_8;
    if (FUN_00419C00(param_1, 0, 0, &local_4, &local_8) != 0) {
        result = FUN_0041B140((int)param_1[0x1e] + local_4 - 0x1c, (int)param_1[0x1f] + local_8 - 0x1c);
    }
    if (FUN_00419C00(param_1, 3, 0, &local_4, &local_8) != 0) {
        result |= FUN_0041B140((int)param_1[0x1e] + local_4 - 0x1c, (int)param_1[0x1f] + local_8 - 0x1c);
    }
    if (FUN_00419C00(param_1, 3, 1, &local_4, &local_8) != 0) {
        result |= FUN_0041B140((int)param_1[0x1e] + local_4 - 0x1c, (int)param_1[0x1f] + local_8 - 0x1c);
    }
    return result;
}
}
