// Adapted from pc_decomp_backup/src/functions/FUN_00418E30.cpp
// Historical source SHA256: 195786fc2c39afa9bb10ad1d69432881e30a396699d481ee39873048df23de0b
extern "C" {
extern "C" unsigned int __cdecl FUN_00417F40(unsigned int**);
extern "C" void __cdecl FUN_0043F490(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

extern "C" unsigned int* __cdecl GEX_Target(unsigned int* param_1)
{
    unsigned char* pbVar3;
    unsigned char* pbVar2;
    unsigned int uVar1;
    unsigned int local_c;
    unsigned int local_8;
    unsigned int local_4;

    uVar1 = FUN_00417F40(&param_1);
    local_4 = (unsigned int)*(unsigned char*)param_1;
    local_8 = (unsigned int)*(unsigned char*)((int)param_1 + 1);
    pbVar3 = (unsigned char*)((int)param_1 + 3);
    local_c = (unsigned int)*(unsigned char*)((int)param_1 + 2);
    pbVar2 = (unsigned char*)((int)param_1 + 5);
    FUN_0043F490(uVar1, local_4, local_8, local_c, (unsigned int)*pbVar3, (unsigned int)*(unsigned char*)((int)param_1 + 4), (unsigned int)*pbVar2);
    return (unsigned int*)((int)param_1 + 6);
}
}
