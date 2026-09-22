struct CacheEntry {
    CacheEntry *next;
    CacheEntry *prev;
    short *owner;
    unsigned char opaque_0c[8];
};

extern "C" {
extern char s_DRAW_CacheClear___004600e0[];
void __cdecl TracePrintf_Debug_00405390(const char *, ...);
extern CacheEntry gpDrawCacheEntries_00465358;
extern CacheEntry DrawCacheEntry_ARRAY_00467188[];
extern CacheEntry DrawCacheEntry_0046a518;
extern CacheEntry DrawCacheEntry_ARRAY_00465370[];
extern CacheEntry DrawCacheEntry_ARRAY_00464e58[];
extern CacheEntry DAT_00464e28_DrawCacheClear5;
extern short DAT_00460040;
extern short DAT_00460042;
extern signed char DAT_00467170;
extern unsigned long DAT_00467178;
extern unsigned long DAT_00467180[];
extern unsigned long *DAT_004A2B14;
extern unsigned long *DAT_004A2B18;
extern short DAT_004A2B20;
}

extern "C" void __cdecl GEX_Target(int clearMode)
{
    TracePrintf_Debug_00405390(s_DRAW_CacheClear___004600e0);

    CacheEntry *tail = &gpDrawCacheEntries_00465358;
    CacheEntry *p = DrawCacheEntry_ARRAY_00467188;
    do {
        if (p->prev && (clearMode || p->next)) {
            tail->next = p;
            p->prev = tail;
            if (p->owner) {
                *p->owner = -1;
                p->owner = 0;
            }
            tail = p;
        }
        ++p;
    } while (p < &DrawCacheEntry_0046a518);
    tail->next = &gpDrawCacheEntries_00465358;
    gpDrawCacheEntries_00465358.prev = tail;

    CacheEntry *q = DrawCacheEntry_ARRAY_00465370;
    do {
        q->next = q + 1;
        q->prev = q - 1;
        if (q->owner) {
            *q->owner = -1;
            q->owner = 0;
        }
        ++q;
    } while (q < (CacheEntry *)&DAT_00467170);
    --q;
    q->next = &DAT_00464e28_DrawCacheClear5;
    p = DrawCacheEntry_ARRAY_00464e58;
    DAT_00464e28_DrawCacheClear5.prev = q;
    DrawCacheEntry_ARRAY_00465370[0].prev = &DAT_00464e28_DrawCacheClear5;
    DAT_00464e28_DrawCacheClear5.next = DrawCacheEntry_ARRAY_00465370;

    do {
        p->next = p + 1;
        p->prev = p - 1;
        if (p->owner) {
            *p->owner = -1;
            p->owner = 0;
        }
        ++p;
    } while (p < &gpDrawCacheEntries_00465358);
    --p;
    p->next = &DrawCacheEntry_0046a518;
    DrawCacheEntry_0046a518.prev = p;
    DrawCacheEntry_ARRAY_00464e58[0].prev = &DrawCacheEntry_0046a518;
    DrawCacheEntry_0046a518.next = DrawCacheEntry_ARRAY_00464e58;

    DAT_004A2B18 = &DAT_00467178;
    DAT_00460040 = 320;
    DAT_00460042 = 0;
    DAT_00467170 = 0;
    *DAT_004A2B18 &= 0x00ffffffUL;
    DAT_004A2B14 = DAT_00467180 + DAT_00467170;
    *DAT_004A2B14 &= 0x00ffffffUL;
    DAT_004A2B20 = 0;
}
