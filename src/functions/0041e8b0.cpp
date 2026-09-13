// Adapted from pc_decomp_backup/src/functions/FUN_0041E8B0.cpp
// Historical source SHA256: 8cffdbd300a418f4d7a0b7ab6247c570aedc6ee72b459a36099091aac0e376fc
extern "C" {
extern "C" { extern int DAT_004A23C0; }
extern "C" void __cdecl FUN_00405350(const char*, ...);
extern "C" void __cdecl FUN_0042CBF0(int*);
extern "C" void __cdecl FUN_0042CC00(void*, int*);

extern "C" void __cdecl GEX_Target(int** list, int listNumber)
{
    int* node = *list;

    while (*node != 0) {
        int* next = (int*)node[0];
        int* owner = (int*)node[2];

        if (owner == 0) {
            FUN_0042CBF0(node);
            FUN_0042CC00((void*)0x00463728, node);
            --DAT_004A23C0;
        } else if ((owner[0x6c / 4] & 0x100000) != 0) {
            FUN_00405350((const char*)0x00459528, owner[2]);
        }
        node = next;
    }

    int* freeList = *(int**)0x00463730;
    if (*freeList == (int)node) {
        FUN_00405350((const char*)0x00459568, listNumber);
    }
}
}
