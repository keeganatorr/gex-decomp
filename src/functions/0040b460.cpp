typedef struct ReadRequest {
    int *nextTilePtr;
    int *currentTilePtr;
    int remaining;
    int loaded;
    int total;
    int file[4];
    void *directory;
    int levelNumber;
    int initialized;
    int reserved;
} ReadRequest;
typedef struct Block Block;
struct Block {
    ReadRequest *list;
    int *data;
    int index;
    int f0c[2];
    char completion[0x3c];
    Block *self;
    int busy;
};

extern "C" {
extern int DAT_00462730_BlockIndex;
extern int ReadRequest_00462a64[];
extern Block READ_REQUEST_2_ARRAY_00462740[9];
extern int DAT_00462724_LevFileUnk1;
extern int gNumReadRequests_00462714;
extern int DAT_00462720_LevFileUnk5;
extern int nblocksFree_004a2924;
extern int gNextReadRequestIndex_00462728;
extern int DAT_00462710_LoadedBlocks;
extern int **gFreeBlockTable_0046271c;
extern int DAT_00462738_BlockNumber;
extern int gDRAMBlockSize_00455ef0;
extern char s_Error_Out_Of_Memory_00455f2c[];
extern char s_load_block_00455f10[];
extern char s_BlockLoad_00455ef8[];
void __cdecl FILE_Close_004094c0(int *);
void __cdecl FILE_Open_00409430(void *, int *, int);
void __cdecl exit_00449780(int);
void __cdecl TracePrintf_Debug_00405390(char *, ...);
void __cdecl assertfail_00405350(char *, ...);
void __cdecl FUN_00409680_ReadFile(int *, int *, int *, int, int);
void __cdecl BLOC_Loaded_0040b3b0(void *);

void __cdecl GEX_Target(void)
{
    int n;
    ReadRequest *req;
    int k;
    int *data;
    Block *blk;
    while (DAT_00462730_BlockIndex != DAT_00462724_LevFileUnk1) {
        req = (ReadRequest *)((char *)ReadRequest_00462a64 - 0xc) + DAT_00462724_LevFileUnk1;
        if (req->loaded != req->total)
            break;
        FILE_Close_004094c0(req->file);
        if (++DAT_00462724_LevFileUnk1 == 10)
            DAT_00462724_LevFileUnk1 = 0;
        gNumReadRequests_00462714--;
    }
    n = 8 - DAT_00462720_LevFileUnk5 < nblocksFree_004a2924 ? 8 - DAT_00462720_LevFileUnk5 : nblocksFree_004a2924;
    while (n) {
        if (DAT_00462730_BlockIndex != gNextReadRequestIndex_00462728) {
            req = (ReadRequest *)((char *)ReadRequest_00462a64 - 0xc) + DAT_00462730_BlockIndex;
            if (!req->initialized) {
                req->initialized = 1;
                FILE_Open_00409430(req->directory, req->file, req->levelNumber);
                req->total = req->remaining = (unsigned int)(req->file[0] + 0x1fff) >> 13;
                req->loaded = 0;
                if (nblocksFree_004a2924 < req->total) {
                    assertfail_00405350(s_Error_Out_Of_Memory_00455f2c, nblocksFree_004a2924, req->total);
                    exit_00449780(10);
                }
            }
            k = req->remaining;
            if (k) {
                n -= k;
                do {
                    data = gFreeBlockTable_0046271c[DAT_00462710_LoadedBlocks];
                    TracePrintf_Debug_00405390(s_load_block_00455f10, DAT_00462738_BlockNumber, data);
                    blk = &READ_REQUEST_2_ARRAY_00462740[DAT_00462738_BlockNumber];
                    blk->self = blk;
                    blk->data = data;
                    blk->index = req->total - req->remaining;
                    blk->busy = 1;
                    blk->list = req;
                    TracePrintf_Debug_00405390(s_BlockLoad_00455ef8, data, DAT_00462710_LoadedBlocks);
                    req->remaining--;
                    if (++DAT_00462738_BlockNumber == 9)
                        DAT_00462738_BlockNumber = 0;
                    DAT_00462720_LevFileUnk5++;
                    if (gDRAMBlockSize_00455ef0 / 0x2000 - ++DAT_00462710_LoadedBlocks == -1)
                        DAT_00462710_LoadedBlocks = 0;
                    nblocksFree_004a2924--;
                    FUN_00409680_ReadFile(req->file, blk->f0c, data, 0x2000, 0);
                    BLOC_Loaded_0040b3b0(blk->completion);
                } while (--k);
                if (req->remaining)
                    continue;
            }
            if (++DAT_00462730_BlockIndex == 10)
                DAT_00462730_BlockIndex = 0;
        } else
            n = 0;
    }
}
}
