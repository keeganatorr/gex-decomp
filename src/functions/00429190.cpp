extern "C" {
int __cdecl abs(int);

int __cdecl GEX_Target(int param_1, int param_2, int param_3, int param_4)
{
    int dx;
    unsigned int flags = 0;
    int dy;
    int adx, ady;

    dx = param_3 - param_1;
    dy = param_4 - param_2;
    adx = abs(dx);
    ady = abs(dy);

    if (dx > 0)
        flags = 1;
    if (dy > 0)
        flags |= 2;

    if (adx > ady) {
        flags |= 4;
        if ((adx >> 1) > ady) {
            flags |= 8;
            return ((int *)0x45ab68)[flags];
        }
    } else {
        if ((ady >> 1) > adx)
            flags |= 8;
    }

    return ((int *)0x45ab68)[flags];
}
}
