// Adapted from pc_decomp_backup/src/functions/FUN_0043CFE0.cpp
// Historical source SHA256: f03755084295d566052b3ea128b33abd377cddff6a4490108e757c8acd02e0cb
extern "C" {
extern "C" void __cdecl FUN_00434A20(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int found = 0;
    void* prev = (void*)param_1[3];
    if (prev != 0) {
        void* next = *(void**)((char*)prev + 4);
        if (next != 0) {
            void* val = *(void**)((char*)next + 4);
            if (val != 0) {
                found = 1;
                param_1[4] = val;
                void* prev2 = *(void**)((char*)prev + 4);
                if (prev2 != 0) {
                    param_1[0xc] = prev2;
                }
            }
        }
    }
    if (found) {
        param_1[0x26] = 0;
    } else if (param_1[0x26] == 0) {
        param_1[0x26] = (void*)0x4000;
    }
    FUN_00434A20(param_1);
}
}
