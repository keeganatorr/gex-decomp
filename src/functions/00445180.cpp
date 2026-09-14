typedef unsigned int uint;
extern "C" {
unsigned short __cdecl GEX_Target(uint value, unsigned short offset)
{
    return (unsigned short)((value >> 4 & 0x3f) | (offset << 6));
}
}
