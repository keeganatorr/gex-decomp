// Adapted from pc_decomp_backup/src/functions/FUN_0041A400.cpp
// Historical source SHA256: 86efbc9142d080c4008b5cf3d7fac6ea6908a34d9b0d0065e921175691b6d086
extern "C" {
extern "C" { extern int DAT_00458FE8; }
extern "C" { extern int DAT_00459018; }
extern "C" void __cdecl FUN_00405350(int, int);

extern "C" int __cdecl GEX_Target(void** param_1)
{
    int result;
    void* pGVar1;
    int iVar2;
    int iVar3;

    result = 0;
    pGVar1 = param_1[3];
    if (pGVar1 != 0) {
        iVar2 = (int)param_1[0x3e];
        if (iVar2 >= 0) {
            iVar3 = (int)param_1[0x3d];
            if (iVar3 >= 0) {
                if (*(int*)((int)pGVar1 + 0x6c) != 0) {
                    if (*(int*)((int)pGVar1 + 0x70) <= iVar3) {
                        FUN_00405350((int)&DAT_00459018, (int)param_1[2]);
                        return 0;
                    }
                    if (*(int*)(*(int*)((int)pGVar1 + 0x74) + iVar3 * 4) < iVar2) {
                        FUN_00405350((int)&DAT_00458FE8, (int)param_1[2]);
                        return 0;
                    }
                }
                result = *(int*)(*(int*)(*(int*)((int)pGVar1 + 0x6c) + 4 + *(int*)((int)pGVar1 + 0x70) + iVar3 * 8) + iVar2 * 4 + 4);
                if (result == 0) {
                    result = *(int*)(*(int*)(*(int*)((int)pGVar1 + 0x6c) + 4 + *(int*)((int)pGVar1 + 0x70) + iVar3 * 8) + 4);
                }
            }
        }
    }
    return result;
}
}
