// Advance the four-byte argument slot before loading its previous value.
extern "C" unsigned int __cdecl GEX_Target(unsigned int **cursor)
{
    ++*cursor;
    return (*cursor)[-1];
}
