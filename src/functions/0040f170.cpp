// Adapted from pc_decomp_backup/src/functions/FUN_0040F170.cpp
// Historical source SHA256: 6f03fbcb33eac79bcb7d58ff286c2c85c36826f38fa2b916a260eb8747c1228a
extern "C" {
extern "C" void* __cdecl FUN_00440430_CheckWallCollisionInner(void*, void**, unsigned int, unsigned int);

extern "C" unsigned int __cdecl GEX_Target(void* param_1, unsigned int xPos, unsigned int yPos)
{
    if ((int)xPos < 0) return 1;
    if ((int)yPos < 0) return 0;
    int* levelData = *(int**)((char*)param_1 + 4);
    if (levelData[1] <= (int)xPos) return 1;
    if (levelData[2] <= (int)yPos) return 4;
    void* tileData = *(void**)((char*)param_1 + 0x14);
    void* result = FUN_00440430_CheckWallCollisionInner((void*)levelData, (void**)tileData, xPos, yPos);
    return *(unsigned int*)((char*)result + 6);
}
}
