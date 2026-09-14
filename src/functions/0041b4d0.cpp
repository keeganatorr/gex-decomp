extern "C" {
void __cdecl GEX_Target(int *object, int ignored)
{
    if (ignored == 0) {
        object[0x1e] &= 0xffe00000;
        object[0x1f] &= 0xffe00000;
    }
}
}
