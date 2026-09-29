extern "C" {
extern int gNextReadRequestIndex_00462728;
extern int DAT_00462724_LevFileUnk1;
extern int DAT_00462730_BlockIndex;
extern int gNumReadRequests_00462714;
extern int DAT_00462738_BlockNumber;
extern int DAT_0046272c_LevFileUnk4;
extern int DAT_00462720_LevFileUnk5;
extern int DAT_00462710_LoadedBlocks;
extern int gDRAMBlockSize_00455ef0;
extern int gVRAMBlockSize_00455ef4;
extern int gNumFreeDRAMBlocks_00462734;
extern int nblocksFree_004a2924;
extern int gHasBlocks_00462718;
extern void *gFreeBlockTable_0046271c;
extern void *gVRAMBlocks_00462708;
extern void *gDRAMBlocks_0046270c;

void *__cdecl MEM_AllocMem_004096c0(int size);
void *__cdecl BLOC_InitTable_0040b6d0(void *table, void *blocks, int count);

void __cdecl BLOC_OpenBlockSupport_0040b6f0(void)
{
    void *next;
    void *table;
    gNextReadRequestIndex_00462728 = 0;
    DAT_00462724_LevFileUnk1 = 0;
    DAT_00462730_BlockIndex = 0;
    gNumReadRequests_00462714 = 0;
    DAT_00462738_BlockNumber = 0;
    DAT_0046272c_LevFileUnk4 = 0;
    DAT_00462720_LevFileUnk5 = 0;
    DAT_00462710_LoadedBlocks = 0;
    gNumFreeDRAMBlocks_00462734 = gDRAMBlockSize_00455ef0 / 8192;
    nblocksFree_004a2924 = gNumFreeDRAMBlocks_00462734;
    gFreeBlockTable_0046271c = MEM_AllocMem_004096c0(gNumFreeDRAMBlocks_00462734 * 4 + 4);
    gVRAMBlocks_00462708 = MEM_AllocMem_004096c0((gVRAMBlockSize_00455ef4 / 8192) * 8192);
    gDRAMBlocks_0046270c = MEM_AllocMem_004096c0((gDRAMBlockSize_00455ef0 / 8192 - gVRAMBlockSize_00455ef4 / 8192) * 8192);
    table = gFreeBlockTable_0046271c;
    next = BLOC_InitTable_0040b6d0(table, gVRAMBlocks_00462708, gVRAMBlockSize_00455ef4 / 8192);
    BLOC_InitTable_0040b6d0(next, gDRAMBlocks_0046270c, gDRAMBlockSize_00455ef0 / 8192 - gVRAMBlockSize_00455ef4 / 8192);
    if (gHasBlocks_00462718 == 0)
        gHasBlocks_00462718 = 1;
}
}
