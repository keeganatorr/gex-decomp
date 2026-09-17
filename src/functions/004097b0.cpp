extern "C" {
__declspec(dllimport) void* __stdcall GlobalFree(void*);
extern int DAT_0047ef70_FreeMemory;

void __cdecl GEX_Target(void)
{
    int* ptr = (int*)0x0047EF80;
    do {
        if (*ptr != 0) {
            GlobalFree((void*)*ptr);
            *ptr = 0;
        }
        ptr++;
    } while (ptr < (int*)0x0047F000);
    DAT_0047ef70_FreeMemory = 0;
}
}