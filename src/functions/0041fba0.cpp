extern "C" {
extern volatile unsigned int DAT_004639DC;
extern volatile unsigned int DAT_004A02D0;
unsigned int __cdecl GEX_Target(void)
{
    return DAT_004A02D0 == DAT_004639DC;
}
}
