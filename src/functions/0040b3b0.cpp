typedef struct BlockList {
    int **blocks;   /* 0x0: where the block table pointer lives */
    int *end;       /* 0x4 */
    int unk8;
    int count;      /* 0xc */
    int max;        /* 0x10 */
} BlockList;
typedef struct ReadRequest {
    BlockList *list;  /* 0x0 */
    int *data;        /* 0x4 */
    int index;        /* 0x8 */
    int unkC[18];
    int busy;         /* 0x54 */
} ReadRequest;
typedef struct ReadCompletion {
    unsigned char unk0[0x3c];
    ReadRequest *request;  /* 0x3c */
} ReadCompletion;
extern "C" {
extern int DAT_00462738_BlockNumber;
extern int DAT_0046272c_LevFileUnk4;
extern int DAT_00462720_LevFileUnk5;
extern ReadRequest READ_REQUEST_2_ARRAY_00462740[9];
void __cdecl BLOC_Loaded_0040b3b0(ReadCompletion *completion)
{
    ReadRequest *request;
    BlockList *list;
    int *data;
    request = completion->request;
    data = request->data;
    list = request->list;
    if (!request->index)
        *list->blocks = data;
    (*list->blocks)[request->index] = (int)data;
    if (++list->count == list->max)
        *list->end = (int)(*list->blocks + list->max + 1);
    request->busy = 0;
    while (DAT_00462738_BlockNumber != DAT_0046272c_LevFileUnk4
           && !READ_REQUEST_2_ARRAY_00462740[DAT_0046272c_LevFileUnk4].busy) {
        if (++DAT_0046272c_LevFileUnk4 == 9)
            DAT_0046272c_LevFileUnk4 = 0;
        DAT_00462720_LevFileUnk5--;
    }
}
}
