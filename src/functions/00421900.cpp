extern "C" {
extern "C" int __cdecl FUN_00419C00(void**, int, int, int*, int*);
extern "C" unsigned int __cdecl FUN_0041B140(int, int);

extern "C" unsigned int __cdecl GEX_Target(void** param_1)
{
    unsigned int result = 0;
    int local_4, local_8;
    if (FUN_00419C00(param_1, 0, 0, &local_4, &local_8) != 0) {
        result = FUN_0041B140((int)param_1[0x1e] + local_4, (int)param_1[0x1f] + local_8);
    }
    if (FUN_00419C00(param_1, 3, 0, &local_4, &local_8) != 0) {
        result |= FUN_0041B140((int)param_1[0x1e] + local_4, (int)param_1[0x1f] + local_8);
    }
    if (FUN_00419C00(param_1, 3, 1, &local_4, &local_8) != 0) {
        result |= FUN_0041B140((int)param_1[0x1e] + local_4, (int)param_1[0x1f] + local_8);
    }
    return result;
}
}
