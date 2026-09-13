// Adapted from pc_decomp_backup/src/functions/FUN_0040D6D0.cpp
// Historical source SHA256: f0a31df2055376d9b24cc4a8173e12bdae743c5f713c6315c1a3061d5d845338
extern "C" {
extern "C" { extern int FUN_004A2934; }
extern "C" void __cdecl GEX_Target(int param_1)
{
    int iVar1 = *(int*)(param_1 + 0xc);
    int bVar2 = 0;
    if (iVar1 != 0 && *(int*)(iVar1 + 8) != 0 && *(int*)(iVar1 + 0xc) > 0 && **(int**)(iVar1 + 0x10) == 1) bVar2 = 1;
    if (*(unsigned int*)(param_1 + 0xb8) == 0 || !bVar2) {
        *(int*)(param_1 + 0xb8) = iVar1;
    } else {
        *(int*)(param_1 + 0x84) = iVar1;
        *(int*)(param_1 + 0xb8) = *(int*)(FUN_004A2934 - 8 + (*(unsigned int*)(param_1 + 0xb8) & 0xffff) * 8);
    }
    *(int*)(param_1 + 0xc) = *(int*)(param_1 + 0xb8);
}
}
