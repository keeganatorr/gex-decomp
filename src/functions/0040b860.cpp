extern "C" {
extern int **FUN_0046271C;
extern int FUN_00462734;
extern int FUN_00455EF0;
extern int FUN_004A2924;

void __cdecl BLOC_FreeBlocks_0040b860(int **levelDataArray)
{
    if (levelDataArray == 0) return;
    while (*levelDataArray != 0) {
        *(FUN_0046271C + FUN_00462734) = *levelDataArray++;
        FUN_00462734 = FUN_00462734 + 1;
        if (FUN_00455EF0 / 8192 - FUN_00462734 == -1) {
            FUN_00462734 = 0;
        }
        FUN_004A2924 = FUN_004A2924 + 1;
    }
}
}
