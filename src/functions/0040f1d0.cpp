// Adapted from pc_decomp_backup/src/functions/FUN_0040F1D0.cpp
// Historical source SHA256: 706eeb057ce5df162e4b4f1fea8406bde761ede6789b5a9c2094aa8275158643
extern "C" {
extern "C" int __cdecl FUN_0040F030(void*, unsigned int, unsigned int);

extern "C" unsigned int __cdecl GEX_Target(void* param_1, void** param_2)
{
    int uVar1;
    int iVar2;
    int uVar3;

    uVar1 = FUN_0040F030(param_1, (unsigned int)param_2[0x1e], (unsigned int)param_2[0x1f]);
    iVar2 = FUN_0040F030(param_1, (unsigned int)param_2[0x1e], (unsigned int)((int)param_2[0x1f] - 0x1000));
    uVar3 = iVar2 - 0x200000;
    if (((uVar3 ^ (uVar3 >> 0x1f)) - (uVar3 >> 0x1f)) < ((uVar1 ^ (uVar1 >> 0x1f)) - (uVar1 >> 0x1f))) {
        uVar1 = uVar3;
    }
    iVar2 = FUN_0040F030(param_1, (unsigned int)param_2[0x1e], (unsigned int)((int)param_2[0x1f] + 0x1000));
    uVar3 = iVar2 + 0x200000;
    if (((uVar1 ^ (uVar1 >> 0x1f)) - (uVar1 >> 0x1f)) <= ((uVar3 ^ (uVar3 >> 0x1f)) - (uVar3 >> 0x1f))) {
        uVar3 = uVar1;
    }
    return uVar3;
}
}
