// Adapted from pc_decomp_backup/src/functions/FUN_0042D7C0.cpp
// Historical source SHA256: f06a3614ca418140c0b9f9f9e456b81405229e60442e15ffadbbd5cf7d8a3c86
extern "C" {
extern "C" { extern void** FUN_004A27FC; }
extern "C" { extern int DAT_004a01e0; }
extern "C" { extern int DAT_004a01e8; }
extern "C" { extern int FUN_004A2990; }
extern "C" int __cdecl FUN_0042d4e0_Object_unk(void**, int);
extern "C" int __cdecl FUN_0040F100(int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_0042cc70_Object_unk(int, void**);

extern "C" int __cdecl GEX_Target(void** param_1, int param_2)
{
    unsigned int uVar3;

    if (param_1 != FUN_004A27FC) {
        return FUN_0042d4e0_Object_unk(param_1, param_2);
    }
    uVar3 = (unsigned int)param_1[0x61] & 0x1fffff;
    if ((*(unsigned short*)(param_2 + 2) & 0xfff) == 0) {
        DAT_004a01e0++;
        if ((int)DAT_004a01e8 < 0) {
            DAT_004a01e8 = (unsigned int)param_1[0x62] & 0xffe00000;
        }
        param_1[0x1e] = (void*)((int)param_1[0x1e] + (0x1fffff - (int)uVar3));
        param_1[0x3a] = (void*)(((unsigned int)param_1[0x61] & 0xffe00000) + 0x1fffff);
        if (param_1[0x39] != 0) {
            FUN_0042cc70_Object_unk(0, param_1);
        }
        return 1;
    }
    {
        int iVar2 = FUN_0040F100(
            (int)FUN_004A2990,
            (unsigned int)*(unsigned short*)(param_2 + 2),
            uVar3);
        if ((iVar2 != 0) && (iVar2 + -0x10000 <= (int)((unsigned int)param_1[0x62] & 0x1fffff))) {
            DAT_004a01e0++;
            if ((int)DAT_004a01e8 < 0) {
                DAT_004a01e8 = (((unsigned int)param_1[0x62] & 0xffe00000) + iVar2) - 0x10000;
            }
            param_1[0x1e] = (void*)((int)param_1[0x1e] + (0x1fffff - (int)uVar3));
            param_1[0x3a] = (void*)(((unsigned int)param_1[0x61] & 0xffe00000) + 0x1fffff);
            if (param_1[0x39] != 0) {
                FUN_0042cc70_Object_unk(0, param_1);
            }
            return 1;
        }
    }
    return 0;
}
}
