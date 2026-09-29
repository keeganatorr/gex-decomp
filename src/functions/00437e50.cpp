extern "C" {
int __cdecl FUN_00437e50(int a, int b)
{
    int bhi;
    int alo;
    int blo;
    int ahi;
    bhi = b >> 16;
    blo = b & 0xffff;
    alo = a & 0xffff;
    ahi = a >> 16;
    return ahi * ((b & 0xffff0000) + blo) + bhi * alo + ((blo * alo) >> 16);
}
}
