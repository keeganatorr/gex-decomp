extern "C" {
extern void *DAT_004a2adc_Tiles2;
extern void *DAT_004a2ae0_TilesBack1;
extern void *PTR_004a2ae4;
extern int DAT_0047edb0_Tiles3;
extern int DAT_0046dc40;
void __cdecl FUN_00441130_VideoTiles(void)
{
    DAT_004a2ae0_TilesBack1 = &DAT_0046dc40;
    DAT_004a2adc_Tiles2 = &DAT_0047edb0_Tiles3;
    PTR_004a2ae4 = &DAT_0046dc40;
}
}
