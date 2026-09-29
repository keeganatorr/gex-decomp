// Adapted from pc_decomp_backup/src/functions/FUN_00418A00.cpp
// Historical source SHA256: 366b8a79e1122bbed5c752347409b3d88650aab4ea8535b2729233be6c2512d2
extern "C" {
extern "C" unsigned int __cdecl FUN_00417F00(unsigned char**);
extern "C" int __cdecl FUN_0041A480(int);
extern "C" void __cdecl FUN_00428FA0(unsigned short*, unsigned short*, unsigned int, unsigned int, unsigned int);
extern "C" unsigned char* __cdecl SCRIPT_AdjustPlut_00418a00(unsigned char* param1, void** param2) {
    unsigned int uVar2 = FUN_00417F00(&param1);
    unsigned int uVar3 = FUN_00417F00(&param1);
    unsigned int uVar4 = FUN_00417F00(&param1);
    int iVar5 = FUN_0041A480((int)param2);
    if (iVar5 != 0 && *(int**)(iVar5 + 0x18) != 0) {
        FUN_00428FA0(*(unsigned short**)(**(int**)(iVar5 + 0x18) + 0xc),
                           (unsigned short*)(param2 + 0x47),
                           uVar2, uVar3, uVar4);
        param2[0x30] = (void*)(param2 + 0x47);
    }
    return param1;
}
}
