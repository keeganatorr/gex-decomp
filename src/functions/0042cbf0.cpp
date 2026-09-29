// Adapted from pc_decomp_backup/src/functions/FUN_0042CBF0.cpp
// Historical source SHA256: 95e4b8c6d4aee6b59281a117c4ac6c4831e3478aff8c20637858847c6765cdc9
extern "C" {
extern "C" void __cdecl LST_Remove_0042cbf0(int *param_1)
{
    int *next = (int *)param_1[1];
    int *cur = (int *)*param_1;
    next[0] = (int)cur;
    cur[1] = (int)next;
}
}
