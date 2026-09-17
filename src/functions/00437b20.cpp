extern "C" void __cdecl FUN_00405390(const char*);
extern "C" void __cdecl FUN_00417B70(int);
extern "C" int DAT_00455c54;
extern "C" const char DAT_0045b140[];
extern "C" void __cdecl GEX_Target(int param1, int* param2) {
    if (*param2 != 0) {
        int val = *(int*)(param1 + 0x178);
        if (((*(unsigned int*)(val + 0x6c) >> 8) & 0xf) == 2) {
            if (DAT_00455c54 > 1) {
                FUN_00405390(DAT_0045b140);
            }
            FUN_00417B70(param1);
        }
    }
}
