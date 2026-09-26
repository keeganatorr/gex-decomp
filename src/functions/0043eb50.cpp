typedef struct TileSlotStruct {
    struct TileSlotStruct *next;  /* 0x0 */
    struct TileSlotStruct *prev;  /* 0x4 */
    short *owner;                 /* 0x8 */
    short x;                      /* 0xc */
    short y;                      /* 0xe */
} TileSlotStruct;
typedef struct DrawCache { short x; short y; short width; short height; } DrawCache;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern TileSlotStruct gpDrawCacheEntries_00465358;
extern char s_Reserving_slot_d_d_004601e0[];
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
void __cdecl GEX_Target(DrawCache *cache, int initialise)
{
    TileSlotStruct *slot;
    TileSlotStruct *next;
    int left;
    int top;
    int right;
    int bottom;
    left = cache->x;
    top = cache->y;
    slot = gpDrawCacheEntries_00465358.next;
    right = cache->x + cache->width;
    bottom = cache->y + cache->height;
    while (slot != &gpDrawCacheEntries_00465358) {
        if (bottom > slot->y && slot->y + 32 > top && slot->x < right && slot->x + 16 > left) {
            slot->prev->next = slot->next;
            next = slot->prev->next;
            slot->next->prev = slot->prev;
            if (initialise)
                slot->prev = 0;
            if (slot->owner) {
                *slot->owner = -1;
                slot->owner = 0;
            }
            slot->next = 0;
            slot = next;
            TracePrintf_Debug_00405390(s_Reserving_slot_d_d_004601e0, slot->x, slot->y);
        } else
            slot = slot->next;
    }
}
}
