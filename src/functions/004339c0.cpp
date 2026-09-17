extern "C" void __cdecl FUN_00433900(void**);
extern "C" void __cdecl GEX_Target(void** param1) {
    unsigned int flags = (unsigned int)param1[0x38];
    if ((flags & 0x100000) == 0) {
        param1[0x35] = param1[0x1e];
        param1[0x36] = param1[0x1f];
        param1[0x3f] = param1[0x1b];
        param1[0x3d] = param1[0x14];
        param1[0x3e] = param1[0x15];
        param1[0x39] = 0;
        param1[0x3a] = 0;
        param1[0x3b] = 0;
        param1[0x3c] = 0;
        unsigned int newFlags = ((flags * 2 ^ flags) & 0x200) ^ flags;
        param1[0x38] = (void*)newFlags;
        param1[0x38] = (void*)(newFlags & 0xfffffeff);
        FUN_00433900(param1);
        if (param1[0x45] == (void*)-1) param1[0x44] = 0;
        param1[0x45] = (void*)-1;
    }
}
