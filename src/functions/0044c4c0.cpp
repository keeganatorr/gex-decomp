// Advance the four-byte argument slot; the return value occupies AX only.
unsigned short __cdecl GEX_Target(unsigned short **cursor)
{
    *cursor += 2;
    return (*cursor)[-2];
}
