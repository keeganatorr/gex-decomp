typedef unsigned int uint;
uint __cdecl GEX_Target(uint *value)
{
    int index = 0;
    while (index < 3) {
        if (*value != 0)
            return 0;
        value += 1;
        index += 1;
    }
    return 1;
}
