int * __cdecl GEX_Target(int *destination, int value, int count)
{
    if (count > 0)
    {
        do
        {
            *destination++ = value;
            value += 0x2000;
        } while (--count != 0);
    }
    return destination;
}
