// Adapted from pc_decomp_backup/src/functions/FUN_00418F50.cpp
// Historical source SHA256: 2ed37116e040e5bd404ea1264b38bd51672e9faf4dea075ffcd5c5e6c03f277b
extern "C" {
extern "C" int __cdecl FUN_00417F00(unsigned char***);

extern "C" unsigned char* __cdecl GEX_Target(unsigned char* param_1, int param_2)
{
    unsigned char bVar1;
    unsigned char* pbVar2;
    unsigned int uVar3;
    unsigned int local_uVar3;
    
    pbVar2 = param_1 + 1;
    bVar1 = *param_1;
    param_1 = param_1 + 2;
    uVar3 = (unsigned int)*pbVar2;
    local_uVar3 = FUN_00417F00((unsigned char***)&param_1);
    *(unsigned int*)(*(int*)(param_2 + 0x68 + (unsigned int)bVar1 * 4) + 0x68 + uVar3 * 4) = local_uVar3;
    return param_1;
}
}
