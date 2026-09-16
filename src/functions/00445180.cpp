typedef unsigned int uint;

extern "C" unsigned short __cdecl GEX_Target(uint value, uint offset)
{
    unsigned short index = (unsigned short)(value >> 4);
    index &= 0x3f;
    index |= (unsigned short)(offset << 6);
    return index;
}
