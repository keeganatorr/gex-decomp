extern "C" int __cdecl FUN_00405390(const char* format, int arg1, int arg2);

extern "C" int __cdecl GEX_Target(int param_1) {
    FUN_00405390((const char*)0x45b068,
                 *(int *)(param_1 + 0x184) / 2097152,
                 *(int *)(param_1 + 0x188) / 2097152);
    return 0;
}
