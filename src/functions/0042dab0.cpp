extern "C" {
int __cdecl FUN_0042d6e0_ObjCallUnk(int *, int);
int __cdecl FUN_0040F100(int, unsigned int, unsigned int);
void __cdecl FUN_0042cc70_Object_unk(int, int *);
extern int *FUN_004A27FC;
extern int FUN_004A2990;

int __cdecl GEX_Target(int *param_1, int param_2)
{
    unsigned int id;
    unsigned int c;
    unsigned int uVar3;
    int iVar2;

    if (param_1 != FUN_004A27FC) {
        return FUN_0042d6e0_ObjCallUnk(param_1, param_2);
    }
    id = *(unsigned short *)(param_2 + 2);
    c = (unsigned int)param_1[0x61] & 0x1fffff;
    uVar3 = (unsigned int)param_1[0x62] & 0x1fffff;
    if ((id & 0xfff) == 0) {
        param_1[0x1f] = param_1[0x1f] - (uVar3 + 1);
        param_1[0x3b] = (unsigned int)param_1[0x62] & 0xffe00000;
        if (param_1[0x3c] != 0) {
            FUN_0042cc70_Object_unk(0, param_1);
        }
        return 1;
    }
    iVar2 = FUN_0040F100(FUN_004A2990, id, c);
    if ((iVar2 != 0) && (iVar2 + -0x10000 <= (int)uVar3)) {
        param_1[0x1f] = param_1[0x1f] + (iVar2 - (int)uVar3);
        param_1[0x3b] = ((unsigned int)param_1[0x62] & 0xffe00000) + iVar2;
        if (param_1[0x3c] != 0) {
            FUN_0042cc70_Object_unk(0, param_1);
        }
        return 1;
    }
    return 0;
}
}
