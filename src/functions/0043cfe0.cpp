extern "C" void __cdecl FUN_00434A20(void**);

extern "C" void __cdecl ob90Init_0043cfe0(void** param_1)
{
    int found = 0;
    void* obj = param_1[3];
    void* a = *(void**)((char*)obj + 4);
    if (a != 0) {
        void* b = *(void**)a;
        if (b != 0) {
            void* c = *(void**)b;
            if (c != 0) {
                found = 1;
                param_1[4] = c;
                void* d = *(void**)((char*)(*(void**)(*(void**)((char*)obj + 4))) + 4);
                if (d != 0) {
                    param_1[0xc] = d;
                }
            }
        }
    }
    if (found != 0) {
        param_1[0x26] = 0;
    } else if (param_1[0x26] == 0) {
        param_1[0x26] = (void*)0x4000;
    }
    FUN_00434A20(param_1);
}
