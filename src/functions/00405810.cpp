extern "C" int gIsShowingVRAM_00487bc0;
extern "C" void* gDebugVRAMWindow_0048750c;
extern "C" void* gMenu_00487f78;
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(void*);
extern "C" __declspec(dllimport) int __stdcall CheckMenuItem(void*, unsigned int, unsigned int);
extern "C" void VRAM_Hide_00405810(void)
{
    if (gIsShowingVRAM_00487bc0 != 0) {
        DestroyWindow(gDebugVRAMWindow_0048750c);
        CheckMenuItem(gMenu_00487f78, 0x9c43, 0);
        gDebugVRAMWindow_0048750c = 0;
        gIsShowingVRAM_00487bc0 = 0;
    }
}