extern "C" unsigned long __cdecl ReadAnalogValue_0040f610(int player, int axis)
{
    if (axis != 0 && axis != 1)
        return 0;

    unsigned char *records = *(unsigned char **)0x004a27dc;
    unsigned long buttons = *(unsigned long *)(records + player * 0x24 + 4);
    int direction;
    if (axis == 0)
        direction = ((buttons & 2) >> 1) - (buttons & 1);
    else
        direction = ((buttons & 8) >> 3) - ((buttons & 4) >> 2);
    return ((unsigned long *)0x00457c64)[direction];
}
