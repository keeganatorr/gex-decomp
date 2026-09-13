// Adapted from pc_decomp_backup/src/functions/FUN_0042DAB0.cpp
// Historical source SHA256: e5e63b44c1fe02d1a5a58ec6e2c6c14f24a86eda9979938f2034423c091497ea
extern "C" {
extern "C" int __cdecl FUN_0042d6e0_ObjCallUnk(void**, int);
extern "C" int __cdecl FUN_0040F100(int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_0042cc70_Object_unk(int, void**);
extern void** FUN_004A27FC;
extern int FUN_004A2990;
extern "C" int __cdecl GEX_Target(void** param1, int param2) {
    if (param1 != FUN_004A27FC)
        return FUN_0042d6e0_ObjCallUnk(param1, param2);
    unsigned int uVar3 = (unsigned int)param1[0x62] & 0x1fffff;
    if ((*(unsigned short*)(param2 + 2) & 0xfff) == 0) {
        param1[0x1f] = (void*)((int)param1[0x1f] - (uVar3 + 1));
        param1[0x3b] = (void*)((unsigned int)param1[0x62] & 0xffe00000);
        if (param1[0x3c] != 0) FUN_0042cc70_Object_unk(0, param1);
        return 1;
    }
    int iVar2 = FUN_0040F100(FUN_004A2990, (unsigned int)*(unsigned short*)(param2 + 2), (unsigned int)param1[0x61] & 0x1fffff);
    if ((iVar2 != 0) && (iVar2 + -0x10000 <= (int)uVar3)) {
        param1[0x1f] = (void*)((int)param1[0x1f] + (iVar2 - (int)uVar3));
        param1[0x3b] = (void*)(((unsigned int)param1[0x62] & 0xffe00000) + iVar2);
        if (param1[0x3c] != 0) FUN_0042cc70_Object_unk(0, param1);
        return 1;
    }
    return 0;
}
}
