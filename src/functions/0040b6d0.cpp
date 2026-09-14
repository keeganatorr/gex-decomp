void __cdecl GEX_Target(int *destination, int value, int count)
{
    int *output = destination;
    while (count > 0) {
        *output = value;
        output += 1;
        value += 0x2000;
        count -= 1;
    }
}
