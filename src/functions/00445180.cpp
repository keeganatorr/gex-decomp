typedef unsigned int uint;

extern "C" unsigned short __cdecl FUN_00445180_CacheInitInner_takes_x_and_y(uint value, uint offset)
{
    unsigned short index = (unsigned short)(value >> 4);
    index &= 0x3f;
    index |= (unsigned short)(offset << 6);
    return index;
}
