typedef unsigned int uint;
extern "C" {
extern unsigned int DAT_004A2890;
extern unsigned int DAT_004A01E4;
extern int DAT_00463AB8;
uint __cdecl FUN_00421380(int *object)
{
    if (DAT_004A2890 == 0 && object[0x20] > 0 && DAT_004A01E4 != 0) {
        DAT_00463AB8 = object[0x20];
        object[0x20] = 0;
    }
    return 1;
}
}
