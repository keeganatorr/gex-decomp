extern unsigned int DAT_004638C4;
extern unsigned int DAT_004A02D0;
extern unsigned int DAT_004639DC;
void __cdecl GEX_Target(int value)
{
    DAT_004639DC = value;
    if (DAT_004A02D0 != value)
        DAT_004638C4 = 1;
}
