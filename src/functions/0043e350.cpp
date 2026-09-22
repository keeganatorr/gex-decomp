struct DrawCacheEntry {
    int field0;
    DrawCacheEntry* field4;
    int field8;
    short xPos;
    short yPos;
    short field10;
    char field12;
    char field13;
};

extern "C" {
    void TracePrintf_Debug_00405390(const char*);
    int FUN_00445180_CacheInitInner_takes_x_and_y(int, int);
    void DRAW_CacheClear_0043e430(int);
    extern char s_DRAW_CacheInit___004600cc[];
    extern DrawCacheEntry DrawCacheEntry_ARRAY_00467188[];
    extern DrawCacheEntry DrawCacheEntry_ARRAY_00465370[];
    extern DrawCacheEntry DrawCacheEntry_ARRAY_00464e58[];
}

extern "C" void GEX_Target(void)
{
    TracePrintf_Debug_00405390(s_DRAW_CacheInit___004600cc);

    DrawCacheEntry* p = DrawCacheEntry_ARRAY_00467188;
    int x = 0x140;
    do {
        int y = 0;
        do {
            p->xPos = (short)x;
            p->yPos = (short)y;
            p->field8 = 0;
            p->field13 = (char)y;
            y += 0x20;
            p->field4 = p;
            ++p;
        } while (y < 0x1e0);
        x += 0x10;
    } while (x < 0x400);

    p = DrawCacheEntry_ARRAY_00465370;
    x = 0x140;
    do {
        int y = 0x1e0;
        do {
            p->xPos = (short)x;
            p->yPos = (short)y;
            p->field8 = 0;
            p->field10 = (short)FUN_00445180_CacheInitInner_takes_x_and_y(x, y);
            ++y;
            ++p;
        } while (y < 0x200);
        x += 0x10;
    } while (x < 0x200);

    p = DrawCacheEntry_ARRAY_00464e58;
    x = 0x200;
    do {
        int y = 0x1e0;
        do {
            p->xPos = (short)x;
            p->yPos = (short)y;
            p->field8 = 0;
            p->field10 = (short)FUN_00445180_CacheInitInner_takes_x_and_y(x, y);
            ++y;
            ++p;
        } while (y < 0x200);
        x += 0x100;
    } while (x < 0x400);

    DRAW_CacheClear_0043e430(1);
}
