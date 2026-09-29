extern "C" {
__declspec(dllimport) void __stdcall CloseHandle(void *hObject);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char *lpOutputString);
}

extern void *HANDLE_ARRAY_0047f010[];
extern int nFileHandles_0047f004;
extern int gIDLDirectory_0047f030;
extern char s_CDIO__Unknown_FileHandle_used_in_004559b8[];

extern "C" void CDIO_FileClose_00409200(void *pHandle);

void CDIO_FileClose_00409200(void *pHandle)
{
    void **lHandle = HANDLE_ARRAY_0047f010;
    int handle = 0;
    do {
        if (*lHandle == pHandle) {
            CloseHandle(pHandle);
            --nFileHandles_0047f004;
            HANDLE_ARRAY_0047f010[handle] = 0;
            return;
        }
        lHandle = lHandle + 1;
        handle = handle + 1;
    } while (lHandle < (void **)&gIDLDirectory_0047f030);
    OutputDebugStringA(s_CDIO__Unknown_FileHandle_used_in_004559b8);
}
