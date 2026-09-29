extern "C" {
void __cdecl FUN_004451e0_LEV_SetUpDrawCacheWithFileData(void*, void*);
void __cdecl FUN_00445140_InnerGraphics(void*);
extern int DAT_00464e48;
extern int DAT_004A2B1C;
extern int DAT_004A2B18;
extern int DAT_004A2B14;
extern unsigned char DAT_0046067C;
extern int DAT_00467180;
extern signed char DAT_00467170;
extern int DAT_00460038;
extern unsigned char DAT_00464E3C;
extern int DAT_00464E40;
extern int DAT_00467178;
extern unsigned char DAT_0046003C;
extern unsigned short DAT_004A2B20;

void __cdecl CEL_DrawCels_0043db70(int param1) {
    *(int*)DAT_004A2B1C = 0;
    int local_Draw6 = DAT_00464e48;
    while (local_Draw6 != 0) {
        FUN_004451e0_LEV_SetUpDrawCacheWithFileData((void*)(local_Draw6 + 4), *(void**)(local_Draw6 + 0xc));
        local_Draw6 = *(int*)local_Draw6;
    }
    DAT_00464e48 = 0;
    DAT_004A2B1C = (int)&DAT_00464e48;
    *(int*)DAT_004A2B18 |= 0xffffff;
    *(int*)DAT_004A2B14 |= 0xffffff;
    if (DAT_0046067C != 0) {
        DAT_00460038 = (int)(&DAT_00467180 + DAT_00467170);
        if (param1 != 0) FUN_00445140_InnerGraphics((void*)DAT_00460038);
        DAT_00464E40 = (int)(&DAT_00467178 + DAT_00467170);
        DAT_00464E3C = DAT_0046003C;
        DAT_00467170 = DAT_00467170 ^ 1;
    }
    DAT_0046003C = 1;
    DAT_0046067C = 0;
    DAT_004A2B18 = (int)(&DAT_00467178 + DAT_00467170);
    *(int*)DAT_004A2B18 &= 0xffffff;
    DAT_004A2B14 = (int)(&DAT_00467180 + DAT_00467170);
    *(int*)DAT_004A2B14 &= 0xffffff;
    DAT_004A2B20 = 0;
}
}
