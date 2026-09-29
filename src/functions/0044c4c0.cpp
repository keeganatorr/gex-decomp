// Advance the four-byte argument slot; the return value occupies AX only.
unsigned short __cdecl _get_short_arg(unsigned short **cursor)
{
    *cursor += 2;
    return (*cursor)[-2];
}
