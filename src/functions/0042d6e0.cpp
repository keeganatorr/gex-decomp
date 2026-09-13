// Adapted from pc_decomp_backup/src/functions/FUN_0042D6E0.cpp
// Historical source SHA256: 522a8fa640a991faa2d4c8960db871683071c0fd4fd6da1126a033b2ad9e1353
extern "C" {
extern "C" int __cdecl FUN_0040F100(int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_0042cc70_Object_unk(int, void**);
extern int FUN_004A2990;
extern "C" int __cdecl GEX_Target(void** param1, int param2) {
    unsigned int uVar2 = (unsigned int)param1[0x62] & 0x1fffff;
    if ((*(unsigned short*)(param2 + 2) & 0xfff) == 0) {
        param1[0x1f] = (void*)((int)param1[0x1f] - (uVar2 + 1));
        param1[0x3b] = (void*)(((unsigned int)param1[0x62] & 0xffe00000) - 1);
        if (param1[0x3c] != 0)
            FUN_0042cc70_Object_unk(0, param1);
        return 1;
    }
    int iVar1 = FUN_0040F100(FUN_004A2990, (unsigned int)*(unsigned short*)(param2 + 2), (unsigned int)param1[0x61] & 0x1fffff);
    if ((iVar1 != 0) && (iVar1 + -0x10000 <= (int)uVar2)) {
        param1[0x1f] = (void*)((int)param1[0x1f] + (iVar1 - (int)uVar2));
        param1[0x3b] = (void*)(((unsigned int)param1[0x62] & 0xffe00000) + iVar1);
        if (param1[0x3c] != 0)
            FUN_0042cc70_Object_unk(0, param1);
        return 1;
    }
    return 0;
}
}
