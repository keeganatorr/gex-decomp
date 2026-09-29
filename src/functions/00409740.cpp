// Tracked-memory free path, reconstructed from the pinned original assembly.
// The original invalid-pointer path contains an inline INT 3. This source
// uses the Win32 DebugBreak API to preserve the observable breakpoint without
// adding inline assembly to a baseline function translation unit.
extern "C" {
__declspec(dllimport) void *__stdcall GlobalFree(void *memory);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char *message);
__declspec(dllimport) void __stdcall DebugBreak(void);

extern void *PTR_ARRAY_0047ef80[32];
extern int DAT_0047ef70_FreeMemory;
extern char s_MEM__can_t_free_mem__unknown_ptr_00455a54[];

void __cdecl FreeMemory_00409740(void *memory)
{
    for (int index = 0; index < 32; ++index) {
        if (PTR_ARRAY_0047ef80[index] == memory) {
            PTR_ARRAY_0047ef80[index] = 0;
            --DAT_0047ef70_FreeMemory;
            GlobalFree(memory);
            return;
        }
    }
    OutputDebugStringA(s_MEM__can_t_free_mem__unknown_ptr_00455a54);
    DebugBreak();
}
}
