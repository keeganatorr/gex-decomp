// Adapted from pc_decomp_backup/src/functions/FUN_00419410.cpp
// Historical source SHA256: 9ad6a16a7d30a249d5881b32a558e624b858907b70b92eb8d672ba01a45ec770
extern "C" {
extern "C" { extern int DAT_0049FB90; }
extern void* DAT_004A2990;

extern "C" unsigned int __cdecl FUN_00417F00(unsigned char**);
extern "C" int __cdecl FUN_00419FE0(void*, int, unsigned int);
extern "C" int __cdecl FUN_0040F100(int, unsigned int, unsigned int);

extern "C" unsigned char* __cdecl GEX_Target(unsigned char* param_1, void** param_2)
{
    unsigned int uVar2;
    unsigned int uVar3;
    int iVar4;

    uVar2 = FUN_00417F00(&param_1);
    uVar3 = FUN_00417F00(&param_1);
    iVar4 = FUN_00419FE0(DAT_004A2990, (int)param_2[0x1e] + (int)(uVar2 * 0x80), (unsigned int)((int)param_2[0x1f] + (int)(uVar3 * 0x80)));
    if ((*(unsigned short*)(iVar4 + 2) & 0xfff) == 0) {
        DAT_0049FB90 = 0;
        return param_1;
    }
    iVar4 = FUN_0040F100((int)DAT_004A2990, (unsigned int)*(unsigned short*)(iVar4 + 2), (unsigned int)((int)param_2[0x1e] + (int)(uVar2 * 0x80)) & 0x1fffff);
    if (iVar4 == 0) {
        DAT_0049FB90 = 0;
        return param_1;
    }
    DAT_0049FB90 = 1;
    return param_1;
}
}
