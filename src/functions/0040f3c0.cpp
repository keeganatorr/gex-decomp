// Adapted from pc_decomp_backup/src/functions/FUN_0040F3C0.cpp
// Historical source SHA256: deebc3be4930d4daefe6ea3ae6c1a9cabd97616ea0e21d4737a0cf43e8d66974
extern "C" {
extern "C" { extern int DAT_00462C9C; }

extern "C" int __cdecl GEX_Target(int param_1)
{
    int result = 0;
    if (DAT_00462C9C != 0) {
        (*(int(*)(int,int,int,int*,int,int,int))(DAT_00462C9C))(param_1, 0, 0, &result, 0, 0, 0);
    }
    return result;
}
}
