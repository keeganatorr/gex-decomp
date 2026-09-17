extern "C" {
    extern void* __cdecl FUN_00409630(void*, int);
    extern void __cdecl FUN_004451e0_LEV_SetUpDrawCacheWithFileData(void*, void*);
    extern void __cdecl FUN_0043eb50_LoadTilePoss(void*, int);
    extern void* DAT_004a2af4;
    extern char DAT_0046a664;
    extern char DAT_0046a668;
    extern short DAT_0046a66c;

    struct DrawCache {
        short field0_0x0;
        short field0x2;
        short field0x4;
        short field0x6;
    };

    void __cdecl GEX_Target(void* LoadedLevel, void* idl_file_handle, int LEV) {
        char* ll = (char*)LoadedLevel;
        ll[8] = 0x20;
        ll[9] = 0x7f;
        *(int*)(ll + 0x10) = -1;
        void* fileMemory = FUN_00409630(idl_file_handle, LEV);
        *(void**)(ll + 4) = fileMemory;
        *(void**)(ll + 0) = (void*)((int)fileMemory + 4);
        if (DAT_004a2af4 == 0) DAT_004a2af4 = LoadedLevel;
        DrawCache drawCache;
        drawCache.field0_0x0 = 0x3f0;
        drawCache.field0x2 = 0x180;
        drawCache.field0x4 = *(short*)((int)fileMemory + 0x324) >> 2;
        drawCache.field0x6 = *(short*)((int)fileMemory + 0x326);
        FUN_004451e0_LEV_SetUpDrawCacheWithFileData(&drawCache, (void*)((int)fileMemory + 0x328));
        DAT_0046a664 = (char)drawCache.field0_0x0 << 2;
        DAT_0046a668 = (char)drawCache.field0x2;
        unsigned short temp = drawCache.field0_0x0;
        temp &= 0x3c0;
        temp >>= 2;
        temp |= drawCache.field0x2 & 0x100;
        DAT_0046a66c = (short)temp >> 4;
        FUN_0043eb50_LoadTilePoss(&drawCache, 1);
    }
}