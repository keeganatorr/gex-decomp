// Adapted from pc_decomp_backup/src/functions/FUN_00412960.cpp
// Historical source SHA256: 89651ab742b95b139395ff5f3b0b9022420d8133da2e3de4d40d5470a06d6ba7
extern "C" {
extern "C" { extern int DAT_004A02A0; }
extern "C" { extern int DAT_00458758; }
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00413050(void**);
extern "C" void __cdecl FUN_00412880(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    unsigned int uVar1;
    int iVar2;
    unsigned int uVar3;

    iVar2 = DAT_004A02A0;
    uVar1 = *(unsigned int*)((int)&DAT_00458758 + ((((unsigned int)param_1[0x1b] & 0x80000000) >> 0x1c) << 2 | (unsigned int)((unsigned int)param_1[0x31] & 0xffe7ffff) >> 0x13));
    FUN_00420BC0(param_1);
    if (iVar2 != 0) {
        uVar3 = 0;
        if (iVar2 != 0) {
            uVar3 = ((iVar2 + 3) & 7) + 1;
        }
        if (((uVar1 == uVar3) || ((uVar1 & 7) + 1 == uVar3)) || (((uVar1 - 2) & 7) + 1 == uVar3)) {
            FUN_00413050(param_1);
            return;
        }
    }
    param_1[0x15] = (void*)0x0;
    param_1[0x26] = (void*)0x0;
    param_1[0x1c] = (void*)0x3a;
    param_1[0x14] = (void*)0x4a;
    param_1[0x28] = (void*)0x0;
    FUN_00412880(param_1);
}
}
