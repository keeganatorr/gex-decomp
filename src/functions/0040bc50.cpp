extern "C" {
extern int DAT_00456034;
void __cdecl GEX_Target(int amount)
{
    if (DAT_00456034 != -1)
        DAT_00456034 = (amount + DAT_00456034) & 0x7fffffff;
}
}
