extern "C" {
    __declspec(dllimport) void * __stdcall GlobalAlloc(unsigned int uFlags, unsigned int dwBytes);
    __declspec(dllimport) void __stdcall OutputDebugStringA(const char *lpOutputString);
    void __cdecl WinShowError_004063d0(int dialogType, const char *formatString, ...);
    extern int DAT_0047ef70_FreeMemory;
    extern void *PTR_ARRAY_0047ef80[];
    extern char s_MEM__Need_more_than_16_Allocs_00455a34[];
    extern char WINSTRING_Memory_Error_00487d60[];
}

extern "C" void * GEX_Target(unsigned int allocationSize) {
    void *allocatedMemory;
    int size;
    void **memPtr;

    do {
        allocatedMemory = GlobalAlloc(0x40, allocationSize);
        if (allocatedMemory != 0) {
            if (DAT_0047ef70_FreeMemory != 0x20) {
                DAT_0047ef70_FreeMemory++;
                size = 0;
                if (PTR_ARRAY_0047ef80[0] != 0) {
                    memPtr = PTR_ARRAY_0047ef80;
                    do {
                        memPtr++;
                        size++;
                    } while (*memPtr != 0);
                }
                PTR_ARRAY_0047ef80[size] = allocatedMemory;
            } else {
                OutputDebugStringA(s_MEM__Need_more_than_16_Allocs_00455a34);
            }
        } else {
            WinShowError_004063d0(1, WINSTRING_Memory_Error_00487d60);
        }
    } while (allocatedMemory == 0);
    return allocatedMemory;
}
