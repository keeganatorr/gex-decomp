extern "C" {
extern const char DAT_00458B90[];
extern void* DAT_004A2864;
extern void __cdecl FUN_00405350(const char*);
extern int __cdecl FUN_00411230(void*, int*, int*, int*);

void __cdecl FUN_004112e0_PlatCorner(int param_1, unsigned int param_2)
{
    int local_28[10];
    int local_2c;
    int local_30;
    int iVar1;

    if (param_2 == 0xffffffff) {
        FUN_00405350(DAT_00458B90);
        return;
    }
    iVar1 = FUN_00411230(DAT_004A2864, local_28, &local_2c, &local_30);
    if (iVar1 != 0) {
        unsigned int b1 = param_2 & 1;
        if (b1 != 0) {
            *(int*)(param_1 + 0x78) = local_28[7] - 0x1f0000;
        } else {
            *(int*)(param_1 + 0x78) = local_28[6];
        }
        if ((param_2 & 0x10) != 0) {
            *(int*)(param_1 + 0x7c) = local_28[9] - 0x1f0000;
            return;
        }
        if (b1 != 0) {
            *(int*)(param_1 + 0x7c) = local_30;
            return;
        }
        *(int*)(param_1 + 0x7c) = local_2c;
    }
}
}
