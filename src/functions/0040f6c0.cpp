// Adapted from pc_decomp_backup/src/functions/FUN_0040F6C0.cpp
// Historical source SHA256: b5ba413251442a98f0eeb7f4852e273aaf859e8a56332862271d7b7d5de609c9
extern "C" {
extern "C" { extern int (__cdecl *DAT_00462C9C)(int, int, void*, int, int*); }

extern "C" int __cdecl GEX_Target(int param_1, int param_2)
{
    int local_4 = 0;
    if (DAT_00462C9C != 0) {
        DAT_00462C9C(param_1, 1, (void*)param_2, 0, &local_4);
    }
    return local_4;
}
}
