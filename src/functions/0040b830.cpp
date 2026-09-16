extern "C" {
    extern void* gDRAMBlocks_0046270c;
    extern void* gVRAMBlocks_00462708;
    extern void* gFreeBlockTable_0046271c;
    extern void FreeMemory_00409740(void*);
}

extern "C" void GEX_Target(void) {
    FreeMemory_00409740(gDRAMBlocks_0046270c);
    FreeMemory_00409740(gVRAMBlocks_00462708);
    FreeMemory_00409740(gFreeBlockTable_0046271c);
}
