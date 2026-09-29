extern "C" {
extern int DAT_004A2940;
extern void* DAT_004A2990;
extern volatile int DAT_004A2A1C;
extern int DAT_004A2A2C;
extern int DAT_004A2A38;
extern int DAT_004A2A90;
extern int DAT_004A2A9C;

void __cdecl FUN_00410c60_CameraFollowGex()
{
    int iVar1;

    DAT_004A2A9C = DAT_004A2A38;
    DAT_004A2A2C = DAT_004A2A1C;
    DAT_004A2A38 = DAT_004A2A38 + DAT_004A2A90;
    DAT_004A2A1C = DAT_004A2A1C + DAT_004A2940;
    if (DAT_004A2A38 < 0) {
        DAT_004A2A38 = 0;
    }
    if (DAT_004A2A1C < 0) {
        DAT_004A2A1C = 0;
    }
    iVar1 = *(int*)(*(int*)((int)DAT_004A2990 + 4) + 4);
    if (iVar1 - 0x1400000 <= DAT_004A2A38) {
        DAT_004A2A38 = iVar1 - 0x1410000;
    }
    iVar1 = *(int*)(*(int*)((int)DAT_004A2990 + 4) + 8);
    if (iVar1 - 0xf00000 <= DAT_004A2A1C) {
        DAT_004A2A1C = iVar1 - 0xf10000;
    }
}
}
