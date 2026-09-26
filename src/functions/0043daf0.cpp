extern "C" {
extern unsigned int *DAT_004a2b18_Draw1;
extern unsigned int DAT_00467178;
extern char DAT_00467170_Draw3_GraphicsDataUnk2;
extern unsigned int *DAT_004a2b14_Draw4;
extern unsigned int DAT_00467180_Draw5_GraphicsDataUnk1[];
extern short DAT_004a2b20;
extern void *DAT_00464e48_Draw6;
extern void **PTR_004a2b1c;
void __cdecl DRAW_CacheInit_0043e350(void);
void __cdecl GEX_Target(void)
{
    DAT_004a2b18_Draw1 = &DAT_00467178;
    DAT_00467170_Draw3_GraphicsDataUnk2 = 0;
    *DAT_004a2b18_Draw1 &= 0xffffff;
    DAT_004a2b14_Draw4 = &DAT_00467180_Draw5_GraphicsDataUnk1[DAT_00467170_Draw3_GraphicsDataUnk2];
    *DAT_004a2b14_Draw4 &= 0xffffff;
    DAT_004a2b20 = 0;
    DAT_00464e48_Draw6 = 0;
    PTR_004a2b1c = &DAT_00464e48_Draw6;
    DRAW_CacheInit_0043e350();
}
}
