extern "C" void __cdecl FUN_00431280(void)
{
    *(unsigned long *)0x0045b104 = 0x03300000;
    unsigned long x = *(unsigned long *)0x004a2a38 - 0x03300000;
    unsigned long y = *(unsigned long *)0x004a2a1c - 0x01900000;
    *(unsigned long *)0x0045b108 = 0x01900000;

    unsigned long *scale = (unsigned long *)0x00463fa0;
    unsigned long *rows = (unsigned long *)0x00463dc8;
    unsigned long *columns = (unsigned long *)0x00463d88;
    int index;
    for (index = 0; index < 8; ++index)
        scale[index] = 0x10000;
    for (index = 0; index < 8; ++index)
        rows[index] = (y & 0xffffff00) + 0x01900000;
    for (index = 0; index < 8; ++index)
        columns[index] = (x & 0xffffff00) + 0x03300000;
    *(unsigned long *)0x0045b100 = 0x10000;
}
