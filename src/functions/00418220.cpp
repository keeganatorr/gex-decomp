// Adapted from pc_decomp_backup/src/functions/FUN_00418220.cpp
// Historical source SHA256: 097e196fad57cf57da144b4c3c674c3cf1eab9b4dd1e8e71d931540828c0ca82
extern "C" {
extern "C" { extern int DAT_0049fb90; }
extern "C" { extern void** DAT_004a27fc; }
extern "C" int __cdecl GEX_Target(int param1, void** param2) {
    void* pGVar2;
    if (param2[0x57] == 0) {
        pGVar2 = param2[0x1e];
    } else {
        void* p = param2[0x57];
        void* next;
        do {
            p = *(void**)((int)p + 0x15c);
            next = *(void**)((int)p + 0x15c);
        } while (next != 0);
        pGVar2 = (void*)(*(int*)((int)p + 0x10));
    }
    DAT_0049fb90 = (int)DAT_004a27fc[0x1e] - (int)pGVar2;
    return param1;
}
}
