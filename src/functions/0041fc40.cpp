extern "C" {
int __cdecl FUN_0040F4C0(int);
int __cdecl FUN_0040F700(int, int*, int);
int __cdecl FUN_0040F5E0(int, int);
extern int DAT_004A02C8;
extern int DAT_004A02A0;
extern unsigned char DAT_004A0285;
extern int DAT_004A02CC;
extern unsigned char DAT_00457C38[];
extern unsigned char DAT_004A0280[];
extern unsigned char DAT_0045A178[];
extern unsigned char DAT_004A028F[];

void __cdecl GXINP_ReadPads_0041fc40(void)
{
    int keyInput;

    keyInput = FUN_0040F4C0(0);
    DAT_004A02C8 = keyInput;
    FUN_0040F700(keyInput, (int*)DAT_0045A178, (int)DAT_004A0280);
    DAT_004A02A0 = DAT_00457C38[keyInput & 0xf];
    keyInput = FUN_0040F5E0(0, keyInput);
    FUN_0040F700(keyInput, (int*)DAT_0045A178, (int)DAT_004A028F);
    DAT_004A02CC = DAT_004A0285;
}
}
