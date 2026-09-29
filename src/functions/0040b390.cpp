// Packed link: table selector in bits 20..30, even byte offset in bits 1..19.
extern "C" unsigned char* __cdecl LINK_RESOLVE_0040b390(unsigned char* table, unsigned int link)
{
    return *(unsigned char**)(table + ((link & 0x7ff00000u) >> 18)) + (link & 0xffffeu);
}
