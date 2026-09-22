// Adapted from pc_decomp_backup/src/functions/FUN_0042D4E0.cpp
// Historical source SHA256: 3ec1c25a6716717999e3c17af86ea8244c97461d98139730f8139cbdd9b71284
extern "C" {
extern "C" int __cdecl FUN_0040F100(int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_0042cc70_Object_unk(int, void**);
extern int FUN_004A2990;
extern "C" int __cdecl GEX_Target(void** param1, int param2) {
    unsigned int w = *(unsigned short*)(param2 + 2);
    unsigned int uVar2 = (unsigned int)param1[0x61] & 0x1fffff;
    if ((w & 0xfff) == 0) {
        param1[0x1e] = (void*)((0x200000 - uVar2) + (char*)param1[0x1e]);
        param1[0x3a] = (void*)(((unsigned int)param1[0x61] & 0xffe00000) + 0x200000);
        if (param1[0x39] != 0) FUN_0042cc70_Object_unk(0, param1);
        return 1;
    }
    int iVar1 = FUN_0040F100(FUN_004A2990, w, uVar2);
    if ((iVar1 != 0) && (iVar1 - 0x10000 <= (int)((unsigned int)param1[0x62] & 0x1fffff))) {
        param1[0x1e] = (void*)((0x200000 - uVar2) + (char*)param1[0x1e]);
        param1[0x3a] = (void*)(((unsigned int)param1[0x61] & 0xffe00000) + 0x200000);
        if (param1[0x39] != 0) FUN_0042cc70_Object_unk(0, param1);
        return 1;
    }
    return 0;
}
}