// Adapted from pc_decomp_backup/src/functions/FUN_0042D5C0.cpp
// Historical source SHA256: 6721f93404d2359e77d4f7869b30208cb57d27b8e138cd374a72055b594dc837
extern "C" {
extern "C" int __cdecl FUN_0040F100(int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_0042cc70_Object_unk(int, void**);

extern int FUN_004A2990;

extern "C" int __cdecl GEX_Target(void** gOb, int param2)
{
    unsigned int uVar2 = (unsigned int)gOb[0x61] & 0x1fffff;
    if ((*(unsigned short*)(param2 + 2) & 0xfff) == 0)
    {
        gOb[0x1e] = (void*)((int)gOb[0x1e] - (uVar2 + 1));
        gOb[0x39] = (void*)(((unsigned int)gOb[0x61] & 0xffe00000) - 1);
        if (gOb[0x3a] != 0)
            FUN_0042cc70_Object_unk(0, gOb);
        return 1;
    }
    int iVar1 = FUN_0040F100(FUN_004A2990, (unsigned int)*(unsigned short*)(param2 + 2), uVar2);
    if ((iVar1 != 0) && (iVar1 + -0x10000 <= (int)((unsigned int)gOb[0x62] & 0x1fffff)))
    {
        gOb[0x1e] = (void*)((int)gOb[0x1e] - (uVar2 + 1));
        gOb[0x39] = (void*)(((unsigned int)gOb[0x61] & 0xffe00000) - 1);
        if (gOb[0x3a] != 0)
            FUN_0042cc70_Object_unk(0, gOb);
        return 1;
    }
    return 0;
}
}
