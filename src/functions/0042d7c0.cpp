extern "C" {
extern int DAT_004a01e0;
extern int DAT_004a01e8;
extern int FUN_004A2990;
int __cdecl FUN_0042d4e0_Object_unk(void**, int);
int __cdecl FUN_0040F100(int, unsigned int, unsigned int);
void __cdecl FUN_0042cc70_Object_unk(int, void**);
extern void** FUN_004A27FC;

int __cdecl GEX_Target(void** param_1, int param_2)
{
    unsigned int id;
    unsigned int uVar3;
    if (FUN_004A27FC != param_1) {
        return FUN_0042d4e0_Object_unk(param_1, param_2);
    }
    id = *(unsigned short*)(param_2 + 2);
    uVar3 = (unsigned int)param_1[0x61] & 0x1fffff;
    if ((id & 0xfff) == 0) {
        DAT_004a01e0++;
        if (DAT_004a01e8 < 0) {
            DAT_004a01e8 = (unsigned int)param_1[0x62] & 0xffe00000;
        }
        param_1[0x1e] = (char*)param_1[0x1e] + (0x1fffff - uVar3);
        param_1[0x3a] = (void*)(((unsigned int)param_1[0x61] & 0xffe00000) + 0x1fffff);
        if (param_1[0x39] != 0) {
            FUN_0042cc70_Object_unk(0, param_1);
        }
        return 1;
    }
    {
        int iVar2 = FUN_0040F100(FUN_004A2990, id, uVar3);
        if (iVar2 != 0 && iVar2 - 0x10000 <= (int)((unsigned int)param_1[0x62] & 0x1fffff)) {
            DAT_004a01e0++;
            if (DAT_004a01e8 < 0) {
                DAT_004a01e8 = (((unsigned int)param_1[0x62] & 0xffe00000) + iVar2) - 0x10000;
            }
            param_1[0x1e] = (char*)param_1[0x1e] + (0x1fffff - uVar3);
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
