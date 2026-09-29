extern "C" {
extern int DAT_004a2824;
extern int DAT_004a285c;
extern int DAT_004a2880;
extern int DAT_004a283c;
extern int DAT_004a2844;
extern int DAT_004a2834;
extern int DAT_00460008[];
extern int DAT_0046000c[];

void __cdecl ob271Clid_0043b2e0(char* param_1, int* param_2)
{
    int uVar1;

    if (*param_2 != 0) {
        DAT_004a2824 = 1;
        DAT_004a285c = ~*(unsigned int*)(param_1 + 0x9c) & 1;
        if ((**(unsigned int**)(param_1 + 0x170) & 0xffff) == 8) {
            DAT_004a2880 = 1;
            DAT_004a283c = *(int*)(param_1 + 0xa0);
        }
        uVar1 = *(int*)(param_1 + 0x54);
        *(int*)(param_1 + 0x54) = 0;
        DAT_004a2844 = DAT_00460008[*(int*)(param_1 + 0xa0) * 2] + *(int*)(param_1 + 0x78);
        DAT_004a2834 = DAT_0046000c[*(int*)(param_1 + 0xa0) * 2] + *(int*)(param_1 + 0x7c);
        *(int*)(param_1 + 0x54) = uVar1;
    }
}
}
