// Adapted from pc_decomp_backup/src/functions/FUN_004218A0.cpp
// Historical source SHA256: 2b9b8b3adb1c0ef8d39f9ace4e5b90170d20fc7b8c4cd17f98c28e95a9485f1e
extern "C" {
extern "C" { extern int DAT_0045A710; }
extern "C" { extern int DAT_0045A714; }
extern "C" { extern void* DAT_004A2990; }
extern "C" int __cdecl FUN_0040F170(void*, int, int);

extern "C" unsigned int __cdecl GEX_Target(void** param_1)
{
    int result;
    unsigned int uVar1;
    uVar1 = (((unsigned int)param_1[0x1b] >> 0x1f) ? 8 : 0) | ((int)param_1[0x31] >> 0x15);
    result = FUN_0040F170(
        DAT_004A2990,
        (int)param_1[0x1e] + *(int*)((char*)&DAT_0045A710 + uVar1 * 8),
        (int)param_1[0x1f] + *(int*)((char*)&DAT_0045A714 + uVar1 * 8));
    return (unsigned int)(result == 0x57);
}
}
