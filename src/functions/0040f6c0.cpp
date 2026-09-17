extern "C" {
extern int (__cdecl *DAT_00462C9C)(int, int, int, int, int*, int, int);
}

extern "C" int __cdecl GEX_Target(int param_1, int param_2)
{
    int local_4 = 0;
    if (DAT_00462C9C != 0) {
        DAT_00462C9C(param_1, 1, param_2, 0, &local_4, 0, 0);
    }
    return local_4;
}
