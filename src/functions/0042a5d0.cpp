// Adapted from pc_decomp_backup/src/functions/FUN_0042A5D0.cpp
// Historical source SHA256: 4ee6aefb103ea42a0514e4eadbb504a503454a6b23d8b8f3cfe07d493c487817
extern "C" {
extern "C" int __cdecl FUN_00429cb0_RemoteTVSelect_Unk1(int, int);
extern "C" int __cdecl GEX_Target(int param1, int param2) {
    int iVar1 = 0;
    int tv = FUN_00429cb0_RemoteTVSelect_Unk1(0, *(int*)(param1 + 0x9c) + 1);
    int i = 0;
    if (*(int*)(param1 + 0xb4) > 0) {
        do {
            iVar1++;
            if (tv == param2) return iVar1;
            i++;
            tv = FUN_00429cb0_RemoteTVSelect_Unk1(tv, 1);
        } while (i < *(int*)(param1 + 0xb4));
    }
    return 0;
}
}
