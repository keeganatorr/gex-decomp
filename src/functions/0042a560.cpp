// Adapted from pc_decomp_backup/src/functions/FUN_0042A560.cpp
// Historical source SHA256: 3ce57faecfaac0ec3a21710c61e7a10a0a39585ebfbe95b0dd0f4a4465d47e3a
extern "C" {
extern "C" int __cdecl FUN_00429CB0(int, int);
extern "C" int __cdecl FUN_0042a560_RemoteUnk(int param1, int param2) {
    int iVar1 = (4 - *(int*)(param1 + 0xa0)) * 0x280000;
    int tv = FUN_00429CB0(0, *(int*)(param1 + 0x9c) + 1);
    int i = 0;
    if (*(int*)(param1 + 0xb4) > 0) {
        do {
            iVar1 += 0x280000;
            if (tv == param2) return iVar1;
            tv = FUN_00429CB0(tv, 1);
            i++;
        } while (i < *(int*)(param1 + 0xb4));
    }
    return 0;
}
}
