// Adapted from pc_decomp_backup/src/functions/FUN_0041E190.cpp
// Historical source SHA256: bdbfd8ee7e0ef2f5f5fd98c47edfaed8720db05d9627a9a17bab38b54bc039d6
extern "C" {
extern "C" { extern int DAT_0046368C; }
extern "C" { extern int DAT_00463734; }
extern "C" int __cdecl FUN_0041CB80(void**, int**);
extern "C" int __cdecl FUN_0041D310(void**, void*);
extern "C" int __cdecl FUN_0041DD50(void**, void*);

extern "C" int __cdecl GEX_Target(void** param_1, void* param_2)
{
    int iVar4;
    int boundsA[10];
    int boundsB[10];
    
    if (((((unsigned int)param_1[0x31] & 0x3f0000) != 0) || ((*(unsigned int*)((int)param_2 + 0xc4) & 0x3f0000) != 0)) ||
        (param_1[0x32] != (void*)0x10000) ||
        (param_1[0x33] != (void*)0x10000 || (*(int*)((int)param_2 + 200) != 0x10000)) ||
        (*(int*)((int)param_2 + 0xcc) != 0x10000)) {
        return FUN_0041D310(param_1, param_2);
    }
    if ((((unsigned int)((int)param_1[0x31] + 0x1000) & 0xc00000) != 0) ||
       ((*(unsigned int*)((int)param_2 + 0xc4) + 0x200000 & 0xc00000) != 0)) {
        return FUN_0041DD50(param_1, param_2);
    }
    DAT_00463734++;
    iVar4 = FUN_0041CB80(param_1, (int**)boundsA);
    if (iVar4 == 0) return 0;
    iVar4 = FUN_0041CB80((void**)param_2, (int**)boundsB);
    if (iVar4 != 0) {
        if ((boundsA[7] < boundsB[6]) || (boundsA[9] < boundsB[8]) ||
            (boundsB[7] < boundsA[6]) || (boundsB[9] < boundsA[8]))
            return 0;
        DAT_0046368C++;
        
    }
    return 0;
}
}
