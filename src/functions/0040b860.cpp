// Adapted from pc_decomp_backup/src/functions/FUN_0040B860.cpp
// Historical source SHA256: 206153bef931f86d9fdb605e13b0ab3e554b55c9514ad56ab3aae6be1f6f42f1
extern "C" {
extern "C" { extern int** FUN_0046271C; }
extern "C" { extern int FUN_00462734; }
extern "C" { extern int FUN_00455EF0; }
extern "C" { extern int FUN_004A2924; }

extern "C" void __cdecl GEX_Target(int** levelDataArray)
{
    if (levelDataArray == 0) return;
    while (*levelDataArray != 0) {
        int* tile = *levelDataArray++;
        FUN_0046271C[FUN_00462734] = tile;
        FUN_00462734++;
        int limit = (FUN_00455EF0 + (FUN_00455EF0 >> 31 & 0x1fff)) >> 13;
        if (limit - FUN_00462734 == -1) FUN_00462734 = 0;
        FUN_004A2924++;
    }
}
}
