typedef unsigned int uint;
uint __cdecl GEX_Target(double *value)
{
    if (0.0 > *value)
        return 0;
    return 1;
}
