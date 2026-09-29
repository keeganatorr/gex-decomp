extern "C" {
extern unsigned int *DAT_004A2B0C;
extern unsigned int *DAT_004A2B10;
void __cdecl FUN_0043db50_UpdateGraphicsState(void)
{
    *DAT_004A2B0C |= 0xffffff;
    *DAT_004A2B10 |= 0xffffff;
}
}
