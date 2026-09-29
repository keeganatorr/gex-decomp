// Adapted from pc_decomp_backup/src/functions/FUN_0042CE70.cpp
// Historical source SHA256: 12fd8b88df7ecb24489ec030753c11b6f892a1360c737cd48648de2a4c9eaed6
extern "C" {
extern "C" void* __cdecl FUN_00440430(void*, void**, unsigned int, unsigned int);

extern "C" void* __cdecl TILES_GetBlockAddress_0042ce70(int param_1, void** param_2, unsigned int param_3, unsigned int param_4)
{
    if ((int)param_3 < 0) return (void*)0x0045afc8;
    if (*(int*)(param_1 + 4) <= (int)param_3) return (void*)0x0045afd8;
    if ((int)param_4 < 0) return (void*)0x0045afe8;
    if (*(int*)(param_1 + 8) <= (int)param_4) return (void*)0x0045aff8;
    return FUN_00440430((void*)param_1, param_2, param_3, param_4);
}
}
